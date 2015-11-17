<?php
/**
 * @file
 * premium_article.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function premium_article_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|premium_article|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'premium_article';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'post_date_by_author' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h1',
        'class' => 'node-title',
        'ft' => array(),
      ),
    ),
  );
  $export['node|premium_article|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|premium_article|paid_view_mode';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'premium_article';
  $ds_fieldsetting->view_mode = 'paid_view_mode';
  $ds_fieldsetting->settings = array(
    'post_date_by_author' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h1',
        'class' => 'node-title',
        'ft' => array(),
      ),
    ),
  );
  $export['node|premium_article|paid_view_mode'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function premium_article_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'commerce_product|class|default';
  $ds_layout->entity_type = 'commerce_product';
  $ds_layout->bundle = 'class';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col_wrapper';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'sku',
        1 => 'title',
        2 => 'commerce_price',
        3 => 'status',
      ),
    ),
    'fields' => array(
      'sku' => 'ds_content',
      'title' => 'ds_content',
      'commerce_price' => 'ds_content',
      'status' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['commerce_product|class|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|premium_article|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'premium_article';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col_wrapper';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_article_list_taxonomy',
        1 => 'title',
        2 => 'post_date_by_author',
        3 => 'body',
        4 => 'product:commerce_price',
        5 => 'field_premium_content',
        6 => 'sharethis',
        7 => 'field_tags',
      ),
    ),
    'fields' => array(
      'field_article_list_taxonomy' => 'ds_content',
      'title' => 'ds_content',
      'post_date_by_author' => 'ds_content',
      'body' => 'ds_content',
      'product:commerce_price' => 'ds_content',
      'field_premium_content' => 'ds_content',
      'sharethis' => 'ds_content',
      'field_tags' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        'node-content-region' => 'node-content-region',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|premium_article|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|premium_article|paid_view_mode';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'premium_article';
  $ds_layout->view_mode = 'paid_view_mode';
  $ds_layout->layout = 'ds_1col_wrapper';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_article_list_taxonomy',
        1 => 'title',
        2 => 'post_date_by_author',
        3 => 'bele123_paid_content_entity_view_1',
        4 => 'sharethis',
        5 => 'field_tags',
      ),
    ),
    'fields' => array(
      'field_article_list_taxonomy' => 'ds_content',
      'title' => 'ds_content',
      'post_date_by_author' => 'ds_content',
      'bele123_paid_content_entity_view_1' => 'ds_content',
      'sharethis' => 'ds_content',
      'field_tags' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        'node-content-region' => 'node-content-region',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|premium_article|paid_view_mode'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function premium_article_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'paid_view_mode';
  $ds_view_mode->label = 'Paid View Mode';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['paid_view_mode'] = $ds_view_mode;

  return $export;
}
