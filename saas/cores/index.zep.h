
extern zend_class_entry *saas_cores_index_ce;

ZEPHIR_INIT_CLASS(Saas_Cores_Index);

PHP_METHOD(Saas_Cores_Index, __construct);
PHP_METHOD(Saas_Cores_Index, verifySaasService);
PHP_METHOD(Saas_Cores_Index, initSel2b);
PHP_METHOD(Saas_Cores_Index, initDms);
PHP_METHOD(Saas_Cores_Index, initPom);
PHP_METHOD(Saas_Cores_Index, initWms);
PHP_METHOD(Saas_Cores_Index, initial);
PHP_METHOD(Saas_Cores_Index, decrypt);
PHP_METHOD(Saas_Cores_Index, getLicenceId);
PHP_METHOD(Saas_Cores_Index, getUniqueMachineID);
PHP_METHOD(Saas_Cores_Index, randomString);

ZEND_BEGIN_ARG_INFO_EX(arginfo_saas_cores_index___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, application)
	ZEND_ARG_INFO(0, pathToKey)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_saas_cores_index_initsel2b, 0, 0, 2)
	ZEND_ARG_INFO(0, application)
	ZEND_ARG_INFO(0, pathToKey)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_saas_cores_index_initdms, 0, 0, 2)
	ZEND_ARG_INFO(0, application)
	ZEND_ARG_INFO(0, pathToKey)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_saas_cores_index_initpom, 0, 0, 2)
	ZEND_ARG_INFO(0, application)
	ZEND_ARG_INFO(0, pathToKey)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_saas_cores_index_initwms, 0, 0, 2)
	ZEND_ARG_INFO(0, application)
	ZEND_ARG_INFO(0, pathToKey)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_saas_cores_index_initial, 0, 0, 1)
	ZEND_ARG_INFO(0, pathToKey)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_saas_cores_index_decrypt, 0, 0, 2)
	ZEND_ARG_INFO(0, ivHashCiphertext)
	ZEND_ARG_INFO(0, password)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_saas_cores_index_getlicenceid, 0, 0, 1)
	ZEND_ARG_INFO(0, licencePath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_saas_cores_index_getuniquemachineid, 0, 0, 0)
	ZEND_ARG_INFO(0, salt)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_saas_cores_index_randomstring, 0, 0, 0)
	ZEND_ARG_INFO(0, length)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(saas_cores_index_method_entry) {
	PHP_ME(Saas_Cores_Index, __construct, arginfo_saas_cores_index___construct, ZEND_ACC_PRIVATE|ZEND_ACC_CTOR)
	PHP_ME(Saas_Cores_Index, verifySaasService, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Saas_Cores_Index, initSel2b, arginfo_saas_cores_index_initsel2b, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Saas_Cores_Index, initDms, arginfo_saas_cores_index_initdms, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Saas_Cores_Index, initPom, arginfo_saas_cores_index_initpom, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Saas_Cores_Index, initWms, arginfo_saas_cores_index_initwms, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Saas_Cores_Index, initial, arginfo_saas_cores_index_initial, ZEND_ACC_PRIVATE)
	PHP_ME(Saas_Cores_Index, decrypt, arginfo_saas_cores_index_decrypt, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_ME(Saas_Cores_Index, getLicenceId, arginfo_saas_cores_index_getlicenceid, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Saas_Cores_Index, getUniqueMachineID, arginfo_saas_cores_index_getuniquemachineid, ZEND_ACC_PRIVATE)
	PHP_ME(Saas_Cores_Index, randomString, arginfo_saas_cores_index_randomstring, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
