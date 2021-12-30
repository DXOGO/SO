#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    fork();
    fork();

    printf("Hello \n");      // vai dar print do "Hello 4x" (2 para o 1º pai e filho e mais 2 para o 2º pai e filho)
}