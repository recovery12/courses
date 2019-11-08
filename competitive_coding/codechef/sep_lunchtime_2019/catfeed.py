
t = int(input())

for i in range(t):
    n, m = map(int, input().split())

    feed = [0 for i in range(n)]
    order = list(map(int, input().split()))

    for o in order:
        check = False
        val = feed[o-1]
        for j in range(n):
            if val > feed[j]:
                print("NO")
                check = True
                break
        if check:
            break
        else:
            feed[o-1] = feed[o-1] + 1
    if check:
        continue
    else:
        print("YES")
