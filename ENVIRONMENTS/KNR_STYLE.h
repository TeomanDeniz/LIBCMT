/******************************************************************************\
# H - KNR_STYLE                                  #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2025/03/31 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - GPL-3.0   :: Update - 2025/12/03 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

/******************************************************************************\
|*                                  CONTENTS                                  *|
|******************************************************************************|
|*............................................................................*|
|*   NAME    :   TYPE  :                     DESCRIPTION                      *|
|*...........:.........:......................................................*|
|* KNR_STYLE : #define : DEFINED IF COMPILER IS USING K&R STYLE SYNTAX.       *|
|*...........:.........:......................................................*|
|* void      : #define : DEFINED IF IN K&R.                                   *|
|*...........:.........:......................................................*|
|* const     : #define : DEFINED IF IN K&R.                                   *|
|*...........:.........:......................................................*|
|* volatile  : #define : DEFINED IF IN K&R.                                   *|
|*...........:.........:......................................................*|
|* signed    : #define : DEFINED IF IN K&R.                                   *|
|*...........:.........:......................................................*|
|* unsigned  : #define : DEFINED IF IN MICROSOFT C COMPILER VERSION 1.0/2.0   *|
|*...........:.........:......................................................*|
\******************************************************************************/

/*############################################################################*\
|*#                              WTF DOES THAT DO?                           #*|
|*############################################################################*|
|*                                                                            *|
|* :::::::::::::::::::::::::::::: EXPLANATION ::::::::::::::::::::::::::::::: *|
|*                                                                            *|
|* DEFINES A MACRO IF YOUR COMPILER IS USING K&R STYLE SYNTAX OR NOT          *|
|*                                                                            *|
\******************************************************************************/

#ifndef KNR_STYLE_H
#	define KNR_STYLE_H 202512 /* VERSION */

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

#	ifndef __cplusplus /* C++ */
#		ifdef __NOPROTO__
#			define KNR_STYLE
#		endif /* __NOPROTO__ */
#		ifndef KNR_STYLE
#			ifndef __STDC__
#				define KNR_STYLE
#			else
#				ifdef __STDC_VERSION__
#					if (__STDC_VERSION__ < 199409L) /* ... < C89 */
#						define KNR_STYLE
#					endif /* __STDC_VERSION__ < 199409L */
#				else
#					define KNR_STYLE
#				endif /* __STDC_VERSION__ */
#			endif /* !__STDC__ */
#		endif /* !KNR_STYLE */
#		ifdef KNR_STYLE
#			define void char
#			define const
#			define volatile
#			define signed
#			ifdef _MSC_VER
#				if (_MSC_VER == 800) /* VERSION 1.0 OR 2.0 */
#					define unsigned /* DOESN'T EXIST */
#				endif /* _MSC_VER == 800 */
#			endif /* _MSC_VER */
#		endif /* KNR_STYLE */
#	endif /* !__cplusplus */

/* ************************ [v] TI CGT CCS (POP) [v] ************************ */
#	ifdef __TI_COMPILER_VERSION__
#		pragma diag_pop /* TI CGT CCS COMPILER DIRECTIVES */
#	endif /* __TI_COMPILER_VERSION__ */
/* ************************ [^] TI CGT CCS (POP) [^] ************************ */

#endif /* !KNR_STYLE_H */

/* * * * * * * * * * * /!\ AUTOMATIC EOF TREATMENT! /!\ * * * * * * * * * * * *\
 * * AT THE ALL END OF FILES, I AM ADDING A SPECIAL BYTE <0X1A> TO END THE  * *
 * *                       FILE IN DOS, CP/M SYSTEMS                        * *
 * *   "//" FOR HANDLING THE BYTE IN MODERN COMPILERS AND #define IS FOR    * *
 * *       HANDLING "//" SYNTAX WHICH IS NOT SUPPORTED ON OLD SYSTEMS       * *
\* * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * */
#undef __LIBCMT__END_OF_FILE__
#define __LIBCMT__END_OF_FILE__ //
