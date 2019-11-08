#!/usr/bin/python3

import numpy as np

n = int(input(""))
img = np.array([[0 for i in range(n)] for i in range(n)])

for i in range(n):
    s = input("")
    c = list(map(int, s.split()))
    img[i] = c

count = 0
for i in range(n):
    for j in range(n-1):
        if img[i][j:j+2][0] == 1 and img[i][j:j+2][1] == 1:
            count = count + 1

print(count)

