#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
typedef struct
{
    int age;
    double height;
    char name[64];
} Person;

void printPersonInfo(Person *p)
{
    printf("Person: %s, %d, %f\n", p->name, p->age, p->height);
}

int main (int argc, char *argv[])
{
    FILE *fp = NULL;
    int i;

    /* Validate number of arguments */
    if(argc != 2)
    {
        printf("USAGE: %s fileName\n", argv[0]);
        return EXIT_FAILURE;
    }


    /* Open the file provided as argument */
    errno = 0;
    fp = fopen(argv[1], "wb");  // 'wb' criar ficheiro p escrita
    if(fp == NULL)
    {
        perror ("Error opening file!");
        return EXIT_FAILURE;
    }
    printf("Quantas pessoas deseja guardar: \n");
    int total;
    scanf("%d",&total); // pessoa especifica qts pessoas quer adicionar
    Person p;
    /* Write 'total' itens on a file */
    for(i = 0 ; i < total ; i++)
    {   
        printf("Qual o nome da pessoa: \n");
        scanf(" %[^\n]",p.name);
        printf("Qual a idade da pessoa: \n");
        scanf("%d",&p.age);
        printf("Qual a altura da pessoa: \n");
        scanf("%lf",&p.height);
        fwrite(&p, sizeof(Person), 1, fp);         // guardar valores no ficheiro
    }

    fclose(fp);

    return EXIT_SUCCESS;
}

// aqui definimos um nº de pessoas e dispomos informação sobre cada uma
// usamos ./wp ex.txt para criar um ficheiro "ex.txt" que guarda
// em valor binario o resultado de writePeople.c