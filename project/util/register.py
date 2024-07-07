class Register:
    def __init__(self, name, offset, description):
        self.name = name
        self.offset = offset
        self.description = description
        self.fields = []