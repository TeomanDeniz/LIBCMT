<IMG SRC="https://raw.githubusercontent.com/TeomanDeniz/TeomanDeniz/refs/heads/main/images/repo_projects/libcmt/HEADER2.png" ALT="Header" STYLE="WIDTH: 100%;"/>

# LIBCMT

**LIBCMT** is a modular, portable C library extension that fills in gaps left by the standard C library.  
It is fully compatible with all major compilers and platforms.

## Clone

```sh
git clone --recurse-submodules --depth 1 "git@github.com:TeomanDeniz/LIBCMT.git"
```

Cloning with `--depth 1` avoids downloading the full repository history.

## Usage

Place the cloned `LIBCMT` folder inside your project and include the header:

```c
#include "LIBCMT/LIBCMT.h"
```

LIBCMT is header-only. No additional setup required.

To include **all features**:

```c
#include "LIBCMT/LIBCMT.h" // For C
// or
#include "LIBCMT/LIBCMT.hpp" // For C++
```

### Modular Include (Optional)

You can selectively include specific components by defining `INCL__<MODULE>` macros before the include:

```c
#define INCL__FAR
#include "LIBCMT/LIBCMT.h" // Includes only the FAR module
```
Or
```c
#define INCL__INLINE
#define INCL__OBJECT
#include "LIBCMT/LIBCMT.h" // Includes INLINE and OBJECT modules only
```

### Sectional Include (Optional)

You can selectively include a specific whole section by defining `INCL__<SECTION>` macros before the include:
```c
#define INCL__KEYWORDS
#include "LIBCMT/LIBCMT.h" // Includes everything in KEYWORDS
```
or
```c
#define INCL__ATTRIBUTES
#define INCL__KEYWORDS
#define INCL__RAX
#include "LIBCMT/LIBCMT.h" // Includes RAX, All KEYWORDS, and All ATTRIBUTES
```

So far, we have these macros for including sections:
- **`INCL__ASM`**
- **`INCL__ATTRIBUTES`**
- **`INCL__CHECK_FEATURE`**
- **`INCL__ENVIRONMENTS`**
- **`INCL__FUNCTIONS`**
- **`INCL__KEYWORDS`**

If no `INCL__...` macro is defined, all modules will be automatically included by default.

Note: Defining an `INCL__<MODULE>` that belongs to a section already included via `INCL__<SECTION>` will not produce any errors or warnings.

# Show off

An example script that made by using this library Tested and worked on both Win2000 GCC Version 3.2, Debian-6 32-bit GCC, Debian-13 64-bit GCC and Win11 GCC 8.1.0:

## Main Header:
```c
#include <stdio.h> /* For printf() */

#define INCL__OBJECT
#define INCL__TRY_CATCH
#define INCL__TYPES
#include "LIBCMT/LIBCMT.h"

// User MUST use different commands depends on the CPU type.
// For architectures, RCX or RAX like registers automatically downs to ECX or EAX but no alterantive exist,
// compiler will throw an error when an unexisting command is used on a certain CPU architecture, type, or version.
#include "LIBCMT/ASM/PUSH.h" // Works on ALL compilers who supports inline assembly without an error or warning by using inline assembly.

extern var ASD(var, var);

#if defined(__unix__)
SECTION (ASD)
	ADD64 (RDI, RSI)
	MOV64 (RAX, RDI)
	RET
END
#elif defined(_WIN64)
SECTION (ASD)
	ADD64 (RCX, RDX)
	MOV64 (RAX, RCX)
	RET
END
#endif

extern var return_42(void);

SECTION (return_42)
	MOV64 (RAX, VALUE(42))
	RET
END

#include "LIBCMT/ASM/POP.h"
```

## Object Creation:
```c
object o_class // Can be also "struct o_class" if you want
{
	i_am_an_object; // Necessary and must be at the top

	void (*print)();
	void (*add)(bit32);
	bit32 value;
};

void print()
{
	object__connect (o_class); // Needed for defining "this"

	printf("[%d]\n", this->value);

	throw (this->value); // Will do nothing if it's not inside a try {...};
}

void add_class(bit32 value)
{
	OBJECT__CONNECT (o_class);

	THIS->value += value;
}

void o_class(bit32 start_value) // Constructor. Automatically works if object is created
{
	object__connect (o_class);

	object__inject_2 (add, add_class); // this->add = add_class
	object__inject (print); // As you see, manual injection is needed for per function in the object.
	// Because, You may need to detect if a needed DLL file exist, and then get the needed function from it and use it in here.
	// Otherwise, you can just use your default function.

	this->value = start_value;
}
```

## Main:
```c
int main(void)
{
	new (o_class, asd) (42);
	new (o_class, asd2) (0);

/*
	or instead, you can also do:

	#define my_class(object_name) new (o_class, object_name)

	so you can use it as:

	my_class (asd) (42);

	which works like namespace in C++ or smthing idk
*/

	asd.add(33); // asd.value is now 84

	try
	{
		int error;

		try
		{
			asd.print();
		}
		catch (error)
		{
			printf("ERROR_1: %d\n", error);
			throw (-2);
		}
	}
	catch (int error2) // May create error on older compilers, so create error2 at the top like I did in the top try-catch
	{
		printf("ERROR_2: %d\n", error2);
	}

	asd2.print();

	destroy (asd);
	destroy (asd2); // destroys are needed

	var test = 42;

	printf("ASD: %d\n", ASD(test, 12));
	printf("return_42: %d\n", return_42());
	return (0);
}
```

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

| **Name**                               | **Type**    | **Description**                                                     |
| -------------------------------------- | ----------- | ------------------------------------------------------------------- |
| `NEW`, `new`                           | `#define()` | Create an object                                                    |
| `DESTROY`, `destroy`                   | `#define()` | Destroy an object (it is necessary)                                 |
| `OBJECT`, `object`                     | `#define`   | Struct definition                                                   |
| `OBJECT__READY`, `object__ready`       | `#define()` | Check if object is successfully allocated; returns `(int)1` if true |
| `I_AM_AN_OBJECT`, `i_am_an_object`     | `#define`   | Declares the function pointer storage for an object                 |
| `OBJECT__CONNECT`, `object__connect`   | `#define()` | Connect a structure into a function                                 |
| `OBJECT__INJECT`, `object__inject`     | `#define()` | Inject a function pointer                                           |
| `OBJECT__INJECT_2`, `object__inject_2` | `#define()` | Inject a function pointer with a function (custom binding)          |
| `OBJECT__INJECT_3`, `object__inject_3` | `#define()` | Inject a function pointer with a function in an object              |

**OBJECT** is a high-performance C/C++ library for object-oriented programming in pure C, providing dynamic function tables, flexible object creation, and optimized cross-platform function injection.

## Compiler & Linking Instructions
This table is for really old compilers. If you're using a modern compiler, ignore this table.
| Compiler & Target | Link / Build Command                     |
|-------------------|------------------------------------------|
| GCC (Win2000) 3.0 | `gcc #.c C:\WINNT\system32\kernel32.dll` |
| GCC (Win98) 3.0   | `gcc #.c C:\WINNT\system32\kernel32.dll` |
| GCC (Win95) 3.0   | `gcc #.c C:\WINNT\system32\kernel32.dll` |
| GCC (DOS) 3.0?    | `gcc #.c -ldjgpp`                        |

## Features
* Pure C object-oriented programming support
* Cleaner syntax than typical C++ alternatives
* Assembly-level function injection for performance optimizations
* Supports 32-bit and 64-bit systems (likely 16-bit as well)
* Compatible with TI CGT/CCS, GCC, and MSVC compilers
* Dynamic function tables for manual runtime binding

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
> Function tables are allocated once per object.

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

## Contents / API / Macros

> ### **`OBJECT`**
> 
> It specifies that the structure you create is an object.
> 
> It performs the same function as "struct" and makes no performance changes.
> 
> It simply works as `#define object struct`.
> 
> Use it like:
> ```c
> object o_test
> {
>     i_am_an_object;
>     ...
> };

> ### **`NEW(NAME, VAR) (...)`**
> 
> Instantiates an object and runs object's constructor.
> 
> After you created the object with `new`, don't forget to delete it with `destroy`.
> 
> Usage:
> ```c
> new (o_object_type, ObjectName) (constructor, parameters, if_have, any);
> 
> ObjectName.call_a_function(42);
> 
> destroy (ObjectName);
> ```
> 
> Suggested macro for ergonomics:
> ```c
> #define test(OBJECT_VAR) new (o_test, OBJECT_VAR)
> 
> test (obj) (...);
> ```

> ### **`DESTROY(OBJECT)`**
> 
> Clears the memory of hte created object if object is successfully created.
> 
> Usage:
> ```c
> new (o_object_type, ObjectName) (constructor, parameters, if_have, any);
> 
> ObjectName.call_a_function(42);
> 
> destroy (ObjectName);
> ```

> ### **`I_AM_AN_OBJECT`**
> 
> Declares the function pointer storage for an object. Place at top of the struct.
> 
> ```c
> object o_test {
>     i_am_an_object;
>     ...
> };
> ```

> ### **`OBJECT__CONNECT(STRUCT_NAME)`**
> 
> Connects an object structure pointer (`this`) to its instance. Put this macro at the top of function bodies that use `this`.
> 
> ```c
> void function_1() {
>     object__connect(o_object);
> 
>     // this
>     ...
> }
> ```
> 
> Or, if you use uppercase version, you'll need to use:
> ```c
> void function_1() {
>     OBJECT__CONNECT(o_object);
> 
>     // THIS
>     ...
> }
> ```

> ### **`OBJECT__READY(OBJECT)`**
> 
> Checks if object is properly allocated.
> 
> ```c
> new(test_object_type, OBJ) ();
> 
> if (object__ready(OBJ)) {
>     OBJ.FUNC1();
>     OBJ.FUNC2();
>     destroy(OBJ);
> } else {
>     printf("Object not ready!\n");
> }
> ```

> ### **`OBJECT__INJECT(MEMBER)`**
> 
> Injects a function with same name.
> 
> ```c
> void test_object_type()
> {
>     object__connect(test_object_type);
> 
>     object__inject(FUNC_A);
>     object__inject(FUNC_B);
> }
> ```
> Means:
> ```c
> this->FUNC_A = FUNC_A;
> this->FUNC_B = FUNC_B;
> ```

> ### **`OBJECT__INJECT_2(MEMBER, FUNCTION)`**
> 
> Injects a function with a different name.
> 
> ```c
> void test_object_type()
> {
>     object__connect(test_object_type);
> 
>     object__inject_2(FUNC_A, impl_func_a);
>     object__inject_2(FUNC_B, impl_func_b);
> }
> ```
> Means:
> ```c
> this->FUNC_A = impl_func_a;
> this->FUNC_B = impl_func_b;
> ```

> ### **`OBJECT__INJECT_3(OBJECT_PTR, MEMBER, FUNCTION)`**
> 
> Inject a function pointer with a function into a specific object instance.
> 
> ```c
> void test_object_type()
> {
>     object__connect(test_object_type);
> 
>     object__inject_3(this, FUNC_A, impl_func_a);
>     object__inject_3(this, FUNC_B, impl_func_b);
> }
> ```
> Means:
> ```c
> this->FUNC_A = impl_func_a;
> this->FUNC_B = impl_func_b;
> ```

## Examples

**Basic object definition**
```c
object test_object_type {
    i_am_an_object;

    void (*worked)(int);
    int value;
};
```

**Functions**
```c
extern void worked(int);

static void test_object_type(void) { // Constructor
    object__connect(test_object_type);

    object__inject(worked);
    this->value = 0;
}

void worked(int n) {
    OBJECT__CONNECT(test_object_type);
    THIS->value += n;
}
```

**Usage**
```c
new (test_object_type, obj) (); // constructor called

obj.worked(42); // uses implicit `this`

destroy (obj);
```

**Multiple objects example**
```c
new (test_object_type, test1) ();
new (test_object_type, test2) ();

test1.worked(42);
test1.worked(42);
test2.worked(42);
test1.worked(42);
test2.worked(42);

destroy (test1);
destroy (test2);
```

**Full example (compact)**

Type + functions + table

```c
object test_object_type {
    i_am_an_object;

    int  (*FUNC1)();
    void (*FUNC2)();
    void (*FUNC3)();
    int a;
};

static int O_FUNC1() {
    object__connect (test_object_type);

    printf("1\n");
    return (42);
}

static void O_FUNC2() {
    object__connect (test_object_type);

    printf("2\n");
}

static void FUNC3() {
    object__connect (test_object_type);

    printf("3\n");
}

static void test_object_type() { // Constructor
    object__connect (test_object_type);
    object__inject_2 (FUNC1, O_FUNC1);
    object__inject_2 (FUNC2, O_FUNC2);
    object__inject (FUNC3);

    printf("0\n");
}
 ```

Using objects in `main`

```c
int main(void) {
    {
        new (test_object_type, TEST) ();
        TEST.FUNC1();
        TEST.FUNC2();
        TEST.FUNC3();

        destroy (TEST);
    }

    {
        new (test_object_type, TEST1) ();
        new (test_object_type, TEST2) ();

        TEST1.FUNC1();
        TEST1.FUNC2();

        TEST2.FUNC1();
        TEST2.FUNC2();

        TEST1.FUNC1();
        TEST2.FUNC1();

        printf("%d\n", TEST1.FUNC1());

        destroy (TEST1);
        destroy (TEST2);
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
	<b>PUSH & POP</b> - Use ASM inside C Language <b>(WIP)</b>
</summary>

> [!WARNING]  
> **THIS IS A WIP CONTENT!!!** THIS EXTENSION MIGHT NOT WORK ON ALL COMPILERS, OPERATING SYSTEMS, OR ARCHITECTURES!!!
> MAJOR MAINTENANCE IS PLANNED! USE IT AT YOUR OWN **RISK**

> ⚠️ Important
> ### File(s) at: [**[📜 LIBCMT/ASM/PUSH.h](https://github.com/TeomanDeniz/LIBCMT/blob/main/ASM/PUSH.h)**] [**[📜 LIBCMT/ASM/POP.h](https://github.com/TeomanDeniz/LIBCMT/blob/main/ASM/POP.h)**]
> ### Call With:
> ```c
> #include "LIBCMT/ASM/PUSH.h"
> // ASM CODE ...
> #include "LIBCMT/ASM/POP.h"
> ```

## Builtin keywords:
| **Name**      | **Type**     | **Description**              |
|---------------|--------------|------------------------------|
| `SECTION`     | `#define ()` | Create a section.            |
| `END`         | `#define`    | End of section.              |
| `VALUE`       | `#define ()` | Use a direct value.          |
| `MEM8`        | `#define ()` | Use 8-bit memory (One arg)   |
| `MEM16`       | `#define ()` | Use 16-bit memory (One arg)  |
| `MEM32`       | `#define ()` | Use 32-bit memory (One arg)  |
| `MEM64`       | `#define ()` | Use 64-bit memory (One arg)  |
| `MEM8_INDEX`  | `#define ()` | Use 8-bit memory (Two args)  |
| `MEM16_INDEX` | `#define ()` | Use 16-bit memory (Two args) |
| `MEM32_INDEX` | `#define ()` | Use 32-bit memory (Two args) |
| `MEM64_INDEX` | `#define ()` | Use 64-bit memory (Two args) |

## ASM Keywords:
### Intel:
Registers:
| **Name**                              | **Description**                     |
|---------------------------------------|-------------------------------------|
| `RSI`, `ESI`, `SI`, `AH`              | Source index register               |
| `RDI`, `EDI`, `DI`, `BH`              | Destination index register          |
| `RBP`, `EBP`, `BP`, `CH`              | Base pointer register               |
| `RSP`, `ESP`, `SP`, `DH`              | Stack pointer register              |
| `RAX`, `EAX`, `AX`, `AL`              | Primary accumulator register        |
| `RBX`, `EBX`, `BX`, `BL`              | Base register                       |
| `RCX`, `ECX`, `CX`, `CL`              | Counter register                    |
| `RDX`, `EDX`, `DX`, `DL`              | Data register                       |
| `CS`, `DS`, `SS`, `ES`, `FS`, `GS`    | Segment registers                   |
| `R8`, `R9`, ..., `R14`, `R15`         | General-purpose extension registers |
| `CR0`, `CR2`, `CR3`, `CR4`, `CR8`     | Control registers                   |
| `DR0`, `DR1`, ..., `DR7`, `DR8`       | Debug registers                     |
| `GDTR`, `IDTR`, `LDTR`, `TR`          | Descriptor table registers          |
| `MM0`, `MM1`, ..., `MM6`, `MM7`       | 64-bit SIMD registers               |
| `XMM0`, `XMM1`, ..., `XMM14`, `XMM15` | 128-bit registers                   |
| `YMM0`, `YMM1`, ..., `YMM14`, `YMM15` | 256-bit registers                   |
| `ZMM0`, `ZMM1`, ..., `ZMM30`, `ZMM31` | 512-bit registers                   |

Commands:
| **Name** | **Type**     | **Description**                                                |
|----------|--------------|----------------------------------------------------------------|
| `RET`    | `#define`    | If section called via CALL, jumps back to where it is called.  |
| `MOV8`   | `#define ()` | Moves 1 byte from the source to the destination.               |
| `MOV16`  | `#define ()` | Moves 2 Bytes from the source to the destination.              |
| `MOV32`  | `#define ()` | Moves 4 Bytes from the source to the destination.              |
| `MOV64`  | `#define ()` | Moves 8 Bytes from the source to the destination.              |
| `ADD8`   | `#define ()` | Adds 1 byte from the source to the destination.                |
| `ADD16`  | `#define ()` | Adds 2 bytes from the source to the destination.               |
| `ADD32`  | `#define ()` | Adds 4 bytes from the source to the destination.               |
| `ADD64`  | `#define ()` | Adds 8 bytes from the source to the destination.               |

**Note**: `MOV64`, `ADD64`, `@64` etc... downscale automatically on 32/16-bit modes.

## Overview
This header provides a unified macro layer that lets you write inline assembly with minimal compiler-specific boilerplate.
The system:
- Detects compiler ASM support
- Detects architecture: **16-bit / 32-bit / 64-bit**
- Detects backend syntax: **AT&T**, **Intel**, or **MSVC inline asm**
- Defines stable macro keywords so your ASM blocks stay portable

It abstracts:
- Register names
- Memory addressing
- Basic arithmetic and move operations
- Section creation (labels)
- Return instructions
---

## What This System Does
* Ensures your inline ASM can compile across:
* * GCC / Clang (AT&T syntax)
* * ICC (AT&T or Intel depending on build)
* * MSVC (__asm{} Intel syntax)
* Provides stable names for registers that change size across architectures
* Allows macro-style 8/16/32/64-bit ops without manual syntax branching
* Provides unified memory addressing patterns
* Enables platform-independent section creation for ASM entry points

## Use Examples
```c
#include "LIBCMT/ASM/PUSH.h"
SECTION (example_func) // example_func:
    MOV32 (EAX, EBX)   // mov rax, ebx
    ADD32 (EAX, 1)     // add eax, 1
    RET                // ret
END
#include "LIBCMT/ASM/POP.h"

extern int example_func(void); // Connect it with C
```
Example - Byte Copy Routine
```c
#include "LIBCMT/ASM/PUSH.h"
SECTION (copy_byte)      // copy_byte:
    MOV8 (MEM8(RDI), AL) // mov byte [rdi], al
    RET                  // ret
END
#include "LIBCMT/ASM/POP.h"
```
Example - Add Value at Index
```c
#include "LIBCMT/ASM/PUSH.h"
SECTION (add_indexed)                  // add_indexed:
    ADD32 (MEM32_INDEX(RAX, RCX), EDX) // add dword [rax + rcx], edx
    RET                                // ret
END
#include "LIBCMT/ASM/POP.h"
```

Example - Setting a direct value to a register
```c
#include "LIBCMT/ASM/PUSH.h"
SECTION (return_42)        // return_42:
    MOV64 (RAX, VALUE(42)) // add rax, 42
    RET                    // ret
END
#include "LIBCMT/ASM/POP.h"
```

----
</details>

<details>

<summary>
	<img src="https://raw.githubusercontent.com/TeomanDeniz/TeomanDeniz/main/images/repo_projects/libcmt/RAX.gif">
	<b>RAX</b> - Read or Write the register RAX in Intel CPU <b>(WIP)</b>
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
| `SET_RAX`, `set_rax` | `#define ()`  | Set `RAX`                 |

## What Does It Do

With these functions, you're able to move and get values from the Intel CPU register RAX and stack with different data sizes and archs.

Using `GET_RAX` or `SET_RAX` on a non-Intel CPU will cause an error.

> ⚠️ Note
> 
> On 32-BIT systems, EAX register is used.

## How To Use

# HOW TO USE

**Example 1: Read RAX into a variable**
```c
uint64_t myValue;

GET_RAX(myValue); // MOV RAX contents into myValue

// myValue now holds the value from RAX
```

**Example 2: Read EAX on 32-bit system**
```c
unsigned int myValue32;

GET_RAX(myValue32); // MOV EAX contents into myValue32

// myValue32 now holds the value from EAX
```

**Example 3: Setting RAX**
```c
uint64_t armValue = 42;

SET_RAX(armValue); // RAX is now 42

// or

SET_RAX(42); // RAX is now 42
```

----
</details>

<details>

<summary>
    <img src="https://raw.githubusercontent.com/TeomanDeniz/TeomanDeniz/main/images/repo_projects/libcmt/X17.gif">
    <b>X17</b> - Read or Write the register X17 in ARM CPU
</summary>

> ⚠️ Important
> ### File at: [**[📜 LIBCMT/ASM/X17.h](https://github.com/TeomanDeniz/LIBCMT/blob/main/ASM/X17.h)**]
> ### Call With:
> ```c
> #define INCL__X17
> #include "LIBCMT/LIBCMT.h"
> ```

| **Name**             | **Type**      | **Description**           |
|----------------------|---------------|---------------------------|
| `GET_X17`, `get_x17` | `#define ()`  | Set `X17` into a variable |
| `SET_X17`, `set_x17` | `#define ()`  | Set `X17`                 |

## What Does It Do

With these functions, you're able to move and get values from the ARM CPU register X17 and stack with different data sizes and archs.

Using `GET_X17` or `SET_X17` on a non-Intel CPU will cause an error.

> ⚠️ Note
> 
> On 32-BIT systems, all functions used from this header will throw an error.

## How To Use

# HOW TO USE

**Example 1: Read X17 into a variable**
```c
uint64_t myValue;

GET_X17(myValue); // MOV X17 contents into myValue

// myValue now holds the value from X17
```

**Example 2: Setting X17**
```c
uint64_t myValue = 42;

SET_X17(myValue); // X17 now 42

// or

SET_X17(42); // X17 now 42
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
>     : "=r"(result)   // %0
>     : "r"(input_var) // %1
>     : "%eax"
> );
> ```

----
</details>

<details>

<summary>
    <img src="https://raw.githubusercontent.com/TeomanDeniz/TeomanDeniz/main/images/repo_projects/libcmt/STRINGIFICATION.gif">
    <b>STRINGIFICATION</b> - Defines a macro if stringification is supported on your compiler
</summary>

> ⚠️ Important
> ### File at: [**[📜 LIBCMT/CHECK_FEATURE/STRINGIFICATION.h](https://github.com/TeomanDeniz/LIBCMT/blob/main/CHECK_FEATURE/STRINGIFICATION.h)**]
> ### Call With:
> ```c
> #define INCL__STRINGIFICATION
> #include "LIBCMT/LIBCMT.h"
> ```

| **Name**                         | **Type**     | **Description**                                       |
|----------------------------------|--------------|-------------------------------------------------------|
| `IS__STRINGIFICATION__SUPPORTED` | `#define`    | Defines if stringification supported by your compiler |

## What Does This Header Do

Defines `IS__STRINGIFICATION__SUPPORTED` if the compiler supports the stringification (`#`) feature.

## What Is The "Stringification"

Stringification refers to the `#` operator in macros, used to convert pure inputs to strings.

**Example**:
```c
#define X(A) #A

printf( X( i am testing something ) ); // Will return: "i am testing something" without a new line.
```

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
	<img src="https://raw.githubusercontent.com/TeomanDeniz/TeomanDeniz/main/images/repo_projects/libcmt/ARCHITECTURE.gif">
	<b>ARCHITECTURE</b> - You can get information about your CPU architecture.
</summary>

> ⚠️ Important
> ### File at: [**[📜 LIBCMT/ENVIRONMENTS/ARCHITECTURE.h](https://github.com/TeomanDeniz/LIBCMT/blob/main/ENVIRONMENTS/ARCHITECTURE.h)**]
> ### Call With:
> ```c
> #define INCL__ARCHITECTURE
> #include "LIBCMT/LIBCMT.h"
> ```

## CPU Architecture Word Size
| Name                | Type      | Description                           |
| ------------------- | --------- | ------------------------------------- |
| `__SYSTEM_64_BIT__` | `#define` | Defined if the system is 64-bit       |
| `__SYSTEM_32_BIT__` | `#define` | Defined if the system is 32-bit       |
| `__SYSTEM_31_BIT__` | `#define` | Defined if the system also 31-bit     |
| `__SYSTEM_16_BIT__` | `#define` | Defined if the system is 16-bit       |
| `__SYSTEM_8_BIT__`  | `#define` | Defined if the system is 8-bit        |
| `__SYSTEM_BIT__`    | `#define` | Macro indicating the system bit-width |

## Forced / Compiler-Supported Extended Integer Sizes
| Name              | Type      | Description                                                        |
| ----------------- | --------- | ------------------------------------------------------------------ |
| `__HAS_128_BIT__` | `#define` | Defined if the system also supports 128-bit                        |
| `__HAS_64_BIT__`  | `#define` | Defined if the system also supports 64-bit (for 32/16-bit systems) |

## Vector Register Sizes
| Name                     | Type      | Description                                             |
| ------------------------ | --------- | ------------------------------------------------------- |
| `__HAS_512_BIT_VECTOR__` | `#define` | Defined if the system supports 512-bit vector registers |
| `__HAS_256_BIT_VECTOR__` | `#define` | Defined if the system supports 256-bit vector registers |
| `__HAS_128_BIT_VECTOR__` | `#define` | Defined if the system supports 128-bit vector registers |

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

| Name        | Type      | Description                                        |
| ----------- | --------- | -------------------------------------------------- |
| `KNR_STYLE` | `#define` | Defined if compiler is using K&R style syntax.     |
| `void`      | `#define` | Defined if in K&R.                                 |
| `const`     | `#define` | Defined if in K&R.                                 |
| `volatile`  | `#define` | Defined if in K&R.                                 |
| `signed`    | `#define` | Defined if in K&R.                                 |
| `unsigned`  | `#define` | Defined if in Microsoft C Compiler Version 1.0/2.0 |

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
	<img src="https://raw.githubusercontent.com/TeomanDeniz/TeomanDeniz/main/images/repo_projects/libcmt/STDCALL.gif">
	<b>STDCALL</b> - A calling convention (mainly on Windows) where the callee cleans the stack and parameters are passed right-to-left
</summary>

> ⚠️ Important
> ### File at: [**[📜 LIBCMT/KEYWORDS/STDCALL.h](https://github.com/TeomanDeniz/LIBCMT/blob/main/KEYWORDS/STDCALL.h)**]
> ### Call With:
> ```c
> #define INCL__STDCALL
> #include "LIBCMT/LIBCMT.h"
> ```

| **Name**  | **Type**   | **Description**                        |
|-----------|------------|----------------------------------------|
| `STDCALL` | `#define`  | Optimise the function to OS ABI rules. |

## How To Use

```c
int STDCALL	WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, ...)
{
	. . .
}
```

## What Does It Do

Defines a calling convention where arguments are passed on the stack, the callee cleans the stack, and (on 32-bit systems) the function name may be decorated.

Primarily associated with Windows APIs but supported by multiple compilers for binary-interface compatibility.

## Side Notes

Yes, you must use the `STDCALL` keyword in your function prototypes:

```c
extern STDCALL int WinMain(...);
//     ^^^^^^^
```

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
	<img src="https://raw.githubusercontent.com/TeomanDeniz/TeomanDeniz/main/images/repo_projects/libcmt/plaltform_corssing.gif">
	<b>TYPES</b> - Standard and fixed-size types with support macros for portability
</summary>

> ⚠️ Important
> ### File at: [**[📜 LIBCMT/KEYWORDS/TYPES.h](https://github.com/TeomanDeniz/LIBCMT/blob/main/KEYWORDS/TYPES.h)**]
> ### Call With:
> ```c
> #define INCL__TYPES
> #include "LIBCMT/LIBCMT.h"
> ```

## Standard Types
| Name           | Type    | Description                                       |
|----------------|---------|---------------------------------------------------|
| `BYTE`, `byte` | typedef | 8-bit storage unit (char)                         |
| `LET`, `let`   | typedef | Type for array indexing and sizes (like `size_t`) |
| `VAR`, `var`   | typedef | Type capable of holding maximum addressable value |
| `PTR`, `ptr`   | typedef | Generic pointer type                              |

## Types with Fixed Sizes
| Name               | Type    | Description                                       |
|--------------------|---------|---------------------------------------------------|
| `BIT8`, `bit8`     | typedef | 8-bit unsigned or signed integer                  |
| `BIT16`, `bit16`   | typedef | 16-bit unsigned or signed integer                 |
| `BIT32`, `bit32`   | typedef | 32-bit unsigned or signed integer                 |
| `BIT64`, `bit64`   | typedef | 64-bit unsigned or signed integer                 |
| `BIT128`, `bit128` | typedef | 128-bit unsigned or signed integer (if supported) |

## Floating-Point Types
| Name                   | Type    | Description                               |
|------------------------|---------|-------------------------------------------|
| `FLOAT32`, `float32`   | typedef | 32-bit single-precision floating-point    |
| `FLOAT64`, `float64`   | typedef | 64-bit double-precision floating-point    |
| `FLOAT128`, `float128` | typedef | 128-bit extended-precision floating-point |

## Macros to Check Support of Types
| Name                  | Type    | Description                                |
|-----------------------|---------|--------------------------------------------|
| `SUPPORTED__BIT64`    | #define | Defined if compiler supports BIT64 type    |
| `SUPPORTED__BIT128`   | #define | Defined if compiler supports BIT128 type   |
| `SUPPORTED__FLOAT64`  | #define | Defined if compiler supports FLOAT64 type  |
| `SUPPORTED__FLOAT128` | #define | Defined if compiler supports FLOAT128 type |

> **Note:**  
> Some types may not be defined if the platform or compiler does not support them.  
> For example, `FLOAT64` may not be available if the native `double` type is only 32 bits on your system.  
> Similarly, `FLOAT128` and `BIT128` are only defined if the compiler and architecture support 128-bit values.  
>
> Users should check the corresponding macros (e.g., `SUPPORTED__FLOAT64`, `SUPPORTED__FLOAT128`, `SUPPORTED__BIT128`) before using these types to ensure portability and correctness.

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

<details>

<summary>
    <img src="https://raw.githubusercontent.com/TeomanDeniz/TeomanDeniz/main/images/repo_projects/libcmt/va_args.gif">
    <b>VA_ARGS</b> - Make "va_args" system work on older compilers (For before C89)
</summary>

> ⚠️ Important
> ### File at: [**[📜 LIBCMT/KEYWORDS/VA_ARGS.h](https://github.com/TeomanDeniz/LIBCMT/blob/main/KEYWORDS/VA_ARGS.h)**]
> ### Call With:
> ```c
> #define INCL__VA_ARGS
> #include "LIBCMT/LIBCMT.h"
> ```

| Name                   | Type        | Description                                            |
| ---------------------- | ----------- | ------------------------------------------------------ |
| `va_list`, `VA_LIST`   | `typedef`   | A type for creating your argument list                 |
| `va_arg`, `VA_ARG`     | `#define()` | Get a variable from your `va_list` in your function    |
| `va_copy`, `VA_COPY`   | `#define()` | Copy your `va_list` address                            |
| `va_start`, `VA_START` | `#define()` | Get the address pointer of your argument list          |
| `va_args`, `VA_ARGS`   | `#define`   | Tell the compiler the function accepts varargs (`...`) |
| `va_end`, `VA_END`     | `#define()` | End a `va_list` pointer                                |

## How To Use

```c
void test(int, va_args); // PROTOTYPE

int main(void)
{
	test(42, 42.0, "Hello world");
	return (0);
}

extern int printf(const char *, va_args); // PROTOTYPE

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
	va_end(y);
}
```

## What Does This Do?

This library allows use of `va_args`-style variable argument functions on **pre-C89** compilers.

You must use `VA_ARGS` or `va_args` instead of `...` to use this feature in functions.

### For example:

```c
printf(const char *, ...);
```
becomes
```c
printf(const char *, va_args);
```

----
</details>

## Icons

* © These icons are inspired by the style of Windows 2000 icons. They are original creations and are not affiliated with or endorsed by Microsoft.
