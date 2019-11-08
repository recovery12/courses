#!/bin/bash
#This script is used to tell filename,size,number of lines in descending order

if [ $# -ne 2 ]
then
	echo -e "Sorry! I can't run the script \n Insufficient Parameters \n Check the" "\e[1;33m Syntax: list.ext.sh <directoryname> <extension>\e[0m"
	exit 1
fi

for file in $1*.$2
do
 
	echo $(du -b $file | awk '{print $1}') $(wc -l $file) 

done | sort -k2nr
