from math import log2
try:
    t = int(input())
except:
    quit()

for i in range(t):
    n = int(input())

    if n == 1:
        print("0")
        continue
    elif n in [2, 3]:
        print("1")
        continue
    elif n == 4:
        print("2")
        continue
    a = int(log2(n))+1

    if a%4 == 0:
        print("3")
    elif a%4 == 1:
        print("0")
    elif a%4 == 2:
        print("9")
    elif a%4 == 3:
        print("2")
