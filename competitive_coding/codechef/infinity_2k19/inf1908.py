
t = int(input())

for i in range(t):
    n, k = map(int, input().split())

    ld = str(n)[-1]
    arr = list(str(n))
    arr[-1] = "0"
    n = int("".join(arr))
    tmp = 9 - int(ld)
    while tmp + 10 < k:
        tmp = tmp + 10
    for j in range(k-tmp-1):
        n = n + 1
    print(n)
        
