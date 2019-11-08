#!/bin/bash
for file in $PWD/*
do
	echo $file
	ext=$(echo $file | sed 's/.*\.//')
	echo $ext
	if [ $ext = $1 ]
	then
		file1=$(echo $file | sed "s/\.[a-z]*/\.$2/g")
		echo $file1
		mv $file $file1
	fi
done
