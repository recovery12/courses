#!/usr/bin/python3.6

import math

class Point(object):
    def __init__(self, x, y):
        self.x = x
        self.y = y
    def __str__(self):
        return '(%g, %g)' % (self.x, self.y)
    def add_point(self, other):
        new_point = Point(0, 0)
        new_point.x = self.x + other.x
        new_point.y = self.y + other.y
        return new_point
    def add_tuple(self, other):
        new_point = Point(0, 0)
        for (x, y) in other:
            new_point.x = self.x + x
            new_point.y = self.y + y
        return new_point
    def __add__(self, other):
        if isinstance(other):
            return self.add_point(other)
x1 = int(input("Enter the co-ordinates of x1:- "))
y1 = int(input("Enter the co-ordinates of y1:- "))
x2 = int(input("Enter the co-ordinates of x2:- "))
y2 = int(input("Enter the co-ordinates of y2:- "))

point1 = Point(x1, y1)
point2 = Point(x2, y2)
print(point2)

tup = tuple()
tup = (5, 5)

distance = math.sqrt((point1.x-point2.x)**2 + (point1.y-point2.y)**2)
print("Distance is ", distance)
point3 = Point(0, 0)
point3 = Point.add_tuple(point1, tup)
print(point3)
