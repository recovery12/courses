import itertools

n = int(input())

for i in range(n):
    string = ""
    b, x = map(int, input().split())
    charset = "".join([chr(i) for i in range(97, 97+b)])
    j = 1
    while b**j > x and b < x:
        x = x - b**j
    
    while True:
        for roll in itertools.product(charset, repeat = j):
            string = string + "".join(roll)
        j = j + 1
        if len(string) > x:
            break
    print(string[x])

