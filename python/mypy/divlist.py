#!/usr/bin/python3.6

def find_integer_with_most_divisors(input_list):
    no = 0
    maxnum = 0
    maxdiv = input_list[0]
    for i in range(len(input_list)):
        m = input_list[i]
        for i in range(1, m+1):
            if m%i == 0:
                no = no + 1
        if maxnum < no:
            maxnum = no
            maxdiv = m
            no = 0
    print(maxdiv)
    print(type(maxdiv))

listin = [10, 20, 50, 30]
find_integer_with_most_divisors(listin)
