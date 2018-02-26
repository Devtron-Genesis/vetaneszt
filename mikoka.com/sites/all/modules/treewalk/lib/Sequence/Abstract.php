<?php


/**
 * Uses the native parent / child hierarchy of taxonomy terms.
 */
abstract class treewalk_Sequence_Abstract {

  /**
   * Find the "previous" item
   */
  function prev($item) {
    return $this->next($item, TRUE);
  }

  /**
   * Find the "next" item.
   */
  abstract function next($item, $reverse = FALSE);

  /**
   * Utility function
   */
  static function nextInArray(array $itemsById, $currentId, $reverse) {
    $ids = array_keys($itemsById);
    foreach ($ids as $index => $id) {
      if ($id === $currentId) {
        $nextIndex = $index + ($reverse ? -1 : 1);
        if (isset($ids[$nextIndex])) {
          return $itemsById[$ids[$nextIndex]];
        }
      }
    }
  }
}
