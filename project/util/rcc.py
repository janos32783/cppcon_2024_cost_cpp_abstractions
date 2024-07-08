import copy
import sys
from util.peripheral import Peripheral

def get_rccs (peripherals : list[Peripheral]) -> list[dict]:
    rccs = []
    for peripheral in peripherals:
        if not "RCC" in peripheral.name:
            continue
        rccs.append(peripheral.to_dict())
    return rccs