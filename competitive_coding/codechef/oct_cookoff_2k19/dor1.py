
t = int(input())

def maxOR(a, b):
    if a.bit_length() != b.bit_length():
        m = max(a, b)
        bt = len(bin(m))-2
        ans = int("1"*bt, 2)
        print(ans)
    else:
        num = ""
        for i in range(a.bit_length()):
            if bin(a)[2:][i] == bin(b)[2:][i]:
                num = num + bin(a)[2:][i]
            else:
                break
        for j in range(i, a.bit_length()):
            num = num + "1"
        print(int(num, 2))
            
for i in range(t):
    l, r = map(int, input().split())
    maxOR(l, r)
