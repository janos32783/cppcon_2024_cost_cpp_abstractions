STARTUP_FILE = startup

all: help

help:
	@echo "possible targets are:"
	@echo "    - base"
	@echo "    - optimization"
	@echo "    - encapsulation_static"
	@echo "    - encapsulation_template"
	@echo "    - inheritance"
	@echo "    - runtime_polymorphism"
	@echo "    - static_polymorphism"
	@echo "    - code_bloat"
	@echo "    - floating_point"
	@echo "    - dynamic_memory"
	@echo "    - no_dynamic_memory"

base:                   MAIN_FILE = 00_base.cpp
optimization:           MAIN_FILE = 01_optimization.cpp
encapsulation_static:   MAIN_FILE = 02_encapsulation_static.cpp
encapsulation_template: MAIN_FILE = 03_encapsulation_template.cpp
inheritance:            MAIN_FILE = 04_inheritance.cpp
runtime_polymorphism:   MAIN_FILE = 05_runtime_polymorphism.cpp
static_polymorphism:    MAIN_FILE = 06_static_polymorphism.cpp
code_bloat:             MAIN_FILE = 07_code_bloat.cpp
floating_point:         MAIN_FILE = 08_floating_point.cpp
dynamic_memory:         MAIN_FILE = 09_dynamic_memory.cpp
no_dynamic_memory:      MAIN_FILE = 10_no_dynamic_memory.cpp

base optimization encapsulation_static encapsulation_template inheritance runtime_polymorphism static_polymorphism code_bloat floating_point dynamic_memory no_dynamic_memory: prog

prog:
	arm-none-eabi-g++ -mcpu=cortex-m0 -c -specs=nano.specs -mfloat-abi=soft -mthumb -o $(STARTUP_FILE).o $(STARTUP_FILE).s
	arm-none-eabi-g++ -mcpu=cortex-m0 -c -std=c++20 -Os -ffunction-sections -fdata-sections -Wall --specs=nano.specs -mfloat-abi=soft -mthumb -o main.o $(MAIN_FILE)
	arm-none-eabi-g++ -mcpu=cortex-m0 -o main.elf main.o $(STARTUP_FILE).o -T linker_script.ld --specs=nosys.specs --specs=nano.specs -mfloat-abi=soft -mthumb
	arm-none-eabi-objcopy -O binary main.elf main.bin

objdump:
	arm-none-eabi-objdump -h -S main.elf

size:
	arm-none-eabi-size main.elf

flash:
	st-flash write main.bin 0x08000000

reset:
	st-flash reset

clean:
	@if [ -f main.o ]; then rm main.o; fi
	@if [ -f main.s ]; then rm main.s; fi
	@if [ -f $(STARTUP_FILE).o ]; then rm $(STARTUP_FILE).o; fi
	@if [ -f main.elf ]; then rm main.elf; fi
	@if [ -f main.bin ]; then rm main.bin; fi
