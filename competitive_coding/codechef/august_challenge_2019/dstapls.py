#!/usr/bin/python3

t = int(input())

def ispow(n, k):
    n1 = n
    chk = 0
    while n1%k == 0:
        if n1 == k and chk == 1:
            break
        n1 = int(n1/k)
        chk = 1

    if n1 == k:
        return True
    else:
        return False

for i in range(t):
    n, k = tuple(map(int, input().split(" ")))

    if k == 1 or n%(k*k) == 0:
        print("NO")
    else:
        print("YES")
