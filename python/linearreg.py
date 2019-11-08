#!/usr/bin/python3

import numpy as np
from matplotlib import pyplot as plt
from matplotlib import colors as mc

class point(object):
    def __init__(self):
        self.x = 0
        self.y = 0
    def __str__(self):
        return '%g, %g' % (self.x, self.y)

def input_data(listx, listy):
    n = 0
    while True:
        x = input("Enter the value of x: ")
        y = input("Enter the value of y: ")

        if x == 'done' and y == 'done':
            return n
        listx.append(float(x))
        listy.append(float(y))
        n = n + 1

x_vals = list()
y_vals = list()
n = input_data(x_vals, y_vals)

for i in range(n):
    plt.scatter(x_vals[i], y_vals[i])
plt.show()
