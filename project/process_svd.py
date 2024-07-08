import sys
import os
from os.path import exists
import xmltodict
import jinja2
from util.peripherals import process
from util.gpio import get_gpios
from util.rcc import get_rccs

if len(sys.argv) != 2:
    print("SVD filename is required as argument")
    sys.exit(1)

svd_filename = sys.argv[1]
if not exists(svd_filename):
    print("file '" + svd_filename + "' does not exist")
    sys.exit(1)
print("parsing file '" + svd_filename + "'")

with open(svd_filename, 'r', encoding='utf-8') as file:
    my_xml = file.read()

my_dict = xmltodict.parse(my_xml, force_list={'field'})

device_dict = my_dict["device"]
mcu_name = device_dict["name"]
version = device_dict["version"]

print("generating header files for '" + mcu_name + "' version " + version)

cpu = device_dict["cpu"]

print("CPU")
print("    name                  : " + cpu["name"])
print("    revision              : " + cpu["revision"])
print("    endianness            : " + cpu["endian"])
print("    MPU present           : " + cpu["mpuPresent"])
print("    FPU present           : " + cpu["fpuPresent"])
print("    NVIC prio bits        : " + cpu["nvicPrioBits"])
print("    vendor systick config : " + cpu["vendorSystickConfig"])

width = device_dict["width"]
data_prefix = "constexpr"
data_type = "std::uint" + width + "_t"
data_macro = "UINT" + width + "_C"

template_loader = jinja2.FileSystemLoader(searchpath="./")
template_env = jinja2.Environment(loader=template_loader)

# template files
gpio_template = template_env.get_template("hal/gpio/constants.j2")
rcc_template = template_env.get_template("hal/rcc/constants.j2")

# parse the SVD file
peripherals = process(device_dict)
gpios = get_gpios(peripherals)
rccs = get_rccs(peripherals)

outputText = gpio_template.render(data_prefix=data_prefix,
                                  data_type=data_type,
                                  data_macro=data_macro,
                                  gpios=gpios)
with open(r'hal/gpio/constants.hpp', 'w') as fp:
    fp.write(outputText)

outputText = rcc_template.render(data_prefix=data_prefix,
                                 data_type=data_type,
                                 data_macro=data_macro,
                                 rccs=rccs)
with open(r'hal/rcc/constants.hpp', 'w') as fp:
    fp.write(outputText)