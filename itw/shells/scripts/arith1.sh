#!/bin/bash
#This script is used to perform arithmetic operations such as addition,subtraction,multipication,division,powerof.
if [ $# -ne 0 ]
then 
	echo -e "\e[0;31m !!!Oooops!!! syntax error\e[0m \n \e[0;32Syntax: arith.sh"
	exit 1
fi

echo -e "\e[1;37m The arithmetic operations are: \e[0m"
echo -e "\e[0;33m 1.Addition\e[0m"
echo -e "\e[0;34m 2.Subtraction\e[0m"
echo -e "\e[0;35m 3.Multipication\e[0m"
echo -e "\e[0;36m 4.Division\e[0m"
echo -e "\e[0;37m 5.Powerof\e[0m"
read -p "Choose an arithmetic operations: " O ; clear

case $O
in
	1)read -p "Enter two values: " x y ; echo $(($x+$y));;
	2)read -p "Enter two values: " x y ; echo $(($x-$y));;
	3)read -p "Enter two values: " x y ; echo $(($x*$y));;
	4)read -p "Enter Dividend: " x ; read -p "Enter Divisor: " y ;  read -p "Enter a Scale: " s ; if [ $y -ne 0 ] ; then echo "scale=$s;$x/$y" | bc ;else echo "ZeroDivisionError" ; fi ;;
	5)read -p "Enter Base: " x ; read -p "Enter index: " y ; echo $(($x**$y));;
	*)echo -e "\e[0;31m ## Invaild Operation selected ##\e[0m \n \e[1;35m Please select the operations which were listed above\e[0m";;
esac
