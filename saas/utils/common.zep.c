
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/file.h"


ZEPHIR_INIT_CLASS(Saas_Utils_Common) {

	ZEPHIR_REGISTER_CLASS(Saas\\Utils, Common, saas, utils_common, saas_utils_common_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Saas_Utils_Common, isConnected) {

	zend_bool is_conn = 0;
	zval connected, _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connected);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "https://seldatinc.com/");
	ZVAL_LONG(&_1, 80);
	ZEPHIR_CALL_FUNCTION(&connected, "fsockopen", NULL, 49, &_0, &_1);
	zephir_check_call_status();
	if (zephir_is_true(&connected)) {
		is_conn = 1;
		zephir_fclose(&connected TSRMLS_CC);
	} else {
		is_conn = 0;
	}
	RETURN_MM_BOOL(is_conn);

}

