try:
    t = int(input())
except:
    quit()

for i in range(t):
    c, x = map(int, input().split())

    if c == x:
        print(1)
    else:
        amt = 1
        pig = 1
        rem = 0
        while pig < c:
            rem = c - pig
            pig = pig * x
        amt = amt + rem
        print(amt)
