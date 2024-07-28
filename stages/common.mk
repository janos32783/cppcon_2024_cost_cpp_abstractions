# common.mk

CC = arm-none-eabi-gcc
CXX = arm-none-eabi-g++
OBJCOPY = arm-none-eabi-objcopy
OBJDUMP = arm-none-eabi-objdump
SIZE = arm-none-eabi-size
STFLASH = st-flash

# target processor
CPU = -mcpu=cortex-m0
# spec file : use the newlib-nano
SPECS = --specs=nano.specs
# no hardware floating point support -> use software support
FLOAT = -mfloat-abi=soft
# thumb instruction set
THUMB = -mthumb
# optimize for size
OPTIMIZATION = -Os
# C standard -> GNU dialect of ISO C11
CSTD = -std=gnu11
# C++ standard -> C++20
CXXSTD = -std=c++20
# place each function and data item in its own section -> help remove unused functions and data
SECTIONS = -ffunction-sections -fdata-sections
# make the linker remove any unused sections
LDSECTIONS = -Wl,--gc-sections
# enable commonly used warnings
WARN = -Wall
# no OS is used, bare metal programming
LDSPECS = --specs=nosys.specs $(SPECS)
# includes
INCLUDES = -I. -I..
# link statically
STATIC = -static

# conditional flag for map file -> make CREATE_MAP=1
ifdef CREATE_MAP
MAPFLAG = -Wl,-Map=memory.map
else
MAPFLAG =
endif

ASMFLAGS = $(CPU) -c $(SPECS) $(FLOAT) $(THUMB)
CFLAGS = $(CPU) -c $(CSTD) $(OPTIMIZATION) $(SECTIONS) $(WARN) $(SPECS) $(FLOAT) $(THUMB) $(INCLUDES)
CXXFLAGS = $(CPU) -c $(CXXSTD) $(OPTIMIZATION) $(SECTIONS) $(WARN) $(SPECS) $(FLOAT) $(THUMB) $(INCLUDES)
LDFLAGS = $(CPU) $(LDSPECS) $(FLOAT) $(THUMB) $(LDSECTIONS) $(STATIC) $(MAPFLAG)
FLASHSTART = 0x08000000

# conditional flag for exceptions -> make NOEXCEPT=1
ifdef NOEXCEPT
CXXFLAGS += -fno-exceptions
endif
# conditional flag for rtti -> make NORTTI=1
ifdef NORTTI
CXXFLAGS += -fno-rtti
endif
# conditional flag for measuring compilation performance -> make MEASURE=1
ifdef MEASURE
CFLAGS += -ftime-report
CXXFLAGS += -ftime-report
endif

%.o : %.s
	$(CXX) $(ASMFLAGS) $< -o $@

%.o : %.c
	$(CC) $(CFLAGS) $< -o $@

%.o : %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@