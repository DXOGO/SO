#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main (int argc, char*argv[]){
    
    if(argc == 1){
        printf("Insira pelo menos 1 argumento!\n");
        return EXIT_FAILURE;
    }
    int valor,i,j;
    char tmp[100];
    char *tipo=getenv("SORTORDER");     // export SORTORDER=0(crescente) / 1(decrescente)

    if( strcmp(tipo,"0")== 0){          // strcmp returns 0 if both strings match, neste caso, se SORTORDER=0
        printf("Ordenação crescente \n");
        
        for( i = 1 ; i < argc-1 ; i++){
            
            for ( j=i+1 ; j < argc-1 ; j++){
                
                valor=strcmp(argv[i],argv[j]);      // compara argumentos para ordenar
                if(valor > 0){              // se o valor>0 ent argv[i] vem depois de argv[j] (alfabeticamente)
                    strcpy(tmp,argv[i]);            // strcpy guarda argv[i] em tmp
                    strcpy(argv[i],argv[j]);        // strcpy guarda argv[j] em argv[i]
                    strcpy(argv[j],tmp);            // strcpy guarda tmp em argv[i]
                }
            }
       }
    }
    else{
        printf("Ordenação decrescente \n");
        
        for( i = 1 ; i < argc-1 ; i++){
            
            for ( j=i+1 ; j < argc-1 ; j++){
            
                valor=strcmp(argv[i],argv[j]);;
                if(valor < 0){               // se o valor<0 ent argv[i] vem antes de argv[j] (alfabeticamente)
                    strcpy(tmp,argv[i]);
                    strcpy(argv[i],argv[j]);
                    strcpy(argv[j],tmp);
                    i=0;
                }
            }
        }
    }
    for( i = 1 ; i < argc; i++){
        printf("%s \n",argv[i]);
    }




    return EXIT_SUCCESS;
}