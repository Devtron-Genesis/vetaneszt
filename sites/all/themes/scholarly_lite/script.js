
(function($) {
	$(document).ready(function() {

			// Add clases to course menu
    $('#block-menu-menu-course').children().children('ul').addClass('course');
    $('#block-menu-menu-course .course').children('li').addClass('course-li');
    $('#block-menu-menu-course .course-li').children('ul').addClass('lecture');
    $('#block-menu-menu-course .lecture').children('li').addClass('lecture-li');
    $('#block-menu-menu-course .lecture-li').children('ul').addClass('video');
    	// Remove href from 1st and 2nd level of course menu
    $('#block-menu-menu-course .course-li').children('a').removeAttr('href');
    $('#block-menu-menu-course .lecture-li').children('a').removeAttr('href');
    	// Add css of pointer to course menu list
  	$("#block-menu-menu-course li:has(ul)").find("a").css('cursor', 'pointer');
	  	// Toggle Sub Nav
  	$("#block-menu-menu-course li:has(ul)").children("ul").hide(); // hide the li UL
  	// $("#block-menu-menu-cource li:has(ul)").find("a").removeAttr('href');
  	$("#block-menu-menu-course li:has(ul)").find("a").click(function() {
    		// Add .show-subnav class to revele on click
    	$(this).toggleClass('course-active-color');
    	$(this).parent().find("ul:first").toggleClass("show-subnav");
    	// how to hide previously clicked submenus?
  	});

    $('ul.video li a.active').parents('li.course-li').children('a').click();
    $('ul.video li a.active').parents('li.lecture-li').children('a').click();

	});

})(jQuery);
