
t = int(input())

def maxORInRange(L, R): 
  
    LOR = L | R 
  
    msbPos = 0
    while(LOR):      
        msbPos += 1
        LOR >>= 1

    maxOR, two = 0, 1
      
    while (msbPos): 
      
        maxOR += two 
        two <<= 1
        msbPos -= 1
  
    return maxOR

for i in range(t):
    l, r = map(int, input().split())
    print(maxORInRange(l, r))
