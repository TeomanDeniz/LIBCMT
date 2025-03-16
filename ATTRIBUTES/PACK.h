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
# : License - AGPL-3.0  :: Update - 2025/03/16 : #    ::::!!!1!!1!!!1!!!::     #
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
|* YOU MUST USE BOTH "PACK" AND "PRAGMA_PACK_..." ON A STRUCT IF YOU WANT TO  *|
|* PACK IT. IF YOU WANNA USE FULL SYNTAX SUPPORT OF THIS FEATURE.             *|
|*                                                                            *|
|* ::::::::::::::::::::::::::::::: HOW TO USE ::::::::::::::::::::::::::::::: *|
|* O - EXAMPLES                                                               *|
|* :                                                                          *|
|* ;.., PRAGMA_PACK_PUSH                                                      *|
|* :  : struct test                                                           *|
|* :  : {                                                                     *|
|* :  :     . . .                                                             *|
|* :  : } PACK;                                                               *|
|* :  : PRAGMA_PACK_POP                                                       *|
|* :                                                                          *|
|* ;.., PRAGMA_PACK_PUSH                                                      *|
|*    : typedef struct test                                                   *|
|*    : {                                                                     *|
|*    :     . . .                                                             *|
|*    : } PACK t_test;                                                        *|
|*    : PRAGMA_PACK_POP                                                       *|
|*                                                                            *|
\******************************************************************************/

/*############################################################################*\
|*#                              WTF THAT DOES?                              #*|
|*############################################################################*|
|*                                                                            *|
|* :::::::::::::::::::::::::::::: EXPLANATION ::::::::::::::::::::::::::::::: *|
|* [PACK] IS PACKING OR REMOVING PADDING BYTES FROM YOUR STURCT.              *|
|* I WOULD PREFER NOT TO USE THIS MODULE UNLESS YOU HAVE A VERY BIG STRUCT.   *|
|*                                                                            *|
|* BECAUSE REMOVING PADDINGS FROM YOUR STURCT WILL CAUSE SOME PERFORMANCE     *|
|* ISSUES.                                                                    *|
|*                                                                            *|
|* :::::::::::::::::::::::::::::::::: HOW? :::::::::::::::::::::::::::::::::: *|
|* WHILE CPU READING YOUR STRUCT, IT IS READING AND DECIDING TO USE IT VIA    *|
|* IT'S ALING. ALING WORKS AS 1 - 2 - 4 - 8 - 16 - 32 - 64... SO PADDING      *|
|*                                                                            *|
|* O - EXAMPLES                                                               *|
|* :                                                                          *|
|* ;.., struct test                                                           *|
|* :  : {                                                                     *|
|* :  :     int a;                                                            *|
|* :  : };                                                                    *|
|* :  ;... THIS STRUCT'S SIZEOF GOING TO BE [4] BYTES!                        *|
|* :                                                                          *|
|* ;.., struct test                                                           *|
|* :  : {                                                                     *|
|* :  :     int a;                                                            *|
|* :  :     char b;                                                           *|
|* :  : };                                                                    *|
|* :  ;.., THIS STRUCT'S SIZEOF GOING TO BE [8] BYTES!                        *|
|* :     :                                                                    *|
|* :     ;.., WHERE IS 3 BYTES SINCE WE USED 5 BYTES IN THE STURCT?           *|
|* :        : ANSER: WE CALLING THEM PADDING. THESE EXTRA SPACES ARE FOR MAKE *|
|* :        : THE CPU READ THE STURCT FASTER FROM THE MEMORY.                 *|
|* :                                                                          *|
|* ;.., SO, IF WE DO:                                                         *|
|*    :                                                                       *|
|*    ;.., PRAGMA_PACK_PUSH                                                   *|
|*    :  : struct test                                                        *|
|*    :  : {                                                                  *|
|*    :  :     int a;                                                         *|
|*    :  :     char b;                                                        *|
|*    :  : } PACK;                                                            *|
|*    :  : PRAGMA_PACK_POP                                                    *|
|*    :                                                                       *|
|*    ;... THIS STRUCT'S SIZEOF GOING TO BE [5] BYTES NOW!                    *|
|*                                                                            *|
|* SO, PADDING IN STURCUT WORKS LIKE FILLING THE AREA WITH EXTRA BYTES TO     *|
|* REACH THESE NUMBERS. OTHERWISE, IT WILL CAUSE AN OVERFLOW (OVERREAD).      *|
|* OR COMPILER JUST DECIDES THE ALING OF THE STRUCT BY 1 OR 2 TO PREVENT IT   *|
|* FROM HAPPENING.                                                            *|
|*                                                                            *|
|* AND YOU MUST AWARE, THIS IS GOING TO CAUSE SOME PERFORMANCE ISSUES WHILE   *|
|* SHARING YOUR STRUCT BETWEEN FUNCTIONS.                                     *|
|*                                                                            *|
\******************************************************************************/

/* ************************* [v] VERSION CONTROL [v] ************************ */
#if (defined(PACK_H) && PACK_H < 202503)
#	undef PACK_H /* OLD VERSION DETECTED */
#endif /* PACK_H < LIBRARY_VERSION */
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

#	define PACK_H 202503 /* VERSION */

/* ****************************** [v] RESET [v] ***************************** */
#	undef PRAGMA_PACK_PUSH
#	undef PRAGMA_PACK_POP
#	undef PACK
/* ****************************** [^] RESET [^] ***************************** */

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
#		endif /* GNUC */
#	endif /* _MSC_VER */

#	ifdef __cplusplus /* C++ */
		}
#	endif /* __cplusplus */

#	ifdef __TI_COMPILER_VERSION__
#		pragma diag_pop /* TI CGT CCS COMPILER DIRECTIVES */
#	endif /* __TI_COMPILER_VERSION__ */
#endif /* PACK_H */
