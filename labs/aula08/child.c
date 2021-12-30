#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("Filho: PID = %d, PPID = %d\n", getpid(), getppid());
    sleep(3);
    printf("Filho: PID = %d, PPID = %d\n", getpid(), getppid());
    // PPID no 2º print é 1 pois o parent ja morreu, ou seja ele é adotado pelo systemd
    return EXIT_SUCCESS;
}
