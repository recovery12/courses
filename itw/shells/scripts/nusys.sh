#!/bin/bash
#This script is used to convert value to there respective numerical systems
if [ $# -ne 0 ]
then 
	echo "Syntax: nusys.sh"
	exit 1
fi
echo -e "Select a numerical system: \n \t 1.Binary System \n \t 2.Octal System \n \t 3.Hexa-decimal System"
read -p "Select a numerical system: " n 
if [ $n -eq 1 ]
then
	read -p "Enter the binary value: " b 
	echo $((2#$b))
else
	echo "invalid binary data"
fi
