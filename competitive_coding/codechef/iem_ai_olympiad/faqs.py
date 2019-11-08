title = input()
lt = [s.strip().lower() for s in input().split(",")]
for i in range(len(lt)):
    lt.append(lt[i]+"ing")

t = int(input())
for i in range(t):
    que = input()
    ans = input()
    q = [s.strip(" ?.").lower() for s in que.split()]
    a = [s.strip(" ?.").lower() for s in ans.split()]

    qb = 0
    ab = 0
    for w in lt:
        if w in q:
            qb = 1
        if w in a:
            ab = 1
    if qb and ab:
        print(que)
        print(ans)
