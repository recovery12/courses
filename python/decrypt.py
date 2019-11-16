#!/usr/bin/python3

from itertools import combinations

def isprime(n):
    if n%2 == 0:
        return False
    for i in range(3, n, 2):
        if n%i == 0:
            return False
    return True

def getprimes(low, high):
    primes = list()

    for p in range(low, high+1):
        if isprime(p):
            primes.append(p)
    return primes


def apupto(intm, limit):
    aps = list()

    for i in range(1, 7):
        a = intm[i]
        tmpl = list()
        while a in range(limit):
            tmpl.append(a)
            a = a+82
        aps.append(tmpl)
    return aps

cipher = "II!26!32%!1I%!32%A!32"
primes = getprimes(3, 11083)
m = "73 73 34 54 36 50 37 33 73 37 36 50 37 65 33 50"
mint = list(map(int, m.split()))

aps = apupto(mint, 11083)
print(aps)
