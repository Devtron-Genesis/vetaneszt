<?php


abstract class treewalk_ParentChildModel_ById extends treewalk_ParentChildModel_Abstract {

  protected $itemIdModel;
  protected $parentIdModel;

  function __construct($itemIdModel, $parentIdModel = NULL) {
    if (!isset($parentIdModel)) {
      $parentIdModel = $itemIdModel;
    }
    $this->itemIdModel = $itemIdModel;
    $this->parentIdModel = $parentIdModel;
  }

  function parent($item) {
    $parentId = $this->parentId($item);
    if ($parentId) {
      return $this->parentIdModel->idLoadItem($parentId);
    }
  }

  abstract protected function parentId($item);
}
