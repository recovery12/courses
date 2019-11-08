#!/usr/bin/python3

class C2:
    def setvalue(self, value):
        self.data = value
    def display(self):
        print(self.data)

class C3(C2):
    def __init__(self, value):
        self.data = value
    def __add__(self, other):
        return C3(self.data + other)
    def __str__(self):
        return "String format is:: %s"% self.data

x = C3("anurag")
x.display()
y = x + " peddi"
print(y)
