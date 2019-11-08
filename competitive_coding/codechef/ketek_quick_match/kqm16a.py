
count = 0
n = int(input())
l = list(map(int, input().split()))
count = len(l)
if l.count(l[0]) == count:
    print(count)
else:
    tmp = 0
    maxi = 0
    for j in range(n):
        for k in range(j+1, n):
            if l[k] > l[j] and l[k] > maxi:
                tmp = tmp + 1
                maxi = l[k]
    count = count + (2**tmp) - 1
    print(count)
