
from itertools import combinations

n, k = map(int, input().split())
l = list(map(int, input().split()))
dis = list(set(l))

tot = 1 + n
for j in range(2, k+1):
    comb = combinations(dis, j)
    for com in comb:
        tot_t = 1
        for d in com:
            tot_t = tot_t * l.count(d)
        tot = tot + tot_t
print((tot)%(10**9+7))
