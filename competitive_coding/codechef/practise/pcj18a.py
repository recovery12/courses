t = int(input())

for i in range(t):
    n, x = map(int, input().split())
    nums = list(map(int, input().split()))
    
    if any(g >= x for g in nums):
        print("YES")
    else:
        print("NO")
