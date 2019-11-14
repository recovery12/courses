#!/usr/bin/python3

def input_data(n):
    array = list()

    for i in range(n):
        array.append(int(input("Enter height of building {}: ".format(i+1))))
    return array

def calcMoves(array):
    j = len(array)-1
    i = 0

    moves = 0
    while i < j:
        ii = i
        ji = j

        while i+1 <= j and array[i] <= array[i+1]:
            array[i] = 0
            i = i + 1
        array[i] = 0
        i = i + 1
        print(array)

        if i > ii:
            moves = moves + 1

        while j-1 >= i and array[j] <= array[j-1]:
            array[j] = 0
            j = j - 1
        array[j] = 0
        j = j - 1
        print(array)

        if j < ji:
            moves = moves + 1

        i = i + 1
        j = j - 1

    return moves

n = 9
array = input_data(n)
print(calcMoves(array))
