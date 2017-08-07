#ifndef WSTATION_H
#define WSTATION_H

/***********************************/
/* Workstation Services prototypes */
/***********************************/

typedef struct {
   byte    slot_in_use;
   byte    servers_order_number;
   byte    servers_network_number[4];
   byte    physical_node_address[6];
   nw_int  socket_number;
   word    receive_timeout;
   byte    routers_physical_node_address[6];
   byte    packet_sequence_number;
   byte    connection_number;
   byte    connection_status;
   word    maximum_time_out;
   word    connection_word;
   byte    major_server_version;
   byte    server_flags;
   byte    minor_server_version;
   } CONNECTION_ID_TABLE;          /* GetConnectionIDTable */

void EndOfJob(void);
int GetConnectionIDTable(CONNECTION_ID_TABLE *table);
int GetDefaultConnectionID(void);
void GetDriveConnectionID(char *table);
void GetDriveFlagTable(char *table);
void GetDriveHandleTable(char *table);
void GetFileServerTable(char *table);
void GetNetwareShellVersion(char *shellInfo,byte *majorVersion,
      byte *minorVersion,byte *revisionLevel);
int GetNumberOfLocalDrives(void);
int GetPreferredConnectionID(void);
int GetPrimaryConnectionID(void);
int GetServerConnectionID(char *serverName,int *connectionID);
int IsShellLoaded(void);
int SetEndofJobStatus(int NewStatus);
int SetNWErrorMode(int NewMode);
void SetPreferredConnectionID(int connection_id);
void SetPrimaryConnectionID(int connection_id);

#endif
