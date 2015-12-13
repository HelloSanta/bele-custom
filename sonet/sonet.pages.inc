<?php
/**
 * Page callback for credit card page.
 */
function deposit_page(){

	return ' ';
}

function result_page(){
	$method=variable_get('sonet_http_method');
	$payment_status=variable_get('sonet_status');
	if($payment_status=='dev'){
		$apiUrl=variable_get('sonet_authorder_dev');
	}
	elseif ($payment_status=='production') {
		$apiUrl=variable_get('sonet_authorder_pro');
	}

	if(empty($_POST)){
		drupal_exit();
	}

	$resultCode = $_POST['resultCode'];
	$resultMesg = $_POST['resultMesg'];
	$icpId = $_POST['icpId'];
	$icpOrderId = $_POST['icpOrderId'];
	$sonetOrderNo = $_POST['sonetOrderNo'];
	$orderDataTime=$_POST['orderDataTime'];
	$mpId=$_POST['mpId'];

	if($resultCode=='ok'){

		//將sonet的訂單紀錄寫入資料庫
		$query=db_select('node','n');
		$query->condition('n.type','deposit_record');
		$query->join('field_data_field_icporderid','a','a.entity_id=n.nid');
		$query->fields('n',array('nid'));
		$query->condition('a.field_icporderid_value',$icpOrderId);
		$nid=$query->execute()->fetchfield();

		$node=node_load($nid);
		$node->field_sonetorderno['und'][0]['value']=$sonetOrderNo;
		$node->field_orderdatatime['und'][0]['value']=$orderDataTime;

		$record_type=$node->field_payment_method['und'][0]['value'];

		node_save($node);


		//通知Sonet完成
		$data['icpId'] = $_POST['icpId'];
		$data['icpOrderId'] = $_POST['icpOrderId'];
		$data['sonetOrderNo'] = $_POST['sonetOrderNo'];

		$data['doAction'] = "confirmOrder";

		$somp = new Somp();

		$finalAry = $somp->doRequest($method,$data,$apiUrl);
		//var_dump($finalAry);
		unset($data['doAction']);



		$resultCode=$finalAry['resultCode'];
		$resultMesg=$finalAry['resultMesg'];
		//訂單完成或訂單建立
		//超商代收跟虛擬帳號都只是建立訂單，玩家還不一定會去付款。
		//dpm($finalAry);
		//dpm($resultCode);

		$message='';

		if($resultCode=='0000'){

			/*以下資訊放置不是全部金流都有的參數*/
			$limitDateTime=empty($finalAry['limitDateTime'])?'1990-01-01 00:00:00':$finalAry['limitDateTime'];
			$storeOrderNo=empty($finalAry['storeOrderNo'])?'':$finalAry['storeOrderNo'];
			$expireDatetime=empty($finalAry['expireDatetime'])?'1990-01-01 00:00:00':$finalAry['expireDatetime'];
			$vatmAccount=empty($finalAry['vatmAccount'])?'':$finalAry['vatmAccount'];


			$node->field_confirmdatetime['und']['0']['value']=$finalAry['confirmDateTime'];
			$node->field_storeorderno['und'][0]['value']=$storeOrderNo;
			$node->field_limitdatetime['und'][0]['value']=$limitDateTime;
			$node->field_resultmesg['und'][0]['value']=$resultMesg;
			$node->field_expiredatetime['und'][0]['value']=$expireDatetime;
			$node->field_vatmaccount['und'][0]['value']=$vatmAccount;
			if(!empty($finalAry['result'])){
				$node->field_price['und'][0]['value']=$finalAry['result'];
			}

			if($record_type=='atm'){
				$node->field_payment_status['und'][0]['value']=2;
				$message=$message.'</br><div class="deposit-result">您的訂單已經建立</br>匯款帳號：'.$vatmAccount.'</br>繳費期限：'.$expireDatetime.
					'</br>若您有任何問題請直撥客服電話：<span style="color:#ffb238">（02）412－8989</span></div></div>';
			}
			elseif($record_type=='super_store'){
				$node->field_payment_status['und'][0]['value']=2;
				$message=$message.'</br><div class="deposit-result">您的訂單已經建立</br>繳款編號：'.$storeOrderNo.'</br>繳費期限：'.$limitDateTime.
					'</br>若您有任何問題請直撥客服電話：<span style="color:#ffb238">（02）412－8989</span></div></div>';
			}
			else{
				$node->field_payment_status['und'][0]['value']=1;

				$uid=$node->field_icpuserid[LANGUAGE_NONE][0]['target_id'];
				$points=$node->field_price[LANGUAGE_NONE][0]['value'];

				//針對不同range的點數進行給點

				if($points>=1000 and $points<3001){
					$points=floor($points*1.05);
				}
				elseif($points>=3001 and $points<5001){
					$points=floor($points*1.06);
				}
				elseif($points>=5001){
					$points=floor($points*1.07);
				}

				//在這裏開始幫玩家儲值，轉換為點數
				$params = array (
					'uid' => $uid,
					'points' => $points,
					'description'=>'購點儲值',
				);
				userpoints_userpointsapi($params);
				$message='儲值成功';
			}
		}
		else{

			$node->field_resultmesg['und'][0]['value']=$resultMesg;
			$message=$message.'</br><div class="deposit-result-failed">錯誤訊息'.$resultMesg.'</div></div>'	;
		}

		node_save($node);

	}
	else{

		//將錯誤訊息寫入資料庫
		$query=db_select('node','n');
		$query->condition('n.type','deposit_record');
		$query->join('field_data_field_icporderid','a','a.entity_id=n.nid');
		$query->fields('n',array('nid'));
		$query->condition('a.field_icporderid_value',$icpOrderId);
		$nid=$query->execute()->fetchfield();

		$node=node_load($nid);

		$node->field_resultmesg['und'][0]['value']=$resultMesg;

		node_save($node);
		// drupal_set_message($resultMesg,'warning');

		$message='<div class="result-message"><div class="deposit-result-failed">錯誤訊息：'.$resultMesg.'</div></div>';
	}

	return $message;

}

function confirm_page(){

	//先判斷環境，再決定actionurl為何
	$payment_status=variable_get('sonet_status');
	if($payment_status=='dev'){
		$actionUrl=variable_get('sonet_frontHost_dev');
	}
	elseif ($payment_status=='production') {
		$actionUrl=variable_get('sonet_frontHost_pro');
	}

	//將此值Post到Sonet對應的頁面，進行後續的動作。
	$output='<form action="'.$actionUrl.'" method="post" name="frm">';
	foreach ($_GET as $a => $b) {
		$output=$output."<input type='hidden' name='".htmlentities($a)."' value='".htmlentities($b)."'>";
	}
	$output=$output.'</form><script language="JavaScript">document.frm.submit()</script>請稍待。。。';

	return $output;
}

function sonet_choose_payment_form($form,&$form_state){

	global $user;
	global $base_url;

	$returnUrl=$base_url.'/deposit/result';

	$userid=$user->uid;

	//icpID 由Sonet提供
	$form['icpId'] = array(
		'#type'     => 'hidden',
		'#name'     => 'icpId',
		'#maxlength'=> 20,
		'#value'    => variable_get('sonet_icpIde'),
	);

	//訂單編號
	$form['icpOrderId'] = array(
		'#type'     => 'hidden',
		'#name'     => 'icpOrderId',
		'#maxlength'=> 30,
		'#value'    =>  date("Ymdhis"),
	);


	//所有選項如下：'credit_card','super_store','spicy_card','smart_pay','small_pay','atm'
	$method=arg(1);

	//icpProId 由Sonet提供
	$form['icpProdId'] = array(
		'#type'     => 'hidden',
		'#name'     => 'icpProdId',
		'#maxlength'=> 15,
		'#value'    => variable_get('sonet_icpProdId'),
	);


	$form['paymentMethod'] = array(
		'#type'     => 'hidden',
		'#name'     => 'method',
		'#maxlength'=> 15,
		'#value'    => $method,
	);

	if($method=='super_store'){ //針對超商代收的部分

		$MeDescription='<img src="/sites/all/themes/battle/images/super_store.png"></br>我們提供三大超商代收方式來共您選擇';

		$active=array(
			'IBON' => '<span class="ibon">'.t('IBON').'</span>',
			'FAMIPORT' => '<span class="FAMI">'.t('FAMI').'</span>',
			'LIFEET' => '<span class="LIFEET">'.t('LIFEET').'</span>'
		);

		$form['mpId'] = array(
			'#type'    => 'radios',
			'#title'   => t('Select the Super Store.'),
			'#options' => $active,
			'#required' => True,
			'#maxlength'=> 10,
			// '#description' => t('Select the Store you want to use'),
		);
	}
	elseif($method=='credit_card'){//針對信用卡的部分

		$MeDescription='請您直接選擇您想要購買的金額後，系統將會自動幫您轉到信用卡的服務頁面。<br> 本公司亦提供線下匯款方式儲值<br><a href="/node/134" class="notonline-btn">線下付款</a>';

		$form['mpId'] = array(
			'#type'    => 'hidden',
			'#value'   => 'CITI',
			'#maxlength'=> 10,
		);

		$form['custom_price'] = array(
			'#type'      => 'textfield',
			'#attributes'=>array('placeholder'=>'填寫購買金額'),
			'#maxlength' => 10,
			'#size'      =>30,
			'#weight'    =>9,
			'#prefix' => '<div class="custom_price">',
			'#suffix' => '</div>',
		);
	}
	elseif($method=='spicy_card'){//針對辣椒卡


		$form['mpId'] = array(
			'#type'    => 'hidden',
			'#value'   => 'WACARD',
			'#maxlength'=> 10,
		);
	}
	elseif($method=='smart_pay'){//針對消費扣款

		$MeDescription='注意：消費性扣款限用IE瀏覽器才可以使用';

		$form['mpId'] = array(
			'#type'    => 'hidden',
			'#value'   => 'CTCBP',
			'#maxlength'=> 10,
		);
	}
	elseif($method=='small_pay'){//針對小額付款

		$MeDescription='以下提供各種不同電信局與方式，供您選擇，選擇完電信局後，請您再選擇您想要儲值的金額。';

		$active=array(
			'TCC'       => t('台灣大哥大'),
			'FET'       => t('遠傳'),
			'OTPCHT'    => t('中華市話'),
			'OTP839'    => t('中華839'),
			'APT'       => t('亞太'),
			'HINET'     => t('HiNet'),
		);
		$form['mpId'] = array(
			'#type'    => 'radios',
			'#title'   => t('Select the Company.'),
			'#options' => $active,
			'#required' => True,
			'#maxlength'=> 10,
			// '#description' => t('Select the Company you want to use'),
		);

		//針對小額付款進行改寫ProdictId
		$price_list=array(
			'idz_0001'   => '購買金額新台幣30元，遊戲寶石10顆。',
			'idz_0002'   => '購買金額新台幣90元，遊戲寶石36顆(+20%)。',
			'idz_0003'  => '購買金額新台幣120元，遊戲寶石52顆(+30%)。',
			'idz_0004'  => '購買金額新台幣300元，遊戲寶石140顆(+40%)。',
			'idz_0005'  => '購買金額新台幣600元，遊戲寶石320顆(+60%)。',
			'idz_0006' => '購買金額新台幣1200元，遊戲寶石720顆(+80%)。',

		);

		$form['icpProdId'] = array(
			'#type'    => 'radios',
			'#title'   => t('Select the Gem Package.'),
			'#options' => $price_list,
			'#required' => True,
			'#maxlength'=> 15,
			'#weight'=>10,
			// '#description' => t('Select the Price you want to deposit'),
		);
	}
	elseif($method=='atm'){//針對ATM虛擬帳號
		$MeDescription='請您直接選擇您想要購買的金額後，系統將會自動幫您轉到虛擬帳號的服務頁面。';
		$form['mpId'] = array(
			'#type'    => 'hidden',
			'#value'   => 'vATM_FCB',
			'#maxlength'=> 10,
		);
	}


	$form['contact_information'] = array(
		'#weight' => -10,
		'#markup' => $MeDescription,
		'#prefix' => '<div class="description">',
		'#suffix' => '</div>',

	);


	//選擇要儲值的金額
	$price_list=array(
		500   => '我要購買500點（加贈 0%）',
		1500  => '我要購買1500點（加贈 5%）',
		3500  => '我要購買3500點（加贈 6%）',
		5000  => '我要購買5000點（加贈 7%）',
	);

	$form['price'] = array(
		'#type'    => 'radios',
		'#title'   => t('點數儲值'),
		'#options' => $price_list,
		'#maxlength'=> 10,
		// '#description' => t('Select the Company you want to use'),
	);

	if(in_array($method, array('spicy_card','small_pay'))){
		$form['price'] = array(
			'#type'    => 'hidden',
			'#value'   => '0',
			'#maxlength'=> 10,
		);
	}

	//sonet:商家消費者代號  使用者ID
	$form['icpUserId'] = array(
		'#type'    => 'hidden',
		'#name'    => 'icpUserId',
		'#value'   =>  $userid,
		'#maxlength'=> 50,
	);

	//sonet:商家訂單備註
	$form['memo'] = array(
		'#type'    => 'hidden',
		'#name'    => 'memo',
		'#value'   =>  variable_get('sonet_status'),
		'#maxlength'=> 200,
	);

	$form['returnUrl'] = array(
		'#type'    => 'hidden',
		'#name'    => 'returnUrl',
		'#value'   =>  $returnUrl,
		'#maxlength'=> 200,
	);

	$form['agree_check']=array(
		'#type' =>	'checkbox',
		'#title' => '我已閱讀與同意<a href="/rules">使用條款</a>',
		'#weight'=>20,
		'#required'=>True,
	);
	$form['selected'] = array(
		'#type' => 'select',
		'#title' => t('發票資訊'),
		'#options' => array(
			0 => t('不用發票'),
			1 => t('二聯式發票'),
			2 => t('三聯式發票'),
		),
		'#default_value' => 0,
		'#weight'=>21,
	);
	$form['company'] = array(
		'#type' => 'textfield',
		'#title' => t('公司抬頭'),
		'#size' => 30,
		'#maxlength' => 128,
		'#weight' =>22,
		'#states' => array(
			'visible' => array(
				':input[name="selected"]' => array('value' => 2),
			),
		),
	);
	$form['company_serial'] = array(
		'#type' => 'textfield',
		'#title' => t('公司統一編號'),
		'#size' => 30,
		'#maxlength' => 128,
		'#weight' =>23,
		'#states' => array(
			'visible' => array(
				':input[name="selected"]' => array('value' => 2),
			),
		),
	);
	$form['company_addr'] = array(
		'#type' => 'textfield',
		'#title' => t('發票寄送地址'),
		'#size' => 30,
		'#maxlength' => 128,
		'#weight' =>24,
		'#states' => array(
			'visible' => array(
				':input[name="selected"]' => array('value' => 2),
			),
		),
	);
	$form['super_store_submit']=array(
		'#type'=>'submit',
		'#value'=>t('確認購買'),
		'#weight' => 30,
		'#prefix' =>'<div class="action">',
		'#suffix' =>'</div>',
	);

	return $form;
	//return drupal_access_denied;
}

function sonet_choose_payment_form_validate($form,&$form_state){

	$method=variable_get('sonet_http_method');
	$payment_status=variable_get('sonet_status');
	if($payment_status=='dev'){
		$apiUrl=variable_get('sonet_authorder_dev');
	}
	elseif ($payment_status=='production') {
		$apiUrl=variable_get('sonet_authorder_pro');
	}

	$data['icpId'] = $form_state['values']['icpId'];
	$data['icpOrderId'] = $form_state['values']['icpOrderId'];
	$data['icpProdId'] = $form_state['values']['icpProdId'];
	$data['mpId'] = $form_state['values']['mpId'];
	$data['memo'] = $form_state['values']['memo'];
	$data['icpUserId'] = $form_state['values']['icpUserId'];
	$data['icpProdDesc'] = '點數儲值';

	if(empty($form_state['values']['custom_price']) && empty($form_state['values']['price'])){
		form_set_error('price','請填寫金額');
	}

	if(!empty($form_state['values']['custom_price'])){
		$data['price'] = $form_state['values']['custom_price'];
	}
	else{
		$data['price'] = $form_state['values']['price'];
	}


	$data['returnUrl'] = $form_state['values']['returnUrl'];
	$data['doAction'] = "authOrder";
	$data['paymentMethod']=$form_state['values']['paymentMethod'];

	//利用Sonet提供的Class
	$somp = new Somp();
	$finalAry = $somp->doRequest($method,$data,$apiUrl);
	$rtMsg = (string)$finalAry['resultCode'];


	if($rtMsg == "00000"){ //認證成功
		unset($data['doAction']);
		$data['authCode'] = $finalAry['authCode'];
		$form_state['sonet_data']=$data;

	}else{ //認證失敗

		$data = null;
		$data['resultCode'] = $finalAry['resultCode'];
		$data['resultMesg'] = $finalAry['resultMesg'];
		$error_message='Error Code:' . $data['resultCode'].'</br> Error Message:' .$data['resultMesg'];
		form_set_error('payment_error', $error_message);
	}
}

function sonet_choose_payment_form_submit($form,&$form_state){
	global $user;
	global $base_url;
	$userid=$user->uid;

	$data['icpId'] = $form_state['sonet_data']['icpId'];
	$data['icpOrderId'] = $form_state['sonet_data']['icpOrderId'];
	$data['icpProdId'] = $form_state['sonet_data']['icpProdId'];
	$data['mpId'] = $form_state['sonet_data']['mpId'];
	$data['memo'] = $form_state['sonet_data']['memo'];
	$data['icpUserId'] = $form_state['sonet_data']['icpUserId'];
	$data['icpProdDesc'] = $form_state['sonet_data']['icpProdDesc'];
	if(!empty($form_state['values']['custom_price'])){
		$data['price'] = $form_state['values']['custom_price'];
	}
	else{
		$data['price'] = $form_state['values']['price'];
	}
	$data['returnUrl'] = $form_state['sonet_data']['returnUrl'];
	$data['authCode'] = $form_state['sonet_data']['authCode'];
	$data['paymentMethod']=$form_state['sonet_data']['paymentMethod'];



	//將此認證紀錄寫入系統資料庫	
	$payment_record = new stdClass;
	$payment_record->type = 'deposit_record';
	$payment_record->uid = $userid;
	$payment_record->title = $data['icpOrderId'];
	$payment_record->field_icporderid[LANGUAGE_NONE][0]['value']=$data['icpOrderId'];
	$payment_record->field_payment_method[LANGUAGE_NONE][0]['value']=$data['paymentMethod'];
	$payment_record->field_mpid[LANGUAGE_NONE][0]['value']=$data['mpId'];
	$payment_record->field_authcode[LANGUAGE_NONE][0]['value']=$data['authCode'];
	$payment_record->field_price[LANGUAGE_NONE][0]['value']=$data['price'];
	$payment_record->field_record_en[LANGUAGE_NONE][0]['value']=variable_get('sonet_status');
	$payment_record->field_icpuserid[LANGUAGE_NONE][0]['target_id']=$data['icpUserId'];
	$payment_record->field_payment_status[LANGUAGE_NONE][0]['value']=0;

	//發票資訊
	$recipes=$form_state['values']['selected'];
	$payment_record->field_recipes[LANGUAGE_NONE][0]['value']=$recipes;
	if($recipes==2){
		$payment_record->field_company[LANGUAGE_NONE][0]['value']=isset($form_state['values']['company'])?$form_state['values']['company']:'';
		$payment_record->field_company_serial[LANGUAGE_NONE][0]['value']=isset($form_state['values']['company_serial'])?$form_state['values']['company_serial']:'';
		$payment_record->field_company_addr[LANGUAGE_NONE][0]['value']=isset($form_state['values']['company_addr'])?$form_state['values']['company_addr']:'';
	}

	node_object_prepare($payment_record);
	node_save($payment_record);

	//重新導向
	$full_url = url($base_url.'/deposit/confirm', array('query' => $data));
	drupal_goto($full_url);
}


/*虛擬帳號通知系統已經付款*/
function atm_confirm_page(){

	if(empty($_POST)){
		drupal_exit();
	}
	else{

		$sonetOrderNo = $_POST['sonetOrderNo'];
		$mpId=$_POST['mpId'];
		$icpId = $_POST['icpId'];
		$icpUserId = $_POST['icpUserId'];
		$vatmAccount=$_POST['vatmAccount'];
		$price=$_POST['price'];
		$payDate=$_POST['payDate'];
		$hashcode=$_POST['hash'];

		$hash=md5($sonetOrderNo.$mpId.$icpId.$icpUserId.$vatmAccount.$price.$payDate);

		/*確認資料的完整性，若是相同代表資料是完整的*/
		if($hash==$hashcode){

			//將sonet的訂單紀錄寫入資料庫
			$query=db_select('node','n');
			$query->condition('n.type','deposit_record');
			$query->join('field_data_field_sonetorderno','a','a.entity_id=n.nid');
			$query->join('field_data_field_vatmaccount','b','b.entity_id=n.nid');
			$query->join('field_data_field_price','c','c.entity_id=n.nid');
			$query->fields('n',array('nid'));
			$query->condition('a.field_sonetorderno_value',$sonetOrderNo);
			$query->condition('b.field_vatmaccount_value',$vatmAccount);
			$query->condition('c.field_price_value',$price);
			$nid=$query->execute()->fetchfield();

			if(!empty($nid)){
				$node=node_load($nid);
				$node->field_payment_status['und'][0]['value']=1;

				echo "0000";
				drupal_exit();
			}
			else{
				watchdog('SONET-ATM', 'SONET ATM CONFIRM ERROR');
				echo "ERROR CONFIRM";
				drupal_exit();
			}

		}
	}

}
?>