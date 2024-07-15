STARTUP_FILE = startup
MAIN = main
INCLUDES = -I. -I.. -I../hal/CMSIS/Device/ST/STM32F0xx/Include -I../hal/CMSIS/Include

all: prog

prog:
	arm-none-eabi-g++ -mcpu=cortex-m0 -c -specs=nano.specs -mfloat-abi=soft -mthumb -o $(STARTUP_FILE).o $(STARTUP_FILE).s
	arm-none-eabi-g++ -mcpu=cortex-m0 -c -std=c++20 -Os -ffunction-sections -fdata-sections -Wall --specs=nano.specs -mfloat-abi=soft -mthumb $(INCLUDES) -o $(MAIN).o $(MAIN).cpp
	arm-none-eabi-g++ -mcpu=cortex-m0 -o $(MAIN).elf $(MAIN).o $(STARTUP_FILE).o -T linker_script.ld --specs=nosys.specs --specs=nano.specs -mfloat-abi=soft -mthumb
	arm-none-eabi-objcopy -O binary $(MAIN).elf $(MAIN).bin

objdump:
	arm-none-eabi-objdump -h -S $(MAIN).elf

size:
	arm-none-eabi-size $(MAIN).elf

flash:
	st-flash write $(MAIN).bin 0x08000000

reset:
	st-flash reset

clean:
	@if [ -f $(MAIN).o ]; then rm $(MAIN).o; fi
	@if [ -f $(MAIN).s ]; then rm $(MAIN).s; fi
	@if [ -f $(STARTUP_FILE).o ]; then rm $(STARTUP_FILE).o; fi
	@if [ -f $(MAIN).elf ]; then rm $(MAIN).elf; fi
	@if [ -f $(MAIN).bin ]; then rm $(MAIN).bin; fi




