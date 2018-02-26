<?php


abstract class treewalk_Sequence_ParentChild extends treewalk_Sequence_Abstract {

  protected $parentChildModel;

  function __construct($parentChildModel) {
    $this->parentChildModel = $parentChildModel;
  }
}
