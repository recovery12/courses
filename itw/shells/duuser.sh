#!/bin/bash
#this script is used to find size of the user

if [ $# -ne 2 ]
then
	echo -e "Sorry! I can't run the script \n Insufficient Parameters \n Check the" "\e[1;33m Syntax: duuser.sh <username> <bytesize>\e[0m"
	exit 1
fi

if [ $(du -b $1 | awk 'END{print}' | awk '{print $1}') -ge $2 ]
then
	echo -e "\e[1;31m "WARNING: Disk usage exceeding $2"\e[0m"
else
	echo -e "\e[1;32m "Disk usage within $2"\e[0m"
fi
