/******************************************************************************\
# H - START                                      #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2024/02/27 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - GPL-3.0   :: Update - 2025/11/14 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*\
|@                                                                            @|
|@                                  WARNING!                                  @|
|@                                                                            @|
|@                          THIS IS A WIP CONTENT!!!                          @|
|@                                                                            @|
|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
|@                                                                            @|
|@     THIS EXTENSION MIGHT NOT WORK ON ALL COMPILERS, OPERATING SYSTEMS,     @|
|@                            AND ARCHITECTURES!!!                            @|
|@                                                                            @|
|@                  UNDERGO MAJOR MAINTENANCE IN THE FUTURE!                  @|
|@                         USE IT WITH YOUR OWN RISK!                         @|
|@                                              ^^^^                          @|
|@                                                                            @|
\*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

/******************************************************************************\
|*                                  CONTENTS                                  *|
|******************************************************************************|
|*                            ....................                            *|
|*                            : BUILTIN KEYWORDS :                            *|
|*............................;,,,,,,,,,,,,,,,,,,;............................*|
|*    NAME   :    TYPE    :                   DESCRIPTION                     *|
|*...........:............:...................................................*|
|* SECTION   : #define () : CREATE A SECTION                                  *|
|*...........:............:...................................................*|
|* END       : #define    : END OF SECTION                                    *|
|*...........:............:...................................................*|
|* MEM       : #define () : USE MEMORY (ONE ARG)                              *|
|*...........:............:...................................................*|
|* MEM_INDEX : #define () : USE MEMORY (TWO ARGS)                             *|
|*...........:............:...................................................*|
|*                                                                            *|
|*                           .....................                            *|
|*                           : REGISTERS (INTEL) :                            *|
|*...........................;,,,,,,,,,,,,,,,,,,,;............................*|
|* NAME :  TYPE   :                        DESCRIPTION                        *|
|*......:.........:...........................................................*|
|* RSI  : #define : SOURCE INDEX, USED FOR SOURCE POINTER IN STRING AND       *|
|* ESI  : #define : MEMORY OPERATIONS                                         *|
|* SI   : #define :                                                           *|
|* AH   : #define :                                                           *|
|*......:.........:...........................................................*|
|* RDI  : #define : DESTINATION INDEX, USED FOR DESTINATION POINTER IN STRING *|
|* EDI  : #define : AND MEMORY OPERATIONS                                     *|
|* DI   : #define :                                                           *|
|* BH   : #define :                                                           *|
|*......:.........:...........................................................*|
|* RBP  : #define : BASE POINTER (FRAME POINTER), USUALLY POINTS TO THE       *|
|* EBP  : #define : CURRENT STACK FRAME BASE                                  *|
|* BP   : #define :                                                           *|
|* CH   : #define :                                                           *|
|*......:.........:...........................................................*|
|* RSP  : #define : STACK POINTER, POINTS TO THE TOP OF THE STACK             *|
|* ESP  : #define :                                                           *|
|* SP   : #define :                                                           *|
|* DH   : #define :                                                           *|
|*......:.........:...........................................................*|
|* RAX  : #define : PRIMARY ACCUMULATOR, OFTEN HOLDS FUNCTION RETURN VALUES   *|
|* EAX  : #define :                                                           *|
|* AX   : #define :                                                           *|
|* AL   : #define :                                                           *|
|*......:.........:...........................................................*|
|* RBX  : #define : BASE REGISTER, GENERAL-PURPOSE (CALLEE-SAVED)             *|
|* EBX  : #define :                                                           *|
|* BX   : #define :                                                           *|
|* BL   : #define :                                                           *|
|*......:.........:...........................................................*|
|* RCX  : #define : COUNTER REGISTER, USED FOR LOOPS OR ARGUMENT PASSING      *|
|* ECX  : #define :                                                           *|
|* CX   : #define :                                                           *|
|* CL   : #define :                                                           *|
|*......:.........:...........................................................*|
|* RDX  : #define : DATA REGISTER, USED FOR I/O, ARITHMETIC, AND ARGUMENT     *|
|* EDX  : #define : PASSING                                                   *|
|* DX   : #define :                                                           *|
|* DL   : #define :                                                           *|
|*......:.........:...........................................................*|
|*                                                                            *|
|*                            ....................                            *|
|*                            : COMMANDS (INTEL) :                            *|
|*............................;,,,,,,,,,,,,,,,,,,;............................*|
|* NAME  :    TYPE    :                      DESCRIPTION                      *|
|*.......:............:.......................................................*|
|* RET   : #define    : IF SECTION CALLED VIA CALL, JUMPS BACK TO WHERE IT IS *|
|*       :            : CALLED                                                *|
|*.......:............:.......................................................*|
|* MOV8  : #define () : MOVES 1 BYTE FROM THE SOURCE TO THE DESTINATION       *|
|*.......:............:.......................................................*|
|* MOV16 : #define () : MOVES 2 BYTES FROM THE SOURCE TO THE DESTINATION      *|
|*.......:............:.......................................................*|
|* MOV32 : #define () : MOVES 4 BYTES FROM THE SOURCE TO THE DESTINATION      *|
|*.......:............:.......................................................*|
|* MOV64 : #define () : MOVES 8 BYTES FROM THE SOURCE TO THE DESTINATION      *|
|*.......:............:.......................................................*|
|* ADD8  : #define () : ADDS 1 BYTE FROM THE SOURCE TO THE DESTINATION        *|
|*.......:............:.......................................................*|
|* ADD16 : #define () : ADDS 2 BYTES FROM THE SOURCE TO THE DESTINATION       *|
|*.......:............:.......................................................*|
|* ADD32 : #define () : ADDS 4 BYTES FROM THE SOURCE TO THE DESTINATION       *|
|*.......:............:.......................................................*|
|* ADD64 : #define () : ADDS 8 BYTES FROM THE SOURCE TO THE DESTINATION       *|
|*.......:............:.......................................................*|
\******************************************************************************/

/*############################################################################*\
|*#                              WTF THAT DOES?                              #*|
|*############################################################################*|
|*                                                                            *|
|* :::::::::::::::::::::::::::::::: OVERVIEW :::::::::::::::::::::::::::::::: *|
|* THIS HEADER PROVIDES A UNIFIED MACRO LAYER THAT LETS YOU WRITE INLINE      *|
|* ASSEMBLY WITH MINIMAL COMPILER-SPECIFIC BOILERPLATE.                       *|
|*                                                                            *|
|* THE SYSTEM:                                                                *|
|* - DETECTS COMPILER ASM SUPPORT                                             *|
|* - DETECTS ARCHITECTURE: 16-BIT / 32-BIT / 64-BIT                           *|
|* - DETECTS BACKEND SYNTAX: AT&T, INTEL, OR MSVC INLINE ASM                  *|
|* - DEFINES STABLE MACRO KEYWORDS SO YOUR ASM BLOCKS STAY PORTABLE           *|
|*                                                                            *|
|* IT ABSTRACTS:                                                              *|
|* - REGISTER NAMES                                                           *|
|* - MEMORY ADDRESSING                                                        *|
|* - BASIC ARITHMETIC AND MOVE OPERATIONS                                     *|
|* - SECTION CREATION (LABELS)                                                *|
|* - RETURN INSTRUCTIONS                                                      *|
|*                                                                            *|
|* NOTE: MOV64, ADD64, @64 ETC... DOWNSCALE AUTOMATICALLY ON 32/16-BIT MODES. *|
|*                                                                            *|
|* :::::::::::::::::::::::::::: WHAT IS IT DOES? :::::::::::::::::::::::::::: *|
|*                                                                            *|
|* * ENSURES YOUR INLINE ASM CAN COMPILE ACROSS:                              *|
|* :                                                                          *|
|* :.. GCC / CLANG (AT&T SYNTAX)                                              *|
|* :                                                                          *|
|* :.. ICC (AT&T OR INTEL DEPENDING ON BUILD)                                 *|
|* :                                                                          *|
|* :.. MSVC (__asm{} INTEL SYNTAX)                                            *|
|*                                                                            *|
|* * PROVIDES STABLE NAMES FOR REGISTERS THAT CHANGE SIZE ACROSS              *|
|*   ARCHITECTURES                                                            *|
|*                                                                            *|
|* * ALLOWS MACRO-STYLE 8/16/32/64-BIT OPS WITHOUT MANUAL SYNTAX BRANCHING    *|
|*                                                                            *|
|* * PROVIDES UNIFIED MEMORY ADDRESSING PATTERNS                              *|
|*                                                                            *|
|* * ENABLES PLATFORM-INDEPENDENT SECTION CREATION FOR ASM ENTRY POINTS       *|
|*                                                                            *|
\******************************************************************************/

/*############################################################################*\
|*#                                HOW TO USE                                #*|
|*############################################################################*|
|*                                                                            *|
|*  O A RANDOM EXAMPLE                                                        *|
|*  :                                                                         *|
|* 1| #include "LIBCMT/ASM/PUSH.h"                                            *|
|* 2| SECTION("example_func") // example_func:                                *|
|* 3|     MOV32(EAX, EBX)     // mov rax, ebx                                 *|
|* 4|     ADD32(EAX, 1)       // add eax, 1                                   *|
|* 5|     RET                 // ret                                          *|
|* 6| END                                                                     *|
|* 7| #include "LIBCMT/ASM/POP.h"                                             *|
|*  :                                                                         *|
|*                                                                            *|
|*  O EXAMPLE - BYTE COPY ROUTINE                                             *|
|*  :                                                                         *|
|* 1| #include "LIBCMT/ASM/PUSH.h"                                            *|
|* 2| SECTION("copy_byte")   // copy_byte:                                    *| 
|* 3|     MOV8(MEM(RDI), AL) // mov byte [rdi], al                            *|
|* 4|     RET                // ret                                           *|
|* 5| END                                                                     *|
|* 6| #include "LIBCMT/ASM/POP.h"                                             *|
|*  :                                                                         *|
|*                                                                            *|
|*  O EXAMPLE - ADD VALUE AT INDEX                                            *|
|*  :                                                                         *|
|* 1| #include "LIBCMT/ASM/PUSH.h"                                            *|
|* 2| SECTION("add_indexed")              // add_indexed                      *|
|* 3|     ADD32(MEM_INDEX(RAX, RCX), EDX) // add dword [rax + rcx], edx       *|
|* 4|     RET                             // ret                              *|
|* 5| END                                                                     *|
|* 6| #include "LIBCMT/ASM/POP.h"                                             *|
|*  :                                                                         *|
|*                                                                            *|
\******************************************************************************/

/* **************************** [v] INCLUDES [v] **************************** */
#include "../CHECK_FEATURE/INLINE_ASM.h" /*
# define IS__INLINE_ASM__SUPPORTED
# define INLINE_ASM_TYPE__GNU
#         */
#include "../ENVIRONMENTS/CPU.h" /*
# define __CPU_INTEL__
#        */
#include "../ENVIRONMENTS/ARCHITECTURE.h" /*
# define __SYSTEM_64_BIT__
# define __SYSTEM_32_BIT__
# define __SYSTEM_16_BIT__
#        */
/* **************************** [^] INCLUDES [^] **************************** */

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

#ifdef IS__INLINE_ASM__SUPPORTED
#	ifdef INLINE_ASM_TYPE__GNU
#		define LOCALMACRO_ATNT_SYNTAX_STRING
#		define __START__
#		define __END__ "\n"
#		define SECTION(NAME) __asm__ (".global "NAME"\n"NAME":\n"
#		define END );
#	endif /* INLINE_ASM_TYPE__GNU */
#	ifdef INLINE_ASM_TYPE__ISO
#		define LOCALMACRO_ATNT_SYNTAX_STRING
#		define __START__
#		define __END__ "\n"
#		define SECTION(NAME) \
			__asm__ (".section "NAME",\"a\"\n.global "NAME"\n"NAME":\n"
#		define END ".text");	
#	endif /* INLINE_ASM_TYPE__ISO */
#	ifdef INLINE_ASM_TYPE__MSVC
#		define LOCALMACRO_INTEL_SYNTAX_PURE
#		define __START__
#		define __END__
#		define SECTION(NAME) __declspec(naked) int NAME(void){__asm {
#		define END }}
#	endif /* INLINE_ASM_TYPE__MSVC */
#	ifdef LOCALMACRO_ATNT_SYNTAX_STRING
#		define MEM(ARG) "("ARG")"
#		define MEM_INDEX(ARG, INDEX) "("ARG","INDEX")"
#		ifdef __CPU_INTEL__
#			ifdef __SYSTEM_64_BIT__
#				define MOV8(A, B) __START__ "movb " B ", " A __END__
#				define MOV16(A, B) __START__ "movw " B ", " A __END__
#				define MOV32(A, B) __START__ "movl " B ", " A __END__
#				define MOV64(A, B) __START__ "movq " B ", " A __END__
#				define ADD8(A, B) __START__ "addb " B ", " A __END__
#				define ADD16(A, B) __START__ "addw " B ", " A __END__
#				define ADD32(A, B) __START__ "addl " B ", " A __END__
#				define ADD64(A, B) __START__ "addq " B ", " A __END__
#				define AH "%ah"
#				define SI "%si"
#				define ESI "%esi"
#				define RSI "%rsi"
#				define BH "%bh"
#				define DI "%di"
#				define EDI "%edi"
#				define RDI "%rdi"
#				define CH "%ch"
#				define BP "%bp"
#				define EBP "%ebp"
#				define RBP "%rbp"
#				define DH "%dh"
#				define SP "%sp"
#				define ESP "%esp"
#				define RSP "%rsp"
#				define AL "%al"
#				define AX "%ax"
#				define EAX "%eax"
#				define RAX "%rax"
#				define BL "%bl"
#				define BX "%bx"
#				define EBX "%ebx"
#				define RBX "%rbx"
#				define CL "%cl"
#				define CX "%cx"
#				define ECX "%ecx"
#				define RCX "%rcx"
#				define DL "%dl"
#				define DX "%dx"
#				define EDX "%edx"
#				define RDX "%rdx"
#			endif /* __SYSTEM_64_BIT__ */
#			ifdef __SYSTEM_32_BIT__
#				define MOV8(A, B) __START__ "movb " B ", " A __END__
#				define MOV16(A, B) __START__ "movw " B ", " A __END__
#				define MOV32(A, B) __START__ "movl " B ", " A __END__
#				define MOV64(A, B) MOV32(A, B)
#				define ADD8(A, B) __START__ "addb " B ", " A __END__
#				define ADD16(A, B) __START__ "addw " B ", " A __END__
#				define ADD32(A, B) __START__ "addl " B ", " A __END__
#				define ADD64(A, B) ADD32(A, B)
#				define AH "%ah"
#				define SI "%si"
#				define ESI "%esi"
#				define RSI ESI
#				define BH "%bh"
#				define DI "%di"
#				define EDI "%edi"
#				define RDI EDI
#				define CH "%ch"
#				define BP "%bp"
#				define EBP "%ebp"
#				define RBP EBP
#				define DH "%dh"
#				define SP "%sp"
#				define ESP "%esp"
#				define RSP ESP
#				define AL "%al"
#				define AX "%ax"
#				define EAX "%eax"
#				define RAX EAX
#				define BL "%bl"
#				define BX "%bx"
#				define EBX "%ebx"
#				define RBX EBX
#				define CL "%cl"
#				define CX "%cx"
#				define ECX "%ecx"
#				define RCX ECX
#				define DL "%dl"
#				define DX "%dx"
#				define EDX "%edx"
#				define RDX EDX
#			endif /* __SYSTEM_32_BIT__ */
#			ifdef __SYSTEM_16_BIT__
#				define MOV8(A, B) __START__ "movb " B ", " A __END__
#				define MOV16(A, B) __START__ "movw " B ", " A __END__
#				define MOV32(A, B) MOV16(A, B)
#				define MOV64(A, B) MOV16(A, B)
#				define ADD8(A, B) __START__ "addb " B ", " A __END__
#				define ADD16(A, B) __START__ "addw " B ", " A __END__
#				define ADD32(A, B) ADD16(A, B)
#				define ADD64(A, B) ADD16(A, B)
#				define AH "%ah"
#				define SI "%si"
#				define ESI SI
#				define RSI SI
#				define BH "%bh"
#				define DI "%di"
#				define EDI DI
#				define RDI DI
#				define CH "%ch"
#				define BP "%bp"
#				define EBP BP
#				define RBP BP
#				define DH "%dh"
#				define SP "%sp"
#				define ESP SP
#				define RSP SP
#				define AL "%al"
#				define AX "%ax"
#				define EAX AX
#				define RAX AX
#				define BL "%bl"
#				define BX "%bx"
#				define EBX BX
#				define RBX BX
#				define CL "%cl"
#				define CX "%cx"
#				define ECX CX
#				define RCX CX
#				define DL "%dl"
#				define DX "%dx"
#				define EDX DX
#				define RDX DX
#			endif /* __SYSTEM_16_BIT__ */
#			define RET "ret\n"
#		endif /* __CPU_INTEL__ */
#		undef LOCALMACRO_ATNT_SYNTAX_STRING
#	endif /* LOCALMACRO_ATNT_SYNTAX_STRING */
#	ifdef LOCALMACRO_INTEL_SYNTAX_PURE
#		define MEM(ARG) ptr [ARG]
#		define MEM_INDEX(ARG, INDEX) ptr [ARG + INDEX]
#		ifdef __CPU_INTEL__
#			ifdef __SYSTEM_64_BIT__
#				define MOV8(A, B) __START__ mov byte A, B __END__
#				define MOV16(A, B) __START__ mov word A, B __END__
#				define MOV32(A, B) __START__ mov dword A, B __END__
#				define MOV64(A, B) __START__ mov qword A, B __END__
#				define ADD8(A, B) __START__ add byte A, B __END__
#				define ADD16(A, B) __START__ add word A, B __END__
#				define ADD32(A, B) __START__ add dword A, B __END__
#				define ADD64(A, B) __START__ add qword A, B __END__
#				define AH ah
#				define SI si
#				define ESI esi
#				define RSI rsi
#				define BH bh
#				define DI di
#				define EDI edi
#				define RDI rdi
#				define CH ch
#				define BP bp
#				define EBP ebp
#				define RBP rbp
#				define DH dh
#				define SP sp
#				define ESP esp
#				define RSP rsp
#				define AL al
#				define AX ax
#				define EAX eax
#				define RAX rax
#				define BL bl
#				define BX bx
#				define EBX ebx
#				define RBX rbx
#				define CL cl
#				define CX cx
#				define ECX ecx
#				define RCX rcx
#				define DL dl
#				define DX dx
#				define EDX edx
#				define RDX rdx
#			endif /* __SYSTEM_64_BIT__ */
#			ifdef __SYSTEM_32_BIT__
#				define MOV8(A, B) __START__ mov byte A, B __END__
#				define MOV16(A, B) __START__ mov word A, B __END__
#				define MOV32(A, B) __START__ mov dword A, B __END__
#				define MOV64(A, B) MOV32(A, B)
#				define ADD8(A, B) __START__ add byte A, B __END__
#				define ADD16(A, B) __START__ add word A, B __END__
#				define ADD32(A, B) __START__ add dword A, B __END__
#				define ADD64(A, B) ADD32(A, B)
#				define AH ah
#				define SI si
#				define ESI esi
#				define RSI ESI
#				define BH bh
#				define DI di
#				define EDI edi
#				define RDI EDI
#				define CH ch
#				define BP bp
#				define EBP ebp
#				define RBP EBP
#				define DH dh
#				define SP sp
#				define ESP esp
#				define RSP ESP
#				define AL al
#				define AX ax
#				define EAX eax
#				define RAX EAX
#				define BL bl
#				define BX bx
#				define EBX ebx
#				define RBX EBX
#				define CL cl
#				define CX cx
#				define ECX ecx
#				define RCX ECX
#				define DL dl
#				define DX dx
#				define EDX edx
#				define RDX EDX
#			endif /* __SYSTEM_32_BIT__ */
#			ifdef __SYSTEM_16_BIT__
#				define MOV8(A, B) __START__ mov byte A, B __END__
#				define MOV16(A, B) __START__ mov word A, B __END__
#				define MOV32(A, B) MOV16(A, B)
#				define MOV64(A, B) MOV16(A, B)
#				define ADD8(A, B) __START__ add byte A, B __END__
#				define ADD16(A, B) __START__ add word A, B __END__
#				define ADD32(A, B) ADD16(A, B)
#				define ADD64(A, B) ADD16(A, B)
#				define AH ah
#				define SI si
#				define ESI SI
#				define RSI SI
#				define BH bh
#				define DI di
#				define EDI DI
#				define RDI DI
#				define CH ch
#				define BP bp
#				define EBP BP
#				define RBP BP
#				define DH dh
#				define SP sp
#				define ESP SP
#				define RSP SP
#				define AL al
#				define AX ax
#				define EAX AX
#				define RAX AX
#				define BL bl
#				define BX bx
#				define EBX BX
#				define RBX BX
#				define CL cl
#				define CX cx
#				define ECX CX
#				define RCX CX
#				define DL dl
#				define DX dx
#				define EDX DX
#				define RDX DX
#			endif /* __SYSTEM_16_BIT__ */
#			define RET ret
#		endif /* __CPU_INTEL__ */
#		undef LOCALMACRO_INTEL_SYNTAX_PURE
#	endif /* LOCALMACRO_INTEL_SYNTAX_PURE */
#else
#	error "INLINE ASM DOES NOT SUPPORTED IN THIS COMPILER"
#endif /* IS__INLINE_ASM__SUPPORTED */