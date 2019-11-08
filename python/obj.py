#!/usr/bin/python3

class Anurag:
    x = 0
    name = ""
    def __init__(self, z):
        self.name = z
        print("The name is", self.name)

    def party(self):
        self.x = self.x + 1
        print("So far", self.x)

s = Anurag("chinnu")
s.party()
s.party()
s.party()
