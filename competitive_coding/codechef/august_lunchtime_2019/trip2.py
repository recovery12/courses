#!/usr/bin/python3

t = int(input())

for i in range(t):
    n, k = map(int, input().split())
    days = list(map(int, input().split()))

    if len(days) < k:
        for j in range(len(days)-1):
            if days[j] == days[j+1]:
                print("NO")
                val = True
                break
        if val:
            continue
        else:
            print("YES")
            for p in days:
                print(p, end=" ")
