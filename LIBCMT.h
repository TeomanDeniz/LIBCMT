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
# : License - AGPL-3.0  :: Update - 2025/08/02 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

#ifndef LIBCMT_H
#	define LIBCMT_H 202508 /* VERSION */

#	ifndef INCL_OBJECT
#		ifndef INCL_FAR
#			ifndef INCL_PACK
#				ifndef INCL_REGPARM
#					ifndef INCL_ARCHITECTURE
#						define LOCALMACRO_DEFINE_ALL_TRY_1
#					endif /* !INCL_ARCHITECTURE */
#				endif /* !INCL_REGPARM */
#			endif /* !INCL_PACK */
#		endif /* !INCL_FAR */
#	endif /* !INCL_OBJECT */

#	ifdef LOCALMACRO_DEFINE_ALL_TRY_1
#		ifndef INCL_KNR_STYLE
#			ifndef INCL_DLL
#				ifndef INCL_PREFETCH
#					ifndef INCL_READ_FILE
#						ifndef INCL_THREAD
#							define LOCALMACRO_DEFINE_ALL_TRY_2
#						endif /* !INCL_THREAD */
#					endif /* !INCL_READ_FILE */
#				endif /* !INCL_PREFETCH */
#			endif /* !INCL_DLL */
#		endif /* !INCL_KNR_STYLE */
#	endif /* LOCALMACRO_DEFINE_ALL_TRY_1 */

#	ifdef LOCALMACRO_DEFINE_ALL_TRY_2
#		ifndef INCL_IGNORE_VAR
#			ifndef INCL_INLINE
#				ifndef INCL_LOCAL
#					ifndef INCL_NORETURN
#						ifndef INCL_TRY_CATCH
#							define LOCALMACRO_DEFINE_ALL_TRY_3
#						endif /* !INCL_TRY_CATCH */
#					endif /* !INCL_NORETURN */
#				endif /* !INCL_LOCAL */
#			endif /* !INCL_INLINE */
#		endif /* !INCL_IGNORE_VAR */
#	endif /* LOCALMACRO_DEFINE_ALL_TRY_2 */

#	ifdef LOCALMACRO_DEFINE_ALL_TRY_3
#		ifndef INCL_UNUSED
#			ifndef INCL_VA_ARGS
#				ifndef INCL_COMMA_OPERATOR
#					ifndef INCL_TOKEN_PASTING
#						define INCL_OBJECT
#						define INCL_FAR
#						define INCL_PACK
#						define INCL_REGPARM
#						define INCL_ARCHITECTURE
#						define INCL_KNR_STYLE
#						define INCL_DLL
#						define INCL_PREFETCH
#						define INCL_READ_FILE
#						define INCL_THREAD
#						define INCL_IGNORE_VAR
#						define INCL_INLINE
#						define INCL_LOCAL
#						define INCL_NORETURN
#						define INCL_TRY_CATCH
#						define INCL_UNUSED
#						define INCL_VA_ARGS
#						define INCL_TOKEN_PASTING
#						define INCL_COMMA_OPERATOR
#					endif /* !INCL_TOKEN_PASTING */
#				endif /* !INCL_COMMA_OPERATOR */
#			endif /* !INCL_VA_ARGS */
#		endif /* !INCL_UNUSED */
#	endif /* LOCALMACRO_DEFINE_ALL_TRY_3 */

#	ifdef INCL_OBJECT
#		include "OBJECT.h" /*
#		 define OBJECT_FUNCTIONS(OBJECT_NAME)
#		 define object_functions
#		 define OBJECT_FROM(OBJECT_STRUCT_NAME)
#		 define object_from
#		 define OBJECT(OBJECT_NAME, VARIABLE_NAME)
#		 define object
#		        */
#	endif /* INCL_OBJECT */

/* *************************** [v] ATTRIBUTES [v] *************************** */
#	ifdef INCL_FAR
#		include "ATTRIBUTES/FAR.h" /*
#		 define FAR
#		        */
#	endif /* INCL_FAR */
#	ifdef INCL_PACK
#		include "ATTRIBUTES/PACK.h" /*
#		 define PRAGMA_PACK_PUSH
#		 define PRAGMA_PACK_POP
#		 define PACK
#		        */
#	endif /* INCL_PACK */
#	ifdef INCL_REGPARM
#		include "ATTRIBUTES/REGPARM.h" /*
#		 define REGPARM(__REGPARM_NUMBER_OF_VARIABLES__)
#		        */
#	endif /* INCL_REGPARM */
/* *************************** [^] ATTRIBUTES [^] *************************** */

/* ************************* [v] CHECK FEATURE [v] ************************** */
#	ifdef INCL_COMMA_OPERATOR
#		include "CHECK_FEATURE/COMMA_OPERATOR.h" /*
#		 define IS__COMMA_OPERATOR__SUPPORTED
#		        */
#	endif /* INCL_COMMA_OPERATOR */
#	ifdef INCL_TOKEN_PASTING
#		include "CHECK_FEATURE/TOKEN_PASTING.h" /*
#		 define IS__TOKEN_PASTING__SUPPORTED
#		        */
#	endif /* INCL_TOKEN_PASTING */
/* ************************* [^] CHECK FEATURE [^] ************************** */

/* ************************** [v] ENVIRONMENTS [v] ************************** */
#	ifdef INCL_ARCHITECTURE
#		include "ENVIRONMENTS/ARCHITECTURE.h" /*
#		 define __SYSTEM_256_BIT__
#		 define __SYSTEM_128_BIT__
#		 define __SYSTEM_64_BIT__
#		 define __SYSTEM_32_BIT__
#		 define __SYSTEM_31_BIT__
#		 define __SYSTEM_16_BIT__
#		 define __SYSTEM_8_BIT__
#		        */
#	endif /* INCL_ARCHITECTURE */
#	ifdef INCL_KNR_STYLE
#		include "ENVIRONMENTS/KNR_STYLE.h" /*
#		 define KNR_STYLE
#		        */
#	endif /* INCL_KNR_STYLE */
/* ************************** [^] ENVIRONMENTS [^] ************************** */

/* *************************** [v] FUNCTIONS [v] **************************** */
#	ifdef INCL_DLL
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
#	endif /* INCL_DLL */
#	ifdef INCL_PREFETCH
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
#	endif /* INCL_PREFETCH */
#	ifdef INCL_READ_FILE
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
#	endif /* INCL_READ_FILE */
#	ifdef INCL_THREAD
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
#	endif /* INCL_THREAD */
/* *************************** [^] FUNCTIONS [^] **************************** */

/* **************************** [v] KEYWORDS [v] **************************** */
#	ifdef INCL_IGNORE_VAR
#		include "KEYWORDS/IGNORE_VAR.h" /*
#		 define IGNORE_VAR
#		 define ignore_var
#		        */
#	endif /* INCL_IGNORE_VAR */
#	ifdef INCL_INLINE
#		include "KEYWORDS/INLINE.h" /*
#		 define INLINE
#		        */
#	endif /* INCL_INLINE */
#	ifdef INCL_LOCAL
#		include "KEYWORDS/LOCAL.h" /*
#		 define LOCAL
#		 define local
#		        */
#	endif /* INCL_LOCAL */
#	ifdef INCL_NORETURN
#		include "KEYWORDS/NORETURN.h" /*
#		 define NORETURN
#		 define noreturn
#		        */
#	endif /* INCL_NORETURN */
#	ifdef INCL_TRY_CATCH
#		include "KEYWORDS/TRY_CATCH.h" /*
#		 define __TRY_CATCH_BUFFER_SIZE__
#		 define TRY
#		 define try
#		 define CATCH(VARIABLE_NAME)
#		 define catch
#		 define THROW(ERROR_NO)
#		 define throw
#		        */
#	endif /* INCL_TRY_CATCH */
#	ifdef INCL_UNUSED
#		include "KEYWORDS/UNUSED.h" /*
#		 define UNUSED
#		 define unused
#		        */
#	endif /* INCL_UNUSED */
/* **************************** [^] KEYWORDS [^] **************************** */

/* *********************** [v] PLATFORM CROSSING [v] ************************ */
#	ifdef INCL_VA_ARGS
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
#	endif /* INCL_VA_ARGS */
/* *********************** [^] PLATFORM CROSSING [^] ************************ */
#endif /* !LIBCMT_H */
