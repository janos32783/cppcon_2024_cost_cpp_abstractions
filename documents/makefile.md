# GCC options summary
#
# the flags that define the core
# ------------------------------
#
#  Cortex-M0:
#    o -mcpu=cortex-m0
#    o -mfloat-abi=soft     // software floating point operations
#    o -mthumb              // thumb instruction set
#
#  Cortex-M0+:
#    o -mcpu=cortex-m0plus
#    o -mfloat-abi=soft
#    o -mthumb
#
#  Cortex-M3:
#    o -mcpu=cortex-m3
#    o -mfloat-abi=soft
#    o -mthumb
#
#  Cortex-M4:
#    o -mcpu=cortex-m4
#    o -mfloat-abi=soft OR -mfloat-abi=softfp OR -mfloat-abi=hard
#    o -mfpu=fpv4-sp-d16
#    o -mthumb
#
#  Cortex-M7:
#    o -mcpu=cortex-m7
#    o -mfloat-abi=soft OR -mfloat-abi=softfp OR -mfloat-abi=hard
#    o -mfpu=fpv5-d16
#    o -mthumb
#
#  Cortex-M33:
#    o -mcpu=cortex-m33
#    o -mfloat-abi=soft OR -mfloat-abi=softfp OR -mfloat-abi=hard
#    o -mfpu=fpv5-sp-d16 OR -mfpu=fpv5-d16
#    o -mthumb
#
#  Cortex-M23:
#    o -mcpu=cortex-m23
#    o -mfloat-abi=soft
#    o -mthumb
#
# some more flags
# ---------------
#
# -W[all, extra]
#   o display compiler warnings
#   o -Wall gives the standard warnings, not all of the warnings
#   o -Wextra gives even more warnings
#
# -O[0,1,2,3,s,g]
#   o defines the level of optimization
#   o -O0: no optimization
#   o -O[1,2,3]: optimization for speed, the larger the number the more aggressive the optimizer -> could lead to larger code size
#   o -Os: optimize for size
#   o -Og: optimize, but don't make debugging more difficult
#
# -fdata-sections
# -ffunction-sections
#   o divides functions and variables into their own sections
#   o this way the linker can remove unused functions (if the --gc-sections flag is specified)
#
# -Wl,--gc-sections
#   o the linker removes unreferenced sections -> they will not be present in the binary
#
# -g
#   o create debugging information
#
# -fno-rtti
# -fno-exceptions
#   o C++ options
#   o tells the compiler that there are no runtime type informations needed, not exceptions are used -> no overhead
#
# -flto
#   o link-time-optimization
#   o the linker optimizes the whole code -> useful, linker can optimize better than the linker in most cases
#
# By adding -specs=nano.specs to the gcc link command, a reduced-size libc is linked in. The effect of this is significant.
# The standard solution for newlib is to add -specs=nosys.specs to the gcc linker command line. This links in a separate library with implementations for all required system functions.