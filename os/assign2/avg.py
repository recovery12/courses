#!/usr/bin/python3

n = int(input("n = "))
l = list()
for i in range(n):
    l.append(float(input()))

avg = sum(l)/n
print(avg)
