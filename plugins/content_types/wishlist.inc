<?php
/**
 * @file
 * Wishlist pane for ctools.
 */

$plugin = array(
  'title' => t('User wishlist'),
  'description' => t('User wishlist items'),
  'single' => TRUE,
  'content_types' => array('list'),
  'required context' => new ctools_context_required(t('User'), 'user'),
  'category' => t('User'),
);

/**
* Implements MODULE_CONTENT_content_type_render().
*
* Render the block.
*/
function ding_wishlist_wishlist_content_type_render($subtype, $conf, $panel_args, $context) {
  $account = $context->data;

  $block         = new stdClass();
  $block->module = 'ding_wishlist';
  $block->delta  = 'wishlist';

  module_load_include('inc', 'ding_wishlist', 'ding_wishlist.pages');
  $block->content = ding_wishlist_user_wishlist_page($account);

  return $block;
}

/**
* Returns an edit form for the content type.
*
* We're not actually doing anything here, but we need to have this hook
* for this content type to work.
*/
function ding_wishlist_wishlist_content_type_edit_form($form, &$form_state) {
  return $form;
}