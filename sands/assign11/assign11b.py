#!/usr/bin/python3

import numpy as np
import matplotlib.pyplot as plt
from math import pi as PI

N = 16
w = np.exp(complex(0,1)*2*PI/N)

arr = np.array([[w**(-1*i*j) for i in range(N)] for j in range(N)])
arr = np.round(arr, 4)

fh = open("values.txt", "w")
for i in range(N):
    fh.write("\nfor n = "+str(i)+"\n")
    for x in arr[i]:
        fh.write("\t"+str(x)+"\n")
fh.close()
 
arr = arr.reshape(N*N, 1)

plt.xlabel("Real values")
plt.ylabel("Imaginary values")
plt.show(plt.plot(arr.real, arr.imag))
