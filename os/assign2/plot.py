#!/usr/bin/python3

import numpy as np
import matplotlib.pyplot as plt

def input_data(n):
    arr = list()
    for i in range(n):
        arr.append(float(input("Enter value: ")))
    return arr

if __name__ == "__main__":
    n = int(input("Enter n: "))
    arr = input_data(n)

    plt.xlabel("Sigma (process behaviour)")
    plt.xlim(0.5, n+0.5)
    plt.ylabel("Page Faults")
    plt.ylim(min(arr)-0.5, max(arr)+0.5)
    plt.suptitle("Variation of slow-down with sigma(Global)", fontsize=15)
    plt.title("Frames = 3N/4")
    plt.plot(range(1, n+1), arr)
    plt.savefig("sigma-global.png", bbox_inches="tight")
    plt.show()
