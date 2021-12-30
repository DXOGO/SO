#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

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
    //Person p;
    Person vals[100];
    /* Validate number of arguments */
    if(argc != 2)
    {
        printf("USAGE: %s fileName\n", argv[0]);
        return EXIT_FAILURE;
    }

    /* Open the file provided as argument */
    errno = 0;
    fp = fopen(argv[1], "rb");  // 'r' para ler .txt que é o 1º argumento dps de './readPeople'
    if(fp == NULL)
    {
        perror ("Error opening file!");
        return EXIT_FAILURE;
    }
    int nf=fread(vals, sizeof(Person), 100, fp);    // ler ficheiro
   for (int i=0;i <nf;i++){
       printf("Pessoa: %s com %d anos e mede %lf m \n",vals[i].name,vals[i].age,vals[i].height);
   }
   fclose(fp);
   
   fp = fopen(argv[1],"ab");    // 'ab' para escrever no .txt
   printf("Quantas pessoas mais deseja adicionar \n");
   int total;
   scanf("%d",&total);
   
   for (int i=nf;i<nf+total;i++){
        printf("Qual o nome da pessoa: \n");
        scanf(" %[^\n]", vals[i].name);
        printf("Qual a idade da pessoa: \n");
        scanf("%d",&vals[i].age);
        printf("Qual a altura da pessoa: \n");
        scanf("%lf",&vals[i].height);
   }
    for (int i=nf;i <nf+total;i++){
       Person a=vals[i];
       printf("Pessoa: %s com %d anos e mede %lf m \n",vals[i].name,vals[i].age,vals[i].height);
       fwrite(&a,sizeof(Person),1,fp);
   }

    return EXIT_SUCCESS;
}

// aqui usamos ./rp ex.txt para ler o ficheiro existente "ex.txt"
// e dá-nos a possibilidade de adicionar uma nova pessoa
// 1º escrevemos as pessoas e só depois lemos