import json
import random
import sys

num_functions = int(sys.argv[1])
num_calls = int(sys.argv[2])

MAX_REGISTERS = 20
MAX_MODES = 10
MAX_CHOICES = 10
MAX_MASKS = 10
BRANCHING_THRESHOLD = 0.5
STOP_THRESHOLD = 0.3

def include_header (file, headers) :
    file.write("/* includes */\n")
    for header in headers :
        file.write("#include <" + header + ">\n")
    file.write("\n")

def add_enum_class (file, name, prefix, underlying_type, num_enums) :
    file.write("/* enum " + name + " */\n")
    file.write("enum class " + name + " : " + underlying_type + " {\n")
    for i in range(num_enums) :
        file.write("    " + prefix + "_" + str(i) + " = " + str(i))
        if (i == num_enums - 1) :
            file.write("\n")
        else :
            file.write(",\n")
    file.write("};\n")
    file.write("template <" + name + " val> concept is_valid_" + prefix + " = (")
    for i in range(num_enums) :
        file.write("(val == " + name + "::" + prefix + "_" + str(i) + ")")
        if (i < num_enums - 1) :
            file.write(" || ")
    file.write(");\n\n")

def add_enum (file, name, prefix, num_enums) :
    file.write("/* enum " + name + " */\n")
    file.write("typedef enum {\n")
    for i in range(num_enums) :
        file.write("    " + prefix + "_" + str(i) + " = " + str(i))
        if (i == num_enums - 1) :
            file.write("\n")
        else :
            file.write(",\n")
    file.write("} " + name + ";\n")
    file.write("#define IS_" + name + "(X) (")
    for i in range(num_enums) :
        file.write("((X) == " + prefix + "_" + str(i) + ")")
        if (i < num_enums - 1) :
            file.write(" || ")
    file.write(")\n\n")

def define_reg_base_class (file) :
    file.write("template<std::uint32_t address>\n")
    file.write("class Register {\n")
    file.write("private:\n")
    file.write("    void set (std::uint32_t val) const {\n")
    file.write("        *(reinterpret_cast<volatile std::uint32_t *>(&m_memory[address])) = val;\n")
    file.write("    }\n")
    file.write("\n")
    file.write("    std::uint32_t get () const {\n")
    file.write("        return *(reinterpret_cast<volatile std::uint32_t *>(&m_memory[address]));\n")
    file.write("    }\n")
    file.write("protected:\n")
    file.write("    void set (std::uint32_t value, std::uint32_t bitmask) const {\n")
    file.write("        std::uint32_t tmp = this->get();\n")
    file.write("        tmp &= ~bitmask;\n")
    file.write("        tmp |= value;\n")
    file.write("        this->set(tmp);\n")
    file.write("    }\n")
    file.write("};\n\n")

def define_reg_class (file, registers) :
    for i, reg in enumerate(registers) :
        file.write("class Register_" + str(i) + " : public Register<" + str(i) + "> {\n")
        file.write("private:\n")
        file.write("    static consteval std::uint32_t calc_set_bits (modes mode, choices choice) {\n")
        file.write("        return static_cast<std::uint32_t>(mode) << static_cast<std::uint32_t>(choice) * 2;\n")
        file.write("    }\n")
        file.write("    static consteval std::uint32_t calc_clear_bits (modes mode, choices choice) {\n")
        file.write("        return (static_cast<std::uint32_t>(masks::mask_" + str(reg['mask_id']) + ") | static_cast<std::uint32_t>(mode)) << static_cast<std::uint32_t>(choice) * 2;\n")
        file.write("    }\n")
        file.write("public:\n")
        file.write("    template<modes mode, choices choice>\n")
        file.write("    requires (is_valid_choice<choice> && is_valid_mode<mode>)\n")
        file.write("    inline void set_mode () {\n")
        file.write("        set(calc_set_bits(mode, choice), calc_clear_bits(mode, choice));\n")
        file.write("    }\n")
        file.write("};\n\n")

def batch_write (string, files) :
    for file in files :
        file.write(string)

c_main = open("main_" + str(num_functions) + ".c", "w")
base_c = open("base_" + str(num_functions) + ".c", "w")
base_cpp = open("base_" + str(num_functions) + ".cpp", "w")
cpp_main = open("main_" + str(num_functions) + ".cpp", "w")
cpp_encapsulation = open("main_encapsulation_" + str(num_functions) + ".cpp", "w")
cpp_static_poly = open("main_static_poly_" + str(num_functions) + ".cpp", "w")
cpp_dynamic_poly = open("main_dynamic_poly_" + str(num_functions) + ".cpp", "w")

# adding includes

include_header(base_c, [ "stdint.h", "time.h", "stdio.h", "unistd.h" ])
include_header(c_main, [ "stdint.h", "time.h", "stdio.h", "unistd.h" ])

include_header(base_cpp, [ "cstdint", "concepts", "type_traits", "iostream", "unistd.h" ])
include_header(cpp_main, [ "cstdint", "concepts", "type_traits", "iostream", "unistd.h" ])
include_header(cpp_encapsulation, [ "cstdint", "concepts", "type_traits", "iostream", "unistd.h" ])
include_header(cpp_static_poly, [ "cstdint", "concepts", "type_traits", "iostream", "unistd.h" ])
include_header(cpp_dynamic_poly, [ "cstdint", "concepts", "type_traits", "iostream", "unistd.h" ])

# adding modes

num_modes = random.randint(1, MAX_MODES)

add_enum(c_main, "MODE", "MODE", num_modes)
add_enum_class(cpp_main, "modes", "mode", "std::uint32_t", num_modes)
add_enum_class(cpp_encapsulation, "modes", "mode", "std::uint32_t", num_modes)
add_enum_class(cpp_static_poly, "modes", "mode", "std::uint32_t", num_modes)
add_enum_class(cpp_dynamic_poly, "modes", "mode", "std::uint32_t", num_modes)

# adding choices

num_choices = random.randint(1, MAX_CHOICES)

add_enum(c_main, "CHOICE", "CHOICE", num_choices)
add_enum_class(cpp_main, "choices", "choice", "std::uint16_t", num_choices)
add_enum_class(cpp_encapsulation, "choices", "choice", "std::uint16_t", num_choices)
add_enum_class(cpp_static_poly, "choices", "choice", "std::uint16_t", num_choices)
add_enum_class(cpp_dynamic_poly, "choices", "choice", "std::uint16_t", num_choices)

# adding masks

num_masks = random.randint(1, MAX_MASKS)

add_enum(c_main, "MASK", "MASK", num_masks)
add_enum_class(cpp_main, "masks", "mask", "std::uint32_t", num_masks)
add_enum_class(cpp_encapsulation, "masks", "mask", "std::uint32_t", num_masks)
add_enum_class(cpp_static_poly, "masks", "mask", "std::uint32_t", num_masks)
add_enum_class(cpp_dynamic_poly, "masks", "mask", "std::uint32_t", num_masks)

# adding registers

num_registers = random.randint(1, MAX_REGISTERS)

c_main.write("uint32_t m_memory[" + str(num_registers) + "];\n\n")
base_c.write("uint32_t m_memory[" + str(num_registers) + "];\n\n")
cpp_main.write("std::uint32_t m_memory[" + str(num_registers) + "];\n\n")
base_cpp.write("std::uint32_t m_memory[" + str(num_registers) + "];\n\n")
cpp_encapsulation.write("std::uint32_t m_memory[" + str(num_registers) + "];\n\n")
cpp_static_poly.write("std::uint32_t m_memory[" + str(num_registers) + "];\n\n")
cpp_dynamic_poly.write("std::uint32_t m_memory[" + str(num_registers) + "];\n\n")

for i in range(num_registers) :
    c_main.write("#define ELEM_" + str(i) + " (*((volatile uint32_t*)&m_memory[" + str(i) + "]))\n")
    cpp_main.write("#define ELEM_" + str(i) + " (*((volatile uint32_t*)&m_memory[" + str(i) + "]))\n")

define_reg_base_class(cpp_encapsulation)
define_reg_base_class(cpp_static_poly)
define_reg_base_class(cpp_dynamic_poly)

registers = []
for i in range(num_registers) :
    registers.append({
        "mask_id" : random.randint(0, num_masks - 1)
    })


cpp_main.write("static consteval std::uint32_t calc_set_bits (modes mode, choices choice) {\n")
cpp_main.write("    return static_cast<std::uint32_t>(mode) << static_cast<std::uint32_t>(choice) * 2;\n")
cpp_main.write("}\n")

cpp_main.write("static consteval std::uint32_t calc_clear_bits (masks mask, modes mode, choices choice) {\n")
cpp_main.write("    return (static_cast<std::uint32_t>(mask) | static_cast<std::uint32_t>(mode)) << static_cast<std::uint32_t>(choice) * 2;\n")
cpp_main.write("}\n")

define_reg_class(cpp_encapsulation, registers)
define_reg_class(cpp_static_poly, registers)
define_reg_class(cpp_dynamic_poly, registers)

# C structs

c_main.write("typedef struct {\n")
c_main.write("    uint32_t choice ;\n")
c_main.write("    uint32_t mode ;\n")
c_main.write("} A_Struct ;\n")

# static polymorphism
cpp_static_poly.write("template <typename T>\n")
cpp_static_poly.write("concept IPeripheral = requires (T peripheral) {\n")
cpp_static_poly.write("    { peripheral.DoStuff() } -> std::same_as<void>;\n")
cpp_static_poly.write("};\n\n")

cpp_static_poly.write("template <IPeripheral TPeripheral>\n")
cpp_static_poly.write("void HandlePeripheral (TPeripheral& peripheral) {\n")
cpp_static_poly.write("    peripheral.DoStuff();\n")
cpp_static_poly.write("}\n")

# dynamic polymorphism
cpp_dynamic_poly.write("class IPeripheral {\n")
cpp_dynamic_poly.write("public:\n")
cpp_dynamic_poly.write("    virtual ~IPeripheral() { }\n")
cpp_dynamic_poly.write("    virtual void DoStuff () = 0;\n")
cpp_dynamic_poly.write("};\n")

cpp_dynamic_poly.write("void HandlePeripheral (IPeripheral& peripheral) {\n")
cpp_dynamic_poly.write("    peripheral.DoStuff();\n")
cpp_dynamic_poly.write("}\n")

# functions

cpp_class_files = [cpp_encapsulation, cpp_static_poly, cpp_dynamic_poly]

for i in range(num_functions) :
    c_main.write("void DoStuff_" + str(i) + "(A_Struct* m_struct) {\n")
    c_main.write("    uint32_t temp;\n")
    c_main.write("\n")
    c_main.write("    if (!IS_CHOICE(m_struct->choice)) { return; }\n")
    c_main.write("    if (!IS_MODE(m_struct->mode)) { return; }\n")
    c_main.write("\n")

    cpp_main.write("template <choices choice, modes mode>\n")
    cpp_main.write("requires (is_valid_choice<choice> && is_valid_mode<mode>)\n")
    cpp_main.write("void DoStuff_" + str(i) + "() {\n")
    cpp_main.write("    uint32_t temp;\n")
    cpp_main.write("\n")

    batch_write("template <choices choice, modes mode>\n", [cpp_static_poly, cpp_dynamic_poly])
    batch_write("requires (is_valid_choice<choice> && is_valid_mode<mode>)\n", [cpp_static_poly, cpp_dynamic_poly])
    batch_write("class Peripheral_" + str(i) + " {\n", [cpp_encapsulation, cpp_static_poly])
    batch_write("class Peripheral_" + str(i) + " : public IPeripheral {\n", [cpp_dynamic_poly])
    batch_write("public:\n", cpp_class_files)
    batch_write("    template <choices choice, modes mode>\n", [cpp_encapsulation])
    batch_write("    requires (is_valid_choice<choice> && is_valid_mode<mode>)\n", [cpp_encapsulation])
    batch_write("    void DoStuff() {\n", [cpp_encapsulation, cpp_static_poly])
    batch_write("    void DoStuff() override {\n", [cpp_dynamic_poly])
    batch_write("\n", cpp_class_files)

    branching_prob = random.random()
    if branching_prob > BRANCHING_THRESHOLD :
        mode_index = random.randint(0, num_modes - 1)
        reg_index = random.randint(0, num_registers - 1)

        c_main.write("    if (m_struct->mode == MODE_" + str(mode_index) + ") {\n")
        c_main.write("        temp = ELEM_" + str(reg_index) + ";\n")
        c_main.write("        temp &= ~((MASK_" + str(registers[reg_index]['mask_id']) + " | m_struct->mode) << m_struct->choice * 2u);\n")
        c_main.write("        temp |= m_struct->mode << m_struct->choice * 2u;\n")
        c_main.write("        ELEM_" + str(reg_index) + " = temp;\n")

        cpp_main.write("    if constexpr (mode == modes::mode_" + str(mode_index) + ") {\n")
        cpp_main.write("        temp = ELEM_" + str(reg_index) + ";\n")
        cpp_main.write("        temp &= ~calc_clear_bits(masks::mask_" + str(registers[reg_index]['mask_id']) + ", mode, choice);\n")
        cpp_main.write("        temp |= calc_set_bits(mode, choice);\n")
        cpp_main.write("        ELEM_" + str(reg_index) + " = temp;\n")

        batch_write("        if constexpr (mode == modes::mode_" + str(mode_index) + ") {\n", cpp_class_files)
        batch_write("            {\n", cpp_class_files)
        batch_write("                Register_" + str(reg_index) + " reg {};\n", cpp_class_files)
        batch_write("                reg.set_mode<mode, choice>();\n", cpp_class_files)
        batch_write("            }\n", cpp_class_files)

        while (random.random() < STOP_THRESHOLD) :
            mode_index = random.randint(0, num_modes - 1)
            reg_index = random.randint(0, num_registers - 1)
            c_main.write("        temp = ELEM_" + str(reg_index) + ";\n")
            c_main.write("        temp &= ~((MASK_" + str(registers[reg_index]['mask_id']) + " | m_struct->mode) << m_struct->choice * 2u);\n")
            c_main.write("        temp |= m_struct->mode << m_struct->choice * 2u;\n")
            c_main.write("        ELEM_" + str(reg_index) + " = temp;\n")

            cpp_main.write("        temp = ELEM_" + str(reg_index) + ";\n")
            cpp_main.write("        temp &= ~calc_clear_bits(masks::mask_" + str(registers[reg_index]['mask_id']) + ", mode, choice);\n")
            cpp_main.write("        temp |= calc_set_bits(mode, choice);\n")
            cpp_main.write("        ELEM_" + str(reg_index) + " = temp;\n")

            batch_write("            {\n", cpp_class_files)
            batch_write("                Register_" + str(reg_index) + " reg {};\n", cpp_class_files)
            batch_write("                reg.set_mode<mode, choice>();\n", cpp_class_files)
            batch_write("            }\n", cpp_class_files)

        c_main.write("    }\n")
        cpp_main.write("    }\n")
        batch_write("        }\n", cpp_class_files)

    while (random.random() < STOP_THRESHOLD) :
        mode_index = random.randint(0, num_modes - 1)
        reg_index = random.randint(0, num_registers - 1)
        c_main.write("    temp = ELEM_" + str(reg_index) + ";\n")
        c_main.write("    temp &= ~((MASK_" + str(registers[reg_index]['mask_id']) + " | m_struct->mode) << m_struct->choice * 2u);\n")
        c_main.write("    temp |= m_struct->mode << m_struct->choice * 2u;\n")
        c_main.write("    ELEM_" + str(reg_index) + " = temp;\n")

        cpp_main.write("    temp = ELEM_" + str(reg_index) + ";\n")
        cpp_main.write("    temp &= ~calc_clear_bits(masks::mask_" + str(registers[reg_index]['mask_id']) + ", mode, choice);\n")
        cpp_main.write("    temp |= calc_set_bits(mode, choice);\n")
        cpp_main.write("    ELEM_" + str(reg_index) + " = temp;\n")

        batch_write("        {\n", cpp_class_files)
        batch_write("            Register_" + str(reg_index) + " reg {};\n", cpp_class_files)
        batch_write("            reg.set_mode<mode, choice>();\n", cpp_class_files)
        batch_write("        }\n", cpp_class_files)

    c_main.write("}\n")
    cpp_main.write("}\n")
    batch_write("    }\n", cpp_class_files)
    batch_write("};\n", cpp_class_files)


# function calls

all_files = [base_c, c_main, base_cpp, cpp_main, cpp_encapsulation, cpp_static_poly, cpp_dynamic_poly]

batch_write("int main (void) {\n", all_files)
batch_write("    struct timespec start, stop;\n", all_files)
batch_write("    clock_gettime(CLOCK_REALTIME, &start);\n", all_files)
batch_write("    uint64_t elapsed_ns = 0;\n", all_files)

for i in range(num_calls) :
    choice_id = random.randint(0, num_choices - 1)
    mode_id = random.randint(0, num_modes - 1)
    func_id = random.randint(0, num_functions - 1)

    c_main.write("    {\n")
    c_main.write("        A_Struct m_struct;\n")
    c_main.write("        m_struct.choice = CHOICE_" + str(choice_id) + ";\n")
    c_main.write("        m_struct.mode = MODE_" + str(mode_id) + ";\n")
    c_main.write("        DoStuff_" + str(func_id) + "(&m_struct) ;\n")
    c_main.write("    }\n")

    cpp_main.write("    {\n")
    cpp_main.write("        DoStuff_" + str(func_id) + "<choices::choice_" + str(choice_id) + ", modes::mode_" + str(mode_id) + ">();\n")
    cpp_main.write("    }\n")

    cpp_encapsulation.write("    {\n")
    cpp_encapsulation.write("        Peripheral_" + str(func_id) + " peripheral {};\n")
    cpp_encapsulation.write("        peripheral.DoStuff<choices::choice_" + str(choice_id) + ", modes::mode_" + str(mode_id) + ">();\n")
    cpp_encapsulation.write("    }\n")

    cpp_static_poly.write("    {\n")
    cpp_static_poly.write("        Peripheral_" + str(func_id) + "<" + " choices::choice_" + str(choice_id) + ", modes::mode_" + str(mode_id) + "> peripheral {};\n")
    cpp_static_poly.write("        HandlePeripheral<Peripheral_" + str(func_id) + "<choices::choice_" + str(choice_id) + ", modes::mode_" + str(mode_id) + ">> (peripheral);\n")
    cpp_static_poly.write("    }\n")

    cpp_dynamic_poly.write("    {\n")
    cpp_dynamic_poly.write("        Peripheral_" + str(func_id) + "<" + " choices::choice_" + str(choice_id) + ", modes::mode_" + str(mode_id) + "> peripheral {};\n")
    cpp_dynamic_poly.write("        HandlePeripheral (peripheral);\n")
    cpp_dynamic_poly.write("    }\n")

batch_write("    clock_gettime(CLOCK_REALTIME, &stop);\n", all_files)
batch_write("    \n", all_files)
batch_write("    elapsed_ns = (stop.tv_sec - start.tv_sec) * (uint64_t)1e9;\n", all_files)
batch_write("    elapsed_ns += stop.tv_nsec - start.tv_nsec;\n", all_files)
batch_write("    \n", all_files)
batch_write("    printf(\"%lu\\n\", elapsed_ns);\n", all_files)
batch_write("    return 0;\n", all_files)
batch_write("}\n", all_files)


c_main.close()
base_c.close()
cpp_main.close()
cpp_encapsulation.close()
cpp_static_poly.close()
cpp_dynamic_poly.close()
base_cpp.close()