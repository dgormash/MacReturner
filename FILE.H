#ifndef FILE_H
#define FILE_H

/****************************/
/* File Services prototypes */
/****************************/

int EraseFiles( byte searchAttributes,byte directoryHandle,char *filePath);
int PurgeAllErasedFiles(void);
int PurgeErasedFiles(void);
int ScanFileInformation(byte directoryHandle, char *filePath,
     byte searchAttributes,int *sequenceNumber,char *fileName,
     byte *fileAttributes,byte *extendedFileAttributes,long *fileSize,
     char *creationDate,char *lastAccessDate,char *lastUpdateDateAndTime,
     char *lastArchiveDateAndTime,long *fileOwnerId);
     
#endif
