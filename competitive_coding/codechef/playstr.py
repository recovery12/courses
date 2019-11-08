
t = int(input())

for k in range(t):
    n = int(input())
    s = input()
    r = input()

    if sorted(list(s)) == sorted(list(r)):
        print("YES")
    else:
        print("NO")
