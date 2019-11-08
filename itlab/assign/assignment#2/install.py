#!/usr/bin/python3

import os

packages = ["selenium", "time", "parsel", "csv"]
for pack in packages:
    try:
        exec("import "+pack)
    except:
        os.system("sudo pip3 install "+pack)

