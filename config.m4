PHP_ARG_ENABLE(saas, whether to enable saas, [ --enable-saas   Enable Saas])

if test "$PHP_SAAS" = "yes"; then

	

	if ! test "x" = "x"; then
		PHP_EVAL_LIBLINE(, SAAS_SHARED_LIBADD)
	fi

	AC_DEFINE(HAVE_SAAS, 1, [Whether you have Saas])
	saas_sources="saas.c kernel/main.c kernel/memory.c kernel/exception.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/string.c kernel/fcall.c kernel/require.c kernel/file.c kernel/operators.c kernel/math.c kernel/concat.c kernel/variables.c kernel/filter.c kernel/iterator.c kernel/time.c kernel/exit.c saas/cores/exceptions/licenceexception.zep.c
	saas/cores/exceptions/licenceexpiredexception.zep.c
	saas/cores/exceptions/licenceinvalidexception.zep.c
	saas/cores/index.zep.c
	saas/cores/saassystem.zep.c
	saas/0__closure.zep.c "
	PHP_NEW_EXTENSION(saas, $saas_sources, $ext_shared,, )
	PHP_SUBST(SAAS_SHARED_LIBADD)

	old_CPPFLAGS=$CPPFLAGS
	CPPFLAGS="$CPPFLAGS $INCLUDES"

	AC_CHECK_DECL(
		[HAVE_BUNDLED_PCRE],
		[
			AC_CHECK_HEADERS(
				[ext/pcre/php_pcre.h],
				[
					PHP_ADD_EXTENSION_DEP([saas], [pcre])
					AC_DEFINE([ZEPHIR_USE_PHP_PCRE], [1], [Whether PHP pcre extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	AC_CHECK_DECL(
		[HAVE_JSON],
		[
			AC_CHECK_HEADERS(
				[ext/json/php_json.h],
				[
					PHP_ADD_EXTENSION_DEP([saas], [json])
					AC_DEFINE([ZEPHIR_USE_PHP_JSON], [1], [Whether PHP json extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	CPPFLAGS=$old_CPPFLAGS

	PHP_INSTALL_HEADERS([ext/saas], [php_SAAS.h])

fi
