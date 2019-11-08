
from math import sqrt

t = int(input())

def isprime(num):
    if num%2 == 0 and num != 2:
        return False

    for i in range(3, int(sqrt(num)), 2):
        if num%i == 0:
            return False
    return True

for i in range(t):
    n = int(input())

    if n == 1:
        print(0)
        continue
    elif n == 2:
        print(1)
        continue

    tot = 0
    if n%2 == 0:
        for j in range(2, n//2+1):
            if isprime(j):
                tot = tot + 1
    else:
        for j in range(n, 1, -2):
            if isprime(j):
                tot = tot + 1
    print(tot)
