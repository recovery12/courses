#!/usr/bin/python3

"""
    Function: Binary Search
    Time complexity is O(log(n))
"""

import time
import numpy as np
import matplotlib.pyplot as plt

def binsearch_a(n, array, num):
    i = 0
    j = n-1

    while i < j:
        m = int((i+j)/2)
        if array[m] > num:
            j = m+1
        elif array[m] < num:
            i = m
        else:
            return m+1
    return -1

def plot(n, time):
    plt.title("Measure of n vs time (O(log(n)))")
    plt.xlabel("n")
    plt.ylabel("Time")
    plt.plot(n, time)
    plt.savefig("logn-vs-t.pdf", bbox_inches="tight")
    plt.show()

if __name__ == '__main__':
    ttaken = dict()

    for i in range(4, 10001):
        arr = [j for j in range(i)]
        start = time.time()
        print(binsearch_a(i, arr, int(i/4)))
        end = time.time()
        ttaken[i] = end-start
    print(ttaken)
    plot(list(ttaken.keys()), list(ttaken.values()))
