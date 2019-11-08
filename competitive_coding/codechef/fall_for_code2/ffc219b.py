
t = int(input())

one = 24
two = 50
three = 35
four = 10
five = 1

def sum_n(n):
    return int(n*(n+1)/2)

def sum_n2(n):
    return int(n*(n+1)*(2*n+1)/6)

def sum_n3(n):
    return int((n*(n+1)/2)**2)

def sum_n4(n):
    return int(((6 * n * n * n * n * n) + (15 * n * n * n * n) + (10 * n * n * n) - n) / 30)

for i in range(t):
    tot = 0
    l, r = map(int, input().split())

    tot = (r-l+1)*one + (sum_n(r-1)-sum_n(l-2))*two + (sum_n2(r-1)-sum_n2(l-2))*three + (sum_n3(r-1)-sum_n3(l-2))*four + (sum_n4(r-1)-sum_n4(l-2))*five
    print(tot)
