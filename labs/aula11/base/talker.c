/**
 * \brief The server
 * \details This server converts strings to upper case
 * \autores : Artur Pereira e José Luís Oliveira
 */

#include "comm.h"

#include <ctype.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int main(void)
{
    /* Creating communication channel */
    servOpenComm();

    /* the service */
    MESSAGE msg;
    while(1) {
        printf("\n[client \'%d\'] Message to be sent: ", 1);
        fgets(msg.data, MSG_MAX, stdin);
        msg.size = strlen(msg.data)+1;
       
        servSend(&msg);
    }
    return 0;
}

