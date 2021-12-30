#include <stdio.h>
#include <stdlib.h>

/* SUGESTÂO: utilize as páginas do manual para conhecer mais sobre as funções usadas:
 man qsort
*/
#define MAXSIZE 80
int compareInts(const void *px1, const void *px2)
{
    int x1 = *((int *)px1);
    int x2 = *((int *)px2);
    return(x1 < x2 ? -1 : x1 == x2 ? 0 : 1);
}

int main(int argc, char *argv[])
{
    int i=0;
    int *numbers;
    char line[MAXSIZE];

    /* Memory allocation for all the numbers in the arguments */
 
    FILE  *fp;
    fp=fopen(argv[1],"r");      //1º argumento (ficheiro.txt)
    if (fp == NULL){
        perror ("Error opening file!");
        return EXIT_FAILURE;
    }
    numbers = (int *) malloc(sizeof(int) * 2);
    while( fscanf(fp,"%d",&numbers[i]) == 1){           // aqui usamos fscanf
        i++;   
        numbers = (int *) realloc(numbers,sizeof(int) *(i+2) );
    }
    /* void qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *)); 
         The qsort() function sorts an array with nmemb elements of size size.*/
    qsort(numbers, i, sizeof(int), compareInts);

    /* Printing the sorted numbers */
    printf("Sorted numbers: \n");
    int j;
    for(j = 0 ; j < i ; j++)
    {
        printf("%d\n", numbers[j]);
    }

    return EXIT_SUCCESS;
}
