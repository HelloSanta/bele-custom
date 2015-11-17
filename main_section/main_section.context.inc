<?php
/**
 * @file
 * main_section.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function main_section_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'basic-page';
  $context->description = '基本頁面隱藏標題';
  $context->tag = 'bele';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'page' => 'page',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'no_title' => array(
      'no_title' => 1,
    ),
    'theme_html' => array(
      'class' => 'hide-breadcrumbs',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('bele');
  t('基本頁面隱藏標題');
  $export['basic-page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'main';
  $context->description = '網站首頁';
  $context->tag = 'bele';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-bele_slideshow-block' => array(
          'module' => 'views',
          'delta' => 'bele_slideshow-block',
          'region' => 'highlighted',
          'weight' => '-10',
        ),
        'menu_block-2' => array(
          'module' => 'menu_block',
          'delta' => '2',
          'region' => 'highlighted',
          'weight' => '-9',
        ),
        'menu_block-3' => array(
          'module' => 'menu_block',
          'delta' => '3',
          'region' => 'highlighted',
          'weight' => '-8',
        ),
        'views-bele_latest_news-block' => array(
          'module' => 'views',
          'delta' => 'bele_latest_news-block',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-ad_banner-block' => array(
          'module' => 'views',
          'delta' => 'ad_banner-block',
          'region' => 'content',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('bele');
  t('網站首頁');
  $export['main'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'main-article-board';
  $context->description = '網站首頁－學習專欄';
  $context->tag = 'bele';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'main/article-board' => 'main/article-board',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-bele_slideshow-block' => array(
          'module' => 'views',
          'delta' => 'bele_slideshow-block',
          'region' => 'highlighted',
          'weight' => '-10',
        ),
        'menu_block-2' => array(
          'module' => 'menu_block',
          'delta' => '2',
          'region' => 'highlighted',
          'weight' => '-9',
        ),
        'menu_block-3' => array(
          'module' => 'menu_block',
          'delta' => '3',
          'region' => 'highlighted',
          'weight' => '-8',
        ),
        'views-bele_article_board-block' => array(
          'module' => 'views',
          'delta' => 'bele_article_board-block',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-ad_banner-block' => array(
          'module' => 'views',
          'delta' => 'ad_banner-block',
          'region' => 'content',
          'weight' => '-9',
        ),
      ),
    ),
    'no_title' => array(
      'no_title' => 1,
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('bele');
  t('網站首頁－學習專欄');
  $export['main-article-board'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'main-class';
  $context->description = '網站首頁－課程介紹';
  $context->tag = 'bele';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'main/class' => 'main/class',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-bele_slideshow-block' => array(
          'module' => 'views',
          'delta' => 'bele_slideshow-block',
          'region' => 'highlighted',
          'weight' => '-10',
        ),
        'menu_block-2' => array(
          'module' => 'menu_block',
          'delta' => '2',
          'region' => 'highlighted',
          'weight' => '-9',
        ),
        'menu_block-3' => array(
          'module' => 'menu_block',
          'delta' => '3',
          'region' => 'highlighted',
          'weight' => '-8',
        ),
        'views-bele_class_introduce-block' => array(
          'module' => 'views',
          'delta' => 'bele_class_introduce-block',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-ad_banner-block' => array(
          'module' => 'views',
          'delta' => 'ad_banner-block',
          'region' => 'content',
          'weight' => '-9',
        ),
      ),
    ),
    'no_title' => array(
      'no_title' => 1,
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('bele');
  t('網站首頁－課程介紹');
  $export['main-class'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'main-consultant';
  $context->description = '網站首頁－顧問介紹';
  $context->tag = 'bele';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'main/consultant' => 'main/consultant',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-bele_slideshow-block' => array(
          'module' => 'views',
          'delta' => 'bele_slideshow-block',
          'region' => 'highlighted',
          'weight' => '-10',
        ),
        'menu_block-2' => array(
          'module' => 'menu_block',
          'delta' => '2',
          'region' => 'highlighted',
          'weight' => '-9',
        ),
        'menu_block-3' => array(
          'module' => 'menu_block',
          'delta' => '3',
          'region' => 'highlighted',
          'weight' => '-8',
        ),
        'views-bele_consultant-block_1' => array(
          'module' => 'views',
          'delta' => 'bele_consultant-block_1',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-ad_banner-block' => array(
          'module' => 'views',
          'delta' => 'ad_banner-block',
          'region' => 'content',
          'weight' => '-9',
        ),
      ),
    ),
    'no_title' => array(
      'no_title' => 1,
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('bele');
  t('網站首頁－顧問介紹');
  $export['main-consultant'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'main-online-consultant';
  $context->description = '網站首頁－線上諮詢';
  $context->tag = 'bele';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'main/online-consultant' => 'main/online-consultant',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-bele_slideshow-block' => array(
          'module' => 'views',
          'delta' => 'bele_slideshow-block',
          'region' => 'highlighted',
          'weight' => '-10',
        ),
        'menu_block-2' => array(
          'module' => 'menu_block',
          'delta' => '2',
          'region' => 'highlighted',
          'weight' => '-9',
        ),
        'menu_block-3' => array(
          'module' => 'menu_block',
          'delta' => '3',
          'region' => 'highlighted',
          'weight' => '-8',
        ),
        'views-bele_online_consultant-block' => array(
          'module' => 'views',
          'delta' => 'bele_online_consultant-block',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-ad_banner-block' => array(
          'module' => 'views',
          'delta' => 'ad_banner-block',
          'region' => 'content',
          'weight' => '-9',
        ),
      ),
    ),
    'no_title' => array(
      'no_title' => 1,
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('bele');
  t('網站首頁－線上諮詢');
  $export['main-online-consultant'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'main-public';
  $context->description = '網站首頁－公益分享';
  $context->tag = 'bele';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'main/public' => 'main/public',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-bele_slideshow-block' => array(
          'module' => 'views',
          'delta' => 'bele_slideshow-block',
          'region' => 'highlighted',
          'weight' => '-10',
        ),
        'menu_block-2' => array(
          'module' => 'menu_block',
          'delta' => '2',
          'region' => 'highlighted',
          'weight' => '-9',
        ),
        'menu_block-3' => array(
          'module' => 'menu_block',
          'delta' => '3',
          'region' => 'highlighted',
          'weight' => '-8',
        ),
        'views-bele_public-block' => array(
          'module' => 'views',
          'delta' => 'bele_public-block',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-ad_banner-block' => array(
          'module' => 'views',
          'delta' => 'ad_banner-block',
          'region' => 'content',
          'weight' => '-9',
        ),
      ),
    ),
    'no_title' => array(
      'no_title' => 1,
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('bele');
  t('網站首頁－公益分享');
  $export['main-public'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'main-video';
  $context->description = '網站首頁－影音報導';
  $context->tag = 'bele';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'main/video' => 'main/video',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-bele_slideshow-block' => array(
          'module' => 'views',
          'delta' => 'bele_slideshow-block',
          'region' => 'highlighted',
          'weight' => '-10',
        ),
        'menu_block-2' => array(
          'module' => 'menu_block',
          'delta' => '2',
          'region' => 'highlighted',
          'weight' => '-9',
        ),
        'menu_block-3' => array(
          'module' => 'menu_block',
          'delta' => '3',
          'region' => 'highlighted',
          'weight' => '-8',
        ),
        'views-bele_video-block' => array(
          'module' => 'views',
          'delta' => 'bele_video-block',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-ad_banner-block' => array(
          'module' => 'views',
          'delta' => 'ad_banner-block',
          'region' => 'content',
          'weight' => '-9',
        ),
      ),
    ),
    'no_title' => array(
      'no_title' => 1,
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('bele');
  t('網站首頁－影音報導');
  $export['main-video'] = $context;

  return $export;
}
