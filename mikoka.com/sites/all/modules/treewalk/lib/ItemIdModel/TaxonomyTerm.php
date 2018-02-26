<?php


class treewalk_ItemIdModel_TaxonomyTerm implements treewalk_ItemIdModel_Interface {

  function itemGetId($term) {
    if (!empty($term)) {
      return $term->tid;
    }
  }

  function idLoadItem($tid) {
    if (!empty($tid)) {
      return taxonomy_term_load($tid);
    }
  }
}
