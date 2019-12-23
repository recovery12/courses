t = int(input())

for i in range(t):
    n = int(input())
    arr = list(map(int, input().split()))

    maxi = 0
    for num in set(arr):
        if maxi < arr.count(num):
            maxi = arr.count(num)
    print(n-maxi)
