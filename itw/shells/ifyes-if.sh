#!/bin/bash
#This script is used to print yes for {Y,y,yes,Yes,YES} and Bad argument for allothers

if [ $# -ne 1 ]
then
	echo -e "Sorry! I can't run the script\n Insufficient Parmeters \n Check the" "\e[1;33m Syntax: ifyes-elif.sh <argument>\e[0m"
	exit 1
fi

if [ "$1" = y -o "$1" = Y -o "$1" = Yes -o "$1" = YES -o "$1" = yes ] 
then
       	echo "yes" 
       	exit 9
else 
	echo "Bad argument" 
       	exit 1
fi
