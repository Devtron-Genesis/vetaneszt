<?php


/**
 * This class assumes that the entities we want to traverse all reference
 * an "external" hierarchy. E.g. nodes that reference taxonomy terms.
 * The prev/next is then based on the tree structure of this external hierarchy.
 */
class treewalk_Sequence_ExternalParentChild extends treewalk_Sequence_ParentChild {

  protected $parentHierarchy;

  function __construct($parentHierarchy, $parentChildModel) {
    $this->parentHierarchy = $parentHierarchy;
    parent::__construct($parentChildModel);
  }

  function next($item, $reverse = FALSE) {
    $parent = $this->parentChildModel->parent($item);
    if ($next = $this->parentChildModel->nextChild($parent, $item, $reverse)) {
      return $next;
    }
    $nextParent = $parent;
    while ($nextParent = $this->parentHierarchy->next($nextParent, $reverse)) {
      if ($next = $this->parentChildModel->firstChild($nextParent, $reverse)) {
        return $next;
      }
    }
  }
}
