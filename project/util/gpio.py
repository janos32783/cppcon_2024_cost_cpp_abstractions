import re
import copy
from util.peripheral import Peripheral
from util.register import Register
from util.field import Field

peripherals = []

def process_gpio (xml_device, data_prefix, data_type, data_macro):
    for xml_peripheral in xml_device["peripherals"]["peripheral"]:
        peripheral_name = xml_peripheral["name"].upper()
        if not "GPIO" in peripheral_name:
            continue
        base_address = int(xml_peripheral["baseAddress"], 16)
        derived_from = xml_peripheral.get("@derivedFrom")
        if derived_from is not None:
            derived_from = derived_from.upper()
            found = False
            for p in peripherals:
                if p.name == derived_from:
                    peripheral = copy.deepcopy(p)
                    peripheral.name = peripheral_name
                    peripheral.address = hex(base_address)
                    peripherals.append(peripheral)
                    found = True
                    break
            if not found:
                print(peripheral_name + " is derived from " + derived_from + ", which could not be found")
        else:
            group_name = xml_peripheral["groupName"].upper()
            address_offset = int(xml_peripheral["addressBlock"]["offset"], 16)
            #address_size = xml_peripheral["addressBlock"]["size"]
            peripheral_address = hex(base_address + address_offset)

            peripheral = Peripheral(peripheral_name, group_name, peripheral_address)

            for xml_register in xml_peripheral["registers"]["register"]:
                reg_name = xml_register["name"].upper()
                reg_offset = xml_register["addressOffset"]
                reg_desc = xml_register["description"]
                reg_desc = reg_desc.replace("\r\n", "")
                reg_desc = reg_desc.replace("\n", "")
                reg_desc = re.sub(' +', ' ', reg_desc)
                register = Register(reg_name, reg_offset, reg_desc)
                for xml_flied in xml_register["fields"]["field"]:
                    field_name = xml_flied["name"]
                    field_offset = xml_flied["bitOffset"]
                    field_width = xml_flied["bitWidth"]
                    field = Field(field_name, field_offset, field_width)
                    register.fields.append(field)
                peripheral.registers.append(register)
            peripherals.append(peripheral)

    text = "#pragma once\n"
    text += "\n"
    text += "#include <cstdint>\n"
    text += "#include <concepts>\n"
    text += "#include \"hal/register.hpp\"\n"
    text += "\n"
    text += "namespace hal {\n"
    text += "\n"
    text += "// GPIO register base addresses\n"
    for peripheral in peripherals:
        text += data_prefix + " "
        text += data_type + " "
        text += peripheral.get_base_address_name()
        text += " = " + data_macro + "(" + peripheral.address + ");\n"
    text += "\n"
    text += "template <" + data_type + " GPIOx_BASE_ADDR>\n"
    text += "concept is_valid_gpio_base_address = (\n"
    for i in range(len(peripherals)):
        text += "    (GPIOx_BASE_ADDR == " + peripherals[i].get_base_address_name() + ")"
        if i < len(peripherals) - 1:
            text += " ||"
        text += "\n"
    text += ");\n"
    text += "\n"
    text += "enum class gpio_ports : std::uint8_t {\n"
    for i in range(len(peripherals)):
        text += "    " + peripherals[i].name.lower()
        if i < len(peripherals) - 1:
            text += ","
        text += "\n"
    text += "};\n"
    text += "\n"
    text += "template <gpio_ports port>\n"
    text += "concept is_valid_gpio_port = (\n"
    for i in range(len(peripherals)):
        text += "    (port == gpio_ports::" + peripherals[i].name.lower() + ")"
        if i < len(peripherals) - 1:
            text += " ||"
        text += "\n"
    text += ");\n"
    text += "\n"
    text += "enum class gpio_pins : std::uint8_t {\n"
    text += "    pin_00 = 0,\n"
    text += "    pin_01 = 1,\n"
    text += "    pin_02 = 2,\n"
    text += "    pin_03 = 3,\n"
    text += "    pin_04 = 4,\n"
    text += "    pin_05 = 5,\n"
    text += "    pin_06 = 6,\n"
    text += "    pin_07 = 7,\n"
    text += "    pin_08 = 8,\n"
    text += "    pin_09 = 9,\n"
    text += "    pin_10 = 10,\n"
    text += "    pin_11 = 11,\n"
    text += "    pin_12 = 12,\n"
    text += "    pin_13 = 13,\n"
    text += "    pin_14 = 14,\n"
    text += "    pin_15 = 15\n"
    text += "};\n"
    text += "\n"
    for peripheral in peripherals:
        for register in peripheral.registers:
            text += "// " + register.description + "\n"
            for field in register.fields:
                text += data_prefix + " "
                text += data_type + " "
                text += peripheral.name + "_"
                text += register.name + "_"
                text += field.name + "_msk = "
                text += data_macro + "(" + field.calculate_mask() + ");\n"

                text += data_prefix + " "
                text += data_type + " "
                text += peripheral.name + "_"
                text += register.name + "_"
                text += field.name + "_pos = "
                text += data_macro + "(" + field.offset + ");\n"
    text += "\n"
    text += "} /* namespace hal */\n"
    return text

    text += "\n"
    text += "template <gpio_ports port>\n"
    text += "requires (is_valid_gpio_port<port>)\n"
    text += "consteval std::uint32_t port_to_base_address () {\n"
    text += "    if (port == gpio_ports::port_a) return GPIOA_BASE_ADDR;\n"
    text += "    else if (port == gpio_ports::port_b) return GPIOB_BASE_ADDR;\n"
    text += "    else if (port == gpio_ports::port_c) return GPIOC_BASE_ADDR;\n"
    text += "    else if (port == gpio_ports::port_d) return GPIOD_BASE_ADDR;\n"
    text += "    else return GPIOF_BASE_ADDR;\n"
    text += "}\n"