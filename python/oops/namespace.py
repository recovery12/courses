#!/usr/bin/python3

x = 11

def demo():
    print(x)    # prints 11

def demo1():
    x = 22
    print(x)    # prints 22 hides 11

class names():
    x = 33
    def meth(self):
        x = 44
        self.x = names.x
        print(x, self.x)

s = names()
s.meth()
# print(names.meth.x) # only visible in method
