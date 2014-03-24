<?php

/**
 * @file
 * Administration and settings for Mission Control.
 */

mission_control_check_safe_mode();

/**
 * Administration UI for Mission Control.
 */
function mission_control_settings() {
  $form = array();

  $form['type'] = array(
    '#type' => 'vertical_tabs',
  );

  $form['display_options'] = array(
    '#type' => 'fieldset',
    '#title' => t('Display options'),
    '#group' => 'type',
  );

  $form['display_options']['enable_git_data'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable displaying of git information'),
    '#default_value' => variable_get('enable_git_data', 0),
  );
  $form['display_options']['git_path'] = array(
    '#type' => 'textfield',
    '#size' => 30,
    '#title' => t('Full path to git repository'),
    '#description' => t('Git repository must be accessible via a local path.'),
    '#maxlength' => 255,
    '#required' => FALSE,
    '#default_value' => variable_get('git_path', ''),
    '#states' => mission_control_depends_on('enable_git_data'),
  );
  $form['display_options']['enable_render_time'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable displaying render time'),
    '#default_value' => variable_get('enable_render_time', 0),
  );
  $form['display_options']['enable_caching_output'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable displaying of cache calls'),
    '#default_value' => variable_get('enable_caching_output', 0),
  );
  $form['display_options']['enable_sql_output'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable displaying of SQL calls'),
    '#default_value' => variable_get('enable_sql_output', 0),
  );
  $form['display_options']['enable_background_task'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable displaying of background tasks'),
    '#default_value' => variable_get('enable_background_task', 0),
  );
  $form['display_options']['enable_directory_sizes'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable displaying of directory sizes for cached CSS and JS files'),
    '#default_value' => variable_get('enable_directory_sizes', 0),
  );

  return system_settings_form($form);
}

/**
 * Run a check to determine if safe mode is enabled and alert the user.
 */
function mission_control_check_safe_mode() {
  if (ini_get('safe_mode')) {
    return drupal_set_message(t('Safe mode is enabled. You will not be able to use the git functionality.'), 'warning');
  }
}
