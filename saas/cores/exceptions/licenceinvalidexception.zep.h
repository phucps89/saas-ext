
extern zend_class_entry *saas_cores_exceptions_licenceinvalidexception_ce;

ZEPHIR_INIT_CLASS(Saas_Cores_Exceptions_LicenceInvalidException);

PHP_METHOD(Saas_Cores_Exceptions_LicenceInvalidException, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_saas_cores_exceptions_licenceinvalidexception___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(saas_cores_exceptions_licenceinvalidexception_method_entry) {
	PHP_ME(Saas_Cores_Exceptions_LicenceInvalidException, __construct, arginfo_saas_cores_exceptions_licenceinvalidexception___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
