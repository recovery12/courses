#!/bin/bash
#This script is used to print no of files consisting a particular string in a directory
if [ $# -ne 2 ]
then
	echo -e "Sorry! I can't run the script \n Insufficient Parameters \n Check the " "\e[1;33m Syntax: printf.sh <string> <directory>\e[0m"
	exit 1
fi

 grep -rnl $2 -e $1 | awk -F/ '{print $NF}' ; grep -rnl $2 -e $1 | awk -F/ '{print $NF}' | echo "Total no of files are" $(wc -l)
