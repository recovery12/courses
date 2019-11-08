t = int(input())

for i in range(t):
    l = int(input())
    nums = set(map(int, input().split()))
    print(nums)
    if len(nums) < l:
        print(len(nums))
        print("YES")
    else:
        print("NO")
