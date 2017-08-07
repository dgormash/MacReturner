#ifndef GENERAL_H
#define GENERAL_H

/**********************/
/* General prototypes */
/**********************/

int GetNetwareVersion( int *supportedConns );
void NWstrcpy(char *destination,char *source,int count);
void NWintconvert(int in,nw_int *convert);
void NWlongconvert(unsigned long in,nw_long *convert);
int ServerID(char *Name);
int convertNWint(nw_int in);
long convertNWlong(nw_long *in);
void convertNWdate(nw_int date_in,char *date_out);
void convertNWtime(nw_int time_in,char *time_out);
void HexToChar(char *destination,byte *source,word count);

#endif
