<div id="mission-control-bar">
  <?php if ($element['enable_git_data']) : ?>
    <div id="mission-control-branch-details" class="pull-left">
      <span class="mission-control-deployed-branch">
        <i class="icon-flow-branch"></i>
        <?php print render($element['current_git_branch']); ?>
        @
        <?php print render($element['git_head_sha']); ?></span>
        <span class="mission-control-hostname">
          <?php print render($element['hostname']); ?>
        </span>
    </div> <!-- /#branch-details -->
  <?php endif; ?>

  <div id="mission-control-stats" class="pull-right">
    <?php if ($element['enable_render_time']) : ?>
      <!-- page render time -->
      <span class="mission-control-topic">
        <?php print render($element['render_time']); ?>ms
      </span>
      <span class="mission-control-unit">render</span>
    <?php endif; ?>

    <?php if ($element['enable_caching_output']) : ?>
      <span class="mission-control-topic">33ms / 34</span>
      <span class="mission-control-unit">cache</span>
    <?php endif; ?>

    <?php if ($element['enable_sql_output']) : ?>
      <span class="mission-control-topic">
      <?php print render($element['sql_call_time']); ?>ms
      /
      <?php print render($element['sql_call_count']); ?></span>
      <span class="mission-control-unit">sql</span>
    <?php endif; ?>

    <?php if ($element['enable_background_task']) : ?>
      <span class="mission-control-topic">8</span>
      <span class="mission-control-unit">tasks</span>
    <?php endif; ?>

    <?php if ($element['enable_directory_sizes']) : ?>
      <span class="mission-control-topic">
        <?php print render($element['css_directory_size']); ?>
      </span>
      <span class="mission-control-unit">css</span>
      <span class="mission-control-topic">
        <?php print render($element['js_directory_size']); ?>
      </span>
      <span class="mission-control-unit">js</span>
    <?php endif; ?>
    </div>
  </div> <!-- /#mission-control-stats -->
</div>
