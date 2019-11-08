#!/bin/bash
#This script is used to paste the last two columns of First file to corresponding lines of second file
if [ $# -ne 2 ]
then 
	echo -e "Sorry I can't run the script \n Insufficient Parameters \n Check the" "\e[1;33m Syntax: paste.sh <Firstfile> <Secondfile>\e[0m"
	exit 1
fi

 awk '{print $(NF-1) " " $NF}' $1 | paste -d" " $2 - > paste.out && mv paste.out $2




















