import copy
import sys
from util.peripheral import Peripheral

def get_gpios (peripherals : list[Peripheral]) -> dict:
    gpio = {}
    gpio["ports"] = []
    gpio["registers"] = []
    first = True
    for peripheral in peripherals:
        if not "GPIO" in peripheral.name:
            continue
        if len(peripheral.name) != 5:
            print(peripheral.name + " is expected to be 5 characters long")
            sys.exit(1)
        port_name = "port_" + peripheral.name[4:].lower()
        gpio["ports"].append({"name": port_name,
                              "address": peripheral.address,
                              "address_name": peripheral.get_base_address_name()})
        for register in peripheral.registers:
            if first:
                gpio["registers"].append(register.to_dict())
            else:
                reg_dict = register.to_dict()
                if not reg_dict in gpio["registers"]:
                    print(reg_dict + " should already be contained")
                    sys.exit(1)
        first = False
    return gpio