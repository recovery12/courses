#!/bin/bash
#This script is used to delete the files whose name consists of special characters in a given directory.
if [ $# -ne 2 ]
then
	echo "Syntax: spchad.sh <directoryname> <special character>"
	exit 1
fi

var=$(ls $1 | sed -n '/'$2'/p')

rm $var
