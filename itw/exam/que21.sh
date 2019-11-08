#!/bin/bash
#This script is used to remove the files with exactly with three lines excludingfiles in subdirectories,symlinks and other special files

if [ $# -ne 1 ]
then
	echo -e "Ooops! syntax error \n Check the " "\e[1;33m Syntax: que2.sh <directory>\e[0m"
	exit 1
fi

var=$(find $1 -maxdepth 1 -type f)

var1=$(wc -l $var | awk '$1=="3"{print $2}')

rm $var1
