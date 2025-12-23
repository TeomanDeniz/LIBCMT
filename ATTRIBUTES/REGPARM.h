/******************************************************************************\
# H - REGPARM                                    #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2023/07/11 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - GPL-3.0   :: Update - 2025/12/23 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

/*############################################################################*\
|*#                                 CONTENTS                                 #*|
|*############################################################################*|
|*............................................................................*|
|*   NAME  :    TYPE    :                    DESCRIPTION                      *|
|*.........:............:.....................................................*|
|* REGPARM : #define () : WITH THIS FEATURE, YOU ARE ABLE TO SEND             *|
|* regparm :            : VARIABLES TO FUNCTION BY USING PURE REGISTERS       *|
|*         :            : INSTEAD OF USING MEMORY.                            *|
|*.........:............:.....................................................*|
\******************************************************************************/

/*############################################################################*\
|*#                                HOW TO USE                                #*|
|*############################################################################*|
|*                                                                            *|
|* ::::::::::::::::::::::::::::::: IMPORTANT :::::::::::::::::::::::::::::::: *|
|*                                                                            *|
|* FOR MORE EFFECTIVE OPTIMISATION, USE "register" KEYWORD ON YOUR ARGUMENTS. *|
|*                                                                            *|
|* YOU MUST ENTER THE NUMBER OF VARIABLES THAT PASS TO FUNCTION WITH          *|
|* REGISTERS IN THE INPUT ARGUMENT. "REGPARM(NUMBER OF REGISTERS)"            *|
|*                                                                            *|
|* ::::::::::::::::::::::::::::::: HOW TO USE ::::::::::::::::::::::::::::::: *|
|*                                                                            *|
|* O - EXAMPLES                                                               *|
|* :                                                                          *|
|* ;..,                                                                       *|
|* :  :                                                                       *|
|* : 1| void REGPARM(1) function(int b)	{                                     *|
|* : 2|     . . .                                                             *|
|* : 3| }                                                                     *|
|* :  :                                                                       *|
|* :                                                                          *|
|* ;..,                                                                       *|
|* :  :                                                                       *|
|* : 1| void REGPARM(2) function(int a, int b)                                *|
|* : 2| {                                                                     *|
|* : 3|     . . .                                                             *|
|* : 4| }                                                                     *|
|* :  :                                                                       *|
|* :                                                                          *|
|* ;..,                                                                       *|
|* :  :                                                                       *|
|* : 1| void regparm(4) function(int a, float b, long c, char *d)             *|
|* : 2| {                                                                     *|
|* : 3|     . . .                                                             *|
|* : 4| }                                                                     *|
|* :  :                                                                       *|
|* :                                                                          *|
|* ;.., FOR THE MOST EFFECTIVE:                                               *|
|*    :                                                                       *|
|*   1| void regparm(2) function(                                             *|
|*   2|     register int a,                                                   *|
|*   3|     register float b,                                                 *|
|*   4|     register char *c                                                  *|
|*   5| )                                                                     *|
|*   6| {                                                                     *|
|*   7|     . . .                                                             *|
|*   8| }                                                                     *|
|*    :                                                                       *|
|*                                                                            *|
\******************************************************************************/

/*############################################################################*\
|*#                               WHAT IT DOES                               #*|
|*############################################################################*|
|*                                                                            *|
|* :::::::::::::::::::::::::::::: EXPLANATION ::::::::::::::::::::::::::::::: *|
|*                                                                            *|
|* USING THIS KEYWORD IN YOUR FUNCTION LETS YOU HOLD A VALUE DIRECTLY IN A    *|
|* CPU REGISTER, ALLOWING DIRECT ACCESS - SIMILAR TO C++ REFERENCES, BUT      *|
|* WITHOUT USING POINTERS.                                                    *|
|*                                                                            *|
|* THIS MEANS WHEN THE PROGRAM REACHES THIS FUNCTION, THE CPU WILL USE THE    *|
|* EXISTING VALUE IN A REGISTER INSTEAD OF FETCHING IT FROM MEMORY (RAM) OR   *|
|* PUSHING/POPPING VALUES TO/FROM THE STACK.                                  *|
|*                                                                            *|
|* IN OTHER WORDS, IT AVOIDS EXTRA INSTRUCTIONS DURING FUNCTION CALLS TO GET  *|
|* THE VALUE.                                                                 *|
|*                                                                            *|
|* :::::::::::::::::::::::::::::::::: NOTE :::::::::::::::::::::::::::::::::: *|
|*                                                                            *|
|*  O - YOU MUST ALSO USE REGPARM IN THE FUNCTION'S PROTOTYPE, IF PRESENT!    *|
|*  :                                                                         *|
|* 1| void REGPARM(2) FUNCT(int A, int B) { ... } <-- FUNCTION DEFINITION     *|
|* 2| extern void REGPARM(2) FUNCT(int A, int B); <-- FUNCTION PROTOTYPE      *|
|*  :                                                                         *|
|*                                                                            *|
\******************************************************************************/

#ifndef REGPARM_H
#	define REGPARM_H 202512 /* VERSION */

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
#		define REGPARM(__REGPARM_NUMBER_OF_VARIABLES__) \
			__attribute__((fastcall))
#	else
#		ifdef __cplusplus /* C++ */
#			define REGPARM(__REGPARM_NUMBER_OF_VARIABLES__) \
				__attribute__((fastcall))
#		else
#			if (\
				defined(__GNUC__) && /* IF GCC */\
				(\
					(__GNUC__ >= 2) && /* IF GRE 2.X.X */\
					(__GNUC_MINOR__ >= 7) && /* IF GEQ X.7.X */\
					(__GNUC_PATCHLEVEL__ >= 1) /* IF GEQ X.X.1 */\
				)\
			) /* IS GCC VERSION 2.7.1 OR GREATHER (MAXIMUM C90) */
#				ifdef __clang__
#					define REGPARM(__REGPARM_NUMBER_OF_VARIABLES__) \
						__attribute__((\
						regparm(__REGPARM_NUMBER_OF_VARIABLES__)))
#				else
#					ifdef __DJGPP__ /* MS-DOS */
#						define REGPARM(__REGPARM_NUMBER_OF_VARIABLES__)
#					else
#						define REGPARM(__REGPARM_NUMBER_OF_VARIABLES__)\
							__attribute__((\
							regparm(__REGPARM_NUMBER_OF_VARIABLES__)))
#					endif /* __DJGPP__ */
#				endif /* __clang__ */
#			else
#				define REGPARM(__REGPARM_NUMBER_OF_VARIABLES__)
#			endif /* __GNUC__ 2.7.1 */
#		endif /* __cplusplus */
#	endif /* _MSC_VER */

#	define regparm REGPARM

/* ************************ [v] TI CGT CCS (POP) [v] ************************ */
#	ifdef __TI_COMPILER_VERSION__
#		pragma diag_pop /* TI CGT CCS COMPILER DIRECTIVES */
#	endif /* __TI_COMPILER_VERSION__ */
/* ************************ [^] TI CGT CCS (POP) [^] ************************ */

#endif /* !REGPARM_H */

/* * * * * * * * * * * /!\ AUTOMATIC EOF TREATMENT! /!\ * * * * * * * * * * * *\
 * * AT THE ALL END OF FILES, I AM ADDING A SPECIAL BYTE <0X1A> TO END THE  * *
 * *                       FILE IN DOS, CP/M SYSTEMS                        * *
 * *   "//" FOR HANDLING THE BYTE IN MODERN COMPILERS AND #define IS FOR    * *
 * *       HANDLING "//" SYNTAX WHICH IS NOT SUPPORTED ON OLD SYSTEMS       * *
\* * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * */
#undef __CMT__END_OF_FILE__
#define __CMT__END_OF_FILE__ //
