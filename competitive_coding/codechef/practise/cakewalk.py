try:
    t = int(input())
except:
    quit()

MAX = 10
for i in range(t):
    times = list()
    for j in range(MAX):
        tmp = list(map(int, input().split()))
        times.append(tmp)

    c = 0
    for m in range(MAX):
        for n in range(MAX):
            if times[m][n] <= 30:
                c = c + 1
    if c >= 60:
        print("yes")
    elif c < 60:
        print("no")
