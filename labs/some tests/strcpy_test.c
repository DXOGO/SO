#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){

    char a[32];
    char b[64] = "Hello";

    strcpy(a,b);
    puts(a);

    int* py;
    int y;
    py = &y;
    *py = 45;
   printf("%d \n", y);

    return 0;
}