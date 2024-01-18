/******************************************************************************\
# H - PACK                                       #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2023/07/07 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - GNU       :: Update - 2024/01/17 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

/* LIST
#	Function never ends even if function reached to "return (0)"
#	Example:

	NORETURN
	noreturn
*/

/* USAGE

int NORETURN	function(void)
{
	return (0);
}

*/

/******************************************************************************\
|*                               WTF THAT DOES?                               *|
|******************************************************************************|
|*                                                                            *|
\******************************************************************************/

/* ************************* [v] VERSION CONTROL [v] ************************ */
#define LIBRARY_VERSION 202401
#ifdef NORETURN_H
#	if (NORETURN_H < LIBRARY_VERSION)
#		undef NORETURN_H
#	endif
#endif
#undef LIBRARY_VERSION
/* ************************* [^] VERSION CONTROL [^] ************************ */

#ifndef NORETURN_H

/* *************************** [v] TI CGT CCS [v] *************************** */
#	ifdef __TI_COMPILER_VERSION__
#		pragma diag_push /* TI CGT CCS COMPILER DIRECTIVES */
#		pragma CHECK_MISRA("-5.4") /* TAG NAMES SHALL BE A UNIQUE IDENTIFIER */
#		pragma CHECK_MISRA("-19.3") /* THE #INCLUDE DIRECTIVE SHALL BE FOLLOWED
#		BY EITHER A <FILENAME> OR "FILENAME" SEQUENCE */
#	endif /* __TI_COMPILER_VERSION__ */
/* *************************** [^] TI CGT CCS [^] *************************** */

#	ifdef __cplusplus /* C++ */
		extern "C" {
#	endif /* __cplusplus */

#	define NORETURN_H 202401

/* ****************************** [v] RESET [v] ***************************** */
#	undef noreturn
#	undef NORETURN
#	undef __noreturn_is_defined
#	undef __NORETURN_IS_DEFINED
/* ****************************** [^] RESET [^] ***************************** */

#	ifndef __STDNORETURN_H
#		define __STDNORETURN_H
#	endif /* __STDNORETURN_H */

#	if (defined(__clang__) && (__clang_major__ >= 3 && __clang_minor__ >= 3))
#		define noreturn _Noreturn
#		define NORETURN _Noreturn
#		define __noreturn_is_defined 1
#		define __NORETURN_IS_DEFINED 1
#	else
#		if (defined(__GNUC__) && ((__GNUC__ > 4) || (__GNUC__ == 4 && __GNUC_MINOR__ >= 2))) /* GCC */
#			define noreturn __attribute__((noreturn))
#			define NORETURN __attribute__((noreturn))
#			define _Noreturn __attribute__((noreturn))
#			define __noreturn_is_defined 1
#			define __NORETURN_IS_DEFINED 1
#		else /* DJGPP || TCC || K&R */
#			define noreturn /* EMPTY */
#			define NORETURN /* EMPTY */
#			define _Noreturn /* EMPTY */
#			define __noreturn_is_defined 0
#			define __NORETURN_IS_DEFINED 0
#		endif /* __GNUC__ */
#	endif /* __clang__ */
#	ifdef __cplusplus /* C++ */
		}
#	endif /* __cplusplus */
#	ifdef __TI_COMPILER_VERSION__
#		pragma diag_pop /* TI CGT CCS COMPILER DIRECTIVES */
#	endif /* __TI_COMPILER_VERSION__ */
#endif /* NORETURN_H */