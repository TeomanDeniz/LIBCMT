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
# : License - GPL-3.0   :: Update - 2025/12/03 : #    ::::!!!1!!1!!!1!!!::     #
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
|*                                                                            *|
|*  O - EXAMPLE                                                               *|
|*  :                                                                         *|
|* 1| int variable[9471];                                                     *|
|* 2| int number = 42;                                                        *|
|* 3|                                                                         *|
|* 4| PREFETCH(variable[0]);                                                  *|
|* 5| // OR                                                                   *|
|* 6| prefetch(number);                                                       *|
|*  :                                                                         *|
|*                                                                            *|
|* ::::::::::::::::::::::::::::: PREFETCH_RANGE ::::::::::::::::::::::::::::: *|
|*                                                                            *|
|*  O - EXAMPLE                                                               *|
|*  :                                                                         *|
|* 1| int variable[9471];                                                     *|
|* 2|                                                                         *|
|* 3| PREFETCH_RANGE(variable, sizeof(variable));                             *|
|* 4| // OR                                                                   *|
|* 5| prefetch_range(variable, 100);                                          *|
|*  :                                                                         *|
|*                                                                            *|
\******************************************************************************/

/*############################################################################*\
|*#                              WTF DOES THAT DO?                           #*|
|*############################################################################*|
|*                                                                            *|
|* :::::::::::::::::::::::::::::::: PREFETCH :::::::::::::::::::::::::::::::: *|
|*                                                                            *|
|* YOU'RE TELLING THE CPU TO LOAD A SPECIFIC MEMORY LOCATION INTO ITS CACHE   *|
|* **BEFORE** IT'S ACTUALLY NEEDED.                                           *|
|*   ^^^^^^                                                                   *|
|* SIMPLY PUT: IT HINTS THE CPU TO FETCH THE VALUE INTO CACHE EARLY,          *|
|* REDUCING MEMORY ACCESS LATENCY WHEN THAT VALUE IS USED SOON AFTER.         *|
|*                                                                            *|
|* THIS DOES NOT MOVE DATA TO "STACK" - IT MOVES IT INTO CACHE LINES.         *|
|* IT'S A PERFORMANCE HINT, NOT A GUARANTEED ACTION.                          *|
|*                                                                            *|
|* ::::::::::::::::::::::::::::: PREFETCH_RANGE ::::::::::::::::::::::::::::: *|
|*                                                                            *|
|* THE "PREFETCH" FUNCTION ONLY WORKS FOR A SINGLE VARIABLE.                  *|
|*                                                                            *|
|* "PREFETCH_RANGE" ALLOWS YOU TO PREFETCH MULTIPLE VARIABLES OR A WHOLE      *|
|* ARRAY BY PREFETCHING A BLOCK OF MEMORY IN A LOOP OR RANGE.                 *|
|*                                                                            *|
|* USE THIS WHEN WORKING WITH LARGE BUFFERS OR ARRAYS TO MINIMIZE CACHE       *|
|* MISSES BEFORE HEAVY PROCESSING.                                            *|
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
#	define PREFETCH_H 202512 /* VERSION */

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
#	include	"../KEYWORDS/IGNORE_VAR.h" /*
#	 define IGNORE_VAR
#	        */
#	include	"../ENVIRONMENTS/KNR_STYLE.h" /*
#	 define KNR_STYLE
#	        */
/* **************************** [^] INCLUDES [^] **************************** */

/* **************************** [v] PREFETCH [v] **************************** */
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
#	ifndef KNR_STYLE /* STANDARD C */
static INLINE void
	PREFETCH_RANGE(void *VARIABLE, register unsigned int LENGTH)
#	else /* K&R */
static INLINE void
	PREFETCH_RANGE(VARIABLE, LENGTH)
	void					*VARIABLE;
	register unsigned int	LENGTH;
#	endif /* !KNR_STYLE */
{
#	if (\
		!defined(ARCH_HAS_PREFETCH) && \
		!defined(PREFETCH)\
	)
	IGNORE_VAR	VARIABLE;
	IGNORE_VAR	LENGTH;
#	else
	char	*CACHE;
	char	*END;

	CACHE = (char *) VARIABLE;
	END = (char *) VARIABLE + LENGTH;

	while (CACHE < END)
	{
		PREFETCH(CACHE);
		CACHE += (4 * sizeof(long));
	}
#	endif /* !ARCH_HAS_PREFETCH && !PREFETCH */
}
/* ************************* [^] PREFETCH_RANGE [^] ************************* */
/* ************************* [v] prefetch_range [v] ************************* */
#	ifndef _LINUX_PREFETCH_H
#		define _LINUX_PREFETCH_H
#		ifndef KNR_STYLE /* STANDARD C */
static INLINE void
	prefetch_range(void *variable, register unsigned int length)
#		else /* K&R */
static INLINE void
	prefetch_range(variable, length)
	void					*variable;
	register unsigned int	length;
#		endif /* !KNR_STYLE */
{
	PREFETCH_RANGE(variable, length);
}
#	endif /* !_LINUX_PREFETCH_H */
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

#endif /* !PREFETCH_H */

/* * * * * * * * * * * /!\ AUTOMATIC EOF TREATMENT! /!\ * * * * * * * * * * * *\
 * * AT THE ALL END OF FILES, I AM ADDING A SPECIAL BYTE <0X1A> TO END THE  * *
 * *                       FILE IN DOS, CP/M SYSTEMS                        * *
 * *   "//" FOR HANDLING THE BYTE IN MODERN COMPILERS AND #define IS FOR    * *
 * *       HANDLING "//" SYNTAX WHICH IS NOT SUPPORTED ON OLD SYSTEMS       * *
\* * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * */
#undef __LIBCMT__END_OF_FILE__
#define __LIBCMT__END_OF_FILE__ //
