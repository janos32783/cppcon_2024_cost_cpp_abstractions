import jinja2
import random
import sys

MAX_FUNCTIONS = int(sys.argv[1])

MAX_REGISTERS = 100
MAX_CALLS = 10
MAX_CONSTANTS = 100
MAX_ENUMS = 30
MAX_ENUM_VALUES = 10
MAX_STRUCTS = 20
MAX_STRUCT_MEMBERS = 10
MAX_IFS = 4
MAX_REG_MAN = 5

template_loader = jinja2.FileSystemLoader(searchpath="./")
template_env = jinja2.Environment(loader=template_loader)

# template files
inefficiencies_template = template_env.get_template("templates/01_inefficiencies.j2")

# constants
constants = []
num_constants = random.randint(1, MAX_CONSTANTS)
for i in range(num_constants) :
    const_name = "CONST_" + str(i)
    const_val = hex(i) + "UL"
    constants.append({
        "name" : const_name,
        "value" : const_val
    })

# registers
registers = []
#num_registers = random.randint(1, MAX_REGISTERS)
num_registers = MAX_REGISTERS
for i in range(num_registers) :
    reg_name = "REG_" + str(i)
    reg_addr = hex(0x48000000 + (4 * i)) + "UL"
    mask_name = constants[random.randint(0, len(constants) - 1)]["name"]
    mask_mul = random.randint(0, 4)
    registers.append({
        "name" : reg_name,
        "address" : reg_addr,
        "mask_name" : mask_name,
        "mask_mul" : mask_mul
    })

types = []
types.append("uint8_t")
types.append("uint16_t")
types.append("uint32_t")
types.append("int")

# enums
enums = []
#num_enums = random.randint(1, MAX_ENUMS)
num_enums = MAX_ENUMS
for i in range(num_enums) :
    enum_name = "ENUM_" + str(i)
    types.append(enum_name)
    enum = {"name" : enum_name, "values" : []}
    #num_enumvalues = random.randint(1, MAX_ENUM_VALUES)
    num_enumvalues = MAX_ENUM_VALUES
    for e in range(num_enumvalues) :
        enum_val_name = enum_name + "_VAL_" + str(e)
        enum_val_val = hex(e) + "UL"
        enum["values"].append({"name" : enum_val_name, "value" : enum_val_val})
    enums.append(enum)

# structs
structs = []
#num_structs = random.randint(1, MAX_STRUCTS)
num_structs = MAX_STRUCTS
for i in range(num_structs) :
    struct_name = "ST_" + str(i)
    struct = {"name" : struct_name, "members" : []}
    #num_members = random.randint(1, MAX_STRUCT_MEMBERS)
    num_members = MAX_STRUCT_MEMBERS
    for e in range(num_members) :
        member_name = struct_name + "_member_" + str(e)
        type_id = random.randint(0, len(types) - 1)
        member_type = types[type_id]
        init = str(random.randint(0, 100))
        for enum in enums :
            if enum["name"] == member_type:
                init = enum["values"][random.randint(0, len(enum["values"]) - 1)]["name"]
        struct["members"].append({"name" : member_name, "type" : member_type, "init" : init})
    structs.append(struct)

# functions
funcs = []
#num_funcs = random.randint(1, MAX_FUNCTIONS)
num_funcs = MAX_FUNCTIONS
for i in range(num_funcs) :
    func_name = "hal_func_" + str(i)
    func_param = structs[random.randint(0, len(structs) - 1)]
    func = {"name" : func_name, "param" : func_param, "ifs" : []}
    #num_ifs = random.randint(1, MAX_IFS)
    num_ifs = MAX_IFS
    for e in range(num_ifs) :
        cond_var = func_param["members"][random.randint(0, len(func_param["members"]) - 1)]
        for enum in enums :
            if enum["name"] == cond_var["type"]:
                cond_val = enum["values"][random.randint(0, len(enum["values"]) - 1)]
                value = func_param["members"][random.randint(0, len(func_param["members"]) - 1)]
                shift = func_param["members"][random.randint(0, len(func_param["members"]) - 1)]
                if_block = {"cond_var" : cond_var, "cond_val" : cond_val, "value" : value, "shift" : shift, "registers" : []}
                num_reg_man = random.randint(1, MAX_REG_MAN)
                for j in range(num_reg_man) :
                    if_block["registers"].append(registers[random.randint(0, len(registers) - 1)])
                func["ifs"].append(if_block)
    funcs.append(func)

# calls
calls = []
#num_calls = random.randint(1, MAX_CALLS)
num_calls = MAX_CALLS
for i in range(num_calls) :
    func = funcs[random.randint(0, len(funcs) - 1)]
    func_param = structs[random.randint(0, len(structs) - 1)]
    call = {"func" : func, "param" : func_param}
    calls.append(call)

outputText = inefficiencies_template.render(registers=registers, constants=constants, enums=enums, structs=structs, funcs=funcs, calls=calls)
with open(r'build/01_main_c.c', 'w') as fp:
    fp.write(outputText)
with open(r'build/01_main_cpp.cpp', 'w') as fp:
    fp.write(outputText)

with open("01_data_c.csv", "a") as myfile:
    myfile.write(str(num_funcs) + ",")
with open("01_data_cpp.csv", "a") as myfile:
    myfile.write(str(num_funcs) + ",")