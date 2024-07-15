from util.peripheral import Peripheral

def get_scb (peripherals : list[Peripheral]) -> dict:
    for peripheral in peripherals:
        if "SCB" == peripheral.name:
            return peripheral.to_dict()