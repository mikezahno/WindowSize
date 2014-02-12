<?php

// /*
//  * Implements hook_form_FORM_ID_alter().
//  */
// function windowsize_form_system_theme_settings_alter(&$form, &$form_state, $form_id) {
//   $form['windowsize'] = array(
//     '#type'        => 'fieldset',
//     '#title'       => t('WindowSize Widget Settings'),
//     '#weight'      => 20,
//     '#tree'        => FALSE,
//   );
// 
//   $form['windowsize']['toggle_windowsize'] = array(
//     '#type'          => 'checkbox',
//     '#title'         => t('Toggle Window Size'),
//     '#description'   => t('Check the box to turn the widget on and make it visible. Uncheck it to hide it.'),
//     '#default_value' => theme_get_setting('toggle_windowsize'),
//   );
// 
//   $position = theme_get_setting('windowsize_position');
//   $position_options = array(
//     'top-left'     => t('Top Left'),
//     'top-right'    => t('Top Right'),
//     'bottom-left'  => t('Bottom Left'),
//     'bottom-right' => t('Bottom Right'),
//   );
//   
//   $form['windowsize']['windowsize_position'] = array(
//     '#type'          => 'select',
//     '#title'         => t('Widget position'),
//     '#description'   => t('Select where on the screen the windowsize widget should appear'),
//     '#options'       => $position_options,
//     '#default_value' => $position ? $position : 'top-left',
//     '#states'        => array(
//       'visible'      => array(
//         ':input[name="toggle_windowsize"]' => array('checked' => TRUE),
//       ),
//     ),
//   );
//   
//   $breakpoints = theme_get_setting('windowsize_breakpoints');
//   $form['windowsize']['windowsize_breakpoints'] = array(
//     '#type'          => 'checkbox',
//     '#title'         => t('Show Twitter Bootstrap 3.x Breakpoints'),
//     '#description'   => t('Check the box to show Twitter Bootstrap 3.x Breakpoints. Uncheck it to hide em.'),
//     '#default_value' => theme_get_setting('windowsize_breakpoints'),
//   );
// }


/**
 * @file
 * Admin page callbacks for the windowsize module.
 */

/**
 * HTML5 Tools configuration page.
 */
function windowsize_admin_settings_form() {
  $form['windowsize'] = array(
    '#type'        => 'fieldset',
    '#title'       => t('WindowSize Widget Settings'),
    '#weight'      => 20,
    '#tree'        => FALSE,
  );

  $form['windowsize']['toggle_windowsize'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Toggle Window Size'),
    '#description'   => t('Check the box to turn the widget on and make it visible. Uncheck it to hide it.'),
    '#default_value' => variable_get('toggle_windowsize'),
  );

  $position = variable_get('windowsize_position');
  $position_options = array(
    'top-left'     => t('Top Left'),
    'top-right'    => t('Top Right'),
    'bottom-left'  => t('Bottom Left'),
    'bottom-right' => t('Bottom Right'),
  );
  
  $form['windowsize']['windowsize_position'] = array(
    '#type'          => 'select',
    '#title'         => t('Widget position'),
    '#description'   => t('Select where on the screen the windowsize widget should appear'),
    '#options'       => $position_options,
    '#default_value' => $position ? $position : 'top-left',
    '#states'        => array(
      'visible'      => array(
        ':input[name="toggle_windowsize"]' => array('checked' => TRUE),
      ),
    ),
  );
  
  $adminpage = variable_get('windowsize_adminpage');
  $form['windowsize']['windowsize_adminpage'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Widget in admin mode'),
    '#description'   => t('Check the box to show the widget on administration pages.'),
    '#default_value' => $adminpage,
    '#states'        => array(
      'visible'      => array(
        ':input[name="toggle_windowsize"]' => array('checked' => TRUE),
      ),
    ),
  );
  
  $breakpoints = variable_get('windowsize_breakpoints');
  $form['windowsize']['windowsize_breakpoints'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Show Twitter Bootstrap 3.x Breakpoints'),
    '#description'   => t('Check the box to show Twitter Bootstrap 3.x Breakpoints. Uncheck it to hide em.'),
    '#default_value' => variable_get('windowsize_breakpoints'),
    '#states'        => array(
      'visible'      => array(
        ':input[name="toggle_windowsize"]' => array('checked' => TRUE),
      ),
    ),
  );
  
  // page-admin
  
  
  // $form['windowsize_help_text'] = array(
  //   '#markup' => t("Helptext"),
  // );

  $form['#submit'][] = 'windowsize_admin_settings_submit';
  
  return system_settings_form($form);
}

function windowsize_admin_settings_submit(&$form, &$form_state) {
  // dpm($form_state['values']);
  // if ($form_state['values']['toggle_windowsize']==0 && $form_state['values']['windowsize_adminpage']==1){
  //   variable_set('windowsize_adminpage') == 0;
  // }
}