#!/usr/bin/python3

"""
    Multiple Inheritance
"""
class C2():
    x = 3
    z = 4

class C3():
    w = 5
    z = 3

class C1(C3, C2):
    x = 2
    y = 76

i1 = C1()
print(i1.z)
