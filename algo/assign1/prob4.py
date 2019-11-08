#!/usr/bin/python3

"""
    Function: Bubble sort
    Time complexity is O(n^2)
"""

import time
import numpy as np
import matplotlib.pyplot as plt

def bubble(n, array):
    for i in range(n):
        for j in range(n-i-1):
            if array[j] > array[j+1]:
                array[j], array[j+1] = array[j+1], array[j]
    return n

def plot(n, time):
    plt.title("Measure of n vs time (O(n^2))")
    plt.xlabel("n")
    plt.ylabel("Time")
    plt.plot(n, time)
    plt.savefig("n_squ-vs-t.pdf", bbox_inches="tight")
    plt.show()

if __name__ == '__main__':
    ttaken = dict()

    for i in range(1, 1001):
        arr = [j for j in range(i, 0, -1)]
        start = time.time()
        bubble(i, arr)
        end = time.time()
        ttaken[i] = end-start
    print(ttaken)
    plot(list(ttaken.keys()), list(ttaken.values()))
