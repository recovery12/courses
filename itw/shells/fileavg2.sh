#!/bin/bash
#This file is used to print file name and average of second column
if [ $# -ne 1 ]
then
	echo -e "Sorry! I can't run the script \n Insufficient Parameters \n Check the" "\e[1;33m Syntax: fileavg2.sh <directory>\e[0m"
	exit 1
fi

for file in $1*
do

	awk '{sum+=$2} END {print "'$file'",sum/NR}' $file 

done
