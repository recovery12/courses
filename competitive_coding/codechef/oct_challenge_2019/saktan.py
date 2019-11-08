
t = int(input())

for i in range(t):
    n, m, q = map(int, input().split())

    rows = [0 for i in range(n)]
    cols = [0 for i in range(m)]

    for j in range(q):
        r, c = map(int, input().split())
        rows[r-1] = rows[r-1] + 1
        cols[c-1] = cols[c-1] + 1

    odd = 0
    for r in rows:
        for c in cols:
            print(r+c, end="")
            if (r+c) & 1:
                odd = odd + 1
        print("")
    print(rows, cols)
    print(odd)
