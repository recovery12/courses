t = int(input())

for i in range(t):
    n = int(input())
    c = 0
    for j in range(n):
        s, j = map(int, input().split())
        if j - s > 5:
            c = c + 1
    print(c)
