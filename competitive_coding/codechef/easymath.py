#!/usr/bin/python3

t = int(input())

def num_prod(n):
    p = 0
    while n != 0:
        p = p + n%10
        n = int(n/10)
    return p

for k in range(t):
    n = int(input())
    arr = list(map(int, input().split(" ")))

    p = list()
    for i in range(n):
        for j in range(i+1, n):
            p.append(num_prod(arr[i]*arr[j]))
    print(max(p))
