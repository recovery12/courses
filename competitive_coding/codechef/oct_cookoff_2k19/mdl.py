
t = int(input())

for i in range(t):
    n = int(input())

    arr = list(map(int, input().split()))
    while len(arr) != 2:
        num = sorted(arr[:3])[1]
        arr.remove(num)
    print(arr[0], arr[1])
