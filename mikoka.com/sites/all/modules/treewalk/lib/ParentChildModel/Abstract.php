<?php


abstract class treewalk_ParentChildModel_Abstract {

  abstract function parent($item);

  abstract function firstChild($parent, $reverse);

  abstract function nextChild($parent, $item, $reverse);
}
