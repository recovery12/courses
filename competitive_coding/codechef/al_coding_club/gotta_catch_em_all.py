n, t = map(int, input().split())
lst = list(map(int, input().split()))

s = int(input())

for i in range(s):
    a, b = map(int, input().split())
    uni = set(lst[a-1:b])
    part = lst[a-1:b]

    maxi = 0
    typ = 0
    for n in uni:
        if maxi < part.count(n):
            maxi = part.count(n)
            typ = n
    if maxi > len(part)//2:
        print(typ)
    else:
        print("Champion")
