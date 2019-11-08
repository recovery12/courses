
t = int(input())

for i in range(t):
    n, m, q = map(int, input().split())

    rows = [0 for i in range(n)]
    cols = [0 for i in range(m)]

    rs = list()
    cs = list()
    odd1 = 0
    for j in range(q):
        r, c = map(int, input().split())
        if r in rs:
            odd1 = odd1 + (m - n + len(cs))
            rs.remove(r)
        else:
            odd1 = odd1 + (m - 2 * len(cs))
            rs.append(r)
        if c in cs:
            odd1 = odd1 + (n - m + len(rs))
            cs.remove(c)
        else:
            odd1 = odd1 + (n - 2 * len(rs))
            cs.append(c)
        print("odd", odd1)
        rows[r-1] = rows[r-1] + 1
        cols[c-1] = cols[c-1] + 1
        for r in rows:
            for c in cols:
                print(r+c, end="")
            print("")

    odd = 0
    for r in rows:
        for c in cols:
            if (r+c) & 1:
                odd = odd + 1
    print(odd)
