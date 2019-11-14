#!/usr/bin/python3

import sys

def input_data(n):
    array = list()

    for i in range(n):
        array.append(int(input("Enter height of building {}: ".format(i+1))))
    return array

def isolated_building(array, ind, n):
    if array[ind] == 0:
        return False

    if ind == n - 1 and array[ind-1] == 0:
        return True
    elif ind == 0 and array[ind+1] == 0:
        return True
    elif array[ind-1] == 0 and array[ind+1] == 0:
        return True

    return False

def minimum_moves(array, n):
    # First Monster

    check = False
    min_count = 0
    pos = 0
    while pos < n-1:
        while pos < n-1 and array[pos] <= array[pos+1] and array[pos] != 0:
            array[pos] = 0
            pos = pos + 1
            check = True
        if check:
           array[pos] = 0
           min_count = min_count + 1
           check = False
        pos = pos + 1

    # Second Monster
    check = False
    pos = n-1
    while pos >= 0:
        while pos > 0 and array[pos] <= array[pos-1] and array[pos] != 0:
            array[pos] = 0
            pos = pos - 1
            check = True
        if check:
            array[pos] = 0
            min_count = min_count + 1
            check = False
        if isolated_building(array, pos, n):
            array[pos] = 0
            min_count = min_count + 1
        pos = pos - 1

    return min_count

if __name__ == '__main__':
    n = int(input("Enter total number of buildings: "))
    if n <= 0:
        print("SuperCity should have atleast one building.")
        sys.quit()
    elif n == 1:
        print("Minimum number of moves are: 1")
        sys.quit()
    
    building_lengths = input_data(n)

    min_moves = minimum_moves(building_lengths, n)
    print("\nMinimum number of moves are:", min_moves)
