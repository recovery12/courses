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
sol1 = list()
arr1 = [np.sin(2*PI*0.2*k) for k in range(N)]

for k in range(N//2+1):
    arr = arr1
    for i in range(int(np.log2(N))):
        sol = list()
        for j in range(0, N//2**i, 2):
            sol.append(arr[j]+np.exp(complex(0,1)*2*PI*2**i*k/N)*arr[j+1])
        arr = sol
    sol1.append(arr)
sol1 = sol1 + sol1[-2:0:-1]
print("These are in the bit reversal order.")
print("Output: \n", np.array(sol1))
print("\nOutput by np.fft:\n", np.fft.fft(arr1))

print("These are in the original order.")
sol = list()
recur(np.array(sol, sol1, 0, N))
print(sol)
