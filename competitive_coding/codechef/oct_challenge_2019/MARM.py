
t = int(input())

for i in range(t):
    n, k = map(int, input().split())

    l = list(map(int, input().split()))

    if n%2 == 0:
        nk = k % (n*3)
        for j in range(nk):
            l[j%n] = l[j%n] ^ l[n-j%n-1]

        for j in range(n):
            print(l[j], end=" ")
        print("")
    elif n%2 == 1:
        nk = k % (n*3)
        for j in range(nk):
            l[j%n] = l[j%n] ^ l[n-j%n-1]
        
        for j in range(n):
            if j == int(n//2):
                if k in range(int(n//2)):
                    print(l[int(n//2)], end=" ")
                    continue
                else:
                    print("0", end=" ")
                    continue
            print(l[j], end=" ")
        print("")

