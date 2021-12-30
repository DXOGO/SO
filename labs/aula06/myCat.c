#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
/* SUGESTÂO: utilize as páginas do manual para conhecer mais sobre as funções usadas:
 man fopen
 man fgets
*/

#define LINEMAXSIZE 80 /* or other suitable maximum line size */


int main(int argc, char *argv[])
{
    FILE *fp = NULL;
    char line [LINEMAXSIZE];        // definir

    /* Validate number of arguments -------------------------------*/
    if( argc <= 1 )
    {
        printf("USAGE: %s fileName\n", argv[0]);
        return EXIT_FAILURE;
    }
    int i;
    /* Open the file provided as argument -------------------------*/ 
    for (i=1 ; i < argc ; i++){
        int linha=1;
        printf("reading %s...\n",argv[i]);      //dar print do nome do ficheiro
        errno = 0;
        
        fp = fopen(argv[i], "r");       // argv[i] -> 1º argumento (ficheiro .txt)

        if( fp == NULL )
        {
            perror ("Error opening file");     // verificaçao de erro de ficheiro (nao existir), mostra a msg antes da msg de erro
            return EXIT_FAILURE;
        }

        /* Read all the lines of the file -------------------------*/
        
        int linhaFull=1;
        while(fgets(line, sizeof(line), fp))      // line -> pointer to an array of chars where the string read is stored 
        {                                         // ler todas as linhas do ficheiro
            if(linhaFull){              //se a linha se mostra numa linha da print normal
               printf("%d-> ",linha);
               linhaFull=0;
            }

            if( line[strlen(line)-1] == '\n'){  // se a linha é demasiado grande mostra ate ao fim da linha e muda de linha
               linhaFull=1;                     // nao mudando o valor da linha atual
                linha++;
            }
            printf(" %s", line); /* not needed to add '\n' to printf because fgets will read the '\n' that ends each line in the file */
           
        }
        fclose(fp);
    }
    return EXIT_SUCCESS;
}
