from util.peripheral import Peripheral

def get_flash (peripherals : list[Peripheral]) -> dict:
    for peripheral in peripherals:
        if "FLASH" == peripheral.name:
            return peripheral.to_dict()