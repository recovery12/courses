#!/usr/bin/python3

t = int(input())

for i in range(t):
    n = int(input())
    l = list(set(map(int, input().split())))
    l.sort()
    print(l[1]-l[0])
