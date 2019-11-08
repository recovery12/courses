
t = int(input())

for i in range(t):
    n = int(input()
    l = list(map(int, input().split()))

    l.sort()

    num = l[0]
    for i in range(1, len(l)):
        num = (num%l[i])
    print(num)
