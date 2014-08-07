#include "SENConnection.h"

SENConnection::SENConnection( unsigned int protocolId, float timeout )
{
	this->protocolId = protocolId;
	this->timeout = timeout;
	mode = None;
	running = false;
	this->ClearData();
}

SENConnection::SENConnection( unsigned int protocolId, float timeout, int port)
{
	this(protocolId, timeout);
	this->Start(port);
}

SENConnection::~SENConnection()
{
	if( this->IsRunning() )
		this->Stop();
}

bool SENConnection::Start( int port )
{
	if(running)
		this->Stop();
	if ( !socket.Open( port ) )
		return false;
	running = true;
	this->OnStart();
	return true;
}

void SENConnection::Stop()
{
	if(!(running))
	{
		this->ClearData();
		socket.Close();
		return;
	}
	bool connected = IsConnected();
	this->ClearData();
	running = false;
	if ( connected )
		this->OnDisconnect();
	this->OnStop();
}
