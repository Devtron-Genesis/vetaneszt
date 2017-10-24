<?php

/**
 * @file
 * Contains all hooks and related methods for the lightgallery_formatter field
 * formatter.
 */

/**
 * Implements hook_field_formatter_info().
 */
function lightgallery_field_formatter_info() {
  return array(
    'lightgallery' => array(
      'label' => t('Lightgallery'),
      'field types' => array('image'),
      'settings' => array(
        'image_styles' => array(
          'lightgallery_image_style' => NULL,
          'lightgallery_image_thumb_style' => NULL,
        ),
        'lightgallery_core' => array(
          'mode' => 'lg-slide',
          'preload' => 1,
          'closable' => TRUE,
          'loop' => TRUE,
          'esc_key' => TRUE,
          'key_press' => TRUE,
          'controls' => TRUE,
          'mouse_wheel' => TRUE,
          'download' => TRUE,
          'counter' => TRUE,
          'drag' => TRUE,
          'touch' => TRUE,
        ),
        'lightgallery_thumbs' => array(
          'thumbnails' => TRUE,
          'animate_thumb' => TRUE,
          'current_pager_position' => 'middle',
          'thumb_width' => 100,
          'thumb_cont_height' => 100,
        ),
      ),
    ),
  );
}

/**
 * Implements hook_field_formatter_settings_form().
 */
function lightgallery_field_formatter_settings_form($field, $instance, $view_mode, $form, &$form_state) {
  $display = $instance['display'][$view_mode];
  $settings = $display['settings'];

  $image_styles = image_style_options(FALSE);

  $element['image_styles']['lightgallery_image_style'] = array(
    '#title' => t('Lightgallery image style'),
    '#type' => 'select',
    '#default_value' => $settings['image_styles']['lightgallery_image_style'],
    '#empty_option' => t('None (original image)'),
    '#options' => $image_styles,
    '#description' => t('Light gallery image style.'),
  );

  $element['image_styles']['lightgallery_image_thumb_style'] = array(
    '#title' => t('Content image style'),
    '#type' => 'select',
    '#default_value' => $settings['image_styles']['lightgallery_image_thumb_style'],
    '#empty_option' => t('None (original image)'),
    '#options' => $image_styles,
    '#description' => t('Content image style.'),
  );

  // Core options.
  $element['lightgallery_core'] = array(
    '#type' => 'fieldset',
    '#title' => t('Lightgallery core settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $element['lightgallery_core']['mode'] = array(
    '#type' => 'select',
    '#title' => t('Transition'),
    '#options' => _lightgallery_get_modes(),
    '#default_value' => $settings['lightgallery_core']['mode'],
    '#description' => t('Type of transition between images.'),
  );

  $element['lightgallery_core']['preload'] = array(
    '#type' => 'select',
    '#title' => t('Preload'),
    '#options' => drupal_map_assoc(array(1, 2, 3, 4)),
    '#default_value' => $settings['lightgallery_core']['preload'],
    '#description' => t('number of preload slides. will exicute only after the current slide is fully loaded.'),
  );

  $element['lightgallery_core']['closable'] = array(
    '#type' => 'checkbox',
    '#title' => t('Closable'),
    '#default_value' => $settings['lightgallery_core']['closable'],
    '#description' => t('Allows clicks on dimmer to close gallery.')
  );

  $element['lightgallery_core']['loop'] = array(
    '#type' => 'checkbox',
    '#title' => t('Loop'),
    '#default_value' => $settings['lightgallery_core']['loop'],
    '#description' => t('If not selected, the ability to loop back to the beginning of the gallery when on the last element, will be disabled.')
  );

  $element['lightgallery_core']['esc_key'] = array(
    '#type' => 'checkbox',
    '#title' => t('Escape key'),
    '#default_value' => $settings['lightgallery_core']['esc_key'],
    '#description' => t('Whether the LightGallery could be closed by pressing the "Esc" key.')
  );

  $element['lightgallery_core']['key_press'] = array(
    '#type' => 'checkbox',
    '#title' => t('Keyboard'),
    '#default_value' => $settings['lightgallery_core']['key_press'],
    '#description' => t('Enable keyboard navigation.')
  );

  $element['lightgallery_core']['controls'] = array(
    '#type' => 'checkbox',
    '#title' => t('Controls'),
    '#default_value' => $settings['lightgallery_core']['controls'],
    '#description' => t('If not checked, prev/next buttons will not be displayed.')
  );

  $element['lightgallery_core']['mouse_wheel'] = array(
    '#type' => 'checkbox',
    '#title' => t('Mouse wheel'),
    '#default_value' => $settings['lightgallery_core']['mouse_wheel'],
    '#description' => t('Chane slide on mousewheel')
  );

  $element['lightgallery_core']['download'] = array(
    '#type' => 'checkbox',
    '#title' => t('Download'),
    '#default_value' => $settings['lightgallery_core']['download'],
    '#description' => t('Enable download button. '
        . 'By default download url will be taken from data-src/href attribute but it supports only for modern browsers.'),
  );

  $element['lightgallery_core']['counter'] = array(
    '#type' => 'checkbox',
    '#title' => t('Counter'),
    '#default_value' => $settings['lightgallery_core']['counter'],
    '#description' => t('Whether to show total number of images and index number of currently displayed image.'),
  );

  $element['lightgallery_core']['drag'] = array(
    '#type' => 'checkbox',
    '#title' => t('Drag'),
    '#default_value' => $settings['lightgallery_core']['drag'],
    '#description' => t('Enables desktop mouse drag support.'),
  );

  $element['lightgallery_core']['touch'] = array(
    '#type' => 'checkbox',
    '#title' => t('Touch'),
    '#default_value' => $settings['lightgallery_core']['touch'],
    '#description' => t('Enables touch support.'),
  );

  // Thumb options.
  $element['lightgallery_thumbs'] = array(
    '#type' => 'fieldset',
    '#title' => t('Lightgallery thumbnail settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $element['lightgallery_thumbs']['thumbnails'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use thumbnails'),
    '#default_value' => $settings['lightgallery_thumbs']['thumbnails'],
    '#description' => t('Indicate if you want to use thumbnails in the LightGallery.')
  );

  $element['lightgallery_thumbs']['animate_thumb'] = array(
    '#type' => 'checkbox',
    '#title' => t('Animate thumbnails'),
    '#default_value' => $settings['lightgallery_thumbs']['animate_thumb'],
    '#description' => t('Enable thumbnail animation.')
  );

  $element['lightgallery_thumbs']['current_pager_position'] = array(
    '#type' => 'select',
    '#title' => t('Position'),
    '#options' => array('left' => t('Left'), 'middle' => t('Middle'), 'right' => t('Right')),
    '#default_value' => $settings['lightgallery_thumbs']['current_pager_position'],
    '#description' => t('Position of selected thumbnail.')
  );

  $element['lightgallery_thumbs']['thumb_width'] = array(
    '#type' => 'textfield',
    '#title' => t('Width'),
    '#default_value' => $settings['lightgallery_thumbs']['thumb_width'],
    '#description' => t('Width of each thumbnails.')
  );

  $element['lightgallery_thumbs']['thumb_cont_height'] = array(
    '#type' => 'textfield',
    '#title' => t('Height'),
    '#default_value' => $settings['lightgallery_thumbs']['thumb_cont_height'],
    '#description' => t('Height of the thumbnail container including padding and border.')
  );


  return $element;
}

/**
 * Implements hook_field_formatter_settings_summary().
 */
function lightgallery_field_formatter_settings_summary($field, $instance, $view_mode) {
  $display = $instance['display'][$view_mode];
  $settings = $display['settings'];

  $summary = array();

  $image_styles = image_style_options(FALSE);
  // Unset possible 'No defined styles' option.
  unset($image_styles['']);
  // Styles could be lost because of enabled/disabled modules that defines
  // their styles in code.
  if (isset($image_styles[$settings['image_styles']['lightgallery_image_style']])) {
    $summary[] = t('Lightgallery image style: @style',
        array('@style' => $image_styles[$settings['image_styles']['lightgallery_image_style']]));
  }
  else {
    $summary[] = t('Lightgallery image style: Original image');
  }

  if (isset($image_styles[$settings['image_styles']['lightgallery_image_thumb_style']])) {
    $summary[] = t('Content image style: @style',
        array('@style' => $image_styles[$settings['image_styles']['lightgallery_image_thumb_style']]));
  }
  else {
    $summary[] = t('Content image style: Original image');
  }

  $summary[] = ($settings['lightgallery_thumbs']['thumbnails']) ? t('Use thumbs in gallery: Yes') : t('Use thumbs in gallery: No');


  return implode('<br />', $summary);
}

/**
 * Implements hook_field_formatter_view().
 */
function lightgallery_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $element = array();

  // Render elements as one piece of markup so that items can be rendered as item list.
  $element[0] = array(
    '#theme' => 'lightgallery_image_formatter',
    '#items' => $items,
    '#entity_type' => $entity_type,
    '#entity' => $entity,
    '#node' => $entity, // Left for legacy support.
    '#field' => $field,
    '#display_settings' => $display['settings'],
  );


  return $element;
}
