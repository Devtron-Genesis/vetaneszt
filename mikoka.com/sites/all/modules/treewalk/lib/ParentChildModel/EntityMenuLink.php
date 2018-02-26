<?php


class treewalk_ParentChildModel_EntityMenuLink extends treewalk_ParentChildModel_ById {

  protected $menuName;
  protected $entityType;

  function __construct($menuName, $entityType) {
    $this->menuName = $menuName;
    $this->entityType = $entityType;
    $itemIdModel = new treewalk_ItemIdModel_Entity($entityType);
    $parentIdModel = new treewalk_ItemIdModel_MenuLink();
    parent::__construct($itemIdModel, $parentIdModel);
  }

  protected function parentId($entity) {
    return @$item['plid'];
  }

  function firstChild($menuLink, $reverse) {
    // TODO: Check if the menu link links to an entity of the given type, 
    if ($menuLink['path'] == 'node/%') {
      return $menuLink['map'][1];
    }
  }

  function nextChild($parentItem, $entity, $reverse) {
    // There is only one "child" per menu item.
    return NULL;
  }
}
