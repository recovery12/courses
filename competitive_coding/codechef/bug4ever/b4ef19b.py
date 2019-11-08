
t = int(input())

for i in range(t):
    n1, n2, n3, n4 = list(map(int, input().split()))

    mini = min((n1, n2, n4))

    rem = n3
    if mini == 0:
        print("0")
    else:
        if n1 - mini > 0:
            rem = rem + (n1 - mini)
        if n2 - mini > 0:
            rem = rem + (n2 - mini)
        if n4 - mini > 0:
            rem = rem + (n4 - mini)
        print(min(mini, rem))
