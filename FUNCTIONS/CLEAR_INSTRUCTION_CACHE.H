/******************************************************************************\
# H - CLEAR_INSTRUCTION_CACHE                    #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2025/12/24 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - GPL-3.0   :: Update - 2025/12/24 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

/*############################################################################*\
|*#                                 CONTENTS                                 #*|
|*############################################################################*|
|*............................................................................*|
|*          NAME           :    TYPE    :             DESCRIPTION             *|
|*.........................:.........:........................................*|
|* CLEAR_INSTRUCTION_CACHE : #define () : IT ENSURES THAT MACHINE CODE YOU    *|
|* clear_instruction_cache :            : JUST WROTE TO MEMORY IS ACTUALLY    *|
|*                         :            : EXECUTED                            *|
|*.........................:............:.....................................*|
\******************************************************************************/

/*############################################################################*\
|*#                                HOW TO USE                                #*|
|*############################################################################*|
|*                                                                            *|
|*  O - EXAMPLE                                                               *|
|*  :                                                                         *|
|* 1| ...                                                                     *|
|* 2| memcpy(code_ptr, bytes, size);                                          *|
|* 3| CLEAR_INSTRUCTION_CACHE(code_ptr, code_ptr + size);                     *|
|* 4| mprotect(page, RX);                                                     *|
|* 5| ...                                                                     *|
|*  :                                                                         *|
|*                                                                            *|
\******************************************************************************/

/*############################################################################*\
|*#                              WTF THAT DOES?                              #*|
|*############################################################################*|
|*                                                                            *|
|* :::::::::::::::::::::::::::::: EXPLANATION ::::::::::::::::::::::::::::::: *|
|*                                                                            *|
|* MODERN CPUS OFTEN HAVE SEPARATE DATA AND INSTRUCTION CACHES.               *|
|*                                                                            *|
|* WRITING BYTES UPDATES DATA CACHE, BUT THE INSTRUCTION CACHE MAY STILL      *|
|* CONTAIN OLD CONTENTS FOR THE SAME ADDRESS.                                 *|
|*                                                                            *|
|* WITHOUT A FLUSH, THE CPU MAY EXECUTE STALE OR GARBAGE INSTRUCTIONS.        *|
|*                                                                            *|
|* ::::::::::::::::::::::::::::::::: EFFECT ::::::::::::::::::::::::::::::::: *|
|*                                                                            *|
|* AFTER CALLING IT:                                                          *|
|*                                                                            *|
|* O - DATA CACHE LINES COVERING [BEGIN, END) ARE WRITTEN BACK                *|
|* O - INSTRUCTION CACHE LINES COVERING [BEGIN, END) ARE INVALIDATED          *|
|* O - NEXT EXECUTION FETCHES THE NEW INSTRUCTIONS FROM MEMORY                *|
|*                                                                            *|
|* ON X86: USUALLY NO VISIBLE EFFECT                                          *|
|* ON ARM / RISC-V / MIPS: MANDATORY                                          *|
|*                                                                            *|
\******************************************************************************/

#ifndef CLEAR_INSTRUCTION_CACHE_H
#	define CLEAR_INSTRUCTION_CACHE_H 202512 /* VERSION */
#	ifdef _MSC_VER
/* **************************** [v] INCLUDES [v] **************************** */
#		include "../ENVIRONMENTS/KNR_STYLE.H" /*
#		 define KNR_STYLE
#		        */
#		include "../KEYWORDS/STDCALL.H" /*
#		 define STDCALL
#		        */
#		include "../KEYWORDS/TYPES.H" /*
#		typedef PTR;
#		typedef BIT64;
#		        */
/* **************************** [^] INCLUDES [^] **************************** */
#		ifndef KNR_STYLE
#			ifdef _WIN64
extern int	STDCALL FlushInstructionCache(PTR, const PTR, BIT64);
#			else
extern int	STDCALL FlushInstructionCache(PTR, const PTR, unsigned long);
#			endif /* _WIN64 */
extern PTR	STDCALL GetCurrentProcess(void);
#		else
extern int	STDCALL FlushInstructionCache();
extern PTR	STDCALL GetCurrentProcess();
#		endif /* !KNR_STYLE */

#		ifdef _WIN64
#			define CLEAR_INSTRUCTION_CACHE(BEGIN, END) \
				FlushInstructionCache(\
					GetCurrentProcess(),\
					(PTR)(BEGIN),\
					(BIT64)((char *)(END) - (char *)(BEGIN))\
				)
#		else
#			define CLEAR_INSTRUCTION_CACHE(BEGIN, END) \
				FlushInstructionCache(\
					GetCurrentProcess(),\
					(PTR)(BEGIN),\
					(unsigned long)((char *)(END) - (char *)(BEGIN))\
				)
#		endif /* _WIN64 */
#	else
#		ifdef __GNUC__
#			define CLEAR_INSTRUCTION_CACHE(BEGIN, END) \
				__builtin___clear_cache((char *)(BEGIN), (char *)(END))
#		else
#			ifdef __clang__
#				define CLEAR_INSTRUCTION_CACHE(BEGIN, END) \
					__builtin___clear_cache((char *)(BEGIN), (char *)(END))
#			endif /* __clang__ */
#		endif /* __GNUC__ */
#	endif /* _MSC_VER */
#	ifndef CLEAR_INSTRUCTION_CACHE
#		define CLEAR_INSTRUCTION_CACHE(BEGIN, END) /* NOTHING */
#	endif /* !CLEAR_INSTRUCTION_CACHE */
#	define clear_instruction_cache CLEAR_INSTRUCTION_CACHE
#endif /* !CLEAR_INSTRUCTION_CACHE_H */

/* * * * * * * * * * * /!\ AUTOMATIC EOF TREATMENT! /!\ * * * * * * * * * * * *\
 * * AT THE ALL END OF FILES, I AM ADDING A SPECIAL BYTE <0X1A> TO END THE  * *
 * *                       FILE IN DOS, CP/M SYSTEMS                        * *
 * *   "//" FOR HANDLING THE BYTE IN MODERN COMPILERS AND #define IS FOR    * *
 * *       HANDLING "//" SYNTAX WHICH IS NOT SUPPORTED ON OLD SYSTEMS       * *
\* * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * */
#undef __CMT__END_OF_FILE__
#define __CMT__END_OF_FILE__ //
