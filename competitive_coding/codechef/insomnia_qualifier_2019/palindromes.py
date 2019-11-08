t = int(input())

for i in range(t):
    string = input()
    n = len(string)
    q, l, r, x, y, m = map(int, input().split())

    tot = 0
    ans = 0
    for j in range(q):
        l = 1 + (l+ans)%n
        r = 1 + (r+ans)%n
        if l > r:
            l, r = r, l
        x = 1 + (x+ans)%m
        y = 1 + (y+ans)%n
        if x > y:
            x, y = y, x
        s = list()
        for v in range(l-1, r):
            for u in range(x, y+1):
                if u+v <= r and string[v:v+u] == string[v:v+u][::-1]:
                    s.append(string[v:v+u])
        ans = len(s)
        tot = tot + ans
    print(tot)
