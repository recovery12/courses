
t = int(input())

for i in range(t):
    a, b, c = map(int, input().split())

    if a == 1 and b == 0 and c == 1:
        print("NO")
    elif a%2 == 1 and b%2 == 1 and c%2 == 0:
        print("NO")
    elif a%2 == 0 and b%2 == 1 and c%2 == 1:
        print("NO")
    elif a%3 != 0 and b%2 == 0 and c%3 == 0:
        print("NO")
    elif a == 0 and b == 0 and c%2 == 1:
        print("NO")
    elif a == 0 and b%2 == 1 and c == 0:
        print("NO")
    elif a%2 == 1 and b == 0 and c == 0:
        print("NO")
    else:
        print("YES")
