
(function($) {
  $(document).ready(function() {

    $('.view-display-id-block_1').find('.view-grouping-header').first().siblings('.view-grouping-content').wrap('<ul class="course"></ul>');
    $('ul.course').children('.view-grouping-content').children('.view-grouping').wrap('<li class="course-li">');
    $('li.course-li').children('.view-grouping').children('.view-grouping-header').wrap('<a class=""></a>');
    $('li.course-li').children('.view-grouping').children('.view-grouping-content').wrap('<ul class="lecture"></ul>');
    $('ul.lecture').children('.view-grouping-content').children('.item-list').wrap('<li class="lecture-li">');
    $('li.lecture-li').children('.item-list').children('h3').wrap('<a class=""></a>');
    $(".view-display-id-block_1 li:has(ul)").find("a").css('cursor', 'pointer');
// Toggle Sub Nav
$(".view-display-id-block_1 li:has(ul)").find("ul").hide(); // hide the li UL
$(".view-display-id-block_1 li:has(ul)").find("a").click(function() {
// Add .show-subnav class to revele on click
$(this).toggleClass('course-active-color');
$(this).parent().find("ul:first").toggleClass("show-subnav");
// how to hide previously clicked submenus?
});
$('.view-display-id-block_1 li a.active').parents('li.course-li').children('.view-grouping').children('a').click();
$('.view-display-id-block_1 li a.active').parents('li.lecture-li').children('.item-list').children('a').click();

$('li.lecture-li').children('.item-list').find('li').children('.views-field-name').find('a').each(function() {
	var lecture_path = $(this).attr('href');
	$(this).parent('span').parent('div').parent('li').parent('ul').siblings('a').attr('href', lecture_path);
});
$('li.lecture-li').children('.item-list').find('li').children('.views-field-name').css('display', 'none');
// $('video').children('source').remove();

// // Add clases to course menu
//  $('#block-menu-menu-course').children().children('ul').addClass('course');
//  $('#block-menu-menu-course .course').children('li').addClass('course-li');
//  $('#block-menu-menu-course .course-li').children('ul').addClass('lecture');
//  $('#block-menu-menu-course .lecture').children('li').addClass('lecture-li');
//  $('#block-menu-menu-course .lecture-li').children('ul').addClass('video');
//  	// Remove href from 1st and 2nd level of course menu
//  $('#block-menu-menu-course .course-li').children('a').removeAttr('href');
//  $('#block-menu-menu-course .lecture-li').children('a').removeAttr('href');
//  	// Add css of pointer to course menu list
// $("#block-menu-menu-course li:has(ul)").find("a").css('cursor', 'pointer');
// 	// Toggle Sub Nav
// $("#block-menu-menu-course li:has(ul)").children("ul").hide(); // hide the li UL
// // $("#block-menu-menu-cource li:has(ul)").find("a").removeAttr('href');
// $("#block-menu-menu-course li:has(ul)").find("a").click(function() {
//  		// Add .show-subnav class to revele on click
//  	$(this).toggleClass('course-active-color');
//  	$(this).parent().find("ul:first").toggleClass("show-subnav");
//  	// how to hide previously clicked submenus?
// });

//  $('ul.video li a.active').parents('li.course-li').children('a').click();
//  $('ul.video li a.active').parents('li.lecture-li').children('a').click();

});

})(jQuery);
