#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <getopt.h>
#include <string.h>

void listDir(char dirname[],char e[],int d,int f){
        
        DIR *dp;
        struct dirent *dent;
        char *thisE=strtok(e,".");
        char *token;
        dp=opendir(dirname);
        if (dp ==NULL){
            printf("Erro a abrir diretoria!\n");
            return ;
        }
        dent =readdir(dp);
        while (dent != NULL){
            if( dent->d_name[0] != '.' ){
                if (e[0] == '.'){
                    if (dent->d_type != 4){
                        if (strstr(dent->d_name,".")){
                        token=strtok(dent->d_name,".");
                        token=strtok(NULL,".");
                        if (strcmp(token,thisE)==0){
                            printf("O ficheiro %s  tem a extensao %s\n", dent->d_name,e);
                        }
                        
                    }
                  }
                }
                if (d){
                    if(dent->d_type ==4){
                        printf("Diretoria  chamada %s\n",dent->d_name);
                    }
                }
                if (f && e[0]!='.'){
                    if( dent->d_type !=4){
                         printf("Ficheiro   %s\n",dent->d_name);
                    }
                }
                if( f==0 && d==0 && e[0]!='.'){
                    printf(" %s \n",dent->d_name);
                }
            }
                dent=readdir(dp);
        }



}

int main(int argc,char *argv[]){
    if (argc ==1){
        printf("Insira arguemntos! \n");
        return EXIT_FAILURE;
    }
    int opt;
    int opt_index=0;
    struct option long_options[]={
            { "dir", no_argument,0,'d'},
            { "ext", required_argument,0 ,'e'},
            { "file", no_argument,0,'f'}
    };
    int controlo_f=0;
    int controlo_d=0;
    char controlo_e[100];
    while( (opt=getopt_long(argc,argv,"fde:",long_options,&opt_index)) != -1){
        switch(opt){
            case 'f':
                    controlo_f=1;
                    printf("Escolheu a opção f\n");
                    break;
            case 'd':
                    controlo_d=1;
                    printf("Escolheu a opção d\n");
                    break;
            case 'e':
                    strcpy(controlo_e,optarg);
                    printf("Escolheu a opção e com argumento %s \n",controlo_e);

                    break;
            default: /* '?' */
                 return EXIT_FAILURE;
        }
    }
       if (optind < argc)
    {
        fprintf(stderr, "Expected argument after options\n");
        return EXIT_FAILURE;
    }
    listDir("./",controlo_e,controlo_d,controlo_f);
    return EXIT_SUCCESS;
}