<?php


/**
 * Uses the native parent / child hierarchy of taxonomy terms.
 */
class treewalk_Sequence_InternalParentChild extends treewalk_Sequence_ParentChild {

  protected $depthFirst;

  function __construct($parentChildModel, $depthFirst = FALSE) {
    $this->depthFirst = $depthFirst;
    parent::__construct($parentChildModel);
  }

  /**
   * Find the "next" item.
   */
  function next($item, $reverse = FALSE) {
    $depthFirst = ($this->depthFirst xor $reverse);
    if ($depthFirst) {
      return $this->next_depthFirst($item, $reverse);
    }
    else {
      return $this->next_breadthFirst($item, $reverse);
    }
  }

  protected function next_breadthFirst($item, $reverse) {

    // Consider the first child
    if ($next = $this->parentChildModel->firstChild($item, $reverse)) {
      return $next;
    }

    // Consider the direct sibling, for the term and each parent.
    while (TRUE) {
      if (!$item) {
        break;
      }
      $parent = $this->parentChildModel->parent($item);
      $next = $this->parentChildModel->nextChild($parent, $item, $reverse);
      if ($next) {
        break;
      }
      $item = $parent;
    }
    if (!empty($next)) {
      return $next;
    }
  }

  protected function next_depthFirst($item, $reverse) {

    // Consider the direct sibling
    $parent = $this->parentChildModel->parent($item);
    $next = $this->parentChildModel->nextChild($parent, $item, $reverse);
    if ($next) {
      // Travel to the deepest first child of $next
      return $this->firstChildDeep($next, $reverse);
    }
    else {
      // Now it's the turn of the parent.
      return $parent;
    }
  }

  function firstChildDeep($item, $reverse) {
    while ($child = $this->parentChildModel->firstChild($item, $reverse)) {
      $item = $child;
    }
    return $item;
  }
}
