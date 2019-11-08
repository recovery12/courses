#!/bin/bash
#This script is used to print yes for {Y,y,yes,Yes,YES} and Bad argument for allothers

if [ $# -ne 1 ]
then
	echo -e "Sorry! I can't run the script\n Insufficient Parmeters \n Check the" "\e[1;33m Syntax: ifyes.sh <argument>\e[0m"
	exit 1
fi

case $1
in	
	y) echo yes;exit 9;;
     	Y) echo yes;exit 9;;
	YES) echo yes;exit 9;;
	Yes) echo yes;exit 9;;
	yes) echo yes;exit 9;;
	*) echo "Bad argument"
	       	exit 1;;
esac	
