t = int(input())

def isprime(num):
    for i in range(2, num):
        if num % i  == 0:
            return False
            break
    else:
        return True

for i in range(t):
    num = int(input())
    if isprime(num):
        print("yes")
    else:
        print("no")
