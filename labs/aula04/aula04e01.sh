#!/bin/bash

function imprime_msg()
{
	echo "A minha primeira funcao"
	echo "date:" $(date) 
	echo "hostname: " $(hostname)
	echo "who am i: " $(whoami)
	return 0
}

imprime_msg
