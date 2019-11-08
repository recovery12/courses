
import numpy as np

t = int(input())

def match(string):
    zc = sum(np.array(list(string)) == "0")
    oc = sum(np.array(list(string)) == "1")

    return zc == oc * oc

for k in range(t):
    s = input()

    c = 0
    for i in range(len(s)-1):
        for j in range(i+1, len(s)):
            if match(s[i:j+1]):
                c = c + 1
    print(c)
