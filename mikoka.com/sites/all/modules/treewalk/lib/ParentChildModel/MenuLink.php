<?php


class treewalk_ParentChildModel_MenuLink extends treewalk_ParentChildModel_ByQuery {

  protected $menuName;

  function __construct($menuName) {
    $this->menuName = $menuName;
    $itemIdModel = new treewalk_ItemIdModel_MenuLink();
    parent::__construct($itemIdModel);
  }

  protected function parentId($item) {
    return @$item['plid'];
  }

  protected function firstChildQuery($plid, $reverse) {
    $q = db_select('menu_links', 'ml');
    $q->leftJoin('menu_router', 'm', 'm.path = ml.router_path');
    $q->fields('ml');
    // Weight should be taken from {menu_links}, not {menu_router}.
    $q->addField('ml', 'weight', 'link_weight');
    $q->fields('m');
    $q->condition('ml.menu_name', $this->menuName);
    if (!empty($plid)) {
      $q->condition('ml.plid', $plid, '=');
    }
    else {
      // TODO: Restrict by menu, and by depth.
      $q->condition('ml.depth', 1, '=');
    }
    $q->orderBy('ml.weight', $reverse ? 'DESC' : 'ASC');
    $q->range(0, 1);
    return $q;
  }

  protected function queryConditionNext($q, $item, $reverse, $plid) {
    $q->condition('ml.weight', $item['weight'], $reverse ? '<' : '>');
  }

  protected function queryLoadItem($q, $plid) {
    if ($item = $q->execute()->fetchAssoc()) {
      $item['weight'] = $item['link_weight'];
      _menu_link_translate($item);
      return $item;
    }
  }
}
