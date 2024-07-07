import sys
import os
from os.path import exists
import xmltodict
from util.gpio import process_gpio

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

xml_device = my_dict["device"]
mcu_name = xml_device["name"]
version = xml_device["version"]

print("generating header files for '" + mcu_name + "' version " + version)

cpu = xml_device["cpu"]

print("CPU")
print("    name                  : " + cpu["name"])
print("    revision              : " + cpu["revision"])
print("    endianness            : " + cpu["endian"])
print("    MPU present           : " + cpu["mpuPresent"])
print("    FPU present           : " + cpu["fpuPresent"])
print("    NVIC prio bits        : " + cpu["nvicPrioBits"])
print("    vendor systick config : " + cpu["vendorSystickConfig"])

width = xml_device["width"]
data_prefix = "constexpr"
data_type = "std::uint" + width + "_t"
data_macro = "UINT" + width + "_C"

os.makedirs(os.path.dirname("hal/gpio/constants.hpp"), exist_ok=True)
f = open("hal/gpio/constants.hpp", "w")
f.write(process_gpio(xml_device, data_prefix, data_type, data_macro))
f.close()