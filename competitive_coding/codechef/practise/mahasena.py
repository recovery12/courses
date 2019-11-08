t = int(input())

wea = list(map(int, input().split()))
r = 0
nr = 0
for n in wea:
    if n%2 == 0:
        r = r + 1
    else:
        nr = nr + 1
if r > nr:
    print("READY FOR BATTLE")
else:
    print("NOT READY")
