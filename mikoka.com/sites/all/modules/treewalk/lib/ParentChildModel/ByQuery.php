<?php


abstract class treewalk_ParentChildModel_ByQuery extends treewalk_ParentChildModel_ById {

  function firstChild($parent, $reverse) {
    $parentId = $this->parentIdModel->itemGetId($parent);
    $q = $this->firstChildQuery($parentId, $reverse);
    return $this->queryLoadItem($q, $parentId);
  }

  function nextChild($parent, $item, $reverse) {
    $parentId = $this->parentIdModel->itemGetId($parent);
    $q = $this->firstChildQuery($parentId, $reverse);
    $this->queryConditionNext($q, $item, $reverse, $parentId);
    return $this->queryLoadItem($q, $parentId);
  }

  abstract protected function queryConditionNext($q, $item, $reverse, $parentId);

  abstract protected function firstChildQuery($parent, $reverse);

  abstract protected function queryLoadItem($q, $parentId);
}
