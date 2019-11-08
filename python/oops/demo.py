#!/usr/bin/python3

class c1():
    def __init__(self, who):
        self.name = who

i1 = c1("anurag")
print(i1.name)

# Attributes in the class can be found by (only public)
print(list(name for name in i1.__dict__ if not name.startswith("__")))
