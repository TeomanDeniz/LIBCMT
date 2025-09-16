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
# : License - GPL-3.0   :: Update - 2025/09/16 : #    ::::!!!1!!1!!!1!!!::     #
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
|* OBJECT           : #define() : CREATE AN OBJECT                            *|
|* object           :           :                                             *|
|*..................:...........:.............................................*|
|* I_AM_AN_OBJECT   : #define() : DECLARES THE FUNCTION POINTER STORAGE FOR   *|
|* i_am_an_object   :           : AN OBJECT                                   *|
|*..................:...........:.............................................*|
|* OBJECT__TABLE    : #define() : CONNECT ALL OF THE FUNCTIONS INTO YOUR      *|
|* object__table    :           : STRUCTURE                                   *|
|*..................:...........:.............................................*|
|* OBJECT__CONNECT  : #define() : CONNECT A STRUCTURE INTO A FUNCTION         *|
|* object__connect  :           :                                             *|
|*..................:...........:.............................................*|
|* OBJECT__INJECT   : (*F)()    : INJECT A FUNCTION WITH A POINTER ADDRESS    *|
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
|* :                                                                          *|
|* :.., CONFIGURABLE MAXIMUM NUMBER OF FUNCTIONS PER OBJECT                   *|
|*    : (`__OBJECT_MAX_FUNCTION_LIMIT__`).                                    *|
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
|* ;.., #define SETUP_OBJECT                                                  *|
|*    : #include "LIBCMT/OBJECT.h"                                            *|
|*    :                                                                       *|
|*    : int main() {                                                          *|
|*    : ...                                                                   *|
|*    : }                                                                     *|
|*                                                                            *|
|* -------------------------------------------------------------------------- *|
|*                                                                            *|
|* O - CONTENTS                                                               *|
|* :                                                                          *|
|* :.., OBJECT(NAME, VAR)                                                     *|
|* :  :                                                                       *|
|* :  : INSTANTIATES AN OBJECT AND BINDS ITS FUNCTION TABLE.                  *|
|* :  :                                                                       *|
|* :  : IF IT HAS A CONSTRUCTOR, THEN USE:                                    *|
|* : 1|     object (s_struct, obj) (...);                                     *|
|* :  : ELSE                                                                  *|
|* : 1|     object (s_struct, obj);                                           *|
|* :  :                                                                       *|
|* :  : WE ALSO SUGGEST YOU TO USE #define FOR MAKE YOUR OBJECT MORE          *|
|* :  : SYNTAX SAFE TO USE AND CREATE                                         *|
|* :  :                                                                       *|
|* : 1| #define o_struct object(VAR) (s_struct, VAR)                          *|
|* : 2|                                                                       *|
|* : 3| o_struct(obj) (...);                                                  *|
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
|* :.., OBJECT__TABLE(STRUCT_NAME)                                            *|
|* :  :                                                                       *|
|* :  : DEFINES A FUNCTION TABLE ARRAY FOR AN OBJECT TYPE.                    *|
|* :  :                                                                       *|
|* : 1| object__table (s_struct) =                                            *|
|* : 2| {                                                                     *|
|* : 3|     constructor_function,                                             *|
|* : 4|     function_2,                                                       *|
|* : 5|     ...                                                               *|
|* : 6|     0 <- DO NOT FORGET TO ADD 0 AT THE END!!!!!!!                     *|
|* : 7| };          ^^^                                                       *|
|* :  :                                                                       *|
|* :  : LIST ALL OF YOUR FINCTIONS ON TOP TO BOTTOM WITH CORRECT INDEXES!     *|
|* :  :                                                                       *|
|* : 1|     struct s_struct {                                                 *|
|* : 2|         i_am_an_object;                                               *|
|* : 3|                                                                       *|
|* : 4|   +-->0 void (*function_a)();                                         *|
|* : 5| +-|-->1 void (*function_b)();                                         *|
|* : 6| | | };                                                                *|
|* : 7| | |                                                                   *|
|* : 8| | | object__table (s_struct) =                                        *|
|* : 9| | | {                                                                 *|
|* :10| | |     constructor_function,                                         *|
|* :11| | +-->0 function_2, // BECAMES function_a                             *|
|* :12| +---->1 function_1, // BECAMES function_b                             *|
|* :13|         0                                                             *|
|* :14|     };                                                                *|
|* :  :                                                                       *|
|* :  : YOU CAN ALSO EXTERN IT IF YOU ALREADY SET IT IN A C FILE              *|
|* :  :                                                                       *|
|* : 1| extern object__table(s_struct);                                       *|
|* :  :                                                                       *|
|* :                                                                          *|
|* :.., OBJECT__CONNECT(STRUCT_NAME)                                          *|
|*    :                                                                       *|
|*    : CONNECTS AN OBJECT STRUCTURE POINTER (this) TO ITS INSTANCE.          *|
|*    :                                                                       *|
|*    : JUST PUT THIS MACRO AT THE TOP OF YOUR FUNCTION BLOCK.                *|
|*    :                                                                       *|
|*   1| void function_1()                                                     *|
|*   2| {                                                                     *|
|*   3|     object__connect(s_struct);                                        *|
|*   4|     ...                                                               *|
|*   5| }                                                                     *|
|*    :                                                                       *|
|*                                                                            *|
|* -------------------------------------------------------------------------- *|
|*                                                                            *|
|* O - SOME EXAMPLES                                                          *|
|* :                                                                          *|
|* : struct test_object_type                                                  *|
|* : {                                                                        *|
|* :     i_am_an_object;                                                      *|
|* :                                                                          *|
|* :     void (*worked)(int);                                                 *|
|* :     int value;                                                           *|
|* : };                                                                       *|
|* :                                                                          *|
|* : static void CONSTRUCTOR(void)                                            *|
|* : {                                                                        *|
|* :     object__connect (test_object_type);                                  *|
|* :                                                                          *|
|* :     this->value = 0;                                                     *|
|* : }                                                                        *|
|* :                                                                          *|
|* : static void worked(int n)                                                *|
|* : {                                                                        *|
|* :     object__connect (test_object_type);                                  *|
|* :                                                                          *|
|* :     this->value += n;                                                    *|
|* : }                                                                        *|
|* :                                                                          *|
|* : object__table(test_object_type) =                                        *|
|* : {                                                                        *|
|* :     CONSTRUCTOR,                                                         *|
|* :     worked,                                                              *|
|* :     0                                                                    *|
|* : };                                                                       *|
|*                                                                            *|
|* O - USAGE                                                                  *|
|* :                                                                          *|
|* : object (test_object_type, obj) (); // CONSTRUCTOR CALLED                 *|
|* : obj.worked(42); // uses implicit "this"                                  *|
|*                                                                            *|
|* O - MULTIPLE OBJECTS EXAMPLE                                               *|
|* :                                                                          *|
|* : object (test_object_type, test1) ();                                     *|
|* : object (test_object_type, test2) ();                                     *|
|* :                                                                          *|
|* : test1.worked(42);                                                        *|
|* : test1.worked(42);                                                        *|
|* : test2.worked(42);                                                        *|
|* : test1.worked(42);                                                        *|
|* : test2.worked(42);                                                        *|
|*                                                                            *|
|* O - FULL EXAMPLE                                                           *|
|* :                                                                          *|
|* ;.., CONNECTING YOUR OBJECT TO YOUR FUNCTIONS                              *|
|* :  :                                                                       *|
|* :  : struct test_object_type                                               *|
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
|* :  : static void CONSTRUCTOR()                                             *|
|* :  : {                                                                     *|
|* :  :     object__connect (test_object_type);                               *|
|* :  :                                                                       *|
|* :  :     printf("0\n");                                                    *|
|* :  : }                                                                     *|
|* :  :                                                                       *|
|* :  : static int FUNC1()                                                    *|
|* :  : {                                                                     *|
|* :  :     object__connect (test_object_type);                               *|
|* :  :                                                                       *|
|* :  :     printf("1\n");                                                    *|
|* :  :     return (42);                                                      *|
|* :  : }                                                                     *|
|* :  :                                                                       *|
|* :  : static void FUNC2()                                                   *|
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
|* :  : object__table (test_object_type) =                                    *|
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
|* THIS SYSTEM ONLY ON DEVICES WITH MORE THAN 4KB OF RAM.                     *|
|*                                                                            *|
\******************************************************************************/

#ifndef OBJECT_H
#	define OBJECT_H 202509 /* VERSION */

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
#	include <setjmp.h> /*
#	 define jmp_buf
#	 define setjmp(jmp_buf env)
#	 define longjmp(jmp_buf env, int val)
#	        */
#	include <stddef.h> /*
#	typedef size_t;
#	        */
#	include <stdint.h> /*
#	typedef uintptr_t;
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
#	include "./ASM/RAX.h" /*
#	 define GET_RAX(VAR)
#	        */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] C++ (PUSH) [v] *************************** */
#	ifdef __cplusplus /* C++ */
extern "C" {
#	endif /* __cplusplus */
/* *************************** [^] C++ (PUSH) [^] *************************** */

/* ********************** [v] CAN CHANGABLE MACRO [v] *********************** */
#	ifndef __OBJECT_MAX_FUNCTION_LIMIT__
#		define __OBJECT_MAX_FUNCTION_LIMIT__ 64 // <- INCREASE IF NEEDED
#	endif /* !__OBJECT_MAX_FUNCTION_LIMIT__ */
/* ********************** [^] CAN CHANGABLE MACRO [^] *********************** */

#	define I_AM_AN_OBJECT void	*__OBJECT_FUNC_PTR__

#	ifdef __CPU_ARM__
#		define OBJECT__CONNECT(OBJECT_STRUCT_TYPE) \
			struct OBJECT_STRUCT_TYPE	*const this = \
				(struct OBJECT_STRUCT_TYPE *)__OBJECT_STRUCTURE_POINTER__
#	else
#		ifdef __CPU_INTEL__
#			define OBJECT__CONNECT(OBJECT_STRUCT_TYPE) \
				register uintptr_t __THIS__;\
				GET_RAX(__THIS__);\
				struct OBJECT_STRUCT_TYPE	*const this = \
					(struct OBJECT_STRUCT_TYPE *)__THIS__;
#		endif /* __CPU_INTEL__ */
#	endif /* __CPU_ARM__ */

#	define OBJECT__TABLE(OBJECT_TYPE) \
		void	*OBJECT_TYPE[__OBJECT_MAX_FUNCTION_LIMIT__]

#	define OBJECT(OBJECT_NAME, VARIABLE_NAME) \
		struct OBJECT_NAME	VARIABLE_NAME;\
		extern void			*OBJECT_NAME[__OBJECT_MAX_FUNCTION_LIMIT__];\
		\
		if (OBJECT_NAME)\
		{\
			register size_t	__OBJECT_INDEX__;\
			void			(*FUNCTION)();\
			register void	**FUNCTION_TABLE;\
			\
			__OBJECT_INDEX__ = 1;\
			FUNCTION_TABLE = OBJECT_NAME;\
			\
			while (FUNCTION_TABLE[__OBJECT_INDEX__])\
			{\
				FUNCTION = (void (*)())(FUNCTION_TABLE[__OBJECT_INDEX__]);\
				((uintptr_t **)&(VARIABLE_NAME))[__OBJECT_INDEX__] = \
					(uintptr_t *)FUNCTION;\
				((uintptr_t **)&(VARIABLE_NAME))[__OBJECT_INDEX__]\
					= OBJECT__INJECT(&(VARIABLE_NAME), FUNCTION);\
				++__OBJECT_INDEX__;\
			}\
		}\
		\
		if (OBJECT_NAME && *OBJECT_NAME)\
			(\
				(void (*)())OBJECT__INJECT(\
					&(VARIABLE_NAME), \
					*OBJECT_NAME)\
			)

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
	*OBJECT__INJECT(void *THIS, void *TARGET)
#	else /* K&R */
static INLINE void
	*OBJECT__INJECT(THIS, TARGET)
	void	*THIS;
	void	*TARGET;
#	endif /* !KNR_STYLE */
{
	register int		INDEX;
	unsigned char		*CODE;

#	ifdef __unix__
#		ifndef KNR_STYLE /* STANDARD C */
	extern void	*mmap(void *, size_t, int, int, int, int);
#		else /* K&R */
	extern void	*mmap();
#		endif /* !KNR_STYLE */
	CODE = (unsigned char *)mmap(((void *)0), 4096, 0X7, 0X22, -1, 0);

	if (CODE == ((unsigned char *) -1))
		return ((void *)0);
#	else
#		ifdef _WIN32
#			ifndef KNR_STYLE /* STANDARD C */
	extern void	*VirtualAlloc(void *, size_t, unsigned int, unsigned int);
#			else /* K&R */
	extern void	*VirtualAlloc();
#			endif /* !KNR_STYLE */
	CODE = (unsigned char *)VirtualAlloc(((void *)0), 4096, 0X00003000, 0X40);

	if (!CODE)
		return ((void *)0);
#		endif /* _WIN32 */
#	endif /* __unix__ */

#	ifdef __CPU_INTEL__
	register uintptr_t	VALUE;
	unsigned char		*_;

	_ = CODE;

#		ifdef __SYSTEM_64_BIT__
	*_++ = 0X48; // MOV
	*_++ = 0XB8; // RAX,
	VALUE = (uintptr_t)THIS; // IMM64
	*_++ = VALUE & 0XFF;
	*_++ = (VALUE >> 8) & 0XFF;
	*_++ = (VALUE >> 16) & 0XFF;
	*_++ = (VALUE >> 24) & 0XFF;
	*_++ = (VALUE >> 32) & 0XFF;
	*_++ = (VALUE >> 40) & 0XFF;
	*_++ = (VALUE >> 48) & 0XFF;
	*_++ = (VALUE >> 56) & 0XFF;
	*_++ = 0X53; // PUSH RBX;
	*_++ = 0X48; // MOV
	*_++ = 0XBB; // RBX,
	VALUE = (uintptr_t)TARGET; // IMM64
	*_++ = VALUE & 0XFF;
	*_++ = (VALUE >> 8) & 0XFF;
	*_++ = (VALUE >> 16) & 0XFF;
	*_++ = (VALUE >> 24) & 0XFF;
	*_++ = (VALUE >> 32) & 0XFF;
	*_++ = (VALUE >> 40) & 0XFF;
	*_++ = (VALUE >> 48) & 0XFF;
	*_++ = (VALUE >> 56) & 0XFF;
	*_++ = 0X48; // MOV
	*_++ = 0X89; // [RAX]
	*_++ = 0X18; // RBX;
	*_++ = 0X5B; // POP RBX;
	*_++ = 0XFF; // JMP
	*_++ = 0X20; // [RAX];
#	else
#		ifdef __SYSTEM_32_BIT__
	*_++ = 0XB8; // MOV EAX,
	VALUE = (uintptr_t)THIS;
	*_++ = VALUE & 0XFF;
	*_++ = (VALUE >> 8) & 0XFF;
	*_++ = (VALUE >> 16) & 0XFF;
	*_++ = (VALUE >> 24) & 0XFF;
	*_++ = 0X53; // PUSH EBX;
	*_++ = 0XBB; // MOV EBX,
	VALUE = (uintptr_t)TARGET;
	*_++ = VALUE & 0XFF;
	*_++ = (VALUE >> 8) & 0XFF;
	*_++ = (VALUE >> 16) & 0XFF;
	*_++ = (VALUE >> 24) & 0XFF;

	*_++ = 0X89; // MOV [EAX],
	*_++ = 0X18; // EBX;
	*_++ = 0X5B; // POP EBX;
	*_++ = 0XFF; // JMP
	*_++ = 0X20; // [EAX];
#			endif /* __SYSTEM_32_BIT__ */
#		endif /* __SYSTEM_64_BIT__ */
#	endif /* __CPU_INTEL__ */

#ifdef __CPU_ARM__
	uintptr_t	*LITERALS;

#	ifdef __SYSTEM_64_BIT__
	const unsigned int	INSTRUCTIONS[4] =
	{
		0X580000B1, /* LDR X17, #IMM (THIS) */
		0X580000B0, /* LDR X16, #IMM (TARGET) */
		0XF9000220, /* STR X16, [X17] */
		0XD61F0200  /* BR X16 */
	};

	for (INDEX = 0; INDEX < 4; ++INDEX)
	{
		const unsigned int	VALUE = INSTRUCTIONS[INDEX];
		CODE[4 * INDEX] = (unsigned char)(VALUE & 0XFF);
		CODE[4 * INDEX + 1] = (unsigned char)((VALUE >> 8) & 0XFF);
		CODE[4 * INDEX + 2] = (unsigned char)((VALUE >> 16) & 0XFF);
		CODE[4 * INDEX + 3] = (unsigned char)((VALUE >> 24) & 0XFF);
	}

	LITERALS = (uintptr_t *)(CODE + 4 * 4);
	LITERALS[0] = (uintptr_t)THIS;
	LITERALS[1] = (uintptr_t)TARGET;

#		else
#			ifdef __SYSTEM_32_BIT__
	const unsigned int	INSTRUCTIONS[5] =
	{
		0XE59F000C, /* LDR R0, [PC, #12] */
		0XE59F100C, /* LDR R1, [PC, #12] */
		0XE5810000, /* STR R0, [R1, #0] */
		0XE59F0008, /* LDR R0, [PC, #8] */
		0XE12FFF10  /* BX R0 */
	};

	for (INDEX = 0; INDEX < 5; ++INDEX)
	{
		const unsigned int	VALUE = INSTRUCTIONS[INDEX];

		CODE[4 * INDEX] = (unsigned char)(VALUE & 0XFF);
		CODE[4 * INDEX + 1] = (unsigned char)((VALUE >> 8) & 0XFF);
		CODE[4 * INDEX + 2] = (unsigned char)((VALUE >> 16) & 0XFF);
		CODE[4 * INDEX + 3] = (unsigned char)((VALUE >> 24) & 0XFF);
	}

	LITERALS = (uintptr_t *)(CODE + 20);
	LITERALS[0] = (uintptr_t)THIS;
	LITERALS[1] = (uintptr_t)&__OBJECT_STRUCTURE_POINTER__;
	LITERALS[2] = (uintptr_t)TARGET;
#			endif /* __SYSTEM_32_BIT__ */
#		endif /* __SYSTEM_64_BIT__ */
#	endif /* __CPU_ARM__ */


#	ifdef __unix__
#		ifndef KNR_STYLE /* STANDARD C */
	extern int	mprotect(void *, size_t, int);
#		else /* K&R */
	extern int	mprotect();
#		endif /* !KNR_STYLE */
	mprotect(CODE, 4096, 0X5);
#	endif /* __unix__ */

	return ((void *)CODE);
}

/* **************************** [v] LOWERCASE [v] *************************** */
#	define i_am_an_object I_AM_AN_OBJECT
#	define object__table OBJECT__TABLE
#	define object__connect OBJECT__CONNECT
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
