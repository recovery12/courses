t = int(input())

def fact(n):
    if n == 0 or n == 1:
        return 1
    else:
        return n * fact(n-1)

for i in range(t):
    N, k = map(int, input().split())

    nums = list(map(int, input().split()))
    nums.sort()

    subset = nums[:k].copy()
    num = subset[-1]
    n = nums.count(num)
    m = subset.count(num)

    tot = int(fact(n)/(fact(n-m)*fact(m)))
    print(tot)
