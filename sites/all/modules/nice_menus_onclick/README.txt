Description
-----------
Module to change the default behavior of Nice menus module from Hover to OnClick.

Dependencies
------------
As its a support for Nice Menus module. You need to install Nice Menus module in order to enable this module.

Features
--------

  - It helps to add OnClick support to a menu tree by replacing the hover action.
  - It also provides a capability of adding a new path "<nolink>"(without quotes). This is useful in cases where user do not want to specify a link.
  - It adds "nolink" class to links with "<nolink>"(without quotes) path. You can style these links in your stylesheet with "nolink"(without quotes) class.

Working
-------
  - Turn On this module. 
  - Go to menu system(/admin/structure/menu) -> Click on "List Links" -> edit any link.
    Inside "path" input box, enter "<nolink>"(without quotes) and save it.
  - Now the above menu item when clicked will open a sub-menu item rather than going to some other page.
  
Use Cases
---------
  - You have a website where you want user to navigate through menu tree to reach on certain link.
    For example, if you have 3 items namely item-1, item-2 and item-3 in a menu tree and you want user to click on final item-3 while navigating through
	item-1 and item-2. So you need to add <nolink> as a path in item-1 and item-2, while item-3 will be the link where you want user to navigate.

Installation
------------
  Just drop this module to modules directory(/sites/all/modules) and enable it as usual.



