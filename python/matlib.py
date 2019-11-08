#!/usr/bin/python3

import math
import numpy as np
from matplotlib import pyplot as plt
from matplotlib import colors as mc

th = np.linspace(0, 2*np.pi, 128)
fig, ax = plt.subplots(figsize=(3, 3))

ax.plot(th, np.sin(th), 'red', label='C2')
ax.plot(th, np.cos(th), 'yellow', label='C1')
ax.legend()
ax.plt.show()
