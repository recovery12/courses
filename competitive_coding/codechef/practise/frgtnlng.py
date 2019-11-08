
t = int(input())

for i in range(t):
    n, k = map(int, input().split())
    dic = list(input().split())
    p = list()
    for j in range(k):
        p.append(input())

    l = list()
    for word in dic:
        c = 1
        for j in range(k):
            if word in p[j]:
                l.append("YES")
                c = 0
                break
        if c:
            l.append("NO")
    for yn in l:
        print(yn, end=" ")
    print("")
