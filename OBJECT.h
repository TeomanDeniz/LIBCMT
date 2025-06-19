/******************************************************************************\
# H - OBJECT                                     #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2025/05/25 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - AGPL-3.0  :: Update - 2025/06/19 : #    ::::!!!1!!1!!!1!!!::     #
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
|*       NAME       :   TYPE    :                 DESCRIPTION                 *|
|*..................:...........:.............................................*|
|* OBJECT_FUNCTIONS : #define() : CONNECT ALL OF THE FUNCTIONS INTO YOUR      *|
|* object_functions :           : STRUCTURE                                   *|
|*..................:...........:.............................................*|
|* OBJECT_FROM      : #define() : CONNECT A STRUCTURE INTO A FUNCTION         *|
|* object_from      :           :                                             *|
|*..................:...........:.............................................*|
|* OBJECT           : #define() : CREATE YOUR OBJECT                          *|
|* object           :           :                                             *|
|*..................:.........................................................*|
\******************************************************************************/

/*############################################################################*\
|*#                                HOW TO USE                                #*|
|*############################################################################*|
|*                                                                            *|
|* O - SETUP                                                                  *|
|* :                                                                          *|
|* : NOTE: SETUP PART IS OPTIONAL IF YOU'RE DEAILNG WITH main FUNCTION BY     *|
|* : YOURSELF WITH LIKE "#define main ..." OR "#define main(...) ..."         *|
|* :                                                                          *|
|* : ELSE, JUST SKIP THE SETUP AND JUMP TO LINE 72 AT THE BOTTOM OF THIS FILE *|
|* :                                                                          *|
|* : BEFORE USING THIS LIBRARY, YOU MUST DEFINE THE MACRO "SETUP_OBJECT"      *|
|* : ONCE, IN ONE C FILE (TYPICALLY YOUR "main.c" OR ENTRY POINT).            *|
|* :                                                                          *|
|* : THIS ENSURES GLOBAL VARIABLES USED INTERNALLY ARE PROPERLY DEFINED.      *|
|* :                                                                          *|
|* : AFTER THAT, YOU CAN INCLUDE THIS HEADER ANYWHERE ELSE WITHOUT DEFINING   *|
|* : THE MACRO AGAIN. ALL OTHER FILES WILL JUST SEE "extern" DECLS.           *|
|* :                                                                          *|
|* ;.., #define SETUP_OBJECT                                                  *|
|*    : #include "LIBCMT/OBJECT.h"                                            *|
|*    :                                                                       *|
|*    : int main() {                                                          *|
|*    : ...                                                                   *|
|*    : }                                                                     *|
|*                                                                            *|
|* THIS LIBRARY MAKES YOU USE "this" SPECIAL VARIABLE INSIDE YOUR FUNCTIONS   *|
|* IF THEY ARE CONNECTED TO A STRUCTURE.                                      *|
|*                                                                            *|
|* JUST CREATE A STRUCTURE LIKE NORMAL. PUT ALL OF YOUR FUNCTION POINTERS AT  *|
|* THE TOP OF YOUR STRUCTURE (IT IS PRIORITY)                                 *|
|*                                                                            *|
|* O - EXAMPLE                                                                *|
|* :                                                                          *|
|* : struct test_object_type                                                  *|
|* : {                                                                        *|
|* :     void (*FUNC1)();                                                     *|
|* :                                                                          *|
|* :     int a;                                                               *|
|* : };                                                                       *|
|*                                                                            *|
|* SELECT YOUR FUNCTIONS AND CONNECT THEM TO YOUR STRUCTURE BY USING          *|
|* "object_from (STRUCTURE_TYPE_NAME)"                                        *|
|*                                                                            *|
|* O - EXAMPLE                                                                *|
|* :                                                                          *|
|* : void FUNC1()                                                             *|
|* : {                                                                        *|
|* :     object_from (test_object_type);                                      *|
|* :                                                                          *|
|* :     ...                                                                  *|
|* : }                                                                        *|
|*                                                                            *|
|* AT THE END, CONNECT BOTH YOUR STRUCTURE AND YOUR FUNCTIONS BY USING        *|
|* "object_functions (STRUCTURE_TYPE_NAME){...};"                             *|
|*                                                                            *|
|* O - EXAMPLE                                                                *|
|* :                                                                          *|
|* : object_functions (test_object_type)                                      *|
|* : {                                                                        *|
|* :     0, // INDEX 0 IS ALWAYS A CONSTRUCTOR FUNCTION                       *|
|* :                                                                          *|
|* :     FUNC1,                                                               *|
|* :     0                                                                    *|
|* : };                                                                       *|
|* :                                                                          *|
|* ;.., BUT BE AWARE! THESE FUNCTIONS ARE PUT INTO YOUR STRUCTURE BY USING    *|
|*    : THEIR INDEX NUMBER! NOT BY THEIR NAMES!!!                             *|
|*    :                                                                       *|
|*    : strcut test                                                           *|
|*    : {                                                                     *|
|*    :      void (*A)(); // FUNCTION_1                                       *|
|*    :      void (*B)(); // FUNCTION_3                                       *|
|*    :      void (*C)(); // FUNCTION_2                                       *|
|*    :                                                                       *|
|*    :      int variable;                                                    *|
|*    :      ...                                                              *|
|*    : }                                                                     *|
|*    :                                                                       *|
|*    : object_functions (test)                                               *|
|*    : {                                                                     *|
|*    :     0, // INDEX 0 IS ALWAYS A CONSTRUCTOR FUNCTION                    *|
|*    :                                                                       *|
|*    :     FUNCTION_1,                                                       *|
|*    :     FUNCTION_3,                                                       *|
|*    :     FUNCTION_2,                                                       *|
|*    :     0                                                                 *|
|*    : };                                                                    *|
|*                                                                            *|
|* AND YET, YOUR OBJECT IS READY TO USE. YOU CAN ALSO DEFINE A CONSTRUCTOR    *|
|* FUNCTION IF YOU WANT.                                                      *|
|*                                                                            *|
|* AND MAKE YOUR OBJECT/STRUCTURE DO SOME JOBS ON THE CREATION.               *|
|*                                                                            *|
|* O - EXAMPLE                                                                *|
|* :                                                                          *|
|* : object_functions (test_object_type)                                      *|
|* : {                                                                        *|
|* :     FUNC1, // INDEX 0 IS ALWAYS A CONSTRUCTOR FUNCTION                   *|
|* :     0                                                                    *|
|* : };                                                                       *|
|*                                                                            *|
|* NOW WHAT? YOU CAN CREATE YOUR STRUCTURE BY USING "object (...) (ARGS...)"  *|
|*                                                                            *|
|* O - EXAMPLE                                                                *|
|* :         YOUR OBJECT TYPE NAME   CONSTRUCTOR FUNCTION PARAMETERS          *|
|* :         vvvvvvvvvvvvvvvv        vv                                       *|
|* : object (test_object_type, TEST) ();                                      *|
|* :                           ^^^^                                           *|
|* :                           YOUR OBJECT VARIABLE NAME                      *|
|* : TEST.FUNC1();                                                            *|
|*                                                                            *|
|* IF YOUR CONSTRUCTOR HAVING PARAMETERS FROM OUTSIDE, YOU CAN SEND           *|
|* PARAMETERS WHILE CREATING YOUR OBJECT.                                     *|
|*                                                                            *|
|* O - EXAMPLE                                                                *|
|* : void FUNC1(int a)                                                        *|
|* : {                                                                        *|
|* :     object_from (test_object_type);                                      *|
|* :                                                                          *|
|* :     ...                                                                  *|
|* : }                                                                        *|
|* :                                                                          *|
|* :         YOUR OBJECT TYPE NAME   CONSTRUCTOR FUNCTION PARAMETERS          *|
|* :         vvvvvvvvvvvvvvvv        vvvv                                     *|
|* : object (test_object_type, TEST) (42);                                    *|
|* :                           ^^^^                                           *|
|* :                           YOUR OBJECT VARIABLE NAME                      *|
|* : TEST.FUNC1();                                                            *|
|*                                                                            *|
|* O - EXAMPLES                                                               *|
|* :                                                                          *|
|* ;.., CONNECTING YOUR OBJECT TO YOUR FUNCTIONS                              *|
|* :  :                                                                       *|
|* :  : struct test_object_type                                               *|
|* :  : {                                                                     *|
|* :  :     void (*FUNC1)();                                                  *|
|* :  :     void (*FUNC2)();                                                  *|
|* :  :     void (*FUNC3)();                                                  *|
|* :  :                                                                       *|
|* :  :     int a;                                                            *|
|* :  : };                                                                    *|
|* :  :                                                                       *|
|* :  : static void CONSTRUCTOR()                                             *|
|* :  : {                                                                     *|
|* :  :     object_from (test_object_type);                                   *|
|* :  :                                                                       *|
|* :  :     printf("0\n");                                                    *|
|* :  : }                                                                     *|
|* :  :                                                                       *|
|* :  : static void FUNC1()                                                   *|
|* :  : {                                                                     *|
|* :  :     object_from (test_object_type);                                   *|
|* :  :                                                                       *|
|* :  :     printf("1\n");                                                    *|
|* :  : }                                                                     *|
|* :  :                                                                       *|
|* :  : static void FUNC2()                                                   *|
|* :  : {                                                                     *|
|* :  :     object_from (test_object_type);                                   *|
|* :  :                                                                       *|
|* :  :     printf("2\n");                                                    *|
|* :  : }                                                                     *|
|* :  :                                                                       *|
|* :  : static void FUNC3()                                                   *|
|* :  : {                                                                     *|
|* :  :     object_from (test_object_type);                                   *|
|* :  :                                                                       *|
|* :  :     printf("3\n");                                                    *|
|* :  : }                                                                     *|
|* :  :                                                                       *|
|* :  : object_functions (test_object_type)                                   *|
|* :  : {                                                                     *|
|* :  :     CONSTRUCTOR, // INDEX 0 IS ALWAYS A CONSTRUCTOR FUNCTION          *|
|* :  :                                                                       *|
|* :  :     FUNC1,                                                            *|
|* :  :     FUNC2,                                                            *|
|* :  :     FUNC3,                                                            *|
|* :  :     0                                                                 *|
|* :  : };                                                                    *|
|* :                                                                          *|
|* ;.., CREATING AND USING AN OBJECT                                          *|
|*    :                                                                       *|
|*    : int main(void)                                                        *|
|*    : {                                                                     *|
|*    :     object (test_object_type, TEST) ();                               *|
|*    :                                                                       *|
|*    :     TEST.FUNC1();                                                     *|
|*    :     TEST.FUNC2();                                                     *|
|*    :     TEST.FUNC3();                                                     *|
|*    :                                                                       *|
|*    :     return (0);                                                       *|
|*    : }                                                                     *|
|*                                                                            *|
\******************************************************************************/

/*############################################################################*\
|*#                              WTF THAT DOES?                              #*|
|*############################################################################*|
|*                                                                            *|
|* :::::::::::::::::::::::::::::: EXPLANATION ::::::::::::::::::::::::::::::: *|
|*                                                                            *|
|* THIS HEADER CREATES A SIMPLE VERSION OF OBJECT & ORIENTED SYSTEM.          *|
|*                                                                            *|
|* IT'S IMPLEMENTS "this" VARIABLE INTO THE FUNCTIONS YOU CONNECTED TO YOUR   *|
|* STRUCTURE.                                                                 *|
|*                                                                            *|
|* AND THIS SYTEM HAS A CONSTRUCTOR SYSTEM TOO.                               *|
|*                                                                            *|
\******************************************************************************/

/*############################################################################*\
|*#                                SIDE NOTES                                #*|
|*############################################################################*|
|*                                                                            *|
|* IF YOU TRY TO USE THIS SYSTEM ON DEVICES LIKE 8051, PIC, MSP430, ETC.,     *|
|* THIS APPROACH CAN BLOAT MEMORY QUICKLY. THEREFORE, PLEASE CONSIDER USING   *|
|* THIS SYSTEM ONLY ON DEVICES WITH MORE THAN 4KB OF RAM.                     *|
|*                                                                            *|
\******************************************************************************/

#ifndef OBJECT_H
#	define OBJECT_H 202506 /* VERSION */

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
#	include "KEYWORDS/LOCAL.h" /*
#	 define LOCAL
#	        */
#	include <setjmp.h> /*
#	 define jmp_buf
#	 define setjmp(jmp_buf env)
#	 define longjmp(jmp_buf env, int val)
#	        */
#	include <stddef.h> /*
#	typedef size_t;
#	        */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] C++ (PUSH) [v] *************************** */
#	ifdef __cplusplus /* C++ */
extern "C" {
#	endif /* __cplusplus */
/* *************************** [^] C++ (PUSH) [^] *************************** */

/* ********************** [v] CAN CHANGABLE MACRO [v] *********************** */
#	ifndef __OBJECT_MAX_FUNCTION_LIMIT__
#		define __OBJECT_MAX_FUNCTION_LIMIT__ 32 // <- INCREASE IF NEEDED
#	endif /* !__OBJECT_MAX_FUNCTION_LIMIT__ */
/* ********************** [^] CAN CHANGABLE MACRO [^] *********************** */

#	define OBJECT_FUNCTIONS(OBJCET_NAME) \
	void *OBJCET_NAME[__OBJECT_MAX_FUNCTION_LIMIT__] =

#	define OBJECT_FROM(OBJECT_STRUCT_NAME) \
	static struct OBJECT_STRUCT_NAME	*this = 0;\
	\
	if (__OBJECT_IS_READY__ == 0)\
	{\
		if (!this && __OBJECT_STRUCTURE_POINTER__ != (void *)0)\
			this = (struct OBJECT_STRUCT_NAME *)__OBJECT_STRUCTURE_POINTER__;\
		\
		longjmp(__OBJECT_LONGJMP_ADDRESS__, 0);\
	}

#	define OBJECT(OBJCET_NAME, VARIABLE_NAME) \
	struct OBJCET_NAME	VARIABLE_NAME;\
	\
	{\
		size_t	__OBJECT_CLASS_INDEX__;\
		\
		__OBJECT_STRUCTURE_POINTER__ = &VARIABLE_NAME;\
		__OBJECT_CLASS_INDEX__ = 0;\
		__OBJECT_IS_READY__ = 0;\
		\
		while (!__OBJECT_IS_READY__)\
		{\
			if (!setjmp(__OBJECT_LONGJMP_ADDRESS__))\
			{\
				void	(*FUNCTION)();\
				\
				if (OBJCET_NAME[__OBJECT_CLASS_INDEX__])\
				{\
					FUNCTION = \
						(void (*)())(OBJCET_NAME[__OBJECT_CLASS_INDEX__]);\
					\
					if (__OBJECT_CLASS_INDEX__)\
					{\
						((long **)&VARIABLE_NAME)[__OBJECT_CLASS_INDEX__ - 1]\
							= (long *)FUNCTION;\
					}\
					\
					++__OBJECT_CLASS_INDEX__;\
					FUNCTION();\
				}\
				\
				if (__OBJECT_CLASS_INDEX__)\
					__OBJECT_IS_READY__ = 1;\
				else\
					++__OBJECT_CLASS_INDEX__;\
				\
			}\
		}\
	}\
	\
	if (*OBJCET_NAME)\
		((void (*)())(*OBJCET_NAME))

/* ************************ [v] GLOBAL VARIABLES [v] ************************ */
#	ifdef SETUP_OBJECT
LOCAL void		*__OBJECT_STRUCTURE_POINTER__ = 0;
LOCAL jmp_buf	__OBJECT_LONGJMP_ADDRESS__;
LOCAL int		__OBJECT_IS_READY__ = 0;
#	else /* CREATE GLOBAL VARIABLES AUTOMATICALLY */
#		ifdef main
#			undef main
#		endif /* main */
#		ifdef WinMain
#			undef WinMain
#		endif /* main */
#		ifndef LOCALMACRO__VA_ARGS_GLOBAL_VARIABLES
#			define LOCALMACRO__VA_ARGS_GLOBAL_VARIABLES
#		endif /* !LOCALMACRO__VA_ARGS_GLOBAL_VARIABLES */
#		ifndef LOCALMACRO__TRY_CATCH_GLOBAL_VARIABLES
#			define LOCALMACRO__TRY_CATCH_GLOBAL_VARIABLES
#		endif /* !LOCALMACRO__TRY_CATCH_GLOBAL_VARIABLES */
#		define LOCALMACRO__OBJECT_GLOBAL_VARIABLES \
			LOCAL void		*__OBJECT_STRUCTURE_POINTER__ = 0;\
			LOCAL jmp_buf	__OBJECT_LONGJMP_ADDRESS__;\
			LOCAL int		__OBJECT_IS_READY__ = 0;
#		define main \
			__IDLE__TRY_CATCH;\
			LOCALMACRO__TRY_CATCH_GLOBAL_VARIABLES\
			LOCALMACRO__VA_ARGS_GLOBAL_VARIABLES\
			LOCALMACRO__OBJECT_GLOBAL_VARIABLES\
			int main
#		define WinMain \
			__IDLE__TRY_CATCH;\
			LOCALMACRO__TRY_CATCH_GLOBAL_VARIABLES\
			LOCALMACRO__VA_ARGS_GLOBAL_VARIABLES\
			LOCALMACRO__OBJECT_GLOBAL_VARIABLES\
			int WINAPI WinMain
#	endif /* SETUP_OBJECT */
LOCAL extern void		*__OBJECT_STRUCTURE_POINTER__;
LOCAL extern jmp_buf	__OBJECT_LONGJMP_ADDRESS__;
LOCAL extern int		__OBJECT_IS_READY__;
/* ************************ [^] GLOBAL VARIABLES [^] ************************ */

/* **************************** [v] LOWERCASE [v] *************************** */
#	define object_functions OBJECT_FUNCTIONS
#	define object_from OBJECT_FROM
#	define object OBJECT
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

#endif /* !OBJECT_H */
