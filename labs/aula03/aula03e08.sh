#!/bin/bash
# select structure to create menus
PS3="> "

select arg in $@; do
	
	echo "You picked $arg ($REPLY)."

done

