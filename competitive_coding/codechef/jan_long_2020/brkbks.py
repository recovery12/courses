t = int(input())

def max_brks(stack, s):
    n = 0
    while s >= sum(stack[:n+1]) and n < len(stack):
        n = n + 1
    return n

for i in range(t):
    hits = 0
    s, w1, w2, w3 = map(int, input().split())

    stack = [w1, w2, w3]
    while len(stack) != 0:
        m = max_brks(stack, s)
        n = max_brks(stack[::-1], s)
        if m >= n:
            while m != 0:
                stack.pop(0)
                m = m - 1
        else:
            stack = stack[::-1]
            while n != 0:
                stack.pop(0)
                n = n - 1
        hits = hits + 1
    print(hits)