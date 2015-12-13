<?php
function sonet_view_access($uid = NULL) {
  

  return TRUE;
}


function sonet_service_check()
{
	dd($_POST);
123
	if(!empty($_POST)){
		return 'test';
	}
	
	return 'test';	
}
?>