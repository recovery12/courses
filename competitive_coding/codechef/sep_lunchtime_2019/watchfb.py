
t = int(input())

for i in range(t):
    n = int(input())

    formats = list()
    for i in range(n):
        val = tuple(map(int, input().split()))
        if i == 0 and val[0] == 1:
            print("YES")
        elif i == 0 and val[0] == 2:
            print("NO")
        elif formats[i-1][0] == 1 and val[0] == 2:
            print("YES")
        elif formats[i-1][0] == 2 and val[0] == 1:
            print("YES")
        elif formats[i-1][0] == 1 and val[0] == 1:
            print("YES")
        elif formats[i-1][0] == 2 and val[0] == 2:
            if val[1] == val[2]:
                print("YES")
            else:
                print("NO")
        formats.append(val)
