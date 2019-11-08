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

class chinnu(Anurag):
    points = 0
    def touchdown(self):
        self.points = self.points + 1
        self.party()
        print("The score is", self.points)


s = Anurag("chinnu")
s.party()
s.party()
s.party()

j = chinnu("chinnu")
j.touchdown()
