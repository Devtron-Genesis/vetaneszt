<?php
/**
 * @file
 * events.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function events_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'events';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Events';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Events';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '518400';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '518400';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_event_type',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['row_class'] = 'col-md-12';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Start Date (field_start_date) */
  $handler->display->display_options['sorts']['field_start_date_value']['id'] = 'field_start_date_value';
  $handler->display->display_options['sorts']['field_start_date_value']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['sorts']['field_start_date_value']['field'] = 'field_start_date_value';
  $handler->display->display_options['sorts']['field_start_date_value']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'event' => 'event',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'event';

  /* Display: Events */
  $handler = $view->new_display('block', 'Events', 'events');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Start Date */
  $handler->display->display_options['fields']['field_start_date']['id'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['fields']['field_start_date']['field'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['label'] = '';
  $handler->display->display_options['fields']['field_start_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_start_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'field_formatter_class' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['path']['alter']['text'] = 'Learn more';
  $handler->display->display_options['fields']['path']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['path']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Logo */
  $handler->display->display_options['fields']['field_logo']['id'] = 'field_logo';
  $handler->display->display_options['fields']['field_logo']['table'] = 'field_data_field_logo';
  $handler->display->display_options['fields']['field_logo']['field'] = 'field_logo';
  $handler->display->display_options['fields']['field_logo']['label'] = '';
  $handler->display->display_options['fields']['field_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_logo']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
    'field_formatter_class' => '',
  );

  /* Display: Latest Events */
  $handler = $view->new_display('block', 'Latest Events', 'latest_events');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Events';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';

  /* Display: Sticky Events */
  $handler = $view->new_display('block', 'Sticky Events', 'block_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'col-md-12 row evnt';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h2>Featured Events</h2>';
  $handler->display->display_options['header']['area']['format'] = 'ace_editor';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: File Usage: File */
  $handler->display->display_options['relationships']['node_to_file']['id'] = 'node_to_file';
  $handler->display->display_options['relationships']['node_to_file']['table'] = 'file_usage';
  $handler->display->display_options['relationships']['node_to_file']['field'] = 'node_to_file';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Start Date */
  $handler->display->display_options['fields']['field_start_date']['id'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['fields']['field_start_date']['field'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['label'] = '';
  $handler->display->display_options['fields']['field_start_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_start_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_start_date']['settings'] = array(
    'format_type' => 'date',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'field_formatter_class' => '',
  );
  /* Field: Content: Start Date */
  $handler->display->display_options['fields']['field_start_date_1']['id'] = 'field_start_date_1';
  $handler->display->display_options['fields']['field_start_date_1']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['fields']['field_start_date_1']['field'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_start_date_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_start_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_start_date_1']['settings'] = array(
    'format_type' => 'month_and_year',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'field_formatter_class' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Event Location */
  $handler->display->display_options['fields']['field_event_location']['id'] = 'field_event_location';
  $handler->display->display_options['fields']['field_event_location']['table'] = 'field_data_field_event_location';
  $handler->display->display_options['fields']['field_event_location']['field'] = 'field_event_location';
  $handler->display->display_options['fields']['field_event_location']['label'] = '';
  $handler->display->display_options['fields']['field_event_location']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_event_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_location']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Field: Body */
  $handler->display->display_options['fields']['field_html_body']['id'] = 'field_html_body';
  $handler->display->display_options['fields']['field_html_body']['table'] = 'field_data_field_html_body';
  $handler->display->display_options['fields']['field_html_body']['field'] = 'field_html_body';
  $handler->display->display_options['fields']['field_html_body']['label'] = '';
  $handler->display->display_options['fields']['field_html_body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_html_body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_html_body']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Field: Link */
  $handler->display->display_options['fields']['field_link']['id'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['table'] = 'field_data_field_link';
  $handler->display->display_options['fields']['field_link']['field'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['label'] = '';
  $handler->display->display_options['fields']['field_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_link']['type'] = 'link_short';
  $handler->display->display_options['fields']['field_link']['settings'] = array(
    'field_formatter_class' => '',
  );
  $handler->display->display_options['fields']['field_link']['delta_limit'] = 'all';
  /* Field: Field: Link */
  $handler->display->display_options['fields']['field_link_1']['id'] = 'field_link_1';
  $handler->display->display_options['fields']['field_link_1']['table'] = 'field_data_field_link';
  $handler->display->display_options['fields']['field_link_1']['field'] = 'field_link';
  $handler->display->display_options['fields']['field_link_1']['label'] = '';
  $handler->display->display_options['fields']['field_link_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_link_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link_1']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_link_1']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_link_1']['settings'] = array(
    'field_formatter_class' => '',
  );
  $handler->display->display_options['fields']['field_link_1']['delta_limit'] = 'all';
  /* Field: File: Path */
  $handler->display->display_options['fields']['uri']['id'] = 'uri';
  $handler->display->display_options['fields']['uri']['table'] = 'file_managed';
  $handler->display->display_options['fields']['uri']['field'] = 'uri';
  $handler->display->display_options['fields']['uri']['relationship'] = 'node_to_file';
  $handler->display->display_options['fields']['uri']['label'] = '';
  $handler->display->display_options['fields']['uri']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uri']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uri']['file_download_path'] = TRUE;
  /* Field: Content: Logo */
  $handler->display->display_options['fields']['field_logo']['id'] = 'field_logo';
  $handler->display->display_options['fields']['field_logo']['table'] = 'field_data_field_logo';
  $handler->display->display_options['fields']['field_logo']['field'] = 'field_logo';
  $handler->display->display_options['fields']['field_logo']['label'] = '';
  $handler->display->display_options['fields']['field_logo']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_logo']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_logo']['alter']['text'] = '<a href="[field_link_1]" target="_blank" rel="nofollow"><img class="img-responsive" src="[uri]" alt="[field_logo-alt]" title="[field_logo-title]" /></a>';
  $handler->display->display_options['fields']['field_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_logo']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
    'field_formatter_class' => '',
  );
  /* Field: Content: Event Name */
  $handler->display->display_options['fields']['field_event_name']['id'] = 'field_event_name';
  $handler->display->display_options['fields']['field_event_name']['table'] = 'field_data_field_event_name';
  $handler->display->display_options['fields']['field_event_name']['field'] = 'field_event_name';
  $handler->display->display_options['fields']['field_event_name']['label'] = '';
  $handler->display->display_options['fields']['field_event_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_event_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_name']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="col-sm-1 col-xs-3 event-date">
  <div class="event-feature">
    <div class="day">[field_start_date]</div>
    <div>[field_start_date_1]</div>
  </div>
</div>
<div class="col-sm-9 col-xs-7">
  <div class="event-title">[field_event_name]</div>
   <div class="event-loc">[field_event_location]</div>
  <div class="event-txt">[field_html_body]</div>
  <div class="event-lnk">[field_link]</div>
</div>
<div class="col-xs-2">
<div class="event-img">[field_logo]</div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Start Date (field_start_date) */
  $handler->display->display_options['sorts']['field_start_date_value']['id'] = 'field_start_date_value';
  $handler->display->display_options['sorts']['field_start_date_value']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['sorts']['field_start_date_value']['field'] = 'field_start_date_value';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['operator'] = 'OR';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'event' => 'event',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Sticky */
  $handler->display->display_options['filters']['sticky']['id'] = 'sticky';
  $handler->display->display_options['filters']['sticky']['table'] = 'node';
  $handler->display->display_options['filters']['sticky']['field'] = 'sticky';
  $handler->display->display_options['filters']['sticky']['value'] = '1';
  $handler->display->display_options['filters']['sticky']['group'] = 1;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'node';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['value'] = '1';
  $handler->display->display_options['filters']['status_1']['group'] = 2;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'event' => 'event',
  );
  $handler->display->display_options['filters']['type_1']['group'] = 2;
  /* Filter criterion: Content: End Date (field_end_date) */
  $handler->display->display_options['filters']['field_end_date_value']['id'] = 'field_end_date_value';
  $handler->display->display_options['filters']['field_end_date_value']['table'] = 'field_data_field_end_date';
  $handler->display->display_options['filters']['field_end_date_value']['field'] = 'field_end_date_value';
  $handler->display->display_options['filters']['field_end_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_end_date_value']['group'] = 2;
  $handler->display->display_options['filters']['field_end_date_value']['form_type'] = 'date_text';
  $handler->display->display_options['filters']['field_end_date_value']['default_date'] = 'now';
  /* Filter criterion: Content: Start Date (field_start_date) */
  $handler->display->display_options['filters']['field_start_date_value']['id'] = 'field_start_date_value';
  $handler->display->display_options['filters']['field_start_date_value']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['filters']['field_start_date_value']['field'] = 'field_start_date_value';
  $handler->display->display_options['filters']['field_start_date_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_start_date_value']['group'] = 2;
  $handler->display->display_options['filters']['field_start_date_value']['expose']['operator_id'] = 'field_start_date_value_op';
  $handler->display->display_options['filters']['field_start_date_value']['expose']['label'] = 'Start Date (field_start_date)';
  $handler->display->display_options['filters']['field_start_date_value']['expose']['operator'] = 'field_start_date_value_op';
  $handler->display->display_options['filters']['field_start_date_value']['expose']['identifier'] = 'field_start_date_value';
  $handler->display->display_options['filters']['field_start_date_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    11 => 0,
  );
  $handler->display->display_options['filters']['field_start_date_value']['form_type'] = 'date_text';
  $handler->display->display_options['filters']['field_start_date_value']['default_date'] = 'now';

  /* Display: Upcoming Events */
  $handler = $view->new_display('block', 'Upcoming Events', 'block_2');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'col-md-12 row evnt';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h2>Upcoming Events</h2>';
  $handler->display->display_options['header']['area']['format'] = 'ace_editor';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: File Usage: File */
  $handler->display->display_options['relationships']['node_to_file']['id'] = 'node_to_file';
  $handler->display->display_options['relationships']['node_to_file']['table'] = 'file_usage';
  $handler->display->display_options['relationships']['node_to_file']['field'] = 'node_to_file';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Start Date */
  $handler->display->display_options['fields']['field_start_date']['id'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['fields']['field_start_date']['field'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['label'] = '';
  $handler->display->display_options['fields']['field_start_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_start_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_start_date']['settings'] = array(
    'format_type' => 'date',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'field_formatter_class' => '',
  );
  /* Field: Content: Start Date */
  $handler->display->display_options['fields']['field_start_date_1']['id'] = 'field_start_date_1';
  $handler->display->display_options['fields']['field_start_date_1']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['fields']['field_start_date_1']['field'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_start_date_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_start_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_start_date_1']['settings'] = array(
    'format_type' => 'month_and_year',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'field_formatter_class' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Event Location */
  $handler->display->display_options['fields']['field_event_location']['id'] = 'field_event_location';
  $handler->display->display_options['fields']['field_event_location']['table'] = 'field_data_field_event_location';
  $handler->display->display_options['fields']['field_event_location']['field'] = 'field_event_location';
  $handler->display->display_options['fields']['field_event_location']['label'] = '';
  $handler->display->display_options['fields']['field_event_location']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_event_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_location']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_event_location']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Field: Body */
  $handler->display->display_options['fields']['field_html_body']['id'] = 'field_html_body';
  $handler->display->display_options['fields']['field_html_body']['table'] = 'field_data_field_html_body';
  $handler->display->display_options['fields']['field_html_body']['field'] = 'field_html_body';
  $handler->display->display_options['fields']['field_html_body']['label'] = '';
  $handler->display->display_options['fields']['field_html_body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_html_body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_html_body']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Field: Link */
  $handler->display->display_options['fields']['field_link']['id'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['table'] = 'field_data_field_link';
  $handler->display->display_options['fields']['field_link']['field'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['label'] = '';
  $handler->display->display_options['fields']['field_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_link']['type'] = 'link_short';
  $handler->display->display_options['fields']['field_link']['settings'] = array(
    'field_formatter_class' => '',
  );
  $handler->display->display_options['fields']['field_link']['delta_limit'] = 'all';
  /* Field: Field: Link */
  $handler->display->display_options['fields']['field_link_1']['id'] = 'field_link_1';
  $handler->display->display_options['fields']['field_link_1']['table'] = 'field_data_field_link';
  $handler->display->display_options['fields']['field_link_1']['field'] = 'field_link';
  $handler->display->display_options['fields']['field_link_1']['label'] = '';
  $handler->display->display_options['fields']['field_link_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_link_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link_1']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_link_1']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_link_1']['settings'] = array(
    'field_formatter_class' => '',
  );
  $handler->display->display_options['fields']['field_link_1']['delta_limit'] = 'all';
  /* Field: File: Path */
  $handler->display->display_options['fields']['uri']['id'] = 'uri';
  $handler->display->display_options['fields']['uri']['table'] = 'file_managed';
  $handler->display->display_options['fields']['uri']['field'] = 'uri';
  $handler->display->display_options['fields']['uri']['relationship'] = 'node_to_file';
  $handler->display->display_options['fields']['uri']['label'] = '';
  $handler->display->display_options['fields']['uri']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uri']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uri']['file_download_path'] = TRUE;
  /* Field: Content: Logo */
  $handler->display->display_options['fields']['field_logo']['id'] = 'field_logo';
  $handler->display->display_options['fields']['field_logo']['table'] = 'field_data_field_logo';
  $handler->display->display_options['fields']['field_logo']['field'] = 'field_logo';
  $handler->display->display_options['fields']['field_logo']['label'] = '';
  $handler->display->display_options['fields']['field_logo']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_logo']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_logo']['alter']['text'] = '<a href="[field_link_1]" target="_blank" rel="nofollow"><img class="img-responsive" src="[uri]" alt="[field_logo-alt]" title="[field_logo-title]" /></a>';
  $handler->display->display_options['fields']['field_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_logo']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
    'field_formatter_class' => '',
  );
  /* Field: Content: Event Name */
  $handler->display->display_options['fields']['field_event_name']['id'] = 'field_event_name';
  $handler->display->display_options['fields']['field_event_name']['table'] = 'field_data_field_event_name';
  $handler->display->display_options['fields']['field_event_name']['field'] = 'field_event_name';
  $handler->display->display_options['fields']['field_event_name']['label'] = '';
  $handler->display->display_options['fields']['field_event_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_event_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_name']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="col-sm-1 col-xs-3 event-date">
  <div class="event-upcoming">
    <div class="day">[field_start_date]</div>
    <div>[field_start_date_1]</div>
  </div>
</div>
<div class="col-sm-9 col-xs-7">
  <div class="event-title">[field_event_name]</div>
   <div class="event-loc">[field_event_location]</div>
  <div class="event-txt">[field_html_body]</div>
  <div class="event-lnk">[field_link]</div>
</div>
<div class="col-xs-2">
<div class="event-img">[field_logo]</div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Start Date (field_start_date) */
  $handler->display->display_options['sorts']['field_start_date_value']['id'] = 'field_start_date_value';
  $handler->display->display_options['sorts']['field_start_date_value']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['sorts']['field_start_date_value']['field'] = 'field_start_date_value';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'event' => 'event',
  );
  /* Filter criterion: Content: Start Date (field_start_date) */
  $handler->display->display_options['filters']['field_start_date_value']['id'] = 'field_start_date_value';
  $handler->display->display_options['filters']['field_start_date_value']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['filters']['field_start_date_value']['field'] = 'field_start_date_value';
  $handler->display->display_options['filters']['field_start_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_start_date_value']['form_type'] = 'date_text';
  $handler->display->display_options['filters']['field_start_date_value']['default_date'] = 'now';

  /* Display: Past Events */
  $handler = $view->new_display('block', 'Past Events', 'block_3');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'col-md-12 row evnt';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h2>Past Events</h2>';
  $handler->display->display_options['header']['area']['format'] = 'ace_editor';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: File Usage: File */
  $handler->display->display_options['relationships']['node_to_file']['id'] = 'node_to_file';
  $handler->display->display_options['relationships']['node_to_file']['table'] = 'file_usage';
  $handler->display->display_options['relationships']['node_to_file']['field'] = 'node_to_file';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Start Date */
  $handler->display->display_options['fields']['field_start_date']['id'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['fields']['field_start_date']['field'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['label'] = '';
  $handler->display->display_options['fields']['field_start_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_start_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_start_date']['settings'] = array(
    'format_type' => 'date',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'field_formatter_class' => '',
  );
  /* Field: Content: Start Date */
  $handler->display->display_options['fields']['field_start_date_1']['id'] = 'field_start_date_1';
  $handler->display->display_options['fields']['field_start_date_1']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['fields']['field_start_date_1']['field'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_start_date_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_start_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_start_date_1']['settings'] = array(
    'format_type' => 'month_and_year',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'field_formatter_class' => '',
  );
  /* Field: Content: Event Name */
  $handler->display->display_options['fields']['field_event_name']['id'] = 'field_event_name';
  $handler->display->display_options['fields']['field_event_name']['table'] = 'field_data_field_event_name';
  $handler->display->display_options['fields']['field_event_name']['field'] = 'field_event_name';
  $handler->display->display_options['fields']['field_event_name']['label'] = '';
  $handler->display->display_options['fields']['field_event_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_event_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_name']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Event Location */
  $handler->display->display_options['fields']['field_event_location']['id'] = 'field_event_location';
  $handler->display->display_options['fields']['field_event_location']['table'] = 'field_data_field_event_location';
  $handler->display->display_options['fields']['field_event_location']['field'] = 'field_event_location';
  $handler->display->display_options['fields']['field_event_location']['label'] = '';
  $handler->display->display_options['fields']['field_event_location']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_event_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_location']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_event_location']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Field: Body */
  $handler->display->display_options['fields']['field_html_body']['id'] = 'field_html_body';
  $handler->display->display_options['fields']['field_html_body']['table'] = 'field_data_field_html_body';
  $handler->display->display_options['fields']['field_html_body']['field'] = 'field_html_body';
  $handler->display->display_options['fields']['field_html_body']['label'] = '';
  $handler->display->display_options['fields']['field_html_body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_html_body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_html_body']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Field: Link */
  $handler->display->display_options['fields']['field_link']['id'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['table'] = 'field_data_field_link';
  $handler->display->display_options['fields']['field_link']['field'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['label'] = '';
  $handler->display->display_options['fields']['field_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_link']['type'] = 'link_short';
  $handler->display->display_options['fields']['field_link']['settings'] = array(
    'field_formatter_class' => '',
  );
  $handler->display->display_options['fields']['field_link']['delta_limit'] = 'all';
  /* Field: Field: Link */
  $handler->display->display_options['fields']['field_link_1']['id'] = 'field_link_1';
  $handler->display->display_options['fields']['field_link_1']['table'] = 'field_data_field_link';
  $handler->display->display_options['fields']['field_link_1']['field'] = 'field_link';
  $handler->display->display_options['fields']['field_link_1']['label'] = '';
  $handler->display->display_options['fields']['field_link_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_link_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link_1']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_link_1']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_link_1']['settings'] = array(
    'field_formatter_class' => '',
  );
  $handler->display->display_options['fields']['field_link_1']['delta_limit'] = 'all';
  /* Field: File: Path */
  $handler->display->display_options['fields']['uri']['id'] = 'uri';
  $handler->display->display_options['fields']['uri']['table'] = 'file_managed';
  $handler->display->display_options['fields']['uri']['field'] = 'uri';
  $handler->display->display_options['fields']['uri']['relationship'] = 'node_to_file';
  $handler->display->display_options['fields']['uri']['label'] = '';
  $handler->display->display_options['fields']['uri']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uri']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uri']['file_download_path'] = TRUE;
  /* Field: Content: Logo */
  $handler->display->display_options['fields']['field_logo']['id'] = 'field_logo';
  $handler->display->display_options['fields']['field_logo']['table'] = 'field_data_field_logo';
  $handler->display->display_options['fields']['field_logo']['field'] = 'field_logo';
  $handler->display->display_options['fields']['field_logo']['label'] = '';
  $handler->display->display_options['fields']['field_logo']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_logo']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_logo']['alter']['text'] = '<a href="[field_link_1]" target="_blank" rel="nofollow"><img class="img-responsive" src="[uri]" alt="[field_logo-alt]" title="[field_logo-title]" /></a>';
  $handler->display->display_options['fields']['field_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_logo']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
    'field_formatter_class' => '',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="col-sm-1 col-xs-3 event-date">
  <div class="event-current">
    <div class="day">[field_start_date]</div>
    <div>[field_start_date_1]</div>
  </div>
</div>
<div class="col-sm-9 col-xs-7">
  <div class="event-title">[field_event_name]</div>
   <div class="event-loc">[field_event_location]</div>
  <div class="event-txt">[field_html_body]</div>
  <div class="event-lnk">[field_link]</div>
</div>
<div class="col-xs-2">
<div class="event-img">[field_logo]</div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'event' => 'event',
  );
  /* Filter criterion: Content: End Date (field_end_date) */
  $handler->display->display_options['filters']['field_end_date_value']['id'] = 'field_end_date_value';
  $handler->display->display_options['filters']['field_end_date_value']['table'] = 'field_data_field_end_date';
  $handler->display->display_options['filters']['field_end_date_value']['field'] = 'field_end_date_value';
  $handler->display->display_options['filters']['field_end_date_value']['operator'] = '<';
  $handler->display->display_options['filters']['field_end_date_value']['form_type'] = 'date_text';
  $handler->display->display_options['filters']['field_end_date_value']['default_date'] = 'now';
  $handler->display->display_options['filters']['field_end_date_value']['year_range'] = '-0:+0';

  /* Display: Current Events */
  $handler = $view->new_display('block', 'Current Events', 'block_4');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'col-md-12 row evnt';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h2>Current Events</h2>';
  $handler->display->display_options['header']['area']['format'] = 'ace_editor';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Start Date */
  $handler->display->display_options['fields']['field_start_date']['id'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['fields']['field_start_date']['field'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['label'] = '';
  $handler->display->display_options['fields']['field_start_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_start_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_start_date']['settings'] = array(
    'format_type' => 'date',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'field_formatter_class' => '',
  );
  /* Field: Content: Start Date */
  $handler->display->display_options['fields']['field_start_date_1']['id'] = 'field_start_date_1';
  $handler->display->display_options['fields']['field_start_date_1']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['fields']['field_start_date_1']['field'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_start_date_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_start_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_start_date_1']['settings'] = array(
    'format_type' => 'month_and_year',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'field_formatter_class' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Field: Body */
  $handler->display->display_options['fields']['field_html_body']['id'] = 'field_html_body';
  $handler->display->display_options['fields']['field_html_body']['table'] = 'field_data_field_html_body';
  $handler->display->display_options['fields']['field_html_body']['field'] = 'field_html_body';
  $handler->display->display_options['fields']['field_html_body']['label'] = '';
  $handler->display->display_options['fields']['field_html_body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_html_body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_html_body']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Logo */
  $handler->display->display_options['fields']['field_logo']['id'] = 'field_logo';
  $handler->display->display_options['fields']['field_logo']['table'] = 'field_data_field_logo';
  $handler->display->display_options['fields']['field_logo']['field'] = 'field_logo';
  $handler->display->display_options['fields']['field_logo']['label'] = '';
  $handler->display->display_options['fields']['field_logo']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_logo']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
    'field_formatter_class' => '',
  );
  /* Field: Content: Event Name */
  $handler->display->display_options['fields']['field_event_name']['id'] = 'field_event_name';
  $handler->display->display_options['fields']['field_event_name']['table'] = 'field_data_field_event_name';
  $handler->display->display_options['fields']['field_event_name']['field'] = 'field_event_name';
  $handler->display->display_options['fields']['field_event_name']['label'] = '';
  $handler->display->display_options['fields']['field_event_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_event_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_name']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="col-sm-2 col-xs-3 event-date">
  <div class="event-current">
    <div>[field_start_date]</div>
    <div>[field_start_date_1]</div>
  </div>
</div>
<div class="col-sm-8 col-xs-7">
  <div class="event-title">[field_event_name]</div>
  <div class="event-txt">[field_html_body]</div>
</div>
<div class="col-xs-2">
<div class="event-img">[field_logo]</div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'event' => 'event',
  );
  /* Filter criterion: Content: Start Date (field_start_date) */
  $handler->display->display_options['filters']['field_start_date_value']['id'] = 'field_start_date_value';
  $handler->display->display_options['filters']['field_start_date_value']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['filters']['field_start_date_value']['field'] = 'field_start_date_value';
  $handler->display->display_options['filters']['field_start_date_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_start_date_value']['form_type'] = 'date_text';
  $handler->display->display_options['filters']['field_start_date_value']['default_date'] = 'now';
  /* Filter criterion: Content: End Date (field_end_date) */
  $handler->display->display_options['filters']['field_end_date_value']['id'] = 'field_end_date_value';
  $handler->display->display_options['filters']['field_end_date_value']['table'] = 'field_data_field_end_date';
  $handler->display->display_options['filters']['field_end_date_value']['field'] = 'field_end_date_value';
  $handler->display->display_options['filters']['field_end_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_end_date_value']['form_type'] = 'date_text';
  $handler->display->display_options['filters']['field_end_date_value']['default_date'] = 'now';

  /* Display: All Events */
  $handler = $view->new_display('block', 'All Events', 'block_5');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '5';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Start Date */
  $handler->display->display_options['fields']['field_start_date']['id'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['fields']['field_start_date']['field'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['label'] = '';
  $handler->display->display_options['fields']['field_start_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_start_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_start_date']['settings'] = array(
    'format_type' => 'date',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'field_formatter_class' => '',
  );
  /* Field: Content: Start Date */
  $handler->display->display_options['fields']['field_start_date_1']['id'] = 'field_start_date_1';
  $handler->display->display_options['fields']['field_start_date_1']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['fields']['field_start_date_1']['field'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_start_date_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_start_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_start_date_1']['settings'] = array(
    'format_type' => 'month_and_year',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'field_formatter_class' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Field: Body */
  $handler->display->display_options['fields']['field_html_body']['id'] = 'field_html_body';
  $handler->display->display_options['fields']['field_html_body']['table'] = 'field_data_field_html_body';
  $handler->display->display_options['fields']['field_html_body']['field'] = 'field_html_body';
  $handler->display->display_options['fields']['field_html_body']['label'] = '';
  $handler->display->display_options['fields']['field_html_body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_html_body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_html_body']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Logo */
  $handler->display->display_options['fields']['field_logo']['id'] = 'field_logo';
  $handler->display->display_options['fields']['field_logo']['table'] = 'field_data_field_logo';
  $handler->display->display_options['fields']['field_logo']['field'] = 'field_logo';
  $handler->display->display_options['fields']['field_logo']['label'] = '';
  $handler->display->display_options['fields']['field_logo']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_logo']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
    'field_formatter_class' => '',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="event-img">[field_logo]</div>
';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'event' => 'event',
  );

  /* Display: Upcomimg Events Media Center */
  $handler = $view->new_display('block', 'Upcomimg Events Media Center', 'block_6');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Upcoming Events';
  $handler->display->display_options['display_description'] = 'For Media Center Page';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'See all events';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'col-md-12 row evnt';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = 'Upcoming Events';
  $handler->display->display_options['header']['area']['format'] = 'ace_editor';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<div class="see-all-lnk">
<a class="pull-right" href="/events">See all Events <i class="fa fa-arrow-right"></i></a>
</div>
';
  $handler->display->display_options['footer']['area']['format'] = 'ace_editor';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: File Usage: File */
  $handler->display->display_options['relationships']['node_to_file']['id'] = 'node_to_file';
  $handler->display->display_options['relationships']['node_to_file']['table'] = 'file_usage';
  $handler->display->display_options['relationships']['node_to_file']['field'] = 'node_to_file';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Start Date */
  $handler->display->display_options['fields']['field_start_date']['id'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['fields']['field_start_date']['field'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['label'] = '';
  $handler->display->display_options['fields']['field_start_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_start_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_start_date']['settings'] = array(
    'format_type' => 'date',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'field_formatter_class' => '',
  );
  /* Field: Content: Start Date */
  $handler->display->display_options['fields']['field_start_date_1']['id'] = 'field_start_date_1';
  $handler->display->display_options['fields']['field_start_date_1']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['fields']['field_start_date_1']['field'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_start_date_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_start_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_start_date_1']['settings'] = array(
    'format_type' => 'month_and_year',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'field_formatter_class' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Event Location */
  $handler->display->display_options['fields']['field_event_location']['id'] = 'field_event_location';
  $handler->display->display_options['fields']['field_event_location']['table'] = 'field_data_field_event_location';
  $handler->display->display_options['fields']['field_event_location']['field'] = 'field_event_location';
  $handler->display->display_options['fields']['field_event_location']['label'] = '';
  $handler->display->display_options['fields']['field_event_location']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_event_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_location']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Field: Body */
  $handler->display->display_options['fields']['field_html_body']['id'] = 'field_html_body';
  $handler->display->display_options['fields']['field_html_body']['table'] = 'field_data_field_html_body';
  $handler->display->display_options['fields']['field_html_body']['field'] = 'field_html_body';
  $handler->display->display_options['fields']['field_html_body']['label'] = '';
  $handler->display->display_options['fields']['field_html_body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_html_body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_html_body']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['text'] = 'Link to the event >';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['link_to_node'] = TRUE;
  /* Field: Field: Link */
  $handler->display->display_options['fields']['field_link']['id'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['table'] = 'field_data_field_link';
  $handler->display->display_options['fields']['field_link']['field'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['label'] = '';
  $handler->display->display_options['fields']['field_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_link']['type'] = 'link_short';
  $handler->display->display_options['fields']['field_link']['settings'] = array(
    'field_formatter_class' => '',
  );
  $handler->display->display_options['fields']['field_link']['delta_limit'] = 'all';
  /* Field: Field: Link */
  $handler->display->display_options['fields']['field_link_1']['id'] = 'field_link_1';
  $handler->display->display_options['fields']['field_link_1']['table'] = 'field_data_field_link';
  $handler->display->display_options['fields']['field_link_1']['field'] = 'field_link';
  $handler->display->display_options['fields']['field_link_1']['label'] = '';
  $handler->display->display_options['fields']['field_link_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_link_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link_1']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_link_1']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_link_1']['settings'] = array(
    'field_formatter_class' => '',
  );
  $handler->display->display_options['fields']['field_link_1']['delta_limit'] = 'all';
  /* Field: File: Path */
  $handler->display->display_options['fields']['uri']['id'] = 'uri';
  $handler->display->display_options['fields']['uri']['table'] = 'file_managed';
  $handler->display->display_options['fields']['uri']['field'] = 'uri';
  $handler->display->display_options['fields']['uri']['relationship'] = 'node_to_file';
  $handler->display->display_options['fields']['uri']['label'] = '';
  $handler->display->display_options['fields']['uri']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uri']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uri']['file_download_path'] = TRUE;
  /* Field: Content: Logo */
  $handler->display->display_options['fields']['field_logo']['id'] = 'field_logo';
  $handler->display->display_options['fields']['field_logo']['table'] = 'field_data_field_logo';
  $handler->display->display_options['fields']['field_logo']['field'] = 'field_logo';
  $handler->display->display_options['fields']['field_logo']['label'] = '';
  $handler->display->display_options['fields']['field_logo']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_logo']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_logo']['alter']['text'] = '<a href="[field_link_1]" target="_blank" rel="nofollow"><img class="img-responsive" src="[uri]" alt="[field_logo-alt]" title="[field_logo-title]" /></a>';
  $handler->display->display_options['fields']['field_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_logo']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
    'field_formatter_class' => '',
  );
  /* Field: Content: Event Name */
  $handler->display->display_options['fields']['field_event_name']['id'] = 'field_event_name';
  $handler->display->display_options['fields']['field_event_name']['table'] = 'field_data_field_event_name';
  $handler->display->display_options['fields']['field_event_name']['field'] = 'field_event_name';
  $handler->display->display_options['fields']['field_event_name']['label'] = '';
  $handler->display->display_options['fields']['field_event_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_event_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_name']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="col-sm-1 col-xs-3 event-date">
  <div class="event-upcoming">
    <div class="day">[field_start_date]</div>
    <div>[field_start_date_1]</div>
  </div>
</div>
<div class="col-sm-9 col-xs-7">
  <div class="event-title">[field_event_name]</div>
   <div class="event-loc">[field_event_location]</div>
  <div class="event-txt">[field_html_body]</div>
  <div class="event-lnk">[field_link]</div>
</div>
<div class="col-xs-2">
<div class="event-img">[field_logo]</div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Start Date (field_start_date) */
  $handler->display->display_options['sorts']['field_start_date_value']['id'] = 'field_start_date_value';
  $handler->display->display_options['sorts']['field_start_date_value']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['sorts']['field_start_date_value']['field'] = 'field_start_date_value';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'event' => 'event',
  );
  /* Filter criterion: Content: Start Date (field_start_date) */
  $handler->display->display_options['filters']['field_start_date_value']['id'] = 'field_start_date_value';
  $handler->display->display_options['filters']['field_start_date_value']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['filters']['field_start_date_value']['field'] = 'field_start_date_value';
  $handler->display->display_options['filters']['field_start_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_start_date_value']['form_type'] = 'date_text';
  $handler->display->display_options['filters']['field_start_date_value']['default_date'] = 'now';
  $translatables['events'] = array(
    t('Master'),
    t('Events'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Page'),
    t('Learn more'),
    t('Latest Events'),
    t('Sticky Events'),
    t('<h2>Featured Events</h2>'),
    t('File'),
    t('<a href="[field_link_1]" target="_blank" rel="nofollow"><img class="img-responsive" src="[uri]" alt="[field_logo-alt]" title="[field_logo-title]" /></a>'),
    t('<div class="col-sm-1 col-xs-3 event-date">
  <div class="event-feature">
    <div class="day">[field_start_date]</div>
    <div>[field_start_date_1]</div>
  </div>
</div>
<div class="col-sm-9 col-xs-7">
  <div class="event-title">[field_event_name]</div>
   <div class="event-loc">[field_event_location]</div>
  <div class="event-txt">[field_html_body]</div>
  <div class="event-lnk">[field_link]</div>
</div>
<div class="col-xs-2">
<div class="event-img">[field_logo]</div>
</div>'),
    t('Start Date (field_start_date)'),
    t('Upcoming Events'),
    t('<h2>Upcoming Events</h2>'),
    t('<div class="col-sm-1 col-xs-3 event-date">
  <div class="event-upcoming">
    <div class="day">[field_start_date]</div>
    <div>[field_start_date_1]</div>
  </div>
</div>
<div class="col-sm-9 col-xs-7">
  <div class="event-title">[field_event_name]</div>
   <div class="event-loc">[field_event_location]</div>
  <div class="event-txt">[field_html_body]</div>
  <div class="event-lnk">[field_link]</div>
</div>
<div class="col-xs-2">
<div class="event-img">[field_logo]</div>
</div>'),
    t('Past Events'),
    t('<h2>Past Events</h2>'),
    t('<div class="col-sm-1 col-xs-3 event-date">
  <div class="event-current">
    <div class="day">[field_start_date]</div>
    <div>[field_start_date_1]</div>
  </div>
</div>
<div class="col-sm-9 col-xs-7">
  <div class="event-title">[field_event_name]</div>
   <div class="event-loc">[field_event_location]</div>
  <div class="event-txt">[field_html_body]</div>
  <div class="event-lnk">[field_link]</div>
</div>
<div class="col-xs-2">
<div class="event-img">[field_logo]</div>
</div>'),
    t('Current Events'),
    t('<h2>Current Events</h2>'),
    t('<div class="col-sm-2 col-xs-3 event-date">
  <div class="event-current">
    <div>[field_start_date]</div>
    <div>[field_start_date_1]</div>
  </div>
</div>
<div class="col-sm-8 col-xs-7">
  <div class="event-title">[field_event_name]</div>
  <div class="event-txt">[field_html_body]</div>
</div>
<div class="col-xs-2">
<div class="event-img">[field_logo]</div>
</div>'),
    t('All Events'),
    t('<div class="event-img">[field_logo]</div>
'),
    t('Upcomimg Events Media Center'),
    t('For Media Center Page'),
    t('See all events'),
    t('<div class="see-all-lnk">
<a class="pull-right" href="/events">See all Events <i class="fa fa-arrow-right"></i></a>
</div>
'),
    t('Link to the event >'),
  );
  $export['events'] = $view;

  return $export;
}
