/******************************************************************************\
# H - LIBCMT                                     #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2025/06/22 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - GPL-3.0   :: Update - 2025/08/27 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

#ifndef LIBCMT_H
#	define LIBCMT_H 202508 /* VERSION */

/* ****************** [v] LOCALMACRO_DEFINE_ALL_TRY_1 [v] ******************* */
#	ifndef INCL__OBJECT
#		ifndef INCL__PUSH_POP
#			ifndef INCL__FAR
#				ifndef INCL__PACK
#					ifndef INCL__REGPARM
#						ifndef INCL__ARCHITECTURE
#							ifndef INCL__CPU
#								define LOCALMACRO_DEFINE_ALL_TRY_1
#							endif /* !INCL__CPU */
#						endif /* !INCL__ARCHITECTURE */
#					endif /* !INCL__REGPARM */
#				endif /* !INCL__PACK */
#			endif /* !INCL__FAR */
#		endif /* !INCL__PUSH_POP */
#	endif /* !INCL__OBJECT */
/* ****************** [^] LOCALMACRO_DEFINE_ALL_TRY_1 [^] ******************* */

/* ****************** [v] LOCALMACRO_DEFINE_ALL_TRY_2 [v] ******************* */
#	ifdef LOCALMACRO_DEFINE_ALL_TRY_1
#		ifndef INCL__KNR_STYLE
#			ifndef INCL__DLL
#				ifndef INCL__PREFETCH
#					ifndef INCL__READ_FILE
#						ifndef INCL__THREAD
#							define LOCALMACRO_DEFINE_ALL_TRY_2
#						endif /* !INCL__THREAD */
#					endif /* !INCL__READ_FILE */
#				endif /* !INCL__PREFETCH */
#			endif /* !INCL__DLL */
#		endif /* !INCL__KNR_STYLE */
#	endif /* LOCALMACRO_DEFINE_ALL_TRY_1 */
/* ****************** [^] LOCALMACRO_DEFINE_ALL_TRY_2 [^] ******************* */

/* ****************** [v] LOCALMACRO_DEFINE_ALL_TRY_3 [v] ******************* */
#	ifdef LOCALMACRO_DEFINE_ALL_TRY_2
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

/* ********************* [v] LOCALMACRO_DEFINE_ALL [v] ********************** */
#	ifdef LOCALMACRO_DEFINE_ALL_TRY_3
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

/* *********************** [v] LIBCMT JUST CALLED [v] *********************** */
#	ifdef LOCALMACRO_DEFINE_ALL
#		define INCL__OBJECT
#		define INCL__FAR
#		define INCL__PACK
#		define INCL__REGPARM
#		define INCL__ARCHITECTURE
#		define INCL__CPU
#		define INCL__KNR_STYLE
#		define INCL__DLL
#		define INCL__PREFETCH
#		define INCL__READ_FILE
#		define INCL__THREAD
#		define INCL__IGNORE_VAR
#		define INCL__INLINE
#		define INCL__LOCAL
#		define INCL__NORETURN
#		define INCL__TRY_CATCH
#		define INCL__UNUSED
#		define INCL__VA_ARGS
#		define INCL__TOKEN_PASTING
#		define INCL__COMMA_OPERATOR
#		define INCL__INLINE_ASM
#	endif /* LOCALMACRO_DEFINE_ALL */
/* *********************** [^] LIBCMT JUST CALLED [^] *********************** */

/* ***************************** [v] OBJECT [v] ***************************** */
#	ifdef INCL__OBJECT
#		include "OBJECT.h" /*
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
#	ifdef INCL__PUSH_POP
#		include "ASM/PUSH_POP.h" /*
#		 define PUSH(PUSH_VAR)
#		 define push
#		 define POP(POP_VAR)
#		 define pop
#		        */
#	endif /* INCL__PUSH_POP */
/* ****************************** [^] ASM [^] ******************************* */

/* *************************** [v] ATTRIBUTES [v] *************************** */
#	ifdef INCL__FAR
#		include "ATTRIBUTES/FAR.h" /*
#		 define FAR
#		        */
#	endif /* INCL__FAR */
#	ifdef INCL__PACK
#		include "ATTRIBUTES/PACK.h" /*
#		 define PRAGMA_PACK_PUSH
#		 define PRAGMA_PACK_POP
#		 define PACK
#		        */
#	endif /* INCL__PACK */
#	ifdef INCL__REGPARM
#		include "ATTRIBUTES/REGPARM.h" /*
#		 define REGPARM(__REGPARM_NUMBER_OF_VARIABLES__)
#		        */
#	endif /* INCL__REGPARM */
/* *************************** [^] ATTRIBUTES [^] *************************** */

/* ************************* [v] CHECK FEATURE [v] ************************** */
#	ifdef INCL__COMMA_OPERATOR
#		include "CHECK_FEATURE/COMMA_OPERATOR.h" /*
#		 define IS__COMMA_OPERATOR__SUPPORTED
#		        */
#	endif /* INCL__COMMA_OPERATOR */
#	ifdef INCL__INLINE_ASM
#		include "CHECK_FEATURE/INLINE_ASM.h" /*
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
#	ifdef INCL__TOKEN_PASTING
#		include "CHECK_FEATURE/TOKEN_PASTING.h" /*
#		 define IS__TOKEN_PASTING__SUPPORTED
#		        */
#	endif /* INCL__TOKEN_PASTING */
/* ************************* [^] CHECK FEATURE [^] ************************** */

/* ************************** [v] ENVIRONMENTS [v] ************************** */
#	ifdef INCL__ARCHITECTURE
#		include "ENVIRONMENTS/ARCHITECTURE.h" /*
#		 define __SYSTEM_256_BIT__
#		 define __SYSTEM_128_BIT__
#		 define __SYSTEM_64_BIT__
#		 define __SYSTEM_32_BIT__
#		 define __SYSTEM_31_BIT__
#		 define __SYSTEM_16_BIT__
#		 define __SYSTEM_8_BIT__
#		        */
#	endif /* INCL__CPU */
#		include "ENVIRONMENTS/CPU.h" /*
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
#		 define __CPU_VER__
#		   char *__CPU_VER__();
#		        */
#	endif /* INCL__CPU */
#	ifdef INCL__KNR_STYLE
#		include "ENVIRONMENTS/KNR_STYLE.h" /*
#		 define KNR_STYLE
#		        */
#	endif /* INCL__KNR_STYLE */
/* ************************** [^] ENVIRONMENTS [^] ************************** */

/* *************************** [v] FUNCTIONS [v] **************************** */
#	ifdef INCL__DLL
#		include "FUNCTIONS/DLL.h" /*
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
#		include "FUNCTIONS/PREFETCH.h" /*
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
#		include "FUNCTIONS/READ_FILE.h" /*
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
#		include "FUNCTIONS/THREAD.h" /*
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
#		include "KEYWORDS/IGNORE_VAR.h" /*
#		 define IGNORE_VAR
#		 define ignore_var
#		        */
#	endif /* INCL__IGNORE_VAR */
#	ifdef INCL__INLINE
#		include "KEYWORDS/INLINE.h" /*
#		 define INLINE
#		        */
#	endif /* INCL__INLINE */
#	ifdef INCL__LOCAL
#		include "KEYWORDS/LOCAL.h" /*
#		 define LOCAL
#		 define local
#		        */
#	endif /* INCL__LOCAL */
#	ifdef INCL__NORETURN
#		include "KEYWORDS/NORETURN.h" /*
#		 define NORETURN
#		 define noreturn
#		        */
#	endif /* INCL__NORETURN */
#	ifdef INCL__TRY_CATCH
#		include "KEYWORDS/TRY_CATCH.h" /*
#		 define __TRY_CATCH_BUFFER_SIZE__
#		 define TRY
#		 define try
#		 define CATCH(VARIABLE_NAME)
#		 define catch
#		 define THROW(ERROR_NO)
#		 define throw
#		        */
#	endif /* INCL__TRY_CATCH */
#	ifdef INCL__UNUSED
#		include "KEYWORDS/UNUSED.h" /*
#		 define UNUSED
#		 define unused
#		        */
#	endif /* INCL__UNUSED */
/* **************************** [^] KEYWORDS [^] **************************** */

/* *********************** [v] PLATFORM CROSSING [v] ************************ */
#	ifdef INCL__VA_ARGS
#		include "PLATFORM_CROSSING/VA_ARGS.h" /*
#		 define va_add(A, B)
#		 define VA_ADD
#		 define va_arg(A, B)
#		 define VA_ARG
#		 define va_copy(A, B)
#		 define VA_COPY
#		 define va_push
#		 define VA_PUSH
#		 define va_pop
#		 define VA_POP
#		 define va_start(A, B)
#		 define VA_START
#		 define va_args
#		 define VA_ARGS
#		 define va_end(A)
#		 define VA_END
#		typedef va_list;
#		typedef VA_LIST;
#		        */
#	endif /* INCL__VA_ARGS */
/* *********************** [^] PLATFORM CROSSING [^] ************************ */
#endif /* !LIBCMT_H */
