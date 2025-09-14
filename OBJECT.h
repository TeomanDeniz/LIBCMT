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
# : License - GPL-3.0   :: Update - 2025/09/14 : #    ::::!!!1!!1!!!1!!!::     #
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
|* OBJECT__TABLE    : #define() : CONNECT ALL OF THE FUNCTIONS INTO YOUR      *|
|* object__table    :           : STRUCTURE                                   *|
|*..................:...........:.............................................*|
|* OBJECT__CONNECT  : #define() : CONNECT A STRUCTURE INTO A FUNCTION         *|
|* object__connect  :           :                                             *|
|*..................:...........:.............................................*|
|* OBJECT           : #define() : CREATE AN OBJECT                            *|
|* object           :           :                                             *|
|*..................:...........:.............................................*|
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
|* CONNECT YOUR FUNCTIONS USING "object__table(...) = { ... }".               *|
|* THE FIRST INDEX (0) IS ALWAYS THE CONSTRUCTOR FUNCTION.                    *|
|* FUNCTIONS ARE BOUND TO STRUCT MEMBERS BY ORDER, NOT NAME.                  *|
|* DON'T FORGET TO ADD 0 END OF THE: OBJECT__TABLE = {..., 0}!!!              *|
|*                                                                            *|
|* O - FUNCTION CONNECTION                                                    *|
|* :                                                                          *|
|* : struct test_object_type                                                  *|
|* : {                                                                        *|
|* :     void (*worked)(int);                                                 *|
|* :     int value;                                                           *|
|* : };                                                                       *|
|* :                                                                          *|
|* : // EVEN THOUGHT YOU DO NOTHING IN CONSTRUCTOR, YOU MUST CREATE IT ANYWAY *|
|* : static void CONSTRUCTOR(void)                                            *|
|* : {                                                                        *|
|* :     object__connect (test_object_type);                                  *| 
|* :     this->value = 0;                                                     *|
|* : }                                                                        *|
|* :                                                                          *|
|* : static void worked(int n)                                                *|
|* : {                                                                        *|
|* :     object__connect (test_object_type);                                  *|
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
#	include "./ASM/PUSH_POP.h" /*
#	 define POP_64(VAR)
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

#	define OBJECT__CONNECT(OBJECT_STRUCT_TYPE) \
		struct OBJECT_STRUCT_TYPE	*const this = \
			(struct OBJECT_STRUCT_TYPE *)__OBJECT_STRUCTURE_POINTER__;

#	define OBJECT__TABLE(OBJECT_TYPE) \
		void *OBJECT_TYPE[__OBJECT_MAX_FUNCTION_LIMIT__]

#	define OBJECT(OBJECT_NAME, VARIABLE_NAME) \
		struct OBJECT_NAME	VARIABLE_NAME;\
		\
		{\
			extern void		*OBJECT_NAME[];\
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
					((long **)&(VARIABLE_NAME))[__OBJECT_INDEX__ - 1]\
						= __TRAMPOLINE_FUNCTION__(&(VARIABLE_NAME), FUNCTION);\
				}\
				\
				++__OBJECT_INDEX__;\
			}\
		}\
		\
		if (*OBJECT_NAME)\
			(\
				(void (*)())__TRAMPOLINE_FUNCTION__(\
					&(VARIABLE_NAME), \
					*OBJECT_NAME)\
			)

/* ************************ [v] GLOBAL VARIABLES [v] ************************ */
#	ifdef SETUP_OBJECT
LOCAL void		*__OBJECT_STRUCTURE_POINTER__ = (void *)0;
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
			LOCAL void		*__OBJECT_STRUCTURE_POINTER__ = (void *)0;
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
/* *************************** [^] PROTOTYPES [^] *************************** */

#	ifndef KNR_STYLE /* STANDARD C */
static INLINE void
	*__TRAMPOLINE_FUNCTION__(void *THIS, void *TARGET)
#	else /* K&R */
static INLINE void
	*__TRAMPOLINE_FUNCTION__(THIS, TARGET)
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
	VALUE = (uintptr_t)THIS;

	for (INDEX = 0; INDEX < 8; INDEX++) // IMM64;
		*_++ = (VALUE >> (INDEX * 8)) & 0XFF;

	*_++ = 0X53; // PUSH RBX;
	*_++ = 0X48; // MOV
	*_++ = 0XBB; // RBX,
	VALUE = (uintptr_t)&__OBJECT_STRUCTURE_POINTER__;

	for (INDEX = 0; INDEX < 8; INDEX++) // IMM64;
		*_++ = (VALUE >> (INDEX * 8)) & 0XFF;

	*_++ = 0X48; // MOV
	*_++ = 0X89; // [RBX],
	*_++ = 0X03; // RAX;
	*_++ = 0X5B; // POP RBX;
	*_++ = 0X48; // MOV
	*_++ = 0XB8; // RAX;
	VALUE = (uintptr_t)TARGET;

	for (INDEX = 0; INDEX < 8; INDEX++) // IMM64
		*_++ = (VALUE >> (INDEX * 8)) & 0XFF;

	*_++ = 0XFF; // JMP
	*_++ = 0XE0; // RAX;
#	else
#		ifdef __SYSTEM_32_BIT__
	*_++ = 0XB8; // MOV EAX,
	VALUE = (uintptr_t)THIS;

	for (INDEX = 0; INDEX < 4; INDEX++) // IMM32;
		*_++ = (VALUE >> (INDEX * 8)) & 0XFF;

	*_++ = 0X53; // PUSH EBX;
	*_++ = 0XBB; // MOV EBX,
	VALUE = (uintptr_t)&__OBJECT_STRUCTURE_POINTER__;

	for (INDEX = 0; INDEX < 4; INDEX++) // IMM32;
		*_++ = (VALUE >> (INDEX * 8)) & 0XFF;

	*_++ = 0X89; // MOV [EBX],
	*_++ = 0X03; // EAX;
	*_++ = 0X5B; // POP EBX;
	*_++ = 0XB8; // MOV EAX,
	VALUE = (uintptr_t)TARGET;

	for (INDEX = 0; INDEX < 4; INDEX++) // IMM32;
		*_++ = (VALUE >> (INDEX * 8)) & 0XFF;

	*_++ = 0XFF; // JMP
	*_++ = 0XE0; // EAX;
#			endif /* __SYSTEM_32_BIT__ */
#		endif /* __SYSTEM_64_BIT__ */
#	endif /* __CPU_INTEL__ */

#	ifdef __CPU_ARM__
	uintptr_t			*LITERALS;

#		ifdef __SYSTEM_64_BIT__
	const unsigned int	INSTRUCTIONS[5] =
		{
			(unsigned)0X580000A0, /* LDR X0, #IMM (THIS) */
			(unsigned)0X580000C1, /* LDR X1, #IMM (&GLOBAL) */
			(unsigned)0XF9000020, /* STR X0, [X1] */
			(unsigned)0X580000C0, /* LDR X0, #IMM (TARGET) */
			(unsigned)0XD61F0000  /*  BR X0 */
		};

	for (INDEX = 0; INDEX < 5; ++INDEX)
	{
		register unsigned int	VALUE;

		VALUE = INSTRUCTIONS[INDEX];
		CODE[4 * INDEX + 0] = (unsigned char)(VALUE & (unsigned)0XFF);
		CODE[4 * INDEX + 1] = (unsigned char)((VALUE >> 8) & (unsigned)0XFF);
		CODE[4 * INDEX + 2] = (unsigned char)((VALUE >> 16) & (unsigned)0XFF);
		CODE[4 * INDEX + 3] = (unsigned char)((VALUE >> 24) & (unsigned)0XFF);
	}

	LITERALS = (uintptr_t *)(CODE + 4 * 5);
	LITERALS[0] = (uintptr_t)THIS;
	LITERALS[1] = (uintptr_t)&__OBJECT_STRUCTURE_POINTER__;
	LITERALS[2] = (uintptr_t)TARGET;
#		else
#			ifdef __SYSTEM_32_BIT__
	const unsigned int	INSTRUCTIONS[5] =
		{
			(unsigned)0XE59F000C, /* LDR R0, [PC, #12] */
			(unsigned)0XE59F100C, /* LDR R1, [PC, #12] */
			(unsigned)0XE5810000, /* STR R0, [R1, #0] */
			(unsigned)0XE59F0008, /* LDR R0, [PC, #8] */
			(unsigned)0XE12FFF10  /*  BX R0 */
		};

	for (INDEX = 0; INDEX < 5; ++INDEX)
	{
		register unsigned int	VALUE;

		VALUE = INSTRUCTIONS[INDEX];
		CODE[4 * INDEX + 0] = (unsigned char)(VALUE & (unsigned)0XFF);
		CODE[4 * INDEX + 1] = (unsigned char)((VALUE >> 8) & (unsigned)0XFF);
		CODE[4 * INDEX + 2] = (unsigned char)((VALUE >> 16) & (unsigned)0XFF);
		CODE[4 * INDEX + 3] = (unsigned char)((VALUE >> 24) & (unsigned)0XFF);
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
