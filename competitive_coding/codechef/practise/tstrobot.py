t = int(input())

for i in range(t):
    n, x = map(int, input().split())
    vp = {x}
    string = input()

    for mv in string:
        if mv == "R":
            x = x + 1
        elif mv == "L":
            x = x - 1
        vp.add(x)
    print(len(vp))

