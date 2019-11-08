
t = int(input())

import math
  
def modInverse(b,m): 
    g = math.gcd(b, m)  
    if (g != 1): 
        return -1
    else:  
        return pow(b, m - 2, m) 
  
def modDivide(a,b,m): 
    a = a % m 
    inv = modInverse(b,m) 
    if(inv == -1): 
        print("Division not defined") 
    else: 
        return ((inv*a) % m)

def fast_exp(b, e):
    mod = 10**9+7
    if e == 1:
        return b
    else:
        if e%2 == 0:
            b1 = pow(fast_exp(b, int(e//2)), 2)
            if b1 >= mod:
                return b1%mod
            else:
                return b1
        else:
            ans = (b * pow(fast_exp(b, int((e-1)//2)), 2))
            if ans >= mod:
                return ans%mod
            else:
                return ans

for i in range(t):
    n, k, m = map(int, input().split())

    mod = 10**9+7
    if n == 1:
        #val = ((k+1)**m)+((k-1)**m)
        val1 = int((fast_exp(k+1, m) + fast_exp(k-1, m)))
        ans = modDivide(val1, 2, mod)
    print(ans)
