<?php

namespace ContainerOa4dsrn;

use Symfony\Component\DependencyInjection\Argument\RewindableGenerator;
use Symfony\Component\DependencyInjection\ContainerInterface;
use Symfony\Component\DependencyInjection\Container;
use Symfony\Component\DependencyInjection\Exception\InvalidArgumentException;
use Symfony\Component\DependencyInjection\Exception\LogicException;
use Symfony\Component\DependencyInjection\Exception\RuntimeException;
use Symfony\Component\DependencyInjection\ParameterBag\FrozenParameterBag;

/**
 * This class has been auto-generated
 * by the Symfony Dependency Injection Component.
 *
 * @final since Symfony 3.3
 */
class LibraryDevDebugProjectContainer extends Container
{
    private $buildParameters;
    private $containerDir;
    private $parameters;
    private $targetDirs = array();

    public function __construct(array $buildParameters = array(), $containerDir = __DIR__)
    {
        $dir = $this->targetDirs[0] = \dirname($containerDir);
        for ($i = 1; $i <= 5; ++$i) {
            $this->targetDirs[$i] = $dir = \dirname($dir);
        }
        $this->buildParameters = $buildParameters;
        $this->containerDir = $containerDir;
        $this->parameters = $this->getDefaultParameters();

        $this->services = array();
        $this->normalizedIds = array(
            'zephir\\backends\\backendfactory' => 'Zephir\\Backends\\BackendFactory',
            'zephir\\basebackend' => 'Zephir\\BaseBackend',
            'zephir\\compiler' => 'Zephir\\Compiler',
            'zephir\\config' => 'Zephir\\Config',
            'zephir\\console\\application' => 'Zephir\\Console\\Application',
            'zephir\\filesystem\\filesysteminterface' => 'Zephir\\FileSystem\\FileSystemInterface',
        );
        $this->fileMap = array(
            'Zephir\\Backends\\BackendFactory' => 'getBackendFactoryService.php',
            'Zephir\\BaseBackend' => 'getBaseBackendService.php',
            'Zephir\\Compiler' => 'getCompilerService.php',
            'Zephir\\Config' => 'getConfigService.php',
            'Zephir\\Console\\Application' => 'getApplicationService.php',
            'Zephir\\FileSystem\\FileSystemInterface' => 'getFileSystemInterfaceService.php',
            'compiler_filesystem' => 'getCompilerFilesystemService.php',
            'compiler_log_formatter' => 'getCompilerLogFormatterService.php',
            'logger' => 'getLoggerService.php',
            'monolog.handler.console_stderr' => 'getMonolog_Handler_ConsoleStderrService.php',
            'monolog.handler.console_stdout' => 'getMonolog_Handler_ConsoleStdoutService.php',
            'monolog.handler.null_internal' => 'getMonolog_Handler_NullInternalService.php',
            'monolog.logger.zephir' => 'getMonolog_Logger_ZephirService.php',
            'monolog.processor.psr_log_message' => 'getMonolog_Processor_PsrLogMessageService.php',
            'oneup_flysystem.adapter_factory.awss3v2' => 'getOneupFlysystem_AdapterFactory_Awss3v2Service.php',
            'oneup_flysystem.adapter_factory.awss3v3' => 'getOneupFlysystem_AdapterFactory_Awss3v3Service.php',
            'oneup_flysystem.adapter_factory.customadapter' => 'getOneupFlysystem_AdapterFactory_CustomadapterService.php',
            'oneup_flysystem.adapter_factory.dropbox' => 'getOneupFlysystem_AdapterFactory_DropboxService.php',
            'oneup_flysystem.adapter_factory.fallback' => 'getOneupFlysystem_AdapterFactory_FallbackService.php',
            'oneup_flysystem.adapter_factory.ftp' => 'getOneupFlysystem_AdapterFactory_FtpService.php',
            'oneup_flysystem.adapter_factory.gaufrette' => 'getOneupFlysystem_AdapterFactory_GaufretteService.php',
            'oneup_flysystem.adapter_factory.googlecloudstorage' => 'getOneupFlysystem_AdapterFactory_GooglecloudstorageService.php',
            'oneup_flysystem.adapter_factory.gridfs' => 'getOneupFlysystem_AdapterFactory_GridfsService.php',
            'oneup_flysystem.adapter_factory.local' => 'getOneupFlysystem_AdapterFactory_LocalService.php',
            'oneup_flysystem.adapter_factory.memory' => 'getOneupFlysystem_AdapterFactory_MemoryService.php',
            'oneup_flysystem.adapter_factory.nulladapter' => 'getOneupFlysystem_AdapterFactory_NulladapterService.php',
            'oneup_flysystem.adapter_factory.rackspace' => 'getOneupFlysystem_AdapterFactory_RackspaceService.php',
            'oneup_flysystem.adapter_factory.replicate' => 'getOneupFlysystem_AdapterFactory_ReplicateService.php',
            'oneup_flysystem.adapter_factory.sftp' => 'getOneupFlysystem_AdapterFactory_SftpService.php',
            'oneup_flysystem.adapter_factory.webdav' => 'getOneupFlysystem_AdapterFactory_WebdavService.php',
            'oneup_flysystem.adapter_factory.zip' => 'getOneupFlysystem_AdapterFactory_ZipService.php',
            'oneup_flysystem.cache_factory.adapter' => 'getOneupFlysystem_CacheFactory_AdapterService.php',
            'oneup_flysystem.cache_factory.memcached' => 'getOneupFlysystem_CacheFactory_MemcachedService.php',
            'oneup_flysystem.cache_factory.memory' => 'getOneupFlysystem_CacheFactory_MemoryService.php',
            'oneup_flysystem.cache_factory.noop' => 'getOneupFlysystem_CacheFactory_NoopService.php',
            'oneup_flysystem.cache_factory.php_redis' => 'getOneupFlysystem_CacheFactory_PhpRedisService.php',
            'oneup_flysystem.cache_factory.predis' => 'getOneupFlysystem_CacheFactory_PredisService.php',
            'oneup_flysystem.cache_factory.psr6' => 'getOneupFlysystem_CacheFactory_Psr6Service.php',
            'oneup_flysystem.cache_factory.stash' => 'getOneupFlysystem_CacheFactory_StashService.php',
            'oneup_flysystem.mount_manager' => 'getOneupFlysystem_MountManagerService.php',
            'oneup_flysystem.plugin.empty_dir' => 'getOneupFlysystem_Plugin_EmptyDirService.php',
            'oneup_flysystem.plugin.get_with_metadata' => 'getOneupFlysystem_Plugin_GetWithMetadataService.php',
            'oneup_flysystem.plugin.list_files' => 'getOneupFlysystem_Plugin_ListFilesService.php',
            'oneup_flysystem.plugin.list_paths' => 'getOneupFlysystem_Plugin_ListPathsService.php',
            'oneup_flysystem.plugin.list_with' => 'getOneupFlysystem_Plugin_ListWithService.php',
        );
        $this->privates = array(
            'compiler_log_formatter' => true,
            'logger' => true,
            'monolog.handler.console_stderr' => true,
            'monolog.handler.console_stdout' => true,
            'monolog.handler.null_internal' => true,
            'monolog.logger.zephir' => true,
            'monolog.processor.psr_log_message' => true,
            'oneup_flysystem.adapter_factory.awss3v2' => true,
            'oneup_flysystem.adapter_factory.awss3v3' => true,
            'oneup_flysystem.adapter_factory.customadapter' => true,
            'oneup_flysystem.adapter_factory.dropbox' => true,
            'oneup_flysystem.adapter_factory.fallback' => true,
            'oneup_flysystem.adapter_factory.ftp' => true,
            'oneup_flysystem.adapter_factory.gaufrette' => true,
            'oneup_flysystem.adapter_factory.googlecloudstorage' => true,
            'oneup_flysystem.adapter_factory.gridfs' => true,
            'oneup_flysystem.adapter_factory.local' => true,
            'oneup_flysystem.adapter_factory.memory' => true,
            'oneup_flysystem.adapter_factory.nulladapter' => true,
            'oneup_flysystem.adapter_factory.rackspace' => true,
            'oneup_flysystem.adapter_factory.replicate' => true,
            'oneup_flysystem.adapter_factory.sftp' => true,
            'oneup_flysystem.adapter_factory.webdav' => true,
            'oneup_flysystem.adapter_factory.zip' => true,
            'oneup_flysystem.cache_factory.adapter' => true,
            'oneup_flysystem.cache_factory.memcached' => true,
            'oneup_flysystem.cache_factory.memory' => true,
            'oneup_flysystem.cache_factory.noop' => true,
            'oneup_flysystem.cache_factory.php_redis' => true,
            'oneup_flysystem.cache_factory.predis' => true,
            'oneup_flysystem.cache_factory.psr6' => true,
            'oneup_flysystem.cache_factory.stash' => true,
            'oneup_flysystem.plugin.empty_dir' => true,
            'oneup_flysystem.plugin.get_with_metadata' => true,
            'oneup_flysystem.plugin.list_files' => true,
            'oneup_flysystem.plugin.list_paths' => true,
            'oneup_flysystem.plugin.list_with' => true,
        );

        $this->aliases = array();
    }

    public function getRemovedIds()
    {
        return require $this->containerDir.\DIRECTORY_SEPARATOR.'removed-ids.php';
    }

    public function compile()
    {
        throw new LogicException('You cannot compile a dumped container that was already compiled.');
    }

    public function isCompiled()
    {
        return true;
    }

    public function isFrozen()
    {
        @trigger_error(sprintf('The %s() method is deprecated since Symfony 3.3 and will be removed in 4.0. Use the isCompiled() method instead.', __METHOD__), E_USER_DEPRECATED);

        return true;
    }

    protected function load($file, $lazyLoad = true)
    {
        return require $this->containerDir.\DIRECTORY_SEPARATOR.$file;
    }

    public function getParameter($name)
    {
        $name = (string) $name;
        if (isset($this->buildParameters[$name])) {
            return $this->buildParameters[$name];
        }
        if (!(isset($this->parameters[$name]) || isset($this->loadedDynamicParameters[$name]) || array_key_exists($name, $this->parameters))) {
            $name = $this->normalizeParameterName($name);

            if (!(isset($this->parameters[$name]) || isset($this->loadedDynamicParameters[$name]) || array_key_exists($name, $this->parameters))) {
                throw new InvalidArgumentException(sprintf('The parameter "%s" must be defined.', $name));
            }
        }
        if (isset($this->loadedDynamicParameters[$name])) {
            return $this->loadedDynamicParameters[$name] ? $this->dynamicParameters[$name] : $this->getDynamicParameter($name);
        }

        return $this->parameters[$name];
    }

    public function hasParameter($name)
    {
        $name = (string) $name;
        if (isset($this->buildParameters[$name])) {
            return true;
        }
        $name = $this->normalizeParameterName($name);

        return isset($this->parameters[$name]) || isset($this->loadedDynamicParameters[$name]) || array_key_exists($name, $this->parameters);
    }

    public function setParameter($name, $value)
    {
        throw new LogicException('Impossible to call set() on a frozen ParameterBag.');
    }

    public function getParameterBag()
    {
        if (null === $this->parameterBag) {
            $parameters = $this->parameters;
            foreach ($this->loadedDynamicParameters as $name => $loaded) {
                $parameters[$name] = $loaded ? $this->dynamicParameters[$name] : $this->getDynamicParameter($name);
            }
            foreach ($this->buildParameters as $name => $value) {
                $parameters[$name] = $value;
            }
            $this->parameterBag = new FrozenParameterBag($parameters);
        }

        return $this->parameterBag;
    }

    private $loadedDynamicParameters = array(
        'kernel.cache_dir' => false,
        'kernel.logs_dir' => false,
    );
    private $dynamicParameters = array();

    /**
     * Computes a dynamic parameter.
     *
     * @param string $name The name of the dynamic parameter to load
     *
     * @return mixed The value of the dynamic parameter
     *
     * @throws InvalidArgumentException When the dynamic parameter does not exist
     */
    private function getDynamicParameter($name)
    {
        switch ($name) {
            case 'kernel.cache_dir': $value = $this->targetDirs[0]; break;
            case 'kernel.logs_dir': $value = ($this->targetDirs[1].'/logs'); break;
            default: throw new InvalidArgumentException(sprintf('The dynamic parameter "%s" must be defined.', $name));
        }
        $this->loadedDynamicParameters[$name] = true;

        return $this->dynamicParameters[$name] = $value;
    }

    private $normalizedParameterNames = array();

    private function normalizeParameterName($name)
    {
        if (isset($this->normalizedParameterNames[$normalizedName = strtolower($name)]) || isset($this->parameters[$normalizedName]) || array_key_exists($normalizedName, $this->parameters)) {
            $normalizedName = isset($this->normalizedParameterNames[$normalizedName]) ? $this->normalizedParameterNames[$normalizedName] : $normalizedName;
            if ((string) $name !== $normalizedName) {
                @trigger_error(sprintf('Parameter names will be made case sensitive in Symfony 4.0. Using "%s" instead of "%s" is deprecated since Symfony 3.4.', $name, $normalizedName), E_USER_DEPRECATED);
            }
        } else {
            $normalizedName = $this->normalizedParameterNames[$normalizedName] = (string) $name;
        }

        return $normalizedName;
    }

    /**
     * Gets the default parameters.
     *
     * @return array An array of the default parameters
     */
    protected function getDefaultParameters()
    {
        return array(
            'kernel.root_dir' => '/root/zephir/Library',
            'kernel.project_dir' => '/root/zephir',
            'kernel.environment' => 'dev',
            'kernel.debug' => true,
            'kernel.name' => 'Library',
            'kernel.bundles' => array(
                'MonologBundle' => 'Symfony\\Bundle\\MonologBundle\\MonologBundle',
                'OneupFlysystemBundle' => 'Oneup\\FlysystemBundle\\OneupFlysystemBundle',
            ),
            'kernel.bundles_metadata' => array(
                'MonologBundle' => array(
                    'parent' => NULL,
                    'path' => '/root/zephir/vendor/symfony/monolog-bundle',
                    'namespace' => 'Symfony\\Bundle\\MonologBundle',
                ),
                'OneupFlysystemBundle' => array(
                    'parent' => NULL,
                    'path' => '/root/zephir/vendor/oneup/flysystem-bundle',
                    'namespace' => 'Oneup\\FlysystemBundle',
                ),
            ),
            'kernel.charset' => 'UTF-8',
            'kernel.container_class' => 'LibraryDevDebugProjectContainer',
            'prototypes_path' => '/root/zephir/prototypes',
            'optimizers_path' => '/root/zephir/Library/Optimizers',
            'kernels_path' => '/root/zephir/kernels',
            'templates_path' => '/root/zephir/templates',
            'monolog.use_microseconds' => true,
            'monolog.swift_mailer.handlers' => array(

            ),
            'monolog.handlers_to_channels' => array(
                'monolog.handler.console_stdout' => NULL,
                'monolog.handler.console_stderr' => NULL,
            ),
        );
    }
}
