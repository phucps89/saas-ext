
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#include "php_ext.h"
#include "saas.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *saas_cores_exceptions_licenceexception_ce;
zend_class_entry *saas_0__closure_ce;
zend_class_entry *saas_cores_exceptions_licenceexpiredexception_ce;
zend_class_entry *saas_cores_exceptions_licenceinvalidexception_ce;
zend_class_entry *saas_cores_index_ce;
zend_class_entry *saas_cores_saassystem_ce;

ZEND_DECLARE_MODULE_GLOBALS(saas)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(saas)
{
	REGISTER_INI_ENTRIES();
	zephir_module_init();
	ZEPHIR_INIT(Saas_Cores_Exceptions_LicenceException);
	ZEPHIR_INIT(Saas_Cores_Exceptions_LicenceExpiredException);
	ZEPHIR_INIT(Saas_Cores_Exceptions_LicenceInvalidException);
	ZEPHIR_INIT(Saas_Cores_Index);
	ZEPHIR_INIT(Saas_Cores_SaasSystem);
	ZEPHIR_INIT(saas_0__closure);
	
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(saas)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_saas_globals *saas_globals TSRMLS_DC)
{
	saas_globals->initialized = 0;

	/* Memory options */
	saas_globals->active_memory = NULL;

	/* Virtual Symbol Tables */
	saas_globals->active_symbol_table = NULL;

	/* Cache Enabled */
	saas_globals->cache_enabled = 1;

	/* Recursive Lock */
	saas_globals->recursive_lock = 0;

	/* Static cache */
	memset(saas_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);

	
	
}

/**
 * Initialize globals only on each thread started
 */
static void php_zephir_init_module_globals(zend_saas_globals *saas_globals TSRMLS_DC)
{
	
}

static PHP_RINIT_FUNCTION(saas)
{
	zend_saas_globals *saas_globals_ptr;
#ifdef ZTS
	tsrm_ls = ts_resource(0);
#endif
	saas_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(saas_globals_ptr TSRMLS_CC);
	zephir_initialize_memory(saas_globals_ptr TSRMLS_CC);

	
	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(saas)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}



static PHP_MINFO_FUNCTION(saas)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_SAAS_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_SAAS_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_SAAS_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_SAAS_VERSION);
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_SAAS_ZEPVERSION);
	php_info_print_table_end();
	
	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(saas)
{
	php_zephir_init_globals(saas_globals TSRMLS_CC);
	php_zephir_init_module_globals(saas_globals TSRMLS_CC);
}

static PHP_GSHUTDOWN_FUNCTION(saas)
{
	
}


zend_function_entry php_saas_functions[] = {
	ZEND_FE_END

};

zend_module_entry saas_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	NULL,
	PHP_SAAS_EXTNAME,
	php_saas_functions,
	PHP_MINIT(saas),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(saas),
#else
	NULL,
#endif
	PHP_RINIT(saas),
	PHP_RSHUTDOWN(saas),
	PHP_MINFO(saas),
	PHP_SAAS_VERSION,
	ZEND_MODULE_GLOBALS(saas),
	PHP_GINIT(saas),
	PHP_GSHUTDOWN(saas),
#ifdef ZEPHIR_POST_REQUEST
	PHP_PRSHUTDOWN(saas),
#else
	NULL,
#endif
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_SAAS
ZEND_GET_MODULE(saas)
#endif
