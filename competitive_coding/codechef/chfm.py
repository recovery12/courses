
import numpy as np
from itertools import permutations

t = int(input())
lt = list()
for i in range(t):
    l = int(input())
    lst = list(map(int, input().split(' ')))
    for j in range(l):
        count = 1
        tmp = lst.copy()
        tmp.remove(lst[j])
        if np.mean(lst) == np.mean(tmp) and len(lst) < 100001:
            print(j)
            count = 0
            break
    if count == 1:
        print("Impossible")

