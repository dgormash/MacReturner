#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <dos.h>
#include "netware.h"
#include <pcxlib.h>
#include <conio.h>
#include <process.h>

void main (void){
INTER_NETWORK_ADDR networkAddress;
//int i;
FILE *inifile;
FILE *stationList;
//char workdir[99];
//char addr[10];
char clss[8];
//char fileData[40][40][40];
//char addr[40];
//char star[40];
//char station[40
struct Data
{
   char	addr[13];
   char	symb;
   int station;
};
struct Data fileData[40];
int i,j;
clrscr();
printf("--------------------------------------\n");
if(IPXInitialise() != 0)
{
	printf("IPX not installed\n");
}
else
{    printf("IPX initilaize status is Ok\n");
}
printf("My MAC-Address is: ");
IPXGetInternetworkAddress(&networkAddress);
for (i=0;i<6;i++)
	printf("%02X ", networkAddress.node_address[i]);
printf("\n");
if((inifile = fopen("cls.ini", "ab")) !=  NULL){
	fprintf(inifile, "\r\n");
	for(i=0;i<6;i++)
	   fprintf(inifile, "%02X", networkAddress.node_address[i]);
	fprintf(inifile, "\t%s\t%d","*", 1);
	fclose(inifile);
  }


sprintf(clss, "clss.ini");

while(access(clss,0))
	sleep(1);
if((stationList =  fopen(clss,"r")) == NULL)
{
	printf("Error while opening clss.ini");
	exit(1);
}
for (i=0;i<=40;i++)
{
	for(j=0;j<=12;j++)
		fileData[i].addr[j] = ' ';
	fileData[i].station = 0;
	fileData[i].symb = ' ';
}

 i=0;

	while(fscanf(stationList, "%s%d %c",fileData[i].addr, &(fileData[i].station), &(fileData[i].symb))!=EOF)
	{
		//printf("%s %d %c\n",fileData[i].addr, fileData[i].station, fileData[i].symb);
		if(networkAddress.node_address == fileData[i].addr){
			printf("hell yeah!!!");
		}
		++i;

	}
fclose(stationList);


}









