#!/usr/bin/ipython3

import numpy as np

pins = np.array([])
check = ("29","35","54","55","65","66")
for i in range(110000, 860000):
    if str(i).startswith(check):
       continue 
    pins = np.append(pins, i)
    print(i)

len(pins)
