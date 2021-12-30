#!/bin/bash

function numeric_to_string()
{
	case "$1" in					# $1 é o 1º arg da function
		1)
			echo "Um"
			;;
		2)
			echo "Dois"
			;;
		3)
			echo "Três"
			;;
		*)
			echo "Outro numero"
	esac
	return $1
}

numeric_to_string $1					# 1º arg do script
echo "Retorno da função é $?"
