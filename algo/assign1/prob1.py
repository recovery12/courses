#!/usr/bin/python3

"""
    Function: Linear Search
    Time complexity is O(n)
"""

import time
import numpy as np
import matplotlib.pyplot as plt

def linsearch(n, array, num):
    for i in range(n):
        if array[i] == num:
            return i+1
    return -1

def plot(n, time):
    plt.title("Measure of n vs time (O(n))")
    plt.xlabel("n")
    plt.ylabel("Time")
    plt.plot(n, time)
    plt.savefig("n-vs-t.pdf", bbox_inches='tight')
    plt.show()

if __name__ == '__main__':
    ttaken = dict()

    for i in range(1, 10001):
        arr = [j for j in range(i)]
        start = time.time()
        linsearch(i, arr, i-1)
        end = time.time()
        ttaken[i] = end-start
    print(ttaken)
    plot(list(ttaken.keys()), list(ttaken.values()))
