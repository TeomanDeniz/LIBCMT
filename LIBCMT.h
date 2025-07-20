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
# : License - AGPL-3.0  :: Update - 2025/07/09 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

#ifndef LIBCMT_H
#	define LIBCMT_H 202507 /* VERSION */
#	include "./OBJECT.h" /*
#	 define OBJECT_FUNCTIONS(OBJCET_NAME)
#	 define object_functions
#	 define OBJECT_FROM(OBJECT_STRUCT_NAME)
#	 define object_from
#	 define OBJECT(OBJCET_NAME, VARIABLE_NAME)
#	 define object
#	        */
#	include "./ATTRIBUTES/FAR.h" /*
#	 define FAR
#	        */
#	include "./ATTRIBUTES/PACK.h" /*
#	 define PRAGMA_PACK_PUSH
#	 define PRAGMA_PACK_POP
#	 define PACK
#	        */
#	include "./ATTRIBUTES/REGPARM.h" /*
#	 define REGPARM(__REGPARM_NUMBER_OF_VARIABLES__)
#	        */
#	include "./ENVIRONEMTS/ARCHITECTURE.h" /*
#	 define __SYSTEM_256_BIT__
#	 define __SYSTEM_128_BIT__
#	 define __SYSTEM_64_BIT__
#	 define __SYSTEM_32_BIT__
#	 define __SYSTEM_31_BIT__
#	 define __SYSTEM_16_BIT__
#	 define __SYSTEM_8_BIT__
#	        */
#	include "./ENVIRONEMTS/KNR_STYLE.h" /*
#	 define KNR_STYLE
#	        */
#	include "./FUNCTIONS/DLL.h" /*
#	 define OPEN_DLL(DLL_FILE)
#	 define open_dll
#	 define READ_DLL(THE_DLL, FUNCTION_NAME)
#	 define read_dll
#	 define CLOSE_DLL(DLL_FILE_FOR_CLOSE)
#	 define close_dll
#	 define DYNAMIC
#	 define dynamic
#	typedef DLL;
#	typedef dll;
#	        */
#	include "./FUNCTIONS/PREFETCH.h" /*
#	 define PREFETCH(__PREFETCH_VARIABLE__)
#	 define prefetch
#	 define PREFETCHW(__PREFETCHW_VARIABLE__)
#	 define prefetchw
#	 define SPIN_LOCK_PREFETCH(__SPIN_LOCK_PREFETCH_VARIABLE__)
#	 define spin_lock_prefetch(__spin_lock_prefetch_variable__)
#	   void PREFETCH_RANGE(void *, uint);
#	   void prefetch_range(void *, uint);
#	        */
#	include "./FUNCTIONS/READ_FILE.h" /*
#	 struct S_FILE;
#	 struct s_file;
#	typedef T_FILE;
#	typedef t_file;
#	    int READ_FILE(char *, struct S_FILE *);
#	    int read_file(char *, struct s_file *);
#	    int READ_FILE(const std::string &, struct S_FILE *); // C++
#	    int read_file(const std::string &, struct s_file *); // C++
#	        */
#	include "./FUNCTIONS/THREAD.h" /*
#	 define MUTEX_LOCK(__MUTEX_LOCK__)
#	 define mutex_lock(__mutex_lock__)
#	 define MUTEX_UNLOCK(__MUTEX_UNLOCK__)
#	 define mutex_unlock(__mutex_unlock__)
#	typedef T_THREAD;
#	typedef t_thread;
#	typedef T_MUTEX;
#	typedef t_mutex;
#	>>>>>>> T_THREAD
#	^^^^^^^ THREAD_CREATE(void (*)(void *), void *);
#	>>>>>>> t_thread
#	^^^^^^^ thread_create(void (*)(void *), void *);
#	    int THREAD_JOIN(T_THREAD, void **);
#	    int thread_join(t_thread, void **);
#	T_MUTEX MUTEX_CREATE(void);
#	t_mutex mutex_create(void);
#	    int MUTEX_DESTROY(T_MUTEX);
#	    int mutex_destroy(t_mutex);
#	        */
#	include "./KEYWORDS/IGNORE_VAR.h" /*
#	 define IGNORE_VAR
#	 define ignore_var
#	        */
#	include "./KEYWORDS/INLINE.h" /*
#	 define INLINE
#	        */
#	include "./KEYWORDS/LOCAL.h" /*
#	 define LOCAL
#	 define local
#	        */
#	include "./KEYWORDS/NORETURN.h" /*
#	 define NORETURN
#	 define noreturn
#	        */
#	include "./KEYWORDS/TRY_CATCH.h" /*
#	 define __TRY_CATCH_BUFFER_SIZE__
#	 define TRY
#	 define try
#	 define CATCH(VARIABLE_NAME)
#	 define catch
#	 define THROW(ERROR_NO)
#	 define throw
#	        */
#	include "./KEYWORDS/UNUSED.h" /*
#	 define UNUSED
#	 define unused
#	        */
#	include "./PLATFORM_CROSSING/VA_ARGS.h" /*
#	 define va_add(A, B)
#	 define VA_ADD
#	 define va_arg(A, B)
#	 define VA_ARG
#	 define va_copy(A, B)
#	 define VA_COPY
#	 define va_push
#	 define VA_PUSH
#	 define va_pop
#	 define VA_POP
#	 define va_start(A, B)
#	 define VA_START
#	 define va_args
#	 define VA_ARGS
#	 define va_end(A)
#	 define VA_END
#	typedef va_list;
#	typedef VA_LIST;
#	        */
#endif /* !LIBCMT_H */
