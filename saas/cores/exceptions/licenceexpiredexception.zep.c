
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/concat.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Saas_Cores_Exceptions_LicenceExpiredException) {

	ZEPHIR_REGISTER_CLASS_EX(Saas\\Cores\\Exceptions, LicenceExpiredException, saas, cores_exceptions_licenceexpiredexception, saas_cores_exceptions_licenceexception_ce, saas_cores_exceptions_licenceexpiredexception_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Saas_Cores_Exceptions_LicenceExpiredException, __construct) {

	zval *licenceData, licenceData_sub, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&licenceData_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &licenceData);



	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "EXPIRED");
	zephir_update_property_zval(this_ptr, SL("code"), &_0);
	zephir_array_fetch_string(&_1, licenceData, SL("expired"), PH_NOISY | PH_READONLY, "saas/Cores/Exceptions/LicenceExpiredException.zep", 7 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_SV(&_2, "Licence expired at ", &_1);
	zephir_update_property_zval(this_ptr, SL("message"), &_2);
	ZEPHIR_MM_RESTORE();

}

