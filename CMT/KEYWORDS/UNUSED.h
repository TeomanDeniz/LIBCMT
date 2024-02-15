/******************************************************************************\
# H - UNUSED                                     #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2023/07/09 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - AGPL-3.0  :: Update - 2024/01/15 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

/*############################################################################*\
|*#                                 CONTENTS                                 #*|
|*############################################################################*|
|*............................................................................*|
|*  NAME  :  TYPE   :                      DESCRIPTION                        *|
|*........:.........:.........................................................*|
|* UNUSED : #define : TELLIG TO THE COMPILER THE FUNCTION MAY UNUSED          *|
|* unused :         :                                                         *|
|*........:.........:.........................................................*|
|* NOPE   : #define : TELLIG TO THE COMPILER THE VARIABLE MAY NOT USED        *|
|* nope   :         :                                                         *|
|*........:.........:.........................................................*|
\******************************************************************************/

/*############################################################################*\
|*#                                HOW TO USE                                #*|
|*############################################################################*|
|*                                                                            *|
|* ::::::::::::::::::::::::::::::::: UNUSED ::::::::::::::::::::::::::::::::: *|
|* JUST PUT THIS TAG ON THE BEGINNING OF THE FUNCTION. EZ LOL                 *|
|*                                                                            *|
|* O - EXAMPLES                                                               *|
|* :                                                                          *|
|* ;.., UNUSED void function(void)                                            *|
|* :  : {                                                                     *|
|* :  :     . . .                                                             *|
|* :  : }                                                                     *|
|* :                                                                          *|
|* ;.., unused void function(void)                                            *|
|*    : {                                                                     *|
|*    :     . . .                                                             *|
|*    : }                                                                     *|
|*                                                                            *|
|* :::::::::::::::::::::::::::::::::: NOPE :::::::::::::::::::::::::::::::::: *|
|* JUST PUT THIS TAG ON THE BEGINNING OF THE VARIABLE. EZ LOL                 *|
|*                                                                            *|
|* O - EXAMPLES                                                               *|
|* :                                                                          *|
|* ;.., NOPE void *test;                                                      *|
|* :                                                                          *|
|* ;.., nope int i;                                                           *|
|*                                                                            *|
\******************************************************************************/

/*############################################################################*\
|*#                              WTF THAT DOES?                              #*|
|*############################################################################*|
|*                                                                            *|
|* :::::::::::::::::::::::::::::: EXPLANATION ::::::::::::::::::::::::::::::: *|
|* THIS KEYWORD TELLS TO THE COMPILER THE FUNCTION IS MAY NOT USED IN THE     *|
|* PROGRAM.                                                                   *|
|*                                                                            *|
|* IF NOT USED, IGNORE THIS FUNCTION DIRECTLY AND THEN CONTINUE TO COMPILE    *|
|* THIS PROGRAM WITHOUT GIVING ANY WARNING.                                   *|
|*                                                                            *|
\******************************************************************************/

/* ************************* [v] VERSION CONTROL [v] ************************ */
#define LIBRARY_VERSION 202402 /* VERSION */
#ifdef UNUSED_H
#	if (UNUSED_H < LIBRARY_VERSION)
#		undef UNUSED_H /* OLD VERSION DETECTED */
#	endif /* UNUSED_H < LIBRARY_VERSION */
#endif /* UNUSED_H */
#undef LIBRARY_VERSION
/* ************************* [^] VERSION CONTROL [^] ************************ */

#ifndef UNUSED_H

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

#	define UNUSED_H 202402

/* ****************************** [v] RESET [v] ***************************** */
#	undef UNUSED
#	undef NOPE
#	undef unused
#	undef nope
/* ****************************** [^] RESET [^] ***************************** */

#	ifdef _MSC_VER
#		define UNUSED __pragma(warning(suppress:4505))
#		define NOPE __pragma(warning(suppress:4100))
#	else
#		ifdef __cplusplus
#			define UNUSED [[maybe_unused]]
#			define NOPE [[maybe_unused]]
#		else
#			if (\
				defined(__clang__) || /* IF CLANG */\
				(\
					defined(__GNUC__) && /* IF GCC */\
					(\
						(__GNUC__ >= 4) && /* IF GEQ 4.X.X */\
						(__GNUC_MINOR__ >= 2) /* IF GEQ X.2.X */\
					)\
				)\
			) /* IS GCC VERSION 4.2.X OR GREATHER (MAXIMUM C99) */
#				define UNUSED __attribute__((unused))
#				define NOPE (void)
#			else /* DJGPP || TCC || K&R */
#				define UNUSED /* EMPTY */
#				define NOPE (void)
#			endif /* __GNUC__ */
#		endif /* __cplusplus */
#	endif /* MICROSOFT C++ */

/* **************************** [v] LOWERCASE [v] *************************** */
#	define unused UNUSED
#	define nope NOPE
/* **************************** [^] LOWERCASE [^] *************************** */

#	ifdef __cplusplus /* C++ */
		}
#	endif /* __cplusplus */
#	ifdef __TI_COMPILER_VERSION__
#		pragma diag_pop /* TI CGT CCS COMPILER DIRECTIVES */
#	endif /* __TI_COMPILER_VERSION__ */
#endif /* UNUSED_H */
