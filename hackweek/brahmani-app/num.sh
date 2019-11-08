#!/bin/bash\nif [ $# -ne 1 ]\nthen\n    echo \"Usage: num.sh <digit>\"\n    exit 1\nfi\n \ncase $1\nin\n    0) echo zero;;\n    1) echo one;;\n    2) echo two;;\n    3) echo three;;\n    4) echo four;;\n    5) echo five;;\n    6) echo six;;\n    7) echo seven;;\n    8) echo eight;;\n    9) echo nine;;\n    *) echo \"Bad argument\"\n            exit 2;;\nesac

