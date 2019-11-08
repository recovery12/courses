
t = int(input())

for i in range(t):
    n = int(input())
    cost = int(input())

    a = 1
    b = 1
    tot = cost
    while True:
        c = a + b
        if c > n:
            break
        tot = tot + cost
        a = b
        b = c
    print(tot)
