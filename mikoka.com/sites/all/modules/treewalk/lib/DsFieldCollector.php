<?php


class treewalk_DsFieldCollector {

  protected $entityType;
  protected $fields = array();
  protected $base;

  function __construct($entityType) {
    $this->entityType = $entityType;
    $this->base = array(
      'properties' => array(
        'settings' => array(
          'prev_label' => array(
            'type' => 'textfield',
            'description' => t('"Previous" label'),
          ),
          'next_label' => array(
            'type' => 'textfield',
            'description' => t('"Next" label'),
          ),
        ),
        'default' => array(
          'prev_label' => 'Previous item',
          'next_label' => 'Next item',
        ),
      ),
      'field_type' => DS_FIELD_TYPE_FUNCTION,
      // use ds native field_settings_form
      // 'module' => 'ds',
      'function' => 'treewalk_prev_next',
    );
  }

  function fieldInstance($bundle, $fieldname, $instance) {
    $fieldinfo = field_info_field($fieldname);
    switch ($fieldinfo['type']) {
      case 'taxonomy_term_reference':
      case 'entityreference':
        $key = 'treewalk__' . $fieldname;
        if (!isset($this->fields[$key])) {
          $this->fields[$key] = $this->$method($bundle, $fieldname, $instance, $fieldinfo);
          $this->fields[$key]['_treewalk']['fieldname'] = $fieldname;
          $this->fields[$key]['_treewalk']['type'] = $fieldinfo['type'];
          $this->fields[$key] += array(
            'title' => t('Prev / Next (!fieldname)', array('!fieldname' => $instance['label'])),
          ) + $this->base;
        }
        $this->fields[$key]['ui_limit'][] = $bundle . '|*';
      }
    }
  }

  function taxonomy() {
  }
}
