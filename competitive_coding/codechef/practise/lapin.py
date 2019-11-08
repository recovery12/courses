
t = int(input())

for i in range(t):
    string = input()
    l = len(string)

    if l%2 == 0:
        chars = list(set(string[:l//2]))
        left = list(string[:l//2])
        right = list(string[l//2:])
    
        flag = False
        for c in chars:
            if left.count(c) != right.count(c):
                flag = True
        if flag:
            print("NO")
        else:
            print("YES")
    else:
        chars = list(set(string[:l//2]))
        left = list(string[:l//2])
        right = list(string[l//2+1:])
    
        flag = False
        for c in chars:
            if left.count(c) != right.count(c):
                flag = True
        if flag:
            print("NO")
        else:
            print("YES")
