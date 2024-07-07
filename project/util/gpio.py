import copy
import sys
from util.peripheral import Peripheral

def process_gpio (dictionary : dict) -> list[dict]:
    peripherals = []
    for periperal_dict in dictionary["peripherals"]["peripheral"]:
        peripheral_name = periperal_dict["name"].upper()
        if not "GPIO" in peripheral_name:
            continue
        derived_from = periperal_dict.get("@derivedFrom")
        if derived_from is not None:
            derived_from = derived_from.upper()
            found = False
            for p in peripherals:
                if p.name == derived_from:
                    peripheral = copy.deepcopy(p)
                    peripheral.name = peripheral_name
                    peripheral.address = hex(int(periperal_dict["baseAddress"], 16))
                    peripherals.append(peripheral)
                    found = True
                    break
            if not found:
                print(peripheral_name + " is derived from " + derived_from + ", which could not be found")
                sys.exit(1)
        else:
            peripheral = Peripheral()
            peripheral.parse(periperal_dict)
            peripherals.append(peripheral)
    peripherals_dict_list = []
    for peripheral in peripherals:
        peripherals_dict_list.append(peripheral.to_dict())
    return peripherals_dict_list