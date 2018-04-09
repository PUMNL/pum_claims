<?php

$claimActivityTypeId = civicrm_api3('OptionValue', 'getvalue', array('name' => 'Claim', 'option_group_id' => 'activity_type', 'return' => 'value'));
$claimInformationCustomGroup = civicrm_api3('CustomGroup', 'getsingle', array('name' => 'Claiminformation'));
$expensesCustomField = civicrm_api3('CustomField', 'getsingle', array('name' => 'Total_Expenses', 'custom_group_id' => $claimInformationCustomGroup['id']));
$descriptionCustomField = civicrm_api3('CustomField', 'getsingle', array('name' => 'Description', 'custom_group_id' => $claimInformationCustomGroup['id']));
$claimStatusCustomField = civicrm_api3('CustomField', 'getsingle', array('name' => 'pum_claim_status', 'custom_group_id' => $claimInformationCustomGroup['id']));

$view = new view();
$view->name = 'claims';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'civicrm_activity';
$view->human_name = 'Claims';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Claims';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'role';
$handler->display->display_options['access']['role'] = pum_claims_get_role_ids(pum_claims_get_roles_who_can_access());
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '25';
$handler->display->display_options['style_plugin'] = 'table';
/* Header: Global: Text area */
$handler->display->display_options['header']['area']['id'] = 'area';
$handler->display->display_options['header']['area']['table'] = 'views';
$handler->display->display_options['header']['area']['field'] = 'area';
$handler->display->display_options['header']['area']['empty'] = TRUE;
$handler->display->display_options['header']['area']['content'] = '<p><a href="/portal/new-claim" class="button">Submit a new claim</a></p>';
$handler->display->display_options['header']['area']['format'] = 'filtered_html';
/* Relationship: CiviCRM Activity Contacts: Activity Contact ID */
$handler->display->display_options['relationships']['contact_id']['id'] = 'contact_id';
$handler->display->display_options['relationships']['contact_id']['table'] = 'civicrm_activity_contact';
$handler->display->display_options['relationships']['contact_id']['field'] = 'contact_id';
$handler->display->display_options['relationships']['contact_id']['label'] = 'Contact';
$handler->display->display_options['relationships']['contact_id']['element_label_colon'] = FALSE;
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
/* Field: CiviCRM Custom: Claiminformation: Claim Status */
$handler->display->display_options['fields']['status']['id'] = 'status';
$handler->display->display_options['fields']['status']['table'] = $claimInformationCustomGroup['table_name'];
$handler->display->display_options['fields']['status']['field'] = $claimStatusCustomField['column_name'];
$handler->display->display_options['fields']['status']['alter']['nl2br'] = TRUE;
$handler->display->display_options['fields']['status']['alter']['strip_tags'] = TRUE;
/* Field: CiviCRM Activities: Scheduled Activity Date */
$handler->display->display_options['fields']['activity_date_time']['id'] = 'activity_date_time';
$handler->display->display_options['fields']['activity_date_time']['table'] = 'civicrm_activity';
$handler->display->display_options['fields']['activity_date_time']['field'] = 'activity_date_time';
$handler->display->display_options['fields']['activity_date_time']['label'] = 'Expense date';
$handler->display->display_options['fields']['activity_date_time']['date_format'] = 'custom';
$handler->display->display_options['fields']['activity_date_time']['custom_date_format'] = 'Y-m-d';
$handler->display->display_options['fields']['activity_date_time']['second_date_format'] = 'long';
/* Field: CiviCRM Custom: Claiminformation: Total Amount */
$handler->display->display_options['fields']['description']['id'] = 'description';
$handler->display->display_options['fields']['description']['table'] = $claimInformationCustomGroup['table_name'];
$handler->display->display_options['fields']['description']['field'] = $descriptionCustomField['column_name'];
$handler->display->display_options['fields']['description']['alter']['nl2br'] = TRUE;
$handler->display->display_options['fields']['description']['alter']['strip_tags'] = TRUE;
/* Field: Global: PHP */
$handler->display->display_options['fields']['amount_submitted']['id'] = 'amount_submitted';
$handler->display->display_options['fields']['amount_submitted']['table'] = 'views';
$handler->display->display_options['fields']['amount_submitted']['field'] = 'php';
$handler->display->display_options['fields']['amount_submitted']['label'] = 'Amount submitted';
$handler->display->display_options['fields']['amount_submitted']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['amount_submitted']['use_php_setup'] = 0;
$handler->display->display_options['fields']['amount_submitted']['php_output'] = '<?php $submitted_amount = pum_claims_get_amount_submitted($row->id); echo "&euro; " . number_format($submitted_amount, 2, \'.\', \',\'); ?>';
/* Field: Global: PHP */
$handler->display->display_options['fields']['amount_approved']['id'] = 'amount_approved';
$handler->display->display_options['fields']['amount_approved']['table'] = 'views';
$handler->display->display_options['fields']['amount_approved']['field'] = 'php';
$handler->display->display_options['fields']['amount_approved']['label'] = 'Amount approved';
$handler->display->display_options['fields']['amount_approved']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['amount_approved']['use_php_setup'] = 0;
$handler->display->display_options['fields']['amount_approved']['php_output'] = '<?php $approved_amount = pum_claims_get_amount_approved($row->id); if ($approved_amount) { echo "&euro; " . number_format($approved_amount, 2, \'.\', \',\'); } ?>';
/* Field: View-edit claim link */
$handler->display->display_options['fields']['php']['id'] = 'php';
$handler->display->display_options['fields']['php']['table'] = 'views';
$handler->display->display_options['fields']['php']['field'] = 'php';
$handler->display->display_options['fields']['php']['ui_name'] = 'View-edit claim link';
$handler->display->display_options['fields']['php']['label'] = '';
$handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['php']['use_php_setup'] = 0;
$handler->display->display_options['fields']['php']['php_output'] = '<?php _pum_claims_view_edit_claim_link($row->id); ?>';
$handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
$handler->display->display_options['fields']['php']['php_click_sortable'] = '';
/* Field: Delete claim link */
$handler->display->display_options['fields']['php_1']['id'] = 'php_1';
$handler->display->display_options['fields']['php_1']['table'] = 'views';
$handler->display->display_options['fields']['php_1']['field'] = 'php';
$handler->display->display_options['fields']['php_1']['ui_name'] = 'Delete claim link';
$handler->display->display_options['fields']['php_1']['label'] = '';
$handler->display->display_options['fields']['php_1']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
$handler->display->display_options['fields']['php_1']['php_output'] = '<?php _pum_claims_delete_claim_link($row->id); ?>';
$handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
$handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
/* Sort criterion: CiviCRM Activities: Scheduled Activity Date */
$handler->display->display_options['sorts']['activity_date_time']['id'] = 'activity_date_time';
$handler->display->display_options['sorts']['activity_date_time']['table'] = 'civicrm_activity';
$handler->display->display_options['sorts']['activity_date_time']['field'] = 'activity_date_time';
$handler->display->display_options['sorts']['activity_date_time']['order'] = 'DESC';
/* Filter criterion: CiviCRM Activities: Activity Type */
$handler->display->display_options['filters']['activity_type']['id'] = 'activity_type';
$handler->display->display_options['filters']['activity_type']['table'] = 'civicrm_activity';
$handler->display->display_options['filters']['activity_type']['field'] = 'activity_type';
$handler->display->display_options['filters']['activity_type']['value'] = array(
    $claimActivityTypeId => $claimActivityTypeId,
);
/* Filter criterion: User: Current */
$handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
$handler->display->display_options['filters']['uid_current']['table'] = 'users';
$handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
$handler->display->display_options['filters']['uid_current']['relationship'] = 'drupal_id';
$handler->display->display_options['filters']['uid_current']['value'] = '1';

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'portal/claims';
$handler->display->display_options['menu']['type'] = 'normal';
$handler->display->display_options['menu']['title'] = 'Claims';
$handler->display->display_options['menu']['weight'] = '0';
$handler->display->display_options['menu']['name'] = 'menu-financials';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;

$translatables['claims'] = array(
    t('Master'),
    t('Claims'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('<p><a href="/portal/new-claim" class="button">Submit a new claim</a></p>'),
    t('Contact'),
    t('Drupal User'),
    t('Activity ID'),
    t('.'),
    t('Status'),
    t('Expense date'),
    t('Subject'),
    t('Page'),
);
