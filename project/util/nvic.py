from util.peripheral import Peripheral

def get_nvic (peripherals : list[Peripheral]) -> dict:
    for peripheral in peripherals:
        if "NVIC" == peripheral.name:
            return peripheral.to_dict()