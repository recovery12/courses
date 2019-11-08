#!/usr/bin/python3

t = int(input())

for i in range(t):
    q, p = map(int, input().split())

    if q <= 1000:
        print(format(q*p, ".6f"))
    else:
        print(format(0.9*q*p, ".6f"))
