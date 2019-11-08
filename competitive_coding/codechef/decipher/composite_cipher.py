#!/usr/bin/python3

m = 26
cipher = input("")
k1 = int(input(""))
k2 = int(input(""))

cip_tmp = list(map(ord, cipher))

def modInverse(a, m) : 
    a = a % m;
    x = 1
    while (a*x)%m != 1: 
        if ((a * x) % m == 1) : 
            return x
        x = x + 1

k2_inv = modInverse(k2, m)
decipher = ""

for i in range(len(cip_tmp)):
    decipher = decipher + chr(((((cip_tmp[i] - 65)- k1) * k2_inv)%26)+65)

print(decipher)
