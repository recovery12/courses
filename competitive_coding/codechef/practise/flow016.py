
t = int(input())

def computeGCD(x, y):
   while(y):
       x, y = y, x % y
   return x

for i in range(t):
    a, b = map(int, input().split())

    gcd = computeGCD(a, b)
    lcm = int(a*b/gcd)
    print(gcd, lcm)
