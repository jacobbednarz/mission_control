(function ($, Drupal, window, document, undefined) {
  Drupal.behaviors.missionControl = {
    attach: function() {
      missionControl = window.missionControl || {};

      var self = this,
          index,
          tipsySelectors = [
            '.mission-control-hostname',
            '.mission-control-queue-count',
            '.mission-control-sql-count'
          ];

      // Loop over all the elements that would like to use tooltips and apply
      // the correct settings.
      for (index = 0; index < tipsySelectors.length; ++index) {
        $(tipsySelectors[index]).tipsy({
          html: true,
          gravity: self.gravityPositionCallback,
        });
      }
    },

    /**
     * Determine what 'gravity' option to apply to the tooltip when hovering.
     */
    gravityPositionCallback: function() {
      var tooltipWidth = 300,
          offset = $(this).offset().left,
          windowWidth = $(window).width();

      if (offset > (windowWidth - tooltipWidth)) {
        return 'se';
      }

      if (offset < (tooltipWidth / 2)) {
        return 'sw';
      }

      return  's';
    }
  };
})(jQuery, Drupal, this, this.document);
