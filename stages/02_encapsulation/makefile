NOEXCEPT=1
include ../common.mk

INCLUDES += -I../hal/Drivers/STM32F0xx_HAL_Driver/Inc \
            -I../hal/Drivers/CMSIS/Device/ST/STM32F0xx/Include \
            -I../hal/Drivers/CMSIS/Include \
            -I../hal/Core/Inc \
            -I..

OBJS = main.o ../startup.o
LINKER_SCRIPT = ../linker_script.ld
ELF = main.elf
BIN = main.bin

all: prog

prog: $(OBJS)
	$(CXX) $(LDFLAGS) -o $(ELF) $(OBJS) -T $(LINKER_SCRIPT)
	$(OBJCOPY) -O binary $(ELF) $(BIN)

objdump:
	$(OBJDUMP) -h -S $(ELF)

size:
	$(SIZE) $(ELF)

flash:
	$(STFLASH) write $(BIN) $(FLASHSTART)

reset:
	$(STFLASH) reset

clean:
	@for obj in $(OBJS); do if [ -f "$$obj" ]; then rm $$obj; fi; done
	@rm -rf $(ELF)
	@rm -rf $(BIN)