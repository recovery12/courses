#!/usr/bin/python3

import numpy as np
import pandas as pd
from pandas import Series,DataFrame

def makespan(k, data):
    fdata = [[[0, 0] for i in range(3)] for i in range(k)]

    for i in range(k):
        for j in range(3):
            if i == 0 and j == 0:
                fdata[i][j][0] = 0
            elif i == 0 and j != 0:
                fdata[i][j][0] = fdata[i][j-1][1]
            elif i != 0 and j == 0:
                fdata[i][j][0] = fdata[i-1][j][1]
            else:
                fdata[i][j][0] = max(fdata[i-1][j][1], fdata[i][j-1][1])
            fdata[i][j][1] = fdata[i][j][0] + data[i][j]

    return fdata[k-1][2][1]

k = int(input())
if k not in range(1, 3001):
    quit()

data = list()
for i in range(k):
    data.append(list(map(int, input().split(' '))))
print(makespan(k, data))
