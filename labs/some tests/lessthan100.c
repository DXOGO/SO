#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>

int main(int argc, char **argv){
    //printf("# arguments: %d\n", argc);
    //printf("11 %s\n", argv[2]);
    //printf("12 %d\n", atoi(argv[3]));

    //int i;
    //for (int i = 1; i < argc; i++){
    //  printf("%d\n", atoi(argv[i]));
    //  if (atoi(argv[i]) >= 100){
    //      printf("%d\n", atoi(argv[i]));
    //  }
    //}

    int min=0, max=0, opt=0;
    int minFlag=0;
    int maxFlag=0;

    while ((opt = getopt(argc, argv, "n:x:")) != -1 ){
        switch (opt)
        {
        case 'n':
            minFlag = 1;
            min = atoi(optarg);
            break;
        case 'x':
            maxFlag = 1;
            max = atoi(optarg);
            break;
        default:
            printf("Algo errado!\n");
            return EXIT_FAILURE;
            break;
        }
    }

    for (int i = 1 ; i < argc ; i++){
        if (minFlag & maxFlag ){ // se -n e -x estao ativos
            if (atoi(argv[i]) > min && atoi(argv[i]) < max){
                printf("%d \n", atoi(argv[i]));
            }
        }else if (minFlag){
            if (atoi(argv[i]) > min){
                printf("%d \n", atoi(argv[i]));
            }
            
        }else if (maxFlag){
            if (atoi(argv[i]) < max){
                printf("%d \n", atoi(argv[i]));
            }
        }else{
            printf("%d \n", atoi(argv[i]));
        }
    }
    return EXIT_SUCCESS;
}