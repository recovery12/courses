#!/usr/bin/python3

N, k = tuple(map(int, input().split(" ")))

arr = list(map(int, input().split(" ")))

tot = 0
k = k-1
ks = k
while k != N-1:
    if arr[k+1] < 0:
       tot = tot + arr[k]
       k = k + 2
    else:
       tot = tot + arr[k]
       k = k + 1

k = N-1
while k != 0:
    if arr[k-1] < 0:
        tot = tot + arr[k]
        k = k - 2
    else:
        tot = tot + arr[k]
        k = k - 1

tot = tot - arr[ks]
print(tot+arr[0])
