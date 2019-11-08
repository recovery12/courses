#!/usr/bin/python3

t = int(input())

for i in range(t):
    lst = list(map(int, input().split()))

    age = [lst[0], lst[1], lst[2]]
    mny = [lst[3], lst[4], lst[5]]

    val = True
    s = sorted(zip(age, mny))
    for i in range(2):
        if s[i][0] < s[i+1][0]:
            if s[i][1] < s[i+1][1]:
                val = True
            else:
                val = False
                break
        elif s[i][0] == s[i+1][0]:
            if s[i][1] == s[i+1][1]:
                val = True
            else:
                val = False
                break
    if val:
        print("FAIR")
    else:
        print("NOT FAIR")
