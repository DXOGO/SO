#!/bin/bash
#This script opens 4 terminal windows.

i="0"
#while [[ $i -lt 4 ]]; do		# while 'i' is less than (same as $i < 4) open a terminal window and i++
#	xterm & i=$(($i+1))             # basicamente abre um terminal em i=0, i=1, i=" e i=3 
#done

until [[ $i -eq 4 ]]; do		# faz o mesmo que a função anterior
	xterm & i=$(($i+1))		# fazer o que está dentro da função 'until' $i = 4
done
