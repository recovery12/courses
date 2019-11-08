#!/usr/bin/python3

import numpy as np

def passwd_gen(s: int) -> str:
if __name__ == '__main__':
    s = 0
    while s not in range(1, 4):
        print("Enter the Srength of the Passwords: ")
        print("1) Weak")
        print("2) Medium")
        print("3) Strong")
        if s not in range(1, 4):
            print("Select a valid option")
    strength = s
