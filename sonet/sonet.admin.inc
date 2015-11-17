<?php

function sonet_config_form($form,&$form_state){
	$form['payment'] = array(
	    '#type' => 'fieldset',
	    '#title' => t('Payment settings'),
	    '#access'=>user_access('administer sonet'),
	    '#weight'=>0,
  	);
  	
  	$options=array(
        'credit_card' => '信用卡',
        'super_store' => '超商代收',
        'spicy_card'  => '辣椒卡',
        'smart_pay'   => '消費扣款',
        'small_pay'   => '小額付費',
        'atm'         => 'ATM虛擬帳號',
    );
	
	$form['payment']['sonet_payment_status'] = array(
	    '#title' => t('Payment Currency Status'),
	    '#description' => t('Check the Payment method you want to enable'),
	    '#type' => 'checkboxes',
	    '#options'=>$options,
	    '#default_value'=>variable_get('sonet_payment_status'),
  	);

	$form['arguement'] = array(
	    '#type' => 'fieldset',
	    '#title' => t('Arguments settings'),
	    '#access'=>user_access('administer arguments sonet'),
	    '#weight'=>1,
  	);
  	
  	$options=array(
  		  'dev' => t('Development'),
        'production' => t('Production'),
        'closed' => t('Closed'),
  	);
  	$form['arguement']['sonet_status'] = array(
	    '#title' => t('Sonet Currency Status'),
	    '#description' => t('Select Current System environment. Ex: Dev,Production,Closed'),
	    '#type' => 'radios',
	    '#options'=>$options,
	    '#default_value'=>variable_get('sonet_status'),
  	);
    $options=array(
        'dev' => t('Development'),
        'production' => t('Production'),
    );
    
  	$form['arguement']['sonet_icpIde']=array(
  		'#title'=>t('icpIde'),
  		'#type' =>'textfield',
  		'#description'=>t('You can get this code from Sonet Service Person'),
  		'#size'=>30,
  		'#default_value'=>variable_get('sonet_icpIde'),
  	);
  	$form['arguement']['sonet_icpProdId']=array(
  		'#title'=>t('icpProdId'),
  		'#type' =>'textfield',
  		'#description'=>t('You can get this code from Sonet Service Person'),
  		'#size'=>30,
  		'#default_value'=>variable_get('sonet_icpProdId'),
  	);

  	$form['arguement']['sonet_icpProdId']=array(
  		'#title'=>t('icpProdId'),
  		'#type' =>'textfield',
  		'#description'=>t('You can get this code from Sonet Service Person'),
  		'#size'=>30,
  		'#default_value'=>variable_get('sonet_icpProdId'),
  	);

  	$options=array(
  		'post' => t('Post'),
        'soap' => t('Soap'),
  	);
  	$form['arguement']['sonet_http_method'] = array(
	    '#title' => t('Sonet Http Method'),
	    '#description' => t('Http Request Method. Post or Soap.'),
	    '#type' => 'radios',
	    '#options'=>$options,
	    '#default_value'=>variable_get('sonet_http_method'),
  	);

  	$form['arguement']['sonet_authorder_dev']=array(
  		'#title'=>t('AuthOrder Http Post Url (Development)'),
  		'#type' =>'textfield',
  		'#description'=>t('Please Check the Sonet Manual.'),
  		'#size'=>60,
  		'#default_value'=>variable_get('sonet_authorder_dev'),
  	);

  	$form['arguement']['sonet_authorder_wsdl_dev']=array(
  		'#title'=>t('AuthOrder Http SOAP Url (Development)'),
  		'#type' =>'textfield',
  		'#description'=>t('Please Check the Sonet Manual.'),
  		'#size'=>60,
  		'#default_value'=>variable_get('sonet_authorder_wsdl_dev'),
  	);

  	$form['arguement']['sonet_authorder_pro']=array(
  		'#title'=>t('AuthOrder Http Post Url (Production)'),
  		'#type' =>'textfield',
  		'#description'=>t('Please Check the Sonet Manual.'),
  		'#size'=>60,
  		'#default_value'=>variable_get('sonet_authorder_pro'),
  	);

  	$form['arguement']['sonet_authorder_wsdl_pro']=array(
  		'#title'=>t('AuthOrder Http SOAP Url (Production)'),
  		'#type' =>'textfield',
  		'#description'=>t('Please Check the Sonet Manual.'),
  		'#size'=>60,
  		'#default_value'=>variable_get('sonet_authorder_wsdl_pro'),
  	);

  	$form['sonet_submit']=array(
  		'#type'=>'submit',
		'#value'=>t('Save'),
		'#weight'=>2,
  	);

  	return $form;
}


function sonet_config_form_validate($form,&$form_state){

}

function sonet_config_form_submit($form,&$form_state){

	//save the data to the variable
	variable_set('sonet_payment_status',$form_state['values']['sonet_payment_status']);
	variable_set('sonet_status',$form_state['values']['sonet_status']);
	variable_set('sonet_icpIde',$form_state['values']['sonet_icpIde']);
	variable_set('sonet_icpProdId',$form_state['values']['sonet_icpProdId']);
	variable_set('sonet_http_method',$form_state['values']['sonet_http_method']);
	variable_set('sonet_authorder_dev',$form_state['values']['sonet_authorder_dev']);
	variable_set('sonet_authorder_wsdl_dev',$form_state['values']['sonet_authorder_wsdl_dev']);
	variable_set('sonet_authorder_pro',$form_state['values']['sonet_authorder_pro']);
	variable_set('sonet_authorder_wsdl_pro',$form_state['values']['sonet_authorder_wsdl_pro']);
  //重建整個Menu
  menu_rebuild();
	drupal_set_message(t('Updated'));
}
?>