/******************************************************************************\
# H - TRY_CATCH                                  #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2023/04/25 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - AGPL-3.0  :: Update - 2025/04/25 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

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
|* WRAPS A BLOCK OF CODE THAT MAY CALL `throw(...)` INSIDE IT.               *|
|*                                                                            *|
|* ::::::::::::::::::::::::::::::::: CATCH :::::::::::::::::::::::::::::::::: *|
|* PLACED RIGHT AFTER `try`, CAPTURES THE ERROR CODE PASSED FROM `throw(...)`*|
|*                                                                            *|
|* ::::::::::::::::::::::::::::::::: THROW :::::::::::::::::::::::::::::::::: *|
|* THROWS AN ERROR CODE AND JUMPS TO THE NEAREST `catch` BLOCK.              *|
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
|* ;.., void test(void)                                                       *|
|*    : {                                                                     *|
|*    :     throw(42);                                                        *|
|*    : }                                                                     *|
|*    :                                                                       *|
|*    : try                                                                   *|
|*    : {                                                                     *|
|*    :     test();                                                           *|
|*    : }                                                                     *|
|*    : catch(int err)                                                        *|
|*    : {                                                                     *|
|*    :     printf("ERROR: %d\n", err);                                       *|
|*    : }                                                                     *|
|*                                                                            *|
\******************************************************************************/

/*############################################################################*\
|*#                              WTF THAT DOES?                              #*|
|*############################################################################*|
|*                                                                            *|
|* :::::::::::::::::::::::::::::: EXPLANATION ::::::::::::::::::::::::::::::: *|
|* THIS CUSTOM ERROR HANDLING SYSTEM USES `setjmp` AND `longjmp` TO           *|
|* MIMIC A BASIC FORM OF EXCEPTION HANDLING IN C.                             *|
|*                                                                            *|
|* - `try` sets a jump point for where the program should return if an error  *|
|*   occurs.                                                                  *|
|*                                                                            *|
|* - `throw(err)` stores the error value and jumps back to that point.        *|
|*                                                                            *|
|* - `catch(variable)` allows you to access the error code thrown.            *|
|*                                                                            *|
|* ::::::::::::::::::::::::::::::::: NOTES :::::::::::::::::::::::::::::::::: *|
|*     * THIS SYSTEM IS GLOBAL — ONLY ONE ERROR CONTEXT AT A TIME!            *|
|*       DO NOT NEST `try/catch` OR USE CONCURRENTLY IN THREADS!              *|
|*                                                                            *|
|*     * ONLY throw() AND catch() int TYPES!                                  *|
|*                                                                            *|
|*     * IF THIS LIBRARY IS ATTEMPTED TO BE COMPILED IN A C++ COMPILER,       *|
|*       THE LIBRARY WILL NOT DEFINE "try", "catch", AND "throw" KEYWORDS!    *|
|*                                                                            *|
\******************************************************************************/

#ifndef TRY_CATCH_H
#	define TRY_CATCH_H 202504 /* VERSION */
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
#		include <setjmp.h> /*
#		 define jmp_buf
#		 define setjmp(jmp_buf env)
#		 define longjmp(jmp_buf env, int val)
#		        */
/* **************************** [^] INCLUDES [^] **************************** */

/* ************************ [v] GLOBAL VARIABLES [v] ************************ */
static jmp_buf	__JMP_ERROR_BUFFER__;
static int		__JMP_ERROR_VALUE__ = 0;
/* ************************ [^] GLOBAL VARIABLES [^] ************************ */

#		define try if (!setjmp(__JMP_ERROR_BUFFER__))
#		define catch(VARIABLE_NAME) \
			else \
				for (\
					VARIABLE_NAME = __JMP_ERROR_VALUE__; \
					__JMP_ERROR_VALUE__; \
					__JMP_ERROR_VALUE__ = 0\
				)
#		define throw(ERROR_NO) \
			__JMP_ERROR_VALUE__ = (int)ERROR_NO;\
			longjmp(__JMP_ERROR_BUFFER__, (int)ERROR_NO)

/* ************************ [v] TI CGT CCS (POP) [v] ************************ */
#		ifdef __TI_COMPILER_VERSION__
#			pragma diag_pop /* TI CGT CCS COMPILER DIRECTIVES */
#		endif /* __TI_COMPILER_VERSION__ */
/* ************************ [^] TI CGT CCS (POP) [^] ************************ */

#	endif /* !__cplusplus */
#endif /* TRY_CATCH_H */
