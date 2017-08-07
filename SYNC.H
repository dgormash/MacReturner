#ifndef SYNC_H
#define SYNC_H

/***************************************/
/* Synchronisation Services prototypes */
/***************************************/

int CloseSemaphore( long semaphoreHandle );
int ExamineSemaphore( long semaphoreHandle,int *semaphoreValue,
    word *openCount);
int OpenSemaphore( char *semaphoreName,int initialValue,long *semaphoreHandle,
    word *openCount);
int SignalSemaphore( long semaphoreHandle );
int WaitOnSemaphore( long semaphoreHandle , int timeoutLimit );
                     
#endif
