#!/bin/bash

ext=$(echo $1 | awk -F"." '{print $NF}')

if test $ext = "c"
then
   name=$(echo $1 | awk -F"." '{print $1}')
   gcc -Wall $1 -o $name -lm
else
   echo "In-valid C file"
fi
