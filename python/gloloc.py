#!/usr/bin/python3

import numpy as np

global g
g = 3

def sample():
    global g1
    g1 = 4
    for i in range(45):
        if i == 19:
            print(locals())

print(globals())
sample()
print(globals())
