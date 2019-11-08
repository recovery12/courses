#!/usr/bin/python3

"""
    Function: Some Function which has five nested loops
    Time complexity is O(n^5)
"""

import time
import numpy as np
import matplotlib.pyplot as plt

def npow5(n):
    for i in range(n):
        for j in range(n):
            for k in range(n):
                for l in range(n):
                    for m in range(n):
                        if i == j:
                            val = i*j
                        elif i == k:
                            val = i*k
                        else:
                            arr = [o for o in range(m*l)]
    return n

def plot(n, time):
    plt.title("Measure of n vs time (O(n^5))")
    plt.xlabel("n")
    plt.ylabel("Time")
    plt.plot(n, time)
    plt.savefig("n_pow_5-vs-t.pdf", bbox_inches="tight")
    plt.show()

if __name__ == '__main__':
    ttaken = dict()

    for i in range(1, 11):
        start = time.time()
        npow5(i)
        end = time.time()
        ttaken[i] = end-start
    print(ttaken)
    plot(list(ttaken.keys()), list(ttaken.values()))
