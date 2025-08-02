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
# : License - AGPL-3.0  :: Update - 2025/08/02 : #    ::::!!!1!!1!!!1!!!::     #
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
|* TRY    : #define   : BEGINS A BLOCK THAT MAY THROW AN ERROR                *|
|* try    :           :                                                       *|
|*........:...........:.......................................................*|
|* CATCH  : #define() : CATCHES THROWN ERRORS FROM THE "try" BLOCK            *|
|* catch  :           :                                                       *|
|*........:...........:.......................................................*|
|* THROW  : #define() : IMMEDIATELY JUMPS TO "catch" WITH A SPECIFIED ERROR   *|
|* throw  :           :                                                       *|
|*........:...........:.......................................................*|
\******************************************************************************/

/*############################################################################*\
|*#                                HOW TO USE                                #*|
|*############################################################################*|
|*                                                                            *|
|* :::::::::::::::::::::::::::::::::: TRY ::::::::::::::::::::::::::::::::::: *|
|* WRAPS A BLOCK OF CODE THAT MAY CALL "throw(...)" WITHIN IT.                *|
|*                                                                            *|
|* ::::::::::::::::::::::::::::::::: CATCH :::::::::::::::::::::::::::::::::: *|
|* PLACED RIGHT AFTER "try", CAPTURES THE ERROR CODE PASSED FROM "throw(...)" *|
|*                                                                            *|
|* ::::::::::::::::::::::::::::::::: THROW :::::::::::::::::::::::::::::::::: *|
|* THROWS AN ERROR CODE AND JUMPS TO THE NEAREST "catch" BLOCK.               *|
|*                                                                            *|
|* O - SETUP                                                                  *|
|* :                                                                          *|
|* : NOTE: SETUP IS OPTIONAL IF YOU’RE HANDLING THE main FUNCTION YOURSELF    *|
|* : WITH LIKE "#define main ..." OR "#define main(...) ..."                  *|
|* :                                                                          *|
|* : BEFORE USING THIS LIBRARY, YOU MUST DEFINE THE MACRO "SETUP_TRY_CATCH"   *|
|* : ONCE, IN ONE C FILE (TYPICALLY YOUR "main.c" OR ENTRY POINT).            *|
|* :                                                                          *|
|* : THIS ENSURES GLOBAL VARIABLES USED INTERNALLY ARE PROPERLY DEFINED.      *|
|* :                                                                          *|
|* : AFTER THAT, YOU CAN INCLUDE THIS HEADER ANYWHERE ELSE WITHOUT DEFINING   *|
|* : THE MACRO AGAIN. ALL OTHER FILES WILL ONLY SEE "extern" DECLARATIONS.    *|
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
|* ;.., FOR COMPILERS LIKE TCC (TINY C COMPILER), YOU MUST DECLARE YOUR       *|
|* :  : "int err" VARIABLE OUTSIDE OF THE "catch()" SCOPE.                    *|
|* :  :                                                                       *|
|* :  : THIS IS BECAUSE TINY C COMPILER DOES NOT ALLOW VARIABLE DECLARATIONS  *|
|* :  : INSIDE CONTROL CLAUSES. FOR EXAMPLE, YOU CAN’T DO SOMETHING LIKE:     *|
|* :  : "for (int a;...)"                                                     *|
|* :  :                                                                       *|
|* :  : FOR EXAMPLE:                                                          *|
|* :  ;..,                                                                    *|
|* :     : int err;                                                           *|
|* :     :                                                                    *|
|* :     : try                                                                *|
|* :     : {                                                                  *|
|* :     :     if (1) throw (99);                                             *|
|* :     : }                                                                  *|
|* :     : catch (err)                                                        *|
|* :     : {                                                                  *|
|* :     :     printf("ERROR: %d\n", err);                                    *|
|* :     : }                                                                  *|
|* :                                                                          *|
|* ;.., TRY/CATCH INSIDE A CALLED FUNCTION:                                   *|
|* :  :                                                                       *|
|* :  : void test(void)                                                       *|
|* :  : {                                                                     *|
|* :  :     throw (42);                                                       *|
|* :  : }                                                                     *|
|* :  :                                                                       *|
|* :  : try                                                                   *|
|* :  : {                                                                     *|
|* :  :     test();                                                           *|
|* :  : }                                                                     *|
|* :  : catch (int err)                                                       *|
|* :  : {                                                                     *|
|* :  :     printf("ERROR: %d\n", err);                                       *|
|* :  : }                                                                     *|
|* :                                                                          *|
|* ;.., TRY/CATCH WITH A NESTED STATEMENT:                                    *|
|*    :                                                                       *|
|*    : try                                                                   *|
|*    : {                                                                     *|
|*    :     try                                                               *|
|*    :     {                                                                 *|
|*    :         throw (42);                                                   *|
|*    :     }                                                                 *|
|*    :     catch (int error)                                                 *|
|*    :     {                                                                 *|
|*    :         printf("err_1: %d\n", error);                                 *|
|*    :         throw (32);                                                   *|
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
|*     * ONLY SUPPORTS throw() AND catch() WITH int TYPE!                     *|
|*                                                                            *|
|*     * IF THIS LIBRARY IS ATTEMPTED TO BE COMPILED IN A C++ COMPILER,       *|
|*       THE LIBRARY WILL NOT DEFINE THE "try", "catch", AND "throw" MACROS   *|
|*       BUT DEFINES "TRY", "CATCH", AND "THROW" ANYWAY.                      *|
|*                                                                            *|
\******************************************************************************/

/*############################################################################*\
|*#                                SIDE NOTES                                #*|
|*############################################################################*|
|*                                                                            *|
|* IF YOU TRY TO USE THIS SYSTEM ON DEVICES LIKE 8051, PIC, MSP430, ETC.,     *|
|* THIS APPROACH MAY QUICKLY BLOAT MEMORY. THEREFORE, PLEASE CONSIDER USING   *|
|* THIS SYSTEM ONLY ON DEVICES WITH MORE THAN 4KB OF RAM.                     *|
|*                                                                            *|
|* DO NOT EXIT FROM TRY-CATCH BY USING "return" OR "goto" KEYWORDS, IT MAY    *|
|* CAUSE A SEGMENTATION ERROR OR UNEXPECTED RESULTS. INSTEAD, JUST DO:        *|
|* USE "throw(0)" TO COMPLETELY EXIT THE TRY BLOCK.                           *|
|*                                                                            *|
\******************************************************************************/

#ifndef TRY_CATCH_H
#	define TRY_CATCH_H 202508 /* VERSION */

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

/* **************************** [v] INCLUDES [v] **************************** */
#	include "LOCAL.h" /*
#	 define LOCAL
#	        */
#	include <setjmp.h> /*
#	 define jmp_buf
#	 define setjmp(jmp_buf env)
#	 define longjmp(jmp_buf env, int val)
#	        */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] C++ (PUSH) [v] *************************** */
#	ifdef __cplusplus /* C++ */
extern "C" {
#	endif /* __cplusplus */
/* *************************** [^] C++ (PUSH) [^] *************************** */

/* ********************** [v] CAN CHANGABLE MACRO [v] *********************** */
#	ifndef __TRY_CATCH_BUFFER_SIZE__
#		define __TRY_CATCH_BUFFER_SIZE__ 32 // <- INCREASE IF NEEDED
#	endif /* !__TRY_CATCH_BUFFER_SIZE__ */
/* ********************** [^] CAN CHANGABLE MACRO [^] *********************** */

#	define TRY \
		++__TRY_CATCH_INDEX__;\
		\
		if (!setjmp(__TRY_CATCH_BUFFER__[(__TRY_CATCH_INDEX__ - 1)]))

#	define CATCH(VARIABLE_NAME) \
		else for (\
				VARIABLE_NAME = __TRY_CATCH_VALUE__; \
				__TRY_CATCH_VALUE__; \
				__TRY_CATCH_VALUE__ = 0\
			)

#	define THROW(ERROR_NO) \
		if (__TRY_CATCH_INDEX__ > 0)\
		{\
			__TRY_CATCH_VALUE__ = (int)ERROR_NO;\
			longjmp(\
				__TRY_CATCH_BUFFER__[--__TRY_CATCH_INDEX__], \
				(int)ERROR_NO\
			);\
		}

/* ************************ [v] GLOBAL VARIABLES [v] ************************ */
#	ifdef SETUP_TRY_CATCH
LOCAL jmp_buf	__TRY_CATCH_BUFFER__[__TRY_CATCH_BUFFER_SIZE__];
LOCAL char		__TRY_CATCH_INDEX__ = 0;
LOCAL int		__TRY_CATCH_VALUE__ = 0;
#	else /* CREATE GLOBAL VARIABLES AUTOMATICALLY */
#		ifdef main
#			undef main
#		endif /* main */
#		ifdef WinMain
#			undef WinMain
#		endif /* main */
#		ifdef LOCALMACRO__VA_ARGS_GLOBAL_VARIABLES
#			define LOCALMACRO__TRY_CATCH__VA_ARGS_GLOBAL_VARIABLES \
				LOCALMACRO__VA_ARGS_GLOBAL_VARIABLES
#		else
#			define LOCALMACRO__TRY_CATCH__VA_ARGS_GLOBAL_VARIABLES
#		endif /* LOCALMACRO__VA_ARGS_GLOBAL_VARIABLES */
#		ifdef LOCALMACRO__OBJECT_GLOBAL_VARIABLES
#			define LOCALMACRO__TRY_CATCH__OBJECT_GLOBAL_VARIABLES \
				LOCALMACRO__OBJECT_GLOBAL_VARIABLES
#		else
#			define LOCALMACRO__TRY_CATCH__OBJECT_GLOBAL_VARIABLES
#		endif /* LOCALMACRO__OBJECT_GLOBAL_VARIABLES */
#		define LOCALMACRO__TRY_CATCH_GLOBAL_VARIABLES \
			LOCAL jmp_buf	__TRY_CATCH_BUFFER__[__TRY_CATCH_BUFFER_SIZE__];\
			LOCAL char		__TRY_CATCH_INDEX__ = 0;\
			LOCAL int		__TRY_CATCH_VALUE__ = 0;
#		define main \
			__IDLE__TRY_CATCH; \
			LOCALMACRO__TRY_CATCH__OBJECT_GLOBAL_VARIABLES \
			LOCALMACRO__TRY_CATCH__VA_ARGS_GLOBAL_VARIABLES \
			LOCALMACRO__TRY_CATCH_GLOBAL_VARIABLES \
			int main
#		define WinMain \
			__IDLE__TRY_CATCH; \
			LOCALMACRO__TRY_CATCH__OBJECT_GLOBAL_VARIABLES \
			LOCALMACRO__TRY_CATCH__VA_ARGS_GLOBAL_VARIABLES \
			LOCALMACRO__TRY_CATCH_GLOBAL_VARIABLES \
			int WINAPI WinMain
#	endif /* SETUP_TRY_CATCH */
/* ************************ [^] GLOBAL VARIABLES [^] ************************ */

/* *************************** [v] PROTOTYPES [v] *************************** */
extern LOCAL jmp_buf	__TRY_CATCH_BUFFER__[__TRY_CATCH_BUFFER_SIZE__];
extern LOCAL char		__TRY_CATCH_INDEX__;
extern LOCAL int		__TRY_CATCH_VALUE__;
/* *************************** [^] PROTOTYPES [^] *************************** */

/* *************************** [v] C++ (PUSH) [v] *************************** */
#	ifdef __cplusplus /* C++ */
}
#	else
/* **************************** [v] LOWERCASE [v] *************************** */
#		define try TRY
#		define catch CATCH
#		define throw THROW
/* **************************** [^] LOWERCASE [^] *************************** */
#	endif /* __cplusplus */
/* *************************** [^] C++ (PUSH) [^] *************************** */

/* ************************ [v] TI CGT CCS (POP) [v] ************************ */
#	ifdef __TI_COMPILER_VERSION__
#		pragma diag_pop /* TI CGT CCS COMPILER DIRECTIVES */
#	endif /* __TI_COMPILER_VERSION__ */
/* ************************ [^] TI CGT CCS (POP) [^] ************************ */

#endif /* !TRY_CATCH_H */
