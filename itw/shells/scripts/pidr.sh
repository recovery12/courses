#!/bin/bash
#This script is used tell whether a given pid is root's or not

if [ $# -ne 1 ]
then 
	echo "Syntax: pidr.sh <pid>"
	exit 1
fi

if [ $(ps -U root | awk '$1=="'$1'"{print $1}') ]
then
	echo "The process is root's process"
else
	echo "The process is not root's process"
fi
