
t = int(input())

for i in range(t):
    n = int(input())

    num = n*(n-1)/2

    if num%n != 0:
        print("NO")
    elif num%n == 0:
        print("YES")
        for j in range(n):
            l = ["0" for x in range(n)]
            for k in range(1+j, int(n//2)+1+j):
                l[k%n] = "1"
            print("".join(l))
            
