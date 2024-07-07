class Peripheral:
    def __init__(self, name, group, address):
        self.name = name
        self.group = group
        self.address = address
        self.registers = []
    def get_base_address_name (self):
        return self.name + "_BASE_ADDR"