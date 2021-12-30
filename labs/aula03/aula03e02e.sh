#!/bin/bash
# This script tells if an input number is greater/smaller than 5 and greater/smaller than 10

if (($1 > 5)) && (($1 < 10)); then
	echo "$1 is greater than 5 and smaller than 10"
elif (($1 < 5)); then
        echo "$1 is smaller than 5 and smaller than 10"
elif (($1 > 10)); then
        echo "$1 is greater than 5 and greater than 10"
elif (($1 == 5)) || (($1 == 10)); then
	echo "argument $1 is the same number $1"
fi
