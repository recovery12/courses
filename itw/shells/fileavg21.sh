#!/bin/bash
if [ $# -ne 1 ]
then
	echo "Syntax: fileavg.sh <directory>"
	exit 1
fi

for file in $1*
do

paste <(echo $file) <(awk '{sum+=$2} END {print  sum/NR}' $file)

done
