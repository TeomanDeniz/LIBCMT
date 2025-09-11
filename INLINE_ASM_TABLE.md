# Inline Assembly - Compiler Syntax & CPU Support Matrix

This table maps compilers (listed top to bottom, identified by their predefined macros) against CPU architectures (listed left to right).

Each cell shows whether the compiler supports inline assembly for the given CPU:
> `YES` - Supported
> 
> `NO` - Not supported
> 
> `?` - Uncertain or partial support

## Small table

```
               __GNUC__ - Intel, ARM, AMD_X86, PowerPC, RISC-V, Coldfire, M68K, SH, MIPS, SPARC, BLACKFIN
               _MSC_VER - Intel
              __clang__ - Intel, ARM, AMD_X86, PowerPC, RISC-V
                  __ICC - Intel, AMD_X86
                  __ECC - Intel
                  __ICL - Intel, AMD_X86
       __INTEL_COMPILER - Intel, AMD_X86
              __TINYC__ - Intel, AMD_X86
            __WATCOMC__ - Intel, AMD_X86
          __CODEGEARC__ - Intel, AMD_X86
           __BORLANDC__ - Intel, AMD_X86
                __LCC__ - Intel, AMD_X86
                AZTEC_C - Intel, AMD_X86
            __AZTEC_C__ - Intel, AMD_X86
                 __DECC - Intel, AMD_X86
               __DECCXX - Intel, AMD_X86
                  _ACC_ - Intel, AMD_X86
                __ACK__ - Intel, AMD_X86
           __COMPCERT__ - Intel, AMD_X86
                  _DICE - Intel, AMD_X86
               __SYSC__ - Intel, AMD_X86
            __convexc__ - Intel, AMD_X86
                __DCC__ - Intel, AMD_X86
                __HP_cc - Intel, AMD_X86
                __CMB__ - Intel, AMD_X86
                __CHC__ - Intel, AMD_X86
               __CC_ARM - ARM
               __COMO__ - Intel, AMD_X86
                 _CRAYC - Intel, AMD_X86
                __DMC__ - Intel, AMD_X86
              __DJGPP__ - Intel, AMD_X86
                __EDG__ - Intel, AMD_X86
             __PATHCC__ - Intel, AMD_X86
          __FCC_VERSION - Intel, AMD_X86
                __ghs__ - Intel, AMD_X86
               __HP_aCC - Intel, AMD_X86
    __IAR_SYSTEMS_ICC__ - Intel, ARM
              __ibmxl__ - Intel, AMD_X86
                __xlC__ - Intel, AMD_X86
               __IBMC__ - Intel, AMD_X86
             __IBMCPP__ - Intel, AMD_X86
                __KCC__ - Intel, AMD_X86
                 __CA__ - ARM
               __KEIL__ - ARM
              __HIGHC__ - Intel, AMD_X86
             __MWERKS__ - Intel, AMD_X86
                   _MRI - Intel, AMD_X86
               __NDPC__ - Intel, AMD_X86
               __NDPX__ - Intel, AMD_X86
            __MINGW32__ - Intel, AMD_X86
            __MINGW64__ - Intel, AMD_X86
                  __sgi - Intel, AMD_X86, SPARC
                    sgi - Intel, AMD_X86, SPARC
                __MRC__ - Intel, AMD_X86
                  MPW_C - Intel, AMD_X86
              MPW_CPLUS - Intel, AMD_X86
        __CC_NORCROFT__ - Intel, AMD_X86
               __NWCC__ - Intel, AMD_X86
             __OPEN64__ - Intel, AMD_X86
             __OPENCC__ - Intel, AMD_X86
               ORA_PROC - Intel, AMD_X86
             __SUNPRO_C - Intel, AMD_X86, SPARC
              _PACC_VER - Intel, AMD_X86
               __POCC__ - Intel, AMD_X86
                  __PGI - Intel, AMD_X86
               __PGIC__ - Intel, AMD_X86
            __RENESAS__ - Coldfire, SH
            __HITACHI__ - Coldfire, SH
                   SASC - Intel, AMD_X86
                _SCO_DS - Intel, AMD_X86
                   SDCC - Z80
                __SNC__ - Intel, AMD_X86
               __VOSC__ - Intel, AMD_X86
                 __SC__ - AMD_X86
             __TenDRA__ - Intel, AMD_X86
__TI_COMPILER_VERSION__ - TI
             _TMS320C6X - TI
                   _UCC - Intel, AMD_X86
               __USLC__ - Intel, AMD_X86
               __VBCC__ - Intel, AMD_X86, M68K
                __ZTC__ - Intel, AMD_X86
             __TURBOC__ - Intel, AMD_X86
            __PACIFIC__ - Intel, AMD_X86
                MIRACLE - Intel, AMD_X86
                THINKC3 - Intel, AMD_X86
                THINKC4 - Intel, AMD_X86
               __HC12__ - HC12
              __HCS08__ - HCS08
           __COLDFIRE__ - Coldfire
               __CC65__ - 6502
             __MWERKS__ - ARM, PowerPC, HC12, HCS08, Coldfire, M68K, DSP56K
```

## Full Table

| Compiler macro (row)          |  Intel |    ARM | AMD_X86 | PowerPC |  RISC-V |   HC12 |  HCS08 | Coldfire |   M68K |    SH |   MIPS |  SPARC |  6502 |   Z80 |    TI | BLACKFIN | DSP56K |
|-------------------------------|-------:|-------:|--------:|--------:|--------:|-------:|-------:|---------:|-------:|------:|-------:|-------:|------:|------:|------:|---------:|-------:|
| \_\_GNUC\_\_                  |    YES |    YES |     YES |     YES |     YES |     NO |     NO |      YES |    YES |   YES |    YES |    YES |    NO |    NO |    NO |      YES |     NO |
| \_MSC_VER                     |    YES |     NO |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_clang\_\_                 |    YES |    YES |     YES |     YES |     YES |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_ICC                       |    YES |     NO |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_ECC                       |    YES |     NO |      NO |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_ICL                       |    YES |     NO |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_INTEL_COMPILER            |    YES |     NO |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_TINYC\_\_                 |    YES |     NO |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_WATCOMC\_\_               |    YES |      ? |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_CODEGEARC\_\_             |    YES |      ? |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_BORLANDC\_\_              |    YES |      ? |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_LCC\_\_                   |    YES |      ? |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| AZTEC_C                       |    YES |      ? |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_AZTEC_C\_\_               |    YES |      ? |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_DECC                      |    YES |      ? |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_DECCXX                    |    YES |      ? |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_ACC\_                       |    YES |      ? |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_ACK\_\_                   |    YES |      ? |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_COMPCERT\_\_              |    YES |      ? |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_DICE                        |    YES |      ? |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_SYSC\_\_                  |    YES |      ? |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_convexc\_\_               |    YES |      ? |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_DCC\_\_                   |    YES |      ? |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_HP_cc                     |    YES |      ? |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_CMB\_\_                   |    YES |      ? |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_CHC\_\_                   |    YES |      ? |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_CC_ARM                    |     NO |    YES |      NO |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_COMO\_\_                  |    YES |      ? |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_CRAYC                       |    YES |      ? |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_DMC\_\_                   |    YES |      ? |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_DJGPP\_\_                 |    YES |      ? |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_EDG\_\_                   |    YES |      ? |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_PATHCC\_\_                |    YES |      ? |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_FCC_VERSION               |    YES |      ? |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_ghs\_\_                   |    YES |      ? |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_HP_aCC                    |    YES |      ? |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_IAR_SYSTEMS_ICC\_\_       |    YES |    YES |       ? |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_ibmxl\_\_                 |    YES |      ? |     YES |     YES |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_xlC\_\_                   |    YES |      ? |     YES |     YES |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_IBMC\_\_                  |    YES |      ? |     YES |     YES |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_IBMCPP\_\_                |    YES |      ? |     YES |     YES |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_KCC\_\_                   |    YES |      ? |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_CA\_\_                    |     NO |    YES |      NO |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_KEIL\_\_                  |     NO |    YES |      NO |      NO |      NO |      ? |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_HIGHC\_\_                 |    YES |      ? |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_MWERKS\_\_                |    YES |      ? |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_MRI                         |    YES |      ? |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_NDPC\_\_                  |    YES |      ? |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_NDPX\_\_                  |    YES |      ? |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_MINGW32\_\_               |    YES |      ? |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_MINGW64\_\_               |    YES |      ? |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_sgi                       |    YES |      ? |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |    YES |    NO |    NO |    NO |       NO |     NO |
| sgi                           |    YES |      ? |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |    YES |    NO |    NO |    NO |       NO |     NO |
| \_\_MRC\_\_                   |    YES |      ? |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| MPW_C                         |    YES |      ? |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| MPW_CPLUS                     |    YES |      ? |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_CC_NORCROFT\_\_           |    YES |      ? |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_NWCC\_\_                  |    YES |      ? |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_OPEN64\_\_                |    YES |      ? |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_OPENCC\_\_                |    YES |      ? |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| ORA_PROC                      |    YES |      ? |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_SUNPRO_C                  |    YES |      ? |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |    YES |    NO |    NO |    NO |       NO |     NO |
| \_PACC_VER                    |    YES |      ? |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_POCC\_\_                  |    YES |      ? |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_PGI                       |    YES |      ? |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_PGIC\_\_                  |    YES |      ? |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_RENESAS\_\_               |     NO |     NO |      NO |      NO |      NO |     NO |     NO |      YES |     NO |   YES |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_HITACHI\_\_               |     NO |     NO |      NO |      NO |      NO |     NO |     NO |      YES |     NO |   YES |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| SASC                          |    YES |      ? |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_SCO_DS                      |    YES |      ? |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| SDCC                          |     NO |     NO |      NO |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |   YES |    NO |       NO |     NO |
| \_\_SNC\_\_                   |    YES |      ? |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_VOSC\_\_                  |    YES |      ? |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_SC\_\_                    |      ? |      ? |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_TenDRA\_\_                |    YES |      ? |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_TI_COMPILER_VERSION\_\_   |     NO |     NO |      NO |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |   YES |       NO |     NO |
| \_TMS320C6X                   |     NO |     NO |      NO |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |   YES |       NO |     NO |
| \_UCC                         |    YES |      ? |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_USLC\_\_                  |    YES |      ? |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_VBCC\_\_                  |    YES |      ? |     YES |      NO |      NO |     NO |     NO |       NO |    YES |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_ZTC\_\_                   |    YES |      ? |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_TURBOC\_\_                |    YES |      ? |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_PACIFIC\_\_               |    YES |      ? |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| MIRACLE                       |    YES |      ? |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| THINKC3                       |    YES |      ? |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| THINKC4                       |    YES |      ? |     YES |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_HC12\_\_                  |     NO |     NO |      NO |      NO |      NO |    YES |     NO |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_HCS08\_\_                 |     NO |     NO |      NO |      NO |      NO |     NO |    YES |       NO |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_COLDFIRE\_\_              |     NO |     NO |      NO |      NO |      NO |     NO |     NO |      YES |     NO |    NO |     NO |     NO |    NO |    NO |    NO |       NO |     NO |
| \_\_CC65\_\_                  |     NO |     NO |      NO |      NO |      NO |     NO |     NO |       NO |     NO |    NO |     NO |     NO |   YES |    NO |    NO |       NO |     NO |
| \_\_MWERKS\_\_                |     NO |    YES |      NO |     YES |      NO |    YES |    YES |      YES |    YES |    NO |     NO |     NO |    NO |    NO |    NO |       NO |    YES |
