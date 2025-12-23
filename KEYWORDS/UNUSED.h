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
# : License - GPL-3.0   :: Update - 2025/12/23 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

/*############################################################################*\
|*#                                 CONTENTS                                 #*|
|*############################################################################*|
|*............................................................................*|
|*  NAME  :  TYPE   :                      DESCRIPTION                        *|
|*........:.........:.........................................................*|
|* UNUSED : #define : TELLS THE COMPILER THAT THE FUNCTION MAY NOT BE USED    *|
|* unused :         :                                                         *|
|*........:.........:.........................................................*|
\******************************************************************************/

/*############################################################################*\
|*#                                HOW TO USE                                #*|
|*############################################################################*|
|*                                                                            *|
|* ::::::::::::::::::::::::::::::::: UNUSED ::::::::::::::::::::::::::::::::: *|
|*                                                                            *|
|* JUST PUT THIS TAG AT THE BEGINNING OF THE FUNCTION.                        *|
|*                                                                            *|
|* O - EXAMPLES                                                               *|
|* :                                                                          *|
|* ;..,                                                                       *|
|* :  :                                                                       *|
|* : 1| unused void function(void)                                            *|
|* : 2| {                                                                     *|
|* : 3|     . . .                                                             *|
|* : 4| }                                                                     *|
|* :  :                                                                       *|
|* :                                                                          *|
|* ;..,                                                                       *|
|*    :                                                                       *|
|*   1| UNUSED void function(void)                                            *|
|*   2| {                                                                     *|
|*   3|     . . .                                                             *|
|*   4| }                                                                     *|
|*    :                                                                       *|
|*                                                                            *|
\******************************************************************************/

/*############################################################################*\
|*#                              WTF THAT DOES?                              #*|
|*############################################################################*|
|*                                                                            *|
|* :::::::::::::::::::::::::::::: EXPLANATION ::::::::::::::::::::::::::::::: *|
|*                                                                            *|
|* THIS KEYWORD TELLS THE COMPILER THAT THE FUNCTION MAY NOT BE USED IN THE   *|
|* PROGRAM.                                                                   *|
|*                                                                            *|
|* IF UNUSED, THE COMPILER IGNORES THIS FUNCTION AND CONTINUES COMPILING      *|
|* THE PROGRAM WITHOUT GIVING ANY WARNINGS.                                   *|
|*                                                                            *|
\******************************************************************************/

#ifndef UNUSED_H
#	define UNUSED_H 202512 /* VERSION */

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
#		define UNUSED __pragma(warning(suppress:4505))
#	else
#		ifdef __cplusplus
#			define UNUSED [[maybe_unused]]
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
#			else /* DJGPP || TCC || K&R */
#				define UNUSED /* EMPTY */
#			endif /* __clang__ || __GNUC__ 4.2.X */
#		endif /* __cplusplus */
#	endif /* _MSC_VER */

/* **************************** [v] LOWERCASE [v] *************************** */
#	define unused UNUSED
/* **************************** [^] LOWERCASE [^] *************************** */

/* ************************ [v] TI CGT CCS (POP) [v] ************************ */
#	ifdef __TI_COMPILER_VERSION__
#		pragma diag_pop /* TI CGT CCS COMPILER DIRECTIVES */
#	endif /* __TI_COMPILER_VERSION__ */
/* ************************ [^] TI CGT CCS (POP) [^] ************************ */

#endif /* !UNUSED_H */

/* * * * * * * * * * * /!\ AUTOMATIC EOF TREATMENT! /!\ * * * * * * * * * * * *\
 * * AT THE ALL END OF FILES, I AM ADDING A SPECIAL BYTE <0X1A> TO END THE  * *
 * *                       FILE IN DOS, CP/M SYSTEMS                        * *
 * *   "//" FOR HANDLING THE BYTE IN MODERN COMPILERS AND #define IS FOR    * *
 * *       HANDLING "//" SYNTAX WHICH IS NOT SUPPORTED ON OLD SYSTEMS       * *
\* * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * */
#undef __CMT__END_OF_FILE__
#define __CMT__END_OF_FILE__ //
