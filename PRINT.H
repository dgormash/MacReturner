#ifndef PRINT_H
#define PRINT_H

/*****************************/
/* Print Services prototypes */
/*****************************/

typedef struct {
   byte     Status;
   byte     PrintFlags;
   byte     TabSize;
   byte     ServerPrinter;
   byte     NumberCopies;
   byte     FormType;
   byte     Reserved1;
   byte     BannerText[13];
   byte     Reserved2;
   byte     LocalLPTDevice;
   nw_int   FlushTimeoutCounter;
   byte     FlushOnClose;
   nw_int   MaximumLines;
   nw_int   MaximumChars;
   byte     FormName[13];
   byte     LPTFlag;
   byte     FileFlag;
   byte     TimeoutFlag;
   nw_long  SetupBufferAddress;
   nw_long  ResetBufferAddress;
   byte     ConnectIdQPrintJob;
   byte     InProgress;
   byte     PrintQFlag;
   byte     PrintJobValid;
   nw_long  PrintQID;
   nw_int   PrintJobNumber;
   } PRINT_CONTROL_DATA;     /* Used in PRINT.C (Print Services) */

int CancelLPTCapture(void);
int CancelSpecificLPTCapture(int prnNo);
int EndLPTCapture(void);
int EndSpecificLPTCapture(int prnNo);
int FlushLPTCapture(void);
int FlushSpecificLPTCapture(int prnNo);
int GetBannerUserName(char *pointer);
int GetLPTCaptureStatus(void);
int GetDefaultLocalPrinter(void);
int GetDefaultCaptureFlags(PRINT_CONTROL_DATA *reply);
int GetPrinterStatus(int prnNo,
                     byte *printerHalted,byte *printerOffline,
                     byte *formType,byte *targetPrinterNumber);
int GetSpecificCaptureFlags(int device,PRINT_CONTROL_DATA *reply);
int SetBannerUserName(char *pointer);
int SetCapturePrintQueue(int device,long queueID);
int SetDefaultLocalPrinter(int device);
int SetDefaultCaptureFlags(PRINT_CONTROL_DATA *flags);
int SetSpecificCaptureFlags(int device,PRINT_CONTROL_DATA *flags);
int SpecifyCaptureFile(int directoryHandle,char *filename);
int StartLPTCapture(void);
int StartSpecificLPTCapture(int device);

#endif
