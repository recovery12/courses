#!/usr/bin/python3

import numpy as np

ccno = np.array([])

for i in range(10**4):
    tmp = []
    for j in range(16):
        if j == 0:
            tmp.append(str(np.random.randint(1,9)))
        else:
            tmp.append(str(np.random.randint(9)))
    ccno = np.append(ccno, "".join(tmp))

print(len(ccno))
