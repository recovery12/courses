#!/bin/bash
#This script is used to remove the files with exactly with "n" lines excludingfiles in subdirectories,symlinks and other special files

if [ $# -ne 1 ]
then
	echo -e "Ooops! syntax error \n Check the " "\e[1;33m Syntax: rmfile-n.sh <directory>\e[0m"
	exit 1
fi

var=$(find $1 -maxdepth 1 -type f)
read -p "Enter the number of lines: " n
var1=$(wc -l $var | awk '$1=="'$n'"{print $2}')

rm $var1
