/******************************************************************************\
# H - IGNORE_VAR                                 #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2024/05/28 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - GPL-3.0   :: Update - 2025/12/03 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

/*############################################################################*\
|*#                                 CONTENTS                                 #*|
|*############################################################################*|
|*............................................................................*|
|*    NAME    :  TYPE   :                      DESCRIPTION                    *|
|*............:.........:.....................................................*|
|* IGNORE_VAR : #define : TELLS THE COMPILER THE VARIABLE MAY NOT BE USED    *|
|* ignore_var :         :                                                     *|
|*............:.........:.....................................................*|
\******************************************************************************/

/*############################################################################*\
|*#                                HOW TO USE                                #*|
|*############################################################################*|
|*                                                                            *|
|* ::::::::::::::::::::::::::::::::: IGNORE ::::::::::::::::::::::::::::::::: *|
|*                                                                            *|
|* TO USE, SIMPLY ADD THE TAG IN FRONT OF THE VARIABLE.                       *|
|*                                                                            *|
|* O - EXAMPLES                                                               *|
|* :                                                                          *|
|* ;.., IGNORE_VAR void *test;                                                *|
|* :                                                                          *|
|* ;.., ignore_var int i;                                                     *|
|* :                                                                          *|
|* ;.., FULL EXAMPLE:                                                         *|
|*    :                                                                       *|
|*   1| int main(int argc, char **argv)                                       *|
|*   2| {                                                                     *|
|*   3|     ignore_var argc;                                                  *|
|*   4|                                                                       *|
|*   5|     . . .                                                             *|
|*   6|                                                                       *|
|*   7| }                                                                     *|
|*    :                                                                       *|
|*                                                                            *|
\******************************************************************************/

/*############################################################################*\
|*#                              WHAT DOES IT DO?                            #*|
|*############################################################################*|
|*                                                                            *|
|* ::::::::::::::::::::::::::::::: EXPLANATION :::::::::::::::::::::::::::::: *|
|*                                                                            *|
|* THIS KEYWORD TELLS THE COMPILER THAT THE VARIABLE MAY NOT BE USED IN THE   *|
|* PROGRAM.                                                                   *|
|*                                                                            *|
|* IF UNUSED, THE COMPILER IGNORES THIS VARIABLE AND CONTINUES COMPILING      *|
|* THE PROGRAM WITHOUT GENERATING ANY WARNINGS.                               *|
|*                                                                            *|
\******************************************************************************/

#ifndef IGNORE_VAR_H
#	define IGNORE_VAR_H 202512 /* VERSION */

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

#	ifdef _MSC_VER /* MICROSOFT C++ */
#		define IGNORE_VAR __pragma(warning(suppress:4100))
#	else
#		ifdef __cplusplus /* C++ */
#			define IGNORE_VAR [[maybe_unused]]
#		else /* 100% */
#			define IGNORE_VAR (void)
#		endif /* __cplusplus */
#	endif /*_MSC_VER */

/* **************************** [v] LOWERCASE [v] *************************** */
#	define ignore_var IGNORE_VAR
/* **************************** [^] LOWERCASE [^] *************************** */

/* ************************ [v] TI CGT CCS (POP) [v] ************************ */
#	ifdef __TI_COMPILER_VERSION__
#		pragma diag_pop /* TI CGT CCS COMPILER DIRECTIVES */
#	endif /* __TI_COMPILER_VERSION__ */
/* ************************ [^] TI CGT CCS (POP) [^] ************************ */

#endif /* !IGNORE_VAR_H */

/* * * * * * * * * * * /!\ AUTOMATIC EOF TREATMENT! /!\ * * * * * * * * * * * *\
 * * AT THE ALL END OF FILES, I AM ADDING A SPECIAL BYTE <0X1A> TO END THE  * *
 * *                       FILE IN DOS, CP/M SYSTEMS                        * *
 * *   "//" FOR HANDLING THE BYTE IN MODERN COMPILERS AND #define IS FOR    * *
 * *       HANDLING "//" SYNTAX WHICH IS NOT SUPPORTED ON OLD SYSTEMS       * *
\* * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * */
#undef __LIBCMT__END_OF_FILE__
#define __LIBCMT__END_OF_FILE__ //
