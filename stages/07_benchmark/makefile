NOEXCEPT=1
NORTTI=1
include ../common.mk

LINKER_SCRIPT = ../linker_script.ld
ELF = main.elf

target_01_c_OBJS = build/01_main_c.o ../startup.o
target_01_cpp_OBJS = build/01_main_cpp.o ../startup.o
target_01_inlined_c_OBJS = build/01_main_inlined_c.o ../startup.o
target_01_inlined_cpp_OBJS = build/01_main_inlined_cpp.o ../startup.o
target_01_classes_OBJS = build/01_main_classes.o ../startup.o
target_02_basic_OBJS = build/02_basic_main.o ../startup.o
target_02_template_OBJS = build/02_basic_template.o ../startup.o
target_03_OBJS = build/03_main.o ../startup.o
target_04_dyn_OBJS = build/04_dyn_poly.o ../startup.o
target_04_sta_OBJS = build/04_sta_poly.o ../startup.o

# Rule for target_01
target_01_c: $(target_01_c_OBJS)
	$(CC) $(LDFLAGS) -o $(ELF) $(target_01_c_OBJS) -T $(LINKER_SCRIPT)

# Rule for target_01
target_01_cpp: $(target_01_cpp_OBJS)
	$(CC) $(LDFLAGS) -o $(ELF) $(target_01_cpp_OBJS) -T $(LINKER_SCRIPT)

target_01_inlined_c: $(target_01_inlined_c_OBJS)
	$(CC) $(LDFLAGS) -o $(ELF) $(target_01_inlined_c_OBJS) -T $(LINKER_SCRIPT)

target_01_inlined_cpp: $(target_01_inlined_cpp_OBJS)
	$(CC) $(LDFLAGS) -o $(ELF) $(target_01_inlined_cpp_OBJS) -T $(LINKER_SCRIPT)

# Rule for target_01_classes
target_01_classes: $(target_01_classes_OBJS)
	$(CC) $(LDFLAGS) -o $(ELF) $(target_01_classes_OBJS) -T $(LINKER_SCRIPT)

# Rule for target_02_basic
target_02_basic: $(target_02_basic_OBJS)
	$(CC) $(LDFLAGS) -o $(ELF) $(target_02_basic_OBJS) -T $(LINKER_SCRIPT)

# Rule for target_02_template
target_02_template: $(target_02_template_OBJS)
	$(CC) $(LDFLAGS) -o $(ELF) $(target_02_template_OBJS) -T $(LINKER_SCRIPT)

# Rule for target_03
target_03: $(target_03_OBJS)
	$(CC) $(LDFLAGS) -o $(ELF) $(target_03_OBJS) -T $(LINKER_SCRIPT)

target_04_dyn: $(target_04_dyn_OBJS)
	$(CC) $(LDFLAGS) -o $(ELF) $(target_04_dyn_OBJS) -T $(LINKER_SCRIPT)

target_04_sta: $(target_04_sta_OBJS)
	$(CC) $(LDFLAGS) -o $(ELF) $(target_04_sta_OBJS) -T $(LINKER_SCRIPT)

size:
	@$(SIZE) $(ELF)

clean:
	@for obj in $(target_01_c_OBJS); do if [ -f "$$obj" ]; then rm $$obj; fi; done
	@for obj in $(target_01_cpp_OBJS); do if [ -f "$$obj" ]; then rm $$obj; fi; done
	@for obj in $(target_01_inlined_c_OBJS); do if [ -f "$$obj" ]; then rm $$obj; fi; done
	@for obj in $(target_01_inlined_cpp_OBJS); do if [ -f "$$obj" ]; then rm $$obj; fi; done
	@for obj in $(target_01_classes_OBJS); do if [ -f "$$obj" ]; then rm $$obj; fi; done
	@for obj in $(target_02_basic_OBJS); do if [ -f "$$obj" ]; then rm $$obj; fi; done
	@for obj in $(target_02_template_OBJS); do if [ -f "$$obj" ]; then rm $$obj; fi; done
	@for obj in $(target_03_OBJS); do if [ -f "$$obj" ]; then rm $$obj; fi; done
	@for obj in $(target_04_dyn_OBJS); do if [ -f "$$obj" ]; then rm $$obj; fi; done
	@for obj in $(target_04_sta_OBJS); do if [ -f "$$obj" ]; then rm $$obj; fi; done
	@rm -rf $(ELF)