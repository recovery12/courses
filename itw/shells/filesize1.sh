#!/bin/bash
#This script is used to list which are bigger than a given a value
if [ $# -ne 2 ]
then
	echo -e "Sorry! I can't run the script \n Insufficient Parameters \n Check the" "\e[1;33m Syntax: filesize.sh <directory> <bytesize>\e[0m"
	exit 1
fi

var=$(find $1 -maxdepth 1 -type f)
du -b $var | awk '{if($1 > '$2') print $0;else echo "its a small file"fi}'
