
t = int(input())

for i in range(t):
    good = 1
    n = int(input())

    price = list(map(int, input().split()))

    for i in range(1, n):
        c = 0
        if i < 5:
            for j in range(i):
                if price[j] <= price[i]:
                   c = 1
                   break
            if c == 0:
                good = good + 1
        else:
            for j in range(i-5, i):
                if price[j] <= price[i]:
                    c = 1
                    break
            if c == 0:
                good = good + 1
    print(good)
