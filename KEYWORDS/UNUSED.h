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
# : License - AGPL-3.0  :: Update - 2025/06/19 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

/*############################################################################*\
|*#                                 CONTENTS                                 #*|
|*############################################################################*|
|*............................................................................*|
|*  NAME  :  TYPE   :                      DESCRIPTION                        *|
|*........:.........:.........................................................*|
|* UNUSED : #define : TELLING TO THE COMPILER THE FUNCTION MAY UNUSED         *|
|* unused :         :                                                         *|
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

#ifndef UNUSED_H
#	define UNUSED_H 202506 /* VERSION */

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

#endif /* !UNUSED_H */
