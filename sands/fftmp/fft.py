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
a = fft([np.sin(2*PI*1*i) for i in np.arange(N)])
#recur(a, 0, N)

def w(k, N):
    w = np.exp(complex(0,1)*2*PI*k/N)
    return w

def fft(arr):
    if len(arr) == 1:
        return arr
    else:
        even = fft(arr[0::2])
        odd = fft(arr[1::2])
        tmp = [np.exp(complex(0,1)*2*PI*i/N)*odd[i] for i in range(len(arr))]
        return [even[i]+tmp[i] for i in range(len(arr)//2)]+[even[i]+tmp[i] for i in range(len(arr))]

sol = fft(a)
print(sol)
