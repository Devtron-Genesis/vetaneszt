<?php


class treewalk_ParentChildModel_EntityReference extends treewalk_ParentChildModel_ByQuery {

  protected $fieldname;
  protected $entityType;
  protected $parentEntityType;

  function __construct($fieldname, $entityType, $parentEntityType = NULL;) {
    if (!isset($parentEntityType)) {
      $parentEntityType = $entityType;
    }
    $this->fieldname = $fieldname;
    $this->entityType = $entityType;
    $this->parentEntityType = $parentEntityType;


    $fieldinfo = field_info_field($fieldname);
    dpm($fieldinfo);
    // TODO: Check for sort criteria.

    $childIdModel = new treewalk_ItemIdModel_Entity($entityType);
    $parentIdModel = new treewalk_ItemIdModel_Entity($parentEntityType);
    parent::__construct($childIdModel, $parentIdModel);
  }

  protected function parentId($entity) {
    foreach ($entity->{$this->fieldname} as $langcode => $items) {
      foreach ($items as $item) {
        // Always return the first item.
        // TODO: Is $item['etid'] correct?
        return $item['etid'];
      }
    }
  }

  protected function queryConditionNext($q, $entity, $reverse, $parentEtid) {
    $q->propertyCondition('title', $entity->title, $reverse ? '<' : '>');
  }

  protected function firstChildQuery($parentEtid, $reverse) {

    $q = new EntityFieldQuery();
    $q->entityCondition('entity_type', $this->entityType);
    // $q->entityCondition('bundle', 'entity');
    // TODO: Is status supported by all entity types?
    $q->propertyCondition('status', 1);
    if (!empty($parentEtid)) {
      $q->fieldCondition($this->fieldname, 'etid', $parentEtid, '='); //, 'delta_group'); //, 'lang_group');
      // $q->fieldDeltaCondition($this->fieldname, 0, '='); // , 'delta_group'); //, 'lang_group');
    }
    else {
      $q->fieldCondition($this->fieldname, 'etid', NULL, '='); //, 'delta_group'); //, 'lang_group');
      // $q->fieldDeltaCondition($this->fieldname, 0, '='); // , 'delta_group'); //, 'lang_group');
    }
    // TODO: Can all entities be ordered by title?
    $q->propertyOrderBy('title', $reverse ? 'DESC' : 'ASC');
    $q->range(0, 1);
    return $q;
  }

  protected function queryLoadItem($q, $parentEtid) {
    $result = $q->execute();
    if (!empty($result[$this->entityType])) {
      foreach ($result[$this->entityType] as $etid => $entity_stub) {
        $entity = $this->itemIdModel->idLoadItem($etid);
        if ($this->parentId($entity) === $parentEtid) {
          return $entity;
        }
      }
    }
  }
}
