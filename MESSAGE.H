#ifndef MESSAGE_H
#define MESSAGE_H

/*******************************/
/* Message Services prototypes */
/*******************************/

int BroadcastToConsole(char *message);
int CheckPipeStatus(byte connectionCount,byte *connections,
                     byte *pipeStatus);
int CloseMessagePipe(byte connectionCount,byte *connections,
                     byte *resultCodes);
int GetBroadcastMessage(char *message);
int GetBroadcastMode(void);
int GetPersonalMessage(char *message,byte *sourceConnection);
void LogNetworkMessage(char *message);
int OpenMessagePipe(byte connectionCount,byte *connections,
                    byte *resultCodes);
int SendBroadcastMessage( byte connectionCount,byte *connections,
                          char *message , byte *resultCodes);
int SendPersonalMessage( byte connectionCount,byte *connections,
                         char *message , byte *resultCodes);
int SetBroadcastMode(int messageMode);

#endif
