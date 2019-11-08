#!/usr/bin/python3

"""
    assert is used to say whether the action method is implemented in subclass
or not.

    raise gives an Exception
"""

from person import Person

class Abstract1():
    def method1(self):
        self.action()
    def action(self):
        assert False, 'action not implemented!'

class Abstract2():
    def method1(self):
        self.action()
    def action(self):
        raise NotImplementedError('action not implemented')

"""class Abstract3(metaclass=Person):
    def method1(self):
        self.action()
    @abstract
    def action(self):
        pass"""

try:
    x = Abstract2()
    x.method1()
except:
    print("Nothing")

# x = Abstract3()
class Subclass(Abstract1):
    def action(self):
        print("spam")

x = Subclass()
x.method1()
