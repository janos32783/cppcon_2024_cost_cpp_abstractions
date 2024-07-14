include ../common.mk

OBJS = main.o ../startup.o
LINKER_SCRIPT = ../linker_script.ld
ELF = main.elf
BIN = main.bin

all: prog

prog: $(OBJS)
	$(CC) $(LDFLAGS) -o $(ELF) $(OBJS) -T $(LINKER_SCRIPT)
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