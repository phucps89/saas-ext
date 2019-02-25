
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(saas_0__closure) {

	ZEPHIR_REGISTER_CLASS(saas, 0__closure, saas, 0__closure, saas_0__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(saas_0__closure, __invoke) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *line, line_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&line_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &line);



	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "ID:");
	ZEPHIR_CALL_FUNCTION(&_1, "stripos", NULL, 35, line, &_0);
	zephir_check_call_status();
	RETURN_MM_BOOL(!ZEPHIR_IS_FALSE_IDENTICAL(&_1));

}

