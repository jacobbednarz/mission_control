<div id="mission-control-bar">
  <?php if ($element['enable_git_data'] && !empty($element['rendered_git_data'])) : ?>
    <div id="mission-control-branch-details" class="pull-left">
      <span class="mission-control-deployed-branch">
        <?php print render($element['rendered_git_data']); ?>
      </span>
    </div> <!-- /#branch-details -->
  <?php endif; ?>

  <?php if ($element['show_hostname']) : ?>
    <div id="mission-control-hostname" class="pull-left">
      <span class="mission-control-hostname" title="<?php print render($element['host_data']); ?>">
        <?php print render($element['hostname']); ?>
      </span>
    </div>
  <?php endif; ?>

  <div id="mission-control-stats" class="pull-right">
    <?php if ($element['enable_render_time']) : ?>
      <span class="mission-control-topic">
        <?php print render($element['render_time']); ?>ms
      </span>
      <span class="mission-control-unit">render</span>
    <?php endif; ?>

    <?php if ($element['enable_caching_output']) : ?>
      <span class="mission-control-topic">
        <?php print render($element['cache_count']); ?>
      </span>
      <span class="mission-control-unit mission-control-cache-breakdown" title="<?php print render($element['cache_count_output']); ?>">cache</span>
    <?php endif; ?>

    <?php if ($element['enable_sql_output']) : ?>
      <span class="mission-control-topic">
      <?php print render($element['sql_call_time']); ?>ms
      /
      <?php print render($element['sql_call_count']); ?></span>
      <span class="mission-control-unit mission-control-sql-count" title="<?php print render($element['sql_group_breakdown']); ?>">sql</span>
    <?php endif; ?>

    <?php if ($element['enable_batch_count']) : ?>
      <span class="mission-control-topic">
        <?php print render($element['batch_count']) ;?>
      </span>
      <span class="mission-control-unit">batch tasks</span>
    <?php endif; ?>

    <?php if ($element['enable_queue_count']) : ?>
      <span class="mission-control-topic">
        <?php print render($element['queue_count']) ;?>
      </span>
      <span class="mission-control-unit mission-control-queue-count" title="<?php print render($element['queue_names']); ?>">queues</span>
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
