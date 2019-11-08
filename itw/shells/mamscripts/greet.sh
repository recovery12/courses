#!/bin/bash
hour=$(date | cut -c12-13)

if [ "$hour" -ge 0 -a "$hour" -le 11 ]
then
	echo "Good morning"
else
	if [ "$hour" -ge 12 -a "$hour" -le 17 ]
	then
		echo "Good afternoon"
	else
		echo "Good evening"
	fi
fi

