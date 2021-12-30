#!/bin/bash	

flagU=0;
flagC=0;
flagP=0;
flagS=0;
flagE=0;

flagSort=0;			# verificaçao
flagReverse=0;		# verificar default

sort="sort "
order=" -n "		# ordem por default


declare -a procs; #declarar array

message(){

	echo "         
        ----------------------------------------------- OPÇÕES VÁLIDAS ------------------------------------------------        

        ./procstat.sh <OPTION> : onde OPTION é número de segundos que serão usados para calcular as taxas de I/O

	Nota: O último argumento passado terá de ser o número de segundos obrigatoriamente!

	Filtros de procura:
                -u <OPTION> : selecionar processos pelo nome de utilizador (OPTION=user)
                -p <OPTION> : número de processos a visualizar (OPTION=number)
                -c <OPTION> : selecionar processos através de uma expressão regular (OPTION=REGEX EXPRESSION)
	
        Filtros de datas:
                -s <DATE>   : data mínima para o início do processo (MES DIA HH:HH)
	        -e <DATE>   : data máxima para o início do processo (MES DIA HH:HH)
        
        Ordenagem das colunas:
                -r	    : reverse order
                -m	    : sorts on MEM
                -t	    : sorts on RSS
                -d	    : sorts on RATER
                -w	    : sorts on RATEW

        Nota: Não pode utilizar duas ordenações ao mesmo tempo, a não ser que uma delas seja '-r'
                
        "	             
}

while getopts ":c:u:s:e:p:rmdtw" options; do
	case "${options}" in

	r) #reverse

		if [[ $flagReverse == 0 ]]; then			
			order=" -rn "								
			flagReverse=1
		else
			printf "\n	ERRO: Só pode utilizar '-r' no máximo uma vez!"
			message
			exit 1
		fi	
	;;

	u) # selecção dos processos ser realizada através do nome do utilizador
		u="${OPTARG}"

		if [[ $flagU == 1 ]]; then
			echo "ERRO: -u <OPTION> só pode ser selecionado uma vez!"
			exit 1
		fi

		flagU=1;
	;;
	
	c) #selecção dos processos a visualizar pode ser realizada através de uma expressão regular
		c="${OPTARG}"

		if [[ $flagC == 1 ]]; then
			echo "ERRO: -c <OPTION> só pode ser selecionado uma vez!"
			exit 1
		fi

		flagC=1;
	;;

	p) # número de processos a visualizar
		p="${OPTARG}"

		if [[ ! "${p}" =~ ^[0-9] ]]; then
			printf "\n	ERRO: Número de processos a mostrar inválido!"
			message	
			exit 1
		fi

		if [[ $flagP == 1 ]]; then
			printf "\n	ERRO: -p <OPTION> só pode ser selecionado uma vez!"
			message
			exit 1
		fi

		flagP=1;
	;;
	
	
	s) #data minima 
		dreg="[A-Za-z]{3} ([0-2][1-9]|[3][0-1]) ([0-1][0-9]|[2][0-4]):[0-5][0-9]"
		if [[ $OPTARG =~ $dreg ]]; then 
			flagS=1;
			dateSecondsS=$(date -d "$OPTARG" "+%s");
		
		else
			printf "\n	ERRO: Por favor escreva a data no formato 'MÊS DIA HORA' (ex: Jan 01 00:00)!"
			message
			exit 1
		fi
	;;

	e) # data máxima
		dreg="[A-Za-z]{3} ([0-2][1-9]|[3][0-1]) ([0-1][0-9]|[2][0-4]):[0-5][0-9]"
		if [[ $OPTARG =~ $dreg ]]; then 
			flagE=1;
			dateSecondsE=$(date -d "$OPTARG" "+%s");
			
		else
			printf "\n	ERRO: Por favor escreva a data no formato 'MÊS DIA HORA' (ex: Jan 01 00:00)!"
			message
			exit 1
		fi
	;;

	m) #sort na memória
		if [[ $flagSort == 0 ]]; then
			flagSort=1;
			sort+=" -k4 ";
			order=" -n "			
		else
			printf "\n	ERRO: Não se pode selecionar mais que 1 tipo de ordenação!"
			message
			exit 1
		fi
		;;
	t)	# sort on RSS

		if [[ $flagSort == 0 ]]; then
			flagSort=1;
			sort+=" -k5 ";
			order=" -n "
		else
			printf "\n	ERRO: Não se pode selecionar mais que 1 tipo de ordenação!"
			message
			exit 1
		fi
		;;
	d)	# sort on RATER

		if [[ $flagSort == 0 ]]; then
			flagSort=1;
			sort+=" -k8 ";	
			order=" -n "		
		else
			printf "\n	ERRO: Não se pode selecionar mais que 1 tipo de ordenação!"
			message
			exit 1
		fi

		;;

	w)	# sort on RATEW

		if [[ $flagSort == 0 ]]; then
			flagSort=1;
			sort+=" -k9 ";
			order=" -n "
		else
			printf "\n	ERRO: Não se pode selecionar mais que 1 tipo de ordenação!"
			message
			exit 1
		fi

		;;

	*) #colocando uma opção inválida ou não colocando um argumento onde era obrigatório, dá print da mensagem '' e termina
		printf "\n	ERRO: Por favor introduza uma expressão válida!"
		message
		exit 1
		;;
	
	esac
done
shift $((OPTIND-1))

# algumas validações

if [[ $flagSort == 1 && $flagReverse == 0 && $flagC == 0 && $flagU == 0  && $flagS == 0 && $flagE == 0 ]]; then 
	order=" -rn "
fi

if [[ $flagSort == 1 && $flagReverse == 1 && $flagC == 0 && $flagU == 0  && $flagS == 0 && $flagE == 0 ]]; then 
	order=" -n "
fi

if [[ $flagP == 1 && $flagReverse == 1 && $flagC == 0 && $flagU == 0  && $flagS == 0 && $flagE == 0 ]]; then 
	order=" -rn "
fi

if [[ $flagS == 1 && $flagE == 1 ]]; then
	if [[ "$dateSecondsS" -gt "$dateSecondsE" ]]; then	# verificar se data minima é menor q a data maxima
		printf "\n	Data mínima (-s <OPTION>) não pode ser maior que a data máxima (-e <OPTION>)!"
		message
		exit 1
	fi
fi

re='^[0-9]+([.][0-9]+)?$'
if [[ ${@: -1} =~ $re ]]; then		# verificar se o ultimo argumento é um numero 
	segundos=${@: -1}
else
	printf "\n	ERRO: Por favor introduza uma expressão válida!"
	message
	exit 1
fi

if [[ ${#@} -gt 1 ]]; then		# verificar q o unico argumento excluindo as opçoes é o $segundos
	printf "\n	ERRO: Por favor introduza uma expressão válida!"
	message
	exit 1
fi

declare -a readb; #declarar array
declare -a writeb; #declarar array
declare -a pid; #declarar array

cd /proc
for file in *[0-9] ; do
	if [ -f "$file/comm" ]; then
		if [ -f "$file/io" ]; then	
			if [ -f "$file/status" ]; then
				if [ -r "$file/io" ]; then	

					PID=$(cat $file/status | grep -w Pid | tr -dc '0-9')		
					pid+=($PID)
					READB=$(cat $file/io | grep -i "rchar" | grep -o -E '[0-9]+')
					readb+=($READB)	
					WRITEB=$(cat $file/io | grep -i "wchar" | grep -o -E '[0-9]+')
					writeb+=($WRITEB)

				fi
			fi
		fi
	fi
done

sleep $segundos
i=0;	
se=0;	# ver a quantidade de processos dentro dos parametros das datas
cc=0;	# contador para o numero de comms q contem a letras especificada pelo utilizador (usar isto com as datas)

for (( i=0; i<${#pid[@]}; i++ )); do		# para todos os processos lidos no 1º loop
	file="${pid[i]}"
	if [ -f "$file/comm" ]; then
		if [ -f "$file/io" ]; then	
			if [ -f "$file/status" ]; then
				if [ -r "$file/io" ]; then		# verificaçoes todas para se poder ler o file

						COMM=$(cat $file/comm | tr " " "_")
						VMSIZE=$(cat $file/status | grep -i "VmSize" | grep -o -E '[0-9]+')
						VMRSS=$(cat $file/status | grep -i "VmRSS" | grep -o -E '[0-9]+')
						USER=$(ps -o uname= -p "${pid[$i]}" )
						DATE=$(LC_ALL=EN_us.utf-8 ls -ld "${file}" | awk '{print $6 " " $7 " " $8 }')	
						dateSeconds=$(date -d "$DATE:00 2020" "+%s"); 	
						READB2=$(cat $file/io | grep -i "rchar" | grep -o -E '[0-9]+')
						WRITEB2=$(cat $file/io | grep -i "wchar" | grep -o -E '[0-9]+')
						RATER=$(echo "scale=2; ($READB2-${readb[$i]})/$segundos" | bc -l )
						RATEW=$(echo "scale=2; ($WRITEB2-${writeb[$i]})/$segundos" | bc -l )			

						if [[ $flagU == 1 && ! "${USER}" = "${u}" ]]; then		# verificar -u	
							i=$((i+1));
							continue							
						fi

						if [[ $flagC == 1 && ! "${COMM}" =~ ${c} ]]; then		# verificar -c
							i=$((i+1));										
							continue		
						fi
						cc=$((cc+1)) 			# c++ -> contador


						if [[ $flagS == 1 && $flagE == 1 ]]; then	# -s -e
							if [[ ( "${dateSeconds}" -lt "${dateSecondsS}" ) || ( "${dateSeconds}" -gt "${dateSecondsE}" ) ]]; then
								i=$((i+1));	
								continue;
							fi
							se=$((se+1));		# se++ -> contador
						fi

						if [[ $flagS == 1 && $flagE == 0 ]]; then	# -s
							if [[ "${dateSeconds}" -lt "${dateSecondsS}" ]]; then
								i=$((i+1));	continue;	
							fi
							se=$((se+1))
						fi

						if [[ $flagS == 0 && $flagE == 1 ]]; then	# -e
							if [[ "${dateSeconds}" -gt "${dateSecondsE}" ]]; then
								i=$((i+1));	continue;		
							fi
							se=$((se+1));		
						fi
						
						procs+=($COMM $USER $file $VMSIZE $VMRSS ${readb[$i]} ${writeb[$i]} $RATER $RATEW $DATE) 	# array q vai dar print
				fi
			fi
		fi
	fi
done

if [[ $flagP == 1 ]]; then	# se houver '-p'
	if [[  $i -lt $p ]]; then
		printf "\n	ERRO: Impossível mostrar %d processos com as opções selecionadas!" "$p"
		message; exit 1

	elif [[ $flagE == 1 ]] || [[ $flagS == 1 ]]; then	# erro se houver mais processos pedidos em -p q retornados de -s e/ou -e 
		if [[ $se -lt $p ]]; then
			printf "\n	ERRO: Impossível mostrar %d processos com as opções selecionadas!" "$p"
			message; exit 1
		fi

	elif [[ $flagC == 1 ]]; then	# erro se houver mais processos pedidos em -p q retornados de -c
		if  [[ $cc -lt $p ]]; then 
			printf "\n	ERRO: Impossível mostrar %d processos com as opções selecionadas!" "$p"
			message; exit 1
		fi
	fi
	printf "%-36s %-16s %12s %12s %11s %16s %16s %12s %12s %15s \n" "COMM" "USER" "PID" "MEM" "RSS" "READB" "WRITEB" "RATER" "RATEW" "DATE"
	printf "%-36s %-16s %12d %12d %11d %16d %16d %12s %12s     %01s %01s %01s \n" "${procs[@]}" | ${sort} ${order} | head -${p}	

else	
	printf "%-36s %-16s %12s %12s %11s %16s %16s %12s %12s %15s \n" "COMM" "USER" "PID" "MEM" "RSS" "READB" "WRITEB" "RATER" "RATEW" "DATE"					
 	if [[ $OPTIND == 1 ]]; then		# se houver só 1 argumento
		order=" -n "
		printf "%-36s %-16s %12d %12d %11d %16d %16d %12s %12s     %01s %01s %01s \n" "${procs[@]}" | ${sort} ${order} 
	
	elif [[ ! ${#procs[@]} == 0 ]]; then
		printf "%-36s %-16s %12d %12d %11d %16d %16d %12s %12s     %01s %01s %01s \n" "${procs[@]}" | ${sort} ${order} 
	else
	 	if [[ $flagU == 1 ]]; then
			printf "\n	ERRO: Utilizador '%s' não existe!" "${u}"
			message 
			exit 1	
		else
			printf "\n	ERRO: Não existem processos com os parâmetros especificados!" "${u}"
			message 
			exit 1	
 		fi
	fi
fi
