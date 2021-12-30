// junta todos os argumentos numa frase

#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
#include <string.h>
#include <ctype.h>

int main(int argc,char **argv){

    if (argc < 2){                               // num de argumentos passados
            printf("Insira argumentos! \n");
            return EXIT_FAILURE;
    }
    
    int espaco=1;                   // vai ter um espaço por argumento
    char* array=malloc(espaco);
    char frase[100];
    int index=0;

    for (int i=1; i < argc; i++){
    
        if (isalpha(argv[i][0]) ){           // isalpha() function checks if a character is an alphabet (a-z/A-Z)
        strcpy(frase,argv[i]);              // guarda cada argumento de argv[i] na frase.
    
            for (int letra=0; letra <= strlen(frase) ;letra++){
                if (letra < strlen(frase)){
                    array[index]=frase[letra];  
                    index++;
                }else{
                    array[index]=' ';
                    index++;
                }    
            }           // ignora todos os argumentos q começam por numeros
        }
    }

    printf("%s \n",array);

    return EXIT_SUCCESS;
}