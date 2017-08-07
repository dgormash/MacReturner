#ifndef IPXSPX_H
#define IPXSPX_H

/*********************************/
/* Sort out compiler differences */
/*********************************/

#ifdef TURBOC
#define _far far
#endif

/*******************/
/* Data Structures */
/*******************/

typedef struct {
                 byte   network_number[4];
                 byte   node_address[6];
        } INTER_NETWORK_ADDR;

typedef struct {
                 INTER_NETWORK_ADDR ina;
                 nw_int             socket_number;
        } NETWORK_ADDR;

typedef struct {
                 void _far  *address;
                 word       length;
        } ECB_FRAGMENT;

/*********************/
/* IPX Packet Header */
/*********************/

typedef struct {
                 nw_int        checksum;
                 nw_int        length;
                 byte          transport_control;
                 byte          packet_type;           /* User Sets */
                 NETWORK_ADDR  dest_addr;             /* User Sets */
                 NETWORK_ADDR  srce_addr;
        } IPX_HEADER;

/*********************/
/* SPX Packet Header */
/*********************/

typedef struct {
                 IPX_HEADER    ipx;
                 byte          connection_control;
                 byte          datastream_type;       /* User Sets */
                 nw_int        source_connection_id;
                 nw_int        dest_connection_id;
                 nw_int        sequence_number;
                 nw_int        acknowledge_number;
                 nw_int        allocation_number;
        } SPX_HEADER;

/*****************************/
/* Event Control Block (ECB) */
/*****************************/

typedef struct {
                 void _far     *link_address;
                 void          (_far *esr)(void);     /* User Sets */
                 byte          in_use;
                 byte          completion_code;
                 nw_int        socket_number;         /* User Sets */
                 byte          IPX_workspace[4];
                 byte          driver_workspace[12];
                 byte          immediate_address[6];  /* User Sets */
                 word          fragment_count;        /* User Sets */
                 ECB_FRAGMENT  fragment[2];           /* User Sets */
        } EVENT_CONTROL_BLOCK;

/******************************/
/* SPX Connection status data */
/******************************/

typedef struct { byte   connection_state;
                 byte   watchdog_is_on;
                 nw_int local_connection_id;
                 nw_int remote_connection_id;
                 nw_int sequence_number;
                 nw_int local_acknowledge_number;
                 nw_int local_allocation_number;
                 nw_int remote_acknowledge_number;
                 nw_int remote_allocation_number;
                 nw_int local_socket;
                 byte   immediate_address[6];
                 byte   network_number[4];
                 byte   node_address[6];
                 nw_int socket;
                 nw_int retransmission_count;
                 nw_int est_roundtrip_delay;
                 nw_int retransmitted_packets;
                 nw_int suppressed_packets;
        } SPX_CONNECTION_STATUS;

/***********************/
/* Function prototypes */
/***********************/

word IPXCancelEvent( EVENT_CONTROL_BLOCK *ecb );
void IPXCloseSocket( word socketNumber );
void IPXDisconnectFromTarget( NETWORK_ADDR *networkAddress );
void IPXGetInternetworkAddress( INTER_NETWORK_ADDR *networkAddress );
word IPXGetIntervalMarker( void );
word IPXGetLocalTarget( INTER_NETWORK_ADDR *networkAddress ,
                        byte *immediateAddress,word *transportTime );
word IPXInitialise( void );
word IPXListenForPacket( EVENT_CONTROL_BLOCK *ecb );
word IPXOpenSocket( word *socketNumber, byte longevity );
void IPXRelinquishControl( void );
void IPXScheduleIPXEvent( EVENT_CONTROL_BLOCK *ecb , word delayTicks );
void IPXSendPacket( EVENT_CONTROL_BLOCK *ecb );

void SPXAbortConnection( word connectionID );
word SPXEstablishConnection( word retryCount, word watchdogFlag ,
                   EVENT_CONTROL_BLOCK *ecb ,word *connectionID );
word SPXGetConnectionStatus( word connectionID ,
                             SPX_CONNECTION_STATUS *connectionStatus );
int SPXInitialise( byte *majorVersion,byte *minorVersion,
                   word *maxConnections,word *availableConnections );
void SPXListenForConnection( word retryCount, word watchdogFlag ,
                             EVENT_CONTROL_BLOCK *ecb );
void SPXListenForSequencedPacket( EVENT_CONTROL_BLOCK *ecb );
void SPXSendSequencedPacket( word connectionID, EVENT_CONTROL_BLOCK *ecb );
void SPXTerminateConnection( word connectionID, EVENT_CONTROL_BLOCK *ecb );

#endif       /* IPXSPX_H */
