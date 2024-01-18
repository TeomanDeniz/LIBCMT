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

/******************************************************************************\
|*                                  CONTENTS                                  *|
|******************************************************************************|
|*............................................................................*|
|*        NAME       :   TYPE  :                 DESCRIPTION                  *|
|*...................:.........:..............................................*|
|* PRAGMA_PACK_PUSH  : #define : START OF THE PACKING EFFECTION [WORKS LIKE   *|
|*                   :         : #pragma pack(push)].                         *|
|*...................:.........:..............................................*|
|* PRAGMA_PACK_POP   : #define : END OF THE PACKING EFFECTION [WORKS LIKE     *|
|*                   :         : #pragma pack(pop)].                          *|
|*...................:.........:..............................................*|
|* __STD_PACK__      : #define : PACK THE SPECIFICALLY SELECTED STRUCT.       *|
|*...................:.........:..............................................*|
\******************************************************************************/

/******************************************************************************\
|*                                 SIDE NOTES                                 *|
|******************************************************************************|
|*                                                                            *|
|*                                 IMPORTANT                                  *|
|* YOU MUST USE BOTH __STD_PACK__ AND PRAGMA_PACK_... ON A STRUCT IF YOU WANT *|
|* TO PACK IT.                                                                *|
|*                                                                            *|
|*                                 HOW TO USE                                 *|
|* O - EXAMPLES                                                               *|
|* :                                                                          *|
|* ;.., PRAGMA_PACK_PUSH                                                      *|
|* :  : struct test                                                           *|
|* :  : {                                                                     *|
|* :  :     . . .                                                             *|
|* :  : } __STD_PACK__;                                                       *|
|* :  : PRAGMA_PACK_POP                                                       *|
|* :                                                                          *|
|* ;.., PRAGMA_PACK_PUSH                                                      *|
|*    : typedef struct test                                                   *|
|*    : {                                                                     *|
|*    :     . . .                                                             *|
|*    : } __STD_PACK__ t_test;                                                *|
|*                                                                            *|
\******************************************************************************/

/******************************************************************************\
|*                               WTF THAT DOES?                               *|
|******************************************************************************|
|*                                                                            *|
\******************************************************************************/

/* ************************* [v] VERSION CONTROL [v] ************************ */
#define LIBRARY_VERSION 202401 /* VERSION */
#ifdef PACK_H
#	if (PACK_H < LIBRARY_VERSION)
#		undef PACK_H /* OLD VERSION DETECTED */
#	endif /* PACK_H < LIBRARY_VERSION */
#endif /* PACK_H */
#undef LIBRARY_VERSION
/* ************************* [^] VERSION CONTROL [^] ************************ */

#ifndef PACK_H

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

#	define PACK_H 202401

/* ****************************** [v] RESET [v] ***************************** */
#	undef PRAGMA_PACK_PUSH
#	undef PRAGMA_PACK_POP
/* ****************************** [^] RESET [^] ***************************** */

#	ifdef _MSC_VER /* MICROSOFT C++ */
#		define PRAGMA_PACK_PUSH(PRAGMA_PACK_PUSH_MSC_VER) \
			__pragma(pack(push, PRAGMA_PACK_PUSH_MSC_VER));
#		define PRAGMA_PACK_POP __pragma(pack(pop));
#		define __STD_PACK__ /* EMPTY */
#	else
#		if (\
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
#			ifndef __TINYC__ /* TCC */
#				define PRAGMA_PACK_PUSH _Pragma("pack(push, 1)")
#				define PRAGMA_PACK_POP _Pragma("pack(pop)");
#				define __STD_PACK__ __attribute__((packed))
#			else
#				define PRAGMA_PACK_PUSH /* EMPTY */
#				define PRAGMA_PACK_POP /* EMPTY */
#				define __STD_PACK__ __attribute__((packed))
#			endif /* __TINYC__ */
#		else
#			define PRAGMA_PACK_PUSH /* EMPTY */
#			define PRAGMA_PACK_POP /* EMPTY */
#			define __STD_PACK__ /* EMPTY */
#		endif /* GNUC */
#	endif /* _MSC_VER */

#	ifdef __cplusplus /* C++ */
		}
#	endif /* __cplusplus */
#	ifdef __TI_COMPILER_VERSION__
#		pragma diag_pop /* TI CGT CCS COMPILER DIRECTIVES */
#	endif /* __TI_COMPILER_VERSION__ */
#endif /* PACK_H */
