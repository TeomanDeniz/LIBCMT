/******************************************************************************\
# H - PACK                                       #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2023/07/11 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - GNU       :: Update - 2024/01/17 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

/* LIST

	WARNING: USE IT ONLY FOR (INTEGER) OR (FLOAT-POINT) VARIABLES

	__STD_REGPARM__(VALUE)

*/

/* USAGE

	void __STD_REGPARM__(1) function(int b)	{
		...
	}

	void __STD_REGPARM__(2) function(int a, int b)
	{
		...
	}

	void __STD_REGPARM__(4) function(int a, int b, int c, int d)
	{
		...
	}

*/

/******************************************************************************\
|*                               WTF THAT DOES?                               *|
|******************************************************************************|
|*                                                                            *|
\******************************************************************************/

/* ************************* [v] VERSION CONTROL [v] ************************ */
#define LIBRARY_VERSION 202401
#ifdef REGPARM_H
#	if (REGPARM_H < LIBRARY_VERSION)
#		undef REGPARM_H
#	endif
#endif
#undef LIBRARY_VERSION
/* ************************* [^] VERSION CONTROL [^] ************************ */

#ifndef REGPARM_H

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

#	define REGPARM_H 202401

/* ****************************** [v] RESET [v] ***************************** */
#	undef __STD_REGPARM__
/* ****************************** [^] RESET [^] ***************************** */

#	ifdef _MSC_VER
#		define __STD_REGPARM__(__REGPARM_NUMBER_OF_VARIABLES__) \
			__attribute__((fastcall))
#	else
#		ifdef __cplusplus
#			define __STD_REGPARM__(__REGPARM_NUMBER_OF_VARIABLES__) \
				__attribute__((fastcall))
#		else
#			if (\
				defined(__GNUC__) && /* IF GCC */ \
				(\
					(__GNUC__ >= 2) || /* IF GEQ 2.X.X */ \
					(\
						(__GNUC_MINOR__ >= 7) || /* IF GEQ X.7.X */ \
						(\
							(__GNUC_PATCHLEVEL__ >= 1) /* IF GEQ X.X.1 */\
						)\
					)\
				)\
			) /* IS GCC VERSION 2.7.1 OR GREATHER (MINIMUM C99) */
#				ifdef __clang__
#					define __STD_REGPARM__(__REGPARM_NUMBER_OF_VARIABLES__) \
						__attribute__((\
						regparm(__REGPARM_NUMBER_OF_VARIABLES__)))
#				else
#					ifdef __DJGPP__
#						define __STD_REGPARM__(__REGPARM_NUMBER_OF_VARIABLES__)
#					else
#						define __STD_REGPARM__(__REGPARM_NUMBER_OF_VARIABLES__)\
							__attribute__((\
							regparm(__REGPARM_NUMBER_OF_VARIABLES__)))
#					endif /* DJGPP */
#				endif /* __clang__ */
#			else
#				define __STD_REGPARM__(__REGPARM_NUMBER_OF_VARIABLES__)
#			endif /* GNUC */
#		endif /* C++ */
#	endif /* MICROSOFT C++ */

#	ifdef __cplusplus /* C++ */
		}
#	endif /* __cplusplus */
#	ifdef __TI_COMPILER_VERSION__
#		pragma diag_pop /* TI CGT CCS COMPILER DIRECTIVES */
#	endif /* __TI_COMPILER_VERSION__ */
#endif /* REGPARM_H */