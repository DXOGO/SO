#!/bin/bash
# For all the files in a folder, show their properties


#for f in $1/*; do
#	if [[ ! -d "$1" || "$#" > 1 ]]; then
#		echo "ERROR: Please input only one argument that is a directory"
#	else
#		if [[ -z "$1" || -d "$1" ]];then
#			file "$f"
#		fi
#	fi
#done

for f in $1/*; do
        if [[ -d "$1" || -z "$1" ]]; then
		if [[ "$#" > 1 ]]; then
			echo "ERROR: Too many arguments!"
		else
			file "$f"
		fi
	else
		echo "ERROR: Please input a directory!"
        fi
done

