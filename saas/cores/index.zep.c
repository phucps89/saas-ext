
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
#include "kernel/file.h"
#include "kernel/object.h"
#include "kernel/exit.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "ext/date/php_date.h"
#include "ext/spl/spl_exceptions.h"


ZEPHIR_INIT_CLASS(Saas_Cores_Index) {

	ZEPHIR_REGISTER_CLASS(Saas\\Cores, Index, saas, cores_index, saas_cores_index_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_declare_property_string(saas_cores_index_ce, SL("pathLogLocationKey"), "/usr/local/sm/", ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_string(saas_cores_index_ce, SL("fileLogLocationKey"), "loclic.sm", ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_string(saas_cores_index_ce, SL("sel2b_module"), "sel2b", ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_string(saas_cores_index_ce, SL("dms_module"), "dms", ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_string(saas_cores_index_ce, SL("pom_module"), "pom", ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_string(saas_cores_index_ce, SL("wms_module"), "wms360", ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_string(saas_cores_index_ce, SL("saas_offline_service_verify"), "http://localhost:12345/verify", ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_string(saas_cores_index_ce, SL("saas_offline_check_licence"), "http://localhost:12345/licence/check", ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_string(saas_cores_index_ce, SL("saas_offline_update_blocking_licence"), "http://localhost:12345/licence/update-blocking", ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_string(saas_cores_index_ce, SL("saas_core_url"), "https://apigw2.seldatdirect.com/staging/saas/api/v1", ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(saas_cores_index_ce, SL("application"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(saas_cores_index_ce, SL("saas_password_encrypt"), "saas_offline_Seldat123@", ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_bool(saas_cores_index_ce, SL("isConnected"), 0, ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_string(saas_cores_index_ce, SL("saas_verify_token"), "370a083d89e60f24d3de8c0de99efb78aea664d5f9f9fdc9b61f8adb8b672630eb2e6f1f40aca81b8257e1d755e4904720eb972483d3700d641bd03575c5b060e84ee14bf9d3d7e476227e2db50378e5", ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Saas_Cores_Index, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *application, application_sub, *pathToKey, pathToKey_sub, *callback = NULL, callback_sub, __$null, _0, arrLicencePath, dataLocLicPath, fileLoclicPath, _5, _6, _1$$3, _2$$4, _3$$4, _4$$5, _7$$7, _8$$7, _9$$8, _10$$9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&application_sub);
	ZVAL_UNDEF(&pathToKey_sub);
	ZVAL_UNDEF(&callback_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&arrLicencePath);
	ZVAL_UNDEF(&dataLocLicPath);
	ZVAL_UNDEF(&fileLoclicPath);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_10$$9);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &application, &pathToKey, &callback);

	if (!callback) {
		callback = &callback_sub;
		callback = &__$null;
	}


	zephir_read_static_property_ce(&_0, saas_cores_index_ce, SL("pathLogLocationKey"), PH_NOISY_CC | PH_READONLY);
	if (!((zephir_file_exists(&_0 TSRMLS_CC) == SUCCESS))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "Sass Model home directory does not exist");
		ZEPHIR_MM_RESTORE();
		zephir_exit(&_1$$3);
	} else {
		zephir_read_static_property_ce(&_2$$4, saas_cores_index_ce, SL("pathLogLocationKey"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_3$$4, "is_writable", NULL, 1, &_2$$4);
		zephir_check_call_status();
		if (!zephir_is_true(&_3$$4)) {
			ZEPHIR_INIT_VAR(&_4$$5);
			ZVAL_STRING(&_4$$5, "Sass Model home directory is not writable");
			ZEPHIR_MM_RESTORE();
			zephir_exit(&_4$$5);
		}
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "verifysaasservice", NULL, 2);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("application"), application);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initial", NULL, 3, pathToKey);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&_5);
	zephir_read_static_property_ce(&_5, saas_cores_index_ce, SL("pathLogLocationKey"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&_6);
	zephir_read_static_property_ce(&_6, saas_cores_index_ce, SL("fileLogLocationKey"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&fileLoclicPath);
	ZEPHIR_CONCAT_VV(&fileLoclicPath, &_5, &_6);
	if (!((zephir_file_exists(&fileLoclicPath TSRMLS_CC) == SUCCESS))) {
		ZEPHIR_INIT_VAR(&arrLicencePath);
		array_init(&arrLicencePath);
	} else {
		ZEPHIR_INIT_VAR(&_7$$7);
		zephir_file_get_contents(&_7$$7, &fileLoclicPath TSRMLS_CC);
		ZEPHIR_INIT_VAR(&dataLocLicPath);
		zephir_fast_trim(&dataLocLicPath, &_7$$7, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_8$$7, "base64_decode", NULL, 4, &dataLocLicPath);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&arrLicencePath);
		zephir_json_decode(&arrLicencePath, &_8$$7, 0 );
	}
	if (!(zephir_fast_in_array(pathToKey, &arrLicencePath TSRMLS_CC))) {
		zephir_array_append(&arrLicencePath, pathToKey, PH_SEPARATE, "saas/Cores/Index.zep", 51);
		ZEPHIR_INIT_VAR(&_9$$8);
		zephir_json_encode(&_9$$8, &arrLicencePath, 0 );
		ZEPHIR_CALL_FUNCTION(&dataLocLicPath, "base64_encode", NULL, 5, &_9$$8);
		zephir_check_call_status();
		zephir_file_put_contents(NULL, &fileLoclicPath, &dataLocLicPath TSRMLS_CC);
	}
	if (!(ZEPHIR_IS_EMPTY(callback))) {
		zephir_read_property(&_10$$9, this_ptr, SL("application"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(NULL, "call_user_func", NULL, 6, callback, &_10$$9);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Saas_Cores_Index, verifySaasService) {

	zend_bool _6;
	zval __$true, headers, ch, result, httpCode, fields, payload, salt, pwverify, _0, _1, _2, _3, _4, _7, _8, _9$$3;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&ch);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&httpCode);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&payload);
	ZVAL_UNDEF(&salt);
	ZVAL_UNDEF(&pwverify);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&headers);
	zephir_create_array(&headers, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Accept: application/json");
	zephir_array_fast_append(&headers, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "Content: application/json");
	zephir_array_fast_append(&headers, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "Content-Type: application/json");
	zephir_array_fast_append(&headers, &_0);
	ZEPHIR_CALL_FUNCTION(&ch, "curl_init", NULL, 7);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&salt, this_ptr, "randomstring", NULL, 8);
	zephir_check_call_status();
	zephir_read_static_property_ce(&_1, saas_cores_index_ce, SL("saas_password_encrypt"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_SVS(&_2, "$2a$07$", &salt, "forsalt$");
	ZEPHIR_CALL_FUNCTION(&pwverify, "crypt", NULL, 9, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&fields);
	zephir_create_array(&fields, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&fields, SL("verify"), &pwverify, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&payload);
	zephir_json_encode(&payload, &fields, 0 );
	zephir_read_static_property_ce(&_3, saas_cores_index_ce, SL("saas_offline_service_verify"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_4, 10002);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_5, 10, &ch, &_4, &_3);
	zephir_check_call_status();
	ZVAL_LONG(&_4, 10023);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_5, 10, &ch, &_4, &headers);
	zephir_check_call_status();
	ZVAL_LONG(&_4, 19913);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_5, 10, &ch, &_4, &__$true);
	zephir_check_call_status();
	ZVAL_LONG(&_4, 10015);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_5, 10, &ch, &_4, &payload);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&result, "curl_exec", NULL, 11, &ch);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	zephir_json_decode(&_0, &result, 0 );
	ZEPHIR_CPY_WRT(&result, &_0);
	ZVAL_LONG(&_4, 2097154);
	ZEPHIR_CALL_FUNCTION(&httpCode, "curl_getinfo", NULL, 12, &ch, &_4);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "curl_close", NULL, 13, &ch);
	zephir_check_call_status();
	_6 = ZEPHIR_IS_LONG(&httpCode, 200);
	if (_6) {
		zephir_read_static_property_ce(&_4, saas_cores_index_ce, SL("saas_password_encrypt"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_7, &result, SL("verify"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_8, "password_verify", NULL, 14, &_4, &_7);
		zephir_check_call_status();
		_6 = zephir_is_true(&_8);
	}
	if (_6) {
		zephir_read_property(&_9$$3, &result, SL("is_connected"), PH_NOISY_CC | PH_READONLY);
		zephir_update_property_zval(this_ptr, SL("isConnected"), &_9$$3);
	} else {
		if (ZEPHIR_IS_EMPTY(&httpCode)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "Saas service is not available!!", "saas/Cores/Index.zep", 95);
			return;
		} else {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "Saas service veirify failed!!", "saas/Cores/Index.zep", 98);
			return;
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Saas_Cores_Index, initSel2b) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *application, application_sub, *pathToKey, pathToKey_sub, *callback = NULL, callback_sub, __$null, index, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&application_sub);
	ZVAL_UNDEF(&pathToKey_sub);
	ZVAL_UNDEF(&callback_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &application, &pathToKey, &callback);

	ZEPHIR_SEPARATE_PARAM(application);
	if (!callback) {
		callback = &callback_sub;
		callback = &__$null;
	}


	ZEPHIR_OBS_VAR(&_0);
	zephir_read_static_property_ce(&_0, saas_cores_index_ce, SL("sel2b_module"), PH_NOISY_CC);
	zephir_update_property_zval(application, SL("module"), &_0);
	ZEPHIR_INIT_VAR(&index);
	object_init_ex(&index, saas_cores_index_ce);
	ZEPHIR_CALL_METHOD(NULL, &index, "__construct", NULL, 15, application, pathToKey, callback);
	zephir_check_call_status();
	RETVAL_ZVAL(application, 1, 0);
	RETURN_MM();

}

PHP_METHOD(Saas_Cores_Index, initDms) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *application, application_sub, *pathToKey, pathToKey_sub, *callback = NULL, callback_sub, __$null, index, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&application_sub);
	ZVAL_UNDEF(&pathToKey_sub);
	ZVAL_UNDEF(&callback_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &application, &pathToKey, &callback);

	ZEPHIR_SEPARATE_PARAM(application);
	if (!callback) {
		callback = &callback_sub;
		callback = &__$null;
	}


	ZEPHIR_OBS_VAR(&_0);
	zephir_read_static_property_ce(&_0, saas_cores_index_ce, SL("dms_module"), PH_NOISY_CC);
	zephir_update_property_zval(application, SL("module"), &_0);
	ZEPHIR_INIT_VAR(&index);
	object_init_ex(&index, saas_cores_index_ce);
	ZEPHIR_CALL_METHOD(NULL, &index, "__construct", NULL, 15, application, pathToKey, callback);
	zephir_check_call_status();
	RETVAL_ZVAL(application, 1, 0);
	RETURN_MM();

}

PHP_METHOD(Saas_Cores_Index, initPom) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *application, application_sub, *pathToKey, pathToKey_sub, *callback = NULL, callback_sub, __$null, index, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&application_sub);
	ZVAL_UNDEF(&pathToKey_sub);
	ZVAL_UNDEF(&callback_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &application, &pathToKey, &callback);

	ZEPHIR_SEPARATE_PARAM(application);
	if (!callback) {
		callback = &callback_sub;
		callback = &__$null;
	}


	ZEPHIR_OBS_VAR(&_0);
	zephir_read_static_property_ce(&_0, saas_cores_index_ce, SL("pom_module"), PH_NOISY_CC);
	zephir_update_property_zval(application, SL("module"), &_0);
	ZEPHIR_INIT_VAR(&index);
	object_init_ex(&index, saas_cores_index_ce);
	ZEPHIR_CALL_METHOD(NULL, &index, "__construct", NULL, 15, application, pathToKey, callback);
	zephir_check_call_status();
	RETVAL_ZVAL(application, 1, 0);
	RETURN_MM();

}

PHP_METHOD(Saas_Cores_Index, initWms) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *application, application_sub, *pathToKey, pathToKey_sub, *callback = NULL, callback_sub, __$null, index, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&application_sub);
	ZVAL_UNDEF(&pathToKey_sub);
	ZVAL_UNDEF(&callback_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &application, &pathToKey, &callback);

	ZEPHIR_SEPARATE_PARAM(application);
	if (!callback) {
		callback = &callback_sub;
		callback = &__$null;
	}


	ZEPHIR_OBS_VAR(&_0);
	zephir_read_static_property_ce(&_0, saas_cores_index_ce, SL("wms_module"), PH_NOISY_CC);
	zephir_update_property_zval(application, SL("module"), &_0);
	ZEPHIR_INIT_VAR(&index);
	object_init_ex(&index, saas_cores_index_ce);
	ZEPHIR_CALL_METHOD(NULL, &index, "__construct", NULL, 15, application, pathToKey, callback);
	zephir_check_call_status();
	RETVAL_ZVAL(application, 1, 0);
	RETURN_MM();

}

PHP_METHOD(Saas_Cores_Index, initial) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_11 = NULL, *_24 = NULL;
	zval *pathToKey, pathToKey_sub, __$true, app, serial, serialDecode, moduleName, e, today, expire, today_time, expire_time, _27, _1$$3, _2$$3, _3$$3, _4$$3, _5$$3, _17$$3, _18$$3, _21$$3, _22$$3, _23$$3, _6$$4, _7$$4, _8$$4, _9$$5, _10$$5, _12$$6, _13$$6, _14$$6, _15$$7, _16$$7, _19$$8, _20$$8, _25$$9, _26$$9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pathToKey_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&app);
	ZVAL_UNDEF(&serial);
	ZVAL_UNDEF(&serialDecode);
	ZVAL_UNDEF(&moduleName);
	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&today);
	ZVAL_UNDEF(&expire);
	ZVAL_UNDEF(&today_time);
	ZVAL_UNDEF(&expire_time);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_17$$3);
	ZVAL_UNDEF(&_18$$3);
	ZVAL_UNDEF(&_21$$3);
	ZVAL_UNDEF(&_22$$3);
	ZVAL_UNDEF(&_23$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_25$$9);
	ZVAL_UNDEF(&_26$$9);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &pathToKey);



	ZEPHIR_OBS_VAR(&app);
	zephir_read_property(&app, this_ptr, SL("application"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&moduleName);
	zephir_read_property(&moduleName, &app, SL("module"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&serial);
	zephir_file_get_contents(&serial, pathToKey TSRMLS_CC);

	/* try_start_1: */

		ZEPHIR_CALL_FUNCTION(&_1$$3, "hex2bin", NULL, 17, &serial);
		zephir_check_call_status_or_jump(try_end_1);
		zephir_read_static_property_ce(&_2$$3, saas_cores_index_ce, SL("saas_password_encrypt"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_SELF(&serialDecode, "decrypt", &_0, 16, &_1$$3, &_2$$3);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_CALL_FUNCTION(&_4$$3, "base64_decode", NULL, 4, &serialDecode);
		zephir_check_call_status_or_jump(try_end_1);
		zephir_json_decode(&_3$$3, &_4$$3, zephir_get_intval(&__$true) );
		zephir_update_property_zval(&app, SL("licence_config"), &_3$$3);
		zephir_read_property(&_5$$3, this_ptr, SL("isConnected"), PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_5$$3)) {
			zephir_read_property(&_7$$4, &app, SL("licence_config"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch_string(&_8$$4, &_7$$4, SL("licence_id"), PH_NOISY | PH_READONLY, "saas/Cores/Index.zep", 149 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_6$$4, this_ptr, "verifylicenceonline", NULL, 18, &_8$$4);
			zephir_check_call_status_or_jump(try_end_1);
			if (!zephir_is_true(&_6$$4)) {
				ZEPHIR_INIT_VAR(&_9$$5);
				object_init_ex(&_9$$5, saas_cores_exceptions_licenceinvalidexception_ce);
				ZEPHIR_INIT_VAR(&_10$$5);
				ZVAL_STRING(&_10$$5, "This licence is invalid");
				ZEPHIR_CALL_METHOD(NULL, &_9$$5, "__construct", &_11, 19, &_10$$5);
				zephir_check_call_status_or_jump(try_end_1);
				zephir_throw_exception_debug(&_9$$5, "saas/Cores/Index.zep", 150 TSRMLS_CC);
				goto try_end_1;

			}
		} else {
			zephir_read_property(&_13$$6, &app, SL("licence_config"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch_string(&_14$$6, &_13$$6, SL("licence_id"), PH_NOISY | PH_READONLY, "saas/Cores/Index.zep", 154 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_12$$6, this_ptr, "verifylicenceoffline", NULL, 20, &_14$$6);
			zephir_check_call_status_or_jump(try_end_1);
			if (!zephir_is_true(&_12$$6)) {
				ZEPHIR_INIT_VAR(&_15$$7);
				object_init_ex(&_15$$7, saas_cores_exceptions_licenceinvalidexception_ce);
				ZEPHIR_INIT_VAR(&_16$$7);
				ZVAL_STRING(&_16$$7, "This licence is invalid");
				ZEPHIR_CALL_METHOD(NULL, &_15$$7, "__construct", &_11, 19, &_16$$7);
				zephir_check_call_status_or_jump(try_end_1);
				zephir_throw_exception_debug(&_15$$7, "saas/Cores/Index.zep", 155 TSRMLS_CC);
				goto try_end_1;

			}
		}
		zephir_read_property(&_17$$3, &app, SL("licence_config"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_18$$3, &_17$$3, SL("service_code"), PH_NOISY | PH_READONLY, "saas/Cores/Index.zep", 160 TSRMLS_CC);
		if (!ZEPHIR_IS_EQUAL(&_18$$3, &moduleName)) {
			ZEPHIR_INIT_VAR(&_19$$8);
			object_init_ex(&_19$$8, saas_cores_exceptions_licenceinvalidexception_ce);
			ZEPHIR_INIT_VAR(&_20$$8);
			ZVAL_STRING(&_20$$8, "This licence can not apply to this product");
			ZEPHIR_CALL_METHOD(NULL, &_19$$8, "__construct", &_11, 19, &_20$$8);
			zephir_check_call_status_or_jump(try_end_1);
			zephir_throw_exception_debug(&_19$$8, "saas/Cores/Index.zep", 161 TSRMLS_CC);
			goto try_end_1;

		}
		ZEPHIR_INIT_VAR(&_21$$3);
		ZVAL_STRING(&_21$$3, "Y-m-d");
		ZEPHIR_CALL_FUNCTION(&today, "date", NULL, 21, &_21$$3);
		zephir_check_call_status_or_jump(try_end_1);
		zephir_read_property(&_22$$3, &app, SL("licence_config"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_VAR(&expire);
		zephir_array_fetch_string(&expire, &_22$$3, SL("expired"), PH_NOISY, "saas/Cores/Index.zep", 165 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&_21$$3);
		object_init_ex(&_21$$3, php_date_get_date_ce());
		ZEPHIR_CALL_METHOD(NULL, &_21$$3, "__construct", NULL, 0, &expire);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_INIT_VAR(&_23$$3);
		ZVAL_STRING(&_23$$3, "Y-m-d");
		ZEPHIR_CALL_METHOD(&expire, &_21$$3, "format", NULL, 0, &_23$$3);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_FUNCTION(&today_time, "strtotime", &_24, 22, &today);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_FUNCTION(&expire_time, "strtotime", &_24, 22, &expire);
		zephir_check_call_status_or_jump(try_end_1);
		if (ZEPHIR_LT(&expire_time, &today_time)) {
			ZEPHIR_INIT_VAR(&_25$$9);
			object_init_ex(&_25$$9, saas_cores_exceptions_licenceexpiredexception_ce);
			zephir_read_property(&_26$$9, &app, SL("licence_config"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(NULL, &_25$$9, "__construct", NULL, 23, &_26$$9);
			zephir_check_call_status_or_jump(try_end_1);
			zephir_throw_exception_debug(&_25$$9, "saas/Cores/Index.zep", 173 TSRMLS_CC);
			goto try_end_1;

		}

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_27);
		ZVAL_OBJ(&_27, EG(exception));
		Z_ADDREF_P(&_27);
		if (zephir_instance_of_ev(&_27, spl_ce_RuntimeException TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CPY_WRT(&e, &_27);
			if (zephir_instance_of_ev(&e, saas_cores_exceptions_licenceexception_ce TSRMLS_CC)) {
				zephir_throw_exception_debug(&e, "saas/Cores/Index.zep", 177 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(saas_cores_exceptions_licenceinvalidexception_ce, "Can not parse licence", "saas/Cores/Index.zep", 179);
			return;
		} else {
			if (zephir_instance_of_ev(&_27, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
				zend_clear_exception(TSRMLS_C);
				ZEPHIR_CPY_WRT(&e, &_27);
				if (zephir_instance_of_ev(&e, saas_cores_exceptions_licenceexception_ce TSRMLS_CC)) {
					zephir_throw_exception_debug(&e, "saas/Cores/Index.zep", 177 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(saas_cores_exceptions_licenceinvalidexception_ce, "Can not parse licence", "saas/Cores/Index.zep", 179);
				return;
			}
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Saas_Cores_Index, verifyLicenceOnline) {

	zval _7$$3;
	zval _3, _12$$4;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *licenceId, licenceId_sub, __$true, headers, ch, result, httpCode, fields, payload, _0, _1, _2, _4, _5, licenceData$$3, tmp$$3, _8$$3, _9$$3, _10$$4, _11$$4, _13$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&licenceId_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&ch);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&httpCode);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&payload);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&licenceData$$3);
	ZVAL_UNDEF(&tmp$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_7$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &licenceId);



	ZEPHIR_INIT_VAR(&headers);
	zephir_create_array(&headers, 4, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Accept: application/json");
	zephir_array_fast_append(&headers, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "Content: application/json");
	zephir_array_fast_append(&headers, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "Content-Type: application/json");
	zephir_array_fast_append(&headers, &_0);
	zephir_read_property(&_1, this_ptr, SL("saas_verify_token"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_SV(&_2, "saas-verify-token: ", &_1);
	zephir_array_fast_append(&headers, &_2);
	ZEPHIR_CALL_FUNCTION(&ch, "curl_init", NULL, 7);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&fields);
	zephir_create_array(&fields, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(&_3, licenceId);
	zephir_array_update_string(&fields, SL("ids"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&payload);
	zephir_json_encode(&payload, &fields, 0 );
	ZEPHIR_OBS_VAR(&_4);
	zephir_read_static_property_ce(&_4, saas_cores_index_ce, SL("saas_core_url"), PH_NOISY_CC);
	ZEPHIR_INIT_LNVAR(_2);
	ZEPHIR_CONCAT_VS(&_2, &_4, "/licence/live-status");
	ZVAL_LONG(&_5, 10002);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_6, 10, &ch, &_5, &_2);
	zephir_check_call_status();
	ZVAL_LONG(&_5, 10023);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_6, 10, &ch, &_5, &headers);
	zephir_check_call_status();
	ZVAL_LONG(&_5, 19913);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_6, 10, &ch, &_5, &__$true);
	zephir_check_call_status();
	ZVAL_LONG(&_5, 10015);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_6, 10, &ch, &_5, &payload);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&result, "curl_exec", NULL, 11, &ch);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	zephir_json_decode(&_0, &result, 0 );
	ZEPHIR_CPY_WRT(&result, &_0);
	ZVAL_LONG(&_5, 2097154);
	ZEPHIR_CALL_FUNCTION(&httpCode, "curl_getinfo", NULL, 12, &ch, &_5);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "curl_close", NULL, 13, &ch);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(&httpCode, 200)) {
		zephir_get_strval(&_7$$3, licenceId);
		ZEPHIR_CPY_WRT(&tmp$$3, &_7$$3);
		zephir_read_property(&_8$$3, &result, SL("result"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_VAR(&_9$$3);
		zephir_read_property(&_9$$3, &_8$$3, SL("licences"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(&licenceData$$3);
		zephir_read_property_zval(&licenceData$$3, &_9$$3, &tmp$$3, PH_NOISY_CC);
		if (Z_TYPE_P(&licenceData$$3) != IS_NULL) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "updateblockinglicence", NULL, 24, &tmp$$3, &licenceData$$3);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_10$$4);
			zephir_read_property(&_11$$4, &licenceData$$3, SL("sts"), PH_NOISY_CC | PH_READONLY);
			zephir_fast_strtolower(&_10$$4, &_11$$4);
			ZEPHIR_INIT_VAR(&_12$$4);
			zephir_create_array(&_12$$4, 1, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_13$$4);
			ZVAL_STRING(&_13$$4, "using");
			zephir_array_fast_append(&_12$$4, &_13$$4);
			if (!(zephir_fast_in_array(&_10$$4, &_12$$4 TSRMLS_CC))) {
				RETURN_MM_BOOL(0);
			}
			RETURN_MM_BOOL(1);
		} else {
			RETURN_MM_BOOL(0);
		}
	} else {
		RETURN_MM_BOOL(0);
	}

}

PHP_METHOD(Saas_Cores_Index, updateBlockingLicence) {

	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *licenceId, licenceId_sub, *licenceData, licenceData_sub, __$true, headers, ch, result, httpCode, fields, payload, salt, pwverify, _0, _1, _2, _3, _4, _5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&licenceId_sub);
	ZVAL_UNDEF(&licenceData_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&ch);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&httpCode);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&payload);
	ZVAL_UNDEF(&salt);
	ZVAL_UNDEF(&pwverify);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &licenceId, &licenceData);



	ZEPHIR_INIT_VAR(&headers);
	zephir_create_array(&headers, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Accept: application/json");
	zephir_array_fast_append(&headers, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "Content: application/json");
	zephir_array_fast_append(&headers, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "Content-Type: application/json");
	zephir_array_fast_append(&headers, &_0);
	ZEPHIR_CALL_FUNCTION(&ch, "curl_init", NULL, 7);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&salt, this_ptr, "randomstring", NULL, 8);
	zephir_check_call_status();
	zephir_read_static_property_ce(&_1, saas_cores_index_ce, SL("saas_password_encrypt"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_SVS(&_2, "$2a$07$", &salt, "forsalt$");
	ZEPHIR_CALL_FUNCTION(&pwverify, "crypt", NULL, 9, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&fields);
	zephir_create_array(&fields, 3, 0 TSRMLS_CC);
	zephir_array_update_string(&fields, SL("verify"), &pwverify, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&fields, SL("licence_id"), licenceId, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_VAR(&_3);
	zephir_read_property(&_3, licenceData, SL("sts"), PH_NOISY_CC);
	zephir_array_update_string(&fields, SL("sts"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&payload);
	zephir_json_encode(&payload, &fields, 0 );
	zephir_read_static_property_ce(&_4, saas_cores_index_ce, SL("saas_offline_update_blocking_licence"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_5, 10002);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_6, 10, &ch, &_5, &_4);
	zephir_check_call_status();
	ZVAL_LONG(&_5, 10023);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_6, 10, &ch, &_5, &headers);
	zephir_check_call_status();
	ZVAL_LONG(&_5, 19913);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_6, 10, &ch, &_5, &__$true);
	zephir_check_call_status();
	ZVAL_LONG(&_5, 10015);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_6, 10, &ch, &_5, &payload);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&result, "curl_exec", NULL, 11, &ch);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	zephir_json_decode(&_0, &result, 0 );
	ZEPHIR_CPY_WRT(&result, &_0);
	ZVAL_LONG(&_5, 2097154);
	ZEPHIR_CALL_FUNCTION(&httpCode, "curl_getinfo", NULL, 12, &ch, &_5);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "curl_close", NULL, 13, &ch);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Saas_Cores_Index, verifyLicenceOffline) {

	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *licenceId, licenceId_sub, __$true, headers, ch, result, httpCode, fields, payload, _0, _1, _2, _4$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&licenceId_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&ch);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&httpCode);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&payload);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &licenceId);



	ZEPHIR_INIT_VAR(&headers);
	zephir_create_array(&headers, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Accept: application/json");
	zephir_array_fast_append(&headers, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "Content: application/json");
	zephir_array_fast_append(&headers, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "Content-Type: application/json");
	zephir_array_fast_append(&headers, &_0);
	ZEPHIR_CALL_FUNCTION(&ch, "curl_init", NULL, 7);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&fields);
	zephir_create_array(&fields, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&fields, SL("licence_id"), licenceId, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&payload);
	zephir_json_encode(&payload, &fields, 0 );
	zephir_read_static_property_ce(&_1, saas_cores_index_ce, SL("saas_offline_check_licence"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_2, 10002);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_3, 10, &ch, &_2, &_1);
	zephir_check_call_status();
	ZVAL_LONG(&_2, 10023);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_3, 10, &ch, &_2, &headers);
	zephir_check_call_status();
	ZVAL_LONG(&_2, 19913);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_3, 10, &ch, &_2, &__$true);
	zephir_check_call_status();
	ZVAL_LONG(&_2, 10015);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_3, 10, &ch, &_2, &payload);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&result, "curl_exec", NULL, 11, &ch);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	zephir_json_decode(&_0, &result, 0 );
	ZEPHIR_CPY_WRT(&result, &_0);
	ZVAL_LONG(&_2, 2097154);
	ZEPHIR_CALL_FUNCTION(&httpCode, "curl_getinfo", NULL, 12, &ch, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "curl_close", NULL, 13, &ch);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(&httpCode, 200)) {
		zephir_read_property(&_4$$3, &result, SL("is_blocked"), PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_4$$3)) {
			RETURN_MM_BOOL(0);
		}
		RETURN_MM_BOOL(1);
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(saas_cores_exceptions_licenceinvalidexception_ce, "An error has occured when checking licence offline", "saas/Cores/Index.zep", 295);
		return;
	}

}

PHP_METHOD(Saas_Cores_Index, decrypt) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *ivHashCiphertext, ivHashCiphertext_sub, *password, password_sub, __$true, method, iv, hash, ciphertext, key, _0, _1, _2, _3, _4, _5, _6, _7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ivHashCiphertext_sub);
	ZVAL_UNDEF(&password_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&iv);
	ZVAL_UNDEF(&hash);
	ZVAL_UNDEF(&ciphertext);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &ivHashCiphertext, &password);



	ZEPHIR_INIT_VAR(&method);
	ZVAL_STRING(&method, "AES-256-CBC");
	ZVAL_LONG(&_0, 0);
	ZVAL_LONG(&_1, 16);
	ZEPHIR_INIT_VAR(&iv);
	zephir_substr(&iv, ivHashCiphertext, 0 , 16 , 0);
	ZVAL_LONG(&_2, 16);
	ZVAL_LONG(&_3, 32);
	ZEPHIR_INIT_VAR(&hash);
	zephir_substr(&hash, ivHashCiphertext, 16 , 32 , 0);
	ZVAL_LONG(&_4, 48);
	ZEPHIR_INIT_VAR(&ciphertext);
	zephir_substr(&ciphertext, ivHashCiphertext, 48 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "sha256");
	ZEPHIR_CALL_FUNCTION(&key, "hash", NULL, 25, &_5, password, &__$true);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRING(&_5, "sha256");
	ZEPHIR_CALL_FUNCTION(&_6, "hash_hmac", NULL, 26, &_5, &ciphertext, &key, &__$true);
	zephir_check_call_status();
	if (!ZEPHIR_IS_IDENTICAL(&_6, &hash)) {
		RETURN_MM_NULL();
	}
	ZVAL_LONG(&_7, 1);
	ZEPHIR_RETURN_CALL_FUNCTION("openssl_decrypt", NULL, 27, &ciphertext, &method, &key, &_7, &iv);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Saas_Cores_Index, getLicenceId) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *licencePath, licencePath_sub, __$true, serial, serialDecode, config, _1, _2, _3, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&licencePath_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&serial);
	ZVAL_UNDEF(&serialDecode);
	ZVAL_UNDEF(&config);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &licencePath);



	ZEPHIR_INIT_VAR(&serial);
	zephir_file_get_contents(&serial, licencePath TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "hex2bin", NULL, 17, &serial);
	zephir_check_call_status();
	zephir_read_static_property_ce(&_2, saas_cores_index_ce, SL("saas_password_encrypt"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_SELF(&serialDecode, "decrypt", &_0, 16, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_3, "base64_decode", NULL, 4, &serialDecode);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&config);
	zephir_json_decode(&config, &_3, zephir_get_intval(&__$true) );
	zephir_array_fetch_string(&_4, &config, SL("licence_id"), PH_NOISY | PH_READONLY, "saas/Cores/Index.zep", 330 TSRMLS_CC);
	RETURN_CTOR(&_4);

}

PHP_METHOD(Saas_Cores_Index, getUniqueMachineID) {

	zend_bool _6$$3;
	zephir_fcall_cache_entry *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *salt = NULL, salt_sub, *_SERVER, result, _0, _1, _2, _3, _4, _17, _18, temp$$3, output$$3, lines$$3, _5$$3, _7$$3, _9$$3, _11$$3, _8$$4, _12$$5, _13$$5, _14$$5, _15$$7, _16$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&salt_sub);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&temp$$3);
	ZVAL_UNDEF(&output$$3);
	ZVAL_UNDEF(&lines$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$7);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));
	zephir_fetch_params(1, 0, 1, &salt);

	if (!salt) {
		salt = &salt_sub;
		ZEPHIR_INIT_VAR(salt);
		ZVAL_STRING(salt, "");
	}


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_GET_CONSTANT(&_1, "PHP_OS");
	ZVAL_LONG(&_2, 0);
	ZVAL_LONG(&_3, 3);
	ZEPHIR_INIT_VAR(&_4);
	zephir_substr(&_4, &_1, 0 , 3 , 0);
	zephir_fast_strtoupper(&_0, &_4);
	if (ZEPHIR_IS_STRING_IDENTICAL(&_0, "WIN")) {
		ZEPHIR_CALL_FUNCTION(&_5$$3, "sys_get_temp_dir", NULL, 28);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&temp$$3);
		ZEPHIR_CONCAT_VSS(&temp$$3, &_5$$3, "/", "diskpartscript.txt");
		_6$$3 = !((zephir_file_exists(&temp$$3 TSRMLS_CC) == SUCCESS));
		if (_6$$3) {
			ZEPHIR_CALL_FUNCTION(&_7$$3, "is_file", NULL, 29, &temp$$3);
			zephir_check_call_status();
			_6$$3 = !zephir_is_true(&_7$$3);
		}
		if (_6$$3) {
			ZEPHIR_INIT_VAR(&_8$$4);
			ZVAL_STRING(&_8$$4, "select disk 0\ndetail disk");
			zephir_file_put_contents(NULL, &temp$$3, &_8$$4 TSRMLS_CC);
		}
		ZEPHIR_INIT_VAR(&_9$$3);
		ZEPHIR_CONCAT_SV(&_9$$3, "diskpart /s ", &temp$$3);
		ZEPHIR_CALL_FUNCTION(&output$$3, "shell_exec", &_10, 30, &_9$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&lines$$3);
		zephir_fast_explode_str(&lines$$3, SL("\n"), &output$$3, LONG_MAX TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_11$$3);
		ZEPHIR_INIT_NVAR(&_11$$3);
		zephir_create_closure_ex(&_11$$3, NULL, saas_0__closure_ce, SL("__invoke"));
		ZEPHIR_CALL_FUNCTION(&result, "array_filter", NULL, 31, &lines$$3, &_11$$3);
		zephir_check_call_status();
		if (zephir_fast_count_int(&result TSRMLS_CC) > 0) {
			ZEPHIR_CALL_FUNCTION(&_12$$5, "array_values", NULL, 32, &result);
			zephir_check_call_status();
			ZEPHIR_MAKE_REF(&_12$$5);
			ZEPHIR_CALL_FUNCTION(&result, "array_shift", NULL, 33, &_12$$5);
			ZEPHIR_UNREF(&_12$$5);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_13$$5);
			zephir_fast_explode_str(&_13$$5, SL(":"), &result, LONG_MAX TSRMLS_CC);
			ZEPHIR_CPY_WRT(&result, &_13$$5);
			ZEPHIR_MAKE_REF(&result);
			ZEPHIR_CALL_FUNCTION(&_14$$5, "end", NULL, 34, &result);
			ZEPHIR_UNREF(&result);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&result);
			zephir_fast_trim(&result, &_14$$5, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
		} else {
			ZEPHIR_CPY_WRT(&result, &output$$3);
		}
	} else {
		ZEPHIR_INIT_VAR(&_15$$7);
		ZVAL_STRING(&_15$$7, "blkid -o value -s UUID");
		ZEPHIR_CALL_FUNCTION(&result, "shell_exec", &_10, 30, &_15$$7);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_15$$7);
		ZVAL_STRING(&_15$$7, "blkid");
		ZEPHIR_CALL_FUNCTION(&_16$$7, "stripos", NULL, 35, &result, &_15$$7);
		zephir_check_call_status();
		if (!ZEPHIR_IS_FALSE_IDENTICAL(&_16$$7)) {
			ZEPHIR_OBS_NVAR(&result);
			zephir_array_fetch_string(&result, _SERVER, SL("HTTP_HOST"), PH_NOISY, "saas/Cores/Index.zep", 356 TSRMLS_CC);
		}
	}
	ZEPHIR_INIT_VAR(&_17);
	zephir_md5(&_17, &result);
	ZEPHIR_INIT_VAR(&_18);
	ZEPHIR_CONCAT_VV(&_18, salt, &_17);
	ZEPHIR_RETURN_CALL_FUNCTION("sha1", NULL, 36, &_18);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Saas_Cores_Index, randomString) {

	zval _2$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_5 = NULL;
	zval *length = NULL, length_sub, str, size, bytes, len, _1$$3, _3$$3, _4$$3, _6$$3, _7$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&length_sub);
	ZVAL_UNDEF(&str);
	ZVAL_UNDEF(&size);
	ZVAL_UNDEF(&bytes);
	ZVAL_UNDEF(&len);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &length);

	if (!length) {
		length = &length_sub;
		ZEPHIR_INIT_VAR(length);
		ZVAL_LONG(length, 16);
	}


	ZEPHIR_INIT_VAR(&str);
	ZVAL_STRING(&str, "");
	while (1) {
		if (!(1)) {
			break;
		}
		ZEPHIR_INIT_NVAR(&len);
		ZVAL_LONG(&len, zephir_fast_strlen_ev(&str));
		if (ZEPHIR_GE(&len, length)) {
			break;
		}
		ZEPHIR_INIT_NVAR(&size);
		zephir_sub_function(&size, length, &len);
		ZEPHIR_CALL_FUNCTION(&bytes, "random_bytes", &_0, 37, &size);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZEPHIR_INIT_NVAR(&_2$$3);
		zephir_create_array(&_2$$3, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "/");
		zephir_array_fast_append(&_2$$3, &_3$$3);
		ZEPHIR_INIT_NVAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "+");
		zephir_array_fast_append(&_2$$3, &_3$$3);
		ZEPHIR_INIT_NVAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "=");
		zephir_array_fast_append(&_2$$3, &_3$$3);
		ZEPHIR_CALL_FUNCTION(&_4$$3, "base64_encode", &_5, 5, &bytes);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "");
		zephir_fast_str_replace(&_1$$3, &_2$$3, &_3$$3, &_4$$3 TSRMLS_CC);
		ZVAL_LONG(&_6$$3, 0);
		ZEPHIR_INIT_NVAR(&_7$$3);
		zephir_substr(&_7$$3, &_1$$3, 0 , zephir_get_intval(&size), 0);
		zephir_concat_self(&str, &_7$$3 TSRMLS_CC);
	}
	RETURN_CCTOR(&str);

}

