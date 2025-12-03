/******************************************************************************\
# H - THREAD                                     #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2025/06/05 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - GPL-3.0   :: Update - 2025/12/03 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

// TODO: AmigaOS 3 & 4

/*############################################################################*\
|*#                                 CONTENTS                                 #*|
|*############################################################################*|
|*............................................................................*|
|*       NAME       :   TYPE    :                 DESCRIPTION                 *|
|*..................:...........:.............................................*|
|* THREAD_CREATE    : (*F)()    : CREATE A THREAD BY PROVIDING A FUNCTION     *|
|* thread_create    :           :                                             *|
|*..................:...........:.............................................*|
|* THREAD_JOIN      : (*F)()    : WAIT FOR A THREAD TO FINISH EXECUTING       *|
|* thread_join      :           :                                             *|
|*..................:...........:.............................................*|
|* MUTEX_CREATE     : (*F)()    : CREATE A MUTEX                              *|
|* mutex_create     :           :                                             *|
|*..................:...........:.............................................*|
|* MUTEX_DESTROY    : (*F)()    : DESTROY A MUTEX                             *|
|* mutex_destroy    :           :                                             *|
|*..................:...........:.............................................*|
|* MUTEX_LOCK       : #define() : LOCK A MUTEX                                *|
|* mutex_lock       :           :                                             *|
|*..................:...........:.............................................*|
|* MUTEX_UNLOCK     : #define() : UNLOCK A MUTEX                              *|
|* mutex_unlock     :           :                                             *|
|*..................:.........................................................*|
|* T_THREAD         : typedef   : THREAD ID TYPE                              *|
|* t_thread         :           :                                             *|
|*..................:.........................................................*|
|* T_MUTEX          : typedef   : MUTEX ID TYPE                               *|
|* t_mutex          :           :                                             *|
|*..................:.........................................................*|
\******************************************************************************/

/*############################################################################*\
|*#                                HOW TO USE                                #*|
|*############################################################################*|
|*                                                                            *|
|* ::::::::::::::::::::::::::::: THREAD_CREATE :::::::::::::::::::::::::::::: *|
|*                                                                            *|
|* CREATES A NEW THREAD. TAKES A FUNCTION POINTER AND ARGUMENT FOR THAT FUNC. *|
|* RETURNS A THREAD HANDLE (T_THREAD), OR NULL ON FAILURE.                    *|
|*                                                                            *|
|*  O - EXAMPLE CODE                                                          *|
|*  :                                                                         *|
|* 1| void *my_thread(void *arg)                                              *|
|* 2| {                                                                       *|
|* 3|     // ...                                                              *|
|* 4|     return 0;                                                           *|
|* 5| }                                                                       *|
|* 6|                                                                         *|
|* 7| t_thread thread = thread_create(my_thread, NULL);                       *|
|* 8| if (!thread) { handle error }                                           *|
|*  :                                                                         *|
|*                                                                            *|
|* :::::::::::::::::::::::::::::: THREAD_JOIN ::::::::::::::::::::::::::::::: *|
|*                                                                            *|
|* WAITS FOR A THREAD TO FINISH AND FREES ITS HANDLE.                         *|
|* TAKES THE THREAD HANDLE AND A VOID** FOR RETURN VALUE (CAN BE NULL).       *|
|* RETURNS 0 ON SUCCESS.                                                      *|
|*                                                                            *|
|*  O - EXAMPLE CODE                                                          *|
|*  :                                                                         *|
|* 1| void *ret;                                                              *|
|* 2| thread_join(thread, &ret);                                              *|
|*  :                                                                         *|
|*                                                                            *|
|* ::::::::::::::::::::::::::::: MUTEX_CREATE ::::::::::::::::::::::::::::::: *|
|*                                                                            *|
|* ALLOCATES AND INITIALIZES A MUTEX. RETURNS A MUTEX HANDLE (T_MUTEX).       *|
|* RETURNS NULL ON FAILURE.                                                   *|
|*                                                                            *|
|*  O - EXAMPLE CODE                                                          *|
|*  :                                                                         *|
|* 1| t_mutex mutex = mutex_create();                                         *|
|* 2| if (!mutex) { handle error }                                            *|
|*  :                                                                         *|
|*                                                                            *|
|* ::::::::::::::::::::::::::::: MUTEX_DESTROY :::::::::::::::::::::::::::::: *|
|*                                                                            *|
|* DESTROYS AND FREES A MUTEX CREATED WITH MUTEX_CREATE.                      *|
|* RETURNS 0 ON SUCCESS.                                                      *|
|*                                                                            *|
|*  O - EXAMPLE CODE                                                          *|
|*  :                                                                         *|
|* 1| mutex_destroy(mutex);                                                   *|
|*  :                                                                         *|
|*                                                                            *|
|* :::::::::::::::::::::::::::::: MUTEX_LOCK :::::::::::::::::::::::::::::::: *|
|*                                                                            *|
|* LOCKS A MUTEX. MACRO AROUND pthread_mutex_lock.                            *|
|*                                                                            *|
|*  O - EXAMPLE CODE                                                          *|
|*  :                                                                         *|
|* 1| mutex_lock(mutex);                                                      *|
|*  :                                                                         *|
|*                                                                            *|
|* ::::::::::::::::::::::::::::: MUTEX_UNLOCK ::::::::::::::::::::::::::::::: *|
|*                                                                            *|
|* UNLOCKS A MUTEX. MACRO AROUND pthread_mutex_unlock.                        *|
|*                                                                            *|
|*  O - EXAMPLE CODE                                                          *|
|*  :                                                                         *|
|* 1| mutex_unlock(mutex);                                                    *|
|*  :                                                                         *|
|*                                                                            *|
|* FOR ACTUALY INFORMATIONS AND EXAMPLE ABOUT THESE FUNCTIONS: PLEASE JUST    *|
|* READ pthreads (AKA: POSIX THREADS) DOCUMENTATIONS.                         *|
|*                                                                            *|
\******************************************************************************/

/*############################################################################*\
|*#                                SIDE NOTES                                #*|
|*############################################################################*|
|*                                                                            *|
|* REMEMBER TO ALWAYS JOIN THREADS YOU CREATE TO AVOID RESOURCE LEAKS.        *|
|* ALWAYS DESTROY MUTEXES AFTER USE.                                          *|
|* ALL WRAPPERS RETURN NULL OR 1 ON FAILURE, NOT -1.                          *|
|* HANDLES (T_THREAD, T_MUTEX) ARE POINTERS AND MUST NOT BE COPIED.           *|
|*                                                                            *|
|* :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: *|
|*                                                                            *|
|*  * IF YOU'RE USING POSIX LESS THAN VERSION 1003.1C, YOU MUST DEFINE A      *|
|*    MACRO __TRY__LINUX_THREADS TO MAKE THESE FUNCTIONS WORK.                *|
|*                                                                            *|
|*  * IF YOU'RE USING PLAN9 OPERATING SYSTEM, YOU MUST DEFINE A MACRO         *|
|*    __TRY__PLAN9 TO MAKE THESE FUNCTIONS WORK ON YOUR OPERATING SYSTEM.     *|
|*                                                                            *|
|*  * IF YOU'RE USING FREE-RTOS, YOU MUST DEFINE A MACRO __TRY__FREE_RTOS     *|
|*    TO MAKE THESE FUNCTIONS WORK ON YOUR OPERATING SYSTEM.                  *|
|*                                                                            *|
|*  * IF YOU'RE USING ZEPHYR OPERATING SYSTEM, YOU MUST DEFINE A MACRO        *|
|*    __TRY__ZEPHYR TO MAKE THESE FUNCTIONS WORK ON YOUR OPERATING SYSTEM.    *|
|*                                                                            *|
|*  * IF YOU'RE USING TI-RTOS OPERATING SYSTEM, YOU MUST DEFINE A MACRO       *|
|*    __TRY__TIRTOS TO MAKE THESE FUNCTIONS WORK ON YOUR OPERATING SYSTEM.    *|
|*                                                                            *|
|*  FOR MORE INFO, PLEASE READ THE TABLE (SUPPORTED PLATFOMS) AT THE BOTTOM!  *|
|*                                                                            *|
\******************************************************************************/

/******************************************************************************\
|**                           SUPPORTED PLATFORMS                            **|
|******************************************************************************|
|*                                                                            *|
|* IF YOU DON'T SEE AN OS IN THIS LIST, THEN THIS FEATURE MAY NOT ABLE TO USE *|
|*              IN THAT DEVICE, OPERATING SYSTEM, OR COMPILER!!!              *|
|*                                                                            *|
|*............................................................................*|
|*:     PLATFORM     :                         NOTES                         :*|
|*:..................:.......................................................:*|
|*:             UNIX : POSIX -1003.1C (<=1995) => AKA: LINUXTHREADS          :*|
|*:                  :     * ROBUST OR RECURSIVE MUTEXES NOT FULLY RELIABLE  :*|
|*:                  :     * SIGNALS + THREADS ARE BUGGY                     :*|
|*:                  :     * TLS AND PRIORITY INHERITANCE UNRELIABLE         :*|
|*:                  :     * ALSO, DON'T WORK THREADS INSIDE FORK() PLEASE   :*|
|*:                  :                                                       :*|
|*:                  : POSIX +1003.1C (>1995) => ALL FUNCTIONS ARE FULLY     :*|
|*:                  :                           SUPPORTED                   :*|
|*:..................:.......................................................:*|
|*: WINDOWS / WINAPI : ALL FUNCTIONS ARE FULLY SUPPORTED                     :*|
|*:..................:.......................................................:*|
|*:             OS/2 : 32BIT => ALL FUNCTIONS ARE FULLY SUPPORTED            :*|
|*:                  :                                                       :*|
|*:                  : 16BIT =>                                              :*|
|*:                  :     * THREAD_CREATE -> YOU CAN'T SEND ARGUMENT TO     :*|
|*:                  :                        THREAD FUNCTION                :*|
|*:                  :     * THREAD_JOIN -> NOT SUPPORTED, ALWAYS RETURNS -1 :*|
|*:..................:.......................................................:*|
|*:            HAIKU : ALL FUNCTIONS ARE FULLY SUPPORTED                     :*|
|*:..................:.......................................................:*|
|*:            PLAN9 : ALL FUNCTIONS ARE FULLY SUPPORTED                     :*|
|*:                  : NOTE: MUTEXES ARE NOT EXIST BUT STILL WILL WORK FINE  :*|
|*:..................:.......................................................:*|
|*:         FREERTOS : THREAD_JOIN -> NOT SUPPORTED, ALWAYS RETURNS -1       :*|
|*:..................:.......................................................:*|
|*:           ZEPHYR : THREAD_JOIN -> CAN'T GET THE RETURN VALUE OF THREAD   :*|
|*:                  :                FUNCTION                               :*|
|*:..................:.......................................................:*|
|*:          VXWORKS : THREAD_JOIN -> NOT SUPPORTED, ALWAYS RETURNS -1       :*|
|*:..................:.......................................................:*|
|*:          TI-RTOS : THREAD_JOIN -> NOT SUPPORTED, ALWAYS RETURNS -1       :*|
|*:..................:.......................................................:*|
\******************************************************************************/

#ifndef THREAD_H
#	define THREAD_H 202512 /* VERSION */

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
#	include "../KEYWORDS/IGNORE_VAR.h" /*
#	 define IGNORE_VAR
#	        */
#	include "../KEYWORDS/INLINE.h" /*
#	 define INLINE
#	        */
#	include "../ENVIRONMENTS/KNR_STYLE.h" /*
#	 define KNR_STYLE
#	        */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] C++ (PUSH) [v] *************************** */
#	ifdef __cplusplus /* C++ */
extern "C" {
#	endif /* __cplusplus */
/* *************************** [^] C++ (PUSH) [^] *************************** */

/* ***************** [v] LOCALMACRO_THREAD_FOR_WINDOWS [v] ****************** */
#	ifdef _WIN32
#		define LOCALMACRO_THREAD_FOR_WINDOWS
#		define LOCALMACRO_THREAD_FOUND
#	endif /* _WIN32 */
/* ***************** [^] LOCALMACRO_THREAD_FOR_WINDOWS [^] ****************** */

/* ******************* [v] LOCALMACRO_THREAD_FOR_UNIX [v] ******************* */
#	ifndef LOCALMACRO_THREAD_FOUND
#		ifdef __linux__
#			define LOCALMACRO_THREAD_FOR_UNIX
#			define LOCALMACRO_THREAD_FOUND
#			ifdef __TRY__LINUX_THREADS
/* *************************** [vv] INCLUDES [vv] *************************** */
#				include <features.h> /*
#				 defined __GNU_LIBRARY__
#				 defined __GLIBC__
#				 defined __GLIBC_MINOR__
#				        */
/* *************************** [^^] INCLUDES [^^] *************************** */
#				ifdef __GNU_LIBRARY__
#					if (__GLIBC__ < 2)
#						define LOCALMACRO_LINUXTHREAD_FOR_UNIX
#					else
#						ifdef __GLIBC_MINOR__
#							if ((__GLIBC__ == 2) && (__GLIBC_MINOR__ < 5))
#								define LOCALMACRO_LINUXTHREAD_FOR_UNIX
#							endif /* GLIBC < 2.5 */
#						endif /* __GLIBC_MINOR__ */
#					endif /* __GLIBC__ < 2.X */
#				else
#					ifdef __GLIBC_MINOR__
#						if ((__GLIBC__ == 2) && (__GLIBC_MINOR__ < 5))
#							define LOCALMACRO_LINUXTHREAD_FOR_UNIX
#						endif /* GLIBC < 2.5 */
#					endif /* __GLIBC_MINOR__ */
#				endif /* __GNU_LIBRARY__ */
#			endif /* __TRY__LINUX_THREADS */
#		else
#			ifdef __APPLE__
#				define LOCALMACRO_THREAD_FOR_UNIX
#			endif /* __APPLE__ */
#		endif /* __linux__ */
#	endif /* !LOCALMACRO_THREAD_FOUND */
/* ******************* [^] LOCALMACRO_THREAD_FOR_UNIX [^] ******************* */

/* ******************* [v] LOCALMACRO_THREAD_FOR_OS2 [v] ******************** */
#	ifndef LOCALMACRO_THREAD_FOUND
#		ifdef __OS2__
#			define LOCALMACRO_THREAD_FOR_OS2
#			define LOCALMACRO_THREAD_FOUND
#			ifdef __32BIT__
#				define LOCALMACRO_THREAD_FOR_OS2_32BIT
#			else
#				ifdef _M_386
#					define LOCALMACRO_THREAD_FOR_OS2_32BIT
#				endif /* _M_386 */
#			endif /* __32BIT__ */
#		else
#			ifdef __EMX__
#				define LOCALMACRO_THREAD_FOR_OS2
#				ifdef __32BIT__
#					define LOCALMACRO_THREAD_FOR_OS2_32BIT
#				else
#					ifdef _M_386
#						define LOCALMACRO_THREAD_FOR_OS2_32BIT
#					endif /* _M_386 */
#				endif /* __32BIT__ */
#			endif /* __EMX__ */
#		endif /* __OS2__ */
#	endif /* !LOCALMACRO_THREAD_FOUND */
/* ******************* [^] LOCALMACRO_THREAD_FOR_OS2 [^] ******************** */

/* ******************** [v] LOCALMACRO_THREAD_HAIKU [v] ********************* */
#	ifndef LOCALMACRO_THREAD_FOUND
#		ifdef __HAIKU__
#			define LOCALMACRO_THREAD_HAIKU
#			define LOCALMACRO_THREAD_FOUND
#		endif /* __HAIKU__ */
#	endif /* !LOCALMACRO_THREAD_FOUND */
/* ******************** [^] LOCALMACRO_THREAD_HAIKU [^] ********************* */

/* ******************** [v] LOCALMACRO_THREAD_PLAN9 [v] ********************* */
#	ifndef LOCALMACRO_THREAD_FOUND
#		ifdef __TRY__PLAN9
#			define LOCALMACRO_THREAD_PLAN9
#			define LOCALMACRO_THREAD_FOUND
#		endif /* __TRY__PLAN9 */
#	endif /* !LOCALMACRO_THREAD_FOUND */
/* ******************** [^] LOCALMACRO_THREAD_PLAN9 [^] ********************* */

/* ******************* [v] LOCALMACRO_THREAD_VXWORKS [v] ******************** */
#	ifndef LOCALMACRO_THREAD_FOUND
#		ifdef __VXWORKS__
#			define LOCALMACRO_THREAD_VXWORKS
#			define LOCALMACRO_THREAD_FOUND
#		else
#			ifdef __vxworks
#				define LOCALMACRO_THREAD_VXWORKS
#				define LOCALMACRO_THREAD_FOUND
#			endif /* __vxworks */
#		endif /* __VXWORKS__ */
#	endif /* !LOCALMACRO_THREAD_FOUND */
/* ******************* [^] LOCALMACRO_THREAD_VXWORKS [^] ******************** */

/* ******************* [v] LOCALMACRO_THREAD_FREERTOS [v] ******************* */
#	ifndef LOCALMACRO_THREAD_FOUND
#		ifdef freertos
#			define LOCALMACRO_THREAD_FREERTOS
#			define LOCALMACRO_THREAD_FOUND
#		else
#			ifdef FREERTOS_CONFIG_H
#				define LOCALMACRO_THREAD_FREERTOS
#				define LOCALMACRO_THREAD_FOUND
#			else
#				ifdef __FREERTOS__
#					define LOCALMACRO_THREAD_FREERTOS
#					define LOCALMACRO_THREAD_FOUND
#				else
#					ifdef __TRY__FREE_RTOS
#						define LOCALMACRO_THREAD_FREERTOS
#						define LOCALMACRO_THREAD_FOUND
#					endif /* __TRY__FREE_RTOS */
#				endif /* __FREERTOS__ */
#			endif /* FREERTOS_CONFIG_H */
#		endif /* freertos */
#	endif /* !LOCALMACRO_THREAD_FOUND */
/* ******************* [^] LOCALMACRO_THREAD_FREERTOS [^] ******************* */

/* ******************* [v] LOCALMACRO_THREAD_ZEPHYR [v] ********************* */
#	ifndef LOCALMACRO_THREAD_FOUND
#		ifdef CONFIG_ZEPHYR
#			define LOCALMACRO_THREAD_ZEPHYR
#			define LOCALMACRO_THREAD_FOUND
#		else
#			ifdef CONFIG_KERNEL_INIT_PRIORITY_DEFAULT
#				define LOCALMACRO_THREAD_ZEPHYR
#				define LOCALMACRO_THREAD_FOUND
#			else
#				ifdef ZEPHYR_VERSION_CODE
#					define LOCALMACRO_THREAD_ZEPHYR
#					define LOCALMACRO_THREAD_FOUND
#				else
#					ifdef __ZEPHYR__
#						define LOCALMACRO_THREAD_ZEPHYR
#						define LOCALMACRO_THREAD_FOUND
#					else
#						ifdef __TRY__ZEPHYR
#							define LOCALMACRO_THREAD_ZEPHYR
#							define LOCALMACRO_THREAD_FOUND
#						endif /* __TRY__ZEPHYR */
#					endif /* __ZEPHYR__ */
#				endif /* ZEPHYR_VERSION_CODE */
#			endif /* CONFIG_KERNEL_INIT_PRIORITY_DEFAULT */
#		endif /* CONFIG_ZEPHYR */
#	endif /* !LOCALMACRO_THREAD_FOUND */
/* ******************* [^] LOCALMACRO_THREAD_ZEPHYR [^] ********************* */

/* ******************* [v] LOCALMACRO_THREAD_TI_RTOS [v] ******************** */
#	ifndef LOCALMACRO_THREAD_FOUND
#		ifdef __TI_COMPILER_VERSION__
#			ifdef __TRY__TIRTOS
#				define LOCALMACRO_THREAD_TI_RTOS
#				define LOCALMACRO_THREAD_FOUND
#			endif /* __TRY__TIRTOS */
#		endif /* __TI_COMPILER_VERSION__ */
#	endif /* !LOCALMACRO_THREAD_FOUND */
/* ******************* [^] LOCALMACRO_THREAD_TI_RTOS [^] ******************** */

#	ifdef LOCALMACRO_THREAD_FOUND
#		ifdef LOCALMACRO_THREAD_FOR_OS2
/* **************************** [v] INCLUDES [v] **************************** */
#			define INCL_DOSPROCESS
#			include <os2.h> /*
#			typedef TID;
#			typedef HMTX;
#			typedef ULONG;
#			typedef PFNTHREAD;
#			typedef SEL;
#			typedef PSEL;
#			typedef PBYTE;
#			 USHORT DosCreateThread(PFNTHREAD, PTID, PBYTE); // 16BIT
#			 APIRET DosCreateThread(PTID, PFNTHREAD, ULONG, ULONG, ULONG);
#			 APIRET DosWaitThread(PTID, ULONG);
#			 USHORT DosAllocSeg(USHORT, PSEL, USHORT);
#			        */
/* **************************** [^] INCLUDES [^] **************************** */

/* **************************** [v] TYPEDEFS [v] **************************** */
typedef TID		T_THREAD;
typedef HMTX	T_MUTEX;
/* **************************** [^] TYPEDEFS [^] **************************** */

#			ifdef LOCALMACRO_THREAD_FOR_OS2_32BIT
#				ifndef KNR_STYLE /* STANDARD C */
static INLINE T_THREAD
	THREAD_CREATE(void *(*F)(void *), void *ARG)
#				else /* K&R */
static INLINE T_THREAD
	THREAD_CREATE(F, ARG)
	void	*(*F)(void *);
	void	*ARG;
#				endif /* !KNR_STYLE */
{
	TID	THREAD_ID;

	if (
		DosCreateThread(
			&THREAD_ID,
			(PFNTHREAD)F,
			(ULONG)ARG,
			0,
			65536
		) != 0
	)
		return (0);

	return (THREAD_ID);
}

#				ifndef KNR_STYLE /* STANDARD C */
static INLINE int
	THREAD_JOIN(T_THREAD THREAD, void **RETURN_VALUE)
#				else /* K&R */
static INLINE int
	THREAD_JOIN(THREAD, RETURN_VALUE)
	T_THREAD	THREAD;
	void		**RETURN_VALUE;
#				endif /* !KNR_STYLE */
{
	ULONG	RETURN_CODE;

	if (DosWaitThread(&THREAD, &RETURN_CODE) != 0)
		return (-1);

	if (RETURN_VALUE)
		*RETURN_VALUE = (void *)RETURN_CODE;

	return (0);
}
#			else /* [v] 16BIT *********************************************** */
#				ifndef KNR_STYLE /* STANDARD C */
static INLINE T_THREAD
	THREAD_CREATE(void *(*F)(void *), void *ARG)
#				else /* K&R */
static INLINE T_THREAD
	THREAD_CREATE(F, ARG)
	void	*(*F)(void *);
	void	*ARG;
#				endif /* !KNR_STYLE */
{
	TID		THREAD_ID;
	SEL		SELECTOR;
	PBYTE	STACK_TOP;

	if (DosAllocSeg(4096, (PSEL)&SELECTOR, SEG_NONSHARED))
		return (0);

	STACK_TOP = (PBYTE)(SELECTOR << 4);
	STACK_TOP += 4096;

	if (DosCreateThread((PFNTHREAD)F, &THREAD_ID, STACK_TOP))
		return (0);

	return (THREAD_ID);
}

#				ifndef KNR_STYLE /* STANDARD C */
static INLINE int
	THREAD_JOIN(T_THREAD THREAD, void **RETURN_VALUE)
#				else /* K&R */
static INLINE int
	THREAD_JOIN(THREAD, RETURN_VALUE)
	T_THREAD	THREAD;
	void		**RETURN_VALUE;
#				endif /* !KNR_STYLE */
{
	IGNORE_VAR	THREAD;

	if (RETURN_VALUE)
		*RETURN_VALUE = (void *)0;

	/* NOT SUPPORTED IN 16BIT OS/2 SYSTEM */
	return (-1);
}
#			endif /* LOCALMACRO_THREAD_FOR_OS2_32BIT */

#			ifndef KNR_STYLE /* STANDARD C */
static INLINE T_MUTEX
	MUTEX_CREATE(void)
#			else /* K&R */
static INLINE T_MUTEX
	MUTEX_CREATE()
#			endif /* !KNR_STYLE */
{
	HMTX	MUTEX;

	if (DosCreateMutexSem((PSZ)0, &MUTEX, 0, 0) != 0)
		return ((T_MUTEX)0);

	return (MUTEX);
}

#			ifndef KNR_STYLE /* STANDARD C */
static INLINE int
	MUTEX_DESTROY(T_MUTEX MUTEX)
#			else /* K&R */
static INLINE int
	MUTEX_DESTROY(MUTEX)
	T_MUTEX	MUTEX;
#			endif /* !KNR_STYLE */
{
	if (DosCloseMutexSem(MUTEX) == 0)
		return (0);

	return (1);
}

#			define MUTEX_LOCK(__MUTEX_LOCK__) \
				DosRequestMutexSem(__MUTEX_LOCK__, SEM_INDEFINITE_WAIT)
#			define MUTEX_UNLOCK(__MUTEX_UNLOCK__) \
				DosReleaseMutexSem(__MUTEX_UNLOCK__)
#		endif /* LOCALMACRO_THREAD_FOR_OS2 */

#		ifdef LOCALMACRO_THREAD_FOR_WINDOWS
/* **************************** [v] INCLUDES [v] **************************** */
#			include <stdlib.h> /*
#			typedef size_t;
#			   void *malloc(size_t);
#			   void free(void *);
#			        */
#			include <windef.h> /*
#			typedef HANDLE;
#			typedef DWORD;
#			typedef BOOL;
#			typedef LPVOID;
#			typedef LPDWORD;
#			typedef LPTHREAD_START_ROUTINE;
#			typedef SIZE_T;
#			        */
#			include <minwinbase.h> /*
#			typedef CRITICAL_SECTION;
#			typedef LPSECURITY_ATTRIBUTES;
#			        */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
extern HANDLE	CreateThread(LPSECURITY_ATTRIBUTES, SIZE_T,
	LPTHREAD_START_ROUTINE, void *, DWORD, LPDWORD);
extern DWORD	WaitForSingleObject(HANDLE, DWORD);
extern BOOL		GetExitCodeThread(HANDLE, LPDWORD);
extern BOOL		CloseHandle(HANDLE);
extern void		InitializeCriticalSection(LPCRITICAL_SECTION);
extern void		DeleteCriticalSection(LPCRITICAL_SECTION);
extern void		EnterCriticalSection(LPCRITICAL_SECTION);
extern void		LeaveCriticalSection(LPCRITICAL_SECTION);
/* *************************** [^] PROTOTYPES [^] *************************** */

/* **************************** [v] TYPEDEFS [v] **************************** */
typedef HANDLE				T_THREAD;
typedef CRITICAL_SECTION	*T_MUTEX;
/* **************************** [^] TYPEDEFS [^] **************************** */

#			ifndef KNR_STYLE /* STANDARD C */
static INLINE T_THREAD
	THREAD_CREATE(void *(*F)(void *), void *ARG)
#			else /* K&R */
static INLINE T_THREAD
	THREAD_CREATE(F, ARG)
	void	*(*F)(void *);
	void	*ARG;
#			endif /* !KNR_STYLE */
{
	T_THREAD	THREAD;

	THREAD = (T_THREAD)CreateThread(
		(LPSECURITY_ATTRIBUTES)0,
		(SIZE_T)0,
		(LPTHREAD_START_ROUTINE)F,
		ARG,
		(DWORD)0,
		(LPDWORD)0
	);

	if (THREAD == (T_THREAD)0)
		return ((T_THREAD)0);

	return ((T_THREAD)THREAD);
}

#			ifndef KNR_STYLE /* STANDARD C */
static INLINE int
	THREAD_JOIN(T_THREAD THREAD, void **RETURN_VALUE)
#			else /* K&R */
static INLINE int
	THREAD_JOIN(THREAD, RETURN_VALUE)
	T_THREAD	THREAD;
	void		**RETURN_VALUE;
#			endif /* !KNR_STYLE */
{
	if (!THREAD)
		return (-1);

	WaitForSingleObject(THREAD, ((DWORD)-1));

	if (RETURN_VALUE)
		GetExitCodeThread(THREAD, (LPDWORD)(*RETURN_VALUE));

	if (CloseHandle(THREAD))
		return (0);

	return (1);
}

#			ifndef KNR_STYLE /* STANDARD C */
static INLINE T_MUTEX
	MUTEX_CREATE(void)
#			else /* K&R */
static INLINE T_MUTEX
	MUTEX_CREATE()
#			endif /* !KNR_STYLE */
{
	T_MUTEX	MUTEX;

	MUTEX = (T_MUTEX)malloc(sizeof(CRITICAL_SECTION));

	if (!MUTEX)
		return ((T_MUTEX)0);

	InitializeCriticalSection(MUTEX);
	return (MUTEX);
}

#			ifndef KNR_STYLE /* STANDARD C */
static INLINE int
	MUTEX_DESTROY(T_MUTEX MUTEX)
#			else /* K&R */
static INLINE int
	MUTEX_DESTROY(MUTEX)
	T_MUTEX	MUTEX;
#			endif /* !KNR_STYLE */
{
	if (!MUTEX)
		return (-1);

	DeleteCriticalSection(MUTEX);
	free(MUTEX);
	return (0);
}

#			define MUTEX_LOCK(__MUTEX_LOCK__) \
				EnterCriticalSection(__MUTEX_LOCK__)
#			define MUTEX_UNLOCK(__MUTEX_UNLOCK__) \
				LeaveCriticalSection(__MUTEX_UNLOCK__)
#		endif /* LOCALMACRO_THREAD_FOR_WINDOWS */

#		ifdef LOCALMACRO_THREAD_FOR_UNIX
/* **************************** [v] INCLUDES [v] **************************** */
#			include <pthread.h> /*
#			typedef pthread_t;
#			typedef pthread_mutex_t;
#			typedef pthread_attr_t;
#			typedef pthread_mutexattr_t;
#			    int pthread_create(pthread_t *, pthread_attr_t *,
#			        	(void (*)(void *)), void *);
#			    int pthread_join(pthread_t *, void **); // LINUXTHREADS
#			    int pthread_join(pthread_t, void **);
#			    int pthread_mutex_init(pthread_mutex_t *,
#			        	pthread_mutexattr_t *);
#			    int pthread_mutex_destroy(pthread_mutex_t *);
#			    int pthread_mutex_lock(pthread_mutex_t *);
#			    int pthread_mutex_unlock(pthread_mutex_t *);
#			        */
#			include <stdlib.h> /*
#			   void *malloc(size_t);
#			   void free(void *);
#			        */
/* **************************** [^] INCLUDES [^] **************************** */

/* **************************** [v] TYPEDEFS [v] **************************** */
typedef pthread_t		*T_THREAD;
typedef pthread_mutex_t	*T_MUTEX;
/* **************************** [^] TYPEDEFS [^] **************************** */

#			ifdef LOCALMACRO_LINUXTHREAD_FOR_UNIX
#				ifndef KNR_STYLE /* STANDARD C */
static INLINE T_THREAD
	THREAD_CREATE(void *(*F)(void *), void *ARG)
#				else /* K&R */
static INLINE T_THREAD
	THREAD_CREATE(F, ARG)
	void	*(*F)(void *);
	void	*ARG;
#				endif /* !KNR_STYLE */
{
	T_THREAD	THREAD;

	THREAD = (T_THREAD)malloc(sizeof(pthread_t));
	if (!THREAD)
		return ((T_THREAD)0);

	if (
		pthread_create(
			THREAD,
			(pthread_attr_t *)0,
			F,
			ARG
		)
	)
	{
		free(THREAD);
		return ((T_THREAD)0);
	}

	return (THREAD);
}

#				ifndef KNR_STYLE /* STANDARD C */
static INLINE int
	THREAD_JOIN(T_THREAD THREAD, void **RETURN_VALUE)
#				else /* K&R */
static INLINE int
	THREAD_JOIN(THREAD, RETURN_VALUE)
	T_THREAD	THREAD;
	void		**RETURN_VALUE;
#				endif /* !KNR_STYLE */
{
	int	RETURN;

	if (!THREAD)
		return (1);

	RETURN = pthread_join(*THREAD, RETURN_VALUE);
	free(THREAD);
	return (RETURN);
}

#				ifndef KNR_STYLE /* STANDARD C */
static INLINE T_MUTEX
	MUTEX_CREATE(void)
#				else /* K&R */
static INLINE T_MUTEX
	MUTEX_CREATE()
#				endif /* !KNR_STYLE */
{
	pthread_mutex_t	*MUTEX;

	MUTEX = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!MUTEX)
		return ((T_MUTEX)0);

	pthread_mutex_init(MUTEX, (pthread_mutexattr_t *)0);
	return ((T_MUTEX)MUTEX);
}

#				ifndef KNR_STYLE /* STANDARD C */
static INLINE int
	MUTEX_DESTROY(T_MUTEX MUTEX)
#				else /* K&R */
static INLINE int
	MUTEX_DESTROY(MUTEX)
	T_MUTEX	MUTEX;
#				endif /* !KNR_STYLE */
{
	if (!MUTEX)
		return (1);

	pthread_mutex_destroy(MUTEX);
	free(MUTEX);
	return (0);
}
#				define MUTEX_LOCK(__MUTEX_LOCK__) \
					pthread_mutex_lock(__MUTEX_LOCK__);
#				define MUTEX_UNLOCK(__MUTEX_UNLOCK__) \
					pthread_mutex_unlock(__MUTEX_UNLOCK__);
#			else /* [v] POSIX THREADS *************************************** */
#				ifndef KNR_STYLE /* STANDARD C */
static INLINE T_THREAD
	THREAD_CREATE(void *(*F)(void *), void *ARG)
#				else /* K&R */
static INLINE T_THREAD
	THREAD_CREATE(F, ARG)
	void	*(*F)(void *);
	void	*ARG;
#				endif /* !KNR_STYLE */
{
	T_THREAD	THREAD;

	THREAD = (T_THREAD)malloc(sizeof(pthread_t));

	if (!THREAD)
		return ((T_THREAD)0);

	if (
		pthread_create(
			THREAD,
			(pthread_attr_t *)0,
			F,
			ARG
		)
	)
	{
		free(THREAD);
		return ((T_THREAD)0);
	}

	return (THREAD);
}

#				ifndef KNR_STYLE /* STANDARD C */
static INLINE int
	THREAD_JOIN(T_THREAD THREAD, void **RETURN_VALUE)
#				else /* K&R */
static INLINE int
	THREAD_JOIN(THREAD, RETURN_VALUE)
	T_THREAD	THREAD;
	void		**RETURN_VALUE;
#				endif /* !KNR_STYLE */
{
	register int	RETURN;

	if (!THREAD)
		return (1);

	RETURN = pthread_join(*THREAD, RETURN_VALUE);
	free(THREAD);
	return (RETURN);
}

#				ifndef KNR_STYLE /* STANDARD C */
static INLINE T_MUTEX
	MUTEX_CREATE(void)
#				else /* K&R */
static INLINE T_MUTEX
	MUTEX_CREATE()
#				endif /* !KNR_STYLE */
{
	pthread_mutex_t	*MUTEX;

	MUTEX = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));

	if (!MUTEX)
		return ((T_MUTEX)0);

	pthread_mutex_init(MUTEX, (pthread_mutexattr_t *)0);
	return ((T_MUTEX)MUTEX);
}

#				ifndef KNR_STYLE /* STANDARD C */
static INLINE int
	MUTEX_DESTROY(T_MUTEX MUTEX)
#				else /* K&R */
static INLINE int
	MUTEX_DESTROY(MUTEX)
	T_MUTEX	MUTEX;
#				endif /* !KNR_STYLE */
{
	if (!MUTEX)
		return (1);

	pthread_mutex_destroy(MUTEX);
	free(MUTEX);
	return (0);
}

#				define MUTEX_LOCK(__MUTEX_LOCK__) \
					pthread_mutex_lock(__MUTEX_LOCK__);
#				define MUTEX_UNLOCK(__MUTEX_UNLOCK__) \
					pthread_mutex_unlock(__MUTEX_UNLOCK__);
#			endif /* LOCALMACRO_LINUXTHREAD_FOR_UNIX */
#		endif /* LOCALMACRO_THREAD_FOR_UNIX */

#		ifdef LOCALMACRO_THREAD_HAIKU
/* **************************** [v] INCLUDES [v] **************************** */
#			include <OS.h> /*
#			 define B_NORMAL_PRIORITY
#			typedef thread_id;
#			typedef sem_id;
#			typedef int32;
#			typedef status_t;
#			>>>>>>> thread_id
#			^^^^^^^ spawn_thread(thread_func, char *, int32, void *);
#			>>>>>>> status_t
#			^^^^^^^ resume_thread(thread_id);
#			>>>>>>> status_t
#			^^^^^^^ wait_for_thread(thread_id, status_t *);
#			 sem_id create_sem(int32, char *);
#			>>>>>>> status_t
#			^^^^^^^ delete_sem(sem_id);
#			>>>>>>> status_t
#			^^^^^^^ acquire_sem(sem_id);
#			>>>>>>> status_t
#			^^^^^^^ release_sem(sem_id);
#			        */
#			include <stdlib.h> /*
#			   void free(void *);
#			   void *malloc(size_t);
#			        */
#			include <stdint.h> /*
#			typedef intptr_t;
#			        */
/* **************************** [^] INCLUDES [^] **************************** */

/* **************************** [v] TYPEDEFS [v] **************************** */
typedef thread_id	*T_THREAD;
typedef sem_id		*T_MUTEX;
/* **************************** [^] TYPEDEFS [^] **************************** */

#			ifndef KNR_STYLE /* STANDARD C */
static int32
	THREAD_WRAPPER(void *ARG)
#			else /* K&R */
static int32
	THREAD_WRAPPER(ARG)
	void	*ARG;
#			endif /* !KNR_STYLE */
{
	void	(**FUNCTION_POINTER)(void *);

	FUNCTION_POINTER = (void (**)(void *))ARG;
	(*FUNCTION_POINTER[0])(FUNCTION_POINTER[1]);
	free(ARG);
	return (0);
}

#			ifndef KNR_STYLE /* STANDARD C */
static INLINE T_THREAD
	THREAD_CREATE(void *(*F)(void *), void *ARG)
#			else /* K&R */
static INLINE T_THREAD
	THREAD_CREATE(F, ARG)
	void	*(*F)(void *);
	void	*ARG;
#			endif /* !KNR_STYLE */
{
	T_THREAD	THREAD;
	void		**WRAPPER_ARGS;

	WRAPPER_ARGS = (void **)malloc(sizeof(void *) * 2);

	if (!WRAPPER_ARGS)
		return ((T_THREAD)0);

	WRAPPER_ARGS[0] = (void *)F;
	WRAPPER_ARGS[1] = ARG;

	THREAD = (T_THREAD)malloc(sizeof(thread_id));

	if (!THREAD)
	{
		free(WRAPPER_ARGS);
		return ((T_THREAD)0);
	}

	*THREAD = spawn_thread(
		THREAD_WRAPPER,
		"haiku_thread",
		B_NORMAL_PRIORITY,
		WRAPPER_ARGS
	);

	if (*THREAD < 0)
	{
		free(THREAD);
		free(WRAPPER_ARGS);
		return ((T_THREAD)0);
	}

	resume_thread(*THREAD);
	return (THREAD);
}

#			ifndef KNR_STYLE /* STANDARD C */
static INLINE int
	THREAD_JOIN(T_THREAD THREAD, void **RETURN_VALUE)
#			else /* K&R */
static INLINE int
	THREAD_JOIN(THREAD, RETURN_VALUE)
	T_THREAD	THREAD;
	void		**RETURN_VALUE;
#			endif /* !KNR_STYLE */
{
	status_t	EXIT_VALUE;

	if (!THREAD)
		return (1);

	wait_for_thread(*THREAD, &EXIT_VALUE);

	if (RETURN_VALUE)
		*RETURN_VALUE = (void *)(intptr_t)EXIT_VALUE;

	free(THREAD);
	return (0);
}

#			ifndef KNR_STYLE /* STANDARD C */
static INLINE T_MUTEX
	MUTEX_CREATE(void)
#			else /* K&R */
static INLINE T_MUTEX
	MUTEX_CREATE()
#			endif /* !KNR_STYLE */
{
	T_MUTEX	MUTEX;

	MUTEX = (T_MUTEX)malloc(sizeof(sem_id));

	if (!MUTEX)
		return ((T_MUTEX)0);

	*MUTEX = create_sem(1, "haiku_mutex");

	if (*MUTEX < 0)
	{
		free(MUTEX);
		return ((T_MUTEX)0);
	}

	return (MUTEX);
}

#			ifndef KNR_STYLE /* STANDARD C */
static INLINE int
	MUTEX_DESTROY(T_MUTEX MUTEX)
#			else /* K&R */
static INLINE int
	MUTEX_DESTROY(MUTEX)
	T_MUTEX	MUTEX;
#			endif /* !KNR_STYLE */
{
	if (!MUTEX)
		return (1);

	delete_sem(*MUTEX);
	free(MUTEX);
	return (0);
}

#			define MUTEX_LOCK(__MUTEX_LOCK__) \
				acquire_sem(*(__MUTEX_LOCK__));
#			define MUTEX_UNLOCK(__MUTEX_UNLOCK__) \
				release_sem(*(__MUTEX_UNLOCK__));
#		endif /* LOCALMACRO_THREAD_HAIKU */

#		ifdef LOCALMACRO_THREAD_PLAN9
/* **************************** [v] INCLUDES [v] **************************** */
#			include <u.h> /* -> <libc.h> */
#			include <libc.h> /*
#			 define RFPROC
#			 define RFMEM
#			 define RFNOWAIT
#			typedef Waitmsg;
#			    int rfork(int);
#			   void exits(char *);
#			    int wait(Waitmsg *);
#			   void free(void *);
#			        */
/* **************************** [^] INCLUDES [^] **************************** */

/* **************************** [v] TYPEDEFS [v] **************************** */
typedef int	T_THREAD;
typedef int	T_MUTEX;
/* **************************** [^] TYPEDEFS [^] **************************** */

static INLINE T_THREAD
	THREAD_CREATE(void *(*F)(void *), void *ARG)
{
	int	PROCESS_ID;

	PROCESS_ID = rfork(RFPROC | RFMEM | RFNOWAIT);

	if (PROCESS_ID == 0)
	{
		F(ARG);
		exits((char *)0);
	}

	return (PROCESS_ID);
}

static INLINE int
	THREAD_JOIN(T_THREAD THREAD, void **RETURN_VALUE)
{
	Waitmsg	MESSAGE;

	while (wait(&MESSAGE) >= 0)
	{
		if (MESSAGE.pid == THREAD)
		{
			if (RETURN_VALUE)
				*RETURN_VALUE = (void *)0;

			free(MESSAGE.msg);
			return (0);
		}

		free(MESSAGE.msg);
	}

	return (-1);
}

static INLINE T_MUTEX
	MUTEX_CREATE(void)
{
	return (0);
}

static INLINE int
	MUTEX_DESTROY(T_MUTEX MUTEX)
{
	IGNORE_VAR	MUTEX;

	return (0);
}

#			define MUTEX_LOCK(__MUTEX_LOCK__)
#			define MUTEX_UNLOCK(__MUTEX_UNLOCK__)
#		endif /* LOCALMACRO_THREAD_PLAN9 */

#		ifdef LOCALMACRO_THREAD_FREERTOS
/* **************************** [v] INCLUDES [v] **************************** */
#			include "FreeRTOS.h" /* -> "task.h", "semphr.h" */ /*
#			 define configMINIMAL_STACK_SIZE
#			 define pdPASS
#			        */
#			include "task.h" /*
#			 define xTaskCreate(pvTaskCode, pcName, usStackDepth, pvParameters,
#			        	uxPriority, pxCreatedTask)
#			 define tskIDLE_PRIORITY
#			typedef TaskHandle_t;
#			        */
#			include "semphr.h" /*
#			 define xSemaphoreCreateMutex()
#			 define vSemaphoreDelete(xSemaphore)
#			 define xSemaphoreTake(xSemaphore, xBlockTime)
#			 define xSemaphoreGive(xSemaphore)
#			typedef SemaphoreHandle_t;
#			        */
#			include "portmacro.h" /*
#			 define portMAX_DELAY
#			        */
/* **************************** [^] INCLUDES [^] **************************** */

/* **************************** [v] TYPEDEFS [v] **************************** */
typedef TaskHandle_t		T_THREAD;
typedef SemaphoreHandle_t	T_MUTEX;
/* **************************** [^] TYPEDEFS [^] **************************** */

#			ifndef KNR_STYLE /* STANDARD C */
static INLINE T_THREAD
	THREAD_CREATE(void *(*F)(void *), void *ARG)
#			else /* K&R */
static INLINE T_THREAD
	THREAD_CREATE(F, ARG)
	void	*(*F)(void *);
	void	*ARG;
#			endif /* !KNR_STYLE */
{
	T_THREAD	HANDLE_THREAD;

	HANDLE_THREAD = (T_THREAD)0;

	if (
		xTaskCreate(
			F,
			"THREAD",
			configMINIMAL_STACK_SIZE,
			ARG,
			(tskIDLE_PRIORITY + 1),
			&HANDLE_THREAD
		) != pdPASS
	)
		return ((T_THREAD)0);

	return (HANDLE_THREAD);
}

#			ifndef KNR_STYLE /* STANDARD C */
static INLINE int
	THREAD_JOIN(T_THREAD THREAD, void **RETURN_VALUE)
#			else /* K&R */
static INLINE int
	THREAD_JOIN(THREAD, RETURN_VALUE)
	T_THREAD	THREAD;
	void		**RETURN_VALUE;
#			endif /* !KNR_STYLE */
{
	IGNORE_VAR	THREAD;

	if (RETURN_VALUE)
		*RETURN_VALUE = (void *)0;

	/* NOT SUPPORTED IN FREERTOS */
	return (-1);
}

#			ifndef KNR_STYLE /* STANDARD C */
static INLINE T_MUTEX
	MUTEX_CREATE(void)
#			else /* K&R */
static INLINE T_MUTEX
	MUTEX_CREATE()
#			endif /* !KNR_STYLE */
{
	return (xSemaphoreCreateMutex());
}

#			ifndef KNR_STYLE /* STANDARD C */
static INLINE int
	MUTEX_DESTROY(T_MUTEX MUTEX)
#			else /* K&R */
static INLINE int
	MUTEX_DESTROY(MUTEX)
	T_MUTEX	MUTEX;
#			endif /* !KNR_STYLE */
{
	vSemaphoreDelete(MUTEX);
	return (0);
}

#			define MUTEX_LOCK(__MUTEX_LOCK__) \
				xSemaphoreTake(__MUTEX_LOCK__, portMAX_DELAY)
#			define MUTEX_UNLOCK(__MUTEX_UNLOCK__) \
				xSemaphoreGive(__MUTEX_UNLOCK__)
#		endif /* LOCALMACRO_THREAD_FREERTOS */

#		ifdef LOCALMACRO_THREAD_ZEPHYR
/* **************************** [v] INCLUDES [v] **************************** */
#			include <zephyr/kernel.h> /*
#			 define K_THREAD_STACK_SIZEOF(sym)
#			 define K_PRIO_PREEMPT(x)
#			 define K_NO_WAIT
#			 define K_FOREVER
#			 struct k_thread;
#			 struct k_mutex;
#			typedef k_thread_entry_t;
#			k_tid_t k_thread_create(struct k_thread *, k_thread_stack_t *,
#			        	size_t, k_thread_entry_t, void *, void *, void *, int,
#			        	uint32_t, k_timeout_t);
#			    int k_thread_join(struct k_thread *, k_timeout_t);
#			    int k_mutex_init(struct k_mutex *);
#			    int k_mutex_lock(struct k_mutex *, k_timeout_t);
#			    int k_mutex_unlock(struct k_mutex *);
#			        */
#			include <stdlib.h> /*
#			   void *malloc(size_t);
#			   void free(void *);
#			        */
/* **************************** [^] INCLUDES [^] **************************** */

/* **************************** [v] TYPEDEFS [v] **************************** */
typedef struct k_thread	*T_THREAD;
typedef struct k_mutex	*T_MUTEX;
/* **************************** [^] TYPEDEFS [^] **************************** */

#			ifndef KNR_STYLE /* STANDARD C */
static INLINE T_THREAD
	THREAD_CREATE(void *(*F)(void *), void *ARG)
#			else /* K&R */
static INLINE T_THREAD
	THREAD_CREATE(F, ARG)
	void	*(*F)(void *);
	void	*ARG;
#			endif /* !KNR_STYLE */
{
	struct k_thread	*THREAD_DATA;
	unsigned char	*STACK_AREA;

	THREAD_DATA = (struct k_thread *)malloc(sizeof(struct k_thread));

	if (!THREAD_DATA)
		return ((T_THREAD)0);

	STACK_AREA = (unsigned char *)malloc(sizeof(unsigned char) * 1024);

	if (!STACK_AREA)
	{
		free(THREAD_DATA);
		return ((T_THREAD)0);
	}

	return (
		k_thread_create(
			THREAD_DATA,
			STACK_AREA,
			1024,
			(k_thread_entry_t)F,
			ARG,
			(void *)0,
			(void *)0,
			K_PRIO_PREEMPT(1),
			0,
			K_NO_WAIT
		)
	);
}

#			ifndef KNR_STYLE /* STANDARD C */
static INLINE int
	THREAD_JOIN(T_THREAD THREAD, void **RETURN_VALUE)
#			else /* K&R */
static INLINE int
	THREAD_JOIN(THREAD, RETURN_VALUE)
	T_THREAD	THREAD;
	void		**RETURN_VALUE;
#			endif /* !KNR_STYLE */
{
	if (RETURN_VALUE)
		*RETURN_VALUE = (void *)0; /* ZEPHYR THREADS DON'T RETURN VALUES */

	return (k_thread_join(THREAD, K_FOREVER));
}

#			ifndef KNR_STYLE /* STANDARD C */
static INLINE T_MUTEX
	MUTEX_CREATE(void)
#			else /* K&R */
static INLINE T_MUTEX
	MUTEX_CREATE()
#			endif /* !KNR_STYLE */
{
	T_MUTEX	MUTEX;

	MUTEX = malloc(sizeof(struct k_mutex));

	if (!MUTEX)
		return ((T_MUTEX)0);

	if (k_mutex_init(MUTEX))
	{
		free(MUTEX);
		return ((T_MUTEX)0);
	}

	return (MUTEX);
}

#			ifndef KNR_STYLE /* STANDARD C */
static INLINE int
	MUTEX_DESTROY(T_MUTEX MUTEX)
#			else /* K&R */
static INLINE int
	MUTEX_DESTROY(MUTEX)
	T_MUTEX	MUTEX;
#			endif /* !KNR_STYLE */
{
	free(T_MUTEX);
	return (0);
}

#			define MUTEX_LOCK(__MUTEX_LOCK__) \
				k_mutex_lock(__MUTEX_LOCK__, K_FOREVER)
#			define MUTEX_UNLOCK(__MUTEX_UNLOCK__) \
				k_mutex_unlock(__MUTEX_UNLOCK__)
#		endif /* LOCALMACRO_THREAD_ZEPHYR */

#		ifdef LOCALMACRO_THREAD_VXWORKS
/* **************************** [v] INCLUDES [v] **************************** */
#			include <taskLib.h> /* ->
#			 define FUNCPTR
#			    int taskSpawn(char *, int, int, int, FUNCPTR, int, int, int,
#			        	int, int, int, int, int, int, int);
#			        */
#			include <semLib.h> /*
#			typedef SEM_ID;
#			 SEM_ID semMCreate(int);
#			 STATUS semDelete(SEM_ID);
#			 STATUS semTake(SEM_ID, int);
#			 STATUS semGive(SEM_ID);
#			        */
#			include <sysLib.h> /*
#			 define WAIT_FOREVER
#			        */
/* **************************** [^] INCLUDES [^] **************************** */

/* **************************** [v] TYPEDEFS [v] **************************** */
typedef int		T_THREAD;
typedef SEM_ID 	T_MUTEX;
/* **************************** [^] TYPEDEFS [^] **************************** */

#			ifndef KNR_STYLE /* STANDARD C */
static INLINE T_THREAD
	THREAD_CREATE(void *(*F)(void *), void *ARG)
#			else /* K&R */
static INLINE T_THREAD
	THREAD_CREATE(F, ARG)
	void	*(*F)(void *);
	void	*ARG;
#			endif /* !KNR_STYLE */
{
	return (
		taskSpawn(
			"tThread",
			100,
			0,
			0X10000,
			(FUNCPTR)F,
			(int)ARG,
			0,
			0,
			0,
			0,
			0,
			0,
			0,
			0,
			0
		)
	);
}

#			ifndef KNR_STYLE /* STANDARD C */
static INLINE int
	THREAD_JOIN(T_THREAD THREAD, void **RETURN_VALUE)
#			else /* K&R */
static INLINE int
	THREAD_JOIN(THREAD, RETURN_VALUE)
	T_THREAD	THREAD;
	void		**RETURN_VALUE;
#			endif /* !KNR_STYLE */
{
	IGNORE_VAR	THREAD;

	if (RETURN_VALUE)
		*RETURN_VALUE = (void *)0;

	/* NOT SUPPORTED IN VXWORKS */
	return (-1);
}

#			ifndef KNR_STYLE /* STANDARD C */
static INLINE T_MUTEX
	MUTEX_CREATE(void)
#			else /* K&R */
static INLINE T_MUTEX
	MUTEX_CREATE()
#			endif /* !KNR_STYLE */
{
	return (semMCreate(SEM_Q_PRIORITY | SEM_INVERSION_SAFE));
}

#			ifndef KNR_STYLE /* STANDARD C */
static INLINE int
	MUTEX_DESTROY(T_MUTEX MUTEX)
#			else /* K&R */
static INLINE int
	MUTEX_DESTROY(MUTEX)
	T_MUTEX	MUTEX;
#			endif /* !KNR_STYLE */
{
	return (semDelete(MUTEX));
}

#			define MUTEX_LOCK(__MUTEX_LOCK__) \
				semTake((__MUTEX_LOCK__), WAIT_FOREVER)
#			define MUTEX_UNLOCK(__MUTEX_UNLOCK__) semGive((__MUTEX_UNLOCK__))
#		endif /* LOCALMACRO_THREAD_VXWORKS */

#		ifdef LOCALMACRO_THREAD_TI_RTOS
/* **************************** [v] INCLUDES [v] **************************** */
#			include <ti/sysbios/knl/Task.h> /*
#			typedef Task_Handle;
#			typedef Task_Params;
#			typedef Task_FuncPtr;
#			   void Task_Params_init(Task_Params *)
#			>>>>>>> Task_Handle
#			^^^^^^^ Task_create(Task_FuncPtr, Task_Params *, Error_Block *);
#			        */
#			include <ti/sysbios/knl/Semaphore.h> /*
#			typedef Semaphore_Handle;
#			 define Semaphore_Mode_BINARY
#			typedef Semaphore_Params;
#			>>>>>>> Semaphore_Handle
#			^^^^^^^ Semaphore_create(int, Semaphore_Params *, Error_Block *);
#			   void Semaphore_delete(Semaphore_Handle *);
#			   bool Semaphore_pend(Semaphore_Handle, uint32_t);
#			   void Semaphore_post(Semaphore_Handle);
#			        */
#			include <xdc/std.h> /*
#			typedef UArg;
#			        */
#			include <xdc/runtime/Error.h> /*
#			typedef Error_Block;
#			        */
#			include <ti/sysbios/BIOS.h> /*
#			 define BIOS_WAIT_FOREVER
#			        */
/* **************************** [^] INCLUDES [^] **************************** */

/* **************************** [v] TYPEDEFS [v] **************************** */
typedef Task_Handle			T_THREAD;
typedef Semaphore_Handle	T_MUTEX;
/* **************************** [^] TYPEDEFS [^] **************************** */

#			ifndef KNR_STYLE /* STANDARD C */
static INLINE T_THREAD
	THREAD_CREATE(void *(*F)(void *), void *ARG)
#			else /* K&R */
static INLINE T_THREAD
	THREAD_CREATE(F, ARG)
	void	*(*F)(void *);
	void	*ARG;
#			endif /* !KNR_STYLE */
{
	Task_Params	TASK_PARAMS;

	Task_Params_init(&TASK_PARAMS);
	TASK_PARAMS.arg0 = (UArg)ARG;
	TASK_PARAMS.stackSize = 1024;
	return (Task_create((Task_FuncPtr)F, &TASK_PARAMS, (Error_Block *)0));
}

#			ifndef KNR_STYLE /* STANDARD C */
static INLINE int
	THREAD_JOIN(T_THREAD THREAD, void **RETURN_VALUE)
#			else /* K&R */
static INLINE int
	THREAD_JOIN(THREAD, RETURN_VALUE)
	T_THREAD	THREAD;
	void		**RETURN_VALUE;
#			endif /* !KNR_STYLE */
{
	IGNORE_VAR	THREAD;

	if (RETURN_VALUE)
		*RETURN_VALUE = (void *)0;

	/* NOT SUPPORTED IN TI-RTOS */
	return (-1);
}

#			ifndef KNR_STYLE /* STANDARD C */
static INLINE T_MUTEX
	MUTEX_CREATE(void)
#			else /* K&R */
static INLINE T_MUTEX
	MUTEX_CREATE()
#			endif /* !KNR_STYLE */
{
	Semaphore_Params	SEMAPHORE_PARAMS;

	Semaphore_Params_init(&SEMAPHORE_PARAMS);
	SEMAPHORE_PARAMS.mode = Semaphore_Mode_BINARY;
	return (Semaphore_create(1, &SEMAPHORE_PARAMS, (Error_Block *)0));
}

#			ifndef KNR_STYLE /* STANDARD C */
static INLINE int
	MUTEX_DESTROY(T_MUTEX MUTEX)
#			else /* K&R */
static INLINE int
	MUTEX_DESTROY(MUTEX)
	T_MUTEX	MUTEX;
#			endif /* !KNR_STYLE */
{
	if (!MUTEX)
		return (1);

	Semaphore_delete(&MUTEX); // [v] changed for TI-RTOS
	return (0);
}

#			define MUTEX_LOCK(__MUTEX_LOCK__) \
				Semaphore_pend(__MUTEX_LOCK__, BIOS_WAIT_FOREVER)
#			define MUTEX_UNLOCK(__MUTEX_UNLOCK__) \
				Semaphore_post(__MUTEX_UNLOCK__)
#		endif /* LOCALMACRO_THREAD_TI_RTOS */
#	else
#		error "OPERATING SYSTEM OR COMPILER DOESN'T SUPPORT THREADS!!!"
#	endif /* LOCALMACRO_THREAD_FOUND */

/* *************************** [v] LOWERCASE [v] **************************** */
/* *************************** [vv] TYPEDEFS [vv] *************************** */
typedef T_THREAD	t_thread;
typedef T_MUTEX		t_mutex;
/* *************************** [^^] TYPEDEFS [^^] *************************** */

#	ifndef KNR_STYLE /* STANDARD C */
static INLINE t_thread
	thread_create(void *(*f)(void *), void *arg)
#	else /* K&R */
static INLINE t_thread
	thread_create(f, arg)
	void	*(*f)(void *);
	void	*arg;
#	endif /* !KNR_STYLE */
{
	return ((t_thread)THREAD_CREATE(f, arg));
}

#	ifndef KNR_STYLE /* STANDARD C */
static INLINE int
	thread_join(t_thread thread, void **return_value)
#	else /* K&R */
static INLINE int
	thread_join(thread, return_value)
	t_thread	thread;
	void		**return_value;
#	endif /* !KNR_STYLE */
{
	return (THREAD_JOIN((T_THREAD)thread, return_value));
}

#	ifndef KNR_STYLE /* STANDARD C */
static INLINE t_mutex
	mutex_create(void)
#	else /* K&R */
static INLINE t_mutex
	mutex_create()
#	endif /* !KNR_STYLE */
{
	return ((t_mutex)MUTEX_CREATE());
}

#	ifndef KNR_STYLE /* STANDARD C */
static INLINE int
	mutex_destroy(t_mutex mutex)
#	else /* K&R */
static INLINE int
	mutex_destroy(mutex)
	t_mutex	mutex;
#	endif /* !KNR_STYLE */
{
	return (MUTEX_DESTROY((T_MUTEX)mutex));
}

#	define mutex_lock(__mutex_lock__) MUTEX_LOCK(__mutex_lock__)
#	define mutex_unlock(__mutex_unlock__) MUTEX_UNLOCK(__mutex_unlock__)
/* *************************** [^] LOWERCASE [^] **************************** */

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

#endif /* !THREAD_H */

/* * * * * * * * * * * /!\ AUTOMATIC EOF TREATMENT! /!\ * * * * * * * * * * * *\
 * * AT THE ALL END OF FILES, I AM ADDING A SPECIAL BYTE <0X1A> TO END THE  * *
 * *                       FILE IN DOS, CP/M SYSTEMS                        * *
 * *   "//" FOR HANDLING THE BYTE IN MODERN COMPILERS AND #define IS FOR    * *
 * *       HANDLING "//" SYNTAX WHICH IS NOT SUPPORTED ON OLD SYSTEMS       * *
\* * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * */
#undef __LIBCMT__END_OF_FILE__
#define __LIBCMT__END_OF_FILE__ //
