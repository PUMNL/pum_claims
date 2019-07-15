<?php
/**
 * Configuration page for pum_claims
 */
function pum_claims_admin_settings($form, &$form_state) {
  $form['pum_claims'] = array(
    '#type' => 'vertical_tabs',
    '#title' => t('PUM Claims Settings'),
  );

  $form['pum_claims_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('PUM Claims Settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#description' => '',
    '#group' => 'pum_claims',
  );

  $form['pum_claims_settings_manual'] = array(
    '#type' => 'fieldset',
    '#title' => t('Manual'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#description' => '',
    '#group' => 'pum_claims_settings',
  );
  $form['pum_claims_settings_renumerationpolicy'] = array(
    '#type' => 'fieldset',
    '#title' => t('Renumeration Policy'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#description' => '',
    '#group' => 'pum_claims_settings',
  );
  $form['pum_claims_settings_manual']['pum_claims_linkmanual_text_en'] = array(
    '#type' => 'textfield',
    '#title' => t('Text description for link to english manual'),
    '#default_value' => variable_get('pum_claims_linkmanual_text_en', NULL),
    '#description' => t('Enter the text description for link to english manual.'),
  );
  $form['pum_claims_settings_manual']['pum_claims_linkmanual_en'] = array(
    '#type' => 'textfield',
    '#title' => t('Link to english manual'),
    '#default_value' => variable_get('pum_claims_linkmanual_en', NULL),
    '#description' => t('Enter the relative URL to the english manual for claims.'),
  );
  $form['pum_claims_settings_manual']['pum_claims_linkmanual_text_nl'] = array(
    '#type' => 'textfield',
    '#title' => t('Text description for link to dutch manual'),
    '#default_value' => variable_get('pum_claims_linkmanual_text_nl', NULL),
    '#description' => t('Enter the text description for link to dutch manual.'),
  );
  $form['pum_claims_settings_manual']['pum_claims_linkmanual_nl'] = array(
    '#type' => 'textfield',
    '#title' => t('Link to dutch manual'),
    '#default_value' => variable_get('pum_claims_linkmanual_nl', NULL),
    '#description' => t('Enter the relative URL to the dutch manual for claims.'),
  );
  $form['pum_claims_settings_renumerationpolicy']['pum_claims_linkrenumerationpolicy_text_en'] = array(
    '#type' => 'textfield',
    '#title' => t('Text description for link to enlish renumeration policy'),
    '#default_value' => variable_get('pum_claims_linkrenumerationpolicy_text_en', NULL),
    '#description' => t('Enter the text description for link to enlish renumeration policy.'),
  );
  $form['pum_claims_settings_renumerationpolicy']['pum_claims_linkrenumerationpolicy_en'] = array(
    '#type' => 'textfield',
    '#title' => t('Link to enlish renumeration policy'),
    '#default_value' => variable_get('pum_claims_linkrenumerationpolicy_en', NULL),
    '#description' => t('Enter the relative URL to the english renumeration policy for claims.'),
  );
  $form['pum_claims_settings_renumerationpolicy']['pum_claims_linkrenumerationpolicy_text_nl'] = array(
    '#type' => 'textfield',
    '#title' => t('Text description for link to dutch renumeration policy'),
    '#default_value' => variable_get('pum_claims_linkrenumerationpolicy_text_nl', NULL),
    '#description' => t('Enter the text description for link to dutch renumeration policy.'),
  );
  $form['pum_claims_settings_renumerationpolicy']['pum_claims_linkrenumerationpolicy_nl'] = array(
    '#type' => 'textfield',
    '#title' => t('Link to dutch renumeration policy'),
    '#default_value' => variable_get('pum_claims_linkrenumerationpolicy_nl', NULL),
    '#description' => t('Enter the relative URL to the dutch renumeration policy for claims.'),
  );

  return system_settings_form($form);
}