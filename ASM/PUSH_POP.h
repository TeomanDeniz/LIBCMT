/******************************************************************************\
# H - PUSH_POP                                   #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2024/02/27 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - AGPL-3.0  :: Update - 2025/05/13 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*\
|@                                                                            @|
|@                                  WARNING!                                  @|
|@                                                                            @|
|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
|@                                                                            @|
|@     THIS EXTENSION MIGHT NOT WORK ON ALL COMPILERS, OPERATING SYSTEMS,     @|
|@                            AND ARCHITECTURES!!!                            @|
|@                                                                            @|
|@          WILL GET DEEP AND HUGE MAINTENANCE ON THE FUTURE! USE IT          @|
|@                             WITH YOUR OWN RISK                             @|
|@                                           ^^^^                             @|
|@                                                                            @|
\*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

/******************************************************************************\
|*                                  CONTENTS                                  *|
|******************************************************************************|
|*............................................................................*|
|* NAME :    TYPE    :                      DESCRIPTION                       *|
|*......:............:........................................................*|
|* PUSH : #define () : MOVES A VALUE TO CPU STACK.                            *|
|* push :            :                                                        *|
|*......:............:........................................................*|
|* POP  : #define () : GETS A VALUE FROM CPU STACK.                           *|
|* pop  :            :                                                        *|
|*......:............:........................................................*|
\******************************************************************************/

/*############################################################################*\
|*#                              WTF THAT DOES?                              #*|
|*############################################################################*|
|*                                                                            *|
|* :::::::::::::::::::::::::::::: EXPLANATION ::::::::::::::::::::::::::::::: *|
|* WITH THESE FUNCTIONS, YOU'RE ABLE TO MOVE AND GET A VALUE FROM CPU STACK.  *|
|* LIKE IN ASSEMBLY. WHIC IT ACTUALLY WORKS WITH ASSEMBLY LOL                 *|
|*                                                                            *|
\******************************************************************************/

/*############################################################################*\
|*#                                HOW TO USE                                #*|
|*############################################################################*|
|*                                                                            *|
|* LET'S WRITE A SIMPLE AND PROBABLY WORLD'S FASTEST SWAP EXAMPLE:            *|
|*                                                                            *|
|* O - EXAMPLE                                                                *|
|* :                                                                          *|
|* ;.., register int a = 42;                                                  *|
|*    : register int b = 11;                                                  *|
|*    :                                                                       *|
|*    : PUSH(a); // > ADDED 42 TO CPU STACK                                   *|
|*    : a = b;   // |                                                         *|
|*    : POP(b);  // < REMOVED 42 FROM CPU STACK                               *|
|*    ;..,                                                                    *|
|*       : b IS NOW 42                                                        *|
|*       : a IS NOW 11                                                        *|
|*                                                                            *|
\******************************************************************************/

#ifndef PUSH_POP_H
#	define PUSH_POP_H 202505 /* VERSION */

/* *********************** [v] TI CGT CCS (PUSH) [v] ************************ */
#	ifdef __TI_COMPILER_VERSION__
#		pragma diag_push /* TI CGT CCS COMPILER DIRECTIVES */
#		pragma CHECK_MISRA("-5.4") /* TAG NAMES SHALL BE A UNIQUE IDENTIFIER */
#		pragma CHECK_MISRA("-19.3") /*
#			THE #INCLUDE DIRECTIVE SHALL BE FOLLOWED BY EITHER A <FILENAME> OR
#			"FILENAME" SEQUENCE
#		*/
#	endif /* __TI_COMPILER_VERSION__ */
/* *********************** [^] TI CGT CCS (PUSH) [^] ************************ */

/* *************************** [v] C++ (PUSH) [v] *************************** */
#	ifdef __cplusplus /* C++ */
extern "C" {
#	endif /* __cplusplus */
/* *************************** [^] C++ (PUSH) [^] *************************** */

#	define push(PUSH_VAR) \
		__asm__ __volatile__("push %0" : : "rm"((long)PUSH_VAR))

#	if (\
		defined(_WIN32) || /* WINDOWS */\
		defined(__DJGPP__) /* MS-DOS */\
	)
#		define pop(POP_VAR) \
		__asm__ __volatile__("pop %0" : "=rm"((long)POP_VAR))
#	else
#		define pop(POP_VAR) \
			{\
				register long	POP_RAX_##POP_VAR;\
				__asm__ __volatile__("pop %0" : "=rm"(POP_RAX_##POP_VAR));\
				POP_VAR = POP_RAX_##POP_VAR;\
			}
#	endif /* MICROSOFT */

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

#endif /* !PUSH_POP_H */
