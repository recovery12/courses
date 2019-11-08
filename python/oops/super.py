#!/usr/bin/python3

class ClassA():
    def __init__(self, name, age=None):
        self.name = name
        self.age = age
    def __str__():
        return str(name)

class ClassB(ClassA):
    def callFunct(self):
        print(super(type))

demo = ClassB("Anurag", 21)
demo.callFunct()
