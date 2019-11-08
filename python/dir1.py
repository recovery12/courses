#!/usr/bin/python3.6

import os

cwd = os.getcwd()
for root,dirs,files in os.walk(cwd):
    for name in files:
        name = os.path.join(cwd, name)
        print(name)
