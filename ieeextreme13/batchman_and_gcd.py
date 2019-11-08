
from itertools import combinations

def find_gcd(some_list):
    gcd = 1
    num = min(some_list)
    for i in range(1, num+1):
        no = 0
        for j in range(len(some_list)):
            if some_list[j]%i == 0:
                no = no + 1
        if no == len(some_list):
            gcd = i
    return gcd

n, k = map(int, input().split())

arr = list(map(int, input().split()))

gcds = set()
for i in range(1, k+1):
    permut = combinations(arr, i)
    for p in permut:
        gcds.add(find_gcd(p))
print(len(gcds))
