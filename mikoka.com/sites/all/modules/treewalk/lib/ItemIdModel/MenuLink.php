<?php


class treewalk_ItemIdModel_MenuLink implements treewalk_ItemIdModel_Interface {

  function itemGetId($item) {
    if (!empty($item)) {
      return $item['mlid'];
    }
  }

  function idLoadItem($mlid) {
    if (!empty($mlid)) {
      return menu_link_load($mlid);
    }
  }
}
