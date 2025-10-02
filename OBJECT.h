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
# : License - GPL-3.0   :: Update - 2025/10/02 : #    ::::!!!1!!1!!!1!!!::     #
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
|* NEW              : #define() : CREATE AN OBJECT                            *|
|* new              :           :                                             *|
|*..................:...........:.............................................*|
|* DESTROY          : #define() : DESTROY AN OBJECT (IT IS NECESSARY)         *|
|* destroy          : #define() :                                             *|
|*..................:...........:.............................................*|
|* OBJECT           : #define   : struct                                      *|
|* object           :           :                                             *|
|*..................:...........:.............................................*|
|* OBJECT__READY    : #define() : CHECK IF OBJECT IS SUCCESSFULLY ALLOCATED   *|
|* object__ready    :           : RETURNS `(int)1` IF TRUE                    *|
|*..................:...........:.............................................*|
|* I_AM_AN_OBJECT   : #define   : DECLARES THE FUNCTION POINTER STORAGE FOR   *|
|* i_am_an_object   :           : AN OBJECT                                   *|
|*..................:...........:.............................................*|
|* OBJECT__CONNECT  : #define() : CONNECT A STRUCTURE INTO A FUNCTION         *|
|* object__connect  : #define() :                                             *|
|*..................:...........:.............................................*|
|* OBJECT__INJECT   : #define() : INJECT A FUNCTION POINTER                   *|
|* object__inject   : #define() :                                             *|
|*..................:...........:.............................................*|
|* OBJECT__INJECT_2 : #define() : INJECT A FUNCTION POINTER WITH A FUNCTION   *|
|* object__inject_2 : #define() :                                             *|
|*..................:...........:.............................................*|
|* OBJECT__INJECT_3 : #define() : INJECT A FUNCTION POINTER WITH A FUNCTION   *|
|* object__inject_3 : #define() : IN AN OBJECT                                *|
|*..................:...........:.............................................*|
\******************************************************************************/

/*############################################################################*\
|*#                                  OBJECT                                  #*|
|*############################################################################*|
|*                                                                            *|
|* OBJECT IS A HIGH-PERFORMANCE C/C++ LIBRARY FOR OBJECT-ORIENTED PROGRAMMING *|
|* IN PURE C, PROVIDING DYNAMIC FUNCTION TABLES, FLEXIBLE OBJECT CREATION,    *|
|* AND OPTIMIZED CROSS-PLATFORM FUNCTION INJECTION.                           *|
|*                                                                            *|
|* -------------------------------------------------------------------------- *|
|*                                                                            *|
|* O - FEATURES                                                               *|
|* :                                                                          *|
|* :.., PURE C OBJECT-ORIENTED PROGRAMMING SUPPORT.                           *|
|* :                                                                          *|
|* :.., DYNAMIC FUNCTION TABLES FOR RUNTIME FUNCTION BINDING.                 *|
|* :                                                                          *|
|* :.., OPTIMIZED ASSEMBLY-LEVEL FUNCTION INJECTION FOR INTEL AND ARM CPUS.   *|
|* :                                                                          *|
|* :.., SUPPORTS 32-BIT AND 64-BIT SYSTEMS.                                   *|
|* :                                                                          *|
|* :.., COMPATIBLE WITH TI CGT/CCS COMPILERS, GCC, AND MSVC.                  *|
|* :                                                                          *|
|* :.., CROSS-PLATFORM MEMORY MANAGEMENT AND EXCEPTION HANDLING SUPPORT.      *|
|*                                                                            *|
|* -------------------------------------------------------------------------- *|
|*                                                                            *|
|* O - WHY USE OBJECT?                                                        *|
|* :                                                                          *|
|* :.., [PERFORMANCE]                                                         *|
|* :  :                                                                       *|
|* :  : USES INLINE ASSEMBLY TO DIRECTLY INJECT FUNCTIONS INTO OBJECTS.       *|
|* :                                                                          *|
|* :.., [FLEXIBILITY]                                                         *|
|* :  :                                                                       *|
|* :  : DYNAMICALLY BIND FUNCTIONS AT RUNTIME WITHOUT VIRTUAL TABLES.         *|
|* :                                                                          *|
|* :.., [PORTABILITY]                                                         *|
|* :  :                                                                       *|
|* :  : SUPPORTS MULTIPLE CPU ARCHITECTURES AND OS ENVIRONMENTS.              *|
|* :                                                                          *|
|* :.., [MEMORY EFFICIENCY]                                                   *|
|* :  :                                                                       *|
|* :  : OBJECTS ONLY ALLOCATE FUNCTION TABLES ONCE.                           *|
|* :                                                                          *|
|* :.., [ERROR HANDLING]                                                      *|
|*    :                                                                       *|
|*    : COMPATIBLE WITH `TRY/CATCH`-STYLE MACROS FOR SAFE OPERATIONS.         *|
|*                                                                            *|
|* -------------------------------------------------------------------------- *|
|*                                                                            *|
|* O - SETUP                                                                  *|
|* :                                                                          *|
|* : NOTE: SETUP PART IS OPTIONAL IF YOU'RE COMPILING YOUR PROGRAM IN         *|
|* : ARM32-BIT AND DEAILNG WITH main FUNCTION BY YOURSELF WITH LIKE           *|
|* : "#define main ..." OR "#define main(...) ..."                            *|
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
|* ;..,                                                                       *|
|*   1| #define SETUP_OBJECT                                                  *|
|*   2| #include "LIBCMT/OBJECT.h"                                            *|
|*   3|                                                                       *|
|*   4| int main() {                                                          *|
|*   5| ...                                                                   *|
|*   6| }                                                                     *|
|*    :                                                                       *|
|*                                                                            *|
|* -------------------------------------------------------------------------- *|
|*                                                                            *|
|* O - CONTENTS                                                               *|
|* :                                                                          *|
|* :.., OBJECT                                                                *|
|* :  :                                                                       *|
|* :  : IT SPECIFIES THAT THE STRUCTURE YOU CREATE IS AN OBJECT.              *|
|* :  :                                                                       *|
|* :  : IT PERFORMS THE SAME FUNCTION AS "STRUCT" AND MAKES NO PERFORMANCE    *|
|* :  : CHANGES.                                                              *|
|* :  :                                                                       *|
|* :  : IT SIMPLY WORKS AS `#define object struct`.                           *|
|* :  :                                                                       *|
|* :  : USE IT LIKE:                                                          *|
|* : 1| object o_test                                                         *|
|* : 2| {                                                                     *|
|* : 3|     i_am_an_object;                                                   *|
|* : 4|     ...                                                               *|
|* : 5| };                                                                    *|
|* :  :                                                                       *|
|* :                                                                          *|
|* :.., NEW (NAME, VAR) (...)                                                 *|
|* :  :                                                                       *|
|* :  : INSTANTIATES AN OBJECT AND RUNS OBJECT'S CONSTRUCTOR.                 *|
|* :  :                                                                       *|
|* :  : AFTER YOU CREATED THE OBJECT WITH `new`, DON'T FORGET TO DELETE IT    *|
|* :  : WITH `destroy`.                                                       *|
|* :  :                                                                       *|
|* :  : USAGE:                                                                *|
|* : 1| new (o_object_type, ObjectName) (constructor_parameters_if_have_any); *|
|* : 2|                                                                       *|
|* : 3| ObjectName.call_a_function(42);                                       *|
|* : 4|                                                                       *|
|* : 5| destroy (ObjectName);                                                 *|
|* :  :                                                                       *|
|* :  : SUGGESTED MACRO FOR ERGONOMICS:                                       *|
|* : 1| #define test(OBJECT_VAR) new (o_test, OBJECT_VAR)                     *|
|* : 2|                                                                       *|
|* : 3| test (obj) (...);                                                     *|
|* :  :                                                                       *|
|* :                                                                          *|
|* :.., DESTROY (OBJECT)                                                      *|
|* :  :                                                                       *|
|* :  : CLEARS THE MEMORY OF HTE CREATED OBJECT IF OBJECT IS SUCCESSFULLY     *|
|* :  : CREATED.                                                              *|
|* :  :                                                                       *|
|* :  : USAGE:                                                                *|
|* : 1| new (o_object_type, ObjectName) (constructor_parameters_if_have_any); *|
|* : 2|                                                                       *|
|* : 3| ObjectName.call_a_function(42);                                       *|
|* : 4|                                                                       *|
|* : 5| destroy (ObjectName);                                                 *|
|* :  :                                                                       *|
|* :                                                                          *|
|* :.., I_AM_AN_OBJECT                                                        *|
|* :  :                                                                       *|
|* :  : DECLARES THE FUNCTION POINTER STORAGE FOR AN OBJECT.                  *|
|* :  : YOU MUST PUT THIS FLAG ON TOP OF THE STRUCT!!!                        *|
|* :  :                                                                       *|
|* : 1| struct s_object                                                       *|
|* : 2| {                                                                     *|
|* : 3|     i_am_an_object;                                                   *|
|* : 4|     ...                                                               *|
|* : 5| };                                                                    *|
|* :  :                                                                       *|
|* :                                                                          *|
|* :.., OBJECT__INJECT(MEMBER)                                                *|
|* :  :                                                                       *|
|* :  : BINDS AN OBJECT FUNCTION POINTER MEMBER TO A FUNCTION WITH SAME NAME. *|
|* :  : USEFUL WHEN YOUR FUNCTION NAME MATCHES THE MEMBER NAME.               *|
|* :  :                                                                       *|
|* :  : IT AUTOMATICALLY CONNECTS `this->MEMBER = MEMBER;`                    *|
|* :  :                                                                       *|
|* :  : EXAMPLE (INSIDE CONSTRUCTOR):                                         *|
|* : 1| static void test_object_type(void)                                    *|
|* : 2| {                                                                     *|
|* : 3|     object__connect (test_object_type);                               *|
|* : 4|                                                                       *|
|* : 5|     object__inject (FUNC_A);                                          *|
|* : 6|     object__inject (FUNC_B);                                          *|
|* : 7| }                                                                     *|
|* :  :                                                                       *|
|* :  : MEANS:                                                                *|
|* : 1| this->FUNC_A = FUNC_A;                                                *|
|* : 2| this->FUNC_B = FUNC_B;                                                *|
|* :  :                                                                       *|
|* :                                                                          *|
|* :.., OBJECT__INJECT_2(MEMBER, FUNCTION)                                    *|
|* :  :                                                                       *|
|* :  : BINDS AN OBJECT FUNCTION POINTER MEMBER TO A SPECIFIC FUNCTION NAME.  *|
|* :  : USE THIS WHEN YOUR FUNCTION NAME AND MEMBER NAME ARE DIFFERENT.       *|
|* :  :                                                                       *|
|* :  : EXAMPLE (INSIDE CONSTRUCTOR):                                         *|
|* : 1| static void test_object_type(void)                                    *|
|* : 2| {                                                                     *|
|* : 3|     object__connect (test_object_type);                               *|
|* : 4|                                                                       *|
|* : 5|     object__inject_2 (FUNC_A, impl_func_a);                           *|
|* : 6|     object__inject_2 (FUNC_B, impl_func_b);                           *|
|* : 7| }                                                                     *|
|* :  :                                                                       *|
|* :  : MEANS:                                                                *|
|* : 1| this->FUNC_A = impl_func_a;                                           *|
|* : 2| this->FUNC_B = impl_func_b;                                           *|
|* :  :                                                                       *|
|* :                                                                          *|
|* :.., OBJECT__INJECT_3(MEMBER, FUNCTION, OBJECT_PTR)                        *|
|* :  :                                                                       *|
|* :  : BINDS AN OBJECT FUNCTION POINTER MEMBER TO A SPECIFIC FUNCTION,       *|
|* :  : USING A SPECIFIC OBJECT INSTANCE POINTER.                             *|
|* :  :                                                                       *|
|* :  : USE THIS WHEN YOU WANT TO INJECT A FUNCTION INTO A PARTICULAR OBJECT. *|
|* :  :                                                                       *|
|* :  : EXAMPLE (INSIDE CONSTRUCTOR OR SETUP FUNCTION):                       *|
|* : 1| static void test_object_type(void)                                    *|
|* : 2| {                                                                     *|
|* : 3|     object__connect (test_object_type);                               *|
|* : 4|                                                                       *|
|* : 5|     object__inject_3(FUNC_A, impl_func_a, this);                      *|
|* : 6|     object__inject_3(FUNC_B, impl_func_b, this);                      *|
|* : 7| }                                                                     *|
|* :  :                                                                       *|
|* :  : MEANS:                                                                *|
|* : 1| this->FUNC_A = impl_func_a;                                           *|
|* : 2| this->FUNC_B = impl_func_b;                                           *|
|* :  :                                                                       *|
|* :                                                                          *|
|* :.., OBJECT__READY(OBJECT)                                                 *|
|* :  :                                                                       *|
|* :  : SOMETIMES YOU MAY WANT TO CHECK IF AN OBJECT IS PROPERLY CREATED      *|
|* :  : BEFORE USING IT. USE `object__ready()` FOR SAFE VALIDATION.           *|
|* :  :                                                                       *|
|* :  : IT RETURNS (int)1 IF OBJECT IS VALID AND ALLOCATED, ELSE 0.           *|
|* :  :                                                                       *|
|* :  : EXAMPLE:                                                              *|
|* :  :                                                                       *|
|* : 1| new (test_object_type, OBJ) ();                                       *|
|* : 2|                                                                       *|
|* : 3| if (object__ready(OBJ))                                               *|
|* : 4| {                                                                     *|
|* : 5|     OBJ.FUNC1();                                                      *|
|* : 6|     OBJ.FUNC2();                                                      *|
|* : 7|                                                                       *|
|* : 8|     destroy (OBJ);                                                    *|
|* : 9| }                                                                     *|
|* :10| else                                                                  *|
|* :11| {                                                                     *|
|* :12|     printf("Object not ready!\n");                                    *|
|* :13| }                                                                     *|
|* :  :                                                                       *|
|* :                                                                          *|
|* :.., OBJECT__CONNECT(STRUCT_NAME)                                          *|
|*    :                                                                       *|
|*    : CONNECTS AN OBJECT STRUCTURE POINTER (THIS) TO ITS INSTANCE.          *|
|*    :                                                                       *|
|*    : JUST PUT THIS MACRO AT THE TOP OF YOUR FUNCTION BLOCK.                *|
|*    :                                                                       *|
|*   1| void function_1()                                                     *|
|*   2| {                                                                     *|
|*   3|     object__connect(s_struct);                                        *|
|*   4|                                                                       *|
|*   5|     // this                                                           *|
|*   6|     ...                                                               *|
|*   7| }                                                                     *|
|*    :                                                                       *|
|*    : OR, IF YOU USE UPPERCASE VERSION, YOU'LL NEED TO USE:                 *|
|*    :                                                                       *|
|*   1| void function_1()                                                     *|
|*   2| {                                                                     *|
|*   3|     OBJECT__CONNECT(s_struct);                                        *|
|*   4|                                                                       *|
|*   5|     // THIS                                                           *|
|*   6|     ...                                                               *|
|*   7| }                                                                     *|
|*    :                                                                       *|
|*                                                                            *|
|* -------------------------------------------------------------------------- *|
|*                                                                            *|
|* O - SOME EXAMPLES                                                          *|
|* :                                                                          *|
|* : object test_object_type                                                  *|
|* : {                                                                        *|
|* :     i_am_an_object;                                                      *|
|* :                                                                          *|
|* :     void (*worked)(int);                                                 *|
|* :     int value;                                                           *|
|* : };                                                                       *|
|* :                                                                          *|
|* : extern void o_worked(int);                                               *|
|* :                                                                          *|
|* : static void test_object_type(void)                                       *|
|* : {                                                                        *|
|* :     object__connect (test_object_type);                                  *|
|* :      object__inject (worked, o_worked);                                  *|
|* :                                                                          *|
|* :     this->value = 0;                                                     *|
|* : }                                                                        *|
|* :                                                                          *|
|* : void o_worked(int n)                                                     *|
|* : {                                                                        *|
|* :     object__connect (test_object_type);                                  *|
|* :                                                                          *|
|* :     this->value += n;                                                    *|
|* : }                                                                        *|
|*                                                                            *|
|* O - USAGE                                                                  *|
|* :                                                                          *|
|* : new (test_object_type, obj) (); // CONSTRUCTOR CALLED                    *|
|* : obj.worked(42); // uses implicit "THIS"                                  *|
|* : destroy (obj);                                                           *|
|*                                                                            *|
|* O - MULTIPLE OBJECTS EXAMPLE                                               *|
|* :                                                                          *|
|* : new (test_object_type, test1) ();                                        *|
|* : new (test_object_type, test2) ();                                        *|
|* :                                                                          *|
|* : test1.worked(42);                                                        *|
|* : test1.worked(42);                                                        *|
|* : test2.worked(42);                                                        *|
|* : test1.worked(42);                                                        *|
|* : test2.worked(42);                                                        *|
|* :                                                                          *|
|* : destroy (test1);                                                         *|
|* : destroy (test2);                                                         *|
|*                                                                            *|
|* O - FULL EXAMPLE                                                           *|
|* :                                                                          *|
|* ;.., CONNECTING YOUR OBJECT TO YOUR FUNCTIONS                              *|
|* :  :                                                                       *|
|* :  : object test_object_type                                               *|
|* :  : {                                                                     *|
|* :  :     i_am_an_object;                                                   *|
|* :  :                                                                       *|
|* :  :     int (*FUNC1)();                                                   *|
|* :  :     void (*FUNC2)();                                                  *|
|* :  :     void (*FUNC3)();                                                  *|
|* :  :                                                                       *|
|* :  :     int a;                                                            *|
|* :  : };                                                                    *|
|* :  :                                                                       *|
|* :  : static int O_FUNC1()                                                  *|
|* :  : {                                                                     *|
|* :  :     object__connect (test_object_type);                               *|
|* :  :                                                                       *|
|* :  :     printf("1\n");                                                    *|
|* :  :     return (42);                                                      *|
|* :  : }                                                                     *|
|* :  :                                                                       *|
|* :  : static void O_FUNC2()                                                 *|
|* :  : {                                                                     *|
|* :  :     object__connect (test_object_type);                               *|
|* :  :                                                                       *|
|* :  :     printf("2\n");                                                    *|
|* :  : }                                                                     *|
|* :  :                                                                       *|
|* :  : static void FUNC3()                                                   *|
|* :  : {                                                                     *|
|* :  :     object__connect (test_object_type);                               *|
|* :  :                                                                       *|
|* :  :     printf("3\n");                                                    *|
|* :  : }                                                                     *|
|* :  :                                                                       *|
|* :  : static void test_object_type()                                        *|
|* :  : {                                                                     *|
|* :  :     object__connect (test_object_type);                               *|
|* :  :     object__inject_2 (FUNC1, O_FUNC1);                                *|
|* :  :     object__inject_2 (FUNC2, O_FUNC2);                                *|
|* :  :     object__inject (FUNC3);                                           *|
|* :  :                                                                       *|
|* :  :     printf("0\n");                                                    *|
|* :  : }                                                                     *|
|* :                                                                          *|
|* ;.., CREATING AND USING OBJECTS                                            *|
|*    :                                                                       *|
|*    : int main(void)                                                        *|
|*    : {                                                                     *|
|*    :     {                                                                 *|
|*    :         new (test_object_type, TEST) ();                              *|
|*    :                                                                       *|
|*    :         TEST.FUNC1();                                                 *|
|*    :         TEST.FUNC2();                                                 *|
|*    :         TEST.FUNC3();                                                 *|
|*    :                                                                       *|
|*    :         destroy (TEST);                                               *|
|*    :     }                                                                 *|
|*    :                                                                       *|
|*    :     {                                                                 *|
|*    :         new (test_object_type, TEST1) ();                             *|
|*    :         new (test_object_type, TEST2) ();                             *|
|*    :                                                                       *|
|*    :         TEST1.FUNC1();                                                *|
|*    :         TEST1.FUNC2();                                                *|
|*    :                                                                       *|
|*    :         TEST2.FUNC1();                                                *|
|*    :         TEST2.FUNC2();                                                *|
|*    :                                                                       *|
|*    :         TEST1.FUNC1();                                                *|
|*    :         TEST2.FUNC1();                                                *|
|*    :                                                                       *|
|*    :         printf("%d\n", TEST1.FUNC1());                                *|
|*    :                                                                       *|
|*    :         destroy (TEST1);                                              *|
|*    :         destroy (TEST2);                                              *|
|*    :     }                                                                 *|
|*    :                                                                       *|
|*    :     return (0);                                                       *|
|*    : }                                                                     *|
|*                                                                            *|
\******************************************************************************/

/*############################################################################*\
|*#                                SIDE NOTES                                #*|
|*############################################################################*|
|*                                                                            *|
|* IF YOU TRY TO USE THIS SYSTEM ON DEVICES LIKE 8051, PIC, MSP430, ETC.,     *|
|* THIS APPROACH CAN BLOAT MEMORY QUICKLY. THEREFORE, PLEASE CONSIDER USING   *|
|* THIS SYSTEM ONLY ON DEVICES WITH MORE THAN 64KB OF RAM.                    *|
|*                                                                            *|
\******************************************************************************/

/* ****************************** [v] C++ [v] ******************************* */
#ifdef __cplusplus /* C++ */
#	error "PLEASE USE CLASSES IN C++!!!"
#endif /* __cplusplus */
/* ****************************** [^] C++ [^] ******************************* */

#ifndef OBJECT_H
#	define OBJECT_H 202510 /* VERSION */

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
#	include <stddef.h> /*
#	typedef size_t;
#	        */
#	include "./KEYWORDS/LOCAL.h" /*
#	 define LOCAL
#	        */
#	include "./KEYWORDS/INLINE.h" /*
#	 define INLINE
#	        */
#	include "./ENVIRONMENTS/KNR_STYLE.h" /*
#	 define KNR_STYLE
#	        */
#	include "./ENVIRONMENTS/CPU.h" /*
#	 define __CPU_INTEL__
#	 define __CPU_ARM__
#	        */
#	include "./ENVIRONMENTS/ARCHITECTURE.h" /*
#	 define __SYSTEM_64_BIT__
#	 define __SYSTEM_32_BIT__
#	        */
#	include "./ASM//INTEL/RAX.h" /*
#	 define GET_RAX(VAR)
#	        */
#	include "./ASM//ARM/X17.h" /*
#	 define GET_X17(VAR)
#	        */
/* **************************** [^] INCLUDES [^] **************************** */

#	ifdef __unix__
#		ifndef KNR_STYLE /* STANDARD C */
extern void	*mmap(void *, size_t, int, int, int, int);
extern int	mprotect(void *, size_t, int);
extern int	munmap(void *, size_t); 
#		else /* K&R */
extern void	*mmap();
extern int	mprotect();
extern int	munmap();
#		endif /* !KNR_STYLE */
#		define LOCALMACRO__FUNCTION_AREA_ALLOCATOR(SIZE) \
			(unsigned char *)mmap(((void *)0), SIZE, 7, 34, -1, 0)
#		define LOCALMACRO__PROTECT_FUNCTION_AREA(FUNCTIONS) \
			mprotect(FUNCTIONS, 4096, 5)
#		define LOCALMACRO__FAILED_TO_ALLOCATE ((unsigned char *)-1)
#		define DESTROY(THE_OBJECT) \
			munmap(\
				(THE_OBJECT).__OBJECT_HEADER__.FUNCTIONS,\
				((size_t *)&(THE_OBJECT))[2]\
			);\
			(THE_OBJECT).__OBJECT_HEADER__.FUNCTIONS = (void *)0
#	else
#		ifdef _WIN32
#			ifndef KNR_STYLE /* STANDARD C */
extern void	*VirtualAlloc(void *, size_t, unsigned long, unsigned long);
extern int	VirtualFree(void *, size_t, unsigned long);
#			else /* K&R */
extern void			*VirtualAlloc();
extern unsigned int	VirtualFree();
#			endif /* !KNR_STYLE */
#			define LOCALMACRO__FUNCTION_AREA_ALLOCATOR(SIZE) \
				(unsigned char *)VirtualAlloc(((void *)0), SIZE, 12288, 64)
#			define LOCALMACRO__PROTECT_FUNCTION_AREA(FUNCTIONS)
#			define LOCALMACRO__FAILED_TO_ALLOCATE ((unsigned char *)0)
#			define DESTROY(THE_OBJECT) \
				VirtualFree(\
					(THE_OBJECT).__OBJECT_HEADER__.FUNCTIONS,\
					0,\
					32768\
				);\
				(THE_OBJECT).__OBJECT_HEADER__.FUNCTIONS = (void *)0
#		endif /* _WIN32 */
#	endif /* __unix__ */

#	define OBJECT struct

#	define I_AM_AN_OBJECT \
		OBJECT __OBJECT_HEADER__\
		{\
			void	*TEMP;\
			void	*FUNCTIONS;\
			void	*SIZE;\
		}	__OBJECT_HEADER__

#	define OBJECT__READY(OBJECT_STRUCT) \
		(*((void **)&(OBJECT_STRUCT)) != (void *)0)

#	ifdef __CPU_ARM__
#		ifdef __SYSTEM_64_BIT__
#			define OBJECT__CONNECT(OBJECT_STRUCT_TYPE) \
				register void			*LOCALMACRO__SELF__;\
				GET_X17(LOCALMACRO__SELF__);\
				OBJECT OBJECT_STRUCT_TYPE	*const THIS = \
					(OBJECT OBJECT_STRUCT_TYPE *)LOCALMACRO__SELF__
#			define object__connect(OBJECT_STRUCT_TYPE) \
				register void			*LOCALMACRO__SELF__;\
				GET_X17(LOCALMACRO__SELF__);\
				OBJECT OBJECT_STRUCT_TYPE	*const this = \
					(OBJECT OBJECT_STRUCT_TYPE *)LOCALMACRO__SELF__
#		endif /* __SYSTEM_64_BIT__ */
#		ifdef __SYSTEM_32_BIT__
#			define OBJECT__CONNECT(OBJECT_STRUCT_TYPE) \
				OBJECT OBJECT_STRUCT_TYPE	*const THIS = \
					(OBJECT OBJECT_STRUCT_TYPE *)__OBJECT_STRUCTURE_POINTER__
#			define object__connect(OBJECT_STRUCT_TYPE) \
				OBJECT OBJECT_STRUCT_TYPE	*const this = \
					(OBJECT OBJECT_STRUCT_TYPE *)__OBJECT_STRUCTURE_POINTER__
#		endif /* __SYSTEM_32_BIT__ */
#	else
#		ifdef __CPU_INTEL__
#			define OBJECT__CONNECT(OBJECT_STRUCT_TYPE) \
				register void			*LOCALMACRO__SELF__;\
				GET_RAX(LOCALMACRO__SELF__);\
				OBJECT OBJECT_STRUCT_TYPE	*const THIS = \
					(OBJECT OBJECT_STRUCT_TYPE *)LOCALMACRO__SELF__
#			define object__connect(OBJECT_STRUCT_TYPE) \
				register void			*LOCALMACRO__SELF__;\
				GET_RAX(LOCALMACRO__SELF__);\
				OBJECT OBJECT_STRUCT_TYPE	*const this = \
					(OBJECT OBJECT_STRUCT_TYPE *)LOCALMACRO__SELF__
#		endif /* __CPU_INTEL__ */
#	endif /* __CPU_ARM__ */

#	define NEW(OBJECT_NAME, VARIABLE_NAME) \
		OBJECT OBJECT_NAME	VARIABLE_NAME;\
		extern void			OBJECT_NAME();\
		\
		while (1)\
		{\
			(VARIABLE_NAME).__OBJECT_HEADER__.TEMP = (void *)(\
				(\
					(\
						sizeof(OBJECT OBJECT_NAME) - \
						(3 * sizeof(void *))\
					) / sizeof(void *)) + 1\
			);\
			\
			{\
				register unsigned char	*FUNCTIONS;\
				\
				(VARIABLE_NAME).__OBJECT_HEADER__.SIZE = \
					(VARIABLE_NAME).__OBJECT_HEADER__.TEMP;\
				FUNCTIONS = LOCALMACRO__FUNCTION_AREA_ALLOCATOR(\
					((size_t)(VARIABLE_NAME).__OBJECT_HEADER__.TEMP) << 12\
				);\
				\
				if (FUNCTIONS == LOCALMACRO__FAILED_TO_ALLOCATE)\
				{\
					(VARIABLE_NAME).__OBJECT_HEADER__.FUNCTIONS = (void *)0;\
					break ;\
				}\
				\
				(VARIABLE_NAME).__OBJECT_HEADER__.FUNCTIONS = \
					(void *)FUNCTIONS;\
			}\
			\
			break ;\
		}\
		\
		if ((VARIABLE_NAME).__OBJECT_HEADER__.FUNCTIONS)\
			(\
				(void (*)())LOCALMACRO__OBJECT_INJECTOR(\
					&(VARIABLE_NAME),\
					OBJECT_NAME,\
					(void *)0\
				)\
			)

#	define OBJECT__INJECT_3(TARGET, SOURCE, OBJECT_PTR) \
		THIS->TARGET = LOCALMACRO__OBJECT_INJECTOR(\
			THIS,\
			SOURCE,\
			(unsigned char *)&THIS->TARGET\
		)
#	define object__inject_3(TARGET, SOURCE, OBJECT_PTR) \
		OBJECT_PTR->TARGET = LOCALMACRO__OBJECT_INJECTOR(\
			OBJECT_PTR,\
			SOURCE,\
			(unsigned char *)&OBJECT_PTR->TARGET\
		)

#	define OBJECT__INJECT_2(TARGET, SOURCE) \
		OBJECT__INJECT_3(TARGET, SOURCE, THIS)
#	define object__inject_2(TARGET, SOURCE) \
		object__inject_3(TARGET, SOURCE, this)

#	define OBJECT__INJECT(TARGET, SOURCE) \
		OBJECT__INJECT_2(TARGET, TARGET)
#	define object__inject(TARGET) \
		object__inject_2(TARGET, TARGET)

/* ************************ [v] GLOBAL VARIABLES [v] ************************ */
#	ifdef __CPU_ARM__
#		ifdef __SYSTEM_32_BIT__ /* BEHOLD! THE ENEMY OF THE REGISTERS!!! */
#			ifdef SETUP_OBJECT
LOCAL void	*__OBJECT_STRUCTURE_POINTER__ = (void *)0;
#			else /* CREATE GLOBAL VARIABLES AUTOMATICALLY */
#				ifdef main
#					undef main
#				endif /* main */
#				ifdef WinMain
#					undef WinMain
#				endif /* main */
#				ifdef LOCALMACRO__VA_ARGS_GLOBAL_VARIABLES
#					define LOCALMACRO__OBJECT__VA_ARGS_GLOBAL_VARIABLES \
						LOCALMACRO__VA_ARGS_GLOBAL_VARIABLES
#				else
#					define LOCALMACRO__OBJECT__VA_ARGS_GLOBAL_VARIABLES
#				endif /* LOCALMACRO__VA_ARGS_GLOBAL_VARIABLES */
#				ifdef LOCALMACRO__TRY_CATCH_GLOBAL_VARIABLES
#					define LOCALMACRO__OBJECT__TRY_CATCH_GLOBAL_VARIABLES \
						LOCALMACRO__TRY_CATCH_GLOBAL_VARIABLES
#				else
#					define LOCALMACRO__OBJECT__TRY_CATCH_GLOBAL_VARIABLES
#				endif /* LOCALMACRO__TRY_CATCH_GLOBAL_VARIABLES */
#				define LOCALMACRO__OBJECT_GLOBAL_VARIABLES \
					LOCAL void	*__OBJECT_STRUCTURE_POINTER__ = (void *)0;
#				define main \
					__IDLE__TRY_CATCH; \
					LOCALMACRO__OBJECT__TRY_CATCH_GLOBAL_VARIABLES \
					LOCALMACRO__OBJECT__VA_ARGS_GLOBAL_VARIABLES \
					LOCALMACRO__OBJECT_GLOBAL_VARIABLES \
					int main
#				define WinMain \
					__IDLE__TRY_CATCH; \
					LOCALMACRO__OBJECT__TRY_CATCH_GLOBAL_VARIABLES \
					LOCALMACRO__OBJECT__VA_ARGS_GLOBAL_VARIABLES \
					LOCALMACRO__OBJECT_GLOBAL_VARIABLES \
					int WINAPI WinMain
#			endif /* SETUP_OBJECT */
extern LOCAL void	*__OBJECT_STRUCTURE_POINTER__;
#		endif /* __SYSTEM_32_BIT__ */
#	endif /* __CPU_ARM__ */
/* ************************ [^] GLOBAL VARIABLES [^] ************************ */

#	ifndef KNR_STYLE /* STANDARD C */
static INLINE void
	*LOCALMACRO__OBJECT_INJECTOR(
	void *SELF,
	void *TARGET,
	unsigned char *INDEX_ADDRESS
)
#	else /* K&R */
static INLINE void
	*LOCALMACRO__OBJECT_INJECTOR(SELF, TARGET, INDEX_ADDRESS)
	void			*SELF;
	void			*TARGET;
	unsigned char	*INDEX_ADDRESS;
#	endif /* !KNR_STYLE */
{
	register unsigned char	*RESULT;
	register unsigned char	*_;

	if (INDEX_ADDRESS)
	{
		register unsigned int	INDEX;

		INDEX = (int)(
			(void **)(
				INDEX_ADDRESS - (sizeof(void *) * 3)
			) - (void **)SELF
		) + 1;
		_ = (unsigned char *)&(((unsigned char **)SELF)[1][INDEX << 12]);
	}
	else
		_ = (unsigned char *)&(((unsigned char **)SELF)[1][0]);

	RESULT = _;

#	ifdef __CPU_INTEL__
#		ifdef __SYSTEM_64_BIT__
	register unsigned long long	VALUE;

	_ [ 0] = 0X48; // MOVABS
	_ [ 1] = 0XB8; // RAX,
	VALUE = (unsigned long long)SELF; // IMM64
	_ [ 2] = VALUE & 0XFF;
	_ [ 3] = (VALUE >> 8) & 0XFF;
	_ [ 4] = (VALUE >> 16) & 0XFF;
	_ [ 5] = (VALUE >> 24) & 0XFF;
	_ [ 6] = (VALUE >> 32) & 0XFF;
	_ [ 7] = (VALUE >> 40) & 0XFF;
	_ [ 8] = (VALUE >> 48) & 0XFF;
	_ [ 9] = (VALUE >> 56) & 0XFF;
	_ [10] = 0XC7; // MOV
	_ [11] = 0X00; // DWORD PTR [RAX],
	VALUE = (unsigned long long)TARGET;
	_ [12] = VALUE & 0XFF; // IMM32;
	_ [13] = (VALUE >> 8) & 0XFF;
	_ [14] = (VALUE >> 16) & 0XFF;
	_ [15] = (VALUE >> 24) & 0XFF;
	_ [16] = 0XC7; // MOV
	_ [17] = 0X40; // DWORD PTR [RAX
	_ [18] = 0X04; // + 4],
	_ [19] = (VALUE >> 32) & 0XFF; // IMM32 + 4;
	_ [20] = (VALUE >> 40) & 0XFF;
	_ [21] = (VALUE >> 48) & 0XFF;
	_ [22] = (VALUE >> 56) & 0XFF;
	_ [23] = 0XFF; // JMP
	_ [24] = 0X20; // [RAX];
#	else
#		ifdef __SYSTEM_32_BIT__
	register unsigned int	VALUE;

	_ [ 0] = 0XB8; // MOV EAX,
	VALUE = (unsigned int)SELF;
	_ [ 1] = VALUE & 0XFF;
	_ [ 2] = (VALUE >> 8) & 0XFF;
	_ [ 3] = (VALUE >> 16) & 0XFF;
	_ [ 4] = (VALUE >> 24) & 0XFF;
	_ [ 5] = 0XC7; // MOV,
	_ [ 6] = 0X00; // DWORD PTR [EAX],
	VALUE = (unsigned int)TARGET;
	_ [ 7] = VALUE & 0XFF;
	_ [ 8] = (VALUE >> 8) & 0XFF;
	_ [ 9] = (VALUE >> 16) & 0XFF;
	_ [10] = (VALUE >> 24) & 0XFF;
	_ [11] = 0XFF; // JMP
	_ [12] = 0X20; // [EAX];
#			endif /* __SYSTEM_32_BIT__ */
#		endif /* __SYSTEM_64_BIT__ */
#	endif /* __CPU_INTEL__ */

#ifdef __CPU_ARM__
	register int				INDEX;

#	ifdef __SYSTEM_64_BIT__
	register unsigned long long	VALUE;

	_ [ 0] = 0XB1;
	_ [ 1] = 0X00;
	_ [ 2] = 0X00;
	_ [ 3] = 0X58; // LDR X17, #IMM (SELF)
	_ [ 4] = 0XB0;
	_ [ 5] = 0X00;
	_ [ 6] = 0X00;
	_ [ 7] = 0X58; // LDR X16, #IMM (TARGET)
	_ [ 8] = 0X00;
	_ [ 9] = 0X02;
	_ [10] = 0X1F;
	_ [11] = 0XD6; // BR X16
	VALUE = (unsigned long long)SELF; // IMM64
	_ [12] = (VALUE & 0XFF);
	_ [13] = (VALUE >> 8) & 0XFF;
	_ [14] = (VALUE >> 16) & 0XFF;
	_ [15] = (VALUE >> 24) & 0XFF;
	_ [16] = (VALUE >> 32) & 0XFF;
	_ [17] = (VALUE >> 40) & 0XFF;
	_ [18] = (VALUE >> 48) & 0XFF;
	_ [19] = (VALUE >> 56) & 0XFF;
	VALUE = (unsigned long long)TARGET; // IMM64
	_ [20] = (VALUE & 0XFF);
	_ [21] = (VALUE >> 8) & 0XFF;
	_ [22] = (VALUE >> 16) & 0XFF;
	_ [23] = (VALUE >> 24) & 0XFF;
	_ [24] = (VALUE >> 32) & 0XFF;
	_ [25] = (VALUE >> 40) & 0XFF;
	_ [26] = (VALUE >> 48) & 0XFF;
	_ [27] = (VALUE >> 56) & 0XFF;
#		else
#			ifdef __SYSTEM_32_BIT__
	register unsigned int	VALUE;

	_ [ 0] = 0X0C;
	_ [ 1] = 0X00;
	_ [ 2] = 0X9F;
	_ [ 3] = 0XE5; /* LDR R0, [PC, #12] */
	_ [ 4] = 0X0C;
	_ [ 5] = 0X10;
	_ [ 6] = 0X9F;
	_ [ 7] = 0XE5; /* LDR R1, [PC, #12] */
	_ [ 8] = 0X00;
	_ [ 9] = 0X00;
	_ [10] = 0X81;
	_ [11] = 0XE5; /* STR R0, [R1, #0] */
	_ [12] = 0X08;
	_ [13] = 0X00;
	_ [14] = 0X9F;
	_ [15] = 0XE5; /* LDR R0, [PC, #8] */
	_ [16] = 0X10;
	_ [17] = 0XFF;
	_ [18] = 0X2F;
	_ [19] = 0XE1; /* BX R0 */
	VALUE = (unsigned int)SELF; // IMM64
	_ [20] = (VALUE & 0XFF);
	_ [21] = (VALUE >> 8) & 0XFF;
	_ [22] = (VALUE >> 16) & 0XFF;
	_ [23] = (VALUE >> 24) & 0XFF;
	VALUE = (unsigned int)&__OBJECT_STRUCTURE_POINTER__; // IMM64
	_ [24] = (VALUE & 0XFF);
	_ [25] = (VALUE >> 8) & 0XFF;
	_ [26] = (VALUE >> 16) & 0XFF;
	_ [27] = (VALUE >> 24) & 0XFF;
	__ = (unsigned int)TARGET; // IMM64
	_ [28] = (VALUE & 0XFF);
	_ [29] = (VALUE >> 8) & 0XFF;
	_ [30] = (VALUE >> 16) & 0XFF;
	_ [31] = (VALUE >> 24) & 0XFF;
#			endif /* __SYSTEM_32_BIT__ */
#		endif /* __SYSTEM_64_BIT__ */
#	endif /* __CPU_ARM__ */

	LOCALMACRO__PROTECT_FUNCTION_AREA(RESULT);
	return (RESULT);
}

/* **************************** [v] LOWERCASE [v] *************************** */
#	define i_am_an_object I_AM_AN_OBJECT
#	define object OBJECT
#	define object__ready OBJECT__READY
#	define destroy DESTROY
#	define new NEW
/* **************************** [^] LOWERCASE [^] *************************** */

/* ************************ [v] TI CGT CCS (POP) [v] ************************ */
#	ifdef __TI_COMPILER_VERSION__
#		pragma diag_pop /* TI CGT CCS COMPILER DIRECTIVES */
#	endif /* __TI_COMPILER_VERSION__ */
/* ************************ [^] TI CGT CCS (POP) [^] ************************ */

#endif /* !OBJECT_H */
