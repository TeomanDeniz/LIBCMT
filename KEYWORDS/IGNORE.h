/******************************************************************************\
# H - IGNORE                                     #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2024/05/28 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - AGPL-3.0  :: Update - 2024/05/28 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

/*############################################################################*\
|*#                                 CONTENTS                                 #*|
|*############################################################################*|
|*............................................................................*|
|*  NAME  :  TYPE   :                      DESCRIPTION                        *|
|*........:.........:.........................................................*|
|* IGNORE : #define : TELLING TO THE COMPILER THE VARIABLE MAY NOT USED       *|
|* ignore :         :                                                         *|
|*........:.........:.........................................................*|
\******************************************************************************/

/*############################################################################*\
|*#                                HOW TO USE                                #*|
|*############################################################################*|
|*                                                                            *|
|* ::::::::::::::::::::::::::::::::: IGNORE ::::::::::::::::::::::::::::::::: *|
|* JUST PUT THIS TAG ON THE BEGINNING OF THE VARIABLE. EZ LOL                 *|
|*                                                                            *|
|* O - EXAMPLES                                                               *|
|* :                                                                          *|
|* ;.., IGNORE void *test;                                                    *|
|* :                                                                          *|
|* ;.., ignore int i;                                                         *|
|*                                                                            *|
\******************************************************************************/

/*############################################################################*\
|*#                              WTF THAT DOES?                              #*|
|*############################################################################*|
|*                                                                            *|
|* :::::::::::::::::::::::::::::: EXPLANATION ::::::::::::::::::::::::::::::: *|
|* THIS KEYWORD TELLS TO THE COMPILER THE VARABLE IS MAY NOT USED IN THE      *|
|* PROGRAM.                                                                   *|
|*                                                                            *|
|* IF NOT USED, IGNORE THIS VARIABLE DIRECTLY AND THEN CONTINUE TO COMPILE    *|
|* THE PROGRAM WITHOUT GIVING ANY WARNING.                                    *|
|*                                                                            *|
\******************************************************************************/

/* ************************* [v] VERSION CONTROL [v] ************************ */
#define LIBRARY_VERSION 202402 /* VERSION */
#ifdef IGNORE_H
#	if (IGNORE_H < LIBRARY_VERSION)
#		undef IGNORE_H /* OLD VERSION DETECTED */
#	endif /* IGNORE_H < LIBRARY_VERSION */
#endif /* IGNORE_H */
#undef LIBRARY_VERSION
/* ************************* [^] VERSION CONTROL [^] ************************ */

#ifndef IGNORE_H
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
#	define IGNORE_H 202402 /* VERSION */
/* ****************************** [v] RESET [v] ***************************** */
#	undef IGNORE
#	undef ignore
/* ****************************** [^] RESET [^] ***************************** */
#	ifdef _MSC_VER
#		define IGNORE __pragma(warning(suppress:4100))
#	else
#		ifdef __cplusplus
#			define IGNORE [[maybe_unused]]
#		else /* 100% */
#			define IGNORE (void)
#		endif /* __cplusplus */
#	endif /* MICROSOFT C++ */
/* **************************** [v] LOWERCASE [v] *************************** */
#	define ignored IGNORE
/* **************************** [^] LOWERCASE [^] *************************** */
#	ifdef __cplusplus /* C++ */
		}
#	endif /* __cplusplus */
#	ifdef __TI_COMPILER_VERSION__
#		pragma diag_pop /* TI CGT CCS COMPILER DIRECTIVES */
#	endif /* __TI_COMPILER_VERSION__ */
#endif /* IGNORE_H */
