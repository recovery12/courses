#!/bin/bash
#This script is used to display Username,Uid.Gid,Homedir,Shell,Groupname,Grouplist
if [ $# -ne 1 ]
then
	echo -e "Sorry! I can't run the script \n Insufficient Parameters \n Check the" "\e[1;33m Syntax: uidgid.sh <uid>\e[0m"
	exit 1
fi

var="$(awk -F: '$3=="'$1'"' /etc/passwd | awk -F: '{print $1 " " $3 " " $4 " " $6 " " $7}' | awk '{print $3}')"

var1="$(awk -F: '$3=="'$1'"' /etc/passwd | awk -F: '{print " Username " $1 " Userid " $3 " Groupid " $4 " Homedirectory " $6 " Shell " $7}')" 

var2="$(grep $var /etc/group | awk -F: '{print " Groupname " $1 " " $4}')"

echo $var1 $var2
