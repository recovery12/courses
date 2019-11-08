
t = int(input())

for i in range(t):
    match = [6,2,5,5,4,5,6,3,7,6]
    a, b = map(int, input().split())

    tot = 0
    for c in str(a+b):
        tot = tot + match[int(c)]
    print(tot)
