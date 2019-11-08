t = int(input())

for i in range(t):
    tab, p = map(int, input().split())
    maxi = 0
    for j in range(tab):
        nums = list(map(int, input().split()))
        if nums[2] <= p:
            wid = nums[0]*nums[1]
            if maxi < wid:
                maxi = wid
    if maxi == 0:
        print("no tablet")
    else:
        print(maxi)
