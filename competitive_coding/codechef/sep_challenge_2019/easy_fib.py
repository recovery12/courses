from math import log2
try:
    t = int(input())
except:
    quit()

for i in range(4,t):
    #n = int(input())

    a = int(log2(i))
    term = 2**a
    a = 0
    b = 1
    if term == 1:
        c = 0
    elif term == 2:
        c = 1
    for j in range(2, int(term)):
        c = (a+b)%10
        tmp = a
        a = b
        b = c
    print(i, c)
