<?php


class treewalk_SequenceFactory {

  function taxonomyTermReference($fieldname, $entityType, $depthFirst = FALSE) {

    // Determine the vocabulary
    $fieldinfo = field_info_field($fieldname);
    if (isset($fieldinfo['settings']['allowed_values'][0]['vocabulary'])) {
      $vocabulary = taxonomy_vocabulary_load($fieldinfo['settings']['allowed_values'][0]['vocabulary']);
    }
    else {
      $vocabulary = NULL;
    }

    // Create parent sequence based on taxonomy term parent/child
    $parentSequence = $this->taxonomyTerm($vocabulary, $depthFirst);

    // Create entity sequence based on entity -> term reference.
    $parentChildModel = new treewalk_ParentChildModel_TaxonomyTermReference($fieldname, $entityType);
    $sequence = new treewalk_Sequence_ExternalParentChild($parentSequence, $parentChildModel);

    return $sequence;
  }

  function taxonomyTerm($vocabulary = NULL, $depthFirst = FALSE) {
    $parentChildModel = new treewalk_ParentChildModel_TaxonomyTerm($vocabulary);
    $sequence = new treewalk_Sequence_InternalParentChild($parentChildModel, $depthFirst);
    return $sequence;
  }

  function internalEntityReference($fieldname, $entityType, $depthFirst = FALSE) {
    $parentChildModel = new treewalk_ParentChildModel_EntityReference($fieldname, $entityType);
    $sequence = new treewalk_Sequence_InternalParentChild($parentChildModel, $depthFirst);
    return $sequence;
  }

  function menuLink($menuName, $depthFirst = FALSE) {
    $parentChildModel = new treewalk_ParentChildModel_MenuLink($menuName);
    $sequence = new treewalk_Sequence_InternalParentChild($parentChildModel, $depthFirst);
    return $sequence;
  }

  function pathMenuLink($menuName, $depthFirst = FALSE) {
    $parentSequence = $this->menuLink($menuName, $depthFirst);
    $parentChildModel = new treewalk_ParentChildModel_PathMenuLink($menuName);
    $sequence = new treewalk_Sequence_ExternalParentChild($parentSequence, $parentChildModel);
    return $sequence;
  }

  function entityMenuLink($menuName, $entityType, $depthFirst = FALSE) {
    $parentSequence = $this->menuLink($menuName, $depthFirst);
    $parentChildModel = new treewalk_ParentChildModel_EntityMenuLink($menuName, $entityType);
    $sequence = new treewalk_Sequence_ExternalParentChild($parentSequence, $parentChildModel);
    return $sequence;
  }
}
