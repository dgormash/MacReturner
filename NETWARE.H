/*********************************/
/* Netware C Library Header file */
/*********************************/

#ifndef NETWARE_H
#define NETWARE_H

#define NETCLB_VERSION 2.30

/***************************************/
/* Bindery object type classifications */
/***************************************/

#define UNKNOWN         0x0000 /* unknown object */
#define USER            0x0001 /* User type object */
#define USER_GROUP      0x0002 /* Group type object */
#define PRINT_Q         0x0003 /* Print Queue type object */
#define FILE_SERVER     0x0004 /* FileServer */
#define JOB_SERVER      0x0005 /* Job server */
#define GATEWAY         0x0006 /* Gateway */
#define PRN_SERVER      0x0007 /* Print server */
#define ARCHIVE_Q       0x0008 /* Archive queue */
#define ARC_SERVER      0x0009 /* Archive server */
#define JOB_Q           0x000a /* Job queue */
#define ADMIN           0x000b /* Administration */
#define REM_BRIDGE      0x0026 /* Remote bridge */
#define ADV_PRN_SERVER  0x0047 /* Advertising Print Server */
#define WILDCARD        0xffff /* WildCard */

/*************************************/
/* Trustee\Effective Rights settings */
/*************************************/

#define RT_NONE       0x00
#define RT_READ       0x01
#define RT_WRITE      0x02
#define RT_OPEN       0x04
#define RT_CREATE     0x08
#define RT_DELETE     0x10
#define RT_OWNERSHIP  0x20
#define RT_SEARCH     0x40
#define RT_MODIFY     0x80
#define RT_ALL        0xff

/*******************/
/* File Attributes */
/*******************/

#define FA_NORMAL         0x00
#define FA_READ_ONLY      0x01
#define FA_HIDDEN         0x02
#define FA_SYSTEM         0x04
#define FA_EXECUTE_ONLY   0x08
#define FA_DIRECTORY      0x10
#define FA_NEEDS_ARCHIVE  0x20
#define FA_SHAREABLE      0x80

/****************************/
/* Extended File Attributes */
/****************************/

#define FA_TRANSACTIONAL  0x10
#define FA_INDEXED        0x20
#define FA_READ_AUDIT     0x40
#define FA_WRITE_AUDIT    0x80

/*****************************/
/* Property Name definitions */
/*****************************/

/* These strings are previously defined by Novell, you can however  */
/* create your own properties, that the Bindery will maintain, but  */
/* they could only be utilised by your own software. eg RWDC rights */
/* within your own package.                                         */

#define LOGINCONTROL  "LOGIN_CONTROL"
#define ACC_SERV      "ACCOUNT_SERVERS"
#define ACC_BAL       "ACCOUNT_BALANCE"
#define PASS          "PASSWORD"
#define SEC_EQUIV     "SECURITY_EQUALS"
#define GROUPMEMS     "GROUP_MEMBERS"
#define GROUPS_IN     "GROUPS_I'M_IN"
#define NETADDR       "NET_ADDRESS"
#define IDENT         "IDENTIFICATION"
#define OPERS         "OPERATORS"

/********************************************************************/
/* Object Max Name Sizes                                            */
/*                                                                  */
/* The following are the maximum size of object values including a  */
/* null terminator. i.e. ASCIIZ strings.                            */
/********************************************************************/

#define OBJECT_LENGTH         48   /* object name max length */
#define PROPERTY_LENGTH       16   /* property name max length */
#define PASSWORD_LENGTH       128  /* password max length */
#define FILE_PATH_LENGTH      256  /* file path maximum length */
#define DIR_PATH_LENGTH       256  /* directory path maximum length */
#define VOLUME_NAME_LENGTH    17   /* volume name maximum length */
#define SEMAPHORE_NAME_LENGTH 127  /* semaphore name maximum length */

/****************************/
/* Some Useful Return Codes */
/****************************/

#define SUCCESS                0x00 /* Function was successful */
#define CAP_NACTIVE            0x00 /* Capture is NOT active */
#define NO_MORE_PATHS          0x9c /* No more trustee paths */
#define NO_NETWARE_SHELL       0xbb /* Netware shell not loaded */
#define NOT_SUPPORTED_AT_V3    0xbc /* Function not available with */
                                    /* Netware 3.xx                */

/****************/
/* All typedefs */
/****************/

typedef unsigned long    dword;     /* four bytes */
typedef unsigned int     word;      /* two bytes */
typedef unsigned char    byte;      /* single byte */

typedef struct {
   byte hi_byte;      /* NetWare int, */
   byte lo_byte;      /* hibyte first (inverse native PC) */
   } nw_int;

typedef struct {
   byte hihi_byte;   /* NetWare long */
   byte hilo_byte;   /* hibyte first (inverse native PC) */
   byte lohi_byte;
   byte lolo_byte;
   } nw_long;

#endif        /* NETWARE_H */

/********************************/
/* Prototypes for all functions */
/********************************/

#include "bindery.h"
#include "connect.h"
#include "direct.h"
#include "file.h"
#include "general.h"
#include "message.h"
#include "nwcall.h"
#include "print.h"
#include "sync.h"
#include "server.h"
#include "wstation.h"
#include "ipxspx.h"
#include "queue.h"
#include "encrypt.h"

/****************************************/
/* End of Netware C Library Header file */
/****************************************/
