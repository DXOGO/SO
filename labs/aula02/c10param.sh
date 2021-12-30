#!/bin/bash
# crie 10 ficheiros em que o nome que aparece antes dos números é um parâmetro do script, ou seja 'c10param.sh abc' cria os ficheiros abc00.dat até abc09.dat.

touch $10{0..9}.dat
echo "Files created successfully!"
