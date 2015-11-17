<?php
/**
 * @file
 * premium_article.features.inc
 */

/**
 * Implements hook_commerce_product_default_types().
 */
function premium_article_commerce_product_default_types() {
  $items = array(
    'product' => array(
      'type' => 'product',
      'name' => '付費文章',
      'description' => '付費文章產品',
      'help' => '',
      'revision' => 1,
    ),
  );
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function premium_article_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function premium_article_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function premium_article_node_info() {
  $items = array(
    'premium_article' => array(
      'name' => t('付費文章'),
      'base' => 'node_content',
      'description' => t('所有付費的文章專欄在這裏建立'),
      'has_title' => '1',
      'title_label' => t('標題'),
      'help' => '',
    ),
    'premium_content' => array(
      'name' => t('詳細付費內容'),
      'base' => 'node_content',
      'description' => t('詳細付費內容'),
      'has_title' => '1',
      'title_label' => t('標題'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
