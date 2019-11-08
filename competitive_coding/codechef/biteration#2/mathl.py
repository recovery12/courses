
import math
from math import log

t = int(input())

for i in range(t):
    n = int(input())

    tot = 0
    mod = 10**9+7
    for j in range(2, n+1):
        tot = tot + log(j**(n-j+1)%(mod))
    print(math.exp(tot))
