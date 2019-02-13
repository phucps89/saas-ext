
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


ZEPHIR_INIT_CLASS(Saas_Cores_Exceptions_LicenceException) {

	ZEPHIR_REGISTER_CLASS_EX(Saas\\Cores\\Exceptions, LicenceException, saas, cores_exceptions_licenceexception, zend_exception_get_default(TSRMLS_C), NULL, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	return SUCCESS;

}

