/******************************************************************************\
# H - LOCAL                                      #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2025/05/14 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - AGPL-3.0  :: Update - 2025/05/14 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

/*############################################################################*\
|*#                                 CONTENTS                                 #*|
|*############################################################################*|
|*............................................................................*|
|*  NAME  :   TYPE   :                       DESCRIPTION                      *|
|*........:..........:........................................................*|
|* LOCAL  : #define  : MAKE VARIABLE THREAD-LOCAL (SEPARATE PER THREAD)       *|
|* local  :          :                                                        *|
|*........:..........:........................................................*|
\******************************************************************************/

/*############################################################################*\
|*#                                HOW TO USE                                #*|
|*############################################################################*|
|*                                                                            *|
|* O - EXAMPLE                                                                *|
|* :                                                                          *|
|* ;..O - FOR GLOBAL VARIABLES:                                               *|
|* :  :                                                                       *|
|* :  : local int g_variable = 0;                                             *|
|* :                                                                          *|
|* ;..O - FOR STATIC VARIABLES:                                               *|
|*    :                                                                       *|
|*    : void test(void)                                                       *|
|*    : {                                                                     *|
|*    :     static local int variable = 0;                                    *|
|*    : }                                                                     *|
|*                                                                            *|
\******************************************************************************/

/*############################################################################*\
|*#                              WTF THAT DOES?                              #*|
|*############################################################################*|
|*                                                                            *|
|* THIS KEYWORD MUST BE ONLY USED AT GLOBAL AND STATIC VARIABLES WHEN NEEDED! *|
|*                                                                            *|
|* MARKS A GLOBAL OR STATIC VARIABLE AS THREAD-LOCAL, MEANING EACH THREAD     *|
|* GETS ITS OWN SEPARATE INSTANCE OF THE VARIABLE.                            *|
|*                                                                            *|
|* THIS ENSURES THAT THE VARIABLE IS NOT SHARED BETWEEN THREADS, PREVENTING   *|
|* RACE CONDITIONS OR UNINTENDED DATA SHARING.                                *|
|*                                                                            *|
\******************************************************************************/

/*############################################################################*\
|*#                                SIDE NOTES                                #*|
|*############################################################################*|
|*                                                                            *|
|* YOU DON'T HAVE TO SET "LOCAL" KEYWORD ON PROTYPES OF GLOBAL VARIABLES.     *|
|*                                                                            *|
|* extern local int g_variable;                                               *|
|*        ^^^^^                                                               *|
|*        NO, DON'T DO THAT ON PROTOTYPES!!!                                  *|
|*        USE IT ONLY WHILE YOU'RE CREATING YOUR GLOBAL VARIABLE!             *|
|*                                                                            *|
\******************************************************************************/

#ifndef LOCAL_H
#	define LOCAL_H 202505 /* VERSION */

/* *********************** [v] TI CGT CCS (PUSH) [v] ************************ *\
|* *   IT'S WORTH NOTING THAT TI COMPILERS MAY HAVE UNIQUE BEHAVIORS WHEN   * *|
|* *                      DEALING WITH MULTI THREADING                      * *|
\* ************************************************************************** */
#	ifdef __TI_COMPILER_VERSION__
#		pragma diag_push /* TI CGT CCS COMPILER DIRECTIVES */
#		pragma CHECK_MISRA("-5.4") /* TAG NAMES SHALL BE A UNIQUE IDENTIFIER */
#		pragma CHECK_MISRA("-19.3") /*
#			THE #INCLUDE DIRECTIVE SHALL BE FOLLOWED BY EITHER A <FILENAME>
#			OR "FILENAME" SEQUENCE
#		*/
#	endif /* __TI_COMPILER_VERSION__ */
/* *********************** [^] TI CGT CCS (PUSH) [^] ************************ */

#	ifdef _MSC_VER
#		define LOCAL __declspec(thread)
#	else
#		ifdef __cplusplus
#			if (__cplusplus >= 201103L) /* AKA: C++ 11+ */
#				define LOCAL thread_local
#			else
#				ifdef __GNUC__
#					define LOCAL __thread
#				else
#					ifdef __clang__
#						define LOCAL __thread
#					else
#						define LOCAL /* DANG IT */
#					endif /* __clang__ */
#				endif /* __GNUC__ */
#			endif /* C++ >= 11 */
#		else /* C LANGUAGE */
#			ifdef __STDC_VERSION__
#				if (__STDC_VERSION__ >= 201112L) /* AKA: C 11+ */
#					define LOCAL _Thread_local
#				else
#					ifdef __GNUC__
#						define LOCAL __thread
#					else
#						ifdef __clang__
#							define LOCAL __thread
#						else
#							define LOCAL /* DANG IT */
#						endif /* __clang__ */
#					endif /* __GNUC__ */
#				endif /* STDC >= 11 */
#			else
#				ifdef __GNUC__
#					define LOCAL __thread
#				else
#					ifdef __clang__
#						define LOCAL __thread
#					else
#						define LOCAL /* DANG IT */
#					endif /* __clang__ */
#				endif /* __GNUC__ */
#			endif /* __STDC_VERSION__ */
#		endif /* __cplusplus */
#	endif /* _MSC_VER */

/* **************************** [v] LOWERCASE [v] *************************** */
#	define local LOCAL
/* **************************** [^] LOWERCASE [^] *************************** */

/* ************************ [v] TI CGT CCS (POP) [v] ************************ */
#		ifdef __TI_COMPILER_VERSION__
#			pragma diag_pop /* TI CGT CCS COMPILER DIRECTIVES */
#		endif /* __TI_COMPILER_VERSION__ */
/* ************************ [^] TI CGT CCS (POP) [^] ************************ */

#endif /* !LOCAL_H */
