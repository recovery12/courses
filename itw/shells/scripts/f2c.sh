#!/bin/bash
#This script converts given fahrenheit to celsius
if [ $# -ne 0 ]
then 
	echo "Syntax: f2c.sh"
fi

read -p "Fahrenheit value: " f
read -p "Precision point: " p
var=$(($f-32))
echo "scale=$p;$var/1.8" | bc
