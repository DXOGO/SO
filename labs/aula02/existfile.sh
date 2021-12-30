#!/bin/bash
# recebe como argumento o nome de um ficheiro, que pode existir ou não, e imprime o código de saída do comando file para esse ficheiro.

file=$1
if [ -f $file ]; then
   echo "Exit code: 0"
else
   echo "Exit code: 1"
fi
