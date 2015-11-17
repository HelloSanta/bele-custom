<?php
/**
 * @file
 * sonet_payment.features.inc
 */

/**
 * Implements hook_views_api().
 */
function sonet_payment_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function sonet_payment_node_info() {
  $items = array(
    'deposit_record' => array(
      'name' => t('儲值紀錄'),
      'base' => 'node_content',
      'description' => t('金流儲值紀錄'),
      'has_title' => '1',
      'title_label' => t('訂單編號'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
