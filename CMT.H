/******************************************************************************\
# H - CMT                                        #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2025/06/22 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - GPL-3.0   :: Update - 2025/12/25 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

#ifndef CMT_H
#	ifndef __MTLIBC__
#		define __MTLIBC__ 202512 /* VERSION */
#	endif /* !__MTLIBC__ */

/* ****************** [v] LOCALMACRO_DEFINE_ALL_TRY_1 [v] ******************* */
#	ifndef INCL__OBJECT
#		ifndef INCL__FAR
#			ifndef INCL__PACK
#				ifndef INCL__REGPARM
#					ifndef INCL__ARCHITECTURE
#						ifndef INCL__CPU
#							ifdef INCL__RAX
#								ifdef INCL__X17
#									ifdef INCL__STDCALL
#										define LOCALMACRO_DEFINE_ALL_TRY_1
#									endif /* INCL__STDCALL */
#								endif /* INCL__X17 */
#							endif /* INCL__RAX */
#						endif /* !INCL__CPU */
#					endif /* !INCL__ARCHITECTURE */
#				endif /* !INCL__REGPARM */
#			endif /* !INCL__PACK */
#		endif /* !INCL__FAR */
#	endif /* !INCL__OBJECT */
/* ****************** [^] LOCALMACRO_DEFINE_ALL_TRY_1 [^] ******************* */

/* ****************** [v] LOCALMACRO_DEFINE_ALL_TRY_2 [v] ******************* */
#	ifdef LOCALMACRO_DEFINE_ALL_TRY_1
#		undef LOCALMACRO_DEFINE_ALL_TRY_1
#		ifndef INCL__KNR_STYLE
#			ifndef INCL__CLEAR_INSTRUCTION_CACHE
#				ifndef INCL__DLL
#					ifndef INCL__PREFETCH
#						ifndef INCL__READ_FILE
#							ifndef INCL__THREAD
#								ifndef INCL__STRINGIFICATION
#									ifndef INCL__ROM
#										define LOCALMACRO_DEFINE_ALL_TRY_2
#									ifndef /* !INCL__ROM */
#								endif /* !INCL__STRINGIFICATION */
#							endif /* !INCL__THREAD */
#						endif /* !INCL__READ_FILE */
#					endif /* !INCL__PREFETCH */
#				endif /* !INCL__DLL */
#			endif /* !INCL__CLEAR_INSTRUCTION_CACHE */
#		endif /* !INCL__KNR_STYLE */
#	endif /* LOCALMACRO_DEFINE_ALL_TRY_1 */
/* ****************** [^] LOCALMACRO_DEFINE_ALL_TRY_2 [^] ******************* */

/* ****************** [v] LOCALMACRO_DEFINE_ALL_TRY_3 [v] ******************* */
#	ifdef LOCALMACRO_DEFINE_ALL_TRY_2
#		undef LOCALMACRO_DEFINE_ALL_TRY_2
#		ifndef INCL__IGNORE_VAR
#			ifndef INCL__INLINE
#				ifndef INCL__LOCAL
#					ifndef INCL__NORETURN
#						ifndef INCL__TRY_CATCH
#							define LOCALMACRO_DEFINE_ALL_TRY_3
#						endif /* !INCL__TRY_CATCH */
#					endif /* !INCL__NORETURN */
#				endif /* !INCL__LOCAL */
#			endif /* !INCL__INLINE */
#		endif /* !INCL__IGNORE_VAR */
#	endif /* LOCALMACRO_DEFINE_ALL_TRY_2 */
/* ****************** [^] LOCALMACRO_DEFINE_ALL_TRY_3 [^] ******************* */

/* ****************** [v] LOCALMACRO_DEFINE_ALL_TRY_4 [v] ******************* */
#	ifdef LOCALMACRO_DEFINE_ALL_TRY_3
#		undef LOCALMACRO_DEFINE_ALL_TRY_3
#		ifndef INCL__ASM
#			ifndef INCL__ATTRIBUTES
#				ifndef INCL__CHECK_FEATURE
#					ifndef INCL__ENVIRONMENTS
#						ifndef INCL__FUNCTIONS
#							ifndef INCL__KEYWORDS
#								define LOCALMACRO_DEFINE_ALL_TRY_4
#							endif /* !INCL__KEYWORDS */
#						endif /* !INCL__FUNCTIONS */
#					endif /* !INCL__ENVIRONMENTS */
#				endif /* !INCL__CHECK_FEATURE */
#			endif /* !INCL__ATTRIBUTES */
#		endif /* !INCL__ASM */
#	endif /* LOCALMACRO_DEFINE_ALL_TRY_3 */
/* ****************** [^] LOCALMACRO_DEFINE_ALL_TRY_4 [^] ******************* */

/* ********************* [v] LOCALMACRO_DEFINE_ALL [v] ********************** */
#	ifdef LOCALMACRO_DEFINE_ALL_TRY_4
#		undef LOCALMACRO_DEFINE_ALL_TRY_4
#		ifndef INCL__UNUSED
#			ifndef INCL__VA_ARGS
#				ifndef INCL__COMMA_OPERATOR
#					ifndef INCL__TOKEN_PASTING
#						ifndef INCL__INLINE_ASM
#							define LOCALMACRO_DEFINE_ALL
#						endif /* !INCL__INLINE_ASM */
#					endif /* !INCL__TOKEN_PASTING */
#				endif /* !INCL__COMMA_OPERATOR */
#			endif /* !INCL__VA_ARGS */
#		endif /* !INCL__UNUSED */
#	endif /* LOCALMACRO_DEFINE_ALL_TRY_3 */
/* ********************* [^] LOCALMACRO_DEFINE_ALL [^] ********************** */

/* ************************ [v] CMT JUST CALLED [v] ************************* */
#	ifdef LOCALMACRO_DEFINE_ALL
#		undef LOCALMACRO_DEFINE_ALL
#		define CMT_H __MTLIBC__
#		ifndef __cplusplus /* PLEASE USE CLASSES IN C++ */
#			define INCL__OBJECT
#		endif /* !__cplusplus */
#		define INCL__ASM
#		define INCL__ATTRIBUTES
#		define INCL__CHECK_FEATURE
#		define INCL__ENVIRONMENTS
#		define INCL__FUNCTIONS
#		define INCL__KEYWORDS
#	endif /* LOCALMACRO_DEFINE_ALL */
/* ************************ [^] CMT JUST CALLED [^] ************************* */

/* ****************************** [v] ASM [v] ******************************* */
#	ifdef INCL__ASM
#		undef INCL__ASM
#		ifndef INCL__RAX
#			define INCL__RAX
#		endif /* !INCL__RAX */
#		ifndef INCL__X17
#			define INCL__X17
#		endif /* !INCL__X17 */
#	endif /* INCL__ASM */
/* ****************************** [^] ASM [^] ******************************* */

/* *************************** [v] ATTRIBUTES [v] *************************** */
#	ifdef INCL__ATTRIBUTES
#		undef INCL__ATTRIBUTES
#		ifndef INCL__FAR
#			define INCL__FAR
#		endif /* !INCL__FAR */
#		ifndef INCL__PACK
#			define INCL__PACK
#		endif /* !INCL__PACK */
#		ifndef INCL__REGPARM
#			define INCL__REGPARM
#		endif /* !INCL__REGPARM */
#	endif /* INCL__ATTRIBUTES */
/* *************************** [^] ATTRIBUTES [^] *************************** */

/* ************************* [v] CHECK FEATURE [v] ************************** */
#	ifdef INCL__CHECK_FEATURE
#		undef INCL__CHECK_FEATURE
#		ifndef INCL__STRINGIFICATION
#			define INCL__STRINGIFICATION
#		endif /* !INCL__STRINGIFICATION */
#		ifndef INCL__TOKEN_PASTING
#			define INCL__TOKEN_PASTING
#		endif /* !INCL__TOKEN_PASTING */
#		ifndef INCL__COMMA_OPERATOR
#			define INCL__COMMA_OPERATOR
#		endif /* !INCL__COMMA_OPERATOR */
#		ifndef INCL__INLINE_ASM
#			define INCL__INLINE_ASM
#		endif /* !INCL__INLINE_ASM */
#	endif /* INCL__CHECK_FEATURE */
/* ************************* [^] CHECK FEATURE [^] ************************** */

/* ************************** [v] ENVIRONMENTS [v] ************************** */
#	ifdef INCL__ENVIRONMENTS
#		undef INCL__ENVIRONMENTS
#		ifndef INCL__ARCHITECTURE
#			define INCL__ARCHITECTURE
#		endif /* !INCL__ARCHITECTURE */
#		ifndef INCL__CPU
#			define INCL__CPU
#		endif /* !INCL__CPU */
#		ifndef INCL__KNR_STYLE
#			define INCL__KNR_STYLE
#		endif /* !INCL__KNR_STYLE */
#	endif /* INCL__ENVIRONMENTS */
/* ************************** [^] ENVIRONMENTS [^] ************************** */

/* *************************** [v] FUNCTIONS [v] **************************** */
#	ifdef INCL__FUNCTIONS
#		undef INCL__FUNCTIONS
#		ifndef INCL__CLEAR_INSTRUCTION_CACHE
#			define INCL__CLEAR_INSTRUCTION_CACHE
#		endif /* !INCL__CLEAR_INSTRUCTION_CACHE */
#		ifndef INCL__DLL
#			define INCL__DLL
#		endif /* !INCL__DLL */
#		ifndef INCL__PREFETCH
#			define INCL__PREFETCH
#		endif /* !INCL__PREFETCH */
#		ifndef INCL__READ_FILE
#			define INCL__READ_FILE
#		endif /* !INCL__READ_FILE */
#		ifndef INCL__THREAD
#			define INCL__THREAD
#		endif /* !INCL__THREAD */
#	endif /* INCL__FUNCTIONS */
/* *************************** [^] FUNCTIONS [^] **************************** */

/* **************************** [v] KEYWORDS [v] **************************** */
#	ifdef INCL__KEYWORDS
#		undef INCL__KEYWORDS
#		ifndef INCL__IGNORE_VAR
#			define INCL__IGNORE_VAR
#		endif /* !INCL__IGNORE_VAR */
#		ifndef INCL__INLINE
#			define INCL__INLINE
#		endif /* !INCL__INLINE */
#		ifndef INCL__LOCAL
#			define INCL__LOCAL
#		endif /* !INCL__LOCAL */
#		ifndef INCL__NORETURN
#			define INCL__NORETURN
#		endif /* !INCL__NORETURN */
#		ifndef INCL__TRY_CATCH
#			define INCL__TRY_CATCH
#		endif /* !INCL__TRY_CATCH */
#		ifndef INCL__UNUSED
#			define INCL__UNUSED
#		endif /* !INCL__UNUSED */
#		ifndef INCL__VA_ARGS
#			define INCL__VA_ARGS
#		endif /* !INCL__VA_ARGS */
#		ifndef INCL__STDCALL
#			define INCL__STDCALL
#		endif /* !INCL__STDCALL */
#		ifndef INCL__ROM
#			define INCL__ROM
#		endif /* !INCL__ROM */
#	endif /* INCL__KEYWORDS */
/* **************************** [^] KEYWORDS [^] **************************** */

/* ***************************** [v] OBJECT [v] ***************************** */
#	ifdef INCL__OBJECT
#		undef INCL__OBJECT
#		include "OBJECT.H" /*
#		 define OBJECT_FUNCTIONS(OBJECT_NAME)
#		 define object_functions
#		 define OBJECT_FROM(OBJECT_STRUCT_NAME)
#		 define object_from
#		 define OBJECT(OBJECT_NAME, VARIABLE_NAME)
#		 define object
#		        */
#	endif /* INCL__OBJECT */
/* ***************************** [^] OBJECT [^] ***************************** */

/* ****************************** [v] ASM [v] ******************************* */
#	ifdef INCL__RAX
#		undef INCL__RAX
#		include "ASM/INTEL/RAX.H" /*
#		 define GET_RAX(VARIABLE)
#		 define SET_RAX(VALUE)
#		        */
#	endif /* INCL__RAX */
#	ifdef INCL__X17
#		undef INCL__X17
#		include "ASM/ARM/X17.H" /*
#		 define GET_X17(VARIABLE)
#		 define SET_X17(VALUE)
#		        */
#	endif /* INCL__X17 */
/* ****************************** [^] ASM [^] ******************************* */

/* *************************** [v] ATTRIBUTES [v] *************************** */
#	ifdef INCL__FAR
#		undef INCL__FAR
#		include "ATTRIBUTES/FAR.H" /*
#		 define FAR
#		        */
#	endif /* INCL__FAR */
#	ifdef INCL__PACK
#		undef INCL__PACK
#		include "ATTRIBUTES/PACK.H" /*
#		 define PRAGMA_PACK_PUSH
#		 define PRAGMA_PACK_POP
#		 define PACK
#		        */
#	endif /* INCL__PACK */
#	ifdef INCL__REGPARM
#		undef INCL__REGPARM
#		include "ATTRIBUTES/REGPARM.H" /*
#		 define REGPARM(__REGPARM_NUMBER_OF_VARIABLES__)
#		        */
#	endif /* INCL__REGPARM */
/* *************************** [^] ATTRIBUTES [^] *************************** */

/* ************************* [v] CHECK FEATURE [v] ************************** */
#	ifdef INCL__COMMA_OPERATOR
#		undef INCL__COMMA_OPERATOR
#		include "CHECK_FEATURE/COMMA_OPERATOR.H" /*
#		 define IS__COMMA_OPERATOR__SUPPORTED
#		        */
#	endif /* INCL__COMMA_OPERATOR */
#	ifdef INCL__INLINE_ASM
#		undef INCL__INLINE_ASM
#		include "CHECK_FEATURE/INLINE_ASM.H" /*
#		 define IS__INLINE_ASM__SUPPORTED
#		 define INLINE_ASM_TYPE__GNU
#		 define INLINE_ASM_TYPE__MSVC
#		 define INLINE_ASM_TYPE__BORLAND
#		 define INLINE_ASM_TYPE__AZTEC
#		 define INLINE_ASM_TYPE__LATTICE
#		 define INLINE_ASM_TYPE__INTEL_MS
#		 define INLINE_ASM_TYPE__WATCOM
#		 define INLINE_ASM_TYPE__ARM
#		 define INLINE_ASM_TYPE__KEIL
#		 define INLINE_ASM_TYPE__HCCF
#		 define INLINE_ASM_TYPE__ISO
#		        */
#	endif /* INCL__INLINE_ASM */
#	ifdef INCL__STRINGIFICATION
#		undef INCL__STRINGIFICATION
#		include "CHECK_FEATURE/STRINGIFICATION.H" /*
#		 define IS__STRINGIFICATION__SUPPORTED
#		        */
#	endif /* INCL__STRINGIFICATION */
#	ifdef INCL__TOKEN_PASTING
#		undef INCL__TOKEN_PASTING
#		include "CHECK_FEATURE/TOKEN_PASTING.H" /*
#		 define IS__TOKEN_PASTING__SUPPORTED
#		        */
#	endif /* INCL__TOKEN_PASTING */
/* ************************* [^] CHECK FEATURE [^] ************************** */

/* ************************** [v] ENVIRONMENTS [v] ************************** */
#	ifdef INCL__ARCHITECTURE
#		undef INCL__ARCHITECTURE
#		include "ENVIRONMENTS/ARCHITECTURE.H" /*
#		 define __SYSTEM_64_BIT__
#		 define __SYSTEM_32_BIT__
#		 define __SYSTEM_31_BIT__
#		 define __SYSTEM_16_BIT__
#		 define __SYSTEM_8_BIT__
#		 define __SYSTEM_BIT__
#		 define __HAS_128_BIT__
#		 define __HAS_64_BIT__
#		 define __HAS_512_BIT_VECTOR__
#		 define __HAS_256_BIT_VECTOR__
#		 define __HAS_128_BIT_VECTOR__
#		        */
#	endif /* INCL__ARCHITECTURE */
#	ifdef INCL__CPU
#		undef INCL__CPU
#		include "ENVIRONMENTS/CPU.H" /*
#		 define __CPU_INTEL__
#		 define __CPU_ARM__
#		 define __CPU_AMD_X86__
#		 define __CPU_POWERPC__
#		 define __CPU_RISCV__
#		 define __CPU_HC12__
#		 define __CPU_HCS08__
#		 define __CPU_COLDFIRE__
#		 define __CPU_M68K__
#		 define __CPU_SH__
#		 define __CPU_MIPS__
#		 define __CPU_SPARC__
#		 define __CPU_6502__
#		 define __CPU_Z80__
#		 define __CPU_TI__
#		 define __CPU_SHARC__
#		 define __CPU_BLACKFIN__
#		 define __CPU_DSP56K__
#		   char *__CPU_VER__();
#		        */
#	endif /* INCL__CPU */
#	ifdef INCL__KNR_STYLE
#		undef INCL__KNR_STYLE
#		include "ENVIRONMENTS/KNR_STYLE.H" /*
#		 define KNR_STYLE
#		 define void
#		 define const
#		 define volatile
#		 define signed
#		 define unsigned
#		        */
#	endif /* INCL__KNR_STYLE */
/* ************************** [^] ENVIRONMENTS [^] ************************** */

/* *************************** [v] FUNCTIONS [v] **************************** */
#	ifdef INCL__CLEAR_INSTRUCTION_CACHE
#		undef INCL__CLEAR_INSTRUCTION_CACHE
#		include "FUNCTIONS/INCL__CLEAR_INSTRUCTION_CACHE.H" /*
#		 define CLEAR_INSTRUCTION_CACHE
#		 define clear_instruction_cache
#		        */
#	endif /* INCL__CLEAR_INSTRUCTION_CACHE */
#	ifdef INCL__DLL
#		undef INCL__DLL
#		include "FUNCTIONS/DLL.H" /*
#		 define OPEN_DLL(DLL_FILE)
#		 define open_dll
#		 define READ_DLL(THE_DLL, FUNCTION_NAME)
#		 define read_dll
#		 define CLOSE_DLL(DLL_FILE_FOR_CLOSE)
#		 define close_dll
#		 define DYNAMIC
#		 define dynamic
#		typedef DLL;
#		typedef dll;
#		        */
#	endif /* INCL__DLL */
#	ifdef INCL__PREFETCH
#		undef INCL__PREFETCH
#		include "FUNCTIONS/PREFETCH.H" /*
#		 define PREFETCH(__PREFETCH_VARIABLE__)
#		 define prefetch
#		 define PREFETCHW(__PREFETCHW_VARIABLE__)
#		 define prefetchw
#		 define SPIN_LOCK_PREFETCH(__SPIN_LOCK_PREFETCH_VARIABLE__)
#		 define spin_lock_prefetch(__spin_lock_prefetch_variable__)
#		   void PREFETCH_RANGE(void *, uint);
#		   void prefetch_range(void *, uint);
#		        */
#	endif /* INCL__PREFETCH */
#	ifdef INCL__READ_FILE
#		undef INCL__READ_FILE
#		include "FUNCTIONS/READ_FILE.H" /*
#		 struct S_FILE;
#		 struct s_file;
#		typedef T_FILE;
#		typedef t_file;
#		    int READ_FILE(char *, struct S_FILE *);
#		    int read_file(char *, struct s_file *);
#		C++
#		    int READ_FILE(const std::string &, struct S_FILE *);
#		    int read_file(const std::string &, struct s_file *);
#		C--
#		        */
#	endif /* INCL__READ_FILE */
#	ifdef INCL__THREAD
#		undef INCL__THREAD
#		include "FUNCTIONS/THREAD.H" /*
#		 define MUTEX_LOCK(__MUTEX_LOCK__)
#		 define mutex_lock(__mutex_lock__)
#		 define MUTEX_UNLOCK(__MUTEX_UNLOCK__)
#		 define mutex_unlock(__mutex_unlock__)
#		typedef T_THREAD;
#		typedef t_thread;
#		typedef T_MUTEX;
#		typedef t_mutex;
#		>>>>>>> T_THREAD
#		^^^^^^^ THREAD_CREATE(void (*)(void *), void *);
#		>>>>>>> t_thread
#		^^^^^^^ thread_create(void (*)(void *), void *);
#		    int THREAD_JOIN(T_THREAD, void **);
#		    int thread_join(t_thread, void **);
#		T_MUTEX MUTEX_CREATE(void);
#		t_mutex mutex_create(void);
#		    int MUTEX_DESTROY(T_MUTEX);
#		    int mutex_destroy(t_mutex);
#		        */
#	endif /* INCL__THREAD */
/* *************************** [^] FUNCTIONS [^] **************************** */

/* **************************** [v] KEYWORDS [v] **************************** */
#	ifdef INCL__IGNORE_VAR
#		undef INCL__IGNORE_VAR
#		include "KEYWORDS/IGNORE_VAR.H" /*
#		 define IGNORE_VAR
#		 define ignore_var
#		        */
#	endif /* INCL__IGNORE_VAR */
#	ifdef INCL__INLINE
#		undef INCL__INLINE
#		include "KEYWORDS/INLINE.H" /*
#		 define INLINE
#		        */
#	endif /* INCL__INLINE */
#	ifdef INCL__LOCAL
#		undef INCL__LOCAL
#		include "KEYWORDS/LOCAL.H" /*
#		 define LOCAL
#		 define local
#		        */
#	endif /* INCL__LOCAL */
#	ifdef INCL__NORETURN
#		undef INCL__NORETURN
#		include "KEYWORDS/NORETURN.H" /*
#		 define NORETURN
#		 define noreturn
#		        */
#	endif /* INCL__NORETURN */
#	ifdef INCL__STDCALL
#		undef INCL__STDCALL
#		include "KEYWORDS/STDCALL.H" /*
#		 define STDCALL
#		        */
#	endif /* INCL__STDCALL */
#	ifdef INCL__ROM
#		undef INCL__ROM
#		include "KEYWORDS/ROM.H" /*
#		 define ROM
#		        */
#	endif /* INCL__ROM */
#	ifdef INCL__TRY_CATCH
#		undef INCL__TRY_CATCH
#		include "KEYWORDS/TRY_CATCH.H" /*
#		 define __TRY_CATCH_BUFFER_SIZE__
#		 define TRY
#		 define try
#		 define CATCH(VARIABLE_NAME)
#		 define catch
#		 define THROW(ERROR_NO)
#		 define throw
#		        */
#	endif /* INCL__TRY_CATCH */
#	ifdef INCL__TYPES
#		undef INCL__TYPES
#		include "KEYWORDS/TYPES.H" /*
#		 define SUPPORTED__BIT64
#		 define SUPPORTED__BIT128
#		 define SUPPORTED__FLOAT64
#		 define SUPPORTED__FLOAT128
#		typedef BYTE;
#		typedef byte;
#		typedef LET;
#		typedef let;
#		typedef VAR;
#		typedef var;
#		typedef PTR;
#		typedef ptr;
#		typedef BIT8;
#		typedef bit8;
#		typedef BIT16;
#		typedef bit16;
#		typedef BIT32;
#		typedef bit32;
#		typedef BIT64;
#		typedef bit64;
#		typedef BIT128;
#		typedef bit128;
#		typedef FLOAT32;
#		typedef float32;
#		typedef FLOAT64;
#		typedef float64;
#		typedef FLOAT128;
#		typedef float128;
#		        */
#	endif /* INCL__TYPES */
#	ifdef INCL__UNUSED
#		undef INCL__UNUSED
#		include "KEYWORDS/UNUSED.H" /*
#		 define UNUSED
#		 define unused
#		        */
#	endif /* INCL__UNUSED */
#	ifdef INCL__VA_ARGS
#		undef INCL__VA_ARGS
#		include "KEYWORDS/VA_ARGS.H" /*
#		 define va_arg(A, B)
#		 define VA_ARG
#		 define va_copy(A, B)
#		 define VA_COPY
#		 define va_start(A, B)
#		 define VA_START
#		 define va_end(A)
#		 define VA_END
#		typedef va_list;
#		typedef VA_LIST;
#		        */
#	endif /* INCL__VA_ARGS */
/* **************************** [^] KEYWORDS [^] **************************** */
#endif /* !CMT_H */

/* * * * * * * * * * * /!\ AUTOMATIC EOF TREATMENT! /!\ * * * * * * * * * * * *\
 * * AT THE ALL END OF FILES, I AM ADDING A SPECIAL BYTE <0X1A> TO END THE  * *
 * *                       FILE IN DOS, CP/M SYSTEMS                        * *
 * *   "//" FOR HANDLING THE BYTE IN MODERN COMPILERS AND #define IS FOR    * *
 * *       HANDLING "//" SYNTAX WHICH IS NOT SUPPORTED ON OLD SYSTEMS       * *
\* * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * */
#undef __CMT__END_OF_FILE__
#define __CMT__END_OF_FILE__ //
