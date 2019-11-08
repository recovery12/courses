"""easy"""

t = int(input())

def isprime(num):
    for i in range(2, num):
        if num % i  == 0:
            return False
            break
    else:
        return True

for k in range(t):
    x, y = map(int, input().split())

    i = 1
    while isprime(x+y+i) != True:
        i = i + 1
    print(i)
