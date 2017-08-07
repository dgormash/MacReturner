#ifndef SERVER_H
#define SERVER_H

/******************************/
/* Server Services prototypes */
/******************************/

typedef struct {
   word buffer_length;
   nw_long system_elapsed_time;
   nw_int cache_buffer_count;
   nw_int cache_buffer_size;
   nw_int dirty_cache_buffers;
   nw_long cache_read_requests;
   nw_long cache_write_requests;
   nw_long cache_hits;
   nw_long cache_misses;
   nw_long physical_read_requests;
   nw_long physical_write_requests;
   nw_int physical_read_errors;
   nw_int physical_write_errors;
   nw_long cache_get_requests;
   nw_long cache_full_write_requests;
   nw_long cache_partial_write_requests;
   nw_long background_dirty_writes;
   nw_long background_aged_writes;
   nw_long total_cache_writes;
   nw_long cache_allocations;
   nw_int thrashing_count;
   nw_int LRU_block_was_dirty;
   nw_int read_beyond_write;
   nw_int fragmented_write_occurred;
   nw_int cache_hit_unavail_block;
   nw_int cache_block_scrapped;
   } DISK_CACHE_STATISTICS;         /* GetDiskCacheStatistics */

typedef struct {
   char server_name[48];
   byte netware_version;
   byte netware_subversion;
   nw_int connections_supported;
   nw_int connections_in_use;
   nw_int max_connected_volumes;
   byte os_revision;
   byte SFT_level;
   byte TTS_level;
   nw_int peak_connections_used;
   byte accounting_version;
   byte VAP_version;
   byte queuing_version;
   byte print_server_version;
   byte virtual_console_version;
   byte security_restrictions_level;
   byte internet_bridge_version;
   byte reserved[60];
   } FILE_SERVER_INFO;		  /* GetFileServerInformation */

typedef struct {
   word buffer_length;
   nw_long system_elapsed_time;
   byte physical_disk_channel;
   byte drive_removable_flag;
   byte physical_drive_type;
   byte controller_drive_number;
   byte controller_number;
   byte controller_type;
   nw_long drive_size;
   nw_int drive_cylinders;
   byte drive_heads;
   byte sectors_per_track;
   char drive_definition_string[64];
   nw_int io_error_count;
   nw_long hot_fix_table_start;
   nw_int hot_fix_table_size;
   nw_int hot_fix_blocks_available;
   byte hot_fix_disabled;
   } PHYSICAL_DISK_STATISTICS;         /* GetPhysicalDiskStatistics */

int CheckConsolePrivileges(void);
int ClearConnectionNumber(int connection);
int DisableFileServerLogin(void);
int DisableTransactionTracking(void);
int DownFileServer(int forceIt);
int EnableFileServerLogin(void);
int EnableTransactionTracking(void);
int GetBinderyObjectDiskSpaceLeft(long objectID,long *systemElapsedTime,
     long *unusedDiskBlocks,byte *restrictionsEnforced);
int GetConnectionsOpenFiles(int connection,int *sequence,word *taskNumber,
     byte *lockFlag,byte *accessFlag,byte *lockType,byte *nameSpace,
     byte *volumeNumber,dword *parentDirEntry,
     dword *directoryEntry,char *fileName);
int GetConnectionsUsageStatistics(int connection,long *systemElapsedTime,
     double *bytesRead,double *bytesWritten,long *totalRequestPackets);
int GetDiskCacheStatistics(DISK_CACHE_STATISTICS *ReplyBuffer);
int GetDiskUtilisation(long objectID,byte volumeNumber,
     word *usedDirectories,word *usedFiles,word *usedBlocks);
int GetEncryptionKey(byte *key);
void GetFileServerDateTime(	int *hours,int *minutes,int *seconds,
	 int *day,int *month,int *year,int *dayOfWeek);
int GetFileServerInformation(FILE_SERVER_INFO *replyBuffer);
int GetFileServerLoginStatus(int *loginEnabled);
int GetNetworkSerialNumber(dword *serverSerialNumber ,
                           word  *appSerialNumber);
int GetPathFromDirectoryEntry(byte nameSpace,byte volumeNumber,
     dword directoryEntry,char *path);
int GetPhysicalDiskStatistics(byte physicalDiskNumber,
     PHYSICAL_DISK_STATISTICS *replyBuffer);
int GetSemaphoreInformation( char *semaphoreName,
                             int *sequence,word *openCount,
                             int *semaphoreValue,
                             word *logicalConnection,
                             word *taskNumber );
int SendConsoleBroadcast(byte connectionCount, byte *connections,
                         char *message );
                         
#endif
