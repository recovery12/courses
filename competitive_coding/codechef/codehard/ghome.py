#!/usr/bin/python3

t = int(input())

for i in range(t):
    m, n = map(int, input().split())

    tiles = 0
    if m%2 == 0:
        tiles = tiles + (m//2)*n
    elif m%2 != 0 and n%2 != 0:
        tiles = tiles + (m//2)*n
        tiles = tiles + (n//2)+1
    elif m%2 != 0 and n%2 == 0:
        tiles = tiles + (m//2)*n
        tiles = tiles + (n//2)
    print(tiles)
