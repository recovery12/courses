t = int(input())

for i in range(t):
    n, k = map(int, input().split())
    nums = list(map(int, input().split()))

    while k <= len(nums):
        tmp = list()
        for j in range(0, len(nums), k):
            if len(nums) - j < k:
                tmp.extend(nums[j:j+k])
            else:
                tmp.append(sum(nums[j:j+k]))
        nums = tmp.copy()
    for x in nums:
        print(x, end=" ")
    print()
