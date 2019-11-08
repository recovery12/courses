
t = int(input())

for i in range(t):
    n = int(input())

    l = list(map(int, input().split()))

    mstar = 0
    for i in range(n):
        star = 0
        for j in range(i):
            if l[j]%l[i] == 0:
                star = star + 1
        if mstar < star :
            mstar = star
    print(mstar)
