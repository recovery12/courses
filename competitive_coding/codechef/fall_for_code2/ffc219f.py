
t = int(input())

for i in range(t):
    n, p = map(int, input().split())

    tot = 0
    l = list(map(int, input().split()))
    l.sort()
    for j in range(n):
        if p >= l[j]:
            tot = tot + 1
            p = p - l[j]
        elif p == 0:
            break
    print(tot)
