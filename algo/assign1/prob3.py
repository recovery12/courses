#!/usr/bin/python3

"""
    Function: Bogo sort
    Time complexity is O(n!)
"""

import time
import numpy as np
import matplotlib.pyplot as plt
from itertools import permutations

def is_sorted(n, array):
    for i in range(n-1):
        if array[i] > array[i+1]:
            return False
    return True

def bogo(n, array):
    permut = permutations([i for i in range(n)], n)
    for seq in permut:
        tmp = np.array(array)
        if is_sorted(n, tmp[list(seq)]):
            return tmp[list(seq)]
    return

def plot(n, time):
    plt.title("Measure of n vs time (O(n!))")
    plt.xlabel("n")
    plt.ylabel("Time")
    plt.plot(n, time)
    plt.savefig("n_fact-vs-t.pdf", bbox_inches="tight")
    plt.show()

if __name__ == '__main__':
    ttaken = dict()

    for i in range(1, 11):
        arr = [j for j in range(i,0,-1)]
        start = time.time()
        bogo(i, arr)
        end = time.time()
        ttaken[i] = end-start
    print(ttaken)
    plot(list(ttaken.keys()), list(ttaken.values()))
