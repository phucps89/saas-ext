
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


ZEPHIR_INIT_CLASS(Saas_Cores_Exceptions_LicenceInvalidException) {

	ZEPHIR_REGISTER_CLASS_EX(Saas\\Cores\\Exceptions, LicenceInvalidException, saas, cores_exceptions_licenceinvalidexception, saas_cores_exceptions_licenceexception_ce, saas_cores_exceptions_licenceinvalidexception_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Saas_Cores_Exceptions_LicenceInvalidException, __construct) {

	zval *message, message_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message);



	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "INVALID");
	zephir_update_property_zval(this_ptr, SL("code"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SV(&_1, "Invalid licence: ", message);
	zephir_update_property_zval(this_ptr, SL("message"), &_1);
	ZEPHIR_MM_RESTORE();

}

