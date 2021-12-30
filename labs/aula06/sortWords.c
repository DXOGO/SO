#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main (int argc, char*argv[]){
    if(argc ==1){
        printf("DEVE INSERIR ARGUMENTOS\n");
        return EXIT_FAILURE;
    }
    int valor,i,j;
    char tmp[100];
    char *tipo=getenv("SORTORDER");
    if( strcmp(tipo,"0")== 0){
        printf("Ordenação crescente \n");
        for( i=1;i<argc-1;i++){
            for (j=i+1;j<argc-1 ; j++){
            valor=strcmp(argv[i],argv[j]);
            if(valor >0){
               strcpy(tmp,argv[i]);
               strcpy(argv[i],argv[j]);
               strcpy(argv[j],tmp);
            }
        }}
    }
    else{
        printf("Ordenação decrescente \n");
        for( i=1;i<argc-1;i++){
            for (j=i+1;j<argc-1 ; j++){
            valor=strcmp(argv[i],argv[j]);
            if(valor <0){
                strcpy(tmp,argv[i]);
               strcpy(argv[i],argv[j]);
               strcpy(argv[j],tmp);
               i=0;
            }
        }
        }
    }
    for( i=1;i<argc;i++){
        printf("%s \n",argv[i]);
    }




    return EXIT_SUCCESS;
}