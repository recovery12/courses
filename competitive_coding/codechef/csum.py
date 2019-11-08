
t = int(input())

for i in range(t):
    n, k = tuple(map(int, input().split()))

    lst = list(map(int, input().split()))
    for i in range(n):
        for j in range(i, n):
            if lst[i] + lst[j] == k:
                print("Yes")
                break
    print("No")
