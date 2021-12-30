#!/bin/bash
# Agrupamento de comandos na Bash
# le argumentos de um ficheiro
{
   i=0
   while read line; do
      echo $i: $line
      i=$(($i+1))
   done
} < $1		# 1º argumento
