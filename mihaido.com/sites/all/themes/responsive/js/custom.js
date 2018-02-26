jQuery(document).ready(function() {
        jQuery('.node-type-termek .field-name-field-kepek img').css('height', 190).css('width', 190);
	jQuery('#main-menu ul.menu').mobileMenu();
	jQuery('.page-product a[href="/ja/product"]').text('商品カテゴリー').attr('href','/ja/products');
	jQuery('.breadcrumb a').not('#custom-breadcrumbs-home').removeAttr('href');

/* Navigation */
	jQuery('#main-menu ul.menu').superfish({ 
		delay:       500,								// 0.1 second delay on mouseout 
		animation:   {opacity:'show',height:'show'},	// fade-in and slide-down animation 
		dropShadows: true								// disable drop shadows 
	});	

});