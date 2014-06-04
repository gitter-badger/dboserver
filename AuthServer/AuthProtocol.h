#ifndef _AUTHPROTOCOL_H
#define _AUTHPROTOCOL_H

#include "Protocol.h"

enum eOpcode
{
	UA_LOGIN_REQ = 100,
	UA_LOGIN_CREATEUSER_REQ = 102,
	UA_LOGIN_DISCONNECT_REQ,
	AU_HEARTBEAT = 1000,
	AU_LOGIN_RES,
	AU_LOGIN_CREATEUSER_RES,
	AU_LOGIN_DISCONNECT_RES,
};

struct SRVINFO
{
	char CharServerIP[MAX_SRVADDR_SIZE + 1];
	WORD CharServerPort;
	DWORD Load;
};

#pragma pack(push, 1)
BEGIN_PACKET(UA_LOGIN_REQ)
	WCHAR UserName[MAX_USERNAME_SIZE + 1];
	WCHAR PassWord[MAX_PASSWORD_SIZE + 1];
	DWORD CodePage;
	WORD hVer;
	WORD lVer;
	BYTE MacAddress[MAX_MAC_ADDR_SIZE];
END_PACKET()

BEGIN_PACKET(AU_LOGIN_RES)
	WORD ResultCode;
	WCHAR UserName[MAX_USERNAME_SIZE + 1];
	BYTE AuthKey[MAX_AUTHKEY_SIZE];
	UINT32 AccountID;
	BYTE LastServerID;
	DWORD AcLevel;
	BYTE ServerCount;
	SRVINFO Servers[MAX_CHARSRV_COUNT];
END_PACKET()
#pragma pack(pop)

#endif