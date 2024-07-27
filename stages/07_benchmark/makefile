include ../common.mk

LINKER_SCRIPT = ../linker_script.ld
ELF = main.elf
BIN = main.bin

target_01_c_OBJS = build/01_main_c.o ../startup.o
target_01_cpp_OBJS = build/01_main_cpp.o ../startup.o
target_02_basic_OBJS = build/02_basic_main.o ../startup.o
target_02_template_OBJS = build/02_basic_template.o ../startup.o
target_03_OBJS = build/03_main.o ../startup.o

# Rule for target_01
target_01_c: $(target_01_c_OBJS)
	$(CC) $(LDFLAGS) -o target_01.elf $(target_01_c_OBJS) -T $(LINKER_SCRIPT)
	$(OBJCOPY) -O binary target_01.elf target_01.bin

# Rule for target_01
target_01_cpp: $(target_01_cpp_OBJS)
	$(CC) $(LDFLAGS) -o target_01.elf $(target_01_cpp_OBJS) -T $(LINKER_SCRIPT)
	$(OBJCOPY) -O binary target_01.elf target_01.bin

# Rule for target_02_basic
target_02_basic: $(target_02_basic_OBJS)
	$(CC) $(LDFLAGS) -o target_02_basic.elf $(target_02_basic_OBJS) -T $(LINKER_SCRIPT)
	$(OBJCOPY) -O binary target_02_basic.elf target_02_basic.bin

# Rule for target_02_template
target_02_template: $(target_02_template_OBJS)
	$(CC) $(LDFLAGS) -o target_02_template.elf $(target_02_template_OBJS) -T $(LINKER_SCRIPT)
	$(OBJCOPY) -O binary target_02_template.elf target_02_template.bin

# Rule for target_03
target_03: $(target_03_OBJS)
	$(CC) $(LDFLAGS) -o target_03.elf $(target_03_OBJS) -T $(LINKER_SCRIPT)
	$(OBJCOPY) -O binary target_03.elf target_03.bin

objdump:
	$(OBJDUMP) -h -S $(ELF)

size:
	$(SIZE) $(ELF)

flash:
	$(STFLASH) write $(BIN) $(FLASHSTART)

reset:
	$(STFLASH) reset

clean:
	@for obj in $(target_01_c_OBJS); do if [ -f "$$obj" ]; then rm $$obj; fi; done
	@for obj in $(target_01_cpp_OBJS); do if [ -f "$$obj" ]; then rm $$obj; fi; done
	@for obj in $(target_02_basic_OBJS); do if [ -f "$$obj" ]; then rm $$obj; fi; done
	@for obj in $(target_02_template_OBJS); do if [ -f "$$obj" ]; then rm $$obj; fi; done
	@for obj in $(target_03_OBJS); do if [ -f "$$obj" ]; then rm $$obj; fi; done
	@rm -rf $(ELF)
	@rm -rf $(BIN)