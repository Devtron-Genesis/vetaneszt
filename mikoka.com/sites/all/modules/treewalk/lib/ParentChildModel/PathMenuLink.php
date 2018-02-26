<?php


class treewalk_ParentChildModel_PathMenuLink extends treewalk_ParentChildModel_Abstract {

  protected $menuName;

  function __construct($menuName) {
    $this->menuName = $menuName;
  }

  function parent($linkPath) {
    $front = variable_get('site_frontpage', 'node');
    if ($front === $linkPath) {
      $linkPath = '<front>';
    }
    if (!empty($linkPath)) {
      $query = db_select('menu_links', 'ml');
      $query->leftJoin('menu_router', 'm', 'm.path = ml.router_path');
      $query->fields('ml');
      // Weight should be taken from {menu_links}, not {menu_router}.
      $query->addField('ml', 'weight', 'link_weight');
      $query->fields('m');
      $query->condition('menu_name', $this->menuName);
      $query->condition('ml.link_path', $linkPath);
      if ($item = $query->execute()->fetchAssoc()) {
        $item['weight'] = $item['link_weight'];
        _menu_link_translate($item);
        return $item;
      }
    }
  }

  function firstChild($menuLink, $reverse) {
    return $menuLink['link_path'];
  }

  function nextChild($menuLink, $linkPath, $reverse) {
    // There is only one "child" per menu item.
    return NULL;
  }
}
