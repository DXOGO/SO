#!/bin/bash
# Compare 2 numbers and check if they're equal, if not then print the biggest

function compareint()
{
	if (($1<$2)); then
		return 2
	elif (($1==$2)); then
		return 1
	else
		return 0
	fi
}

read n1 n2
compareint $n1 $n2

case $? in 
	0) 
		echo "$n1 is bigger"
		;;	
	1)	
		echo "Equal"
		;;
	2)
		echo "$n2 is bigger"
		;;
esac
