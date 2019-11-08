#!/usr/bin/python3

"""
    Shivam is the youngest programmer in the world, he is just 12 years old. Shivam is learning programming and today he is writing his first program.

Program is very simple, Given two integers A and B, write a program to add these two numbers. 

Input:-
    The first line contains an integer T, total number of test cases. Then follow T lines, each line contains two Integers A and B. 

Output:-
    Add A and B and display it.

Constraints:-
    1 ≤ T ≤ 1000
    1 ≤ A,B ≤ 10000
"""

T = int(input())
for tc in range(T):
	# Read integers a and b.
	(a, b) = map(int, input().split(' '))
	
	ans = a + b
	print(ans)
