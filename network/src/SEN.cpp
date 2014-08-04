#include "SEUException.h"
#include "SEN.h"

SocketManager::SocketManager()
{
	if(!(this.InitializeSockets()))
		throw SEUException("Socket Intialization Failed: Windows Socket Application Failed");
}

SocketManager SocketManager::getInstance()
{
	if(SocketManager::instance == NULL)
	{
		instance = new SocketManager();
		this = instance;
	}
	return instance;
}

SocketManager::~SocketManager()
{
	this.ShutdownSockets();
}

bool SocketManager::InitializeSockets()
{
	#if PLATFORM == PLATFORM_WINDOWS
	WSADATA WsaData;
	return WSAStartup( MAKEWORD(2,2), &WsaData ) == NO_ERROR;
	#else
	return true;
	#endif
}

void SocketManager::ShutodwnSockets()
{
	#if PLATFORM == PLATFORM_WINDOWS
	WSACleanup();
	#endif
}
