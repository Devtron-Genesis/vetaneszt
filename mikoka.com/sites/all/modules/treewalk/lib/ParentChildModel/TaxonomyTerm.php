<?php


class treewalk_ParentChildModel_TaxonomyTerm extends treewalk_ParentChildModel_ByQuery {

  protected $vocabulary;

  function __construct($vocabulary) {
    $this->vocabulary = $vocabulary;

    $termIdModel = new treewalk_ItemIdModel_TaxonomyTerm();
    parent::__construct($termIdModel);
  }

  function parent($term) {
    return reset(taxonomy_get_parents($term->tid));
  }

  protected function parentId($term) {
    // TODO: This is not the most efficient way! Look into taxonomy_term_get_parents()
    $term = $this->parent($term);
    if (!empty($term)) {
      return $term->tid;
    }
  }

  protected function queryConditionNext($q, $currentTerm, $reverse, $parentTid) {
    $op = $reverse ? '<' : '>';
    $q->where("t.weight $op :weight OR (t.weight = :weight AND t.name $op :name)", array(
      ':weight' => $currentTerm->weight,
      ':name' => $currentTerm->name,
    ));
  }

  protected function firstChildQuery($parentTid, $reverse) {
    $q = db_select('taxonomy_term_data', 't');
    $q->join('taxonomy_term_hierarchy', 'h', 'h.tid = t.tid');
    $q->addField('t', 'tid');
    if (!empty($parentTid)) {
      $q->condition('h.parent', $parentTid);
    }
    else {
      // Root level
      $q->condition('h.parent', NULL);
    }
    if (!empty($this->vocabulary)) {
      $q->condition('t.vid', $this->vocabulary->vid);
    }
    // $q->addTag('term_access');
    $q->orderBy('t.weight', $reverse ? 'DESC' : 'ASC');
    $q->orderBy('t.name', $reverse ? 'DESC' : 'ASC');
    $q->range(0, 1);
    return $q;
  }

  protected function queryLoadItem($q, $parentTid) {
    $childTid = $q->execute()->fetchField();
    if (!empty($childTid)) {
      // TODO: Check if $parent is really the parent for $child.
      return taxonomy_term_load($childTid);
    }
  }
}
