#!/bin/bash
#This script is used to whether the given input is directory or not
if [ $# -ne 1 ]
then 
	echo "Syntax: direx.sh <directoryname>"
	exit 1
fi

if [ -d $1 ]
then 	
	echo "It's a directory"
else
	echo "It's not a directory"
fi
