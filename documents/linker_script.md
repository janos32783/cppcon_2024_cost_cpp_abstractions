# Linker Script

This document gives some background information on linker scripts. Since the code snippets in this project are compiled for and executed on an STM32F030CCT6 microcontroller, the contents of the linkers script are specific to this device as well.

## Memory Map

The datasheet states that the STM32F030CCT6 microcontroller has 256KBytes Flash memory and 32Kbytes SRAM.

Flash is non-volatile memory used for storing the program code and read-only data. The memory map in the datasheet specifies that the Flash starts at address 0x08000000 and reaches up to address 0x08040000. Based on the addresses, the size 0x40000 bytes, which is 262144 in decimal. Dividing it by 1024 results in the 256KBytes.

RAM is volatile memrory for runtime data storage. It starts at address 0x20000000 and is 32Kbytes in size.

This information is translated in the linker script as follows:

```
MEMORY
{
    RAM   (xrw) : ORIGIN = 0x20000000, LENGTH = 32K
    FLASH  (rx) : ORIGIN = 0x08000000, LENGTH = 256K
}
```

## Entry Point

The entry point of the program is the reset handler. The reset handler is specified in the startup script. It executes necessary initialization steps (such as setting the stack pointer and copying data from the Flash to the RAM) before calling the entry point of the application, which is usually the *main* function. The entry point must be specified in the linker script so that the address stored in the vetor table is correct.

```
ENTRY(Reset_Handler)
```

## Symbols

The linker script provides a mechanism for defining symbols which can be referenced from the startup script. For example, the startup script need to initialize the stack pointer. But in order to do so, it needs to know the memory address to which the stack pointer should be initialized. This address can be calculated in the linker script, which specifies the memory layout. Traditionally, the stack pointer is initalized to the highest address of the stack region and the stack area grows *downwards* as new data is pushed onto the stack.

```
_end_of_stack = ORIGIN(RAM) + LENGTH(RAM);
```

## Minimum Heap and Stack Size

```
_Min_Heap_Size = 0x200; /* required amount of heap */
_Min_Stack_Size = 0x400; /* required amount of stack */
```

## Sections

The compiler groups the data and code into different sections, and it is the job of the linker to organize these sections in memory. The relevant sections in this project are the following:

- Code Sections
    - **.isr_vector**: contains the interrupt vector table, which includes the initial stack pointer and the addresses of the interrupt and exception handlers.
    - **.text**: contains the main executable code of the program.
    - **.glue_7**: contains interworking code for calling Thumb functions from ARM code. It's used for compatibility between ARM and Thumb instruction sets.
    - **.glue_7t**: contains interworking code for calling ARM functions from Thumb code.
    - **.eh_frame**: contains exception handling frames used for stack unwinding during exceptions and debugging.
    - **.init**: contains initialization functions that are called before *main*.
    - **.fini**: contains finalization functions that are called after *main* completes.
- Read-Only Data Sections
    - **.rodata**: contains read-only data, such as constants and string literals.
- ARM-Specific Sections
    - **.ARM.extab**: contains the ARM exception tables, which are used for exception handling.
    - **.ARM.exidx**: contains ARM exception index tables, used for stack unwinding during exceptions.
- Initialization Array Sections
    - **.preinit_array**: contains pointers to functions that are called before any other initialization functions.
    - **.init_array**: contains pointers to initialization functions that are called before *main*.
    - **.fini_array**: contains pointers to finalization functions that are called after *main* completes.
- Data Sections
    - **.data**: contains initialized global and static variables. These variables are copied from FLASH to RAM at startup.
    - **.RamFunc**: contains functions that need to be copied to and executed from RAM for faster execution or special requirements.
- Uninitialized Data Sections
    - **.bss**: contains uninitialized global and static variables. The startup code zeroes out this section.
    - **COMMON**: contains uninitialized global and static variables that are common symbols. These are allocated in the .bss section by the linker.

### .isr_vector

The datasheet states that on system reset, the vector table is fixed at address 0x00000000. The memory map in the datasheet shows, that, depending on the boot configuration, 0x00000000 is mapped to the beginning of the Flash memory (using a technique called *memory aliasing*, where the same physical memory can appear at different addresses). Consequently, the linker script must make sure that the vector table is placed at the very beginning of the Flash memory, to address 0x08000000. On system reset, the microcontroller's memory aliasing mechanism maps the start of the Flash to address 0x00000000. As part of the reset sequence of ARM Cortex-M processors, the microcontroller fetches the initial stack pointer from address 0x00000000 and loads it into the stack pointer, then it fetches the reset handler address from address 0x00000004 and loads it into the program counter, and finally it starts execution with the program counter now pointing to the reset handler.