#!/usr/bin/python3.6

import copy

class Point():
    """represents a point in 2-D space"""

class Rectangle():
    """represents a rectangle attributes are: height, width, left-corner"""

def print_point(p):
    print('(%g, %g)' % (p.x, p.y))

def find_center(box):
    p = Point()
    p.x = box.lcorner.x + box.width/2
    p.y = box.lcorner.y + box.height/2
    return p

def mov_rect(rect, dx, dy):
    rect.lcorner.x = rect.lcorner.x + dx
    rect.lcorner.y = rect.lcorner.y + dy

def mov_rect1(rect, dx, dy):
    rectn = copy.deepcopy(rect)
    rectn.lcorner.x = rectn.lcorner.x + dx
    rectn.lcorner.y = rectn.lcorner.y + dy

box = Rectangle()
box.lcorner = Point()
box.lcorner.x = int(input("Enter the x co-ordinate of left corner:- "))
box.lcorner.y = int(input("Enter the y co-ordinate of left corner:- "))
box.width = int(input("Enter the width of the rectangle:- "))
box.height = int(input("Enter the height of the rectangle:- "))

center = Point()
center = find_center(box)
print_point(center)
mov_rect(box, 3, 4)
print_point(box.lcorner)
