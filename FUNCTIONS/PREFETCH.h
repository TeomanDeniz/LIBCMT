/******************************************************************************\
# H - PREFETCH                                   #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2023/07/08 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - AGPL-3.0  :: Update - 2025/04/03 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

/*############################################################################*\
|*#                                 CONTENTS                                 #*|
|*############################################################################*|
|*............................................................................*|
|*        NAME        :    TYPE    :               DESCRIPTION                *|
|*....................:............:..........................................*|
|* PREFETCH           : #define () : MAKE A VALUE FROM MEMORY PRIOR AND MOVE  *|
|* prefetch           :            : IT TO CPU HEAP BEFORE USE.               *|
|*....................:............:..........................................*|
|* PREFETCHW          : #define () : SAME WITN PREFETCH. BUT, IT TELLS TO CPU *|
|* prefetchw          :            : PREFETCHTED DATA MIGHT BE MODYFYED SOON. *|
|*....................:............:..........................................*|
|* SPIN_LOCK_PREFETCH : #define () : PREFETCH SPIN LOCKS (ONLY UNIX)          *|
|* spin_lock_prefetch :            :          ^^^^ ^^^^^ WTF ARE THESE?       *|
|*....................:............:..........................................*|
|* PREFETCH_RANGE     : (*f)()     : PREFETCH THE WHOLE MEMORY. WOW! LOOK AT  *|
|* prefetch_range     :            : THAT!                                    *|
|*....................:............:..........................................*|
\******************************************************************************/

/*############################################################################*\
|*#                                HOW TO USE                                #*|
|*############################################################################*|
|*                                                                            *|
|* :::::::::::::::::::::::::::::::: PREFETCH :::::::::::::::::::::::::::::::: *|
|* O - EXAMPLE                                                                *|
|* :                                                                          *|
|* ;.., int variable[9471];                                                   *|
|*    : int number = 42;                                                      *|
|*    :                                                                       *|
|*    : PREFETCH(variable[0]);                                                *|
|*    : // OR                                                                 *|
|*    : prefetch(number);                                                     *|
|*                                                                            *|
|* ::::::::::::::::::::::::::::: PREFETCH_RANGE ::::::::::::::::::::::::::::: *|
|* O - EXAMPLE                                                                *|
|* :                                                                          *|
|* ;.., int variable[9471];                                                   *|
|*    :                                                                       *|
|*    : PREFETCH_RANGE(variable, sizeof(variable));                           *|
|*    : // OR                                                                 *|
|*    : prefetch_range(variable, 100);                                        *|
|*                                                                            *|
\******************************************************************************/

/*############################################################################*\
|*#                              WTF THAT DOES?                              #*|
|*############################################################################*|
|*                                                                            *|
|* :::::::::::::::::::::::::::::::: PREFETCH :::::::::::::::::::::::::::::::: *|
|* YOU'RE TELLING THE CPU THAT THAT ONE PIECE OF MEMORY MUST BE IN PRE-SEARCH *|
|* AND IT'S VALUE MUST BE IN CPU BEFORE IT IS GET USED.                       *|
|* SIMPLY: THE CPU GETS THE VALUE FROM THE MEMORY AND STORES IT IN CPU'S      *|
|* STACK BEFORE IT IS GET USED.                                               *|
|*                                                                            *|
|* ::::::::::::::::::::::::::::: PREFETCH_RANGE ::::::::::::::::::::::::::::: *|
|* SINCE, "PREFETCH" FUNCTION PREFETCHES ONLY ONE VARIABLE, YOU CAN PREFETCH  *|
|* MULTILE VARIABLES WITH THIS FUNCTION. MAYBE EVEN THE WHOLE ARRAY.          *|
|*                                                                            *|
\******************************************************************************/

/*############################################################################*\
|*#                                SIDE NOTES                                #*|
|*############################################################################*|
|*                                                                            *|
|* SOURCE:                                                                    *|
|* https://elixir.bootlin.com/linux/v4.8/source/include/linux/prefetch.h      *|
|*                                                                            *|
|* ASM:                                                                       *|
|* __asm__ __volatile__("prefetcht0 (%0)" : : "r"( PTR ));                    *|
|*                                                                            *|
\******************************************************************************/

#ifndef PREFETCH_H
#	define PREFETCH_H 202504 /* VERSION */

/* *********************** [v] TI CGT CCS (PUSH) [v] ************************ */
#	ifdef __TI_COMPILER_VERSION__
#		pragma diag_push /* TI CGT CCS COMPILER DIRECTIVES */
#		pragma CHECK_MISRA("-5.4") /* TAG NAMES SHALL BE A UNIQUE IDENTIFIER */
#		pragma CHECK_MISRA("-19.3") /* THE #INCLUDE DIRECTIVE SHALL BE FOLLOWED
#		BY EITHER A <FILENAME> OR "FILENAME" SEQUENCE */
#	endif /* __TI_COMPILER_VERSION__ */
/* *********************** [^] TI CGT CCS (PUSH) [^] ************************ */

/* *************************** [v] MVS LINKER [v] *************************** */
/* **** MVS LINKER DOES NOT SUPPORT EXTERNAL NAMES LARGER THAN 8 BYTES!! **** */
// NOTE: TARGETING IBM MAINFRAME SYSTEMS (Z/OS)
#ifdef (__MVS__)
#	pragma map(PREFETCH_RANGE, "PRFRANGE")
#endif /* __MVS__ */
/* *************************** [^] MVS LINKER [^] *************************** */

/* *************************** [v] C++ (PUSH) [v] *************************** */
#	ifdef __cplusplus /* C++ */
extern "C" {
#	endif /* __cplusplus */
/* *************************** [^] C++ (PUSH) [^] *************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#	ifdef _MSC_VER /* MICROSOFT C++ */
#		include	<xmmintrin.h> /*
#		   void	_mm_prefetch(void *, enum _mm_hint);
#		        */
#	endif /* _MSC_VER */
#	include	"../KEYWORDS/INLINE.h" /*
#	 define INLINE
#	        */
#	include	"../KEYWORDS/IGNORE.h" /*
#	 define IGNORE
#	        */
#	include	"../ENVIRONMENTS/CACHE.h" /*
#	 define L1_CACHE_BYTES
#	        */
#	include	"../ENVIRONMENTS/KNR_STYLE.h" /*
#	 define KNR_STYLE
#	        */
/* **************************** [^] INCLUDES [^] **************************** */

/* **************************** [v] PREFETCH [v] **************************** */
#	ifndef PREFETCH_STRIDE
#		define PREFETCH_STRIDE (4 * L1_CACHE_BYTES)
#	endif /* !PREFETCH_STRIDE */
#	if (\
		defined(__TINYC__) || /* TINY C COMPILER */\
		defined(__DJGPP__) || /* DJGPP DOS C COMPILER */\
		defined(__SDCC) || /* SMALL DEVICE C COMPILER */\
		defined(__SCCZ80) || /* SMALL DEVICE C COMPILER ZILOG Z80 */\
		defined(ARCH_HAS_PREFETCHW) /* AS IT SEEMS */\
	)
#		define PREFETCH(__PREFETCH_VARIABLE__) /* NOTHING */
#	else
#		ifdef _MSC_VER /* MICROSOFT C++ */
#			define PREFETCH(__PREFETCH_VARIABLE__) (\
				_mm_prefetch((char const *const) __PREFETCH_VARIABLE__, \
				_MM_HINT_T0)\
			)
#		else
#			if (\
				defined(__GNUC__) || /* GCC */\
				defined(__clang__) /* LLVM */\
			)
#				define PREFETCH(__PREFETCH_VARIABLE__) (\
					__builtin_prefetch(&__PREFETCH_VARIABLE__))
#			else
#				define PREFETCH(X) /* NULL */
#			endif /* __GNUC__ || __clang__ */
#		endif /* _MSC_VER */
#	endif /* __TINYC__ || __DJGPP__ || __SDCC || __SCCZ80 || ARCH_HAS */
/* **************************** [^] PREFETCH [^] **************************** */

/* *************************** [v] PREFETCHW [v] **************************** */
#	if (\
		defined(__TINYC__) || /* TINY C COMPILER */\
		defined(__DJGPP__) || /* DJGPP DOS C COMPILER */\
		defined(__SDCC) || /* SMALL DEVICE C COMPILER */\
		defined(__SCCZ80) || /* SMALL DEVICE C COMPILER ZILOG Z80 */\
		defined(ARCH_HAS_PREFETCHW) /* AS IT SEEMS */\
	)
#		ifndef ARCH_HAS_PREFETCHW
#			define PREFETCHW(__PREFETCHW_VARIABLE__) /* NOTHING */
#		endif /* !ARCH_HAS_PREFETCHW */
#	else
#		ifdef _MSC_VER /* MICROSOFT C++ */
#			define PREFETCHW(__PREFETCHW_VARIABLE__) (\
				_mm_prefetch((char const *const) \
					__PREFETCHW_VARIABLE__, _MM_HINT_T0)\
			)
#		else
#			if (\
				defined(__GNUC__) || /* GCC */\
				defined(__clang__) /* LLVM */\
			)
#				define PREFETCHW(__PREFETCHW_VARIABLE__) (\
					__builtin_prefetch(&__PREFETCHW_VARIABLE__, 1)\
				)
#			else
#				define PREFETCHW(X) /* NULL */
#			endif /* __GNUC__ || __clang__ */
#		endif /* _MSC_VER */
#	endif /* __TINYC__ || __DJGPP__ || __SDCC || __SCCZ80 || ARCH_HAS */
/* *************************** [^] PREFETCHW [^] **************************** */

/* **************************** [v] prefetch [v] **************************** */
#	ifndef ARCH_HAS_PREFETCH
#		ifdef __LINUX_ARM_ARCH__
#			if (__LINUX_ARM_ARCH__ >= 5)
#				define ARCH_HAS_PREFETCH
#				define prefetch(__prefetch_variable__) __asm__ __volatile__(\
					"pld\t%a0"\
					: : "p" (__prefetch_variable__))
#			else
#				define prefetch(__prefetch_variable__) /* NULL */
#			endif /* __LINUX_ARM_ARCH__ >= 7 */
#			define PREFETCH(__PREFETCH_VARIABLE__) \
				prefetch(__PREFETCH_VARIABLE__)
#		else
#			ifndef prefetch
#				define prefetch(__prefetch_variable__) \
					PREFETCH(__prefetch_variable__)
#			endif /* !prefetch */
#		endif /* __LINUX_ARM_ARCH__ */
#	else
#		define PREFETCH(__PREFETCH_VARIABLE__) \
			prefetch(__PREFETCH_VARIABLE__)
#	endif /* !ARCH_HAS_PREFETCH */
/* **************************** [^] prefetch [^] **************************** */

/* *************************** [v] prefetchw [v] **************************** */
#	ifndef ARCH_HAS_PREFETCHW
#		ifdef __LINUX_ARM_ARCH__
#			ifndef __ALT_SMP_ASM
#				ifdef CONFIG_SMP
#					define __ALT_SMP_ASM(SMP, UP)\
						"9998:	" SMP "\n"\
						"	.pushsection \".alt.smp.init\", \"a\"\n"\
						"	.align	2\n"\
						"	.long	9998b - .\n"\
						"	" UP "\n"\
						"	.popsection\n"
#				else
#					define __ALT_SMP_ASM(SMP, UP) UP
#				endif /* CONFIG_SMP */
#			endif /* !__ALT_SMP_ASM */
#			if (__LINUX_ARM_ARCH__ >= 7)
#				define ARCH_HAS_PREFETCHW
#				define prefetchw(__prefetchw_variable__) __asm__ __volatile__(\
					".arch_extension	mp\n"\
					__ALT_SMP_ASM(\
						"pldw\t%a0",\
						"pld\t%a0"\
					)\
					: : "p" (__prefetchw_variable__)\
				)
#			else
#				define prefetchw(__prefetchw_variable__) /* NULL */
#			endif /* __LINUX_ARM_ARCH__ >= 7 */
#			define PREFETCHW(__PREFETCHW_VARIABLE__) \
				prefetchw(__PREFETCHW_VARIABLE__)
#		else
#			ifndef prefetchw
#				define prefetchw(__prefetchw_variable__) \
					PREFETCHW(__prefetchw_variable__)
#			endif /* !prefetchw */
#		endif /* __LINUX_ARM_ARCH__ */
#	else
#		define PREFETCHW(__PREFETCHW_VARIABLE__) \
			prefetchw(__PREFETCHW_VARIABLE__)
#	endif /* !ARCH_HAS_PREFETCHW */
/* *************************** [^] prefetchw [^] **************************** */

/* ************************* [v] PREFETCH_RANGE [v] ************************* */
#	ifndef KNR_STYLE /* K&R */
extern INLINE void
	PREFETCH_RANGE(void *VARIABLE, register unsigned int LENGHT)
#	else /* STANDARD C */
extern INLINE void
	PREFETCH_RANGE(VARIABLE, LENGHT)
	void					*VARIABLE;
	register unsigned int	LENGHT;
#	endif /* !KNR_STYLE */
{
#	if (\
		!defined(ARCH_HAS_PREFETCH) && \
		!defined(PREFETCH)\
	)
	IGNORE VARIABLE;
	IGNORE LENGHT;
#	else
	char	*CACHE;
	char	*END;

	CACHE = (char *) VARIABLE;
	END = (char *) VARIABLE + LENGHT;

	while (CACHE < END)
	{
		PREFETCH(CACHE);
		CACHE += PREFETCH_STRIDE;
	}
#	endif /* !ARCH_HAS_PREFETCH && !PREFETCH */
}
/* ************************* [^] PREFETCH_RANGE [^] ************************* */
/* ************************* [v] prefetch_range [v] ************************* */
#	ifndef _LINUX_PREFETCH_H
#		define _LINUX_PREFETCH_H
#		ifndef KNR_STYLE /* K&R */
extern INLINE void
	prefetch_range(void *variable, register unsigned int lenght)
#		else /* STANDARD C */
extern INLINE void
	prefetch_range(variable, lenght)
	void					*variable;
	register unsigned int	lenght;
#		endif /* !KNR_STYLE */
{
	PREFETCH_RANGE(variable, lenght);
}
#	endif /* _LINUX_PREFETCH_H */
/* ************************* [^] prefetch_range [^] ************************* */

/* *********************** [v] spin_lock_prefetch [v] *********************** */
#	ifndef ARCH_HAS_SPINLOCK_PREFETCH
#		ifndef spin_lock_prefetch
#			define spin_lock_prefetch(__spin_lock_prefetch_variable__) \
				PREFETCHW(__spin_lock_prefetch_variable__)
#		endif /* !spin_lock_prefetch */
#	endif /* !ARCH_HAS_SPINLOCK_PREFETCH */
/* *********************** [^] spin_lock_prefetch [^] *********************** */

/* *********************** [v] SPIN_LOCK_PREFETCH [v] *********************** */
#	ifndef ARCH_HAS_SPINLOCK_PREFETCH
#		define SPIN_LOCK_PREFETCH(__SPIN_LOCK_PREFETCH_VARIABLE__) \
			PREFETCHW(__SPIN_LOCK_PREFETCH_VARIABLE__)
#	else
#		ifndef SPIN_LOCK_PREFETCH
#			define SPIN_LOCK_PREFETCH(__SPIN_LOCK_PREFETCH_VARIABLE__) \
				spin_lock_prefetch(__SPIN_LOCK_PREFETCH_VARIABLE__)
#		endif /* SPIN_LOCK_PREFETCH */
#	endif /* !ARCH_HAS_SPINLOCK_PREFETCH */
/* *********************** [^] SPIN_LOCK_PREFETCH [^] *********************** */

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

#endif /* PREFETCH_H */
