#!/usr/bin/python3

num = int(input())

if num == 1:
    print("Yes")
    quit()

for i in range(2, num):
    y = 1
    c = 0
    if num%i == 0:
        while num != 1:
            if num%i == 0:
                num = num//i
                y = y + 1
            else:
                break
    if y > 1 and num == 1:
        c = 1
        break
if c == 1:
    print("Yes")
else:
    print("No")
