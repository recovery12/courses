#!/usr/bin/python3

t = int(input())

def strict_inc(arr):
    ind = list()
    for i in range(len(arr)-1):
        if arr[i] >= arr[i+1]:
            ind.append(i)
    return ind

for k in range(t):
    n = int(input())
    arr = list(map(int, input().split(" ")))

    ind = strict_inc(arr)
    tmp = arr.copy()
    a = tmp[-1]-tmp[0]
    l = len(arr)-a
    tot = l*(l+1)/2
    tot = tot + (len(arr[:ind[0]])-1)
    print(tot)
    
