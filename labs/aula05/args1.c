#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int i;

    for(i = 0 ; i < argc ; i++)
    {
       if ( argc <= 3 ){
            printf("Argument %02d: \"%s\"\n", i, argv[i]);          
        }
        else {
            printf("ERROR! Can only output 3 arguments, you used %0d! \n", argc);
            return EXIT_SUCCESS;
        }
    }

    return EXIT_SUCCESS;
}