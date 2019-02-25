
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/exit.h"
#include "kernel/string.h"
#include "kernel/file.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Saas_Cores_SaasSystem) {

	ZEPHIR_REGISTER_CLASS(Saas\\Cores, SaasSystem, saas, cores_saassystem, saas_cores_saassystem_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_declare_property_string(saas_cores_saassystem_ce, SL("domain"), "http://saascore.local", ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(saas_cores_saassystem_ce, SL("apis"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(saas_cores_saassystem_ce, SL("token"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(saas_cores_saassystem_ce, SL("user"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(saas_cores_saassystem_ce, SL("_basePath"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(saas_cores_saassystem_ce, SL("_extRequired"), ZEND_ACC_PRIVATE TSRMLS_CC);

	saas_cores_saassystem_ce->create_object = zephir_init_properties_Saas_Cores_SaasSystem;
	return SUCCESS;

}

PHP_METHOD(Saas_Cores_SaasSystem, start) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *basePath, basePath_sub, ins;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&basePath_sub);
	ZVAL_UNDEF(&ins);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &basePath);



	ZEPHIR_INIT_VAR(&ins);
	object_init_ex(&ins, saas_cores_saassystem_ce);
	ZEPHIR_CALL_METHOD(NULL, &ins, "__construct", NULL, 38, basePath);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Saas_Cores_SaasSystem, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *basePath, basePath_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&basePath_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &basePath);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkenv", NULL, 39);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("_basePath"), basePath);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "clear", NULL, 40);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "init", NULL, 41);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "login", NULL, 42);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "main", NULL, 43);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Saas_Cores_SaasSystem, checkEnv) {

	zval ext, _0, *_1, _2$$3, _4$$4, _5$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ext);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_extRequired"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "saas/Cores/SaasSystem.zep", 41);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
	{
		ZEPHIR_INIT_NVAR(&ext);
		ZVAL_COPY(&ext, _1);
		ZEPHIR_CALL_FUNCTION(&_2$$3, "extension_loaded", &_3, 44, &ext);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE(&_2$$3)) {
			ZEPHIR_INIT_NVAR(&_4$$4);
			ZEPHIR_GET_CONSTANT(&_4$$4, "PHP_EOL");
			ZEPHIR_INIT_LNVAR(_5$$4);
			ZEPHIR_CONCAT_SVSV(&_5$$4, "Error: Module [", &ext, "] is not loaded", &_4$$4);
			zend_print_zval(&_5$$4, 0);
			ZEPHIR_MM_RESTORE();
			zephir_exit_empty();
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&ext);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Saas_Cores_SaasSystem, init) {

	zval _0, _1, _2, _3, _4, _5, _6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("domain"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_VS(&_1, &_0, "/v1/auth/login");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "login");
	zephir_update_property_array(this_ptr, SL("apis"), &_2, &_1 TSRMLS_CC);
	zephir_read_property(&_3, this_ptr, SL("domain"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_LNVAR(_1);
	ZEPHIR_CONCAT_VS(&_1, &_3, "/v1/package/customer/available");
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "available_package");
	zephir_update_property_array(this_ptr, SL("apis"), &_4, &_1 TSRMLS_CC);
	zephir_read_property(&_5, this_ptr, SL("domain"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_LNVAR(_1);
	ZEPHIR_CONCAT_VS(&_1, &_5, "/v1/licence/generate");
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "generate_licence");
	zephir_update_property_array(this_ptr, SL("apis"), &_6, &_1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Saas_Cores_SaasSystem, login) {

	zval __$true, handle, username, password, fields, headers, ch, result, httpCode, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _12, _13, data$$3, _14$$3, _15$$3, _16$$3, _17$$3;
	zephir_fcall_cache_entry *_11 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&handle);
	ZVAL_UNDEF(&username);
	ZVAL_UNDEF(&password);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&ch);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&httpCode);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&data$$3);
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_15$$3);
	ZVAL_UNDEF(&_16$$3);
	ZVAL_UNDEF(&_17$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "php://stdin");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "r");
	ZEPHIR_CALL_FUNCTION(&handle, "fopen", NULL, 45, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_GET_CONSTANT(&_0, "PHP_EOL");
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_SV(&_2, "Please login to SAAS System!", &_0);
	zend_print_zval(&_2, 0);
	php_printf("%s", "Username: ");
	ZEPHIR_CALL_FUNCTION(&_3, "fgets", NULL, 46, &handle);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&username);
	zephir_fast_trim(&username, &_3, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
	zephir_fclose(&handle TSRMLS_CC);
	php_printf("%s", "Password: ");
	ZVAL_BOOL(&_5, 0);
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "getpassword", NULL, 47, &_5);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&password);
	zephir_fast_trim(&password, &_4, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_GET_CONSTANT(&_1, "PHP_EOL");
	ZEPHIR_INIT_VAR(&_6);
	ZEPHIR_GET_CONSTANT(&_6, "PHP_EOL");
	ZEPHIR_INIT_VAR(&_7);
	ZEPHIR_CONCAT_VSV(&_7, &_1, "Connecting to server...", &_6);
	zend_print_zval(&_7, 0);
	ZEPHIR_INIT_VAR(&fields);
	zephir_create_array(&fields, 2, 0 TSRMLS_CC);
	zephir_array_update_string(&fields, SL("login"), &username, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&fields, SL("password"), &password, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&headers);
	zephir_create_array(&headers, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_8);
	ZVAL_STRING(&_8, "Accept: application/json");
	zephir_array_fast_append(&headers, &_8);
	ZEPHIR_INIT_NVAR(&_8);
	ZVAL_STRING(&_8, "Content: application/json");
	zephir_array_fast_append(&headers, &_8);
	ZEPHIR_CALL_FUNCTION(&ch, "curl_init", NULL, 7);
	zephir_check_call_status();
	zephir_read_property(&_5, this_ptr, SL("apis"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_9, &_5, SL("login"), PH_NOISY | PH_READONLY, "saas/Cores/SaasSystem.zep", 75 TSRMLS_CC);
	ZVAL_LONG(&_10, 10002);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_11, 10, &ch, &_10, &_9);
	zephir_check_call_status();
	ZVAL_LONG(&_10, 47);
	ZVAL_LONG(&_12, zephir_fast_count_int(&fields TSRMLS_CC));
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_11, 10, &ch, &_10, &_12);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_13, "http_build_query", NULL, 48, &fields);
	zephir_check_call_status();
	ZVAL_LONG(&_10, 10015);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_11, 10, &ch, &_10, &_13);
	zephir_check_call_status();
	ZVAL_LONG(&_10, 10023);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_11, 10, &ch, &_10, &headers);
	zephir_check_call_status();
	ZVAL_LONG(&_10, 19913);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_11, 10, &ch, &_10, &__$true);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&result, "curl_exec", NULL, 11, &ch);
	zephir_check_call_status();
	ZVAL_LONG(&_10, 2097154);
	ZEPHIR_CALL_FUNCTION(&httpCode, "curl_getinfo", NULL, 12, &ch, &_10);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "curl_close", NULL, 13, &ch);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(&httpCode, 200)) {
		ZEPHIR_INIT_VAR(&data$$3);
		zephir_json_decode(&data$$3, &result, zephir_get_intval(&__$true) );
		zephir_array_fetch_string(&_14$$3, &data$$3, SL("result"), PH_NOISY | PH_READONLY, "saas/Cores/SaasSystem.zep", 88 TSRMLS_CC);
		zephir_array_fetch_string(&_15$$3, &_14$$3, SL("token"), PH_NOISY | PH_READONLY, "saas/Cores/SaasSystem.zep", 88 TSRMLS_CC);
		zephir_update_property_zval(this_ptr, SL("token"), &_15$$3);
		zephir_array_fetch_string(&_16$$3, &data$$3, SL("result"), PH_NOISY | PH_READONLY, "saas/Cores/SaasSystem.zep", 89 TSRMLS_CC);
		zephir_array_fetch_string(&_17$$3, &_16$$3, SL("user"), PH_NOISY | PH_READONLY, "saas/Cores/SaasSystem.zep", 89 TSRMLS_CC);
		zephir_update_property_zval(this_ptr, SL("user"), &_17$$3);
		RETURN_MM_BOOL(1);
	} else {
		php_printf("%s", "Login failed!!!");
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(Saas_Cores_SaasSystem, getPassword) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_7 = NULL, *_9 = NULL;
	zval *stars = NULL, stars_sub, __$false, oldStyle, password, kytu, _0, _17, _2$$3, _3$$3, _4$$3, _5$$4, _6$$5, _8$$7, _10$$9, _11$$9, _12$$9, _13$$9, _14$$9, _15$$10, _16$$10;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&stars_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&oldStyle);
	ZVAL_UNDEF(&password);
	ZVAL_UNDEF(&kytu);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_14$$9);
	ZVAL_UNDEF(&_15$$10);
	ZVAL_UNDEF(&_16$$10);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &stars);

	if (!stars) {
		stars = &stars_sub;
		stars = &__$false;
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "stty -g");
	ZEPHIR_CALL_FUNCTION(&oldStyle, "shell_exec", &_1, 30, &_0);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(stars)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "stty -echo");
		ZEPHIR_CALL_FUNCTION(NULL, "shell_exec", &_1, 30, &_2$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_2$$3);
		ZEPHIR_GET_CONSTANT(&_2$$3, "STDIN");
		ZEPHIR_CALL_FUNCTION(&_3$$3, "fgets", NULL, 46, &_2$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "\n");
		ZEPHIR_INIT_VAR(&password);
		zephir_fast_trim(&password, &_3$$3, &_4$$3, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	} else {
		ZEPHIR_INIT_VAR(&_5$$4);
		ZVAL_STRING(&_5$$4, "stty -icanon -echo min 1 time 0");
		ZEPHIR_CALL_FUNCTION(NULL, "shell_exec", &_1, 30, &_5$$4);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&password);
		ZVAL_STRING(&password, "");
		while (1) {
			if (!(1)) {
				break;
			}
			ZEPHIR_INIT_NVAR(&_6$$5);
			ZEPHIR_GET_CONSTANT(&_6$$5, "STDIN");
			ZEPHIR_CALL_FUNCTION(&kytu, "fgetc", &_7, 49, &_6$$5);
			zephir_check_call_status();
			if (ZEPHIR_IS_STRING_IDENTICAL(&kytu, "\n")) {
				break;
			} else {
				ZEPHIR_CALL_FUNCTION(&_8$$7, "ord", &_9, 50, &kytu);
				zephir_check_call_status();
				if (ZEPHIR_IS_LONG_IDENTICAL(&_8$$7, 127)) {
					if (zephir_fast_strlen_ev(&password) > 0) {
						ZEPHIR_INIT_NVAR(&_10$$9);
						ZEPHIR_GET_CONSTANT(&_10$$9, "STDOUT");
						ZEPHIR_INIT_NVAR(&_11$$9);
						ZVAL_STRING(&_11$$9, "\\x08 \\x08");
						zephir_fwrite(NULL, &_10$$9, &_11$$9 TSRMLS_CC);
						ZVAL_LONG(&_12$$9, 0);
						ZVAL_LONG(&_13$$9, -1);
						ZEPHIR_INIT_NVAR(&_14$$9);
						zephir_substr(&_14$$9, &password, 0 , -1 , 0);
						ZEPHIR_CPY_WRT(&password, &_14$$9);
					}
				} else {
					ZEPHIR_INIT_NVAR(&_15$$10);
					ZEPHIR_GET_CONSTANT(&_15$$10, "STDOUT");
					ZEPHIR_INIT_NVAR(&_16$$10);
					ZVAL_STRING(&_16$$10, "*");
					zephir_fwrite(NULL, &_15$$10, &_16$$10 TSRMLS_CC);
					zephir_concat_self(&password, &kytu TSRMLS_CC);
				}
			}
		}
	}
	ZEPHIR_INIT_VAR(&_17);
	ZEPHIR_CONCAT_SV(&_17, "stty ", &oldStyle);
	ZEPHIR_CALL_FUNCTION(NULL, "shell_exec", &_1, 30, &_17);
	zephir_check_call_status();
	RETURN_CCTOR(&password);

}

PHP_METHOD(Saas_Cores_SaasSystem, clear) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "clear");
	ZEPHIR_CALL_FUNCTION(NULL, "system", NULL, 51, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Saas_Cores_SaasSystem, main) {

	zend_bool _19$$3;
	zval menu, handle, select, validSelection, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12$$3, _13$$3, _18$$3, _20$$3, _16$$4, _21$$6, _22$$6;
	zephir_fcall_cache_entry *_14 = NULL, *_15 = NULL, *_17 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&menu);
	ZVAL_UNDEF(&handle);
	ZVAL_UNDEF(&select);
	ZVAL_UNDEF(&validSelection);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_18$$3);
	ZVAL_UNDEF(&_20$$3);
	ZVAL_UNDEF(&_16$$4);
	ZVAL_UNDEF(&_21$$6);
	ZVAL_UNDEF(&_22$$6);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "clear", NULL, 40);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "logo", NULL, 52);
	zephir_check_call_status();
	zend_print_zval(&_0, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_GET_CONSTANT(&_1, "PHP_EOL");
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_GET_CONSTANT(&_2, "PHP_EOL");
	zephir_read_property(&_3, this_ptr, SL("user"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_4, &_3, SL("full_name"), PH_NOISY | PH_READONLY, "saas/Cores/SaasSystem.zep", 145 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_GET_CONSTANT(&_5, "PHP_EOL");
	ZEPHIR_INIT_VAR(&_6);
	ZEPHIR_GET_CONSTANT(&_6, "PHP_EOL");
	ZEPHIR_INIT_VAR(&_7);
	ZEPHIR_CONCAT_VVSVVV(&_7, &_1, &_2, "Hello ", &_4, &_5, &_6);
	zend_print_zval(&_7, 0);
	ZEPHIR_INIT_VAR(&menu);
	ZVAL_STRING(&menu, "");
	zephir_concat_self_str(&menu, SL("=========================================================================\n") TSRMLS_CC);
	zephir_concat_self_str(&menu, SL("= 0. Exit                                                               =\n") TSRMLS_CC);
	zephir_concat_self_str(&menu, SL("= 1. Download licence                                                   =\n") TSRMLS_CC);
	zephir_concat_self_str(&menu, SL("=========================================================================") TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_8);
	ZEPHIR_GET_CONSTANT(&_8, "PHP_EOL");
	ZEPHIR_INIT_VAR(&_9);
	ZEPHIR_GET_CONSTANT(&_9, "PHP_EOL");
	ZEPHIR_INIT_VAR(&_10);
	ZEPHIR_CONCAT_VVV(&_10, &menu, &_8, &_9);
	zend_print_zval(&_10, 0);
	ZEPHIR_INIT_VAR(&validSelection);
	zephir_create_array(&validSelection, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_11);
	ZVAL_LONG(&_11, 0);
	zephir_array_fast_append(&validSelection, &_11);
	ZEPHIR_INIT_NVAR(&_11);
	ZVAL_LONG(&_11, 1);
	zephir_array_fast_append(&validSelection, &_11);
	while (1) {
		if (!(1)) {
			break;
		}
		php_printf("%s", "Please select function: ");
		ZEPHIR_INIT_NVAR(&_12$$3);
		ZVAL_STRING(&_12$$3, "php://stdin");
		ZEPHIR_INIT_NVAR(&_13$$3);
		ZVAL_STRING(&_13$$3, "r");
		ZEPHIR_CALL_FUNCTION(&handle, "fopen", &_14, 45, &_12$$3, &_13$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&select, "fgets", &_15, 46, &handle);
		zephir_check_call_status();
		zephir_fclose(&handle TSRMLS_CC);
		if (ZEPHIR_IS_LONG(&select, 0)) {
			ZVAL_LONG(&_16$$4, 0);
			ZEPHIR_MM_RESTORE();
			zephir_exit(&_16$$4);
		}
		if (ZEPHIR_IS_LONG(&select, 1)) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "downloadlicenceprocess", &_17, 53);
			zephir_check_call_status();
			break;
		}
		zephir_array_fetch_long(&_18$$3, &validSelection, 0, PH_NOISY | PH_READONLY, "saas/Cores/SaasSystem.zep", 166 TSRMLS_CC);
		_19$$3 = ZEPHIR_LT(&select, &_18$$3);
		if (!(_19$$3)) {
			zephir_array_fetch_long(&_20$$3, &validSelection, 1, PH_NOISY | PH_READONLY, "saas/Cores/SaasSystem.zep", 166 TSRMLS_CC);
			_19$$3 = ZEPHIR_GT(&select, &_20$$3);
		}
		if (_19$$3) {
			ZEPHIR_INIT_NVAR(&_21$$6);
			ZEPHIR_GET_CONSTANT(&_21$$6, "PHP_EOL");
			ZEPHIR_INIT_LNVAR(_22$$6);
			ZEPHIR_CONCAT_SV(&_22$$6, "Invalid selected function. Please try again!", &_21$$6);
			zend_print_zval(&_22$$6, 0);
		}
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "main", NULL, 43);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Saas_Cores_SaasSystem, logo) {

	zval logo;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&logo);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&logo);
	ZVAL_STRING(&logo, "");
	zephir_concat_self_str(&logo, SL("      ::::::::      :::         :::      :::::::: \n") TSRMLS_CC);
	zephir_concat_self_str(&logo, SL("    :+:    :+:   :+: :+:     :+: :+:   :+:    :+: \n") TSRMLS_CC);
	zephir_concat_self_str(&logo, SL("   +:+         +:+   +:+   +:+   +:+  +:+         \n") TSRMLS_CC);
	zephir_concat_self_str(&logo, SL("  +#++:++#++ +#++:++#++: +#++:++#++: +#++:++#++   \n") TSRMLS_CC);
	zephir_concat_self_str(&logo, SL("        +#+ +#+     +#+ +#+     +#+        +#+    \n") TSRMLS_CC);
	zephir_concat_self_str(&logo, SL("#+#    #+# #+#     #+# #+#     #+# #+#    #+#     \n") TSRMLS_CC);
	zephir_concat_self_str(&logo, SL("########  ###     ### ###     ###  ########       ") TSRMLS_CC);
	RETURN_CCTOR(&logo);

}

PHP_METHOD(Saas_Cores_SaasSystem, downloadLicenceProcess) {

	zend_bool _29$$4;
	zend_string *_11;
	zend_ulong _10;
	zval listPackage, handle, validSelection, index, package, _0, _1, _2, _4, _5, _6, _8, *_9, _20, _21, _22, _23, _24, _12$$3, _13$$3, _14$$3, _15$$3, _16$$3, _17$$3, _18$$3, _19$$3, _25$$4, _26$$4, _28$$4, _30$$4, _31$$6, _32$$6, _33$$7;
	zephir_fcall_cache_entry *_3 = NULL, *_7 = NULL, *_27 = NULL, *_34 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, select = 0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&listPackage);
	ZVAL_UNDEF(&handle);
	ZVAL_UNDEF(&validSelection);
	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&package);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_15$$3);
	ZVAL_UNDEF(&_16$$3);
	ZVAL_UNDEF(&_17$$3);
	ZVAL_UNDEF(&_18$$3);
	ZVAL_UNDEF(&_19$$3);
	ZVAL_UNDEF(&_25$$4);
	ZVAL_UNDEF(&_26$$4);
	ZVAL_UNDEF(&_28$$4);
	ZVAL_UNDEF(&_30$$4);
	ZVAL_UNDEF(&_31$$6);
	ZVAL_UNDEF(&_32$$6);
	ZVAL_UNDEF(&_33$$7);

	ZEPHIR_MM_GROW();

	php_printf("%s", "Loading available packages...");
	ZEPHIR_CALL_METHOD(&listPackage, this_ptr, "getavailablepackages", NULL, 54);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&validSelection);
	zephir_create_array(&validSelection, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_LONG(&_0, 1);
	zephir_array_fast_append(&validSelection, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, zephir_fast_count_int(&listPackage TSRMLS_CC));
	zephir_array_fast_append(&validSelection, &_0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "clear", NULL, 40);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "=");
	ZVAL_LONG(&_1, 80);
	ZEPHIR_CALL_FUNCTION(&_2, "str_repeat", &_3, 55, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_GET_CONSTANT(&_0, "PHP_EOL");
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VV(&_4, &_2, &_0);
	zend_print_zval(&_4, 0);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "0. Back");
	ZVAL_LONG(&_1, 77);
	ZEPHIR_CALL_FUNCTION(&_6, "str_pad", &_7, 56, &_5, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_8);
	ZEPHIR_CONCAT_SVS(&_8, "= ", &_6, "=\n");
	zend_print_zval(&_8, 0);
	zephir_is_iterable(&listPackage, 0, "saas/Cores/SaasSystem.zep", 199);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&listPackage), _10, _11, _9)
	{
		ZEPHIR_INIT_NVAR(&index);
		if (_11 != NULL) { 
			ZVAL_STR_COPY(&index, _11);
		} else {
			ZVAL_LONG(&index, _10);
		}
		ZEPHIR_INIT_NVAR(&package);
		ZVAL_COPY(&package, _9);
		ZEPHIR_SINIT_NVAR(_12$$3);
		ZVAL_LONG(&_12$$3, ((zephir_get_numberval(&index) + 1)));
		zephir_array_fetch_string(&_13$$3, &package, SL("service"), PH_NOISY | PH_READONLY, "saas/Cores/SaasSystem.zep", 197 TSRMLS_CC);
		zephir_array_fetch_string(&_14$$3, &_13$$3, SL("name"), PH_NOISY | PH_READONLY, "saas/Cores/SaasSystem.zep", 197 TSRMLS_CC);
		zephir_array_fetch_string(&_15$$3, &package, SL("name"), PH_NOISY | PH_READONLY, "saas/Cores/SaasSystem.zep", 197 TSRMLS_CC);
		ZEPHIR_INIT_LNVAR(_16$$3);
		ZEPHIR_CONCAT_VSVSV(&_16$$3, &_12$$3, ". ", &_14$$3, " - ", &_15$$3);
		ZVAL_LONG(&_17$$3, 77);
		ZEPHIR_CALL_FUNCTION(&_18$$3, "str_pad", &_7, 56, &_16$$3, &_17$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_19$$3);
		ZEPHIR_CONCAT_SVS(&_19$$3, "= ", &_18$$3, "=\n");
		zend_print_zval(&_19$$3, 0);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&package);
	ZEPHIR_INIT_NVAR(&index);
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRING(&_5, "=");
	ZVAL_LONG(&_1, 80);
	ZEPHIR_CALL_FUNCTION(&_20, "str_repeat", &_3, 55, &_5, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_5);
	ZEPHIR_GET_CONSTANT(&_5, "PHP_EOL");
	ZEPHIR_INIT_VAR(&_21);
	ZEPHIR_GET_CONSTANT(&_21, "PHP_EOL");
	ZEPHIR_INIT_VAR(&_22);
	ZEPHIR_CONCAT_VVV(&_22, &_20, &_5, &_21);
	zend_print_zval(&_22, 0);
	ZEPHIR_INIT_VAR(&_23);
	ZVAL_STRING(&_23, "php://stdin");
	ZEPHIR_INIT_VAR(&_24);
	ZVAL_STRING(&_24, "r");
	ZEPHIR_CALL_FUNCTION(&handle, "fopen", NULL, 45, &_23, &_24);
	zephir_check_call_status();
	while (1) {
		if (!(1)) {
			break;
		}
		php_printf("%s", "Please select package to download licence: ");
		ZEPHIR_INIT_NVAR(&_25$$4);
		ZEPHIR_CALL_FUNCTION(&_26$$4, "fgets", &_27, 46, &handle);
		zephir_check_call_status();
		zephir_fast_trim(&_25$$4, &_26$$4, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
		select = zephir_get_intval(&_25$$4);
		if (select == 0) {
			break;
		}
		zephir_array_fetch_long(&_28$$4, &validSelection, 0, PH_NOISY | PH_READONLY, "saas/Cores/SaasSystem.zep", 209 TSRMLS_CC);
		_29$$4 = ZEPHIR_GT_LONG(&_28$$4, select);
		if (!(_29$$4)) {
			zephir_array_fetch_long(&_30$$4, &validSelection, 1, PH_NOISY | PH_READONLY, "saas/Cores/SaasSystem.zep", 209 TSRMLS_CC);
			_29$$4 = ZEPHIR_LT_LONG(&_30$$4, select);
		}
		if (_29$$4) {
			ZEPHIR_INIT_NVAR(&_31$$6);
			ZEPHIR_GET_CONSTANT(&_31$$6, "PHP_EOL");
			ZEPHIR_INIT_LNVAR(_32$$6);
			ZEPHIR_CONCAT_SV(&_32$$6, "Invalid selected function. Please try again!", &_31$$6);
			zend_print_zval(&_32$$6, 0);
		} else {
			ZEPHIR_OBS_NVAR(&package);
			zephir_array_fetch_long(&package, &listPackage, (select - 1), PH_NOISY, "saas/Cores/SaasSystem.zep", 213 TSRMLS_CC);
			zephir_array_fetch_string(&_33$$7, &package, SL("customer_package_id"), PH_NOISY | PH_READONLY, "saas/Cores/SaasSystem.zep", 214 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "downloadlicence", &_34, 57, &_33$$7);
			zephir_check_call_status();
			break;
		}
	}
	zephir_fclose(&handle TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Saas_Cores_SaasSystem, getAvailablePackages) {

	zval __$true, headers, ch, result, httpCode, data, _0, _1, _2, _3, _4, _5, _7$$3;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&ch);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&httpCode);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&headers);
	zephir_create_array(&headers, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Accept: application/json");
	zephir_array_fast_append(&headers, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "Content: application/json");
	zephir_array_fast_append(&headers, &_0);
	zephir_read_property(&_1, this_ptr, SL("token"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_SV(&_2, "Authorization: Bearer ", &_1);
	zephir_array_fast_append(&headers, &_2);
	ZEPHIR_CALL_FUNCTION(&ch, "curl_init", NULL, 7);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, SL("apis"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_4, &_3, SL("available_package"), PH_NOISY | PH_READONLY, "saas/Cores/SaasSystem.zep", 232 TSRMLS_CC);
	ZVAL_LONG(&_5, 10002);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_6, 10, &ch, &_5, &_4);
	zephir_check_call_status();
	ZVAL_LONG(&_5, 10023);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_6, 10, &ch, &_5, &headers);
	zephir_check_call_status();
	ZVAL_LONG(&_5, 19913);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_6, 10, &ch, &_5, &__$true);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&result, "curl_exec", NULL, 11, &ch);
	zephir_check_call_status();
	ZVAL_LONG(&_5, 2097154);
	ZEPHIR_CALL_FUNCTION(&httpCode, "curl_getinfo", NULL, 12, &ch, &_5);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "curl_close", NULL, 13, &ch);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(&httpCode, 200)) {
		ZEPHIR_INIT_VAR(&data);
		zephir_json_decode(&data, &result, zephir_get_intval(&__$true) );
		zephir_array_fetch_string(&_7$$3, &data, SL("result"), PH_NOISY | PH_READONLY, "saas/Cores/SaasSystem.zep", 242 TSRMLS_CC);
		RETURN_CTOR(&_7$$3);
	}
	array_init(return_value);
	RETURN_MM();

}

PHP_METHOD(Saas_Cores_SaasSystem, downloadLicence) {

	zephir_fcall_cache_entry *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *customer_package_id, customer_package_id_sub, __$true, headers, fields, ch, result, httpCode, data, licenceKey, _0, _1, _2, _3, _4, _5, _6, _7, _9, _10, _11$$3, _12$$3, _13$$3, _14$$3, _15$$3, _16$$3, _17$$3, _18$$5, _19$$5, _20$$5, _21$$6, _22$$6, _23$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&customer_package_id_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&ch);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&httpCode);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&licenceKey);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_15$$3);
	ZVAL_UNDEF(&_16$$3);
	ZVAL_UNDEF(&_17$$3);
	ZVAL_UNDEF(&_18$$5);
	ZVAL_UNDEF(&_19$$5);
	ZVAL_UNDEF(&_20$$5);
	ZVAL_UNDEF(&_21$$6);
	ZVAL_UNDEF(&_22$$6);
	ZVAL_UNDEF(&_23$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &customer_package_id);



	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_GET_CONSTANT(&_0, "PHP_EOL");
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SV(&_1, "Checking licence...", &_0);
	zend_print_zval(&_1, 0);
	ZEPHIR_INIT_VAR(&headers);
	zephir_create_array(&headers, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "Accept: application/json");
	zephir_array_fast_append(&headers, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "Content: application/json");
	zephir_array_fast_append(&headers, &_2);
	zephir_read_property(&_3, this_ptr, SL("token"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_SV(&_4, "Authorization: Bearer ", &_3);
	zephir_array_fast_append(&headers, &_4);
	ZEPHIR_INIT_VAR(&fields);
	zephir_create_array(&fields, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&fields, SL("customer_package_id"), customer_package_id, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_FUNCTION(&ch, "curl_init", NULL, 7);
	zephir_check_call_status();
	zephir_read_property(&_5, this_ptr, SL("apis"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_6, &_5, SL("generate_licence"), PH_NOISY | PH_READONLY, "saas/Cores/SaasSystem.zep", 264 TSRMLS_CC);
	ZVAL_LONG(&_7, 10002);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_8, 10, &ch, &_7, &_6);
	zephir_check_call_status();
	ZVAL_LONG(&_7, 10023);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_8, 10, &ch, &_7, &headers);
	zephir_check_call_status();
	ZVAL_LONG(&_7, 19913);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_8, 10, &ch, &_7, &__$true);
	zephir_check_call_status();
	ZVAL_LONG(&_7, 47);
	ZVAL_LONG(&_9, zephir_fast_count_int(&fields TSRMLS_CC));
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_8, 10, &ch, &_7, &_9);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_10, "http_build_query", NULL, 48, &fields);
	zephir_check_call_status();
	ZVAL_LONG(&_7, 10015);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_8, 10, &ch, &_7, &_10);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&result, "curl_exec", NULL, 11, &ch);
	zephir_check_call_status();
	ZVAL_LONG(&_7, 2097154);
	ZEPHIR_CALL_FUNCTION(&httpCode, "curl_getinfo", NULL, 12, &ch, &_7);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "curl_close", NULL, 13, &ch);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(&httpCode, 200)) {
		ZEPHIR_INIT_VAR(&_11$$3);
		ZEPHIR_GET_CONSTANT(&_11$$3, "PHP_EOL");
		ZEPHIR_INIT_VAR(&_12$$3);
		ZEPHIR_CONCAT_SV(&_12$$3, "Downloading licence...", &_11$$3);
		zend_print_zval(&_12$$3, 0);
		ZEPHIR_INIT_VAR(&data);
		zephir_json_decode(&data, &result, zephir_get_intval(&__$true) );
		zephir_array_fetch_string(&_13$$3, &data, SL("result"), PH_NOISY | PH_READONLY, "saas/Cores/SaasSystem.zep", 277 TSRMLS_CC);
		ZEPHIR_OBS_VAR(&licenceKey);
		zephir_array_fetch_string(&licenceKey, &_13$$3, SL("value"), PH_NOISY, "saas/Cores/SaasSystem.zep", 277 TSRMLS_CC);
		zephir_read_property(&_14$$3, this_ptr, SL("_basePath"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_15$$3);
		ZEPHIR_CONCAT_VS(&_15$$3, &_14$$3, "/.sdkey");
		zephir_file_put_contents(NULL, &_15$$3, &licenceKey TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_16$$3);
		ZEPHIR_GET_CONSTANT(&_16$$3, "PHP_EOL");
		ZEPHIR_INIT_VAR(&_17$$3);
		ZEPHIR_CONCAT_SV(&_17$$3, "Downloading licence completely!", &_16$$3);
		zend_print_zval(&_17$$3, 0);
	} else {
		ZEPHIR_INIT_NVAR(&data);
		zephir_json_decode(&data, &result, zephir_get_intval(&__$true) );
		if (zephir_array_isset_string(&data, SL("error_message"))) {
			zephir_array_fetch_string(&_18$$5, &data, SL("error_message"), PH_NOISY | PH_READONLY, "saas/Cores/SaasSystem.zep", 284 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_19$$5);
			ZEPHIR_GET_CONSTANT(&_19$$5, "PHP_EOL");
			ZEPHIR_INIT_VAR(&_20$$5);
			ZEPHIR_CONCAT_VV(&_20$$5, &_18$$5, &_19$$5);
			zend_print_zval(&_20$$5, 0);
		} else {
			zephir_array_fetch_string(&_21$$6, &data, SL("message"), PH_NOISY | PH_READONLY, "saas/Cores/SaasSystem.zep", 286 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_22$$6);
			ZEPHIR_GET_CONSTANT(&_22$$6, "PHP_EOL");
			ZEPHIR_INIT_VAR(&_23$$6);
			ZEPHIR_CONCAT_VV(&_23$$6, &_21$$6, &_22$$6);
			zend_print_zval(&_23$$6, 0);
		}
	}
	ZEPHIR_INIT_NVAR(&_2);
	ZEPHIR_GET_CONSTANT(&_2, "PHP_EOL");
	ZEPHIR_INIT_LNVAR(_4);
	ZEPHIR_CONCAT_SV(&_4, "System will back to main menu in 5 seconds...", &_2);
	zend_print_zval(&_4, 0);
	ZVAL_LONG(&_7, 5);
	ZEPHIR_CALL_FUNCTION(NULL, "sleep", NULL, 58, &_7);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

zend_object *zephir_init_properties_Saas_Cores_SaasSystem(zend_class_entry *class_type TSRMLS_DC) {

		zval _1$$3;
	zval _0, _3, _2$$3, _4$$4;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("_extRequired"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			zephir_create_array(&_1$$3, 2, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_2$$3);
			ZVAL_STRING(&_2$$3, "curl");
			zephir_array_fast_append(&_1$$3, &_2$$3);
			ZEPHIR_INIT_NVAR(&_2$$3);
			ZVAL_STRING(&_2$$3, "json");
			zephir_array_fast_append(&_1$$3, &_2$$3);
			zephir_update_property_zval(this_ptr, SL("_extRequired"), &_1$$3);
		}
		zephir_read_property(&_3, this_ptr, SL("apis"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_3) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_4$$4);
			array_init(&_4$$4);
			zephir_update_property_zval(this_ptr, SL("apis"), &_4$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

