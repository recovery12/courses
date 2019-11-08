
t = int(input())

for i in range(t):
    n, c = map(int, input().split())

    a_candies = list(map(int, input().split()))

    if c >= sum(a_candies):
        print("Yes")
    else:
        print("No")
