#ifndef CONNECT_H
#define CONNECT_H

/**********************************/
/* Connection Services prototypes */
/**********************************/

int AttachToFileServer(char *serverName);
int DetachFromFileServer(char *serverName);
int EnterLoginArea(int numberOfLocalDrives,char *loginDirectoryName);
int GetConnectionInformation(word connectNo,char *objectName,
     word *objectType,long *objectID,byte *loginTime);
int GetConnectionNumber(void);
int GetInternetAddress(int conn_no,byte *networkNumber,
                       byte *nodeAddress,word *socketNumber);
int GetObjectConnectionNumbers(word objType,char *objName,
     word *connectionCount,byte *connections);
void GetStationAddress(byte *physicalNodeAddress);
int LoginObjectEncrypted(word objectType,char *objectName,
                         byte *encryptedPassword);
int LoginToFileServer(word objectType,char *objectName,
     char *objectPassword);
void LogoutFromFileServer(char *serverName);
void Logout(void);

#endif
