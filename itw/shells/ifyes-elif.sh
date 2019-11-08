#!/bin/bash
#This script is used to print yes for {Y,y,Yes,yes,YES} and Bad argument for allothers

if [ $# -ne 1 ]
then
	echo -e "Sorry! I can't run the script \n Insufficient Parameters \n Check the" "\e[1;33m Syntax: ifyes-elif.sh <argument>\e[0m"
	exit 1
fi

if [ $1 = y ]
then
	echo "yes" 
	exit 9
elif [ $1 = Y ]
then
	echo "yes"
	exit 9
elif [ $1 = Yes ]
then
	echo "yes"
	exit 9
elif [ $1 = YES ]
then
	echo "yes"
	exit 9
elif [ $1 = yes ]
then 
	echo "yes"
	exit 9
else
	echo "Bad argument"
	exit 1
fi
