#!/bin/bash

lista=( $(seq 2 3 15))		# de 2 a 15 de 3 em 3 (2, 5, 8, 11, 14)

echo vals ${lista[@]}		# mostrar valores
echo count ${#lista[@]}		# contar quantos valores dentro do array (são 5)
echo index ${!lista[@]}		# mostrar os index (0,1,2,3,4)

for ((i = 0; i < ${#lista[@]}; i++)); do
	lista[i]=$((${lista[i]}+1))		# somar cada valor do array +1 e dar print do 'index: valor'
	echo "$i: ${lista[i]}"
done

unset lista[1]					# remover index 1 e 3
unset lista[3]

echo count ${#lista[@]}				# nova lista só tem 3 index em vez de 5

for i in ${!lista[@]}; do
	echo "$i: ${lista[i]}"			# print do resto dos index (index 0, 2 e 4)
done
