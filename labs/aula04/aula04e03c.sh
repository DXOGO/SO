#!/bin/bash
# script to read numbers from a file and sort them


while read line; do
	[[ $line =~ ^[0-9]+$ ]] && a+=($line)	# como criar array 'a' com os valores de cada linha do ficheiro
done < "$1"

for (( i=0; i < ${#a[@]}; i++ )); do		# while i < nº de valores lidos no 'a' 
	min=$i
	for (( j = i+1; j < ${#a[@]}; j++ )); do
		if (( a[j] <= a[min] )); then
      			min=$j		
		fi
	done
	temp=${a[i]}
	a[i]=${a[min]}
	a[min]=$temp
done

for i in "${a[@]}"
do
	echo "$i"
done


