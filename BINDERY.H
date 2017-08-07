#ifndef BINDERY_H
#define BINDERY_H

/*******************************/
/* Bindery Services prototypes */
/*******************************/

int AddBinderyObjectToSet(int objectType,char *objectName,
     char *propertyName,int memberType,char *memberName);
int ChangeBinderyObjectPassword(int objectType,char *objectName,
     char *oldPass,char *newPass);
int ChangeBinderyObjectSecurity(byte newSecurity,int objectType,
     char *objectName);
int ChangePropertySecurity(int objectType,char *objectName,
     byte newPropSecurity,char *propName);
int CloseBindery(void);
int CreateBinderyObject(byte flag,byte security,int objectType,
     char *objectName);
int CreateProperty(int objectType,char *objectName,byte propFlags,
     byte propSecurity,char *prop_name);
int DeleteBinderyObject(int objectType,char *objectName);
int DeleteBinderyObjectFromSet(int objectType,char *objectName,
     char *propertyName,int memberType,char *member_name);
int DeleteProperty(int objectType,char *objectName,char *propName);
int GetBinderyAccessLevel(long *objectID,byte *accessLevel);
int GetBinderyObjectID(word objectType,char *objectName,long *objectID);
int GetBinderyObjectName(long objectID,word *objectType,char *objectName);
int IsBinderyObjectInSet(int objectType,char *objectName,
     char *propertyName,int memberType,char *member_name);
int OpenBindery(void);
int ReadPropertyValue(int objectType,char *objectName,char *propertyName,
     int segment,char *propertyValues,byte *moreSegments,
     byte *propertyFlag);
int RenameBinderyObject(int objectType,char *objectName,
     char *new_objectName);
int ScanBinderyObject(int scanObjectType,char *scanObjectName,
	 long *lastObjectID,int *objectType,char *objectName,
	 byte *objectHasProperties,byte *objectSecurity,byte *objectFlag);
int ScanProperty(int objectType,char *objectName,char *scanPropertyName,
     char *propertyName,byte *propertyFlags,byte *propertySecurity,
     byte *propertyHasValue,byte *moreProperties);
int VerifyBinderyObjectPassword(word objectType,char *objectName,
                                char *password);
int VerifyObjectPasswordEncrypted(word objectType,char *objectName,
                                  byte *encryptedPassword);
int WritePropertyValue(int objectType,char *objectName,int segment,
     byte erase_remaining,char *propName,byte *value);

#endif
