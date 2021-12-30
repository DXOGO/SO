#!/bin/bash
# Calculate the sum of a series of numbers.

SCORE="0"
COUNT_NUMBERS="0"
SUM="0"
MEDIA="0"

while true; do
	echo -n "Enter your score [0-10] ('q' to quit and 'r' to restart): "
	read SCORE;
	if (( "$SCORE" < "0" )) || (( "$SCORE" > "10" )); then
 		echo "Try again: "
 	elif [[ "$SCORE" == "q" ]]; then
 		echo "Sum: $SUM."
		echo "Media: $MEDIA"
 		break
	elif [[ "$SCORE" == "r" ]]; then
		echo "Reset back to 0, you can start over!"
		SCORE="0"
		COUNT_NUMBERS="0"
		SUM="0"
		MEDIA="0"
 	else
		SUM=$((SUM + SCORE))
		COUNT_NUMBERS=$((COUNT_NUMBERS + 1))
		MEDIA=$((SUM/COUNT_NUMBERS))
 	fi
done

echo "Exiting."
