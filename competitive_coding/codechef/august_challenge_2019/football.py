#!/usr/bin/python3

t = int(input())

for k in range(t):
    n = int(input())

    goals = list(map(int, input().split(" ")))
    fouls = list(map(int, input().split(" ")))

    maxi = 0
    for i in range(n):
        point = 20*goals[i] - 10*fouls[i]
        if maxi < point:
            maxi = point
    print(maxi)
