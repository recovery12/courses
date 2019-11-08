#!/usr/bin/python3

"""
    Function: Maximum subset problem
    Time complexity is O(2^n)
"""

import time
import numpy as np
import matplotlib.pyplot as plt

def max_subset(m, arr, n):
    for i in range(2**n):
        bits = [0 for i in range(n)]
        act = list(map(int, list(bin(i)[2:])))
        del bits[-len(act):]
        bits.extend(act)
        bits = (np.array(bits) == 1)
        if sum(arr[bits]) == m:
            return True
    return False
    
def plot(n, time):
    plt.title("Measure of n vs time (O(2^n))")
    plt.xlabel("n")
    plt.ylabel("Time")
    plt.plot(n, time)
    plt.savefig("2_pow_n-vs-t.pdf", bbox_inches="tight")
    plt.show()

if __name__ == '__main__':
    ttaken = dict()

    for i in range(1, 21):
        arr = np.array([np.random.randint(4*i) for j in range(i)])
        m = sum(arr)
        start = time.time()
        max_subset(m, arr, i)
        end = time.time()
        ttaken[i] = end-start
    print(ttaken)
    plot(list(ttaken.keys()), list(ttaken.values()))
