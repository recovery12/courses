#!/usr/bin/python3

import numpy as np
from math import pi as PI

def recur(sol, a, s, e):
    if e-s == 1:
        sol.append(a[0])
    else:
        m = (s+e)//2
        recur(sol, a[0::2], s, m)
        recur(sol, a[1::2], m, e)

N = 16
sol = list()
arr1 = [i for i in range(N)]
recur(sol, arr1, 0, N)
print("Original array: ", arr1)
print("Bit reversal: ", sol)

sol = list()
arr2 = [0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15]
recur(sol, arr2, 0, N)
print("Original array: ", arr2)
print("Bit reversal: ", sol)
