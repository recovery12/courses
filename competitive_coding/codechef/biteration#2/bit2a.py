
t = int(input())

def print_array(b):
    for x in b:
        print(x, end=" ")
    print("")

for i in range(t):
    n = int(input())

    a = list(map(int, input().split()))

    b = list()
    for i in range(n):
        count = 0
        for j in range(i, n):
            if a[i] < a[j]:
                count = count + 1
        b.append(count)
    print_array(b)
