#!/bin/bash -x
#This script is used to know whether a process is running or not
if [ $# -ne 1 ]
then 
	echo -e "Sorry! I can't run the script \n Insufficient Parameters \n Check the" "\e[1;33m Syntax: pid.sh <pid>\e[0m"
	exit 1
fi


if [ $(ps --pid $1 | awk '{print $1}' | grep $1) ]
then
	echo "Process is running"
read -p "Enter duration time for sleep: " v
sleep $v

if [ $(ps --pid $1 | awk '{print $1}' | grep $1) ]
then
	echo "Process is running"
else
	echo "Process is not running"
fi

else
	echo "Process is not running"
fi
