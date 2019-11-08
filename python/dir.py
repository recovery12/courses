#!/usr/bin/python3

import os

cwd = os.getcwd()

def walk(dire):
    print(os.listdir(cwd))
    for name in os.listdir(cwd):
        path = os.path.join(cwd, name)
        if os.path.isdir(path):
            print(os.listdir(path), "\nin the dir", name)

walk(cwd)
