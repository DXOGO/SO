#!/bin/bash
#This script grants one or more file(s) the permission to be executed

for i in $*; do
       	chmod 755 $i
done

echo "All files were granted permission successfully!"
