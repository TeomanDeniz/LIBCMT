<IMG SRC="https://raw.githubusercontent.com/TeomanDeniz/TeomanDeniz/refs/heads/main/images/repo_projects/libcmt/HEADER2.png" ALT="Header" STYLE="WIDTH: 100%;"/>

LIBCMT is a modular and portable C library extension designed to provide essential tools and features missing from the standard C library fully compatible with all compilers and platforms.

## Usage

To include **all features**:

```c
#include "LIBCMT/LIBCMT.h"    // For C
// or
#include "LIBCMT/LIBCMT.hpp"  // For C++
```

## Modular Include (Optional)

You can selectively include specific components by defining `INCL__<MODULE>` macros before the include:

```c
#define INCL__FAR
#include "LIBCMT/LIBCMT.h" // Includes only the FAR module
```
Or
```c
#define INCL__FAR
#define INCL__OBJECT
#include "LIBCMT/LIBCMT.h" // Includes FAR and OBJECT modules only
```

If no `INCL__...` macro is defined, all modules will be automatically included by default.

# Contents

<details>

<summary>
	<img src="https://raw.githubusercontent.com/TeomanDeniz/TeomanDeniz/main/images/repo_projects/libcmt/OBJECT.gif">
	<b>OBJECT</b> - Implements basic OOP (Object-Oriented Programming) features in C.
</summary>

> ⚠️ Important
> ### File at: [**[📜 LIBCMT/OBJECT.h](https://github.com/TeomanDeniz/LIBCMT/blob/main/OBJECT.h)**]
> ### Call With:
> ```c
> #define INCL__OBJECT
> #include "LIBCMT/LIBCMT.h"
> ```

| **Name**                             | **Type**    | **Description**                                     |
| ------------------------------------ | ----------- | --------------------------------------------------- |
| `OBJECT__TABLE`, `object__table`     | `#define()` | Connect all of the functions into your structure    |
| `OBJECT__CONNECT`, `object__connect` | `#define()` | Connect a structure into a function                 |
| `OBJECT`, `object`                   | `#define()` | Create an object                                    |
| `I_AM_AN_OBJECT`, `i_am_an_object`   | `#define`   | Declares the function pointer storage for an object |

**OBJECT** is a high-performance C/C++ library for object-oriented programming in pure C, providing dynamic function tables, flexible object creation, and optimized cross-platform function injection.

## Features
* Pure C object-oriented programming support.
* Dynamic function tables for runtime function binding.
* Optimized assembly-level function injection for Intel and ARM CPUs.
* Supports 32-bit and 64-bit systems.
* Compatible with TI CGT/CCS compilers, GCC, and MSVC.
* Cross-platform memory management and exception handling support.
* Configurable maximum number of functions per object (\_\_OBJECT_MAX_FUNCTION_LIMIT\_\_).

## Why use OBJECT?
> * Performance
> Uses inline/assembly injection to directly inject functions into objects.
> 
> * Flexibility
> Dynamically bind functions at runtime without virtual tables.
> 
> * Portability
> Supports multiple CPU architectures and OS environments.
> 
> * Memory efficiency
> Objects only allocate their function tables once.
> 
> * Error handling
> Compatible with try/catch-style macros for safe operations.

## Setup

> ### ⚠️ Note
> 
> **Setup** The setup section is optional if you handle main in ARM 32-bit CPUs. If you want the library to define internal global variables automatically, define SETUP_OBJECT once in one C file (typically your main.c / entry point). And also, if you're not using `#define main ...` or `#define main() ...`, you don't have to setup OBJECT either. It will automatically settle everything up by itself.

Before using this library, you **must define** the macro `SETUP_OBJECT` **once**, typically in your `main.c` or entry point file.

This ensures internal global variables are defined properly.

Other files should **not** define it again - they'll only see `extern` declarations.

**Example**:
```c
#define SETUP_OBJECT
#include "LIBCMT/OBJECT.h"

int main()
{
	// ...
}
```
Or
```c
#define SETUP_OBJECT
#define INCL__OBJECT
#include "LIBCMT/LIBCMT.h"

int main()
{
	// ...
}
```

## Contents / API (quick reference)

> ### **`OBJECT(NAME, VAR)`**
> 
> Instantiates an object and binds its function table.
> * If the object has a constructor: `object(s_struct, obj) (...);`
> * Otherwise: `object(s_struct, obj);`
> 
> Suggested macro for ergonomics:
> ```c
> #define o_struct(object_var) object(s_struct, object_var)
> 
> o_struct (obj) (...);
> ```

> ### **`I_AM_AN_OBJECT`**
> 
> Declares the function pointer storage for an object. Place at top of the struct.
> 
> ```c
> struct s_object {
>     i_am_an_object;
>     ...
> };
> ```

> ### **`OBJECT__TABLE(STRUCT_NAME)`**
> 
> Defines the function table array for an object type.
> 
> ```c
> object__table(s_struct) = {
>     constructor_function,
>     function_2,
>     ...
>     0 /* TERMINATOR - DO NOT FORGET */
> };
> ```
> List functions top-to-bottom in the correct indexes. Index 0 is the constructor.

> ### **`OBJECT__CONNECT(STRUCT_NAME)`**
> 
> Connects an object structure pointer (`SELF`) to its instance. Put this macro at the top of function bodies that use `SELF`.
> 
> ```c
> void function_1() {
>     object__connect(s_struct);
>     ...
> }
> ```

## Examples

**Basic object definition**
```c
struct test_object_type {
    i_am_an_object;

    void (*worked)(int);
    int value;
};
```

**Functions**
```c
static void CONSTRUCTOR(void) {
    object__connect(test_object_type);
    SELF->value = 0;
}

static void worked(int n) {
    object__connect(test_object_type);
    SELF->value += n;
}

object__table(test_object_type) = {
    CONSTRUCTOR,
    worked,
    0
};
```

**Usage**
```c
object(test_object_type, obj) (); // constructor called
obj.worked(42); // uses implicit `SELF`
```

**Multiple objects example**
```c
object(test_object_type, test1) ();
object(test_object_type, test2) ();

test1.worked(42);
test1.worked(42);
test2.worked(42);
test1.worked(42);
test2.worked(42);
```

**Full example (compact)**

Type + functions + table

```c
struct test_object_type {
    i_am_an_object;

    int  (*FUNC1)();
    void (*FUNC2)();
    void (*FUNC3)();
    int a;
};

static void CONSTRUCTOR() {
    object__connect(test_object_type);
    printf("0\n");
}

static int FUNC1() {
    object__connect(test_object_type);
    printf("1\n");
    return (42);
}

static void FUNC2() {
    object__connect(test_object_type);
    printf("2\n");
}

static void FUNC3() {
    object__connect(test_object_type);
    printf("3\n");
}

object__table(test_object_type) = {
    CONSTRUCTOR, /* index 0 = constructor */
    FUNC1,
    FUNC2,
    FUNC3,
    0
};
 ```

Using objects in `main`

```c
int main(void) {
    {
        object(test_object_type, TEST) ();
        TEST.FUNC1();
        TEST.FUNC2();
        TEST.FUNC3();
    }

    {
        object(test_object_type, TEST1) ();
        object(test_object_type, TEST2) ();

        TEST1.FUNC1();
        TEST1.FUNC2();

        TEST2.FUNC1();
        TEST2.FUNC2();

        TEST1.FUNC1();
        TEST2.FUNC1();

        printf("%d\n", TEST1.FUNC1());
    }

    return (0);
}
```

## Notes & reminders

- Always terminate `object__table(...)` with `0`.
- Index 0 of the function table is the constructor.
- Use `object__connect(TYPE)` in every function that needs `SELF`.
- `__OBJECT_MAX_FUNCTION_LIMIT__` controls the maximum number of functions per object-increase if required.

----
</details>

# ![](https://raw.githubusercontent.com/TeomanDeniz/TeomanDeniz/main/images/repo_projects/libcmt/asm2.gif) ASM

<details>

<summary>
	<img src="https://raw.githubusercontent.com/TeomanDeniz/TeomanDeniz/main/images/repo_projects/libcmt/push_pop.gif">
	<b>PUSH & POP</b> - Add the value to memory stack <b>(WIP)</b>
</summary>

> [!WARNING]  
> **THIS IS A WIP CONTENT!!!** THIS EXTENSION MIGHT NOT WORK ON ALL COMPILERS, OPERATING SYSTEMS, OR ARCHITECTURES!!!
> MAJOR MAINTENANCE IS PLANNED! USE IT AT YOUR OWN **RISK**

> ⚠️ Important
> ### File at: [**[📜 LIBCMT/ASM/PUSH_POP.h](https://github.com/TeomanDeniz/LIBCMT/blob/main/ASM/PUSH_POP.h)**]
> ### Call With:
> ```c
> #define INCL__PUSH_POP
> #include "LIBCMT/LIBCMT.h"
> ```

| **Name**             | **Type**      | **Description**                          |
|----------------------|---------------|------------------------------------------|
| `PUSH_16`, `push_16` | `#define ()`  | Push 2 Bytes into CPU stack.             |
| `PUSH_32`, `push_32` | `#define ()`  | Push 4 Bytes into CPU stack.             |
| `PUSH_64`, `push_64` | `#define ()`  | Push 8 Bytes into CPU stack if possible. |
| `POP_16`, `pop_16`   | `#define ()`  | Pop 2 Bytes into CPU stack.              |
| `POP_32`, `pop_32`   | `#define ()`  | Pop 4 Bytes into CPU stack.              |
| `POP_64`, `pop_64`   | `#define ()`  | Pop 8 Bytes into CPU stack if possible.  |

## What Does It Do

With these functions, you're able to move and retrieve values from the memory stack with different data sizes and architectures.

> ⚠️ Note
> 
> On 32-Bit systems, PUSH_64 and POP_64 macros can maximum push 32-Bit variables. They behave like a `long` type instead of a true 64-bit value.

## How To Use

Let's write a simple and probably the world's fastest swap example:
```c
register int	a = 42;
register int	b = 11;

PUSH_32(a); // > Added 42 to CPU stack
a = b;      // |
POP_32(b);  // < Removed 42 from CPU stack

// b is now 42
// a is now 11
```

For sending and geting direct values:
```c
register int	a;

PUSH_32(62); // > Added 62 to CPU stack
POP_32(a);   // < Removed 62 from CPU stack

// a is now 62
```

----
</details>

<details>

<summary>
	<img src="https://raw.githubusercontent.com/TeomanDeniz/TeomanDeniz/main/images/repo_projects/libcmt/RAX.gif">
	<b>RAX</b> - Read or Write the register RAX/X0 <b>(WIP)</b>
</summary>

> [!WARNING]  
> **THIS IS A WIP CONTENT!!!** THIS EXTENSION MIGHT NOT WORK ON ALL COMPILERS, OPERATING SYSTEMS, OR ARCHITECTURES!!!
> MAJOR MAINTENANCE IS PLANNED! USE IT AT YOUR OWN **RISK**

> ⚠️ Important
> ### File at: [**[📜 LIBCMT/ASM/RAX.h](https://github.com/TeomanDeniz/LIBCMT/blob/main/ASM/RAX.h)**]
> ### Call With:
> ```c
> #define INCL__RAX
> #include "LIBCMT/LIBCMT.h"
> ```

| **Name**             | **Type**      | **Description**           |
|----------------------|---------------|---------------------------|
| `GET_RAX`, `get_rax` | `#define ()`  | Set `RAX` into a variable |

## What Does It Do

With these functions, you're able to move and get values from the CPU register (RAX, X0, ETC.) and stack with different data sizes and archs.

> ⚠️ Note
> 
> On 32-BIT systems, EAX or R0 registers are used.

## How To Use

# HOW TO USE

**Example 1: Read RAX into a variable**
```c
uint64_t myValue;

GET_RAX(myValue);  // MOV RAX contents into myValue

// myValue now holds the value from RAX
```

**Example 2: Read EAX on 32-bit system**
```c
unsigned int myValue32;

GET_RAX(myValue32);  // MOV EAX contents into myValue32

// myValue32 now holds the value from EAX
```

**Example 3: Cross-architecture ARM support**
```c
uint64_t armValue;

GET_RAX(armValue);  // Reads X0 on ARM64 or R0 on ARM32

// armValue now holds the first argument register value
```

----
</details>

# ![](https://raw.githubusercontent.com/TeomanDeniz/TeomanDeniz/main/images/repo_projects/libcmt/Attributes.png) Attributes

<details>

<summary>
	<img src="https://raw.githubusercontent.com/TeomanDeniz/TeomanDeniz/main/images/repo_projects/libcmt/far.gif">
	<b>FAR</b> - If a program compiles on a 16-bit system and you have a chunk of memory larger than 64 KB, you need this.
</summary>

> ⚠️ Important
> ### File at: [**[📜 LIBCMT/ATTRIBUTES/FAR.h](https://github.com/TeomanDeniz/LIBCMT/blob/main/ATTRIBUTES/FAR.h)**]
> ### Call With:
> ```c
> #define INCL__FAR
> #include "LIBCMT/LIBCMT.h"
> ```

| **Name** | **Type**   | **Description**                                                               |
|----------|------------|-------------------------------------------------------------------------------|
| `FAR`    | `#define`  | Marks a memory segment or pointer as far, allowing access beyond 64KB limits. |

## How to Use

`FAR` defines the memory access type depending on the compiler and platform.

* On **16-bit systems**, it expands to a far pointer keyword (e.g., `far`, `_far`).
* On **modern systems**, it's often empty or unused.

## Examples

**Example - Variables**: Creates an integer variable that uses a far memory pointer.
```c
FAR int far_var;
far_var = 42;
```

**Example - Pointers**: A string pointer stored in far memory space.
```c
FAR char *far_ptr;
far_ptr = "Hello, world!";
```

**Example - Structs**: A struct stored in far memory.
```c
struct FAR far_struct
{
	int id;
	char name[20];
};
```

**Example - Function Pointers**: A function pointer in far memory.
```c
FAR void (*far_function)(void);
```

**Pro-Tip**:
* Check your compiler documentation for memory models and pointer types.
* To support very old compilers, this file avoids using `#if`.
* On **modern systems** (32/64-bit), far pointers are obsolete and mostly ignored.
* Far pointers are slower (due to segment switching).
* Use `FAR` only if you're planning to compile your code on 16-bit real mode environments.

## What It Does

`FAR` is a **memory qualifier** used to access memory locations beyond the current segment in **16-bit architectures**.

In 16-bit compilers (MS-DOS, Turbo C, Watcom, etc.), pointers are:
* **Near**: within a single segment
* **Far**: across segments

**How?** Memory segmentation in 16-bit systems uses 64KB segments:
* **Near pointer** -> 16-bit offset
* **Far pointer** -> 32-bit (segment:offset)

**Example**:
```c
int near_ptr_var; // accesses memory in the current segment.
int FAR far_ptr_var; // accesses memory across segments (full 1MB space).
```

**Function Pointers**:
```c
void (*near_func)(void); // can call functions within the same segment.
FAR void (*far_func)(void); // can call functions in different segments.
```

----
</details>

<details>

<summary>
	<img src="https://raw.githubusercontent.com/TeomanDeniz/TeomanDeniz/main/images/repo_projects/libcmt/pack.png">
	<b>PACK</b> - Packs and removes the padding bytes from your struct.
</summary>

> ⚠️ Important
> ### File at: [**[📜 LIBCMT/ATTRIBUTES/PACK.h](https://github.com/TeomanDeniz/LIBCMT/blob/main/ATTRIBUTES/PACK.h)**]
> ### Call With:
> ```c
> #define INCL__PACK
> #include "LIBCMT/LIBCMT.h"
> ```

| **Name**            | **Type**   | **Description**                                                   |
|---------------------|------------|-------------------------------------------------------------------|
| `PRAGMA_PACK_PUSH`  | `#define`  | Begins structure packing (works like `#pragma pack(push)`)        |
| `PRAGMA_PACK_POP`   | `#define`  | Ends structure packing (works like `#pragma pack(pop)`)           |
| `PACK`              | `#define`  | Applies packing to a specific struct                              |

> **Note:** To fully use this feature, you must apply both `PACK` and `PRAGMA_PACK_*` macros around the struct.

---

## Example

```c
PRAGMA_PACK_PUSH
struct test
{
	. . .
} PACK;
PRAGMA_PACK_POP

```
or
```c
PRAGMA_PACK_PUSH
typedef struct test
{
	. . .
} PACK t_test;
PRAGMA_PACK_POP
```

## What It Does

`PACK` removes padding bytes from your struct, reducing its size in memory.

However, **avoid using this unless necessary** (e.g., binary layouts, network packets), as removing padding may cause **performance issues**.

**Why?**

When the CPU reads a struct, it aligns memory access for performance. Typical alignments follow 1, 2, 4, 8, 16, etc. To match these, the compiler inserts padding bytes.

**Example**:
```c
struct test
{
	int a;
}; // sizeof = 4 bytes
```

```c
struct test
{
	int a;
	char b;
}; // sizeof = 8 bytes (includes 3 bytes padding)
```
Where did the 3 bytes go? -> Padding. Padding is added so the CPU can read memory efficiently.

**Now packed**:
```c
PRAGMA_PACK_PUSH
struct test
{
	int a;
	char b;
} PACK;
PRAGMA_PACK_POP
```
Now `sizeof` is **5 bytes**, but access may be slower or unaligned on some systems. Sharing packed structs between functions or modules might lead to performance loss due to unaligned memory access.

----
</details>

<details>

<summary>
	<img src="https://raw.githubusercontent.com/TeomanDeniz/TeomanDeniz/main/images/repo_projects/libcmt/regparm.png">
	<b>REGPARM</b> - Pass arguments to a function via using CPU registers. <b>(WIP)</b>
</summary>

> ⚠️ Important
> ### File at: [**[📜 LIBCMT/ATTRIBUTES/REGPARM.h](https://github.com/TeomanDeniz/LIBCMT/blob/main/ATTRIBUTES/REGPARM.h)**]
> ### Call With:
> ```c
> #define INCL__REGPARM
> #include "LIBCMT/LIBCMT.h"
> ```

| **Name**              | **Type**      | **Description**                                                                                              |
|-----------------------|---------------|--------------------------------------------------------------------------------------------------------------|
| `REGPARM`, `regparm`  | `#define ()`  | With this feature, you are able to send variables to functions using pure registers instead of using memory. |

## How to Use

**Important** - For more effective optimisation, use the `register` keyword on your arguments.

You must enter the number of variables passed to the function via registers in the argument: `REGPARM(<number_of_registers>)`

## Examples

```c
void REGPARM(1) function(int b)
{
    . . .
}

void REGPARM(2) function(int a, int b)
{
    . . .
}

void regparm(4) function(int a, float b, long c, char *d)
{
    . . .
}
```

For the most effective usage:

```c
void regparm(2) function(
    register int a,
    register float b,
    register char *c
)
{
    . . .
}
```

## What It Does

Using this keyword in your function lets you hold a value directly in a CPU register, allowing direct access-similar to C++ references but without using pointers.

When the program reaches this function, the CPU will use the existing value in a register instead of fetching it from memory (RAM) or pushing/popping values to/from the stack.

In other words, it avoids extra instructions during function calls to get the value.

**Note**: You **must** also use `REGPARM` in the function's prototype if one is declared:

```c
void REGPARM(2) FUNCT(int A, int B) { ... } // Function definition
extern void REGPARM(2) FUNCT(int A, int B); // Function prototype
```

----
</details>

# ![](https://raw.githubusercontent.com/TeomanDeniz/TeomanDeniz/main/images/repo_projects/libcmt/CHECK_FEATURE.gif) Check Feature

<details>

<summary>
	<img src="https://raw.githubusercontent.com/TeomanDeniz/TeomanDeniz/main/images/repo_projects/libcmt/COMMA_OPERATOR.gif">
	<b>COMMA OPERATOR</b> - Defines a macro if comma operator is supported on your compiler
</summary>

> ⚠️ Important
> ### File at: [**[📜 LIBCMT/CHECK_FEATURE/COMMA_OPERATOR.h](https://github.com/TeomanDeniz/LIBCMT/blob/main/CHECK_FEATURE/COMMA_OPERATOR.h)**]
> ### Call With:
> ```c
> #define INCL__COMMA_OPERATOR
> #include "LIBCMT/LIBCMT.h"
> ```

| **Name**                        | **Type**     | **Description**                                      |
|---------------------------------|--------------|------------------------------------------------------|
| `IS__COMMA_OPERATOR__SUPPORTED` | `#define`    | Defines if comma operator supported by your compiler |

## What Does This Header Do

Defines `IS__COMMA_OPERATOR__SUPPORTED` if the compiler supports the comma operator.

## What Is The "Comma Operator"

The comma operator refers to the `(,)` operator in macros or expressions, used to evaluate multiple expressions in sequence and return the last.

**Example**:
```c
int a = (b++, funct(), c = 42, b += c, 66); // Performs all actions and returns 66
```

----
</details>

<details>

<summary>
	<img src="https://raw.githubusercontent.com/TeomanDeniz/TeomanDeniz/main/images/repo_projects/libcmt/INLINE_ASM.gif">
	<b>INLINE ASM</b> - Defines a macro if inline asm is supported on your compiler and which type of syntax it is using
</summary>

> ⚠️ Important
> ### File at: [**[📜 LIBCMT/CHECK_FEATURE/INLINE_ASM.h](https://github.com/TeomanDeniz/LIBCMT/blob/main/CHECK_FEATURE/INLINE_ASM.h)**]
> ### Call With:
> ```c
> #define INCL__INLINE_ASM
> #include "LIBCMT/LIBCMT.h"
> ```

| Name                         | Type      | Description                                                |
| ---------------------------- | --------- | ---------------------------------------------------------- |
| `IS__INLINE_ASM__SUPPORTED`  | `#define` | Defined if the compiler supports inline assembly in C/C++. |
| `INLINE_ASM_TYPE__GNU`       | `#define` | GNU-style extended inline assembly (GCC, Clang).           |
| `INLINE_ASM_TYPE__MSVC`      | `#define` | Microsoft Visual C++ block-style assembly.                 |
| `INLINE_ASM_TYPE__BORLAND`   | `#define` | Borland/Turbo C simple inline assembly.                    |
| `INLINE_ASM_TYPE__AZTEC`     | `#define` | Aztec C block-style (x86).                                 |
| `INLINE_ASM_TYPE__LATTICE`   | `#define` | Lattice C string-style (68K/Amiga).                        |
| `INLINE_ASM_TYPE__INTEL_MS`  | `#define` | Intel C MS-style single-line assembly.                     |
| `INLINE_ASM_TYPE__WATCOM`    | `#define` | Watcom C pragma/block-style assembly.                      |
| `INLINE_ASM_TYPE__ARM`       | `#define` | ARM compiler-style inline assembly with constraints.       |
| `INLINE_ASM_TYPE__KEIL`      | `#define` | Keil embedded pragma-block-style assembly.                 |
| `INLINE_ASM_TYPE__HCCF`      | `#define` | HC(S) or ColdFire compiler-style inline assembly.          |
| `INLINE_ASM_TYPE__ISO`       | `#define` | ISO-C extended inline assembly.                            |

## Purpose
This header detects whether the compiler supports inline assembly and, if so, identifies which syntax style it uses. Different compilers have different assembly embedding formats, and the library defines a macro for the matching type.

> ⚠️ Important
> 
> **PLEASE CHECK THE TABLE AT [[`📜 LIBCMT/INLINE_ASM_TABLE.md`](https://github.com/TeomanDeniz/LIBCMT/blob/main/INLINE_ASM_TABLE.md)] FOR INFORMATION ABOUT SUPPORTED ARCHITECTURES.**

> ## Supported Syntax Types & Examples
> ### GNU Style (GCC, Clang) - Extended Inline Assembly - **`INLINE_ASM_TYPE__GNU`**
> ```c
> int result;
> asm("movl %1, %0" : "=r"(result) : "r"(input_var) : );
> ```
> 
> ### Microsoft Visual C++ Style - Block Assembly - **`INLINE_ASM_TYPE__MSVC`**
> ```c
> int input_var = 42;
> 
> __asm {
>     mov eax, input_var
>     mov result, eax
> }
> ```
> 
> ### Borland Style - Simple Inline - **`INLINE_ASM_TYPE__BORLAND`**
> ```c
> asm mov eax, input_var
> asm mov result, eax
> ```
> 
> ### Aztec C Style (x86) - Block with Braces - **`INLINE_ASM_TYPE__AZTEC`**
> ```c
> asm {
>     mov ax, input_var
>     mov result, ax
> }
> ```
> 
> ### Lattice C Style (68K/Amiga) - String Based - **`INLINE_ASM_TYPE__LATTICE`**
> ```c
> asm("move.l input_var,d0");
> asm("move.l d0,result");
> ```
> 
> ### Intel C MS-Style - Single Line - **`INLINE_ASM_TYPE__INTEL_MS`**
> ```c
> __asm mov eax, input_var
> __asm mov result, eax
> ```
> 
> ### Watcom C Style - Pragma/Block - **`INLINE_ASM_TYPE__WATCOM`**
> ```c
> _asm {
>     mov eax, input_var
>     mov result, eax
> }
> // or
> #pragma aux myhalt = "mov ax,4C00h" "int 21h";
> void myhalt(void);
> ```
> 
> ### ARM Compiler Style - Constraints - **`INLINE_ASM_TYPE__ARM`**
> ```c
> __asm("mov %0,%1" : "=r"(result) : "r"(input_var));
> ```
> 
> ### Keil Embedded Style - Pragma Blocks - **`INLINE_ASM_TYPE__KEIL`**
> ```c
> #pragma asm
> MOV A, #input_var
> MOV result, A
> #pragma endasm
> ```
> 
> ### Watcom C Style - Pragma/Block - **`INLINE_ASM_TYPE__WATCOM`**
> ```c
> _asm {
>     mov eax, input_var
>     mov result, eax
> }
> // or
> #pragma aux myhalt = "mov ax,4C00h" "int 21h";
> void myhalt(void);
> ```
> 
> ### FreeScale - HC12, HCS08, ColdFire - **`INLINE_ASM_TYPE__HCCF`**
> ```c
> unsigned char result, input_var = 0X42;
> 
> asm LDAA input_var
> asm STAA result
> // or
> #pragma asm
>     LDAA input_var
>     STAA result
> #pragma endasm
> ```
> 
> ### ISO C Style - Inline Assembly - **`INLINE_ASM_TYPE__ISO`**
> ```c
> __asm__ __volatile__ (
>     "movl %0, %%eax;"
>     "movl %%eax, %1;"
>     : "r"(input_var), "r"(result)
> );
> ```

----
</details>

<details>

<summary>
	<img src="https://raw.githubusercontent.com/TeomanDeniz/TeomanDeniz/main/images/repo_projects/libcmt/TOKEN_PASTING.gif">
	<b>TOKEN PASTNG</b> - Defines a macro if token pasting is supported on your compiler
</summary>

> ⚠️ Important
> ### File at: [**[📜 LIBCMT/CHECK_FEATURE/TOKEN_PASTING.h](https://github.com/TeomanDeniz/LIBCMT/blob/main/CHECK_FEATURE/TOKEN_PASTING.h)**]
> ### Call With:
> ```c
> #define INCL__TOKEN_PASTING
> #include "LIBCMT/LIBCMT.h"
> ```

| **Name**                       | **Type**     | **Description**                                     |
|--------------------------------|--------------|-----------------------------------------------------|
| `IS__TOKEN_PASTING__SUPPORTED` | `#define`    | Defines if token pasting supported by your compiler |

## What Does This Header Do

Defines `IS__TOKEN_PASTING__SUPPORTED` if the compiler supports the token pasting (`##`) feature.

## What Is The "Token Pasting"

Token pasting refers to the `##` operator in macros, used to merge two tokens into one during preprocessing.

**Example**:
```c
#define AB(A, B) A##B

int AB(ma, in)(void) // Expands to: int main(void)
{
	. . .
}
```

----
</details>

# ![](https://raw.githubusercontent.com/TeomanDeniz/TeomanDeniz/main/images/repo_projects/libcmt/environments.png) Environments

<details>

<summary>
	<img src="https://raw.githubusercontent.com/TeomanDeniz/TeomanDeniz/main/images/repo_projects/libcmt/cache.gif">
	<b>ARCHITECTURE</b> - You can get information about your CPU architecture.
</summary>

> ⚠️ Important
> ### File at: [**[📜 LIBCMT/ENVIRONMENTS/ARCHITECTURE.h](https://github.com/TeomanDeniz/LIBCMT/blob/main/ENVIRONMENTS/ARCHITECTURE.h)**]
> ### Call With:
> ```c
> #define INCL__ARCHITECTURE
> #include "LIBCMT/LIBCMT.h"
> ```

| Name                 | Type      | Description                                   |
| -------------------- | --------- | --------------------------------------------- |
| `__SYSTEM_256_BIT__` | `#define` | Defined if the system also supports 256-bit   |
| `__SYSTEM_128_BIT__` | `#define` | Defined if the system also supports 128-bit   |
| `__SYSTEM_64_BIT__`  | `#define` | Defined if the system is 64-bit               |
| `__SYSTEM_32_BIT__`  | `#define` | Defined if the system is 32-bit               |
| `__SYSTEM_31_BIT__`  | `#define` | Defined if the system also supports 31-bit    |
| `__SYSTEM_16_BIT__`  | `#define` | Defined if the system is 16-bit               |
| `__SYSTEM_8_BIT__`   | `#define` | Defined if the system is 8-bit                |
| `__SYSTEM_BIT__`     | `#define` | Macro indicating the system bit-width.        |

These defines indicate the bit-width supported or used by the system.

`__SYSTEM__BIT__` is a macro that evaluates to the number of bits of the target architecture-typically `8`, `16`, `32`, or `64`-based on the CPU or compiler settings.

----
</details>

<details>

<summary>
	<img src="https://raw.githubusercontent.com/TeomanDeniz/TeomanDeniz/main/images/repo_projects/libcmt/CPU.gif">
	<b>CPU</b> - You can get information about CPU in runtime.
</summary>

> ⚠️ Important
> ### File at: [**[📜 LIBCMT/ENVIRONMENTS/CPU.h](https://github.com/TeomanDeniz/LIBCMT/blob/main/ENVIRONMENTS/CPU.h)**]
> ### Call With:
> ```c
> #define INCL__CPU
> #include "LIBCMT/LIBCMT.h"
> ```

| Name               | Type      | Description                                                                                                            |
| ------------------ | --------- | ---------------------------------------------------------------------------------------------------------------------- |
| `__CPU_INTEL__`    | `#define` | Defined if the target CPU is Intel (x86/x86-64)                                                                        |
| `__CPU_ARM__`      | `#define` | Defined if the target CPU is ARM-Based (aarch32/aarch64)                                                               |
| `__CPU_AMD_X86__`  | `#define` | Defined if the target CPU is ARM-x86                                                                                   |
| `__CPU_POWERPC__`  | `#define` | Defined if the target CPU is IBM-PowerPC                                                                               |
| `__CPU_RISCV__`    | `#define` | Defined if the target CPU is RISC-V                                                                                    |
| `__CPU_HC12__`     | `#define` | Defined if the target CPU is HC12                                                                                      |
| `__CPU_HCS08__`    | `#define` | Defined if the target CPU is HCS08                                                                                     |
| `__CPU_COLDFIRE__` | `#define` | Defined if the target CPU is ColdFire                                                                                  |
| `__CPU_M68K__`     | `#define` | Defined if the target CPU is M68K                                                                                      |
| `__CPU_SH__`       | `#define` | Defined if the target CPU is SuperH                                                                                    |
| `__CPU_MIPS__`     | `#define` | Defined if the target CPU is MIPS                                                                                      |
| `__CPU_SPARC__`    | `#define` | Defined if the target CPU is SPARC                                                                                     |
| `__CPU_6502__`     | `#define` | Defined if the target CPU is 6502 Microprocessor                                                                       |
| `__CPU_Z80__`      | `#define` | Defined if the target CPU is Z80                                                                                       |
| `__CPU_TI__`       | `#define` | Defined if the target CPU is TI-MCU Processor                                                                          |
| `__CPU_SHARC__`    | `#define` | Defined if the target CPU is SHARC                                                                                     |
| `__CPU_BLACKFIN__` | `#define` | Defined if the target CPU is Blackfin                                                                                  |
| `__CPU_DSP56K__`   | `#define` | Defined if the target CPU is Motorola-DSP56000                                                                         |
| `__CPU_VER__`      | `(*F)()`  | Returns static C-string describing CPU vendor and version info at runtime. Same signature on both Intel and ARM builds |

This header provides CPU vendor/architecture detection and a runtime version query function with a unified signature across supported CPUs.

- At compile time, preprocessor checks detect the target CPU architecture (Intel x86/x86-64, AMD x86, ARM/AArch32/AArch64, PowerPC, RISC-V, etc.) and define the corresponding __CPU_xxx__ macro.
- At runtime, __CPU_VER__() returns a static C-string containing the CPU vendor ID and a short model/version/stepping description.
- For x86-family CPUs, CPUID is used to obtain vendor and version fields.
- For ARM-family CPUs, MIDR_EL1 or MIDR is read and parsed.
- For other architectures, similar native registers or instructions can be implemented in the same interface.

Purpose: Allows any codebase to get a consistent CPU identification string without linking extra libraries, calling OS APIs, or using sprintf/printf.

----
</details>

<details>

<summary>
	<img src="https://raw.githubusercontent.com/TeomanDeniz/TeomanDeniz/main/images/repo_projects/libcmt/is_stdc.gif">
	<b>KNR_STYLE</b> - Creates a macro that determines whether the compiler uses the STD ANSI C standard or the K&R substandard 1989.
</summary>

# **[📜 ENVIRONMENTS/KNR_STYLE.h](https://github.com/TeomanDeniz/LIBCMT/blob/main/ENVIRONMENTS/KNR_STYLE.h)**

> ⚠️ Important
> ### File at: [**[📜 LIBCMT/ENVIRONMENTS/KNR_STYLE.h](https://github.com/TeomanDeniz/LIBCMT/blob/main/ENVIRONMENTS/KNR_STYLE.h)**]
> ### Call With:
> ```c
> #define INCL__KNR_STYLE
> #include "LIBCMT/LIBCMT.h"
> ```

| Name        | Type      | Description                                    |
| ----------- | --------- | ---------------------------------------------- |
| `KNR_STYLE` | `#define` | Defined if compiler is using K&R style syntax. |

Defines a macro if your compiler is using K&R style syntax or not.

----
</details>

# ![](https://raw.githubusercontent.com/TeomanDeniz/TeomanDeniz/main/images/repo_projects/libcmt/functions.png) Functions

<details>

<summary>
	<img src="https://raw.githubusercontent.com/TeomanDeniz/TeomanDeniz/main/images/repo_projects/libcmt/dll.png">
	<b>DLL</b> - Cross platform dynamic link library functions.
</summary>

> ⚠️ Important
> ### File at: [**[📜 LIBCMT/FUNCTIONS/DLL.h](https://github.com/TeomanDeniz/LIBCMT/blob/main/FUNCTIONS/DLL.h)**]
> ### Call With:
> ```c
> #define INCL__DLL
> #include "LIBCMT/LIBCMT.h"
> ```

| NAME                     | TYPE         | DESCRIPTION                                       |
|--------------------------|--------------|---------------------------------------------------|
| `DLL`, `dll`             | `typedef`    | A variable type for handling the opened DLL       |
| `OPEN_DLL`, `open_dll`   | `#define()`  | Open a DLL file                                   |
| `READ_DLL`, `read_dll`   | `#define()`  | Call a function pointer from the DLL file         |
| `CLOSE_DLL`, `close_dll` | `#define()`  | Close DLL file                                    |
| `DYNAMIC`, `dynamic`     | `#define`    | Set function/variable as dynamically linkable     |

## How To Use

### Creating a DLL File

To create dynamic link libraries, first compile your `.c` file with the `-c` flag (to produce object file), then link it with `-shared`:

**Example**:

**`my_dll.c`**
```c
#include <stdio.h>

void dynamic my_write(void)
{
	printf("TEST\n");
}
```

**Compile with:**
```sh
gcc -c my_dll.c -o my_sll.o
gcc -shared my_sll.o -o my_dll.dll
```

Congrats! You now created a dynamic link library!

### Connect To DLL File

**Example**:
```c
{
	dll	dll_file;

	dll_file = open_dll("my_dll.dll");

	if (!dll_file) // DLL file couldn't open or not a DLL
		exit(1);

	void (*my_write)(); // Function pointer
	my_write = (void (*)()) read_dll(dll_file, "my_write");

	if (!my_write) // Function doesn't exist in DLL
		exit(1);

	my_write();
	close_dll(dll_file);

	// DO NOT close the DLL before using a function from it!
	// It will cause a segmentation error!
}
```

## What Does That Do

Dynamic Link Libraries are separate files from executables that need functions/variables from them.

You can get a function pointer from a DLL file and use it directly.

But this library just handles cross-platform keywords for that.

Why compile the whole `printf` unction into every `.exe` file? Just strue `printf` in a DLL file and connect all EXEs to it.

Your ~40KB `.exe` files will become ~100 bytes. Crazy, right?

## Side Notes
* For OS/2 16-BIT or AmigaOS-3, use your function's ordinal number to retrieve the function pointer from the dll.
* Refer to your compiler's documentation for details on compiling dlls.

----
</details>

<details>

<summary>
	<img src="https://raw.githubusercontent.com/TeomanDeniz/TeomanDeniz/main/images/repo_projects/libcmt/prefetch.png">
	<b>PREFETCH</b> - Reduces the cache-miss latency of memory accesses. <b>(WIP)</b>
</summary>

> ⚠️ Important
> ### File at: [**[📜 LIBCMT/FUNCTIONS/PREFETCH.h](https://github.com/TeomanDeniz/LIBCMT/blob/main/FUNCTIONS/PREFETCH.h)**]
> ### Call With:
> ```c
> #define INCL__PREFETCH
> #include "LIBCMT/LIBCMT.h"
> ```

| Name                                       | Type         | Description                                                  |
| ------------------------------------------ | ------------ | ------------------------------------------------------------ |
| `PREFETCH`, `prefetch`                     | `#define ()` | Make a value from memory preloaded into CPU cache before use |
| `PREFETCHW`, `prefetchw`                   | `#define ()` | Same as `PREFETCH`, but tells CPU the data may be modified   |
| `SPIN_LOCK_PREFETCH`, `spin_lock_prefetch` | `#define ()` | Prefetch spin locks (only on UNIX)                           |
| `PREFETCH_RANGE`, `prefetch_range`         | `(*f)()`     | Prefetch the whole memory block                              |

## How To Use

### `PREFETCH`

**Example**:
```c
int variable[9471];
int number = 42;

PREFETCH(variable[0]);
// OR
prefetch(number);
```

### `PREFETCH_RANGE`

**Example**:
```c
int variable[9471];

PREFETCH_RANGE(variable, sizeof(variable));
// OR
prefetch_range(variable, 100);
```

## What is That Do

### `PREFETCH`

You're telling the CPU to load a specific memory location into its cache **before** it's actually needed.

**Simply put**: it hints the CPU to fetch the value into cache early, reducing memory access latency when that value is used shortly after.

Note: This does not move data to the stack - it moves it into cache lines. It's a performance hint, not a guaranteed action.

### `PREFETCH_RANGE`

The `PREFETCH` function only works for a single variable.

`PREFETCH_RANGE` allows you to prefetch multiple variables or a whole array by prefetching a block of memory in a loop or range.

Use this when working with large buffers or arrays to minimize cache misses before heavy processing.

----
</details>

<details>

<summary>
	<img src="https://raw.githubusercontent.com/TeomanDeniz/TeomanDeniz/main/images/repo_projects/libcmt/READ_FILE.gif">
	<b>READ_FILE</b> - Reads a file and returns it's content to you. <b>(WIP)</b>
</summary>

> ⚠️ Important
> ### File at: [**[📜 LIBCMT/FUNCTIONS/READ_FILE.h](https://github.com/TeomanDeniz/LIBCMT/blob/main/FUNCTIONS/READ_FILE.h)**]
> ### Call With:
> ```c
> #define INCL__READ_FILE
> #include "LIBCMT/LIBCMT.h"
> ```

| NAME                     | TYPE      | DESCRIPTION                              |
| ------------------------ | --------- | ---------------------------------------- |
| `READ_FILE`, `read_file` | `(*f)()`  | Reads a file and returns its content     |
| `S_FILE`, `s_file`       | `struct`  | Struct type returned by `READ_FILE`      |
| `T_FILE`, `t_file`       | `typedef` | `typedef struct s_file`, `struct s_file` |

## Error Levels

| Code | Description                                                      |
| ---- | ---------------------------------------------------------------- |
| 0    | File opened and read successfully                                |
| 1    | File does not exist                                              |
| 2    | Failed to allocate necessary memory from RAM for struct's `data` |
| 3    | Permission denied while trying to read the file                  |

## Structure Info

```c
struct s_file
{
	size_t size;  // Size of the file (bytes)
	char   *data; // Every byte of the file
};
```

## What Does that Do

Reads the entire contents of a file specified by `file_path` into memory and stores it in the provided `s_file` structure.

## Side Notes

Yes, you **must** free the `"data"` field of the structure when you're done.

----
</details>

<details>

<summary>
	<img src="https://raw.githubusercontent.com/TeomanDeniz/TeomanDeniz/main/images/repo_projects/libcmt/THREAD.gif">
	<b>THREAD</b> - Use and manage multithreading in your application across platforms.
</summary>

> ⚠️ Important
> ### File at: [**[📜 LIBCMT/FUNCTIONS/THREAD.h](https://github.com/TeomanDeniz/LIBCMT/blob/main/FUNCTIONS/THREAD.h)**]
> ### Call With:
> ```c
> #define INCL__THREAD
> #include "LIBCMT/LIBCMT.h"
> ```

| **Name**                         | **Type**  | **Description**                                          |
| -------------------------------- | --------- | -------------------------------------------------------- |
| `THREAD_CREATE`, `thread_create` | (\*F)()   | Create a thread by providing a function                  |
| `THREAD_JOIN`, `thread_join`     | (\*F)()   | Wait for a thread to finish executing                    |
| `MUTEX_CREATE`, `mutex_create`   | (\*F)()   | Create a mutex                                           |
| `MUTEX_DESTROY`, `mutex_destroy` | (\*F)()   | Destroy a mutex                                          |
| `MUTEX_LOCK`, `mutex_lock`       | #define() | Lock a mutex                                             |
| `MUTEX_UNLOCK`, `mutex_unlock`   | #define() | Unlock a mutex                                           |
| `T_THREAD`, `t_thread`           | typedef   | Thread ID type                                           |
| `T_MUTEX`, `t_mutex`             | typedef   | Mutex ID type                                            |

## How To Use

### `THREAD_CREATE`

Creates a new thread. Takes a function pointer and an argument for that function. Returns a thread handle (`t_thread`), or `NULL` on failure.

**Example**:
```c
void	*my_thread(void *arg)
{
	// ...
	return 0;
}

{
	t_thread thread = thread_create(my_thread, NULL);

	if (!thread)
	{
		// handle error
	}
}
```

### `THREAD_JOIN`

Waits for a thread to finish and frees its handle. Takes the thread handle and a `void**` for the return value (can be `NULL`). Returns `0` on success.

**Example**:
```c
void *ret;
thread_join(thread, &ret);
```

### `MUTEX_CREATE`

Allocates and initializes a mutex. Returns a mutex handle (`t_mutex`). Returns `NULL` on failure.

**Example**:
```c
t_mutex mutex = mutex_create();

if (!mutex)
{
	// handle error
}
```

### `MUTEX_DESTROY`

Destroys and frees a mutex created with `mutex_create`. Returns `0` on success.

**Example**:
```c
mutex_destroy(mutex);
```

### `MUTEX_LOCK`

Locks a mutex.

**Example**:
```c
mutex_lock(mutex);
```

### `MUTEX_UNLOCK`

Unlocks a mutex.

**Example**:
```c
mutex_unlock(mutex);
```

For detailed information and examples, please refer to the POSIX Threads (pthreads) documentation.

## Side Notes

* Always join threads you create to avoid resource leaks.
* Always destroy mutexes after use.
* All wrappers return `NULL` or `1` on failure, not `-1`.
* Handles (`t_thread`, `t_mutex`) are pointers and must not be copied.

## Platform-specific macros

* For POSIX versions earlier than 1003.1c, define `__TRY__LINUX_THREADS` to enable these functions.
* For Plan9 OS, define `__TRY__PLAN9`.
* For FreeRTOS, define `__TRY__FREE_RTOS`.
* For Zephyr OS, define `__TRY__ZEPHYR`.
* For TI-RTOS, define `__TRY__TIRTOS`.
* See the supported platforms table below for details.

## Supported Platforms

| PLATFORM       | NOTES                                                      |
| -------------- | ---------------------------------------------------------- |
| UNIX           | POSIX -1003.1C (<=1995): Also known as LinuxThreads<br/>- Robust or recursive mutexes not fully reliable<br/>- Signals + threads are buggy<br/>- TLS and priority inheritance unreliable<br/>- Avoid using threads inside `fork()`<br/>POSIX +1003.1C (>1995): All functions fully supported      |
| WINDOWS/WINAPI | All functions fully supported                              |
| OS/2 - 32-bit  | All functions fully supported                              |
| OS/2 - 16-bit  | - `THREAD_CREATE`: Cannot send argument to thread function<br/>- `THREAD_JOIN`: Not supported, always returns -1          |
| HAIKU          | All functions fully supported                              |
| PLAN9          | All functions fully supported                              |
| FREERTOS       | `THREAD_JOIN` not supported, always returns -1             |
| ZEPHYR         | `THREAD_JOIN` cannot get return value of thread function   |
| VXWORKS        | `THREAD_JOIN` not supported, always returns -1             |
| TI-RTOS        | `THREAD_JOIN` not supported, always returns -1             |

If your OS is not listed, these features may not be supported on your device, OS, or compiler.

----
</details>

# ![](https://raw.githubusercontent.com/TeomanDeniz/TeomanDeniz/main/images/repo_projects/libcmt/keywords.png) Keywords

<details>

<summary>
	<img src="https://raw.githubusercontent.com/TeomanDeniz/TeomanDeniz/main/images/repo_projects/libcmt/ignore.gif">
	<b>IGNORE_VAR</b> - Tag the variables that may not be used in the project. (For ignoring warnings)
</summary>

> ⚠️ Important
> ### File at: [**[📜 LIBCMT/KEYWORDS/IGNORE_VAR.h](https://github.com/TeomanDeniz/LIBCMT/blob/main/KEYWORDS/IGNORE_VAR.h)**]
> ### Call With:
> ```c
> #define INCL__IGNORE_VAR
> #include "LIBCMT/LIBCMT.h"
> ```

| **Name**                    | **Type**   | **Description**                                    |
|-----------------------------|------------|----------------------------------------------------|
| `IGNORE_VAR`, `ignore_var`  | `#define`  | Tells the compiler the variable may not be used    |

# How To Use

## IGNORE

To use, simply add the tag in front of the variable.

### Examples

```c
IGNORE_VAR void *test;

ignore_var int i;
```

```c
int main(int argc, char **argv)
{
    ignore_var argc;

    ...
}
```

## What Does It Do

This keyword tells the compiler that the variable may not be used in the program.

If unused, the compiler ignores this variable and continues compiling the program without generating any warnings.

----
</details>

<details>

<summary>
	<img src="https://raw.githubusercontent.com/TeomanDeniz/TeomanDeniz/main/images/repo_projects/libcmt/inline.png">
	<b>INLINE</b> - Inline your function on specific compilers.
</summary>

> ⚠️ Important
> ### File at: [**[📜 LIBCMT/KEYWORDS/INLINE.h](https://github.com/TeomanDeniz/LIBCMT/blob/main/KEYWORDS/INLINE.h)**]
> ### Call With:
> ```c
> #define INCL__INLINE
> #include "LIBCMT/LIBCMT.h"
> ```

| **Name** | **Type**  | **Description**                                       |
| -------- | --------- | ----------------------------------------------------- |
| `INLINE` | `#define` | The function is now inlined, similar to a `#include`. |

## How to Use

Just put this tag at the beginning of the function.

**Example**:
```c
INLINE void function(void)
{
	. . .
}
```

## **How Not to Use It**

1. **Avoid using `static inline` if possible.**

Using `static` with `INLINE` cancels the effect or limits visibility.

If the function is only called once or twice, it might not get inlined.

If unused, it may still take up a symbol. Not worth the risk.

**Bad Example**:
```c
// This will make your function just a static:
static INLINE int test(void)
{
	return (15 + 42);
}
```

2. **Don't use `goto`**

Technically allowed, but may break optimisation badly.

**Bad Example**:
```c
// This is wrong... This feels so wrong:
INLINE int test(void)
{
	LAYER:
	. . .
	goto LAYER;
}
```

3. **No `static` variables inside inline functions**

**Bad Example**:
```c
// what da dog doing?
INLINE void test(void)
{
	static int	dog;
	. . .
}
```

4. **No recursion**

Inline functions can't call themselves.

**Bad Example**:
```c
// You can't call something that doesn't exist in the binary.
INLINE void inline_test(int a)
{
	inline_test(a + 1);
	. . .
}
```

5. **No `va_list`, `va_arg`, or `...`**

**Bad Example**:
```c
// No, don't! PLEASE! I BEG YOU!!!
INLINE void inline_test(int a, ...)
{
	va_list list;
	. . .
}
```

## What Does It Do?

It replaces the call to the inline function with its actual code at the call site.

**Example**:
```c
// Inline function:
INLINE int test(void)
{
	return (15 + 42);
}

// Used in main:
int main(void)
{
	printf("%d", test());
	return (0);
}

// Becomes this during compilation:
int main(void)
{
	printf("%d", (15 + 42));
	return (0);
}
```

This was just an example. You’re free to write whatever you want inside the function - **but be aware of what not to do** by reading the "How Not to Use It" section above.

## Side Notes
* `[[clang::always_inline]]` doesn't work reliably in Clang. Believe me.
* Use this keyword with your `static` functions and those defined in header files.
* You don't need to map inline functions with MVS linker pragmas (like `#pragma map`) when targeting z/OS systems.
* Inline functions don’t generate external symbols unless inlining fails.

----
</details>

<details>

<summary>
	<img src="https://raw.githubusercontent.com/TeomanDeniz/TeomanDeniz/main/images/repo_projects/libcmt/LOCAL.gif">
	<b>LOCAL</b> - Ensure each thread has its own independent copy of a "global" or "static" variable it used on.
</summary>

> ⚠️ Important
> ### File at: [**[📜 LIBCMT/KEYWORDS/LOCAL.h](https://github.com/TeomanDeniz/LIBCMT/blob/main/KEYWORDS/LOCAL.h)**]
> ### Call With:
> ```c
> #define INCL__LOCAL
> #include "LIBCMT/LIBCMT.h"
> ```

| **Name**         | **Type**   | **Description**                                     |
|------------------|------------|-----------------------------------------------------|
| `LOCAL`, `local` | `#define`  | Make a variable thread-local (separate per thread). |

## How To Use

**For Global Variables**:
```c
local int g_variable = 0;
```

**For Static Variables**:
```c
void test(void)
{
	static local int	variable = 0;
}
```

## What Does It Do

This keyword must only be used with **global** or `static` variables when needed.

It marks the variable as **thread-local**, meaning **each thread gets its own separate instance** of that variable.

This ensures the variable is **not shared between threads**, preventing race conditions or unintended data sharing.

## Side Notes

Yes, you must use the `local` keyword in the **prototypes of global variables** too.

```c
extern local int g_variable;
//     ^^^^^
```

Add that if you're trying to access your global variable using the `extern` keyword.

----
</details>

<details>

<summary>
	<img src="https://raw.githubusercontent.com/TeomanDeniz/TeomanDeniz/main/images/repo_projects/libcmt/no_return.png">
	<b>NORETURN</b> - Optimise your function if there is a direct exit in it.
</summary>

> ⚠️ Important
> ### File at: [**[📜 LIBCMT/KEYWORDS/NORETURN.h](https://github.com/TeomanDeniz/LIBCMT/blob/main/KEYWORDS/NORETURN.h)**]
> ### Call With:
> ```c
> #define INCL__NORETURN
> #include "LIBCMT/LIBCMT.h"
> ```

| **Name**                | **Type**   | **Description**                                                |
|-------------------------|------------|----------------------------------------------------------------|
| `NORETURN`, `noreturn`  | `#define`  | Tells the compiler that the program will end in this function. |

## How To Use

Just put this tag at the beginning of the function.

**Example**:
```c
NORETURN void function(void)
{
	. . .

	if (...) 
		exit(0);

	. . .
}

noreturn void function(void)
{
	. . .

	if (...) 
		exit(0);

	. . .
}
```

## What Does It Do

Warns the compiler that the function may terminate the program without returning to `main()`.

The only way to do that is by using the `exit()` function.

This is used for optimisation purposes.

----
</details>

<details>

<summary>
	<img src="https://raw.githubusercontent.com/TeomanDeniz/TeomanDeniz/main/images/repo_projects/libcmt/try_catch.gif">
	<b>TRY_CATCH</b> - Use original "try", "catch()", and "throw()" keywords in C Language like in JavaScript.
</summary>

> ⚠️ Important
> ### File at: [**[📜 LIBCMT/KEYWORDS/TRY_CATCH.h](https://github.com/TeomanDeniz/LIBCMT/blob/main/KEYWORDS/TRY_CATCH.h)**]
> ### Call With:
> ```c
> #define INCL__TRY_CATCH
> #include "LIBCMT/LIBCMT.h"
> ```

| Name             | Type        | Description                                         |
| ---------------- | ----------- | --------------------------------------------------- |
| `TRY`, `try`     | `#define`   | Begins a block that may throw an error              |
| `CATCH`, `catch` | `#define()` | Catches thrown errors from the `try` block          |
| `THROW`, `throw` | `#define()` | Immediately jumps to `catch` with a specified error |

## Setup

> ### ⚠️ Note
> 
> **Setup** is _optional_ or _unnecessary_ unless if you're redefining `main` manually via:
> ```c
> #define main ...
> // or
> #define main(...) ...
> ```
> Otherwise, skip this section and go directly to usage examples below.

Before using this library, you **must define** the macro `SETUP_TRY_CATCH` **once**, typically in your `main.c` or entry point file.

This ensures internal global variables are defined properly.

Other files should **not** define it again - they'll only see `extern` declarations.

**Example**:
```c
#define SETUP_TRY_CATCH
#include "LIBCMT/KEYWORDS/TRY_CATCH.h"
```
Or
```c
#define SETUP_TRY_CATCH
#define INCL__TRY_CATCH
#include "LIBCMT/LIBCMT.h"

```

## How To Use

* **`try`{...}** - Wraps a block of code that may call `throw(...)` within it.

* **`catch`(int){...}** - Placed right after try. Captures the error code passed from `throw(...)`.

* **`throw`(int)** - Throws an error code and jumps to the nearest `catch()` block.

## **Examples**

**Basic Try/Catch**:
```cpp
try
{
	if (1)
		throw (99);
}
catch (int err)
{
	printf("ERROR: %d\n", err);
}
```

### TCC (Tiny C Compiler) Compatibility

Compilers like TCC do not allow variable declarations inside control clauses (e.g. `for (int a;...)`).

So, declare `int err;` outside the `catch()` scope:
```cpp
{
	int	err;

	try
	{
		if (1)
			throw (99);
	}
	catch (err)
	{
		printf("ERROR: %d\n", err);
	}
}
```

### Try/Catch Inside a Called Function
```cpp
#include <stdio.h>
#include "LIBCMT/KEYWORDS/TRY_CATCH.h"

void test(void)
{
	throw (42);
}

int main(void)
{
	try
	{
		test();
	}
	catch (int err)
	{
		printf("ERROR: %d\n", err);
	}

	return (0);
}
```

### Nested Try/Catch
```cpp
{
	try
	{
		try {
			throw (42);
		}
		catch (int error) {
			printf("err_1: %d\n", error);
			throw (32);
		}
	}
	catch (int error)
	{
		printf("err_2: %d\n", error);
	}
}
```

## What Does This Do

This custom error handling system uses `setjmp` and `longjmp` to mimic a basic form of exception handling in C.

* `try` sets a jump point for where the program should return if an error occurs.
* `throw(err)` stores the error value and jumps back to that point.
* `catch(variable)` allows you to access the thrown error code.

## Notes
* Only supports `throw()` and `catch()` with `int` type.
* If compiled with a C++ compiler, the library will not define the `try`, `catch`, and `throw` macros but defines `TRY`, `CATCH`, and `THROW` anyway.
* Avoid using this system on constrained devices like 8051, PIC, MSP430, etc. It may quickly bloat memory. **Use it only on devices with more than 4KB of RAM**.
* Do **not** exit from `try` using `return` or `goto`, this may cause segmentation faults or unexpected results.
Instead, use:
```cpp
throw (0); // to completely exit the try block
```

----
</details>

<details>

<summary>
	<img src="https://raw.githubusercontent.com/TeomanDeniz/TeomanDeniz/main/images/repo_projects/libcmt/unused.gif">
	<b>UNUSED</b> - Tag the functions that may not used in the project. (For ignore warnings)
</summary>

> ⚠️ Important
> ### File at: [**[📜 LIBCMT/KEYWORDS/UNUSED.h](https://github.com/TeomanDeniz/LIBCMT/blob/main/KEYWORDS/UNUSED.h)**]
> ### Call With:
> ```c
> #define INCL__UNUSED
> #include "LIBCMT/LIBCMT.h"
> ```

| **Name**           | **Type**     | **Description**                                      |
|--------------------|--------------|------------------------------------------------------|
| `UNUSED`, `unused` | `#define`    | Tells the compiler that the function may not be used |

## How To Use

Just put this tag at the beginning of the function.

**Example**:
```c
UNUSED void function(void)
{
	. . .
}

unused void function(void)
{
	. . .
}
```

## What Does That Do

This keyword tells the compiler that the function may not be used in the program.

If unused, the compiler ignores this function and continues compiling the program without giving any warnings.

----
</details>

# ![](https://raw.githubusercontent.com/TeomanDeniz/TeomanDeniz/main/images/repo_projects/libcmt/plaltform_corssing.gif) Platform Crossing

<details>

<summary>
	<img src="https://raw.githubusercontent.com/TeomanDeniz/TeomanDeniz/main/images/repo_projects/libcmt/va_args.gif">
	<b>VA_ARGS</b> - Make "va_args" system work on older compilers (For before C89)
</summary>

> ⚠️ Important
> ### File at: [**[📜 LIBCMT/PLATFORM_CROSSING/VA_ARGS.h](https://github.com/TeomanDeniz/LIBCMT/blob/main/PLATFORM_CROSSING/VA_ARGS.h)**]
> ### Call With:
> ```c
> #define INCL__VA_ARGS
> #include "LIBCMT/LIBCMT.h"
> ```

| Name                   | Type        | Description                                            |
| ---------------------- | ----------- | ------------------------------------------------------ |
| `va_list`, `VA_LIST`   | `typedef`   | A type for creating your argument list                 |
| `va_add`, `VA_ADD`     | `#define()` | Add a variable to your `va_list` in your function      |
| `va_arg`, `VA_ARG`     | `#define()` | Get a variable from your `va_list` in your function    |
| `va_copy`, `VA_COPY`   | `#define()` | Copy your `va_list` address                            |
| `va_push`, `VA_PUSH`   | `#define`   | Open the argument list to send arguments               |
| `va_pop`, `VA_POP`     | `#define`   | Close the argument list after sending arguments        |
| `va_start`, `VA_START` | `#define()` | Get the address pointer of your argument list          |
| `va_args`, `VA_ARGS`   | `#define`   | Tell the compiler the function accepts varargs (`...`) |
| `va_end`, `VA_END`     | `#define()` | End a `va_list` pointer                                |

## Setup

> ### ⚠️ Note
> 
> **Setup** is _optional_ or _unnecessary_ unless if you're redefining `main` manually via:
> ```c
> #define main ...
> // or
> #define main(...) ...
> ```
> Otherwise, skip this section and go directly to usage examples below.

Before using this library, you **must define** the macro `SETUP_VA_ARGS` **once**, typically in your `main.c` or entry point file.

This ensures internal global variables are defined properly.

Other files should **not** define it again - they'll only see `extern` declarations.

**Example**:
```c
#define SETUP_VA_ARGS
#include "LIBCMT/PLATFORM_CROSSING/VA_ARGS.h"
```
Or
```c
#define SETUP_VA_ARGS
#define INCL__VA_ARGS
#include "LIBCMT/LIBCMT.h"

```

## How To Use

```c
void test(int, va_args); // Prototype

int main(void)
{
	test(42,
		va_push
			va_add(double, 42.0)
			va_add(char *, "Hello world")
			va_add(int, 0X44800000) // Float: 1024.0
		va_pop
	);
	return 0;
}

extern int	printf(const char *, ...); // Prototype

void test(int start, va_args)
{
	va_list x;
	va_list y;

	va_start(x, start);
	va_copy(y, x);

	printf("%d\nx:%f\n", start, va_arg(x, double));
	va_end(x);

	printf("y:%f\n", va_arg(y, double));
	printf("y:%s\n", va_arg(y, char *));
	printf("y:%f\n", va_arg(y, float)); // Yes, this works

	va_end(y);
}
```

## What Does This Do?

This library allows use of `va_args`-style variable argument functions on **pre-C89** compilers.

It mimics `<stdarg.h>` but requires a little extra setup.

**Required Macros:**
+ Use `VA_PUSH` and `VA_POP` to wrap arguments.
+ Use `va_add(type, value)` to add arguments.
+ Replace `...` with `va_args` in function signatures.

**Examples**:

Using the function:
```c
printf("%d %d", va_push va_add(int, 42) va_add(char, 'a') va_pop);
```

Creating the function:
```c
void printf(const char *, va_args);
```

**Side Note:** On **64-bit architectures**, retrieving 32-, 16-, or 8-bit values using this mechanism may result in an **"Illegal instruction"** error, depending on how the architecture and calling convention handle type promotion and memory. This behavior is __not a flaw__ in this implementation, but a known limitation that's intentionally left unsupported to maintain consistency and stability.

----
</details>

## Icons

* © These icons are inspired by the style of Windows 2000 icons. They are original creations and are not affiliated with or endorsed by Microsoft.
