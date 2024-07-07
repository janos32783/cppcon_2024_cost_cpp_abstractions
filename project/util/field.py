class Field:
    def __init__(self, name, offset, width):
        self.name = name
        self.offset = offset
        self.width = width
    def calculate_mask (self):
        mask = "1" * int(self.width)
        after = "0" * int(self.offset)
        before = "0" * (32 - int(self.width) - int(self.offset))
        return "0b" + before + mask + after