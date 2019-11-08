
import numpy as np

def f(n):
    return 2*np.log(n)

def g(n):
    return np.log(n) + 5

def iterate():
    for i in range(2000):
        print(i, f(i), g(i))
iterate()
