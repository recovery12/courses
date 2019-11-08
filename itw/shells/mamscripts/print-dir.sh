#!/bin/bash

for file in $1/*
do
	if [ -d $file ]
	then
		echo "$file is a directory"
	else
		echo "$file is not a directory"
	fi
done
