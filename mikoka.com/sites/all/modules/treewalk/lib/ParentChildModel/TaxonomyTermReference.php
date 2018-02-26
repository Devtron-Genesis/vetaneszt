<?php


class treewalk_ParentChildModel_TaxonomyTermReference extends treewalk_ParentChildModel_ByQuery {

  protected $fieldname;
  protected $entityType;

  function __construct($fieldname, $entityType) {
    $this->fieldname = $fieldname;
    $this->entityType = $entityType;

    $itemIdModel = new treewalk_ItemIdModel_Entity($entityType);
    $parentIdModel = new treewalk_ItemIdModel_TaxonomyTerm();
    parent::__construct($itemIdModel, $parentIdModel);
  }

  protected function parentId($entity) {
    foreach ($entity->{$this->fieldname} as $langcode => $items) {
      foreach ($items as $item) {
        // Always return the first item.
        return $item['tid'];
      }
    }
  }

  protected function queryConditionNext($q, $entity, $reverse, $parentTid) {
    $q->propertyCondition('title', $entity->title, $reverse ? '<' : '>');
  }

  protected function firstChildQuery($parentTid, $reverse) {
    $q = new EntityFieldQuery();
    $q->entityCondition('entity_type', $this->entityType);
    // $q->entityCondition('bundle', 'entity');
    $q->propertyCondition('status', 1);
    if (!empty($parentTid)) {
      $q->fieldCondition($this->fieldname, 'tid', $parentTid, '='); //, 'delta_group'); //, 'lang_group');
      // $q->fieldDeltaCondition($this->fieldname, 0, '='); // , 'delta_group'); //, 'lang_group');
    }
    else {
      $q->fieldCondition($this->fieldname, 'tid', NULL, '='); //, 'delta_group'); //, 'lang_group');
      // $q->fieldDeltaCondition($this->fieldname, 0, '='); // , 'delta_group'); //, 'lang_group');
    }
    $q->propertyOrderBy('title', $reverse ? 'DESC' : 'ASC');
    $q->range(0, 1);
    return $q;
  }

  protected function queryLoadItem($q, $parentTid) {
    $result = $q->execute();
    if (!empty($result[$this->entityType])) {
      foreach ($result[$this->entityType] as $etid => $entity_stub) {
        $entity = $this->itemIdModel->idLoadItem($etid);
        if ($this->parentId($entity) === $parentTid) {
          return $entity;
        }
      }
    }
  }
}
