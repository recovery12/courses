
t = int(input(""))

for k in range(t):
    n, q, k, l, r = tuple(map(int, input().split()))
    can = list()
    price = list()
    for i in range(n):
        c, p = tuple(map(int, input().split()))
        can.append(c)
        price.append(p)
    tmp = can.copy()
    for m in range(1, q+1):
        can = tmp.copy()
        cheap = max(price) + 1
        for j in range(n):
            if price[j] > cheap:
                continue
            for i in range(m):
                if can[j] > k+1:
                    can[j] = can[j] - 1
                elif can[j] < k-1:
                    can[j] = can[j] + 1
                else:
                    can[j] = k
                    break

            if can[j] >= l and can[j] <= r:
                if cheap > price[j]:
                    cheap = price[j]
        if cheap == max(price) + 1:
            cheap = -1
        print(cheap, end=" ")
    print("")
