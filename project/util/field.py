class Field:
    def __init__(self, name : str = "", offset : str = "", width : str = ""):
        self.name = name
        self.offset = offset
        self.width = width
    def calculate_mask (self):
        mask = "1" * int(self.width)
        after = "0" * int(self.offset)
        before = "0" * (32 - int(self.width) - int(self.offset))
        return "0b" + before + mask + after
    def parse (self, dictionary: dict):
        self.name = dictionary["name"]
        self.offset = dictionary["bitOffset"]
        self.width = dictionary["bitWidth"]
    def to_dict (self) -> dict:
        return {"name": self.name,
                "offset": self.offset,
                "bitmask": self.calculate_mask()}