#ifndef DIRECT_H
#define DIRECT_H

/*********************************/
/* Directory Services prototypes */
/*********************************/

typedef struct {
   word    buffer_length;
   nw_long system_elapsed_time;
   byte    volume_number;
   byte    logical_drive_number;
   nw_int  sectors_per_block;
   nw_int  starting_block;
   nw_int  total_blocks;
   nw_int  available_blocks;
   nw_int  total_directory_slots;
   nw_int  available_directory_slots;
   nw_int  max_used_dir_entries;
   byte    volume_is_hashed;
   byte    volume_is_cached;
   byte    volume_is_removable;
   byte    volume_is_mounted;
   char    volume_name[17];
   } VOLUME_STATISTICS;         /* GetVolumeInformation */

int AddTrusteeToDirectory(byte directoryHandle,char *directoryPath,
     long trusteeObjectID,byte trusteeRightsMask);
int AllocPermanentDirectoryHandle(byte directoryHandle,char *directoryPath,
     char driveLetter,byte *newDirectoryHandle,byte *effectiveRightsMask);
int AllocTemporaryDirectoryHandle(byte directoryHandle,char *directoryPath,
     char driveLetter,byte *newDirectoryHandle,byte *effectiveRightsMask);
int CreateDirectory(byte directoryHandle,byte maximumRightsMask,
     char *directoryPath);
int DeallocateDirectoryHandle(byte directoryHandle);
int DeleteDirectory(byte directoryHandle,char *directoryPath);
void DeleteFakeRoot(byte drive);
int DeleteTrusteeFromDirectory(byte directoryHandle,char *directoryPath,
     long trusteeObjectID);
int GetCurrentDirectory(char driveNumber,char *directoryPath);
int GetDirectoryHandle(char driveNumber,byte *statusFlags);
int GetDirectoryPath(byte directoryHandle,char *directoryPath);
int GetEffectiveDirectoryRights(byte directoryHandle,char *directoryPath,
     byte *effectiveRights);
int GetVolumeInformation(byte volumeNumber,VOLUME_STATISTICS *replyBuffer);
int GetVolumeInfoWithHandle(byte directoryHandle,char *volumeName,
     word *sectorsPerBlock,word *totalBlocks,
     word *availableBlocks,word *totalDirectorySlots,
     word *availableDirectorySlots,int *volumeIsRemovable);
int GetVolumeInfoWithNumber(byte volumeNumber,char *volumeName,
     word *sectorsPerBlock,word *totalBlocks,
     word *availableBlocks,word *totalDirectorySlots,
     word *availableDirectorySlots,int *volumeIsRemovable);
int GetVolumeName(int volumeNumber,char *volumeName);
int GetVolumeNumber(char *volumeName,int *volumeNumber);
int MapFakeRoot(byte drive,char *path);
int ModifyMaximumRightsMask(byte directoryHandle,char *directoryPath,
     byte revokeRightsMask,byte grantRightsMask);
int RenameDirectory(byte directoryHandle,char *directoryPath,
     char *newDirectoryName);
int RestoreDirectoryHandle(char *saveBuffer,byte *newDirectoryHandle,
     byte *effectiveRightsMask);
int SaveDirectoryHandle(byte directoryHandle,char *saveBuffer);
int ScanBinderyObjectTrusteePaths(long objectID,byte volumeNumber,
     int *sequenceNumber,char *trusteeAccessMask,char *trusteePathName);
int ScanDirectoryForTrustees(byte directoryHandle,
     char *directoryPath,int *sequenceNumber,char *directoryName,
     char *creationDateTime,long *ownerID,long *trusteeID,
     byte *trusteeRightsMask);
int ScanDirectoryInformation(byte searchDirectoryHandle,
     char *searchDirectoryPath,int *subdirNumber,char *directoryName,
     byte *creationDateTime,long *ownerObjectID,byte *maximumRightsMask);
int SetDirectoryHandle(byte sourceDirectoryHandle,
     char *sourceDirectoryPath,byte targetDirectoryHandle);
     
#endif
