#ifndef NWCALL_H
#define NWCALL_H

/**********************/
/* NW Call prototypes */
/**********************/

int NWcall(int ah_set,void *request, void *reply);
int NWcallx(int ah_set,int al_set,void *request, void *reply);
int NWF2call(byte function,void *request,word requestLength,
             void *reply,word replyLength);
             
#endif
