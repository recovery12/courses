#!/usr/bin/python3

import numpy as np
import matplotlib.pyplot as plt
from math import pi as PI

w = np.exp(complex(0,1)*2*PI/16)


for i in range(16):
    fig = plt.figure()
    plt.suptitle("Plot of k vs w**-("+str(i)+"*k)", fontsize=16)
    #plt.title("w = exp(j*(2pi)/N), 0 < k < 16", fontsize=10)
    x = np.array([w**(-i*k) for k in range(16)])
    plt.subplot(2,1,1)
    plt.ylabel("Real(w**-("+str(i)+"k))")
    plt.plot(range(16), x.real)
    plt.subplot(2,1,2)
    plt.xlabel("k")
    plt.ylabel("Imag(w**-("+str(i)+"k))")
    plt.plot(range(16), x.imag)
    num = str(i)
    fig.savefig("fig"+num+".jpeg")
    
