#include "SEN.h"

bool senInitializeSockets(bool enable_experimental)
{
	if(enable_experimental)
	{
		#define SEN_WIN_EXP	4
		#define SEN_UNIX_EXP	3
		#define SEN_MAC_EXP	2
		#define SEN_UNID_EXP	1
		
		#if PLATFORM == PLATFORM_WINDOWS
		#define SEN_EXP SEN_WIN_EXP
		#elif PLATFORM == PLATFORM_UNIX
		#define SEN_EXP SEN_UNIX_EXP
		#elif PLATFORM == PLATFORM_MAC
		#define SEN_EXP SEN_MAC_EXP
		#else
		#define SEN_EXP SEN_UNID_EXP
		#endif
	}
	#if PLATFORM == PLATFORM_WINDOWS
	WSADATA WsaData;
	return WSAStartup( MAKEWORD(2,2), &WsaData ) == NO_ERROR;
	#else
	return true;
	#endif
}

void senShutodwnSockets()
{
	#if PLATFORM == PLATFORM_WINDOWS
	WSACleanup();
	#endif
}
