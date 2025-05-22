/******************************************************************************\
# H - TRY_CATCH                                  #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2025/04/25 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - AGPL-3.0  :: Update - 2025/05/22 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*\
@@                                                                            @@
@@                _______   _________  ________  ____    ____                 @@
@@               |_   __ \ |  _   _  ||_   __  ||_   \  /   _|                @@
@@                 | |__) ||_/ | | \_|  | |_ \_|  |   \/   |                  @@
@@                 |  __ /     | |      |  _|     | |\  /| |                  @@
@@                _| |  \ \_  _| |_    _| |_     _| |_\/_| |_                 @@
@@               |____| |___||_____|  |_____|   |_____||_____|                @@
@@                                                                            @@
@@                          YES, YOU HEARD IT RIGHT!                          @@
@@                     READ THE FUCKING MANUAL BEFORE USE                     @@
@@                     ^    ^   ^       ^                                     @@
\*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

/*############################################################################*\
|*#                                 CONTENTS                                 #*|
|*############################################################################*|
|*............................................................................*|
|*  NAME  :   TYPE    :                     DESCRIPTION                       *|
|*........:...........:.......................................................*|
|* try    : #define   : BEGINS A BLOCK THAT MAY THROW AN ERROR                *|
|*........:...........:.......................................................*|
|* catch  : #define() : CATCHES THROWN ERRORS FROM THE `try` BLOCK            *|
|*........:...........:.......................................................*|
|* throw  : #define() : IMMEDIATELY JUMPS TO `catch` WITH A SPECIFIED ERROR   *|
|*............................................................................*|
\******************************************************************************/

/*############################################################################*\
|*#                                HOW TO USE                                #*|
|*############################################################################*|
|*                                                                            *|
|* :::::::::::::::::::::::::::::::::: TRY ::::::::::::::::::::::::::::::::::: *|
|* WRAPS A BLOCK OF CODE THAT MAY CALL "throw(...)" INSIDE IT.                *|
|*                                                                            *|
|* ::::::::::::::::::::::::::::::::: CATCH :::::::::::::::::::::::::::::::::: *|
|* PLACED RIGHT AFTER "try", CAPTURES THE ERROR CODE PASSED FROM "throw(...)" *|
|*                                                                            *|
|* ::::::::::::::::::::::::::::::::: THROW :::::::::::::::::::::::::::::::::: *|
|* THROWS AN ERROR CODE AND JUMPS TO THE NEAREST "catch" BLOCK.               *|
|*                                                                            *|
|* O - SETUP                                                                  *|
|* :                                                                          *|
|* : NOTE: SETUP PART IS OPTIONAL IF YOU'RE DEAILNG WITH main FUNCTION BY     *|
|* : YOURSELF!!!                                                              *|
|* :                                                                          *|
|* : BEFORE USING THIS LIBRARY, PLEASE SET A MACRO WITH NAME                  *|
|* : "SETUP_TRY_CATCH" AND INCLUDE THIS LIBRARY TO MAKE IT WORK!!!            *|
|* :                                                                          *|
|* : AFTER THAT, YOU DON'T NEED TO SET THAT MACRO ANYWHERE ELSE.              *|
|* :                                                                          *|
|* ;.., #define SETUP_TRY_CATCH                                               *|
|*    : #include "LIBCMT/KEYWORDS/TRY_CATCH.h"                                *|
|*    :                                                                       *|
|*    : int main() {                                                          *|
|*    : ...                                                                   *|
|*    : }                                                                     *|
|*                                                                            *|
|* O - EXAMPLES                                                               *|
|* :                                                                          *|
|* ;.., try                                                                   *|
|* :  : {                                                                     *|
|* :  :     if (1) throw(99);                                                 *|
|* :  : }                                                                     *|
|* :  : catch(int err)                                                        *|
|* :  : {                                                                     *|
|* :  :     printf("ERROR: %d\n", err);                                       *|
|* :  : }                                                                     *|
|* :                                                                          *|
|* ;.., FOR TCC (TINY C COMPILER) LIKE COMPILERS, YOU HAVE TO CREATE YOUR     *|
|* :  : "int err" VARIABLE OUTSIDE OF THE "catch()" SCOPE.                    *|
|* :  :                                                                       *|
|* :  : IT'S BECAUSE OF YOU CAN'T CREATE VARIABLES INSIDE CONTROL CLAUSES IN  *|
|* :  : TINY C COMPILER. LIKE YOU CAN'T DO SOMETHING LIKE: "for (int a;...)". *|
|* :  :                                                                       *|
|* :  : FOR EAXMPLE:                                                          *|
|* :  ;..,                                                                    *|
|* :     : int err;                                                           *|
|* :     :                                                                    *|
|* :     : try                                                                *|
|* :     : {                                                                  *|
|* :     :     if (1) throw(99);                                              *|
|* :     : }                                                                  *|
|* :     : catch(err)                                                         *|
|* :     : {                                                                  *|
|* :     :     printf("ERROR: %d\n", err);                                    *|
|* :     : }                                                                  *|
|* :                                                                          *|
|* ;.., TRY/CATCH VIA USING INSIDE A FUNCION WE CALLED:                       *|
|* :  :                                                                       *|
|* :  : void test(void)                                                       *|
|* :  : {                                                                     *|
|* :  :     throw(42);                                                        *|
|* :  : }                                                                     *|
|* :  :                                                                       *|
|* :  : try                                                                   *|
|* :  : {                                                                     *|
|* :  :     test();                                                           *|
|* :  : }                                                                     *|
|* :  : catch(int err)                                                        *|
|* :  : {                                                                     *|
|* :  :     printf("ERROR: %d\n", err);                                       *|
|* :  : }                                                                     *|
|* :                                                                          *|
|* ;.., TRY/CATCH VIA USING NESTED STATEMEMNT:                                *|
|*    :                                                                       *|
|*    : try                                                                   *|
|*    : {                                                                     *|
|*    :     try                                                               *|
|*    :     {                                                                 *|
|*    :         throw(42);                                                    *|
|*    :     }                                                                 *|
|*    :     catch (int error)                                                 *|
|*    :     {                                                                 *|
|*    :         printf("err_1: %d\n", error);                                 *|
|*    :         throw(32);                                                    *|
|*    :     }                                                                 *|
|*    : }                                                                     *|
|*    : catch (int error)                                                     *|
|*    : {                                                                     *|
|*    :     printf("err_2: %d\n", error);                                     *|
|*    : }                                                                     *|
|*                                                                            *|
\******************************************************************************/

/*############################################################################*\
|*#                              WTF THAT DOES?                              #*|
|*############################################################################*|
|*                                                                            *|
|* :::::::::::::::::::::::::::::: EXPLANATION ::::::::::::::::::::::::::::::: *|
|* THIS CUSTOM ERROR HANDLING SYSTEM USES "setjmp" AND "longjmp" TO           *|
|* MIMIC A BASIC FORM OF EXCEPTION HANDLING IN C.                             *|
|*                                                                            *|
|* - "try" SETS A JUMP POINT FOR WHERE THE PROGRAM SHOULD RETURN IF AN ERROR  *|
|*   OCCURS.                                                                  *|
|*                                                                            *|
|* - "throw(err)" STORES THE ERROR VALUE AND JUMPS BACK TO THAT POINT.        *|
|*                                                                            *|
|* - "catch(variable)" ALLOWS YOU TO ACCESS THE ERROR CODE THROWN.            *|
|*                                                                            *|
|* ::::::::::::::::::::::::::::::::: NOTES :::::::::::::::::::::::::::::::::: *|
|*     * ONLY throw() AND catch() WITH int TYPE!                              *|
|*                                                                            *|
|*     * IF THIS LIBRARY IS ATTEMPTED TO BE COMPILED IN A C++ COMPILER,       *|
|*       THE LIBRARY WILL NOT DEFINE "try", "catch", AND "throw" KEYWORDS!    *|
|*                                                                            *|
\******************************************************************************/

#ifndef TRY_CATCH_H
#	define TRY_CATCH_H 202505 /* VERSION */
#	ifndef __cplusplus /* C++ */

/* *********************** [v] TI CGT CCS (PUSH) [v] ************************ */
#		ifdef __TI_COMPILER_VERSION__
#			pragma diag_push /* TI CGT CCS COMPILER DIRECTIVES */
#			pragma CHECK_MISRA("-5.4") /*
#				TAG NAMES SHALL BE A UNIQUE IDENTIFIER
#			*/
#			pragma CHECK_MISRA("-19.3") /*
#				THE #INCLUDE DIRECTIVE SHALL BE FOLLOWED BY EITHER A <FILENAME>
#				OR "FILENAME" SEQUENCE
#			*/
#		endif /* __TI_COMPILER_VERSION__ */
/* *********************** [^] TI CGT CCS (PUSH) [^] ************************ */

/* **************************** [v] INCLUDES [v] **************************** */
#		include "LOCAL.h" /*
#		 define LOCAL
#		        */
#		include <setjmp.h> /*
#		 define jmp_buf
#		 define setjmp(jmp_buf env)
#		 define longjmp(jmp_buf env, int val)
#		        */
/* **************************** [^] INCLUDES [^] **************************** */

/* ********************** [v] CAN CHANGABLE MACRO [v] *********************** */
#		ifndef __TRY_CATCH_BUFFER_SIZE__
#			define __TRY_CATCH_BUFFER_SIZE__ 32 // <- INCREASE IT IF YOU NEED
#		endif /* !__TRY_CATCH_BUFFER_SIZE__ */
/* ********************** [^] CAN CHANGABLE MACRO [^] *********************** */

#		define try if (!setjmp(__TRY_CATCH_BUFFER__[__TRY_CATCH_INDEX__++]))
#		define catch(VARIABLE_NAME) \
			else \
				for (\
					VARIABLE_NAME = __TRY_CATCH_VALUE__; \
					__TRY_CATCH_VALUE__; \
					__TRY_CATCH_VALUE__ = 0\
				)
#		define throw(ERROR_NO) \
			__TRY_CATCH_VALUE__ = (int)ERROR_NO;\
			longjmp(__TRY_CATCH_BUFFER__[--__TRY_CATCH_INDEX__], (int)ERROR_NO)


/* ************************ [v] GLOBAL VARIABLES [v] ************************ */
#		ifdef SETUP_TRY_CATCH
LOCAL jmp_buf	__TRY_CATCH_BUFFER__[__TRY_CATCH_BUFFER_SIZE__];
LOCAL char		__TRY_CATCH_INDEX__ = 0;
LOCAL int		__TRY_CATCH_VALUE__ = 0;
#		else /* CREATE GLOBAL VARIABLES AUTOMATICALLY */
#			ifdef main
#				undef main
#			endif /* main */
#			ifdef WinMain
#				undef WinMain
#			endif /* main */
#			ifndef LOCALMACRO__VA_ARGS_GLOBAL_VARIABLES
#				define LOCALMACRO__VA_ARGS_GLOBAL_VARIABLES
#			endif /* !LOCALMACRO__VA_ARGS_GLOBAL_VARIABLES */
#			define LOCALMACRO__TRY_CATCH_GLOBAL_VARIABLES \
				LOCAL jmp_buf	__TRY_CATCH_BUFFER__[\
					__TRY_CATCH_BUFFER_SIZE__\
				];\
				LOCAL char		__TRY_CATCH_INDEX__ = 0;\
				LOCAL int		__TRY_CATCH_VALUE__ = 0;
#			define main \
				__IDLE__TRY_CATCH;\
				LOCALMACRO__TRY_CATCH_GLOBAL_VARIABLES\
				LOCALMACRO__VA_ARGS_GLOBAL_VARIABLES\
				int main
#			define WinMain \
				__IDLE__TRY_CATCH;\
				LOCALMACRO__TRY_CATCH_GLOBAL_VARIABLES\
				LOCALMACRO__VA_ARGS_GLOBAL_VARIABLES\
				int WINAPI WinMain
#		endif /* SETUP_TRY_CATCH */
LOCAL extern jmp_buf	__TRY_CATCH_BUFFER__[__TRY_CATCH_BUFFER_SIZE__];
LOCAL extern char		__TRY_CATCH_INDEX__;
LOCAL extern int		__TRY_CATCH_VALUE__;
/* ************************ [^] GLOBAL VARIABLES [^] ************************ */

/* ************************ [v] TI CGT CCS (POP) [v] ************************ */
#		ifdef __TI_COMPILER_VERSION__
#			pragma diag_pop /* TI CGT CCS COMPILER DIRECTIVES */
#		endif /* __TI_COMPILER_VERSION__ */
/* ************************ [^] TI CGT CCS (POP) [^] ************************ */

#	endif /* !__cplusplus */
#endif /* !TRY_CATCH_H */
