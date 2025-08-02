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
|*        NAME        :   TYPE    :                DESCRIPTION                *|
|*....................:...........:...........................................*|
|* OBJECT__FUNCTIONS  : #define() : CONNECT ALL OF THE FUNCTIONS INTO YOUR    *|
|* object__functions  :           : STRUCTURE                                 *|
|*....................:...........:...........................................*|
|* OBJECT__FUNCTION   : #define() : CREATE FUNCTION POINTER INSIDE YOUR       *|
|* object__function   :           : STRUCTURE                                 *|
|*....................:...........:...........................................*|
|* OBJECT__CONNECT    : #define() : CONNECT A STRUCTURE INTO A FUNCTION       *|
|* object_from        :           :                                           *|
|*....................:...........:...........................................*|
|* OBJECT             : #define() : CREATE AN OBJECT                          *|
|* object             :           :                                           *|
|*....................:...........:...........................................*|
|* USE                : #define() : USE A FUNCTION INSIDE AN OBJECT           *|
|* use                :           :                                           *|
|*....................:...........:...........................................*|
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
|* : ELSE, JUST SKIP THE SETUP AND JUMP TO LINE 78 AT THE BOTTOM OF THIS FILE *|
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
|* :::::::::::::::::::::::::::::::: GENERAL ::::::::::::::::::::::::::::::::: *|
|*                                                                            *|
|* THIS LIBRARY PROVIDES AN OOP-LIKE SYSTEM FOR C, FEATURING:                 *|
|* - IMPLICIT "this" POINTER                                                  *|
|* - CONSTRUCTOR SUPPORT                                                      *|
|* - FUNCTION POINTER BINDING BY INDEX                                        *|
|*                                                                            *|
|* DEFINE YOUR STRUCTURE NORMALLY WITH FUNCTION POINTERS AT THE TOP.          *|
|* CONNECT YOUR FUNCTIONS USING "object__functions(...) { ... }".             *|
|* THE FIRST INDEX (0) IS ALWAYS THE CONSTRUCTOR FUNCTION.                    *|
|* FUNCTIONS ARE BOUND TO STRUCT MEMBERS BY ORDER, NOT NAME.                  *|
|*                                                                            *|
|* O - FUNCTION CONNECTION                                                    *|
|* :                                                                          *|
|* : struct test_object_type                                                  *|
|* : {                                                                        *|
|* :     void object__function(worked);                                       *|
|* :     int value;                                                           *|
|* : };                                                                       *|
|* :                                                                          *|
|* : static void CONSTRUCTOR(void)                                            *|
|* : {                                                                        *|
|* :     object__connect(test_object_type);                                   *| 
|* :     this->value = 0;                                                     *|
|* : }                                                                        *|
|* :                                                                          *|
|* : static void worked(int n)                                                *|
|* : {                                                                        *|
|* :     object__connect(test_object_type);                                   *|
|* :     this->value += n;                                                    *|
|* : }                                                                        *|
|* :                                                                          *|
|* : object__functions(test_object_type)                                      *|
|* : {                                                                        *|
|* :     CONSTRUCTOR,                                                         *|
|* :     worked,                                                              *|
|* :     0                                                                    *|
|* : };                                                                       *|
|*                                                                            *|
|* O - USAGE                                                                  *|
|* :                                                                          *|
|* : object(test_object_type, obj) (); // CONSTRUCTOR CALLED                  *|
|* : obj.worked(42); // uses implicit "this"                                  *|
|*                                                                            *|
|* WHEN USING MULTIPLE OBJECTS IN THE SAME SCOPE, USE "use(...)" TO SWITCH    *|
|* CONTEXT SAFELY:                                                            *|
|*                                                                            *|
|* O - MULTIPLE OBJECTS EXAMPLE                                               *|
|* :                                                                          *|
|* : object(test_object_type, test1) ();                                      *|
|* : object(test_object_type, test2) ();                                      *|
|* :                                                                          *|
|* : use(test1).worked(42);                                                   *|
|* : test1.worked(42);                                                        *|
|* : test1.worked(42);                                                        *|
|* : use(test2).worked(42);                                                   *|
|* : use(test1).worked(42);                                                   *|
|* : use(test2).worked(42);                                                   *|
|*                                                                            *|
|* USING "use(obj)" BEFORE A SEQUENCE SAVES A CONTEXT SWITCH (ASM OPTIM).     *|
|* IT IS OPTIONAL, BUT RECOMMENDED FOR PERFORMANCE WHEN SWITCHING OBJECTS.    *|
|*                                                                            *|
|* O - FULL EXAMPLE                                                           *|
|* :                                                                          *|
|* ;.., CONNECTING YOUR OBJECT TO YOUR FUNCTIONS                              *|
|* :  :                                                                       *|
|* :  : struct test_object_type                                               *|
|* :  : {                                                                     *|
|* :  :     int object__function(FUNC1);                                      *|
|* :  :     void object__function(FUNC2);                                     *|
|* :  :     void object__function(FUNC3);                                     *|
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
|* :  : static int FUNC1()                                                    *|
|* :  : {                                                                     *|
|* :  :     object_from (test_object_type);                                   *|
|* :  :                                                                       *|
|* :  :     printf("1\n");                                                    *|
|* :  :     return (42);                                                      *|
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
|* ;.., CREATING AND USING OBJECTS                                            *|
|*    :                                                                       *|
|*    : int main(void)                                                        *|
|*    : {                                                                     *|
|*    :     {                                                                 *|
|*    :         object (test_object_type, TEST) ();                           *|
|*    :                                                                       *|
|*    :         TEST.FUNC1();                                                 *|
|*    :         TEST.FUNC2();                                                 *|
|*    :         TEST.FUNC3();                                                 *|
|*    :     }                                                                 *|
|*    :                                                                       *|
|*    :     {                                                                 *|
|*    :         object (test_object_type, TEST1) ();                          *|
|*    :         object (test_object_type, TEST2) ();                          *|
|*    :                                                                       *|
|*    :         use(TEST1).FUNC1();                                           *|
|*    :         TEST1.FUNC2();                                                *|
|*    :                                                                       *|
|*    :         use(TEST2).FUNC1();                                           *|
|*    :         TEST2.FUNC2();                                                *|
|*    :                                                                       *|
|*    :         use(TEST1).FUNC1();                                           *|
|*    :         use(TEST2).FUNC1();                                           *|
|*    :                                                                       *|
|*    :         // IF COMMA OPERATOR SUPPORTED (LIKE: a = (x++, y = 42, z))   *|
|*    :         printf("%d\n", use(TEST1).FUNC1());                           *|
|*    :         // ELSE (WHICH IS REALLY OLD COMPILERS)                       *|
|*    :         use(TEST1);                                                   *|
|*    :         printf("%d\n", TEST1.FUNC1());                                *|
|*    :     }                                                                 *|
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
#	define OBJECT_H 202508 /* VERSION */

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
#	include "CHECK_FEATURE/COMMA_OPERATOR.h" /*
#	 define IS__COMMA_OPERATOR__SUPPORTED
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

#	define OBJECT__FUNCTIONS(OBJECT_TYPE) \
		void *OBJECT_TYPE[__OBJECT_MAX_FUNCTION_LIMIT__] =

#	define OBJECT__FUNCTION(FUNCTION_NAME) (*FUNCTION_NAME)()

#	define OBJECT__CONNECT(OBJECT_STRUCT_TYPE) \
		struct OBJECT_STRUCT_TYPE	*const this = \
			(struct OBJECT_STRUCT_TYPE *const)__OBJECT_STRUCTURE_POINTER__

#	define OBJECT(OBJECT_NAME, VARIABLE_NAME) \
		struct OBJECT_NAME	VARIABLE_NAME;\
		\
		{\
			register size_t	__OBJECT_INDEX__;\
			void			(*FUNCTION)();\
			\
			__OBJECT_INDEX__ = 0;\
			\
			while (OBJECT_NAME[__OBJECT_INDEX__])\
			{\
				FUNCTION = \
					(void (*)())(OBJECT_NAME[__OBJECT_INDEX__]);\
				\
				if (__OBJECT_INDEX__)\
				{\
					((long **)&VARIABLE_NAME)[__OBJECT_INDEX__ - 1]\
						= (long *)FUNCTION;\
				}\
				\
				++__OBJECT_INDEX__;\
			}\
		}\
		\
		__OBJECT_STRUCTURE_POINTER__ = (void *)&VARIABLE_NAME;\
		\
		if (*OBJECT_NAME)\
			((void (*)())(*OBJECT_NAME))

#	ifdef IS__COMMA_OPERATOR__SUPPORTED
#		define USE(VARIABLE_NAME) (\
			__OBJECT_STRUCTURE_POINTER__ = (void *)&VARIABLE_NAME,\
			VARIABLE_NAME\
		)
#	else
#		define USE(VARIABLE_NAME) \
			__OBJECT_STRUCTURE_POINTER__ = (void *)&VARIABLE_NAME;\
			(void)VARIABLE_NAME
#	endif /* IS__COMMA_OPERATOR__SUPPORTED */

/* ************************ [v] GLOBAL VARIABLES [v] ************************ */
#	ifdef SETUP_OBJECT
LOCAL void		*__OBJECT_STRUCTURE_POINTER__ = (void *)0;
LOCAL jmp_buf	__OBJECT_LONGJMP_ADDRESS__;
LOCAL int		__OBJECT_IS_READY__ = 0;
#	else /* CREATE GLOBAL VARIABLES AUTOMATICALLY */
#		ifdef main
#			undef main
#		endif /* main */
#		ifdef WinMain
#			undef WinMain
#		endif /* main */
#		ifdef LOCALMACRO__VA_ARGS_GLOBAL_VARIABLES
#			define LOCALMACRO__OBJECT__VA_ARGS_GLOBAL_VARIABLES \
				LOCALMACRO__VA_ARGS_GLOBAL_VARIABLES
#		else
#			define LOCALMACRO__OBJECT__VA_ARGS_GLOBAL_VARIABLES
#		endif /* LOCALMACRO__VA_ARGS_GLOBAL_VARIABLES */
#		ifdef LOCALMACRO__TRY_CATCH_GLOBAL_VARIABLES
#			define LOCALMACRO__OBJECT__TRY_CATCH_GLOBAL_VARIABLES \
				LOCALMACRO__TRY_CATCH_GLOBAL_VARIABLES
#		else
#			define LOCALMACRO__OBJECT__TRY_CATCH_GLOBAL_VARIABLES
#		endif /* LOCALMACRO__TRY_CATCH_GLOBAL_VARIABLES */
#		define LOCALMACRO__OBJECT_GLOBAL_VARIABLES \
			LOCAL void		*__OBJECT_STRUCTURE_POINTER__ = (void *)0;\
			LOCAL jmp_buf	__OBJECT_LONGJMP_ADDRESS__;\
			LOCAL int		__OBJECT_IS_READY__ = 0;
#		define main \
			__IDLE__TRY_CATCH; \
			LOCALMACRO__OBJECT__TRY_CATCH_GLOBAL_VARIABLES \
			LOCALMACRO__OBJECT__VA_ARGS_GLOBAL_VARIABLES \
			LOCALMACRO__OBJECT_GLOBAL_VARIABLES \
			int main
#		define WinMain \
			__IDLE__TRY_CATCH; \
			LOCALMACRO__OBJECT__TRY_CATCH_GLOBAL_VARIABLES \
			LOCALMACRO__OBJECT__VA_ARGS_GLOBAL_VARIABLES \
			LOCALMACRO__OBJECT_GLOBAL_VARIABLES \
			int WINAPI WinMain
#	endif /* SETUP_OBJECT */
/* ************************ [^] GLOBAL VARIABLES [^] ************************ */

/* *************************** [v] PROTOTYPES [v] *************************** */
extern LOCAL void		*__OBJECT_STRUCTURE_POINTER__;
extern LOCAL jmp_buf	__OBJECT_LONGJMP_ADDRESS__;
extern LOCAL int		__OBJECT_IS_READY__;
/* *************************** [^] PROTOTYPES [^] *************************** */

/* **************************** [v] LOWERCASE [v] *************************** */
#	define object__functions OBJECT__FUNCTIONS
#	define object__function OBJECT__FUNCTION
#	define object__connect OBJECT__CONNECT
#	define object OBJECT
#	define use USE
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
