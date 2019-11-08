#!/bin/bash
#This script is used to change the extension of the files
if [ $# -ne 3 ]
then
	echo -e "!!Oooops!! Bad Syntax \n check the Syntax: rename-ext.sh <filename> <old-ext> <new-ext>"
	exit 1
fi
mv "$1" $(echo "$1" | sed -n "s/\.'$2'/\.'$3'/")
