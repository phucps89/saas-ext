<?php

use Symfony\Component\DependencyInjection\Argument\RewindableGenerator;

// This file has been auto-generated by the Symfony Dependency Injection Component for internal use.
// Returns the private 'compiler_log_formatter' shared autowired service.

return $this->services['compiler_log_formatter'] = new \Zephir\Logger\Formatter\CompilerFormatter(${($_ = isset($this->services['Zephir\Config']) ? $this->services['Zephir\Config'] : $this->load('getConfigService.php')) && false ?: '_'});
