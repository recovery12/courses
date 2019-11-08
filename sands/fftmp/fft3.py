#!/usr/bin/python3

import numpy as np
from math import pi as PI
from scipy import fft, ifft

def recur(a, s, e):
    if e-s == 1:
        print(a)
    else:
        m = (s+e)//2
        recur(a[0::2], s, m)
        recur(a[1::2], m, e)

N = 16
a = [np.sin(2*PI*0.2*i) for i in np.arange(N)]
print(fft([np.sin(2*PI*0.2*i) for i in np.arange(N)]))
nmax = 2
while N > nmax:
    istep = nmax * 2
    theta = 2*PI/nmax
    tmp = -2*np.sin(0.5*theta)**2+complex(0,1)*np.sin(theta)
    w = complex(0,1)

    for m in range(0, nmax, 2):
        for i in range(m, int(N/2), istep):
            j = int(i/2) + nmax
            tmp1 = a[j]*w
            x = a[i].real - tmp1.real
            y = a[i].imag - tmp1.imag
            a[j] = complex(x,y)
            x = a[i].real + w.real
            y = a[i].imag + w.imag
            a[i] = complex(x, y)
        w = w*tmp + w
    nmax = istep
print(np.array(a))
