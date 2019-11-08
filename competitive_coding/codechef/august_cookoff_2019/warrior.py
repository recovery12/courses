
t = int(input(""))

for k in range(t):
    n, q = tuple(map(int, input("").split()))
    pows = list(map(int, input("").split()))
    chk = 0
    for i in range(q):
        win = list()
        x = int(input())
        for j in range(len(pows)):
            wn = 0
            n = 0
            i = j
            while n != len(pows):
                y = pows[i]
                if x > y:
                    wn = wn + 1
                    x = 2*(x-y)
                else:
                    chk = 1
                    break
                if i == len(pows)-1:
                    i = 0
                else:
                    i = i + 1
                n = n + 1
            win.append(wn)
        print(max(win))
