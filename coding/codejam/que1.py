#!/usr/bin/python3

b = int(input())
low = int(input())
high = int(input())

mini = 2*high
maxi = 0
maxnum = low
mininum = high

def computeHCF(x, y):
    hcf = 1
    if x > y:
        smaller = y
    else:
        smaller = x
    for i in range(1, smaller+1):
        if((x % i == 0) and (y % i == 0)):
            hcf = i
            
    return hcf

def seq(num, b):
    c = 0
    while num != 1:
        if num%b == 0:
            num = num//b
        else:
            hcf = computeHCF(num%b, b)
            if hcf != 1:
                num = num//hcf
            else:
                num = 3*num + 1
        c = c + 1
    return c

def seq2(num, b, c):
    if num == 1:
        return c
    else:
        if num%b == 0:
            num = num//b
            c = c + 1
            c = seq2(num, b, c)
        else:
            hcf = computeHCF(num%b, b, c)
            if hcf != 1:
               num = num//hcf

for i in range(low, high+1):
    count = 0
    count = seq2(i, b, count)
    print(count, i)
    if maxi < count:
        maxi = count
        maxinum = i
    elif mini > count:
        mini = count
        mininum = i
print(maxinum, maxi, mininum, mini, b, low, high)

"""            for i in range(b, 2, -1):
                if computeHCF(num%b, b) != 1:
                    num = num//i
                    break
            else:
                num = 3*num + 1"""
