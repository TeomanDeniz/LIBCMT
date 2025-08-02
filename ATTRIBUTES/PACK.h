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
# : License - AGPL-3.0  :: Update - 2025/08/02 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

/*############################################################################*\
|*#                                 CONTENTS                                 #*|
|*############################################################################*|
|*............................................................................*|
|*        NAME       :   TYPE  :                 DESCRIPTION                  *|
|*...................:.........:..............................................*|
|* PRAGMA_PACK_PUSH  : #define : START OF THE PACKING EFFECTION [WORKS LIKE   *|
|*                   :         : #pragma pack(push)].                         *|
|*...................:.........:..............................................*|
|* PRAGMA_PACK_POP   : #define : END OF THE PACKING EFFECTION [WORKS LIKE     *|
|*                   :         : #pragma pack(pop)].                          *|
|*...................:.........:..............................................*|
|* PACK              : #define : PACK THE SPECIFICALLY SELECTED STRUCT.       *|
|*...................:.........:..............................................*|
\******************************************************************************/

/*############################################################################*\
|*#                                HOW TO USE                                #*|
|*############################################################################*|
|*                                                                            *|
|* ::::::::::::::::::::::::::::::: IMPORTANT :::::::::::::::::::::::::::::::: *|
|* YOU MUST USE BOTH "PACK" AND "PRAGMA_PACK_..." MACROS ON A STRUCT IF YOU   *|
|* WANT TO PACK IT. THIS IS REQUIRED TO UNLOCK THE FULL SYNTAX SUPPORT FOR    *|
|* THIS FEATURE.                                                              *|
|*                                                                            *|
|* ::::::::::::::::::::::::::::::: HOW TO USE ::::::::::::::::::::::::::::::: *|
|* O - EXAMPLES                                                               *|
|* :                                                                          *|
|* ;.., PRAGMA_PACK_PUSH                                                      *|
|* :  : struct test                                                           *|
|* :  : {                                                                     *|
|* :  :     ...                                                               *|
|* :  : } PACK;                                                               *|
|* :  : PRAGMA_PACK_POP                                                       *|
|* :                                                                          *|
|* ;.., PRAGMA_PACK_PUSH                                                      *|
|*    : typedef struct test                                                   *|
|*    : {                                                                     *|
|*    :     ...                                                               *|
|*    : } PACK t_test;                                                        *|
|*    : PRAGMA_PACK_POP                                                       *|
|*                                                                            *|
\******************************************************************************/

/*############################################################################*\
|*#                               WHAT IT DOES                               #*|
|*############################################################################*|
|*                                                                            *|
|* :::::::::::::::::::::::::::::: EXPLANATION ::::::::::::::::::::::::::::::: *|
|* [PACK] REMOVES PADDING BYTES FROM YOUR STRUCT TO TIGHTLY PACK ITS FIELDS.  *|
|*                                                                            *|
|* UNLESS YOU ARE DEALING WITH A VERY LARGE STRUCT OR LOW-LEVEL BINARY DATA,  *|
|* IT IS RECOMMENDED TO AVOID USING THIS FEATURE.                             *|
|*                                                                            *|
|* REMOVING PADDING CAN CAUSE PERFORMANCE PENALTIES ON SOME SYSTEMS.          *|
|*                                                                            *|
|* :::::::::::::::::::::::::::::::::: HOW? :::::::::::::::::::::::::::::::::: *|
|* WHEN THE CPU ACCESSES STRUCT FIELDS, IT RELIES ON MEMORY ALIGNMENT RULES.  *|
|* ALIGNMENT USUALLY FOLLOWS POWERS OF TWO (1, 2, 4, 8, 16, ...).             *|
|* TO MAINTAIN THIS, COMPILERS AUTOMATICALLY ADD PADDING BYTES.               *|
|*                                                                            *|
|* O - EXAMPLES                                                               *|
|* :                                                                          *|
|* ;.., struct test                                                           *|
|* :  : {                                                                     *|
|* :  :     int a;                                                            *|
|* :  : };                                                                    *|
|* :  ;... SIZEOF = 4 BYTES                                                   *|
|* :                                                                          *|
|* ;.., struct test                                                           *|
|* :  : {                                                                     *|
|* :  :     int a;                                                            *|
|* :  :     char b;                                                           *|
|* :  : };                                                                    *|
|* :  ;.., SIZEOF = 8 BYTES                                                   *|
|* :     :                                                                    *|
|* :     ;.., WHERE DID THE EXTRA 3 BYTES GO?                                 *|
|* :        : ANSWER: THEY ARE PADDING BYTES ADDED FOR ALIGNMENT.             *|
|* :        : THIS HELPS THE CPU READ THE STRUCT FASTER.                      *|
|* :                                                                          *|
|* ;.., PACKING THE STRUCT:                                                   *|
|*    :                                                                       *|
|*    ;.., PRAGMA_PACK_PUSH                                                   *|
|*    :  : struct test                                                        *|
|*    :  : {                                                                  *|
|*    :  :     int a;                                                         *|
|*    :  :     char b;                                                        *|
|*    :  : } PACK;                                                            *|
|*    :  : PRAGMA_PACK_POP                                                    *|
|*    :                                                                       *|
|*    ;... NOW SIZEOF = 5 BYTES                                               *|
|*                                                                            *|
|* PADDING WORKS BY FILLING STRUCTS WITH EXTRA BYTES TO ALIGN THEIR FIELDS.   *|
|* WITHOUT IT, YOU RISK OVERREAD/OVERFLOW OR UNALIGNED ACCESS.                *|
|* COMPILERS MAY FORCE THE ALIGNMENT TO A LOWER VALUE TO PREVENT THIS.        *|
|*                                                                            *|
|* /!\ BE AWARE: PACKING MAY CAUSE PERFORMANCE ISSUES WHEN PASSING STRUCTS    *|
|* BETWEEN FUNCTIONS OR MODULES DUE TO UNALIGNED MEMORY ACCESS.               *|
|*                                                                            *|
\******************************************************************************/

#ifndef PACK_H
#	define PACK_H 202508 /* VERSION */

/* *********************** [v] TI CGT CCS (PUSH) [v] ************************ */
#	ifdef __TI_COMPILER_VERSION__
#		pragma diag_push /* TI CGT CCS COMPILER DIRECTIVES */
#		pragma CHECK_MISRA("5.4") /* TAG NAMES SHALL BE A UNIQUE IDENTIFIER */
#		pragma CHECK_MISRA("19.3") /*
#			THE #INCLUDE DIRECTIVE SHALL BE FOLLOWED BY EITHER A <FILENAME> OR
#			"FILENAME" SEQUENCE
#		*/
#	endif /* __TI_COMPILER_VERSION__ */
/* *********************** [^] TI CGT CCS (PUSH) [^] ************************ */

/* *************************** [v] C++ (PUSH) [v] *************************** */
#	ifdef __cplusplus /* C++ */
extern "C" {
#	endif /* __cplusplus */
/* *************************** [^] C++ (PUSH) [^] *************************** */

#	ifdef _MSC_VER /* MICROSOFT C++ */
#		define PRAGMA_PACK_PUSH(PRAGMA_PACK_PUSH_MSC_VER) \
			__pragma(pack(push, PRAGMA_PACK_PUSH_MSC_VER));
#		define PRAGMA_PACK_POP __pragma(pack(pop));
#		define PACK /* EMPTY */
#	else
#		if (\
			defined(__GNUC__) && /* IF GCC */\
			(\
				(__GNUC__ >= 2) && /* IF GRE 2.X.X */\
				(__GNUC_MINOR__ >= 7) && /* IF GEQ X.7.X */\
				(__GNUC_PATCHLEVEL__ >= 1) /* IF GEQ X.X.1 */\
			)\
		) /* IS GCC VERSION 2.7.1 OR GREATHER (MAXIMUM C90) */
#			ifdef __TINYC__ /* TCC */
#				define PRAGMA_PACK_PUSH /* EMPTY */
#				define PRAGMA_PACK_POP /* EMPTY */
#				define PACK __attribute__((packed))
#			else
#				define PRAGMA_PACK_PUSH _Pragma("pack(push, 1)")
#				define PRAGMA_PACK_POP _Pragma("pack(pop)");
#				define PACK __attribute__((packed))
#			endif /* __TINYC__ */
#		else
#			define PRAGMA_PACK_PUSH /* EMPTY */
#			define PRAGMA_PACK_POP /* EMPTY */
#			define PACK /* EMPTY */
#		endif /* __GNUC__ 2.7.1 */
#	endif /* _MSC_VER */

/* *************************** [v] C++ (POP) [v] **************************** */
#	ifdef __cplusplus /* C++ */
}
#	endif /* __cplusplus */
/* *************************** [^] C++ (POP) [^] **************************** */

/* ************************ [v] TI CGT CCS (POP) [v] ************************ */
#	ifdef __TI_COMPILER_VERSION__
#		pragma diag_pop /* TI CGT CCS COMPILER DIRECTIVES */
#	endif /* __TI_COMPILER_VERSION__ */
/* ************************ [^] TI CGT CCS (POP) [^] ************************ */

#endif /* !PACK_H */
