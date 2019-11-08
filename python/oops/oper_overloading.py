#!/usr/bin/python3

class Person():
    def __init__(self, name, age, place=None):
        self.name = name
        self.age = age
        self.place = place
    def __add__(self, obj):
        return Person(self.name, self.age + obj.age)
    #def __repr__(self):
    #    return "(Name: %s, Age: %s)"% (self.name, self.age)
    def __str__(self):
        return "[%s %s]"% (self.name, self.age)

p1 = Person("xyz", 21)
p2 = Person("yzx", 32, "asdf")

p3 = p1 + p2
print(p3)
