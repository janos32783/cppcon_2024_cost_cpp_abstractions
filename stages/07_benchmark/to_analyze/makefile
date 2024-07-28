NOEXCEPT=1
NORTTI=1
MEASURE=1
include ../../common.mk

LINKER_SCRIPT = ../../linker_script.ld
ELF = main.elf

c_OBJS = main_c.o ../../startup.o
cpp_OBJS = main_cpp.o ../../startup.o

# Rule for target_01
c: $(c_OBJS)
	$(CC) $(LDFLAGS) -o $(ELF) $(c_OBJS) -T $(LINKER_SCRIPT)

# Rule for target_01
cpp: $(cpp_OBJS)
	$(CC) $(LDFLAGS) -o $(ELF) $(cpp_OBJS) -T $(LINKER_SCRIPT)

size:
	@$(SIZE) $(ELF)

objdump:
	@$(OBJDUMP) -h -S $(ELF)

clean:
	@for obj in $(c_OBJS); do if [ -f "$$obj" ]; then rm $$obj; fi; done
	@for obj in $(cpp_OBJS); do if [ -f "$$obj" ]; then rm $$obj; fi; done
	@rm -rf $(ELF)