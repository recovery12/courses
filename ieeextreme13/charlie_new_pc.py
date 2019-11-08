
t = int(input())

for i in range(t):
    b = int(input())
    n = int(input())
    ns = list(map(int, input().split()))

    mat = list()
    for i in range(n):
        mat.append(sorted(list(map(int, input().split()))))

    
