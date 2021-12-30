/**
 *  \file sharedMemory.c (implementation file)
 *
 *  \brief Shared memory management.
 *
 *   Operations defined on shared memory:
 *      \li creation of a new block
 *      \li connection to a previously created block
 *      \li destruction of a previously created block
 *      \li mapping of the block previously created on the process address space
 *      \li unmapping of the block off the process address space.
 *
 *  \author António Rui Borges 
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/shm.h>

/** \brief access permission: user r-w */
#define  MASK           0600    /* base de 0 6 = 110, 0 = 000, 0 = 000
                                                 rwx      rwx      rwx
                                                  u        g        o
 *  \brief Creation of a new block.
 *
 *  The function fails if there is already a block of shared memory with a creation key equal to <tt>key</tt>.
 *
 *  \param key creation key
 *  \param size block size (in bytes)
 *
 *  \return block identifier, upon success
 *  \return -\c 1, when an error occurs (the actual situation is reported in <tt>errno</tt>)
 */

int shmemCreate (int key, unsigned int size)
{
    return shmget ((key_t) key, size, MASK | IPC_CREAT | IPC_EXCL);
}

/**
 *  \brief Connection to a previously created block.
 *
 *  The function fails if there is no block with a creation key equal to <tt>key</tt>.
 *
 *  \param key creation key
 *
 *  \return block identifier, upon success
 *  \return -\c 1, when an error occurs (the actual situation is reported in <tt>errno</tt>)
 */

int shmemConnect (int key)
{
    return shmget ((key_t) key, 1, MASK);
}

/**
 *  \brief Destruction of a previously created block.
 *
 *  The function fails if there is no block with an identifier equal to <tt>shmid</tt>.
 *
 *  \param shmid block identifier
 *
 *  \return \c 0, upon success
 *  \return -\c 1, when an error occurs (the actual situation is reported in <tt>errno</tt>)
 */

int shmemDestroy (int shmid)
{
    return shmctl (shmid, IPC_RMID, (struct shmid_ds *) NULL);
}

/**
 *  \brief Mapping of the block previously created on the process address space.
 *
 *  The function fails if there is no block with an identifier equal to <tt>shmid</tt>.
 *
 *  \param shmid block identifier
 *  \param pAttAdd pointer to the location where the local address of the attached block is stored
 *
 *  \return \c 0, upon success
 *  \return -\c 1, when an error occurs (the actual situation is reported in <tt>errno</tt>)
 */

int shmemAttach (int shmid, void **pAttAdd)
{
    void *add;                                                                                    /* temporary pointer */

    add = shmat (shmid, (char *) NULL, 0);
    if (add != (void *) -1) { 
        *pAttAdd = (void *) add;
        return 0;
    }
    else return 1;
}

/**
 *  \brief Unmapping of the block off the process address space.
 *
 *  The function fails if the pointer does not locate a region of the address space
 *  where a mapping took previously place.
 *
 *  \param attAdd local address of the attached block
 *
 *  \return \c 0, upon success
 *  \return -\c 1, when an error occurs (the actual situation is reported in <tt>errno</tt>)
 */

int shmemDettach (void *attAdd)
{
    return shmdt (attAdd);
}




/*
SYSTEM V IPC
    -> semaforos ou arrays de semaforos
    -> segmentos de memória partilhada
    -> sincronizaçao + comunicaçao --- filas de mensagens (receção de uma msg pode ser um processo bloqueante)
    -> segmento de memoria partilhada existe smp independentemente se tem ou não processos lá, só são removidos
       do sistema se for explicitamente pedido por um dos processos

    shm -> shared memory
    sem -> semaphore
    msg -> fila de mensagens

    #include <sys/ipc.h>
    #include <sys/shm.h>  
    
------------------------------------------------------------------------------------------------------------  
                                                                                            u   g   o
                                                                              > permissões rwx|rwx|rwx
                                identificador externo shm       ------------- > IPC_CREATE - criar shm
    ident. interno smh  <                |                      |             > IPC_EXCL - garante criação
     (-1 se erro)       |                |                      |
                        int shmget(key_t key, size_t size, int shmflg);
                            |                         |
                            |                         |
shmget - allocates a System V shared memory segment   > tamanho (bytes) do shm  
          (criar ou aceder a segmentos shm)

-------------------------------------------------------------------------------------------------------------

         cshmctl - System V  <     identificador interno smh
      shared memory control  |            |                               > dependente de cmd
                             |            |                               |
                        int shmctl(int shmid, int cmd, struct shmid_ds *buf);
                                                    |
                             comando (ex: IPC_RMID) <

-------------------------------------------------------------------------------------------------------------

                        retorno de smhget <                   > pedido para o endereço de mapeamento
                                          |                   |
                        void *shmat(int shmid, const void *shmaddr, int shmflg);
                         |                                                |
                         |______________________                          > flags
                                                |
                        int shmdt(const void *shmaddr);

*/  