#!/usr/bin/python3

import numpy as np

# 17MCME13 Peddi Anurag

def print_set(sets):
    print("{", end="")
    for ele in sets:
        print(ele, end=",")
    print("}")
    return None

def create_set(n):
    sets = list()

    i = 0
    while i < n:
        element = int(input("Enter the element: "))
        if element not in sets:
            sets.append(element)
            i = i + 1
    return sets

def is_member(seta, value):
    for element in seta:
        if element == value:
            return True
    return False

def subset(seta, setb):
    count = 0

    for e1 in seta:
        for e2 in setb:
            if e1 == e2:
                count = count + 1
                break
    if count == len(seta):
        return True
    else:
        return False

def superset(seta, setb):
    count = 0

    for e1 in setb:
        for e2 in seta:
            if e1 == e2:
                count = count + 1
                break
    if count == len(setb):
        return True
    else:
        return False

def union(seta, setb):
    setc = seta.copy()

    for element in setb:
        if is_member(setc, element) == False:
            setc.append(element)
    return setc

def intersection(seta, setb):
    setc = list()

    for element in seta:
        if is_member(setb, element):
            setc.append(element)
    return setc

def difference(seta, setb):
    setc = list()

    for element in seta:
        if not is_member(setb, element):
            setc.append(element)
    return setc

def sym_diff(seta, setb):
    ts1 = difference(seta, setb)
    ts2 = difference(setb, seta)
    ts3 = union(ts1, ts2)

    return ts3

if __name__ == '__main__':
    n1 = int(input("Enter the number of elements in setA: "))
    print("Enter elements in setA: ")
    seta = create_set(n1)

    n2 = int(input("Enter the number of elements in setB: "))
    print("Enter elements in setB: ")
    setb = create_set(n2)

    print("Operations are:")
    print("1) Union")
    print("2) Intersection")
    print("3) Difference")
    print("4) Symmetric Difference")
    print("5) Is member")
    print("6) Subset")
    print("7) Superset")
    opt = int(input("Enter your input: "))

    if opt == 1:
        setc = union(seta, setb)
        print_set(setc)
    elif opt == 2:
        setc = intersection(seta, setb)
        print_set(setc)
    elif opt == 3:
        setc = difference(seta, setb)
        print_set(setc)
    elif opt == 4:
        setc = sym_diff(seta, setb)
        print_set(setc)
    elif opt == 5:
        val = int(input("Enter the value to be searched: "))
        setc = is_member(seta, val)
        if setc:
            print("Is a member")
        else:
            print("Is not a member")
    elif opt == 6:
        setc = subset(seta, setb)
        if setc:
            print("Subset")
        else:
            print("Not a subset")
    elif opt == 7:
        setc = superset(seta, setb)
        if setc:
            print("Superset")
        else:
            print("Not a superset")
