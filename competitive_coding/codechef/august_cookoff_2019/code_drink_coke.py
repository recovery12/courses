
t = int(input(""))

for k in range(t):
    n, m, k, l, r = tuple(map(int, input().split()))
    can = list()
    price = list()
    for i in range(n):
        c, p = tuple(map(int, input().split()))
        can.append(c)
        price.append(p)
    for i in range(m):
        for j in range(n):
            if can[j] > k+1:
                can[j] = can[j] - 1
            elif can[j] < k-1:
                can[j] = can[j] + 1
            else:
                can[j] = k

    cheap = max(price) + 1
    for i in range(n):
        if can[i] >= l and can[i] <= r:
            if cheap > price[i]:
                cheap = price[i]
    if cheap == max(price) + 1:
        cheap = -1
    print(cheap)
