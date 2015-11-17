<?php
/**
 * @file
 * sonet_payment.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function sonet_payment_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'sonet_atm';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = '(sonet)ATM虛擬帳號';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'ATM虛擬帳號';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = '重設';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '40';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« 第一頁';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ 上一頁';
  $handler->display->display_options['pager']['options']['tags']['next'] = '下一頁 ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = '最後一頁 »';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_icpuserid_target_id']['id'] = 'field_icpuserid_target_id';
  $handler->display->display_options['relationships']['field_icpuserid_target_id']['table'] = 'field_data_field_icpuserid';
  $handler->display->display_options['relationships']['field_icpuserid_target_id']['field'] = 'field_icpuserid_target_id';
  /* 欄位: 內容: 訂單編號 */
  $handler->display->display_options['fields']['field_icporderid']['id'] = 'field_icporderid';
  $handler->display->display_options['fields']['field_icporderid']['table'] = 'field_data_field_icporderid';
  $handler->display->display_options['fields']['field_icporderid']['field'] = 'field_icporderid';
  /* 欄位: 內容: SoNet訂單編號 */
  $handler->display->display_options['fields']['field_sonetorderno']['id'] = 'field_sonetorderno';
  $handler->display->display_options['fields']['field_sonetorderno']['table'] = 'field_data_field_sonetorderno';
  $handler->display->display_options['fields']['field_sonetorderno']['field'] = 'field_sonetorderno';
  /* 欄位: 內容: 付款方式 */
  $handler->display->display_options['fields']['field_mpid']['id'] = 'field_mpid';
  $handler->display->display_options['fields']['field_mpid']['table'] = 'field_data_field_mpid';
  $handler->display->display_options['fields']['field_mpid']['field'] = 'field_mpid';
  /* 欄位: 內容: 會員名稱 */
  $handler->display->display_options['fields']['field_icpuserid']['id'] = 'field_icpuserid';
  $handler->display->display_options['fields']['field_icpuserid']['table'] = 'field_data_field_icpuserid';
  $handler->display->display_options['fields']['field_icpuserid']['field'] = 'field_icpuserid';
  $handler->display->display_options['fields']['field_icpuserid']['settings'] = array(
    'link' => 0,
  );
  /* 欄位: 使用者: facebook id */
  $handler->display->display_options['fields']['field_facebook_id']['id'] = 'field_facebook_id';
  $handler->display->display_options['fields']['field_facebook_id']['table'] = 'field_data_field_facebook_id';
  $handler->display->display_options['fields']['field_facebook_id']['field'] = 'field_facebook_id';
  $handler->display->display_options['fields']['field_facebook_id']['relationship'] = 'field_icpuserid_target_id';
  $handler->display->display_options['fields']['field_facebook_id']['label'] = 'Facebook id';
  /* 欄位: 內容: 金額 */
  $handler->display->display_options['fields']['field_price']['id'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['table'] = 'field_data_field_price';
  $handler->display->display_options['fields']['field_price']['field'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* 欄位: 內容: 訂單時間 */
  $handler->display->display_options['fields']['field_orderdatatime']['id'] = 'field_orderdatatime';
  $handler->display->display_options['fields']['field_orderdatatime']['table'] = 'field_data_field_orderdatatime';
  $handler->display->display_options['fields']['field_orderdatatime']['field'] = 'field_orderdatatime';
  $handler->display->display_options['fields']['field_orderdatatime']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* 欄位: 內容: ATM虛擬帳號 */
  $handler->display->display_options['fields']['field_vatmaccount']['id'] = 'field_vatmaccount';
  $handler->display->display_options['fields']['field_vatmaccount']['table'] = 'field_data_field_vatmaccount';
  $handler->display->display_options['fields']['field_vatmaccount']['field'] = 'field_vatmaccount';
  /* 欄位: 內容: ATM繳款期限 */
  $handler->display->display_options['fields']['field_expiredatetime']['id'] = 'field_expiredatetime';
  $handler->display->display_options['fields']['field_expiredatetime']['table'] = 'field_data_field_expiredatetime';
  $handler->display->display_options['fields']['field_expiredatetime']['field'] = 'field_expiredatetime';
  $handler->display->display_options['fields']['field_expiredatetime']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* 欄位: 內容: 訂單狀態 */
  $handler->display->display_options['fields']['field_payment_status']['id'] = 'field_payment_status';
  $handler->display->display_options['fields']['field_payment_status']['table'] = 'field_data_field_payment_status';
  $handler->display->display_options['fields']['field_payment_status']['field'] = 'field_payment_status';
  /* 欄位: 內容: 回傳錯誤訊息 */
  $handler->display->display_options['fields']['field_resultmesg']['id'] = 'field_resultmesg';
  $handler->display->display_options['fields']['field_resultmesg']['table'] = 'field_data_field_resultmesg';
  $handler->display->display_options['fields']['field_resultmesg']['field'] = 'field_resultmesg';
  /* Sort criterion: 內容: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: 內容: 已發表 */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: 內容: 類型 */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'deposit_record' => 'deposit_record',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: 內容: 付款種類 (field_payment_method) */
  $handler->display->display_options['filters']['field_payment_method_value']['id'] = 'field_payment_method_value';
  $handler->display->display_options['filters']['field_payment_method_value']['table'] = 'field_data_field_payment_method';
  $handler->display->display_options['filters']['field_payment_method_value']['field'] = 'field_payment_method_value';
  $handler->display->display_options['filters']['field_payment_method_value']['value'] = array(
    'atm' => 'atm',
  );
  $handler->display->display_options['filters']['field_payment_method_value']['group'] = 1;
  /* Filter criterion: 內容: 訂單編號 (field_icporderid) */
  $handler->display->display_options['filters']['field_icporderid_value']['id'] = 'field_icporderid_value';
  $handler->display->display_options['filters']['field_icporderid_value']['table'] = 'field_data_field_icporderid';
  $handler->display->display_options['filters']['field_icporderid_value']['field'] = 'field_icporderid_value';
  $handler->display->display_options['filters']['field_icporderid_value']['group'] = 1;
  $handler->display->display_options['filters']['field_icporderid_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['operator_id'] = 'field_icporderid_value_op';
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['label'] = '訂單編號';
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['operator'] = 'field_icporderid_value_op';
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['identifier'] = 'field_icporderid_value';
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['autocomplete_field'] = 'field_icporderid';
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: 內容: SoNet訂單編號 (field_sonetorderno) */
  $handler->display->display_options['filters']['field_sonetorderno_value']['id'] = 'field_sonetorderno_value';
  $handler->display->display_options['filters']['field_sonetorderno_value']['table'] = 'field_data_field_sonetorderno';
  $handler->display->display_options['filters']['field_sonetorderno_value']['field'] = 'field_sonetorderno_value';
  $handler->display->display_options['filters']['field_sonetorderno_value']['group'] = 1;
  $handler->display->display_options['filters']['field_sonetorderno_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['operator_id'] = 'field_sonetorderno_value_op';
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['label'] = 'SoNet訂單編號';
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['operator'] = 'field_sonetorderno_value_op';
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['identifier'] = 'field_sonetorderno_value';
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['autocomplete_field'] = 'field_sonetorderno';
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: 內容: 訂單狀態 (field_payment_status) */
  $handler->display->display_options['filters']['field_payment_status_value']['id'] = 'field_payment_status_value';
  $handler->display->display_options['filters']['field_payment_status_value']['table'] = 'field_data_field_payment_status';
  $handler->display->display_options['filters']['field_payment_status_value']['field'] = 'field_payment_status_value';
  $handler->display->display_options['filters']['field_payment_status_value']['group'] = 1;
  $handler->display->display_options['filters']['field_payment_status_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_payment_status_value']['expose']['operator_id'] = 'field_payment_status_value_op';
  $handler->display->display_options['filters']['field_payment_status_value']['expose']['label'] = '訂單狀態';
  $handler->display->display_options['filters']['field_payment_status_value']['expose']['operator'] = 'field_payment_status_value_op';
  $handler->display->display_options['filters']['field_payment_status_value']['expose']['identifier'] = 'field_payment_status_value';
  $handler->display->display_options['filters']['field_payment_status_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: 使用者: facebook id (field_facebook_id) */
  $handler->display->display_options['filters']['field_facebook_id_value']['id'] = 'field_facebook_id_value';
  $handler->display->display_options['filters']['field_facebook_id_value']['table'] = 'field_data_field_facebook_id';
  $handler->display->display_options['filters']['field_facebook_id_value']['field'] = 'field_facebook_id_value';
  $handler->display->display_options['filters']['field_facebook_id_value']['relationship'] = 'field_icpuserid_target_id';
  $handler->display->display_options['filters']['field_facebook_id_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['operator_id'] = 'field_facebook_id_value_op';
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['label'] = 'Facebook id';
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['description'] = '與遊戲內facebook id 相同';
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['operator'] = 'field_facebook_id_value_op';
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['identifier'] = 'field_facebook_id_value';
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['autocomplete_dependent'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/workbench/deposit-record/atm';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'ATM虛擬帳號';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['sonet_atm'] = array(
    t('Master'),
    t('ATM虛擬帳號'),
    t('more'),
    t('Apply'),
    t('重設'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« 第一頁'),
    t('‹ 上一頁'),
    t('下一頁 ›'),
    t('最後一頁 »'),
    t('使用者 entity referenced from field_icpuserid'),
    t('訂單編號'),
    t('SoNet訂單編號'),
    t('付款方式'),
    t('會員名稱'),
    t('Facebook id'),
    t('金額'),
    t('訂單時間'),
    t('ATM繳款期限'),
    t('訂單狀態'),
    t('回傳錯誤訊息'),
    t('與遊戲內facebook id 相同'),
    t('Page'),
  );
  $export['sonet_atm'] = $view;

  $view = new view();
  $view->name = 'sonet_credit_card';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = '(sonet)信用卡';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = '信用卡';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = '重設';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '40';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« 第一頁';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ 上一頁';
  $handler->display->display_options['pager']['options']['tags']['next'] = '下一頁 ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = '最後一頁 »';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_icpuserid_target_id']['id'] = 'field_icpuserid_target_id';
  $handler->display->display_options['relationships']['field_icpuserid_target_id']['table'] = 'field_data_field_icpuserid';
  $handler->display->display_options['relationships']['field_icpuserid_target_id']['field'] = 'field_icpuserid_target_id';
  /* 欄位: 內容: 訂單編號 */
  $handler->display->display_options['fields']['field_icporderid']['id'] = 'field_icporderid';
  $handler->display->display_options['fields']['field_icporderid']['table'] = 'field_data_field_icporderid';
  $handler->display->display_options['fields']['field_icporderid']['field'] = 'field_icporderid';
  /* 欄位: 內容: SoNet訂單編號 */
  $handler->display->display_options['fields']['field_sonetorderno']['id'] = 'field_sonetorderno';
  $handler->display->display_options['fields']['field_sonetorderno']['table'] = 'field_data_field_sonetorderno';
  $handler->display->display_options['fields']['field_sonetorderno']['field'] = 'field_sonetorderno';
  /* 欄位: 內容: 付款方式 */
  $handler->display->display_options['fields']['field_mpid']['id'] = 'field_mpid';
  $handler->display->display_options['fields']['field_mpid']['table'] = 'field_data_field_mpid';
  $handler->display->display_options['fields']['field_mpid']['field'] = 'field_mpid';
  /* 欄位: 內容: 會員名稱 */
  $handler->display->display_options['fields']['field_icpuserid']['id'] = 'field_icpuserid';
  $handler->display->display_options['fields']['field_icpuserid']['table'] = 'field_data_field_icpuserid';
  $handler->display->display_options['fields']['field_icpuserid']['field'] = 'field_icpuserid';
  $handler->display->display_options['fields']['field_icpuserid']['settings'] = array(
    'link' => 0,
  );
  /* 欄位: 使用者: facebook id */
  $handler->display->display_options['fields']['field_facebook_id']['id'] = 'field_facebook_id';
  $handler->display->display_options['fields']['field_facebook_id']['table'] = 'field_data_field_facebook_id';
  $handler->display->display_options['fields']['field_facebook_id']['field'] = 'field_facebook_id';
  $handler->display->display_options['fields']['field_facebook_id']['relationship'] = 'field_icpuserid_target_id';
  $handler->display->display_options['fields']['field_facebook_id']['label'] = 'Facebook id';
  /* 欄位: 內容: 金額 */
  $handler->display->display_options['fields']['field_price']['id'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['table'] = 'field_data_field_price';
  $handler->display->display_options['fields']['field_price']['field'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* 欄位: 內容: 訂單時間 */
  $handler->display->display_options['fields']['field_orderdatatime']['id'] = 'field_orderdatatime';
  $handler->display->display_options['fields']['field_orderdatatime']['table'] = 'field_data_field_orderdatatime';
  $handler->display->display_options['fields']['field_orderdatatime']['field'] = 'field_orderdatatime';
  $handler->display->display_options['fields']['field_orderdatatime']['label'] = '建立訂單時間';
  $handler->display->display_options['fields']['field_orderdatatime']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* 欄位: 內容: 訂單狀態 */
  $handler->display->display_options['fields']['field_payment_status']['id'] = 'field_payment_status';
  $handler->display->display_options['fields']['field_payment_status']['table'] = 'field_data_field_payment_status';
  $handler->display->display_options['fields']['field_payment_status']['field'] = 'field_payment_status';
  /* 欄位: 內容: 回傳錯誤訊息 */
  $handler->display->display_options['fields']['field_resultmesg']['id'] = 'field_resultmesg';
  $handler->display->display_options['fields']['field_resultmesg']['table'] = 'field_data_field_resultmesg';
  $handler->display->display_options['fields']['field_resultmesg']['field'] = 'field_resultmesg';
  /* Sort criterion: 內容: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: 內容: 已發表 */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: 內容: 類型 */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'deposit_record' => 'deposit_record',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: 內容: 付款種類 (field_payment_method) */
  $handler->display->display_options['filters']['field_payment_method_value']['id'] = 'field_payment_method_value';
  $handler->display->display_options['filters']['field_payment_method_value']['table'] = 'field_data_field_payment_method';
  $handler->display->display_options['filters']['field_payment_method_value']['field'] = 'field_payment_method_value';
  $handler->display->display_options['filters']['field_payment_method_value']['value'] = array(
    'credit_card' => 'credit_card',
  );
  $handler->display->display_options['filters']['field_payment_method_value']['group'] = 1;
  /* Filter criterion: 內容: 訂單編號 (field_icporderid) */
  $handler->display->display_options['filters']['field_icporderid_value']['id'] = 'field_icporderid_value';
  $handler->display->display_options['filters']['field_icporderid_value']['table'] = 'field_data_field_icporderid';
  $handler->display->display_options['filters']['field_icporderid_value']['field'] = 'field_icporderid_value';
  $handler->display->display_options['filters']['field_icporderid_value']['group'] = 1;
  $handler->display->display_options['filters']['field_icporderid_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['operator_id'] = 'field_icporderid_value_op';
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['label'] = '訂單編號';
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['operator'] = 'field_icporderid_value_op';
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['identifier'] = 'field_icporderid_value';
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['autocomplete_field'] = 'field_icporderid';
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: 內容: SoNet訂單編號 (field_sonetorderno) */
  $handler->display->display_options['filters']['field_sonetorderno_value']['id'] = 'field_sonetorderno_value';
  $handler->display->display_options['filters']['field_sonetorderno_value']['table'] = 'field_data_field_sonetorderno';
  $handler->display->display_options['filters']['field_sonetorderno_value']['field'] = 'field_sonetorderno_value';
  $handler->display->display_options['filters']['field_sonetorderno_value']['group'] = 1;
  $handler->display->display_options['filters']['field_sonetorderno_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['operator_id'] = 'field_sonetorderno_value_op';
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['label'] = 'SoNet訂單編號';
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['operator'] = 'field_sonetorderno_value_op';
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['identifier'] = 'field_sonetorderno_value';
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['autocomplete_field'] = 'field_sonetorderno';
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: 內容: 訂單狀態 (field_payment_status) */
  $handler->display->display_options['filters']['field_payment_status_value']['id'] = 'field_payment_status_value';
  $handler->display->display_options['filters']['field_payment_status_value']['table'] = 'field_data_field_payment_status';
  $handler->display->display_options['filters']['field_payment_status_value']['field'] = 'field_payment_status_value';
  $handler->display->display_options['filters']['field_payment_status_value']['group'] = 1;
  $handler->display->display_options['filters']['field_payment_status_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_payment_status_value']['expose']['operator_id'] = 'field_payment_status_value_op';
  $handler->display->display_options['filters']['field_payment_status_value']['expose']['label'] = '訂單狀態';
  $handler->display->display_options['filters']['field_payment_status_value']['expose']['operator'] = 'field_payment_status_value_op';
  $handler->display->display_options['filters']['field_payment_status_value']['expose']['identifier'] = 'field_payment_status_value';
  $handler->display->display_options['filters']['field_payment_status_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: 使用者: facebook id (field_facebook_id) */
  $handler->display->display_options['filters']['field_facebook_id_value']['id'] = 'field_facebook_id_value';
  $handler->display->display_options['filters']['field_facebook_id_value']['table'] = 'field_data_field_facebook_id';
  $handler->display->display_options['filters']['field_facebook_id_value']['field'] = 'field_facebook_id_value';
  $handler->display->display_options['filters']['field_facebook_id_value']['relationship'] = 'field_icpuserid_target_id';
  $handler->display->display_options['filters']['field_facebook_id_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['operator_id'] = 'field_facebook_id_value_op';
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['label'] = 'Facebook id';
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['description'] = '與遊戲內的Facebook ID相同';
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['operator'] = 'field_facebook_id_value_op';
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['identifier'] = 'field_facebook_id_value';
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['autocomplete_field'] = 'field_facebook_id';
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['autocomplete_dependent'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/workbench/deposit-record/credit_card';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = '信用卡付款';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['sonet_credit_card'] = array(
    t('Master'),
    t('信用卡'),
    t('more'),
    t('Apply'),
    t('重設'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« 第一頁'),
    t('‹ 上一頁'),
    t('下一頁 ›'),
    t('最後一頁 »'),
    t('使用者 entity referenced from field_icpuserid'),
    t('訂單編號'),
    t('SoNet訂單編號'),
    t('付款方式'),
    t('會員名稱'),
    t('Facebook id'),
    t('金額'),
    t('建立訂單時間'),
    t('訂單狀態'),
    t('回傳錯誤訊息'),
    t('與遊戲內的Facebook ID相同'),
    t('Page'),
  );
  $export['sonet_credit_card'] = $view;

  $view = new view();
  $view->name = 'sonet_deposit_record';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = '(Sonet)儲值紀錄';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = '總儲值紀錄';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    4 => '4',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = '重設';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '40';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« 第一頁';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ 上一頁';
  $handler->display->display_options['pager']['options']['tags']['next'] = '下一頁 ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = '最後一頁 »';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_icpuserid_target_id']['id'] = 'field_icpuserid_target_id';
  $handler->display->display_options['relationships']['field_icpuserid_target_id']['table'] = 'field_data_field_icpuserid';
  $handler->display->display_options['relationships']['field_icpuserid_target_id']['field'] = 'field_icpuserid_target_id';
  /* 欄位: 內容: 訂單編號 */
  $handler->display->display_options['fields']['field_icporderid']['id'] = 'field_icporderid';
  $handler->display->display_options['fields']['field_icporderid']['table'] = 'field_data_field_icporderid';
  $handler->display->display_options['fields']['field_icporderid']['field'] = 'field_icporderid';
  /* 欄位: 內容: SoNet訂單編號 */
  $handler->display->display_options['fields']['field_sonetorderno']['id'] = 'field_sonetorderno';
  $handler->display->display_options['fields']['field_sonetorderno']['table'] = 'field_data_field_sonetorderno';
  $handler->display->display_options['fields']['field_sonetorderno']['field'] = 'field_sonetorderno';
  /* 欄位: 內容: 付款方式 */
  $handler->display->display_options['fields']['field_mpid']['id'] = 'field_mpid';
  $handler->display->display_options['fields']['field_mpid']['table'] = 'field_data_field_mpid';
  $handler->display->display_options['fields']['field_mpid']['field'] = 'field_mpid';
  /* 欄位: 內容: 付款種類 */
  $handler->display->display_options['fields']['field_payment_method']['id'] = 'field_payment_method';
  $handler->display->display_options['fields']['field_payment_method']['table'] = 'field_data_field_payment_method';
  $handler->display->display_options['fields']['field_payment_method']['field'] = 'field_payment_method';
  /* 欄位: 內容: 會員名稱 */
  $handler->display->display_options['fields']['field_icpuserid']['id'] = 'field_icpuserid';
  $handler->display->display_options['fields']['field_icpuserid']['table'] = 'field_data_field_icpuserid';
  $handler->display->display_options['fields']['field_icpuserid']['field'] = 'field_icpuserid';
  $handler->display->display_options['fields']['field_icpuserid']['settings'] = array(
    'link' => 0,
  );
  /* 欄位: 使用者: facebook id */
  $handler->display->display_options['fields']['field_facebook_id']['id'] = 'field_facebook_id';
  $handler->display->display_options['fields']['field_facebook_id']['table'] = 'field_data_field_facebook_id';
  $handler->display->display_options['fields']['field_facebook_id']['field'] = 'field_facebook_id';
  $handler->display->display_options['fields']['field_facebook_id']['relationship'] = 'field_icpuserid_target_id';
  $handler->display->display_options['fields']['field_facebook_id']['label'] = 'Facebook id';
  /* 欄位: 內容: 金額 */
  $handler->display->display_options['fields']['field_price']['id'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['table'] = 'field_data_field_price';
  $handler->display->display_options['fields']['field_price']['field'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* 欄位: 內容: 訂單時間 */
  $handler->display->display_options['fields']['field_orderdatatime']['id'] = 'field_orderdatatime';
  $handler->display->display_options['fields']['field_orderdatatime']['table'] = 'field_data_field_orderdatatime';
  $handler->display->display_options['fields']['field_orderdatatime']['field'] = 'field_orderdatatime';
  $handler->display->display_options['fields']['field_orderdatatime']['label'] = '建立訂單時間';
  $handler->display->display_options['fields']['field_orderdatatime']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* 欄位: 內容: 系統環境 */
  $handler->display->display_options['fields']['field_record_en']['id'] = 'field_record_en';
  $handler->display->display_options['fields']['field_record_en']['table'] = 'field_data_field_record_en';
  $handler->display->display_options['fields']['field_record_en']['field'] = 'field_record_en';
  /* 欄位: 內容: 訂單狀態 */
  $handler->display->display_options['fields']['field_payment_status']['id'] = 'field_payment_status';
  $handler->display->display_options['fields']['field_payment_status']['table'] = 'field_data_field_payment_status';
  $handler->display->display_options['fields']['field_payment_status']['field'] = 'field_payment_status';
  /* Sort criterion: 內容: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: 內容: 已發表 */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: 內容: 類型 */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'deposit_record' => 'deposit_record',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: 內容: 訂單編號 (field_icporderid) */
  $handler->display->display_options['filters']['field_icporderid_value']['id'] = 'field_icporderid_value';
  $handler->display->display_options['filters']['field_icporderid_value']['table'] = 'field_data_field_icporderid';
  $handler->display->display_options['filters']['field_icporderid_value']['field'] = 'field_icporderid_value';
  $handler->display->display_options['filters']['field_icporderid_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_icporderid_value']['group'] = 1;
  $handler->display->display_options['filters']['field_icporderid_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['operator_id'] = 'field_icporderid_value_op';
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['label'] = '訂單編號';
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['operator'] = 'field_icporderid_value_op';
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['identifier'] = 'field_icporderid_value';
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['autocomplete_field'] = 'field_icporderid';
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: 內容: SoNet訂單編號 (field_sonetorderno) */
  $handler->display->display_options['filters']['field_sonetorderno_value']['id'] = 'field_sonetorderno_value';
  $handler->display->display_options['filters']['field_sonetorderno_value']['table'] = 'field_data_field_sonetorderno';
  $handler->display->display_options['filters']['field_sonetorderno_value']['field'] = 'field_sonetorderno_value';
  $handler->display->display_options['filters']['field_sonetorderno_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_sonetorderno_value']['group'] = 1;
  $handler->display->display_options['filters']['field_sonetorderno_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['operator_id'] = 'field_sonetorderno_value_op';
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['label'] = 'SoNet訂單編號';
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['operator'] = 'field_sonetorderno_value_op';
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['identifier'] = 'field_sonetorderno_value';
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['autocomplete_field'] = 'field_sonetorderno';
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: 內容: 付款方式 (field_mpid) */
  $handler->display->display_options['filters']['field_mpid_value']['id'] = 'field_mpid_value';
  $handler->display->display_options['filters']['field_mpid_value']['table'] = 'field_data_field_mpid';
  $handler->display->display_options['filters']['field_mpid_value']['field'] = 'field_mpid_value';
  $handler->display->display_options['filters']['field_mpid_value']['group'] = 1;
  $handler->display->display_options['filters']['field_mpid_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_mpid_value']['expose']['operator_id'] = 'field_mpid_value_op';
  $handler->display->display_options['filters']['field_mpid_value']['expose']['label'] = '付款方式';
  $handler->display->display_options['filters']['field_mpid_value']['expose']['operator'] = 'field_mpid_value_op';
  $handler->display->display_options['filters']['field_mpid_value']['expose']['identifier'] = 'field_mpid_value';
  $handler->display->display_options['filters']['field_mpid_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: 內容: 付款種類 (field_payment_method) */
  $handler->display->display_options['filters']['field_payment_method_value']['id'] = 'field_payment_method_value';
  $handler->display->display_options['filters']['field_payment_method_value']['table'] = 'field_data_field_payment_method';
  $handler->display->display_options['filters']['field_payment_method_value']['field'] = 'field_payment_method_value';
  $handler->display->display_options['filters']['field_payment_method_value']['group'] = 1;
  $handler->display->display_options['filters']['field_payment_method_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_payment_method_value']['expose']['operator_id'] = 'field_payment_method_value_op';
  $handler->display->display_options['filters']['field_payment_method_value']['expose']['label'] = '付款種類';
  $handler->display->display_options['filters']['field_payment_method_value']['expose']['operator'] = 'field_payment_method_value_op';
  $handler->display->display_options['filters']['field_payment_method_value']['expose']['identifier'] = 'field_payment_method_value';
  $handler->display->display_options['filters']['field_payment_method_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: 內容: 訂單狀態 (field_payment_status) */
  $handler->display->display_options['filters']['field_payment_status_value']['id'] = 'field_payment_status_value';
  $handler->display->display_options['filters']['field_payment_status_value']['table'] = 'field_data_field_payment_status';
  $handler->display->display_options['filters']['field_payment_status_value']['field'] = 'field_payment_status_value';
  $handler->display->display_options['filters']['field_payment_status_value']['group'] = 1;
  $handler->display->display_options['filters']['field_payment_status_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_payment_status_value']['expose']['operator_id'] = 'field_payment_status_value_op';
  $handler->display->display_options['filters']['field_payment_status_value']['expose']['label'] = '訂單狀態';
  $handler->display->display_options['filters']['field_payment_status_value']['expose']['operator'] = 'field_payment_status_value_op';
  $handler->display->display_options['filters']['field_payment_status_value']['expose']['identifier'] = 'field_payment_status_value';
  $handler->display->display_options['filters']['field_payment_status_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: 使用者: 名稱 */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['relationship'] = 'field_icpuserid_target_id';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = '玩家名稱';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
  $handler->display->display_options['filters']['uid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: 使用者: facebook id (field_facebook_id) */
  $handler->display->display_options['filters']['field_facebook_id_value']['id'] = 'field_facebook_id_value';
  $handler->display->display_options['filters']['field_facebook_id_value']['table'] = 'field_data_field_facebook_id';
  $handler->display->display_options['filters']['field_facebook_id_value']['field'] = 'field_facebook_id_value';
  $handler->display->display_options['filters']['field_facebook_id_value']['relationship'] = 'field_icpuserid_target_id';
  $handler->display->display_options['filters']['field_facebook_id_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['operator_id'] = 'field_facebook_id_value_op';
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['label'] = 'Facebook id';
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['description'] = '與遊戲內的Facebook ID相同';
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['operator'] = 'field_facebook_id_value_op';
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['identifier'] = 'field_facebook_id_value';
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['autocomplete_field'] = 'field_facebook_id';
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['autocomplete_dependent'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'admin/workbench/deposit-record';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = '總儲值紀錄';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'export_csv.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['path'] = 'admin/workbench/deposit-record/export';
  $handler->display->display_options['displays'] = array(
    'page_1' => 'page_1',
    'default' => 0,
  );

  /* Display: Data export 2 */
  $handler = $view->new_display('views_data_export', 'Data export 2', 'views_data_export_2');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'export_xls.xls';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['path'] = 'admin/workbench/deposit-record/export-xls';
  $handler->display->display_options['displays'] = array(
    'page_1' => 'page_1',
    'default' => 0,
  );
  $translatables['sonet_deposit_record'] = array(
    t('Master'),
    t('總儲值紀錄'),
    t('more'),
    t('Apply'),
    t('重設'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« 第一頁'),
    t('‹ 上一頁'),
    t('下一頁 ›'),
    t('最後一頁 »'),
    t('使用者 entity referenced from field_icpuserid'),
    t('訂單編號'),
    t('SoNet訂單編號'),
    t('付款方式'),
    t('付款種類'),
    t('會員名稱'),
    t('Facebook id'),
    t('金額'),
    t('建立訂單時間'),
    t('系統環境'),
    t('訂單狀態'),
    t('玩家名稱'),
    t('與遊戲內的Facebook ID相同'),
    t('Page'),
    t('Data export'),
    t('Data export 2'),
  );
  $export['sonet_deposit_record'] = $view;

  $view = new view();
  $view->name = 'sonet_small_pay';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = '(sonet)小額付費';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = '小額付費';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = '重設';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '40';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« 第一頁';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ 上一頁';
  $handler->display->display_options['pager']['options']['tags']['next'] = '下一頁 ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = '最後一頁 »';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_icpuserid_target_id']['id'] = 'field_icpuserid_target_id';
  $handler->display->display_options['relationships']['field_icpuserid_target_id']['table'] = 'field_data_field_icpuserid';
  $handler->display->display_options['relationships']['field_icpuserid_target_id']['field'] = 'field_icpuserid_target_id';
  /* 欄位: 內容: 訂單編號 */
  $handler->display->display_options['fields']['field_icporderid']['id'] = 'field_icporderid';
  $handler->display->display_options['fields']['field_icporderid']['table'] = 'field_data_field_icporderid';
  $handler->display->display_options['fields']['field_icporderid']['field'] = 'field_icporderid';
  /* 欄位: 內容: SoNet訂單編號 */
  $handler->display->display_options['fields']['field_sonetorderno']['id'] = 'field_sonetorderno';
  $handler->display->display_options['fields']['field_sonetorderno']['table'] = 'field_data_field_sonetorderno';
  $handler->display->display_options['fields']['field_sonetorderno']['field'] = 'field_sonetorderno';
  /* 欄位: 內容: 付款方式 */
  $handler->display->display_options['fields']['field_mpid']['id'] = 'field_mpid';
  $handler->display->display_options['fields']['field_mpid']['table'] = 'field_data_field_mpid';
  $handler->display->display_options['fields']['field_mpid']['field'] = 'field_mpid';
  /* 欄位: 內容: 會員名稱 */
  $handler->display->display_options['fields']['field_icpuserid']['id'] = 'field_icpuserid';
  $handler->display->display_options['fields']['field_icpuserid']['table'] = 'field_data_field_icpuserid';
  $handler->display->display_options['fields']['field_icpuserid']['field'] = 'field_icpuserid';
  $handler->display->display_options['fields']['field_icpuserid']['settings'] = array(
    'link' => 0,
  );
  /* 欄位: 使用者: facebook id */
  $handler->display->display_options['fields']['field_facebook_id']['id'] = 'field_facebook_id';
  $handler->display->display_options['fields']['field_facebook_id']['table'] = 'field_data_field_facebook_id';
  $handler->display->display_options['fields']['field_facebook_id']['field'] = 'field_facebook_id';
  $handler->display->display_options['fields']['field_facebook_id']['relationship'] = 'field_icpuserid_target_id';
  $handler->display->display_options['fields']['field_facebook_id']['label'] = 'Facebook id';
  /* 欄位: 內容: 金額 */
  $handler->display->display_options['fields']['field_price']['id'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['table'] = 'field_data_field_price';
  $handler->display->display_options['fields']['field_price']['field'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* 欄位: 內容: 訂單時間 */
  $handler->display->display_options['fields']['field_orderdatatime']['id'] = 'field_orderdatatime';
  $handler->display->display_options['fields']['field_orderdatatime']['table'] = 'field_data_field_orderdatatime';
  $handler->display->display_options['fields']['field_orderdatatime']['field'] = 'field_orderdatatime';
  $handler->display->display_options['fields']['field_orderdatatime']['label'] = '建立訂單時間';
  $handler->display->display_options['fields']['field_orderdatatime']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* 欄位: 內容: 繳款編號 */
  $handler->display->display_options['fields']['field_storeorderno']['id'] = 'field_storeorderno';
  $handler->display->display_options['fields']['field_storeorderno']['table'] = 'field_data_field_storeorderno';
  $handler->display->display_options['fields']['field_storeorderno']['field'] = 'field_storeorderno';
  /* 欄位: 內容: 繳款期限 */
  $handler->display->display_options['fields']['field_limitdatetime']['id'] = 'field_limitdatetime';
  $handler->display->display_options['fields']['field_limitdatetime']['table'] = 'field_data_field_limitdatetime';
  $handler->display->display_options['fields']['field_limitdatetime']['field'] = 'field_limitdatetime';
  $handler->display->display_options['fields']['field_limitdatetime']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* 欄位: 內容: 訂單狀態 */
  $handler->display->display_options['fields']['field_payment_status']['id'] = 'field_payment_status';
  $handler->display->display_options['fields']['field_payment_status']['table'] = 'field_data_field_payment_status';
  $handler->display->display_options['fields']['field_payment_status']['field'] = 'field_payment_status';
  /* 欄位: 內容: 回傳錯誤訊息 */
  $handler->display->display_options['fields']['field_resultmesg']['id'] = 'field_resultmesg';
  $handler->display->display_options['fields']['field_resultmesg']['table'] = 'field_data_field_resultmesg';
  $handler->display->display_options['fields']['field_resultmesg']['field'] = 'field_resultmesg';
  /* Sort criterion: 內容: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: 內容: 已發表 */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: 內容: 類型 */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'deposit_record' => 'deposit_record',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: 內容: 付款種類 (field_payment_method) */
  $handler->display->display_options['filters']['field_payment_method_value']['id'] = 'field_payment_method_value';
  $handler->display->display_options['filters']['field_payment_method_value']['table'] = 'field_data_field_payment_method';
  $handler->display->display_options['filters']['field_payment_method_value']['field'] = 'field_payment_method_value';
  $handler->display->display_options['filters']['field_payment_method_value']['value'] = array(
    'small_pay' => 'small_pay',
  );
  $handler->display->display_options['filters']['field_payment_method_value']['group'] = 1;
  /* Filter criterion: 內容: 訂單編號 (field_icporderid) */
  $handler->display->display_options['filters']['field_icporderid_value']['id'] = 'field_icporderid_value';
  $handler->display->display_options['filters']['field_icporderid_value']['table'] = 'field_data_field_icporderid';
  $handler->display->display_options['filters']['field_icporderid_value']['field'] = 'field_icporderid_value';
  $handler->display->display_options['filters']['field_icporderid_value']['group'] = 1;
  $handler->display->display_options['filters']['field_icporderid_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['operator_id'] = 'field_icporderid_value_op';
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['label'] = '訂單編號';
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['operator'] = 'field_icporderid_value_op';
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['identifier'] = 'field_icporderid_value';
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['autocomplete_field'] = 'field_icporderid';
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: 內容: SoNet訂單編號 (field_sonetorderno) */
  $handler->display->display_options['filters']['field_sonetorderno_value']['id'] = 'field_sonetorderno_value';
  $handler->display->display_options['filters']['field_sonetorderno_value']['table'] = 'field_data_field_sonetorderno';
  $handler->display->display_options['filters']['field_sonetorderno_value']['field'] = 'field_sonetorderno_value';
  $handler->display->display_options['filters']['field_sonetorderno_value']['group'] = 1;
  $handler->display->display_options['filters']['field_sonetorderno_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['operator_id'] = 'field_sonetorderno_value_op';
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['label'] = 'SoNet訂單編號';
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['operator'] = 'field_sonetorderno_value_op';
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['identifier'] = 'field_sonetorderno_value';
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['autocomplete_field'] = 'field_sonetorderno';
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: 內容: 訂單狀態 (field_payment_status) */
  $handler->display->display_options['filters']['field_payment_status_value']['id'] = 'field_payment_status_value';
  $handler->display->display_options['filters']['field_payment_status_value']['table'] = 'field_data_field_payment_status';
  $handler->display->display_options['filters']['field_payment_status_value']['field'] = 'field_payment_status_value';
  $handler->display->display_options['filters']['field_payment_status_value']['group'] = 1;
  $handler->display->display_options['filters']['field_payment_status_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_payment_status_value']['expose']['operator_id'] = 'field_payment_status_value_op';
  $handler->display->display_options['filters']['field_payment_status_value']['expose']['label'] = '訂單狀態';
  $handler->display->display_options['filters']['field_payment_status_value']['expose']['operator'] = 'field_payment_status_value_op';
  $handler->display->display_options['filters']['field_payment_status_value']['expose']['identifier'] = 'field_payment_status_value';
  $handler->display->display_options['filters']['field_payment_status_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: 內容: 付款方式 (field_mpid) */
  $handler->display->display_options['filters']['field_mpid_value']['id'] = 'field_mpid_value';
  $handler->display->display_options['filters']['field_mpid_value']['table'] = 'field_data_field_mpid';
  $handler->display->display_options['filters']['field_mpid_value']['field'] = 'field_mpid_value';
  $handler->display->display_options['filters']['field_mpid_value']['value'] = array(
    'TCC' => 'TCC',
    'FET' => 'FET',
    'OTPCHT' => 'OTPCHT',
    'APT' => 'APT',
    'VIBO' => 'VIBO',
    'HINET' => 'HINET',
    'SONET' => 'SONET',
    'ESUN' => 'ESUN',
    'CYC_TCC' => 'CYC_TCC',
    'CYC_FET' => 'CYC_FET',
    'CYC_OTP839' => 'CYC_OTP839',
    'CYC_OTPCHT' => 'CYC_OTPCHT',
    'CYC_HINET' => 'CYC_HINET',
  );
  $handler->display->display_options['filters']['field_mpid_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_mpid_value']['expose']['operator_id'] = 'field_mpid_value_op';
  $handler->display->display_options['filters']['field_mpid_value']['expose']['label'] = '付款方式';
  $handler->display->display_options['filters']['field_mpid_value']['expose']['operator'] = 'field_mpid_value_op';
  $handler->display->display_options['filters']['field_mpid_value']['expose']['identifier'] = 'field_mpid_value';
  $handler->display->display_options['filters']['field_mpid_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_mpid_value']['expose']['reduce'] = TRUE;
  /* Filter criterion: 使用者: facebook id (field_facebook_id) */
  $handler->display->display_options['filters']['field_facebook_id_value']['id'] = 'field_facebook_id_value';
  $handler->display->display_options['filters']['field_facebook_id_value']['table'] = 'field_data_field_facebook_id';
  $handler->display->display_options['filters']['field_facebook_id_value']['field'] = 'field_facebook_id_value';
  $handler->display->display_options['filters']['field_facebook_id_value']['relationship'] = 'field_icpuserid_target_id';
  $handler->display->display_options['filters']['field_facebook_id_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['operator_id'] = 'field_facebook_id_value_op';
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['label'] = 'Facebook id';
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['description'] = '與遊戲內的Facebook ID相同';
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['operator'] = 'field_facebook_id_value_op';
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['identifier'] = 'field_facebook_id_value';
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['autocomplete_dependent'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/workbench/deposit-record/small_pay';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = '小額付費';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['sonet_small_pay'] = array(
    t('Master'),
    t('小額付費'),
    t('more'),
    t('Apply'),
    t('重設'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« 第一頁'),
    t('‹ 上一頁'),
    t('下一頁 ›'),
    t('最後一頁 »'),
    t('使用者 entity referenced from field_icpuserid'),
    t('訂單編號'),
    t('SoNet訂單編號'),
    t('付款方式'),
    t('會員名稱'),
    t('Facebook id'),
    t('金額'),
    t('建立訂單時間'),
    t('繳款編號'),
    t('繳款期限'),
    t('訂單狀態'),
    t('回傳錯誤訊息'),
    t('與遊戲內的Facebook ID相同'),
    t('Page'),
  );
  $export['sonet_small_pay'] = $view;

  $view = new view();
  $view->name = 'sonet_smart_pay';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = '(sonet)消費性扣款';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = '消費性扣款';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = '重設';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '40';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« 第一頁';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ 上一頁';
  $handler->display->display_options['pager']['options']['tags']['next'] = '下一頁 ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = '最後一頁 »';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_icpuserid_target_id']['id'] = 'field_icpuserid_target_id';
  $handler->display->display_options['relationships']['field_icpuserid_target_id']['table'] = 'field_data_field_icpuserid';
  $handler->display->display_options['relationships']['field_icpuserid_target_id']['field'] = 'field_icpuserid_target_id';
  /* 欄位: 內容: 訂單編號 */
  $handler->display->display_options['fields']['field_icporderid']['id'] = 'field_icporderid';
  $handler->display->display_options['fields']['field_icporderid']['table'] = 'field_data_field_icporderid';
  $handler->display->display_options['fields']['field_icporderid']['field'] = 'field_icporderid';
  /* 欄位: 內容: SoNet訂單編號 */
  $handler->display->display_options['fields']['field_sonetorderno']['id'] = 'field_sonetorderno';
  $handler->display->display_options['fields']['field_sonetorderno']['table'] = 'field_data_field_sonetorderno';
  $handler->display->display_options['fields']['field_sonetorderno']['field'] = 'field_sonetorderno';
  /* 欄位: 內容: 付款方式 */
  $handler->display->display_options['fields']['field_mpid']['id'] = 'field_mpid';
  $handler->display->display_options['fields']['field_mpid']['table'] = 'field_data_field_mpid';
  $handler->display->display_options['fields']['field_mpid']['field'] = 'field_mpid';
  /* 欄位: 內容: 會員名稱 */
  $handler->display->display_options['fields']['field_icpuserid']['id'] = 'field_icpuserid';
  $handler->display->display_options['fields']['field_icpuserid']['table'] = 'field_data_field_icpuserid';
  $handler->display->display_options['fields']['field_icpuserid']['field'] = 'field_icpuserid';
  $handler->display->display_options['fields']['field_icpuserid']['settings'] = array(
    'link' => 0,
  );
  /* 欄位: 使用者: facebook id */
  $handler->display->display_options['fields']['field_facebook_id']['id'] = 'field_facebook_id';
  $handler->display->display_options['fields']['field_facebook_id']['table'] = 'field_data_field_facebook_id';
  $handler->display->display_options['fields']['field_facebook_id']['field'] = 'field_facebook_id';
  $handler->display->display_options['fields']['field_facebook_id']['relationship'] = 'field_icpuserid_target_id';
  $handler->display->display_options['fields']['field_facebook_id']['label'] = 'Facebook id';
  /* 欄位: 內容: 金額 */
  $handler->display->display_options['fields']['field_price']['id'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['table'] = 'field_data_field_price';
  $handler->display->display_options['fields']['field_price']['field'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* 欄位: 內容: 訂單時間 */
  $handler->display->display_options['fields']['field_orderdatatime']['id'] = 'field_orderdatatime';
  $handler->display->display_options['fields']['field_orderdatatime']['table'] = 'field_data_field_orderdatatime';
  $handler->display->display_options['fields']['field_orderdatatime']['field'] = 'field_orderdatatime';
  $handler->display->display_options['fields']['field_orderdatatime']['label'] = '建立訂單時間';
  $handler->display->display_options['fields']['field_orderdatatime']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* 欄位: 內容: 訂單狀態 */
  $handler->display->display_options['fields']['field_payment_status']['id'] = 'field_payment_status';
  $handler->display->display_options['fields']['field_payment_status']['table'] = 'field_data_field_payment_status';
  $handler->display->display_options['fields']['field_payment_status']['field'] = 'field_payment_status';
  /* 欄位: 內容: 回傳錯誤訊息 */
  $handler->display->display_options['fields']['field_resultmesg']['id'] = 'field_resultmesg';
  $handler->display->display_options['fields']['field_resultmesg']['table'] = 'field_data_field_resultmesg';
  $handler->display->display_options['fields']['field_resultmesg']['field'] = 'field_resultmesg';
  /* Sort criterion: 內容: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: 內容: 已發表 */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: 內容: 類型 */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'deposit_record' => 'deposit_record',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: 內容: 付款種類 (field_payment_method) */
  $handler->display->display_options['filters']['field_payment_method_value']['id'] = 'field_payment_method_value';
  $handler->display->display_options['filters']['field_payment_method_value']['table'] = 'field_data_field_payment_method';
  $handler->display->display_options['filters']['field_payment_method_value']['field'] = 'field_payment_method_value';
  $handler->display->display_options['filters']['field_payment_method_value']['value'] = array(
    'smart_pay' => 'smart_pay',
  );
  $handler->display->display_options['filters']['field_payment_method_value']['group'] = 1;
  /* Filter criterion: 內容: 訂單編號 (field_icporderid) */
  $handler->display->display_options['filters']['field_icporderid_value']['id'] = 'field_icporderid_value';
  $handler->display->display_options['filters']['field_icporderid_value']['table'] = 'field_data_field_icporderid';
  $handler->display->display_options['filters']['field_icporderid_value']['field'] = 'field_icporderid_value';
  $handler->display->display_options['filters']['field_icporderid_value']['group'] = 1;
  $handler->display->display_options['filters']['field_icporderid_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['operator_id'] = 'field_icporderid_value_op';
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['label'] = '訂單編號';
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['operator'] = 'field_icporderid_value_op';
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['identifier'] = 'field_icporderid_value';
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['autocomplete_field'] = 'field_icporderid';
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: 內容: SoNet訂單編號 (field_sonetorderno) */
  $handler->display->display_options['filters']['field_sonetorderno_value']['id'] = 'field_sonetorderno_value';
  $handler->display->display_options['filters']['field_sonetorderno_value']['table'] = 'field_data_field_sonetorderno';
  $handler->display->display_options['filters']['field_sonetorderno_value']['field'] = 'field_sonetorderno_value';
  $handler->display->display_options['filters']['field_sonetorderno_value']['group'] = 1;
  $handler->display->display_options['filters']['field_sonetorderno_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['operator_id'] = 'field_sonetorderno_value_op';
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['label'] = 'SoNet訂單編號';
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['operator'] = 'field_sonetorderno_value_op';
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['identifier'] = 'field_sonetorderno_value';
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['autocomplete_field'] = 'field_sonetorderno';
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: 內容: 訂單狀態 (field_payment_status) */
  $handler->display->display_options['filters']['field_payment_status_value']['id'] = 'field_payment_status_value';
  $handler->display->display_options['filters']['field_payment_status_value']['table'] = 'field_data_field_payment_status';
  $handler->display->display_options['filters']['field_payment_status_value']['field'] = 'field_payment_status_value';
  $handler->display->display_options['filters']['field_payment_status_value']['group'] = 1;
  $handler->display->display_options['filters']['field_payment_status_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_payment_status_value']['expose']['operator_id'] = 'field_payment_status_value_op';
  $handler->display->display_options['filters']['field_payment_status_value']['expose']['label'] = '訂單狀態';
  $handler->display->display_options['filters']['field_payment_status_value']['expose']['operator'] = 'field_payment_status_value_op';
  $handler->display->display_options['filters']['field_payment_status_value']['expose']['identifier'] = 'field_payment_status_value';
  $handler->display->display_options['filters']['field_payment_status_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: 使用者: facebook id (field_facebook_id) */
  $handler->display->display_options['filters']['field_facebook_id_value']['id'] = 'field_facebook_id_value';
  $handler->display->display_options['filters']['field_facebook_id_value']['table'] = 'field_data_field_facebook_id';
  $handler->display->display_options['filters']['field_facebook_id_value']['field'] = 'field_facebook_id_value';
  $handler->display->display_options['filters']['field_facebook_id_value']['relationship'] = 'field_icpuserid_target_id';
  $handler->display->display_options['filters']['field_facebook_id_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['operator_id'] = 'field_facebook_id_value_op';
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['label'] = 'Facebook id';
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['description'] = '與遊戲內的Facebook ID相同';
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['operator'] = 'field_facebook_id_value_op';
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['identifier'] = 'field_facebook_id_value';
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['autocomplete_dependent'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/workbench/deposit-record/smart_pay';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = '消費性扣款';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['sonet_smart_pay'] = array(
    t('Master'),
    t('消費性扣款'),
    t('more'),
    t('Apply'),
    t('重設'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« 第一頁'),
    t('‹ 上一頁'),
    t('下一頁 ›'),
    t('最後一頁 »'),
    t('使用者 entity referenced from field_icpuserid'),
    t('訂單編號'),
    t('SoNet訂單編號'),
    t('付款方式'),
    t('會員名稱'),
    t('Facebook id'),
    t('金額'),
    t('建立訂單時間'),
    t('訂單狀態'),
    t('回傳錯誤訊息'),
    t('與遊戲內的Facebook ID相同'),
    t('Page'),
  );
  $export['sonet_smart_pay'] = $view;

  $view = new view();
  $view->name = 'sonet_spicy_card';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = '(sonet)辣椒卡';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = '辣椒卡付款';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = '重設';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '40';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« 第一頁';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ 上一頁';
  $handler->display->display_options['pager']['options']['tags']['next'] = '下一頁 ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = '最後一頁 »';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_icpuserid_target_id']['id'] = 'field_icpuserid_target_id';
  $handler->display->display_options['relationships']['field_icpuserid_target_id']['table'] = 'field_data_field_icpuserid';
  $handler->display->display_options['relationships']['field_icpuserid_target_id']['field'] = 'field_icpuserid_target_id';
  /* 欄位: 內容: 訂單編號 */
  $handler->display->display_options['fields']['field_icporderid']['id'] = 'field_icporderid';
  $handler->display->display_options['fields']['field_icporderid']['table'] = 'field_data_field_icporderid';
  $handler->display->display_options['fields']['field_icporderid']['field'] = 'field_icporderid';
  /* 欄位: 內容: SoNet訂單編號 */
  $handler->display->display_options['fields']['field_sonetorderno']['id'] = 'field_sonetorderno';
  $handler->display->display_options['fields']['field_sonetorderno']['table'] = 'field_data_field_sonetorderno';
  $handler->display->display_options['fields']['field_sonetorderno']['field'] = 'field_sonetorderno';
  /* 欄位: 內容: 付款方式 */
  $handler->display->display_options['fields']['field_mpid']['id'] = 'field_mpid';
  $handler->display->display_options['fields']['field_mpid']['table'] = 'field_data_field_mpid';
  $handler->display->display_options['fields']['field_mpid']['field'] = 'field_mpid';
  /* 欄位: 內容: 會員名稱 */
  $handler->display->display_options['fields']['field_icpuserid']['id'] = 'field_icpuserid';
  $handler->display->display_options['fields']['field_icpuserid']['table'] = 'field_data_field_icpuserid';
  $handler->display->display_options['fields']['field_icpuserid']['field'] = 'field_icpuserid';
  $handler->display->display_options['fields']['field_icpuserid']['settings'] = array(
    'link' => 0,
  );
  /* 欄位: 使用者: facebook id */
  $handler->display->display_options['fields']['field_facebook_id']['id'] = 'field_facebook_id';
  $handler->display->display_options['fields']['field_facebook_id']['table'] = 'field_data_field_facebook_id';
  $handler->display->display_options['fields']['field_facebook_id']['field'] = 'field_facebook_id';
  $handler->display->display_options['fields']['field_facebook_id']['relationship'] = 'field_icpuserid_target_id';
  $handler->display->display_options['fields']['field_facebook_id']['label'] = 'Facebook id';
  /* 欄位: 內容: 金額 */
  $handler->display->display_options['fields']['field_price']['id'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['table'] = 'field_data_field_price';
  $handler->display->display_options['fields']['field_price']['field'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* 欄位: 內容: 訂單時間 */
  $handler->display->display_options['fields']['field_orderdatatime']['id'] = 'field_orderdatatime';
  $handler->display->display_options['fields']['field_orderdatatime']['table'] = 'field_data_field_orderdatatime';
  $handler->display->display_options['fields']['field_orderdatatime']['field'] = 'field_orderdatatime';
  $handler->display->display_options['fields']['field_orderdatatime']['label'] = '建立訂單時間';
  $handler->display->display_options['fields']['field_orderdatatime']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* 欄位: 內容: 訂單狀態 */
  $handler->display->display_options['fields']['field_payment_status']['id'] = 'field_payment_status';
  $handler->display->display_options['fields']['field_payment_status']['table'] = 'field_data_field_payment_status';
  $handler->display->display_options['fields']['field_payment_status']['field'] = 'field_payment_status';
  /* 欄位: 內容: 回傳錯誤訊息 */
  $handler->display->display_options['fields']['field_resultmesg']['id'] = 'field_resultmesg';
  $handler->display->display_options['fields']['field_resultmesg']['table'] = 'field_data_field_resultmesg';
  $handler->display->display_options['fields']['field_resultmesg']['field'] = 'field_resultmesg';
  /* Sort criterion: 內容: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: 內容: 已發表 */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: 內容: 類型 */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'deposit_record' => 'deposit_record',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: 內容: 付款種類 (field_payment_method) */
  $handler->display->display_options['filters']['field_payment_method_value']['id'] = 'field_payment_method_value';
  $handler->display->display_options['filters']['field_payment_method_value']['table'] = 'field_data_field_payment_method';
  $handler->display->display_options['filters']['field_payment_method_value']['field'] = 'field_payment_method_value';
  $handler->display->display_options['filters']['field_payment_method_value']['value'] = array(
    'spicy_card' => 'spicy_card',
  );
  $handler->display->display_options['filters']['field_payment_method_value']['group'] = 1;
  /* Filter criterion: 內容: 訂單編號 (field_icporderid) */
  $handler->display->display_options['filters']['field_icporderid_value']['id'] = 'field_icporderid_value';
  $handler->display->display_options['filters']['field_icporderid_value']['table'] = 'field_data_field_icporderid';
  $handler->display->display_options['filters']['field_icporderid_value']['field'] = 'field_icporderid_value';
  $handler->display->display_options['filters']['field_icporderid_value']['group'] = 1;
  $handler->display->display_options['filters']['field_icporderid_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['operator_id'] = 'field_icporderid_value_op';
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['label'] = '訂單編號';
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['operator'] = 'field_icporderid_value_op';
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['identifier'] = 'field_icporderid_value';
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['autocomplete_field'] = 'field_icporderid';
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: 內容: SoNet訂單編號 (field_sonetorderno) */
  $handler->display->display_options['filters']['field_sonetorderno_value']['id'] = 'field_sonetorderno_value';
  $handler->display->display_options['filters']['field_sonetorderno_value']['table'] = 'field_data_field_sonetorderno';
  $handler->display->display_options['filters']['field_sonetorderno_value']['field'] = 'field_sonetorderno_value';
  $handler->display->display_options['filters']['field_sonetorderno_value']['group'] = 1;
  $handler->display->display_options['filters']['field_sonetorderno_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['operator_id'] = 'field_sonetorderno_value_op';
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['label'] = 'SoNet訂單編號';
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['operator'] = 'field_sonetorderno_value_op';
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['identifier'] = 'field_sonetorderno_value';
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['autocomplete_field'] = 'field_sonetorderno';
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: 內容: 訂單狀態 (field_payment_status) */
  $handler->display->display_options['filters']['field_payment_status_value']['id'] = 'field_payment_status_value';
  $handler->display->display_options['filters']['field_payment_status_value']['table'] = 'field_data_field_payment_status';
  $handler->display->display_options['filters']['field_payment_status_value']['field'] = 'field_payment_status_value';
  $handler->display->display_options['filters']['field_payment_status_value']['group'] = 1;
  $handler->display->display_options['filters']['field_payment_status_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_payment_status_value']['expose']['operator_id'] = 'field_payment_status_value_op';
  $handler->display->display_options['filters']['field_payment_status_value']['expose']['label'] = '訂單狀態';
  $handler->display->display_options['filters']['field_payment_status_value']['expose']['operator'] = 'field_payment_status_value_op';
  $handler->display->display_options['filters']['field_payment_status_value']['expose']['identifier'] = 'field_payment_status_value';
  $handler->display->display_options['filters']['field_payment_status_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: 使用者: facebook id (field_facebook_id) */
  $handler->display->display_options['filters']['field_facebook_id_value']['id'] = 'field_facebook_id_value';
  $handler->display->display_options['filters']['field_facebook_id_value']['table'] = 'field_data_field_facebook_id';
  $handler->display->display_options['filters']['field_facebook_id_value']['field'] = 'field_facebook_id_value';
  $handler->display->display_options['filters']['field_facebook_id_value']['relationship'] = 'field_icpuserid_target_id';
  $handler->display->display_options['filters']['field_facebook_id_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['operator_id'] = 'field_facebook_id_value_op';
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['label'] = 'Facebook id';
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['description'] = '與遊戲內的Facebook ID相同';
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['operator'] = 'field_facebook_id_value_op';
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['identifier'] = 'field_facebook_id_value';
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['autocomplete_dependent'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/workbench/deposit-record/spicy_card';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = '辣椒卡付款';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['sonet_spicy_card'] = array(
    t('Master'),
    t('辣椒卡付款'),
    t('more'),
    t('Apply'),
    t('重設'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« 第一頁'),
    t('‹ 上一頁'),
    t('下一頁 ›'),
    t('最後一頁 »'),
    t('使用者 entity referenced from field_icpuserid'),
    t('訂單編號'),
    t('SoNet訂單編號'),
    t('付款方式'),
    t('會員名稱'),
    t('Facebook id'),
    t('金額'),
    t('建立訂單時間'),
    t('訂單狀態'),
    t('回傳錯誤訊息'),
    t('與遊戲內的Facebook ID相同'),
    t('Page'),
  );
  $export['sonet_spicy_card'] = $view;

  $view = new view();
  $view->name = 'sonet_super_store';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = '(sonet)超商代收';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = '超商代收';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = '重設';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '40';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« 第一頁';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ 上一頁';
  $handler->display->display_options['pager']['options']['tags']['next'] = '下一頁 ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = '最後一頁 »';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_icpuserid_target_id']['id'] = 'field_icpuserid_target_id';
  $handler->display->display_options['relationships']['field_icpuserid_target_id']['table'] = 'field_data_field_icpuserid';
  $handler->display->display_options['relationships']['field_icpuserid_target_id']['field'] = 'field_icpuserid_target_id';
  /* 欄位: 內容: 訂單編號 */
  $handler->display->display_options['fields']['field_icporderid']['id'] = 'field_icporderid';
  $handler->display->display_options['fields']['field_icporderid']['table'] = 'field_data_field_icporderid';
  $handler->display->display_options['fields']['field_icporderid']['field'] = 'field_icporderid';
  /* 欄位: 內容: SoNet訂單編號 */
  $handler->display->display_options['fields']['field_sonetorderno']['id'] = 'field_sonetorderno';
  $handler->display->display_options['fields']['field_sonetorderno']['table'] = 'field_data_field_sonetorderno';
  $handler->display->display_options['fields']['field_sonetorderno']['field'] = 'field_sonetorderno';
  /* 欄位: 內容: 付款方式 */
  $handler->display->display_options['fields']['field_mpid']['id'] = 'field_mpid';
  $handler->display->display_options['fields']['field_mpid']['table'] = 'field_data_field_mpid';
  $handler->display->display_options['fields']['field_mpid']['field'] = 'field_mpid';
  /* 欄位: 內容: 會員名稱 */
  $handler->display->display_options['fields']['field_icpuserid']['id'] = 'field_icpuserid';
  $handler->display->display_options['fields']['field_icpuserid']['table'] = 'field_data_field_icpuserid';
  $handler->display->display_options['fields']['field_icpuserid']['field'] = 'field_icpuserid';
  $handler->display->display_options['fields']['field_icpuserid']['settings'] = array(
    'link' => 0,
  );
  /* 欄位: 使用者: facebook id */
  $handler->display->display_options['fields']['field_facebook_id']['id'] = 'field_facebook_id';
  $handler->display->display_options['fields']['field_facebook_id']['table'] = 'field_data_field_facebook_id';
  $handler->display->display_options['fields']['field_facebook_id']['field'] = 'field_facebook_id';
  $handler->display->display_options['fields']['field_facebook_id']['relationship'] = 'field_icpuserid_target_id';
  $handler->display->display_options['fields']['field_facebook_id']['label'] = 'Facebook id';
  /* 欄位: 內容: 金額 */
  $handler->display->display_options['fields']['field_price']['id'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['table'] = 'field_data_field_price';
  $handler->display->display_options['fields']['field_price']['field'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* 欄位: 內容: 訂單時間 */
  $handler->display->display_options['fields']['field_orderdatatime']['id'] = 'field_orderdatatime';
  $handler->display->display_options['fields']['field_orderdatatime']['table'] = 'field_data_field_orderdatatime';
  $handler->display->display_options['fields']['field_orderdatatime']['field'] = 'field_orderdatatime';
  $handler->display->display_options['fields']['field_orderdatatime']['label'] = '建立訂單時間';
  $handler->display->display_options['fields']['field_orderdatatime']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* 欄位: 內容: 繳款編號 */
  $handler->display->display_options['fields']['field_storeorderno']['id'] = 'field_storeorderno';
  $handler->display->display_options['fields']['field_storeorderno']['table'] = 'field_data_field_storeorderno';
  $handler->display->display_options['fields']['field_storeorderno']['field'] = 'field_storeorderno';
  /* 欄位: 內容: 繳款期限 */
  $handler->display->display_options['fields']['field_limitdatetime']['id'] = 'field_limitdatetime';
  $handler->display->display_options['fields']['field_limitdatetime']['table'] = 'field_data_field_limitdatetime';
  $handler->display->display_options['fields']['field_limitdatetime']['field'] = 'field_limitdatetime';
  $handler->display->display_options['fields']['field_limitdatetime']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* 欄位: 內容: 訂單狀態 */
  $handler->display->display_options['fields']['field_payment_status']['id'] = 'field_payment_status';
  $handler->display->display_options['fields']['field_payment_status']['table'] = 'field_data_field_payment_status';
  $handler->display->display_options['fields']['field_payment_status']['field'] = 'field_payment_status';
  /* 欄位: 內容: 回傳錯誤訊息 */
  $handler->display->display_options['fields']['field_resultmesg']['id'] = 'field_resultmesg';
  $handler->display->display_options['fields']['field_resultmesg']['table'] = 'field_data_field_resultmesg';
  $handler->display->display_options['fields']['field_resultmesg']['field'] = 'field_resultmesg';
  /* Sort criterion: 內容: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: 內容: 已發表 */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: 內容: 類型 */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'deposit_record' => 'deposit_record',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: 內容: 付款種類 (field_payment_method) */
  $handler->display->display_options['filters']['field_payment_method_value']['id'] = 'field_payment_method_value';
  $handler->display->display_options['filters']['field_payment_method_value']['table'] = 'field_data_field_payment_method';
  $handler->display->display_options['filters']['field_payment_method_value']['field'] = 'field_payment_method_value';
  $handler->display->display_options['filters']['field_payment_method_value']['value'] = array(
    'super_store' => 'super_store',
  );
  $handler->display->display_options['filters']['field_payment_method_value']['group'] = 1;
  /* Filter criterion: 內容: 訂單編號 (field_icporderid) */
  $handler->display->display_options['filters']['field_icporderid_value']['id'] = 'field_icporderid_value';
  $handler->display->display_options['filters']['field_icporderid_value']['table'] = 'field_data_field_icporderid';
  $handler->display->display_options['filters']['field_icporderid_value']['field'] = 'field_icporderid_value';
  $handler->display->display_options['filters']['field_icporderid_value']['group'] = 1;
  $handler->display->display_options['filters']['field_icporderid_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['operator_id'] = 'field_icporderid_value_op';
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['label'] = '訂單編號';
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['operator'] = 'field_icporderid_value_op';
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['identifier'] = 'field_icporderid_value';
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['autocomplete_field'] = 'field_icporderid';
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_icporderid_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: 內容: SoNet訂單編號 (field_sonetorderno) */
  $handler->display->display_options['filters']['field_sonetorderno_value']['id'] = 'field_sonetorderno_value';
  $handler->display->display_options['filters']['field_sonetorderno_value']['table'] = 'field_data_field_sonetorderno';
  $handler->display->display_options['filters']['field_sonetorderno_value']['field'] = 'field_sonetorderno_value';
  $handler->display->display_options['filters']['field_sonetorderno_value']['group'] = 1;
  $handler->display->display_options['filters']['field_sonetorderno_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['operator_id'] = 'field_sonetorderno_value_op';
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['label'] = 'SoNet訂單編號';
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['operator'] = 'field_sonetorderno_value_op';
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['identifier'] = 'field_sonetorderno_value';
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['autocomplete_field'] = 'field_sonetorderno';
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_sonetorderno_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: 內容: 繳款編號 (field_storeorderno) */
  $handler->display->display_options['filters']['field_storeorderno_value']['id'] = 'field_storeorderno_value';
  $handler->display->display_options['filters']['field_storeorderno_value']['table'] = 'field_data_field_storeorderno';
  $handler->display->display_options['filters']['field_storeorderno_value']['field'] = 'field_storeorderno_value';
  $handler->display->display_options['filters']['field_storeorderno_value']['group'] = 1;
  $handler->display->display_options['filters']['field_storeorderno_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_storeorderno_value']['expose']['operator_id'] = 'field_storeorderno_value_op';
  $handler->display->display_options['filters']['field_storeorderno_value']['expose']['label'] = '繳款編號';
  $handler->display->display_options['filters']['field_storeorderno_value']['expose']['description'] = '例如：IBON繳款號碼、FAMI繳款號碼';
  $handler->display->display_options['filters']['field_storeorderno_value']['expose']['operator'] = 'field_storeorderno_value_op';
  $handler->display->display_options['filters']['field_storeorderno_value']['expose']['identifier'] = 'field_storeorderno_value';
  $handler->display->display_options['filters']['field_storeorderno_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_storeorderno_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_storeorderno_value']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['field_storeorderno_value']['expose']['autocomplete_field'] = 'field_storeorderno';
  $handler->display->display_options['filters']['field_storeorderno_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_storeorderno_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_storeorderno_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: 內容: 訂單狀態 (field_payment_status) */
  $handler->display->display_options['filters']['field_payment_status_value']['id'] = 'field_payment_status_value';
  $handler->display->display_options['filters']['field_payment_status_value']['table'] = 'field_data_field_payment_status';
  $handler->display->display_options['filters']['field_payment_status_value']['field'] = 'field_payment_status_value';
  $handler->display->display_options['filters']['field_payment_status_value']['group'] = 1;
  $handler->display->display_options['filters']['field_payment_status_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_payment_status_value']['expose']['operator_id'] = 'field_payment_status_value_op';
  $handler->display->display_options['filters']['field_payment_status_value']['expose']['label'] = '訂單狀態';
  $handler->display->display_options['filters']['field_payment_status_value']['expose']['operator'] = 'field_payment_status_value_op';
  $handler->display->display_options['filters']['field_payment_status_value']['expose']['identifier'] = 'field_payment_status_value';
  $handler->display->display_options['filters']['field_payment_status_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: 內容: 付款方式 (field_mpid) */
  $handler->display->display_options['filters']['field_mpid_value']['id'] = 'field_mpid_value';
  $handler->display->display_options['filters']['field_mpid_value']['table'] = 'field_data_field_mpid';
  $handler->display->display_options['filters']['field_mpid_value']['field'] = 'field_mpid_value';
  $handler->display->display_options['filters']['field_mpid_value']['value'] = array(
    'IBON' => 'IBON',
    'FAMIPORT' => 'FAMIPORT',
    'LIFEET' => 'LIFEET',
  );
  $handler->display->display_options['filters']['field_mpid_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_mpid_value']['expose']['operator_id'] = 'field_mpid_value_op';
  $handler->display->display_options['filters']['field_mpid_value']['expose']['label'] = '付款方式';
  $handler->display->display_options['filters']['field_mpid_value']['expose']['operator'] = 'field_mpid_value_op';
  $handler->display->display_options['filters']['field_mpid_value']['expose']['identifier'] = 'field_mpid_value';
  $handler->display->display_options['filters']['field_mpid_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_mpid_value']['expose']['reduce'] = TRUE;
  /* Filter criterion: 使用者: facebook id (field_facebook_id) */
  $handler->display->display_options['filters']['field_facebook_id_value']['id'] = 'field_facebook_id_value';
  $handler->display->display_options['filters']['field_facebook_id_value']['table'] = 'field_data_field_facebook_id';
  $handler->display->display_options['filters']['field_facebook_id_value']['field'] = 'field_facebook_id_value';
  $handler->display->display_options['filters']['field_facebook_id_value']['relationship'] = 'field_icpuserid_target_id';
  $handler->display->display_options['filters']['field_facebook_id_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['operator_id'] = 'field_facebook_id_value_op';
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['label'] = 'Facebook id';
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['description'] = '與遊戲內的Facebook ID相同';
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['operator'] = 'field_facebook_id_value_op';
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['identifier'] = 'field_facebook_id_value';
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_facebook_id_value']['expose']['autocomplete_dependent'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/workbench/deposit-record/super_store';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = '超商代收';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['sonet_super_store'] = array(
    t('Master'),
    t('超商代收'),
    t('more'),
    t('Apply'),
    t('重設'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« 第一頁'),
    t('‹ 上一頁'),
    t('下一頁 ›'),
    t('最後一頁 »'),
    t('使用者 entity referenced from field_icpuserid'),
    t('訂單編號'),
    t('SoNet訂單編號'),
    t('付款方式'),
    t('會員名稱'),
    t('Facebook id'),
    t('金額'),
    t('建立訂單時間'),
    t('繳款編號'),
    t('繳款期限'),
    t('訂單狀態'),
    t('回傳錯誤訊息'),
    t('例如：IBON繳款號碼、FAMI繳款號碼'),
    t('與遊戲內的Facebook ID相同'),
    t('Page'),
  );
  $export['sonet_super_store'] = $view;

  return $export;
}
