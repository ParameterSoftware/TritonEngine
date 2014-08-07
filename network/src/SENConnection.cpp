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

bool SENConnection::IsRunning() 
{
	return running;
}

void SENConnection::Listen()
{
	bool connected = this->IsConnected();
	this->ClearData();
	if ( connected )
		this->OnDisconnect();
	mode = Server;
	state = Listening;
}

void SENConnection::Connect( const SENAddress & address )
{
	bool connected = this->IsConnected();
	ClearData();
	if ( connected )
		this->OnDisconnect();
	mode = Client;
	state = Connecting;
	this->address = address;

}

bool SENConnection::IsConnection()
{
	return state == Connecting;
}

bool SENConnection::ConnectFailed()
{
	return state == ConnectFailed;
}

bool SENConnection::IsConnected()
{
	return state == Connected;
}

bool SENConnection::IsListening()
{
	return state == Listening;
}

bool SENConnection::GetMode()
{
	return mode;
}

void SENConnection::Update( float deltaTime )
{
	if(!running)
	{
		this->Stop();
		return;
	}
	timeoutAccumulator += deltaTime;
	if ( timeoutAccumulator > timeout )
	{
		if ( state == Connecting )
		{
			ClearData();
			state = ConnectFail;
			OnDisconnect();
		}
		else if ( state == Connected )
		{
			ClearData();
			if ( state == Connecting )
				state = ConnectFail;
			OnDisconnect();
		}
	}

}

bool SENConnection::SendPacket( const unsigned char data[], int size )
{
	if ( address.GetAddress() == 0 )
	{
		throw SEUException("No Address to Send to");
		return false;
	}
	unsigned char* packet = new unsigned char[size+4];
	packet[0] = (unsigned char) ( protocolId >> 24 );
	packet[1] = (unsigned char) ( ( protocolId >> 16 ) & 0xFF );
	packet[2] = (unsigned char) ( ( protocolId >> 8 ) & 0xFF );
	packet[3] = (unsigned char) ( ( protocolId ) & 0xFF );
	memcpy( &packet[4], data, size );
	bool res = socket.Send( address, packet, size + 4 );
	delete [] packet;
	return res;
}

bool SENConnection::SendPacket( const unsigned char data[], int size, SENAddress & address)
{
	this->Connect(address);
	this->SendPacket(data, size);
}

int SENConnection::ReceivePacket( unsigned char data[], int size )
{
	unsigned char* packet = new unsigned char[size+4];
	Address sender;
	int bytes_read = socket.Receive( sender, packet, size + 4 );
	if ( bytes_read == 0 )
	{
		delete [] packet;
		return 0;
	}
	if ( bytes_read <= 4 )
	{
		delete [] packet;
		return 0;
	}
	if ( packet[0] != (unsigned char) ( protocolId >> 24 ) || packet[1] != (unsigned char) ( ( protocolId >> 16 ) & 0xFF ) || packet[2] != (unsigned char) ( ( protocolId >> 8 ) & 0xFF ) || packet[3] != (unsigned char) ( protocolId & 0xFF ) )
	{
		delete [] packet;
		return 0;
	}
	if ( mode == Server && !IsConnected() )
	{
		state = Connected;
		address = sender;
		OnConnect();
	}
	if ( sender == address )
	{
		if ( mode == Client && state == Connecting )
		{
			state = Connected;
			OnConnect();
		}
		timeoutAccumulator = 0.0f;
		memcpy( data, &packet[4], size - 4 );
		delete [] packet;
		return size - 4;
	}
	delete [] packet;
	return 0;

}

int SENConnection::GetHeaderSize()
{
	return 4;
}

void SENConnection::ClearData()
{
	state = Disconnected;
	timeoutAccumulator = 0.0f;
	address = Address();
}
