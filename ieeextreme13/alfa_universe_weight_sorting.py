
n, m = map(int, input().split())

from itertools import permutations

permut = permutations(range(n), 2)
uni = set()

for i in range(m):
    p1 = permut
    relation = input()
    c1 = relation[0]
    c2 = relation[1]
    tmps = set()
    for j in p1:
        if ord(c1)-65 in j or ord(c2)-65 in j:
            continue
        else:
            tmps.add(chr(j[0]+65)+c1+chr(j[1]+65)+c2)
            tmps.add(chr(j[0]+65)+c1+c2+chr(j[1]+65))
            tmps.add(chr(j[1]+65)+c1+chr(j[0]+65)+c2)
            tmps.add(c1+chr(j[0]+65)+chr(j[1]+65)+c2)
            tmps.add(chr(j[0]+65)+c1+chr(j[1]+65)+c2)
            tmps.add(chr(j[0]+65)+c1+chr(j[1]+65)+c2)
    
    
