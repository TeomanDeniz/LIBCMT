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
# : License - AGPL-3.0  :: Update - 2025/07/19 : #    ::::!!!1!!1!!!1!!!::     #
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
|* O - EXAMPLES                                                               *|
|* :                                                                          *|
|* ;.., void REGPARM(1) function(int b)	{                                     *|
|* :  :     . . .                                                             *|
|* :  : }                                                                     *|
|* :                                                                          *|
|* ;.., void REGPARM(2) function(int a, int b)                                *|
|* :  : {                                                                     *|
|* :  :     . . .                                                             *|
|* :  : }                                                                     *|
|* :                                                                          *|
|* ;.., void regparm(4) function(int a, float b, long c, char *d)             *|
|* :  : {                                                                     *|
|* :  :     . . .                                                             *|
|* :  : }                                                                     *|
|* :                                                                          *|
|* ;.., FOR THE MOST EFFECTIVE:                                               *|
|*    : void regparm(2) function(                                             *|
|*    :     register int a,                                                   *|
|*    :     register float b,                                                 *|
|*    :     register char *c                                                  *|
|*    : )                                                                     *|
|*    : {                                                                     *|
|*    :     . . .                                                             *|
|*    : }                                                                     *|
|*                                                                            *|
\******************************************************************************/

/*############################################################################*\
|*#                               WHAT IT DOES                               #*|
|*############################################################################*|
|*                                                                            *|
|* :::::::::::::::::::::::::::::: EXPLANATION ::::::::::::::::::::::::::::::: *|
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
|* O - YOU MUST ALSO USE REGPARM IN THE FUNCTION'S PROTOTYPE, IF PRESENT!     *|
|* :                                                                          *|
|* ;.., void REGPARM(2) FUNCT(int A, int B) { ... } <-- FUNCTION DEFINITION   *|
|*    : extern void REGPARM(2) FUNCT(int A, int B); <-- FUNCTION PROTOTYPE    *|
|*                                                                            *|
\******************************************************************************/

#ifndef REGPARM_H
#	define REGPARM_H 202507 /* VERSION */

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

#endif /* !REGPARM_H */
