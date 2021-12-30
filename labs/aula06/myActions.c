#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 
/* SUGESTÂO: utilize as páginas do manual para conhecer mais sobre as funções usadas:
 man system
 man date
*/

int main(int argc, char *argv[])
{
    char text[1024];
    FILE *fp;
    struct tm *data_hora_atual;     
    //variável do tipo time_t para armazenar o tempo em segundos  
        time_t segundos;
    //obtendo o tempo em segundos  
    time(&segundos);  
    data_hora_atual = localtime(&segundos); 
    
    fp=fopen("command.log","a");
    fprintf(fp,"---------------------------------\n");
    fprintf(fp,"Quando foi aberto: %d-%d-%d pelas %02d:%02d \n",data_hora_atual->tm_mday,data_hora_atual->tm_mon+1,data_hora_atual->tm_year+1900,data_hora_atual->tm_hour,data_hora_atual->tm_min);

    do
    {
        printf("Command: ");                // oq tem fprintf(fp, ...) é escrito no command log
        scanf("%1023[^\n]%*c", text); 
  
        /* system(const char *command) executes a command specified in command
            by calling /bin/sh -c command, and returns after the command has been
            completed.
        */
        if(strcmp(text, "end")) {
            printf("\n * Command to be executed: %s\n", text);
            printf("---------------------------------\n");
            system(text);       // executar o argumento como como comando da shell
            fprintf(fp,"---------------------------------\n");
            time(&segundos);  
            data_hora_atual = localtime(&segundos); 
        
            fprintf(fp,"%02d:%02d:%02d\t\t$%s\n", data_hora_atual->tm_hour,data_hora_atual->tm_min,data_hora_atual->tm_sec,text);           printf("---------------------------------\n");
        }
    } while(strcmp(text, "end"));

    printf("-----------The End---------------\n");
    fprintf(fp,"---------------------------------\n");
    time(&segundos);  
    data_hora_atual = localtime(&segundos); 
    fprintf(fp,"Quando foi fechado: %d-%d-%d pelas %02d:%02d \n",data_hora_atual->tm_mday,data_hora_atual->tm_mon+1,data_hora_atual->tm_year+1900,data_hora_atual->tm_hour,data_hora_atual->tm_min);
    fclose(fp);

    return EXIT_SUCCESS;
}
