
t = int(input())

for i in range(t):
    n, k = map(int, input().split())

    l = list(map(int, input().split()))

    tmp = l.copy()
    for m in range(1, k+1):
        l = tmp.copy()
        for j in range(m):
            l[j%n] = l[j%n] ^ l[n-j%n-1]

        print(m, end=" -> ")
        for j in range(n):
            print(l[j], end=" ")
        print("")
