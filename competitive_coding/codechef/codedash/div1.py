
t = int(input())

from math import sqrt

def isprime(n):
    if n%2 == 0 and n != 2:
        return False

    for i in range(3, int(sqrt(n))+1):
        if n%i == 0:
            return False
    return True

for i in range(t):
    num = 1
    n = int(input())
    tmp = n
    tmp1 = n
    if n > 10**6:
        n = 10**6

    for j in range(2, n+1):
        tmp = tmp1
        if tmp%j == 0:
            while tmp%j == 0:
                print(num, j)
                num = num ^ j
                tmp = int(tmp//j)
    print(num)
