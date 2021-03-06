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

  $form['git_information'] = array(
    '#type' => 'fieldset',
    '#title' => t('Git integration'),
    '#group' => 'type',
  );
  $form['server_information'] = array(
    '#type' => 'fieldset',
    '#title' => t('Server details'),
    '#group' => 'type',
  );
  $form['page_render'] = array(
    '#type' => 'fieldset',
    '#title' => t('Page render'),
    '#group' => 'type',
  );
  $form['cache'] = array(
    '#type' => 'fieldset',
    '#title' => t('Cache'),
    '#group' => 'type',
  );
  $form['database'] = array(
    '#type' => 'fieldset',
    '#title' => t('Database and SQL'),
    '#group' => 'type',
  );
  $form['assets'] = array(
    '#type' => 'fieldset',
    '#title' => t('Assets'),
    '#group' => 'type',
  );
  $form['background_tasks'] = array(
    '#type' => 'fieldset',
    '#title' => t('Background tasks'),
    '#group' => 'type',
  );

  $form['git_information']['mission_control_enable_git_data'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable displaying of git information'),
    '#default_value' => variable_get('mission_control_enable_git_data', 0),
  );
  $form['git_information']['mission_control_git_path'] = array(
    '#type' => 'textfield',
    '#size' => 30,
    '#title' => t('Full path to git repository'),
    '#description' => t('Git repository must be accessible via a local path'),
    '#maxlength' => 255,
    '#required' => FALSE,
    '#default_value' => variable_get('mission_control_git_path', ''),
    '#states' => mission_control_depends_on('enable_git_data'),
  );
  $form['server_information']['mission_control_show_hostname'] = array(
    '#type' => 'checkbox',
    '#title' => t('Display hostname of the current server'),
    '#default_value' => variable_get('mission_control_show_hostname', 0),
  );
  $form['server_information']['mission_control_use_fqdn_hostname'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use FQDN for server hostname'),
    '#default_value' => variable_get('mission_control_use_fqdn_hostname', 0),
    '#states' => mission_control_depends_on('show_hostname'),
    '#description' => t('Instead of using just the sub domain of a host, you can use the full hostname'),
  );
  $form['page_render']['mission_control_enable_render_time'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show page render time'),
    '#default_value' => variable_get('mission_control_enable_render_time', 0),
  );
  $form['cache']['mission_control_enable_caching_output'] = array(
    '#type' => 'checkbox',
    '#title' => t('Display statistics for objects served from the database cache'),
    '#default_value' => variable_get('mission_control_enable_caching_output', 0),
  );
  $form['cache']['mission_control_include_memcache_cache_backends'] = array(
    '#type' => 'checkbox',
    '#title' => t('Include details from memcache backends in the cache metrics'),
    '#default_value' => variable_get('mission_control_include_memcache_cache_backends', 0),
    '#description' => t('If you use an additional memcache backend for caching, you will need to enable this to get accurate data'),
  );
  $form['database']['mission_control_enable_sql_output'] = array(
    '#type' => 'checkbox',
    '#title' => t('Display information around all SQL calls being executed'),
    '#default_value' => variable_get('mission_control_enable_sql_output', 0),
  );
  $form['database']['mission_control_slow_sql_threshold'] = array(
    '#type' => 'select',
    '#title' => t('Slow query threshold'),
    '#description' => t('Time (in milliseconds) that you would like to flag as a slow SQL query.'),
    '#options' => array(
      '0' => '0 (Disable)',
      '5' => 5,
      '10' => 10,
      '15' => 15,
      '20' => 20,
      '25' => 25,
      '30' => 30,
      '35' => 35,
      '40' => 40,
      '45' => 45,
      '50' => 50,
    ),
    '#default_value' => variable_get('mission_control_slow_sql_threshold'),
  );
  $form['assets']['mission_control_enable_directory_sizes'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable displaying of directory sizes for cached CSS and JS files'),
    '#description' => t('Note: If you do not have aggregration enabled, it will just display N/A'),
    '#default_value' => variable_get('mission_control_enable_directory_sizes', 0),
  );
  $form['background_tasks']['mission_control_enable_batch_count'] = array(
    '#type' => 'checkbox',
    '#title' => t('Display a count of active batch processes'),
    '#default_value' => variable_get('mission_control_enable_batch_count', 0),
  );
  $form['background_tasks']['mission_control_enable_queue_count'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show a count of active queues'),
    '#default_value' => variable_get('mission_control_enable_queue_count', 0),
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
