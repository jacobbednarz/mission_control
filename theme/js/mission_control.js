(function ($, Drupal, window, document, undefined) {
  Drupal.behaviors.missionControl = {
    attach: function() {
      missionControl = window.missionControl || {};

      var index,
          tipsySelectors = ['.mission-control-hostname', '.mission-control-queue-count'];

      // Loop over all the elements that would like to use tooltips and apply
      // the correct settings.
      for (index = 0; index < tipsySelectors.length; ++index) {
        $(tipsySelectors[index]).tipsy({
          html: true,
          gravity: 's',
        });
      }
    }
  };
})(jQuery, Drupal, this, this.document);
