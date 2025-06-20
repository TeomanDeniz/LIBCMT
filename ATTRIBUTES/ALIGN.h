/******************************************************************************\
# H - ALIGN                                      #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2023/07/12 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - AGPL-3.0  :: Update - 2025/06/19 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

/*############################################################################*\
|*#                                 CONTENTS                                 #*|
|*############################################################################*|
|*............................................................................*|
|*   NAME    :    TYPE    :                   DESCRIPTION                     *|
|*...........:............:...................................................*|
|* ALIGN     : #define () : ???                                               *|
|* align     :            :                                                   *|
|*...........:............:...................................................*|
|* MAX_ALIGN : #define    : RETURNS THE MAX SET VALUE OF ALIGNMENT.           *|
|*...........:............:...................................................*|
\******************************************************************************/

/*############################################################################*\
|*#                                HOW TO USE                                #*|
|*############################################################################*|
|*                                                                            *|
|* ::::::::::::::::::::::::::::::: MAX_ALIGN :::::::::::::::::::::::::::::::: *|
|* IT RETURNS A VALUE OF THE MAX ALING NUMBER YOUR COMPILER CAN ACCEPT.       *|
|*                                                                            *|
|* :::::::::::::::::::::: "ALIGN(ALIGN_VALUE, OBJECT)" :::::::::::::::::::::: *|
|* O - EXAMPLE 1 (VARIABLES)                                                  *|
|* :                                                                          *|
|* ;.., ALIGN(16, int var);                                                   *|
|* :  : align(16, int var) = 42;                                              *|
|* :                                                                          *|
|* ;... AN EXAMPLE OF CREATING AN INTEGER AND SETTING VARIABLE'S ALIGN AS 16. *|
|*                                                                            *|
|* O - EXAMPLE 2 (STRUCTS)                                                    *|
|* :                                                                          *|
|* ;.., ALIGN(MAX_ALIGN, struct s_struct                                      *|
|* :  : {                                                                     *|
|* :  :     . . .                                                             *|
|* :  : });                                                                   *|
|* :                                                                          *|
|* ;.., AN EXAMPLE OF CREATING A STRUCT AND SETTING STRUCT'S ALIGN AS MAX     *|
|*    : BAYT ARCHITECTURE CAN HANDLE.                                         *|
|*    :                                                                       *|
|*    : PRO-TIP: DON'T FORGET TO FINISH THE STRUCT WITH ')'                   *|
|*    : BETWEEN '}' AND ';'.                                                  *|
|*                                                                            *|
|* O - EXAMPLE 3 (FUNCTIONS)                                                  *|
|* :                                                                          *|
|* ;.., YES. ALIGNING FUNCTIONS. WTF                                          *|
|*    : align(16, void) function(void)                                        *|
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
|* IDK                                                                        *|
|*                                                                            *|
\******************************************************************************/

#ifndef ALIGN_H
#	define ALIGN_H 202506 /* VERSION */

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

/* **************************** [v] INCLUDES [v] **************************** */
#	include	"../ENVIRONMENTS/CACHE.h" /*
#	 define L1_CACHE_BYTES
#	        */
/* **************************** [^] INCLUDES [^] **************************** */

#	define MAX_ALIGN L1_CACHE_BYTES

#	ifdef _MSC_VER /* MICROSOFT C++ */
#		define ALIGN(__ALIGN_VARIABLE__, ...) \
			__declspec(align(__ALIGN_VARIABLE__)) __VA_ARGS__
#	else
#		if (\
			defined(__GNUC__) && /* IF GCC */\
			(\
				(__GNUC__ >= 2) && /* IF GRE 2.X.X */\
				(__GNUC_MINOR__ >= 7) && /* IF GEQ X.7.X */\
				(__GNUC_PATCHLEVEL__ >= 1) /* IF GEQ X.X.1 */\
			)\
		) /* IS GCC VERSION 2.7.1 OR GREATHER (MAXIMUM C90) */
#			define ALIGN(__ALIGN_VARIABLE__, ...) \
				__VA_ARGS__ __attribute__((aligned(__ALIGN_VARIABLE__)))
#		else
#			define ALIGN(__ALIGN_VARIABLE__, ...) __VA_ARGS__
#		endif /* __GNUC__ 2.7.1 */
#	endif /* _MSC_VER */

#	define align ALIGN

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

#endif /* !ALIGN_H */
