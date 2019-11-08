
a, b = map(int, input().split())

arr = list(map(int, input().split()))
sets = list(map(int, input().split()))

sets.sort()
p1 = 0
for e in sets:
    while True:
        if p1 < a and e < arr[p1]:
            arr.insert(p1, e)
            p1 = p1 + 1
            a = a + 1
            break
        elif p1 < a:
            p1 = p1 + 1
        else:
            break
    if p1 == a:
        arr.append(e)
for e in arr:
    print(e, end=" ")
print()
