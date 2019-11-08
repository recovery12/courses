
t = int(input())

for i in range(t):
    check = True
    n = int(input())
    arr = list(map(int, input().split()))

    arr.sort()
    wid = int(n/4)
    for i in range(3):
        if arr[wid*i:wid*(i+1)][-1] != arr[wid*(i+1):wid*(i+2)][0]:
            continue
        else:
            check = False
            break

    if check:
        print(arr[wid*1:wid*2][0], arr[wid*2:wid*3][0], arr[wid*3:wid*4][0])
    else:
        print(-1)
