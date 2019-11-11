#!/usr/bin/python3

import numpy as np
import matplotlib.pyplot as plt

def input_data(n):
    x = list()
    y = list()
    for i in range(n):
        x.append(float(input("Enter x: ")))
        y.append(float(input("Enter y: ")))
    return x, y

if __name__ == "__main__":
    N = 160
    n = int(input("Enter n: "))
    x, y = input_data(n)

    plt.xlabel("No of Frames(F)")
    plt.xlim(0, N)
    plt.ylabel("Slow Down")
    plt.ylim(min(arr)-0.5, max(arr)+0.5)
    plt.suptitle("Variation of slow-down with No of Frames(F)", fontsize=15)
    plt.title("Process 1")
    plt.plot(x, y)
    plt.savefig("frames-p1.png", bbox_inches="tight")
    plt.show()
