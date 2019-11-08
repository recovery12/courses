#!/bin/bash

if [ $# -eq 2 ]
then
    name=$(echo "$1" | sed 's/.c//')
    gcc -Wall $1 -o $name -$2
    exit 0
elif [ $# -eq 1 ]
then
    name=$(echo "$1" | sed 's/.c//')
    gcc -Wall $1 -o $name
    exit 0
else
    echo "Syntax: ./comp <filename> [options]"
    exit 1
fi

