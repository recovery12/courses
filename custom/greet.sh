#!/bin/bash
hour=$(date | cut -c12-13)

if [ "$hour" -ge 0 -a "$hour" -le 11 ]
then
	echo "Good morning Master Anurag"
elif [ "$hour" -ge 12 -a "$hour" -le 17 ]
then
	echo "Good afternoon Master Anurag"
else
	echo "Good evening Master Anurag"
fi

