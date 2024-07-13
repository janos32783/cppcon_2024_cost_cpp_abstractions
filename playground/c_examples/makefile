STARTUP_FILE = startup

all: help

help:
	@echo "possible targets are:"
	@echo "    - base"
	@echo "    - hal"

base: MAIN_FILE = 00_base.c
hal:  MAIN_FILE = 01_hal.c

base hal: prog

prog:
	arm-none-eabi-gcc -mcpu=cortex-m0 -c -specs=nano.specs -mfloat-abi=soft -mthumb -o $(STARTUP_FILE).o $(STARTUP_FILE).s
	arm-none-eabi-gcc -mcpu=cortex-m0 -c -std=gnu11 -Os -ffunction-sections -fdata-sections -Wall --specs=nano.specs -mfloat-abi=soft -mthumb -o main.o $(MAIN_FILE)
	arm-none-eabi-gcc -mcpu=cortex-m0 -o main.elf main.o $(STARTUP_FILE).o -T linker_script.ld --specs=nosys.specs --specs=nano.specs -mfloat-abi=soft -mthumb
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
