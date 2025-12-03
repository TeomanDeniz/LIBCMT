/******************************************************************************\
# H - STDCALL                                    #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2023/07/11 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - GPL-3.0   :: Update - 2025/12/03 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

/*############################################################################*\
|*#                                 CONTENTS                                 #*|
|*############################################################################*|
|*............................................................................*|
|*   NAME  :  TYPE   :                      DESCRIPTION                       *|
|*.........:.........:........................................................*|
|* STDCALL : #define : OPTIMISE THE FUNCTION TO OS ABI RULES                  *|
|*.........:.........:........................................................*|
\******************************************************************************/

/*############################################################################*\
|*#                                HOW TO USE                                #*|
|*############################################################################*|
|*                                                                            *|
|*  O - EXAMPLE                                                               *|
|*  :                                                                         *|
|*  : AN EAXMPLE FOR USING ON FUNCTIONS:                                      *|
|*  :                                                                         *|
|* 1| int STDCALL WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, ...)  *|
|* 2| {                                                                       *|
|* 3|     . . .                                                               *|
|* 4| }                                                                       *|
|*  :                                                                         *|
|*                                                                            *|
\******************************************************************************/

/*############################################################################*\
|*#                             WHAT DOES IT DO?                             #*|
|*############################################################################*|
|*                                                                            *|
|* DEFINES A FUNCTION CALLING CONVENTION WHERE ARGUMENTS ARE PASSED ON THE    *|
|* STACK, THE CALLEE CLEANS THE STACK, AND (ON 32-BIT SYSTEMS) THE FUNCTION   *|
|* NAME MAY BE DECORATED ACCORDINGLY.                                         *|
|*                                                                            *|
|* PRIMARILY ASSOCIATED WITH WINDOWS APIS BUT SUPPORTED BY SEVERAL COMPILERS  *|
|* FOR INTEROPERABILITY WITH EXISTING BINARY INTERFACES.                      *|
|*                                                                            *|
\******************************************************************************/

/*############################################################################*\
|*#                                SIDE NOTES                                #*|
|*############################################################################*|
|*                                                                            *|
|* YES, YOU DO NEED TO USE THE "STDCALL" KEYWORD IN YOUR FUNCTION PROTOTYPES. *|
|*                                                                            *|
|* extern STDCALL int WinMain(...);                                           *|
|*        ^^^^^^^                                                             *|
|*                                                                            *|
\******************************************************************************/

#ifndef STDCALL_H
#	define STDCALL_H 202512 /* VERSION */

/* *********************** [v] TI CGT CCS (PUSH) [v] ************************ */
#	ifdef __TI_COMPILER_VERSION__
#		pragma diag_push /* TI CGT CCS COMPILER DIRECTIVES */
#		pragma CHECK_MISRA("5.4") /*
#			TAG NAMES SHALL BE A UNIQUE IDENTIFIER
#		*/
#		pragma CHECK_MISRA("19.3") /*
#			THE #INCLUDE DIRECTIVE SHALL BE FOLLOWED BY EITHER A <FILENAME>
#			OR "FILENAME" SEQUENCE
#		*/
#	endif /* __TI_COMPILER_VERSION__ */
/* *********************** [^] TI CGT CCS (PUSH) [^] ************************ */

#	ifdef _MSC_VER
#		ifdef _M_CEE
#			define STDCALL __clrcall
#		else
#			ifdef _M_CEE_PURE
#				define STDCALL __clrcall
#			else
#				ifdef _WIN32
#					define STDCALL __stdcall
#				endif /* _WIN32 */
#			endif /* _M_CEE_PURE */
#		endif /* _M_CEE */
#	endif /* _MSC_VER */
#	ifndef STDCALL
#		ifdef __BORLANDC__
#			if (__BORLANDC__ < 0X500) /* VERSION 5.0 */
#				define STDCALL stdcall
#			else
#				define STDCALL __stdcall
#			endif /* __BORLANDC__ < 0X500 */
#		endif /* __BORLANDC__ */
#	endif /* !STDCALL */
#	ifndef STDCALL
#		ifdef __WATCOMC__
#			if (__WATCOMC__ < 1100) /* VERSION 11.0 */
#				define STDCALL stdcall
#			else
#				define STDCALL __stdcall
#			endif /* __WATCOMC__ < 1100 */
#		endif /* __WATCOMC__ */
#	endif /* !STDCALL */
#	ifndef STDCALL
#		ifdef __GNUC__
#			ifdef _WIN32
#				define STDCALL __attribute__((stdcall))
#			else
#				ifdef __CYGWIN__
#					define STDCALL __attribute__((stdcall))
#				endif /* __CYGWIN__ */
#			endif /* _WIN32 */
#		endif /* __GNUC__ */
#	endif /* !STDCALL */
#	ifndef STDCALL
#		ifdef __clang__
#			ifdef _WIN32
#				define STDCALL __attribute__((stdcall))
#			else
#				ifdef __CYGWIN__
#					define STDCALL __attribute__((stdcall))
#				endif /* __CYGWIN__ */
#			endif /* _WIN32 */
#		endif /* __clang__ */
#	endif /* !STDCALL */
#	ifndef STDCALL
#		define STDCALL
#	endif /* !STDCALL */

/* ************************ [v] TI CGT CCS (POP) [v] ************************ */
#	ifdef __TI_COMPILER_VERSION__
#		pragma diag_pop /* TI CGT CCS COMPILER DIRECTIVES */
#	endif /* __TI_COMPILER_VERSION__ */
/* ************************ [^] TI CGT CCS (POP) [^] ************************ */

#endif /* !STDCALL_H */

/* * * * * * * * * * * /!\ AUTOMATIC EOF TREATMENT! /!\ * * * * * * * * * * * *\
 * * AT THE ALL END OF FILES, I AM ADDING A SPECIAL BYTE <0X1A> TO END THE  * *
 * *                       FILE IN DOS, CP/M SYSTEMS                        * *
 * *   "//" FOR HANDLING THE BYTE IN MODERN COMPILERS AND #define IS FOR    * *
 * *       HANDLING "//" SYNTAX WHICH IS NOT SUPPORTED ON OLD SYSTEMS       * *
\* * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * */
#undef __LIBCMT__END_OF_FILE__
#define __LIBCMT__END_OF_FILE__ //
