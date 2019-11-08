#!/bin/bash
#This script is used to convert the input into stars
if [ $# -ne 0 ]
then
	echo "Synatx: pass.sh"
fi

#unset password;
while IFS= read -r -s -n1 pass; do
  if [[ -z $pass ]]; then
     echo
     break
  else
     echo -n '*'
     password+=$pass
  fi
done 


