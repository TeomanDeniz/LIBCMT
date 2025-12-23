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
# : License - GPL-3.0   :: Update - 2025/12/22 : #    ::::!!!1!!1!!!1!!!::     #
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
|*#                     COMPILER & LINKING INSTRUCTIONS                      #*|
|*############################################################################*|
|*                                                                            *|
|*  THIS TABLE IS FOR REALLY OLD COMPILERS. IGNORE THIS TABLE IF YOU'RE IN A  *|
|*                              MODERN COMPILER                               *|
|*                                                                            *|
|*____________________________________________________________________________*|
|* COMPILTER & TARGET |                 LINK / BUILD COMMAND                  *|
|*____________________|_______________________________________________________*|
|* GCC (WIN2000) 3.0  | GCC #.c C:\WINNT\system32\kernel32.dll                *|
|* GCC (WIN98) 3.0    | GCC #.c C:\WINNT\system32\kernel32.dll                *|
|* GCC (WIN95) 3.0    | GCC #.c C:\WINNT\system32\kernel32.dll                *|
|* GCC (DOS) 3.0?     | GCC #.c -ldjgpp                                       *|
\******************************************************************************/

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
|* :.., CLEANER SYNTAX THAN TYPICAL C++ ALTERNATIVES                          *|
|* :                                                                          *|
|* :.., ASSEMBLY-LEVEL FUNCTION INJECTION FOR PERFORMANCE OPTIMIZATIONS       *|
|* :                                                                          *|
|* :.., SUPPORTS 32-BIT AND 64-BIT SYSTEMS (LIKELY 16-BIT AS WELL).           *|
|* :                                                                          *|
|* :.., COMPATIBLE WITH TI CGT/CCS COMPILERS, GCC, AND MSVC.                  *|
|* :                                                                          *|
|* :.., DYNAMIC FUNCTION TABLES FOR MANUAL RUNTIME BINDING.                   *|
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
|*    :                                                                       *|
|*    : FUNCTION TABLES ARE ALLOCATED ONCE PER OBJECT.                        *|
|*                                                                            *|
|* -------------------------------------------------------------------------- *|
|*                                                                            *|
|*  O - SETUP                                                                 *|
|*  :                                                                         *|
|*  : NOTE: SETUP PART IS OPTIONAL IF YOU'RE COMPILING YOUR PROGRAM IN        *|
|*  : ARM 32-BIT AND NEVER USED THIS ADDON IN A C FILE THAT HAS "main()"      *|
|*  : FUNCTION. OTHERWISE, SKIP THE SETUP AND JUMP TO LINE 148 AT THE         *|
|*  : BOTTOM OF THIS FILE.                                                    *|
|*  :                                                                         *|
|*  : IF THE FILE DOES NOT CONTAIN main(), AND YOU STILL USE THE LIBRARY,     *|
|*  : THEN ONE SOURCE FILE SOMEWHERE MUST DEFINE "CMT_SETUP"                  *|
|*  :                                                                         *|
|*  : THIS ENSURES GLOBAL VARIABLES OR FUNCTIONS THAT ARE EXPOSED FOR LINKING *|
|*  : PROPERLY DEFINED.                                                       *|
|*  :                                                                         *|
|*  : AFTER THAT, YOU CAN INCLUDE THIS HEADER ANYWHERE ELSE WITHOUT DEFINING  *|
|*  : THE MACRO AGAIN; OTHER FILES WILL ONLY SEE EXTERN DECLARATIONS.         *|
|*  :                                                                         *|
|* 1| #define CMT_SETUP                                                       *|
|* 2| #include "CMT/OBJECT.H"                                                 *|
|*  :                                                                         *|
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
|* :  : INJECTS A FUNCTION WITH SAME NAME.                                    *|
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
|* :  : INJECTS A FUNCTION WITH A DIFFERENT NAME.                             *|
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
|* :.., OBJECT__INJECT_3(OBJECT_PTR, MEMBER, FUNCTION)                        *|
|* :  :                                                                       *|
|* :  : INJECT A FUNCTION POINTER WITH A FUNCTION INTO A SPECIFIC OBJECT      *|
|* :  : INSTANCE.                                                             *|
|* :  :                                                                       *|
|* :  : USE THIS WHEN YOU WANT TO INJECT A FUNCTION INTO A PARTICULAR OBJECT. *|
|* :  :                                                                       *|
|* :  : EXAMPLE (INSIDE CONSTRUCTOR OR SETUP FUNCTION):                       *|
|* : 1| static void test_object_type(void)                                    *|
|* : 2| {                                                                     *|
|* : 3|     object__connect (test_object_type);                               *|
|* : 4|                                                                       *|
|* : 5|     object__inject_3(this, FUNC_A, impl_func_a);                      *|
|* : 6|     object__inject_3(this, FUNC_B, impl_func_b);                      *|
|* : 7| }                                                                     *|
|* :  :                                                                       *|
|* :  : MEANS:                                                                *|
|* : 1| this->FUNC_A = impl_func_a;                                           *|
|* : 2| this->FUNC_B = impl_func_b;                                           *|
|* :  :                                                                       *|
|* :                                                                          *|
|* :..., OBJECT__READY(OBJECT)                                                *|
|* :   :                                                                      *|
|* :   : SOMETIMES YOU MAY WANT TO CHECK IF AN OBJECT IS PROPERLY CREATED     *|
|* :   : BEFORE USING IT. USE `object__ready()` FOR SAFE VALIDATION.          *|
|* :   :                                                                      *|
|* :   : IT RETURNS (int)1 IF OBJECT IS VALID AND ALLOCATED, ELSE 0.          *|
|* :   :                                                                      *|
|* :   : EXAMPLE:                                                             *|
|* :   :                                                                      *|
|* :  1| new (test_object_type, OBJ) ();                                      *|
|* :  2|                                                                      *|
|* :  3| if (object__ready(OBJ))                                              *|
|* :  4| {                                                                    *|
|* :  5|     OBJ.FUNC1();                                                     *|
|* :  6|     OBJ.FUNC2();                                                     *|
|* :  7|                                                                      *|
|* :  8|     destroy (OBJ);                                                   *|
|* :  9| }                                                                    *|
|* : 10| else                                                                 *|
|* : 11| {                                                                    *|
|* : 12|     printf("Object not ready!\n");                                   *|
|* : 13| }                                                                    *|
|* :   :                                                                      *|
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
|*   O - SOME EXAMPLES                                                        *|
|*   :                                                                        *|
|*  1| object test_object_type                                                *|
|*  2| {                                                                      *|
|*  3|     i_am_an_object;                                                    *|
|*  4|                                                                        *|
|*  5|     void (*worked)(int);                                               *|
|*  6|     int value;                                                         *|
|*  7| };                                                                     *|
|*  8|                                                                        *|
|*  9| extern void o_worked(int);                                             *|
|* 10|                                                                        *|
|* 11| static void test_object_type(void)                                     *|
|* 12| {                                                                      *|
|* 13|     object__connect (test_object_type);                                *|
|* 14|      object__inject (worked, o_worked);                                *|
|* 15|                                                                        *|
|* 16|     this->value = 0;                                                   *|
|* 17| }                                                                      *|
|* 18|                                                                        *|
|* 19| void o_worked(int n)                                                   *|
|* 20| {                                                                      *|
|* 21|     object__connect (test_object_type);                                *|
|* 22|                                                                        *|
|* 23|     this->value += n;                                                  *|
|* 24| }                                                                      *|
|*   :                                                                        *|
|*                                                                            *|
|*  O - USAGE                                                                 *|
|*  :                                                                         *|
|* 1| new (test_object_type, obj) (); // CONSTRUCTOR CALLED                   *|
|* 2| obj.worked(42); // uses implicit "THIS"                                 *|
|* 3| destroy (obj);                                                          *|
|*  :                                                                         *|
|*                                                                            *|
|*   O - MULTIPLE OBJECTS EXAMPLE                                             *|
|*   :                                                                        *|
|*  1| new (test_object_type, test1) ();                                      *|
|*  2| new (test_object_type, test2) ();                                      *|
|*  3|                                                                        *|
|*  4| test1.worked(42);                                                      *|
|*  5| test1.worked(42);                                                      *|
|*  6| test2.worked(42);                                                      *|
|*  7| test1.worked(42);                                                      *|
|*  8| test2.worked(42);                                                      *|
|*  9|                                                                        *|
|* 10| destroy (test1);                                                       *|
|* 11| destroy (test2);                                                       *|
|*   :                                                                        *|
|*                                                                            *|
|* O - FULL EXAMPLE                                                           *|
|* :                                                                          *|
|* ;..., CONNECTING YOUR OBJECT TO YOUR FUNCTIONS                             *|
|* :   :                                                                      *|
|* :  1| object test_object_type                                              *|
|* :  2| {                                                                    *|
|* :  3|     i_am_an_object;                                                  *|
|* :  4|                                                                      *|
|* :  5|     int (*FUNC1)();                                                  *|
|* :  6|     void (*FUNC2)();                                                 *|
|* :  7|     void (*FUNC3)();                                                 *|
|* :  8|                                                                      *|
|* :  9|     int a;                                                           *|
|* : 10| };                                                                   *|
|* : 11|                                                                      *|
|* : 12| static int O_FUNC1()                                                 *|
|* : 13| {                                                                    *|
|* : 14|     object__connect (test_object_type);                              *|
|* : 15|                                                                      *|
|* : 16|     printf("1\n");                                                   *|
|* : 17|     return (42);                                                     *|
|* : 18| }                                                                    *|
|* : 19|                                                                      *|
|* : 20| static void O_FUNC2()                                                *|
|* : 21| {                                                                    *|
|* : 22|     object__connect (test_object_type);                              *|
|* : 23|                                                                      *|
|* : 24|     printf("2\n");                                                   *|
|* : 25| }                                                                    *|
|* : 26|                                                                      *|
|* : 27| static void FUNC3()                                                  *|
|* : 28| {                                                                    *|
|* : 29|     object__connect (test_object_type);                              *|
|* : 30|                                                                      *|
|* : 31|     printf("3\n");                                                   *|
|* : 32| }                                                                    *|
|* : 33|                                                                      *|
|* : 34| static void test_object_type()                                       *|
|* : 35| {                                                                    *|
|* : 36|     object__connect (test_object_type);                              *|
|* : 37|     object__inject_2 (FUNC1, O_FUNC1);                               *|
|* : 38|     object__inject_2 (FUNC2, O_FUNC2);                               *|
|* : 39|     object__inject (FUNC3);                                          *|
|* : 40|                                                                      *|
|* : 41|     printf("0\n");                                                   *|
|* : 42| }                                                                    *|
|* :   :                                                                      *|
|* :                                                                          *|
|* ;.., CREATING AND USING OBJECTS                                            *|
|*    :                                                                       *|
|*   1| int main(void)                                                        *|
|*   2| {                                                                     *|
|*   3|     {                                                                 *|
|*   4|         new (test_object_type, TEST) ();                              *|
|*   5|                                                                       *|
|*   6|         TEST.FUNC1();                                                 *|
|*   7|         TEST.FUNC2();                                                 *|
|*   8|         TEST.FUNC3();                                                 *|
|*   9|                                                                       *|
|*  10|         destroy (TEST);                                               *|
|*  11|     }                                                                 *|
|*  12|                                                                       *|
|*  13|     {                                                                 *|
|*  14|         new (test_object_type, TEST1) ();                             *|
|*  15|         new (test_object_type, TEST2) ();                             *|
|*  16|                                                                       *|
|*  17|         TEST1.FUNC1();                                                *|
|*  18|         TEST1.FUNC2();                                                *|
|*  19|                                                                       *|
|*  20|         TEST2.FUNC1();                                                *|
|*  21|         TEST2.FUNC2();                                                *|
|*  22|                                                                       *|
|*  23|         TEST1.FUNC1();                                                *|
|*  24|         TEST2.FUNC1();                                                *|
|*  25|                                                                       *|
|*  26|         printf("%d\n", TEST1.FUNC1());                                *|
|*  27|                                                                       *|
|*  28|         destroy (TEST1);                                              *|
|*  29|         destroy (TEST2);                                              *|
|*  30|     }                                                                 *|
|*  31|                                                                       *|
|*  32|     return (0);                                                       *|
|*  33| }                                                                     *|
|*    :                                                                       *|
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
#	define OBJECT_H 202512 /* VERSION */

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
#	include "./ATTRIBUTES/FAR.H" /*
#	 define FAR
#	        */
#	include "./KEYWORDS/LOCAL.H" /*
#	 define LOCAL
#	        */
#	include "./KEYWORDS/INLINE.H" /*
#	 define INLINE
#	        */
#	include "./ENVIRONMENTS/KNR_STYLE.H" /*
#	 define KNR_STYLE
#	        */
#	include "./ENVIRONMENTS/CPU.H" /*
#	 define __CPU_INTEL__
#	 define __CPU_ARM__
#	        */
#	include "./ENVIRONMENTS/ARCHITECTURE.H" /*
#	 define __SYSTEM_64_BIT__
#	 define __SYSTEM_32_BIT__
#	        */
#	include "./ASM/INTEL/RAX.H" /*
#	 define GET_RAX(VAR)
#	        */
#	include "./ASM/ARM/X17.H" /*
#	 define GET_X17(VAR)
#	        */
#	include "./KEYWORDS/STDCALL.H" /*
#	 define STDCALL
#	        */
/* **************************** [^] INCLUDES [^] **************************** */

/* ********************** [v] CHECK FUNCTION SIZE [v] *********************** */
#	ifdef __CPU_INTEL__
#		ifdef __SYSTEM_64_BIT__
#			define LOCALMACRO__FUNCTION_SIZE 25
#		endif /* __SYSTEM_64_BIT__ */
#		ifdef __SYSTEM_32_BIT__
#			define LOCALMACRO__FUNCTION_SIZE 13
#		endif /* __SYSTEM_32_BIT__ */
#		ifdef __SYSTEM_16_BIT__
#			define LOCALMACRO__FUNCTION_SIZE 9
#		endif /* __SYSTEM_16_BIT__ */
#	endif /* __CPU_INTEL__ */
#	ifdef __CPU_ARM__
#		ifdef __SYSTEM_64_BIT__
#			define LOCALMACRO__FUNCTION_SIZE 28
#		endif /* __SYSTEM_64_BIT__ */
#		ifdef __SYSTEM_32_BIT__
#			define LOCALMACRO__FUNCTION_SIZE 32
#		endif /* __SYSTEM_32_BIT__ */
#	endif /* __CPU_ARM__ */
/* ********************** [^] CHECK FUNCTION SIZE [^] *********************** */

/* ***************************** [v] STRUCT [v] ***************************** */
struct __OBJECT_HEADER__
{
	void	*TEMP;
	void	*OP_CODES;
#	ifdef __unix__
	void	*SIZE;
#	endif /* __unix__ */
};
/* ***************************** [^] STRUCT [^] ***************************** */

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
#		define LOCALMACRO__FUNCTION_ALLOCATOR(VARIABLE_NAME, OBJECT_NAME) \
			register unsigned char	*OP_CODES;\
			\
			(VARIABLE_NAME).__OBJECT_HEADER__.SIZE = \
				(void *)(\
					(\
						(\
							sizeof(struct OBJECT_NAME) -\
							sizeof(struct __OBJECT_HEADER__)\
						) / sizeof(void *)\
					) * LOCALMACRO__FUNCTION_SIZE\
				);\
			OP_CODES = (unsigned char *)mmap(\
				((void *)0),\
				(size_t)(VARIABLE_NAME).__OBJECT_HEADER__.SIZE,\
				7,\
				34,\
				-1,\
				0\
			);\
			\
			if (OP_CODES == ((unsigned char *)-1))\
				(VARIABLE_NAME).__OBJECT_HEADER__.OP_CODES = (void *)0;\
			else\
			{\
				mprotect(\
					OP_CODES,\
					(size_t)(VARIABLE_NAME).__OBJECT_HEADER__.SIZE,\
					7\
				);\
				(VARIABLE_NAME).__OBJECT_HEADER__.OP_CODES = (void *)OP_CODES;\
			}
#		define DESTROY(THE_OBJECT) \
			munmap(\
				(THE_OBJECT).__OBJECT_HEADER__.OP_CODES,\
				(size_t)(THE_OBJECT).__OBJECT_HEADER__.SIZE\
			);\
			(THE_OBJECT).__OBJECT_HEADER__.OP_CODES = (void *)0
#	endif /* __unix__ */

#	ifndef LOCALMACRO__FUNCTION_ALLOCATOR
#		ifdef _WIN32
#			ifndef KNR_STYLE /* STANDARD C */
extern void	*STDCALL VirtualAlloc(void *, size_t, unsigned long, unsigned long);
extern int	STDCALL VirtualFree(void *, size_t, unsigned long);
#			else /* K&R */
extern char	*STDCALL VirtualAlloc();
extern int	 STDCALL VirtualFree();
#			endif /* !KNR_STYLE */
#			define LOCALMACRO__FUNCTION_ALLOCATOR(VARIABLE_NAME, OBJECT_NAME) \
				register unsigned char	*OP_CODES;\
				\
				OP_CODES = (unsigned char *)VirtualAlloc(\
					((void *)0),\
					(\
						(\
							sizeof(struct OBJECT_NAME) -\
							sizeof(struct __OBJECT_HEADER__)\
						) / sizeof(void *)\
					) * LOCALMACRO__FUNCTION_SIZE,\
					12288,\
					64\
				);\
				\
				if (OP_CODES == ((unsigned char *)0))\
					(VARIABLE_NAME).__OBJECT_HEADER__.OP_CODES = (void *)0;\
				else\
					(VARIABLE_NAME).__OBJECT_HEADER__.OP_CODES = \
						(void *)OP_CODES;
#			define DESTROY(THE_OBJECT) \
				do\
				{\
					VirtualFree(\
						(THE_OBJECT).__OBJECT_HEADER__.OP_CODES,\
						0,\
						32768\
					);\
					(THE_OBJECT).__OBJECT_HEADER__.OP_CODES = (void *)0;\
				}\
				while (0)
#		endif /* _WIN32 */
#	endif /* !LOCALMACRO__FUNCTION_ALLOCATOR */

#	ifndef LOCALMACRO__FUNCTION_ALLOCATOR
#		ifdef __DJGPP__
struct S_DPMI_MEMORY_INFO
{
	unsigned long	HANDLE;
	unsigned long	SIZE;
	unsigned long	ADDRESS;
};

#			ifndef KNR_STYLE /* STANDARD C */
extern int	__dpmi_allocate_memory(struct S_DPMI_MEMORY_INFO *);
extern int	__dpmi_free_memory(unsigned long);
#			else /* K&R */
extern int	__dpmi_allocate_memory();
extern int	__dpmi_free_memory();
#			endif /* !KNR_STYLE */
#			define LOCALMACRO__FUNCTION_ALLOCATOR(VARIABLE_NAME, OBJECT_NAME) \
				register unsigned char		*OP_CODES;\
				struct S_DPMI_MEMORY_INFO	OBJECT_MEMORY;\
				\
				OBJECT_MEMORY.SIZE = (\
					(
						sizeof(OBJECT OBJECT_NAME) - sizeof(__OBJECT_HEADER__)
					) / sizeof(void *)\
				) * LOCALMACRO__FUNCTION_SIZE;\
				OBJECT_MEMORY.HANDLE = 0;\
				\
				if (__dpmi_allocate_memory(&OBJECT_MEMORY))\
					OP_CODES = ((unsigned char *)-1);\
				else\
					OP_CODES = (unsigned char *)OBJECT_MEMORY.ADDRESS;\
				\
				if (OP_CODES == ((unsigned char *)-1))\
					(VARIABLE_NAME).__OBJECT_HEADER__.OP_CODES = (void *)0;\
				else\
					(VARIABLE_NAME).__OBJECT_HEADER__.OP_CODES = \
						(void *)OBJECT_MEMORY.HANDLE;
#			define DESTROY(THE_OBJECT) \
				__dpmi_free_memory((THE_OBJECT).__OBJECT_HEADER__.OP_CODES);\
				(THE_OBJECT).__OBJECT_HEADER__.OP_CODES = (void *)0
#		endif /* __DJGPP__ */
#	endif /* !LOCALMACRO__FUNCTION_ALLOCATOR */

#	define OBJECT struct
#	define I_AM_AN_OBJECT struct __OBJECT_HEADER__	__OBJECT_HEADER__
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
				register void				*LOCALMACRO__SELF__;\
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
		{\
			(VARIABLE_NAME).__OBJECT_HEADER__.TEMP = (void *)(\
				(\
					(\
						sizeof(OBJECT OBJECT_NAME) - (3 * sizeof(void *))\
					) / sizeof(void *)) + 1\
			);\
			LOCALMACRO__FUNCTION_ALLOCATOR(VARIABLE_NAME, OBJECT_NAME);\
		}\
		\
		if ((VARIABLE_NAME).__OBJECT_HEADER__.OP_CODES)\
			(\
				(void FAR (*)())LOCALFUNCTION__OBJECT_INJECTOR(\
					&(VARIABLE_NAME),\
					OBJECT_NAME,\
					(void *)0\
				)\
			)

#	define OBJECT__INJECT_3(OBJECT_PTR, TARGET, SOURCE) \
		THIS->TARGET = LOCALFUNCTION__OBJECT_INJECTOR(\
			THIS,\
			SOURCE,\
			(unsigned char *)&THIS->TARGET\
		)
#	define object__inject_3(OBJECT_PTR, TARGET, SOURCE) \
		OBJECT_PTR->TARGET = LOCALFUNCTION__OBJECT_INJECTOR(\
			OBJECT_PTR,\
			SOURCE,\
			(unsigned char *)&OBJECT_PTR->TARGET\
		)

#	define OBJECT__INJECT_2(TARGET, SOURCE) \
		OBJECT__INJECT_3(THIS, TARGET, SOURCE)
#	define object__inject_2(TARGET, SOURCE) \
		object__inject_3(this, TARGET, SOURCE)

#	define OBJECT__INJECT(TARGET) \
		OBJECT__INJECT_2(TARGET, TARGET)
#	define object__inject(TARGET) \
		object__inject_2(TARGET, TARGET)

/**@@@@@@@@@@@@@@@@@@@@@@@@@@@ [v] OTO-LINKER [v] @@@@@@@@@@@@@@@@@@@@@@@@@@@**\
|**@    HEADER-ONLY AUTO-INITIALIZER: NO MAKEFILES, NO .C FILES REQUIRED    @**|
|**@      INJECTS ALL NEEDED DEFINITIONS AND SETUP LOGIC AUTOMATICALLY      @**|
\**@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ OTO-LINKER @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@**/
#	ifdef __CPU_ARM__
#		ifdef __SYSTEM_32_BIT__ /* BEHOLD! THE ENEMY OF THE REGISTERS!!! */
/* *************************** [v] PROTOTYPES [v] *************************** */
extern LOCAL void	*__OBJECT_STRUCTURE_POINTER__;
/* *************************** [^] PROTOTYPES [^] *************************** */
#			define CMT_LOCAL__OBJECT \
				LOCAL void	*__OBJECT_STRUCTURE_POINTER__ = (void *)0
#			ifdef CMT_SETUP
CMT_LOCAL__OBJECT;
#			else
#				ifndef CMT_GLOBAL__TRY_CATCH
#					define CMT_GLOBAL__TRY_CATCH
#				endif /* !CMT_GLOBAL__TRY_CATCH */
#				undef main
#				undef WinMain
#				undef CMT_OTO_LINKER
#				undef CMT_GLOBAL__OBJECT
#				define CMT_GLOBAL__OBJECT CMT_LOCAL__OBJECT
#				define CMT_OTO_LINKER __CMT_JAILBREAK_VARIABLE__;\
					CMT_GLOBAL__OBJECT;\
					CMT_GLOBAL__TRY_CATCH;
#				define main CMT_OTO_LINKER int main
#				define WinMain CMT_OTO_LINKER int STDCALL WinMain
#			endif /* CMT_SETUP */
#		endif /* __SYSTEM_32_BIT__ */
#	endif /* __CPU_ARM__ */
/* @@@@@@@@@@@@@@@@@@@@@@@@@@@ [^] OTO-LINKER [^] @@@@@@@@@@@@@@@@@@@@@@@@@@@ */

#	ifndef KNR_STYLE /* STANDARD C */
static INLINE void
	*LOCALFUNCTION__OBJECT_INJECTOR(
	void *SELF,
	void *TARGET,
	unsigned char *INDEX_ADDRESS
)
#	else /* K&R */
static INLINE void
	*LOCALFUNCTION__OBJECT_INJECTOR(SELF, TARGET, INDEX_ADDRESS)
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
			(void **)(INDEX_ADDRESS - (sizeof(void *) << 1)) - (void **)SELF
		) + 1;
		_ = (unsigned char *)&(
			((unsigned char **)SELF)[1][
				(INDEX * LOCALMACRO__FUNCTION_SIZE) + (INDEX != 0)
			]
		);
	}
	else
		_ = (unsigned char *)&(((unsigned char **)SELF)[1][0]);

	RESULT = _;

#	ifdef __CPU_INTEL__
#		ifdef __SYSTEM_64_BIT__
	register unsigned long long	VALUE;

	_ [0X00] = 0X48; // MOVABS
	_ [0X01] = 0XB8; // RAX,
	VALUE = (unsigned long long)SELF; // IMM64
	_ [0X02] = VALUE & 0XFF;
	_ [0X03] = (VALUE >> 8) & 0XFF;
	_ [0X04] = (VALUE >> 16) & 0XFF;
	_ [0X05] = (VALUE >> 24) & 0XFF;
	_ [0X06] = (VALUE >> 32) & 0XFF;
	_ [0X07] = (VALUE >> 40) & 0XFF;
	_ [0X08] = (VALUE >> 48) & 0XFF;
	_ [0X09] = (VALUE >> 56) & 0XFF;
	_ [0X0A] = 0XC7; // MOV
	_ [0X0B] = 0X00; // DWORD PTR [RAX],
	VALUE = (unsigned long long)TARGET;
	_ [0X0C] = VALUE & 0XFF; // IMM32;
	_ [0X0D] = (VALUE >> 8) & 0XFF;
	_ [0X0E] = (VALUE >> 16) & 0XFF;
	_ [0X0F] = (VALUE >> 24) & 0XFF;
	_ [0X10] = 0XC7; // MOV
	_ [0X11] = 0X40; // DWORD PTR [RAX
	_ [0X12] = 0X04; // + 4],
	_ [0X13] = (VALUE >> 32) & 0XFF; // IMM32 + 4;
	_ [0X14] = (VALUE >> 40) & 0XFF;
	_ [0X15] = (VALUE >> 48) & 0XFF;
	_ [0X16] = (VALUE >> 56) & 0XFF;
	_ [0X17] = 0XFF; // JMP
	_ [0X18] = 0X20; // [RAX];
#	else
#		ifdef __SYSTEM_32_BIT__
	register unsigned int	VALUE;

	_ [0X00] = 0XB8; // MOV EAX,
	VALUE = (unsigned int)SELF;
	_ [0X01] = VALUE & 0XFF;
	_ [0X02] = (VALUE >> 8) & 0XFF;
	_ [0X03] = (VALUE >> 16) & 0XFF;
	_ [0X04] = (VALUE >> 24) & 0XFF;
	_ [0X05] = 0XC7; // MOV
	_ [0X06] = 0X00; // DWORD PTR [EAX],
	VALUE = (unsigned int)TARGET;
	_ [0X07] = VALUE & 0XFF;
	_ [0X08] = (VALUE >> 8) & 0XFF;
	_ [0X09] = (VALUE >> 16) & 0XFF;
	_ [0X0A] = (VALUE >> 24) & 0XFF;
	_ [0X0B] = 0XFF; // JMP
	_ [0X0C] = 0X20; // [EAX];
#			else
#				ifdef __SYSTEM_16_BIT__ // PROBABLY FOR ONLY TURBO C COMPILER
	_ [0X00] = 0XB8; // MOV AX,
	VALUE = (unsigned int)SELF;
	_ [0X01] = VALUE & 0XFF; // IMM16
	_ [0X02] = (VALUE >> 8) & 0XFF;
	_ [0X03] = 0XC7; // MOV
	_ [0X04] = 0X00; // WORD PTR [AX],
	VALUE = (unsigned int)TARGET;
	_ [0X05] = VALUE & 0XFF; // IMM16
	_ [0X06] = (VALUE >> 8) & 0XFF;
	_ [0X07] = 0XFF; // JMP
	_ [0X08] = 0X20; // [AX]
#				endif /* __SYSTEM_16_BIT__ */
#			endif /* __SYSTEM_32_BIT__ */
#		endif /* __SYSTEM_64_BIT__ */
#	endif /* __CPU_INTEL__ */

#ifdef __CPU_ARM__
	register int				INDEX;

#	ifdef __SYSTEM_64_BIT__
	register unsigned long long	VALUE;

	_ [0X00] = 0XB1;
	_ [0X01] = 0X00;
	_ [0X02] = 0X00;
	_ [0X03] = 0X58; // LDR X17, #IMM (SELF)
	_ [0X04] = 0XB0;
	_ [0X05] = 0X00;
	_ [0X06] = 0X00;
	_ [0X07] = 0X58; // LDR X16, #IMM (TARGET)
	_ [0X08] = 0X00;
	_ [0X09] = 0X02;
	_ [0X0A] = 0X1F;
	_ [0X0B] = 0XD6; // BR X16
	VALUE = (unsigned long long)SELF; // IMM64
	_ [0X0C] = (VALUE & 0XFF);
	_ [0X0D] = (VALUE >> 8) & 0XFF;
	_ [0X0E] = (VALUE >> 16) & 0XFF;
	_ [0X0F] = (VALUE >> 24) & 0XFF;
	_ [0X10] = (VALUE >> 32) & 0XFF;
	_ [0X11] = (VALUE >> 40) & 0XFF;
	_ [0X12] = (VALUE >> 48) & 0XFF;
	_ [0X13] = (VALUE >> 56) & 0XFF;
	VALUE = (unsigned long long)TARGET; // IMM64
	_ [0X14] = (VALUE & 0XFF);
	_ [0X15] = (VALUE >> 8) & 0XFF;
	_ [0X16] = (VALUE >> 16) & 0XFF;
	_ [0X17] = (VALUE >> 24) & 0XFF;
	_ [0X18] = (VALUE >> 32) & 0XFF;
	_ [0X19] = (VALUE >> 40) & 0XFF;
	_ [0X1A] = (VALUE >> 48) & 0XFF;
	_ [0X1B] = (VALUE >> 56) & 0XFF;
#		else
#			ifdef __SYSTEM_32_BIT__
	register unsigned int	VALUE;

	_ [0X00] = 0X0C;
	_ [0X01] = 0X00;
	_ [0X02] = 0X9F;
	_ [0X03] = 0XE5; /* LDR R0, [PC, #12] */
	_ [0X04] = 0X0C;
	_ [0X05] = 0X10;
	_ [0X06] = 0X9F;
	_ [0X07] = 0XE5; /* LDR R1, [PC, #12] */
	_ [0X08] = 0X00;
	_ [0X09] = 0X00;
	_ [0X0A] = 0X81;
	_ [0X0B] = 0XE5; /* STR R0, [R1, #0] */
	_ [0X0C] = 0X08;
	_ [0X0D] = 0X00;
	_ [0X0E] = 0X9F;
	_ [0X0F] = 0XE5; /* LDR R0, [PC, #8] */
	_ [0X10] = 0X10;
	_ [0X11] = 0XFF;
	_ [0X12] = 0X2F;
	_ [0X13] = 0XE1; /* BX R0 */
	VALUE = (unsigned int)SELF; // IMM64
	_ [0X14] = (VALUE & 0XFF);
	_ [0X15] = (VALUE >> 8) & 0XFF;
	_ [0X16] = (VALUE >> 16) & 0XFF;
	_ [0X17] = (VALUE >> 24) & 0XFF;
	VALUE = (unsigned int)&__OBJECT_STRUCTURE_POINTER__; // IMM64
	_ [0X18] = (VALUE & 0XFF);
	_ [0X19] = (VALUE >> 8) & 0XFF;
	_ [0X1A] = (VALUE >> 16) & 0XFF;
	_ [0X1B] = (VALUE >> 24) & 0XFF;
	VALUE = (unsigned int)TARGET; // IMM64
	_ [0X1C] = (VALUE & 0XFF);
	_ [0X1D] = (VALUE >> 8) & 0XFF;
	_ [0X1E] = (VALUE >> 16) & 0XFF;
	_ [0X1F] = (VALUE >> 24) & 0XFF;
#			endif /* __SYSTEM_32_BIT__ */
#		endif /* __SYSTEM_64_BIT__ */
#	endif /* __CPU_ARM__ */

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

/* * * * * * * * * * * /!\ AUTOMATIC EOF TREATMENT! /!\ * * * * * * * * * * * *\
 * * AT THE ALL END OF FILES, I AM ADDING A SPECIAL BYTE <0X1A> TO END THE  * *
 * *                       FILE IN DOS, CP/M SYSTEMS                        * *
 * *   "//" FOR HANDLING THE BYTE IN MODERN COMPILERS AND #define IS FOR    * *
 * *       HANDLING "//" SYNTAX WHICH IS NOT SUPPORTED ON OLD SYSTEMS       * *
\* * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * */
#undef __CMT__END_OF_FILE__
#define __CMT__END_OF_FILE__ //
