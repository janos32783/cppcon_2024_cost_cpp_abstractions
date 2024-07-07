from util.register import Register

class Peripheral:
    def __init__(self, name : str = "", group : str = "", address : str = ""):
        self.name = name
        self.group = group
        self.address = address
        self.registers = []
    def get_base_address_name (self):
        return self.name + "_BASE_ADDR"
    def parse (self, dictionary: dict):
        self.name = dictionary["name"].upper()
        self.group = dictionary["groupName"].upper()
        base_address = int(dictionary["baseAddress"], 16)
        address_offset = int(dictionary["addressBlock"]["offset"], 16)
        self.address = hex(base_address + address_offset)
        for register_dict in dictionary["registers"]["register"]:
            register = Register()
            register.parse(register_dict)
            self.registers.append(register)
    def to_dict (self) -> dict:
        dictionary = {}
        dictionary["name"] = self.name
        dictionary["group"] = self.group
        dictionary["address"] = self.address
        dictionary["base_address_name"] = self.get_base_address_name()
        dictionary["registers"] = []
        for register in self.registers:
            dictionary["registers"].append(register.to_dict())
        return dictionary