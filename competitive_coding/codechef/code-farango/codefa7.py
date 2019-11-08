
t = int(input())

def fact(n):
    if n in [0, 1]:
        return 1
    else:
        l = [1, 1]
        for i in range(2, n+1):
            l.append(i * l[i-1])
    return l[-1]

for i in range(t):
    n = int(input())

    print(fact(n))
