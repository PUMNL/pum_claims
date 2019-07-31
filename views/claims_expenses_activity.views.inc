<?php

$activity_type_option_group = civicrm_api3('OptionGroup', 'getvalue', array('return' => 'id', 'name' => 'activity_type'));
$claims_id = civicrm_api3('OptionValue', 'getvalue', array('name' => 'Claim', 'option_group_id' => $activity_type_option_group, 'return' => 'value'));

$view = new view();
$view->name = 'claim_expenses_activity';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'civicrm_activity';
$view->human_name = 'Claim/Expenses Activity';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Claim/Expenses';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'role';
$handler->display->display_options['access']['role'] = pum_claims_get_role_ids(pum_claims_get_roles_who_can_access_expenseform());
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'id' => 'id',
  'status' => 'status',
  'activity_type' => 'activity_type',
  'activity_date_time' => 'activity_date_time',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
  'id' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'status' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'activity_type' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'activity_date_time' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
/* Relationship: CiviCRM Activity Contacts: Activity Contact ID */
$handler->display->display_options['relationships']['contact_id']['id'] = 'contact_id';
$handler->display->display_options['relationships']['contact_id']['table'] = 'civicrm_activity_contact';
$handler->display->display_options['relationships']['contact_id']['field'] = 'contact_id';
$handler->display->display_options['relationships']['contact_id']['record_type'] = '3';
/* Relationship: CiviCRM Contacts: Drupal ID */
$handler->display->display_options['relationships']['drupal_id']['id'] = 'drupal_id';
$handler->display->display_options['relationships']['drupal_id']['table'] = 'civicrm_contact';
$handler->display->display_options['relationships']['drupal_id']['field'] = 'drupal_id';
$handler->display->display_options['relationships']['drupal_id']['relationship'] = 'contact_id';
$handler->display->display_options['relationships']['drupal_id']['required'] = TRUE;
/* Field: CiviCRM Activities: Activity ID */
$handler->display->display_options['fields']['id']['id'] = 'id';
$handler->display->display_options['fields']['id']['table'] = 'civicrm_activity';
$handler->display->display_options['fields']['id']['field'] = 'id';
$handler->display->display_options['fields']['id']['exclude'] = TRUE;
$handler->display->display_options['fields']['id']['separator'] = '';
/* Field: CiviCRM Activities: Activity Status */
$handler->display->display_options['fields']['status']['id'] = 'status';
$handler->display->display_options['fields']['status']['table'] = 'civicrm_activity';
$handler->display->display_options['fields']['status']['field'] = 'status';
$handler->display->display_options['fields']['status']['label'] = 'Status';
/* Field: CiviCRM Activities: Scheduled Activity Date */
$handler->display->display_options['fields']['activity_date_time']['id'] = 'activity_date_time';
$handler->display->display_options['fields']['activity_date_time']['table'] = 'civicrm_activity';
$handler->display->display_options['fields']['activity_date_time']['field'] = 'activity_date_time';
$handler->display->display_options['fields']['activity_date_time']['label'] = 'Date';
$handler->display->display_options['fields']['activity_date_time']['date_format'] = 'custom';
$handler->display->display_options['fields']['activity_date_time']['custom_date_format'] = 'Y-n-j';
$handler->display->display_options['fields']['activity_date_time']['second_date_format'] = 'long';
/* Field: CiviCRM Custom: Claiminformation: Pay/Receive */
$handler->display->display_options['fields']['pay_receive_390']['id'] = 'pay_receive_390';
$handler->display->display_options['fields']['pay_receive_390']['table'] = 'civicrm_value_claiminformation_70';
$handler->display->display_options['fields']['pay_receive_390']['field'] = 'pay_receive_390';
/* Field: CiviCRM Custom: Claiminformation: Claim Linked to */
$handler->display->display_options['fields']['pum_projectnumber_referencenumbe_387']['id'] = 'pum_projectnumber_referencenumbe_387';
$handler->display->display_options['fields']['pum_projectnumber_referencenumbe_387']['table'] = 'civicrm_value_claiminformation_70';
$handler->display->display_options['fields']['pum_projectnumber_referencenumbe_387']['field'] = 'pum_projectnumber_referencenumbe_387';
$handler->display->display_options['fields']['pum_projectnumber_referencenumbe_387']['label'] = 'PUM Projectnumber';
/* Field: CiviCRM Custom: Claiminformation: Currency */
$handler->display->display_options['fields']['currency_388']['id'] = 'currency_388';
$handler->display->display_options['fields']['currency_388']['table'] = 'civicrm_value_claiminformation_70';
$handler->display->display_options['fields']['currency_388']['field'] = 'currency_388';
/* Field: CiviCRM Custom: Claiminformation: Total Amount */
$handler->display->display_options['fields']['total_expenses_389']['id'] = 'total_expenses_389';
$handler->display->display_options['fields']['total_expenses_389']['table'] = 'civicrm_value_claiminformation_70';
$handler->display->display_options['fields']['total_expenses_389']['field'] = 'total_expenses_389';
$handler->display->display_options['fields']['total_expenses_389']['label'] = 'Amount';
$handler->display->display_options['fields']['total_expenses_389']['exclude'] = TRUE;
$handler->display->display_options['fields']['total_expenses_389']['alter']['text'] = '[currency_388] [total_expenses_389]';
/* Field: Signed Amount */
$handler->display->display_options['fields']['php']['id'] = 'php';
$handler->display->display_options['fields']['php']['table'] = 'views';
$handler->display->display_options['fields']['php']['field'] = 'php';
$handler->display->display_options['fields']['php']['ui_name'] = 'Signed Amount';
$handler->display->display_options['fields']['php']['label'] = 'Amount';
$handler->display->display_options['fields']['php']['use_php_setup'] = 0;
$handler->display->display_options['fields']['php']['php_output'] = '<?php
if ($row->pay_receive_390 == "To receive from PUM") {
echo $row->total_expenses_389;
} else if ($row->pay_receive_390 == "To be paid to PUM") {
echo "-".$row->total_expenses_389;
}
?>';
$handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
$handler->display->display_options['fields']['php']['php_click_sortable'] = '';
/* Sort criterion: CiviCRM Activities: Scheduled Activity Date */
$handler->display->display_options['sorts']['activity_date_time']['id'] = 'activity_date_time';
$handler->display->display_options['sorts']['activity_date_time']['table'] = 'civicrm_activity';
$handler->display->display_options['sorts']['activity_date_time']['field'] = 'activity_date_time';
/* Filter criterion: CiviCRM Activities: Activity Type */
$handler->display->display_options['filters']['activity_type']['id'] = 'activity_type';
$handler->display->display_options['filters']['activity_type']['table'] = 'civicrm_activity';
$handler->display->display_options['filters']['activity_type']['field'] = 'activity_type';
$handler->display->display_options['filters']['activity_type']['value'] = array(
  $claims_id => $claims_id,
);
$handler->display->display_options['filters']['activity_type']['group'] = 1;
/* Filter criterion: User: Current */
$handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
$handler->display->display_options['filters']['uid_current']['table'] = 'users';
$handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
$handler->display->display_options['filters']['uid_current']['relationship'] = 'drupal_id';
$handler->display->display_options['filters']['uid_current']['value'] = '1';

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'expert/claim-expenses';
$handler->display->display_options['menu']['type'] = 'normal';
$handler->display->display_options['menu']['title'] = 'Claim/Expenses';
$handler->display->display_options['menu']['weight'] = '0';
$handler->display->display_options['menu']['name'] = 'menu-financials';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;
