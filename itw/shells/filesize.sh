#!/bin/bash
#This script is used to check the file size

if [ $# -ne 2 ]
then
	echo -e "Sorry! I can't run the script \n Insufficient Parameters \n Check the" "\e[1;33m Syntax: filesize.sh <directory> <bytesize>\e[0m"
	exit 1
fi

for file in $1/*
do 
       if [ $(du -b $file | awk '{print $1}') -ge $2 ]
       then
	      ls -lh $file  
       else
             echo "it is a smaller file than $2 "
       fi
done 
