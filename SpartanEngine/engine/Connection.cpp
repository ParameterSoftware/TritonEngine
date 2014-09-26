#include "Connection.h"
#include "Exception.h"

using namespace seu;
using namespace sen;

Connection::Connection( unsigned int protocolId, float timeout, int port )
{
	this->protocolId = protocolId;
	this->timeout = timeout;
	mode = None;
	running = false;
	this->ClearData();
	if(port != NULL)
		this->Start(port);
}

Connection::~Connection()
{
	if( this->IsRunning() )
		this->Stop();
}

bool Connection::Start( int port )
{
	if(running)
		this->Stop();
	if ( !socket.Open( port ) )
		return false;
	running = true;
	this->OnStart();
	return true;
}

void Connection::Stop()
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

bool Connection::IsRunning() 
{
	return running;
}

void Connection::Listen()
{
	bool connected = this->IsConnected();
	this->ClearData();
	if ( connected )
		this->OnDisconnect();
	mode = Server;
	state = Listening;
}

void Connection::Connect( const Address & address )
{
	bool connected = this->IsConnected();
	ClearData();
	if ( connected )
		this->OnDisconnect();
	mode = Client;
	state = Connecting;
	this->address = address;

}

bool Connection::IsConnecting()
{
	return state == Connecting;
}

bool Connection::ConnectFailed()
{
	return state == ConnectFailed;
}

bool Connection::IsConnected()
{
	return state == Connected;
}

bool Connection::IsListening()
{
	return state == Listening;
}

Connection::Mode Connection::GetMode()
{
	return mode;
}

void Connection::Update( float deltaTime )
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

bool Connection::SendPacket( const unsigned char data[], int size, Address laddress )
{
	if ( laddress.address != NULL)
	{
		address = laddress;
	}

	if ( address.GetAddress() == 0 )
	{
		throw Exception("No Address to Send to");
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

int Connection::ReceivePacket( unsigned char data[], int size )
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

int Connection::GetHeaderSize()
{
	return 4;
}

void Connection::ClearData()
{
	state = Disconnected;
	timeoutAccumulator = 0.0f;
	address = Address();
}

template<typedef<T> bool Connection::operator!=(T object)
{
	if(typedef(T) != Connection)
	{
		return true;
	}

	if(object.address != this->address || object.socket != this->socket)
	{
		return true;
	}

	return false;
}

template<typedef<T> bool operator==(T object)
{
	if(typedef(T) != Connection)
	{
		return false;
	}

	if(object.address != this->address || object.socket != this->socket)
	{
		return false;
	}

	return true;
}