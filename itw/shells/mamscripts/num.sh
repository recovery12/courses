#!/bin/bash

if [ $# -ne 1 ]
then
	echo "Usage: num.sh <digit>"
	exit 1
fi

case $1
in
	0) echo zero;;
	1) echo one;;
	2) echo two;;
	3) echo three;;
	4) echo four;;
	5) echo five;;
	6) echo six;;
	7) echo seven;;
	8) echo eight;;
	9) echo nine;;
	*) echo "Bad argument"
		exit 2;;
esac

