
extern zend_class_entry *saas_cores_saassystem_ce;

ZEPHIR_INIT_CLASS(Saas_Cores_SaasSystem);

PHP_METHOD(Saas_Cores_SaasSystem, start);
PHP_METHOD(Saas_Cores_SaasSystem, __construct);
PHP_METHOD(Saas_Cores_SaasSystem, checkEnv);
PHP_METHOD(Saas_Cores_SaasSystem, init);
PHP_METHOD(Saas_Cores_SaasSystem, login);
PHP_METHOD(Saas_Cores_SaasSystem, getPassword);
PHP_METHOD(Saas_Cores_SaasSystem, clear);
PHP_METHOD(Saas_Cores_SaasSystem, main);
PHP_METHOD(Saas_Cores_SaasSystem, logo);
PHP_METHOD(Saas_Cores_SaasSystem, downloadLicenceProcess);
PHP_METHOD(Saas_Cores_SaasSystem, getAvailablePackages);
PHP_METHOD(Saas_Cores_SaasSystem, downloadLicence);
zend_object *zephir_init_properties_Saas_Cores_SaasSystem(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_saas_cores_saassystem_start, 0, 0, 1)
	ZEND_ARG_INFO(0, basePath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_saas_cores_saassystem___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, basePath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_saas_cores_saassystem_getpassword, 0, 0, 0)
	ZEND_ARG_INFO(0, stars)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_saas_cores_saassystem_downloadlicence, 0, 0, 1)
	ZEND_ARG_INFO(0, customer_package_id)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(saas_cores_saassystem_method_entry) {
	PHP_ME(Saas_Cores_SaasSystem, start, arginfo_saas_cores_saassystem_start, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Saas_Cores_SaasSystem, __construct, arginfo_saas_cores_saassystem___construct, ZEND_ACC_PRIVATE|ZEND_ACC_CTOR)
	PHP_ME(Saas_Cores_SaasSystem, checkEnv, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Saas_Cores_SaasSystem, init, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Saas_Cores_SaasSystem, login, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Saas_Cores_SaasSystem, getPassword, arginfo_saas_cores_saassystem_getpassword, ZEND_ACC_PRIVATE)
	PHP_ME(Saas_Cores_SaasSystem, clear, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Saas_Cores_SaasSystem, main, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Saas_Cores_SaasSystem, logo, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Saas_Cores_SaasSystem, downloadLicenceProcess, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Saas_Cores_SaasSystem, getAvailablePackages, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Saas_Cores_SaasSystem, downloadLicence, arginfo_saas_cores_saassystem_downloadlicence, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
