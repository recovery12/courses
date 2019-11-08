#!/bin/bash
#This script is used to add shebang and give excuitable permission
if [ $# -ne 1 ]
then 
	echo "Synatx: shebang.sh <filename>"
	exit 1
fi

> $1
which bash > $1
chmod u+x $1
vi $1
