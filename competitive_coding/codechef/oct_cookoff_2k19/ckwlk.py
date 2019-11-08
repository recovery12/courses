
t = int(input())

from math import log2

for i in range(t):
    n = int(input())

    c = 0
    tmp = n
    rem = 0
    while rem == 0:
        rem = tmp%10
        if rem == 0:
            c = c + 1
        else:
            break
        tmp = tmp//10
    if tmp == 1:
        print("Yes")
        continue
    val = log2(tmp)
    if val == int(val) and c >= int(val):
        print("Yes")
    else:
        print("No")
