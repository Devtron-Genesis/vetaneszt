<?php


class treewalk_ItemIdModel_Entity implements treewalk_ItemIdModel_Interface {

  protected $entityType;
  protected $idKey;

  function __construct($entityType) {
    $this->entityType = $entityType;
    $info = entity_get_info($entityType);
    $this->idKey = $info['entity keys']['id'];
  }

  function itemGetId($entity) {
    return $entity->{$this->idKey};
  }

  function idLoadItem($etid) {
    return reset(entity_load($this->entityType, array($etid)));
  }
}
