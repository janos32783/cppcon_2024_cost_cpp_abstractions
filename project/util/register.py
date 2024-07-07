from util.field import Field
import re

class Register:
    def __init__(self, name : str = "", offset : str = "", description : str = ""):
        self.name = name
        self.offset = offset
        self.description = description
        self.fields = []
    def parse (self, dictionary: dict):
        self.name = dictionary["name"].upper()
        self.offset = dictionary["addressOffset"]
        self.description = dictionary["description"]
        self.description = self.description.replace("\r\n", "")
        self.description = self.description.replace("\n", "")
        self.description = re.sub(' +', ' ', self.description)
        for flied_dict in dictionary["fields"]["field"]:
            field = Field()
            field.parse(flied_dict)
            self.fields.append(field)
    def to_dict (self) -> dict:
        dictionary = {}
        dictionary["name"] = self.name
        dictionary["offset"] = self.offset
        dictionary["description"] = self.description
        dictionary["fields"] = []
        for field in self.fields:
            dictionary["fields"].append(field.to_dict())
        return dictionary