
t = int(input())

for i in range(t):
    n, k = map(int, input().split())

    arr = list(map(int, input().split()))

    sums = 0
    for i in range(n):
        for j in range(i+1, n):
            if arr[i] > arr[j]:
                sums = sums + int(k*(k+1)/2)
            elif arr[i] < arr[j]:
                sums = sums + int(k*(k-1)/2)
    print(sums)
