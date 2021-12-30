#!/bin/bash
# This script will test if we're in a leap year or not.

if [[ $# = 1 ]]; then
	year=$1			# year input
else
	year=$(date +%Y)	# if no input is added the program uses the current year
fi

if [[ $(($year % 400)) -eq 0 ]]; then 				# '-eq' checks if the remainder(%) of $year with 400 equals 0
	echo " (1) This is a leap year. February has 29 days."

elif [[ $(($year % 4)) -eq 0 ]]; then				# '-eq' checks if the remainder(%) of $year with 4 equals 0
	if [[ $(($year % 100)) -ne 0 ]]; then			# '-ne' checks if the remainder(%) of $year with 100 is not equal to 0
		echo " (2) This is a leap year, February has 29 days."
	else
		echo " (1) This is not a leap year. February has 28 days."
	fi

else
	echo " (2) This is not a leap year. February has 28 days."
fi
