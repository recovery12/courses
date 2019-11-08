
k, j = map(int, input().split())

def rappers(k, j, tot):
    m1 = min(k, j)
    m2 = max(k, j)
    k = m2
    j = m1
    if k == 0 or j == 0:
        return 0

    if k == j and k != 1:
        if k%3 in [0, 1]:
            tot = tot + int(k/3)*2
        else:
            tot = tot + int(k/3)*2 + 1
        return tot
    elif k == j:
        return tot

    for i in range(m1, 0, -1):
        print(m1, m2)
        if 2*i <= k:
            tot = tot + i
            k = k - 2*i
            j = j - i
            tot = rappers(k, j, tot)

    return tot

tot = 0
tot = rappers(k, j, tot)
print(tot)
