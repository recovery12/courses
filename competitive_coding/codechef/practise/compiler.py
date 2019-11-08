
t = int(input())

for i in range(t):
    string = input()

    l = list()
    maxi = 0
    for c in string:
        if c == "<":
            l.append("<")
        elif c == ">":
            if len(l) != 0 and l[-1] == "<":
                co = co + 2
                l = l[:-1]
    print(co)
