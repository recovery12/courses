
n, a, b = map(int, input().split())

def find_nums(n,a,b):
    if a > int(n/2):
        print("NO")
        return

    nt = n
    for i in range(b, a, -1):
        n = nt
        l = list()
        j = i
        while n != 0:
            c = True
            val = int(n/j)
            if val > 1:
                for k in range(val):
                    l.append(j)
            elif val == 1:
                if n - val * j >= a and n - val * j <= b:
                    l.append(j)
                else:
                    tmp = l.pop()
                    n = n + tmp
                    c = False
            if c:
                n = n - val * j
            j = j - 1
    print("YES")
    l.sort()
    for x in l:
        print(x, end=" ")
    print("")

find_nums(n, a, b)
