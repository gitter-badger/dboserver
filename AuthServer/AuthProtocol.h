#ifndef _AUTHPROTOCOL_H
#define _AUTHPROTOCOL_H

#include "Protocol.h"

#pragma once

enum eOpcode
{
	UA_LOGIN_REQ = 100,
	UA_LOGIN_REQ_KOREA_CJ,
	UA_LOGIN_CREATEUSER_REQ,
	UA_LOGIN_DISCONNECT_REQ,

	AU_HEARTBEAT = 1000,
	AU_LOGIN_RES,
	AU_LOGIN_CREATEUSER_RES,
	AU_LOGIN_DISCONNECT_RES,
};

#pragma pack(1)

BEGIN_PACKET(AU_HEARTBEAT)
END_PACKET()

BEGIN_PACKET(UA_LOGIN_REQ)
	WCHAR UserName[MAX_USERNAME_SIZE + 1];
	WCHAR PassWord[MAX_PASSWORD_SIZE + 1];
	DWORD CodePage;
	WORD hVer;
	WORD lVer;
	BYTE MacAddress[MAX_MAC_ADDR_SIZE];
END_PACKET()

BEGIN_PACKET(UA_LOGIN_REQ_KOREA_CJ)
	DWORD		CodePage;
	WORD		LVersion;
	WORD		RVersion;
	BYTE		MacAddress[MAX_MAC_ADDR_SIZE];
	WORD		CpCookieLength;
	char		CpCookie[MAX_SIZE_CP_COOKIE + 1];
END_PACKET()

BEGIN_PACKET(AU_LOGIN_RES)
	WORD ResultCode;
	WCHAR UserName[MAX_USERNAME_SIZE + 1];
	BYTE AuthKey[MAX_AUTHKEY_SIZE];
	int AccountID;
	BYTE LastServerID;
	DWORD AcLevel;
	BYTE ServerCount;
	SRVINFO Servers[MAX_CHARSRV_COUNT];
END_PACKET()

BEGIN_PACKET(UA_LOGIN_DISCONNECT_REQ)
	WCHAR UserName[MAX_USERNAME_SIZE + 1];
	DWORD CodePage;
	bool IsEnteringCharacterServer;
END_PACKET()

BEGIN_PACKET(AU_LOGIN_DISCONNECT_RES)
END_PACKET()

#pragma pack()

#endif