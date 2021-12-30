#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int ret;

    printf("Antes do fork: PID = %d, PPID = %d\n", getpid(), getppid());
    if ((ret = fork()) < 0) { 
        perror("erro na duplicação do processo");
        return EXIT_FAILURE;
    }
    
    if (ret > 0) {
	    sleep(1);
    	printf("\nPAI\n");
    
    } else
	    printf("\nFILHO\n");

        printf("Quem sou eu?\nApós o fork: PID = %d, PPID = %d, retorno do fork = %d\n",getpid(), getppid(), ret);

    return EXIT_SUCCESS;
}

// fork no processo filho é sempre 0
// fork no processo pai > 0 se tudo deu certo