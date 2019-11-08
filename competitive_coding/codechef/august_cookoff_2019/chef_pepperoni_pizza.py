
t = int(input())

def rev(part, n):
    for i in range(0, int(n/2)):
        part[i], part[n-1-i] = part[n-1-i], part[i]
    return part

def diff_pepperoni(pizza, n):
    p1 = 0
    p2 = 0
    for i in range(n):
        for j in range(int(n/2)):
            if pizza[i][j] == '1':
                p1 = p1 + 1

            if pizza[i][int(n/2)+j] == '1':
                p2 = p2 + 1
    if p1 - p2 > 0:
        return p1-p2
    else:
        return p2-p1

for k in range(t):
    n = int(input())
    pizza = list()
    for i in range(n):
        part = input()
        pizza.append(list(part))

    mini = n*n
    if diff_pepperoni(pizza, n) == 0:
        print(0)
        continue
    for i in range(n):
        for j in range(int(n/2)):
            if  
        """tmp = pizza.copy()
        if pizza[i] != pizza[i][::-1]:
            tmp[i] = rev(pizza[i].copy(), n)
            val = diff_pepperoni(tmp, n)
            if mini > val:
                mini = val"""
    if mini == n*n:
        mini = 0
    print(mini)
