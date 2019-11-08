#!/bin/bash
#This is used to replace spaces with _ in file names
if [ $# -ne 1 ]
then 
	echo -e "Sorry! I can't run the script \n Insufficient Parameters \n Check the" "\e[1;33m Syntax: rmspace.sh <filename>\e[0m"
	exit 1
fi

mv "$1" $(echo "$1" | sed "s/\ /_/g") 
