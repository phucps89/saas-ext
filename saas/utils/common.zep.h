
extern zend_class_entry *saas_utils_common_ce;

ZEPHIR_INIT_CLASS(Saas_Utils_Common);

PHP_METHOD(Saas_Utils_Common, isConnected);

ZEPHIR_INIT_FUNCS(saas_utils_common_method_entry) {
	PHP_ME(Saas_Utils_Common, isConnected, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
