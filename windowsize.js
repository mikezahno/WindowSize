(function($) {
  $(document).ready(function(){
    var height          = $(window).height();
    var width           = $(window).width();
    var mode            = Drupal.settings.windowsize_adminmode;
    var adminpage       = Drupal.settings.windowsize_adminpage;
    var position        = Drupal.settings.windowsize_position;
    var breakpoints     = Drupal.settings.windowsize_breakpoints;
    var showBreakpoints = show_breakpoints(breakpoints);
    
    console.log(Drupal.settings);
    
    function checkAdmin(adminpage, mode) {
      var showWidget = false;
      
      if(mode === 0){
        showWidget = true;
      }
      if(adminpage === 0 && mode===1){
        showWidget = false;
      }
      if(adminpage === 1 && mode===1){
        showWidget = true;
      }
      return showWidget;
    }
    
    
    //Display the current window width.
    if(checkAdmin(adminpage, mode)){
      $("body").prepend('<div id="windowsize" class="' + position + '"><h4>'+ width +'&nbsp;x&nbsp;'+ height +'&nbsp;'+showBreakpoints+'</h4></div>');
    }
    
    
    $(window).resize(function() {
      var height = $(window).height();
      var width = $(window).width();
      //Add the current window width on resizing the window.
      showBreakpoints = show_breakpoints(breakpoints);
      $("#windowsize").html('<h4>'+ width +'&nbsp;x&nbsp;'+ height +' '+showBreakpoints+'</h4>');
    });
    
    function show_breakpoints(show) {
      if (show === 1) {
        // xs 480px and below
        // sm 767px and below
        // md 768px and above
        // lg 980px and up
        // xs 1200px and up
        var bsW = "Bootstrap Size";
        var w = $( window ).width();
        
        // @media (max-width: @screen-xs-max) { ... }
        if (w < 480) {
          bsW = "XS";
        }
        // @media (max-width: @screen-xs-max) { ... }
        if (w >= 480 && w < 768) {
          bsW = "XS Wide";
        }
        
        // @media (min-width: @screen-sm-min) and (max-width: @screen-sm-max) { ... }
        if (w >= 768 && w < 992) {
          bsW = "SM";
        }
        
        // @media (min-width: @screen-md-min) and (max-width: @screen-md-max) { ... }
        if (w >= 992 && w < 1200) {
          bsW = "MD";
        }
        
        // @media (min-width: @screen-lg-min) { ... }
        if (w > 1200) {
          bsW = "LG";
        }
        return '<span class="label label-info">'+bsW+'</span>';
      }
      return "";
    }
    
  });
})(jQuery);