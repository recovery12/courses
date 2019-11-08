#!/usr/bin/python3

import numpy as np
import matplotlib.pyplot as plt
from math import pi as PI

N = 16
f = 0.2
j = complex(0,1)
w = np.exp(j*2*PI/N)
W = np.array([[w**(n*k) for k in range(N)] for n in range(N)])
x = np.array([np.cos(2*PI*f*k)+j*np.sin(2*PI*f*k) for k in range(N)])

sol = np.linalg.multi_dot((W,x))

plt.xlabel("Real part")
plt.ylabel("Imag part")
plt.show(plt.plot(sol.real, sol.imag))

plt.xlabel("k where k in [0,15]")
plt.ylabel("|a+ib|")
plt.show(plt.plot(np.arange(N), np.abs(sol)))
plt.xlabel("k where k in [0,15]")
plt.ylabel("Real part")
plt.show(plt.plot(np.arange(N), sol.real))
plt.xlabel("k where k in [0,15]")
plt.ylabel("Imag part")
plt.show(plt.plot(np.arange(N), sol.imag))
