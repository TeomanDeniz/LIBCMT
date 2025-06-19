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
# : License - AGPL-3.0  :: Update - 2025/06/19 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

/*############################################################################*\
|*#                                 CONTENTS                                 #*|
|*############################################################################*|
|*............................................................................*|
|*    NAME    :  TYPE   :                      DESCRIPTION                    *|
|*............:.........:.....................................................*|
|* IGNORE_VAR : #define : TELLING TO THE COMPILER THE VARIABLE MAY NOT USED   *|
|* ignore_var :         :                                                     *|
|*............:.........:.....................................................*|
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
|* ;.., IGNORE_VAR void *test;                                                *|
|* :                                                                          *|
|* ;.., ignore_var int i;                                                     *|
|* :                                                                          *|
|* ;.., int main(int argc, char **argv)                                       *|
|*    : {                                                                     *|
|*    :     ignore_var argc;                                                  *|
|*    :                                                                       *|
|*    :     . . .                                                             *|
|*    :                                                                       *|
|*    : }                                                                     *|
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

#ifndef IGNORE_VAR_H
#	define IGNORE_VAR_H 202506 /* VERSION */

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
