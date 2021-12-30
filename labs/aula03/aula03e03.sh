#!/bin/bash
# This script checks the existence of a file

echo "Checking..."

if [[ -z "$1" || "$#" > 1 ]]; then	# '-z' checks if $1 is a null string and $# counts if the number of argumentes is > 1 
	echo "ERROR: Please input 1 argument."
elif [[ -e $1 ]] ; then			# '-f' checks if the file exists
        echo "$1 existe."
else
	echo "$1 não existe"
fi

if [[ -d "$1" ]]; then			# '-d' checks if $1 is a directory 
	echo "Argument $1 is a directory"			 
fi

if [[ -w "$1" ]]; then			# '-w' checks if $1 is writable	
        echo "Argument $1 is writable"
fi

if [[ -x "$1" ]]; then			# '-x' checks if $1 is executable
        echo "Argument $1 is executable"
fi

echo "...done."
