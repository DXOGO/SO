#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])				        //Pai
{
    int ret;									      //Pai

    printf("Antes do fork: PID = %d, PPID = %d\n", getpid(), getppid());	      //Pai
    if ((ret = fork()) < 0) { 							  //  chamada de fork e dps operação com fork (executado por pai e filho)
        perror ("erro na duplicação do processo");		 //     caso der erro ent pai
	return EXIT_FAILURE;					            //       pois fork n tem sucesso, logo, n há child
    }
    if (ret > 0) 								           // executado por pai e filho
	    sleep (1);							              // o pai dorme
    printf("Quem sou eu?\nApós o fork: PID = %d, PPID = %d\n", getpid(), getppid());  // da print o filho e depois o pai

    return EXIT_SUCCESS;							      // acaba pai e filho
}
        // neste pc temos antes de fork -> pid=308 e ppid=296
        // depois do fork este em cima torna-se pai e forma uma child, logo, child -> pid=309 e ppid=308
        // e continuando depois do fork e dps de sleep da print do parent -> pid=308 e ppid=296
        // sleep para dar print primeiro da child e dps no parent
