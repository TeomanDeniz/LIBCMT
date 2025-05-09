/******************************************************************************\
# H - NORETURN                                   #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2023/07/07 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - AGPL-3.0  :: Update - 2025/04/25 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

/*############################################################################*\
|*#                                 CONTENTS                                 #*|
|*############################################################################*|
|*............................................................................*|
|*   NAME   :  TYPE   :                     DESCRIPTION                       *|
|*..........:.........:.......................................................*|
|* NORETURN : #define : TELLING TO THE COMPILER THE PROGRAM WILL BE END IN    *|
|* noreturn :         : THIS FUNCTION.                                        *|
|*..........:.........:.......................................................*|
\******************************************************************************/

/*############################################################################*\
|*#                                HOW TO USE                                #*|
|*############################################################################*|
|*                                                                            *|
|* :::::::::::::::::::::::::::::::: NORETURN :::::::::::::::::::::::::::::::: *|
|* JUST PUT THIS TAG ON THE BEGINNING OF THE FUNCTION. EZ LOL                 *|
|*                                                                            *|
|* ::::::::::::::::::::::::::::::: SHOW TIME :::::::::::::::::::::::::::::::: *|
|* O - EXAMPLES                                                               *|
|* :                                                                          *|
|* ;.., NORETURN void function(void)                                          *|
|* :  : {                                                                     *|
|* :  :     . . .                                                             *|
|* :  : }                                                                     *|
|* :                                                                          *|
|* ;.., noreturn void function(void)                                          *|
|*    : {                                                                     *|
|*    :     . . .                                                             *|
|*    : }                                                                     *|
|*                                                                            *|
\******************************************************************************/

/*############################################################################*\
|*#                              WTF THAT DOES?                              #*|
|*############################################################################*|
|*                                                                            *|
|* :::::::::::::::::::::::::::::: EXPLANATION ::::::::::::::::::::::::::::::: *|
|* IT WARNS THE COMPILER THAT THE FUNCTION WITH "NORETURN" KEYWORD WILL BE    *|
|* EXIT FROM THE PROGRAM WITHOUT REACHING THE "return" FROM main() FUNCTION.  *|
|*                                                                            *|
|* WHICH MEANS FOR SOME OPTIMISATION PURPOSES.                                *|
|*                                                                            *|
\******************************************************************************/

#ifndef NORETURN_H
#	define NORETURN_H 202504 /* VERSION */

/* *********************** [v] TI CGT CCS (PUSH) [v] ************************ */
#	ifdef __TI_COMPILER_VERSION__
#		pragma diag_push /* TI CGT CCS COMPILER DIRECTIVES */
#		pragma CHECK_MISRA("-5.4") /* TAG NAMES SHALL BE A UNIQUE IDENTIFIER */
#		pragma CHECK_MISRA("-19.3") /*
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

#	ifndef __STDNORETURN_H
#		define __STDNORETURN_H /* <stdnoreturn.h> */
#	endif /* __STDNORETURN_H */

#	if (\
		defined(__clang__) && /* IF CLANG */\
		(\
			(__clang_major__ >= 3) && /* IF GEQ 3.X */\
			(__clang_minor__ >= 3) /* IF GEQ X.3 */\
		)\
	) /* IS CLANG VERSION 3.3 OR GREATHER (MAXIMUM C99) */
#		define STD_NORETURN _Noreturn
#		define __noreturn_is_defined 1
#		define __NORETURN_IS_DEFINED 1
#	else
#		if (\
			defined(__clang__) || /* IF CLANG */\
			(\
				defined(__GNUC__) && /* IF GCC */\
				(\
					(__GNUC__ >= 4) && /* IF GEQ 4.X.X */\
					(__GNUC_MINOR__ >= 2) /* IF GEQ X.2.X */\
				)\
			)\
		) /* IS GCC VERSION 4.2.X OR GREATHER (MAXIMUM C99) */
#			define STD_NORETURN __attribute__((noreturn))
#			define _Noreturn __attribute__((noreturn))
#			define __noreturn_is_defined 1
#			define __NORETURN_IS_DEFINED 1
#		else /* DJGPP || TCC || K&R || ... */
#			define STD_NORETURN /* EMPTY */
#			define _Noreturn /* EMPTY */
#			define __noreturn_is_defined 0
#			define __NORETURN_IS_DEFINED 0
#		endif /* __clang__ || __GNUC__ 4.2.X */
#	endif /* __clang__ 3.3 */

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

#endif /* NORETURN_H */
