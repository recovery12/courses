
t = int(input())

for i in range(t):
    m, x, y = map(int, input().split())

    cops = list(map(int, input().split()))

    house = [0 for i in range(101)]
    c = 0
    for cop in cops:
        if cop-1 - x*y <= 0:
            ll = 0
        else:
            ll = cop - x*y - 1

        if cop-1 + x*y >= 99:
            uu = 99
        else:
            uu = cop-1 + x*y

        if c > 100:
            print(0)
            break
        for j in range(ll, uu+1):
            if house[j] == 0:
                house[j] = house[j] + 1
                c = c + 1
            else:
                continue
    print(100-c)
