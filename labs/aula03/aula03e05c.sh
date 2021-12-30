#!/bin/bash
#FOr all the files in a folder, change their name to new_filename

if [[ $# == 1 ]]; then
	if [[ $1 == "" ]]; then
		echo "Argumentos inválidos!"
	else
		if [ -d $1 ]; then
			cd $1
			for f in *; do
				mv "$f" "new_$f"
			done
		else
			echo "Não é uma diretoria!"
		fi
	fi
else
	if [[ $2 == "-r" && $# == 2 ]]; then
		cd $1
		for f in *; do
			mv "$f" "${f#new_}"
		done
	else
		echo "Argumentos inválidos!"
	fi
fi
