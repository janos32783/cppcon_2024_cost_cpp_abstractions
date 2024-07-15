from util.peripheral import Peripheral

def get_systick (peripherals : list[Peripheral]) -> dict:
    for peripheral in peripherals:
        if "STK" == peripheral.name:
            return peripheral.to_dict()