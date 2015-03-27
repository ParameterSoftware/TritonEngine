#include "Exception.h"
#include "Socket.h"

using namespace seu;
using namespace sen;

//Socket

Socket::Socket( unsigned short port, bool blocking_mode)
{
	socket = 0;
	this->Open(port, blocking_mode);
}

Socket::~Socket()
{
	this->Close();
}

bool Socket::Open(unsigned short port, bool bm)
{
	if(this->IsOpen())
		this->Close();
	
	socket = ::socket( AF_INET, SOCK_DGRAM, IPPROTO_UDP );

	if ( socket <= 0 )
	{
		throw Exception( "Socket Creation Failed\nStandard Socket function failed" );
		socket = 0;
		return false;
	}
	
	Address* alt_address = new Address(INADDR_ANY, port);
	
	sockaddr_in address = alt_address->to_sai();
	
	delete alt_address;

	if ( bind( socket, (const sockaddr*) &address, sizeof(sockaddr_in) ) < 0 )
	{
		throw Exception("Socket Binding Failed\n");
		Close();
		return false;
	}
	
	if(bm)
		return true;
	
	#if PLATFORM == PLATFORM_MAC || PLATFORM == PLATFORM_UNIX
		int nonBlocking = 1;
		if ( fcntl( socket, F_SETFL, O_NONBLOCK, nonBlocking ) == -1 )
		{
			throw Exception( "Non-Blocking Socket Mode failed to be Set (UNIX)\n" );
			Close();
			return false;
		}
	#elif PLATFORM == PLATFORM_WINDOWS
		DWORD nonBlocking = 1;
		if ( ioctlsocket( socket, FIONBIO, &nonBlocking ) != 0 )
		{
			throw Exception( "Non-Blocking Socket Mode failed to be Set (Windows)\n" );
			Close();
			return false;
		}
	#endif
	
	return true;
}

void Socket::Close()
{
	if ( socket != 0 )
	{
		#if PLATFORM == PLATFORM_MAC || PLATFORM == PLATFORM_UNIX
			close( socket );
		#elif PLATFORM == PLATFORM_WINDOWS
			closesocket( socket );
		#endif
		socket = 0;
	}
}

bool Socket::IsOpen()
{
	return socket != 0;
}

bool Socket::Send( const Address &destination, const void * data, int size )
{
	if(!(data))
		return false;
	if(!(size > 0))
		return false;
	if ( socket == 0 )
		return false;
		
	sockaddr_in address = destination.to_sai();
		
	int sent_bytes = sendto( socket, (const char*)data, size, 0, (sockaddr*)&address, sizeof(sockaddr_in) );
		
	return sent_bytes == size;
}

int Socket::Receive( Address & sender, void * data, int size )
{
	if(!(data))
		return 0;
	if(!(size > 0))
		return 0;
	if ( socket == 0 )
		return 0;
	
	#if PLATFORM == PLATFORM_WINDOWS
		typedef int socklen_t;
	#endif
	
	sockaddr_in from;
	socklen_t fromLength = sizeof( from );

	int received_bytes = recvfrom( socket, (char*)data, size, 0, (sockaddr*)&from, &fromLength );
	
	if ( received_bytes <= 0 )
		return 0;
	
	unsigned int address = ntohl( from.sin_addr.s_addr );
	unsigned int port = ntohs( from.sin_port );

	sender = Address( address, port );

	return received_bytes;	
}

//Address

Address::Address()
{
	address = 0;
	port = 0;
}

Address::Address( unsigned char a, unsigned char b, unsigned char c, unsigned char d, unsigned short port )
{
	this->address = ( a << 24 ) | ( b << 16 ) | ( c << 8 ) | d;
	this->port = port;
}

Address::Address( unsigned int address, unsigned short port )
{
	this->address = address;
	this->port = port;
}

unsigned int Address::GetAddress()
{
	return address;
}

unsigned char Address::GetA()
{
	return ( unsigned char ) ( address >> 24 );
}

unsigned char Address::GetB()
{
	return ( unsigned char ) ( address >> 16 );
}

unsigned char Address::GetC()
{
	return ( unsigned char ) ( address >> 8 );
}

unsigned char Address::GetD()
{
	return ( unsigned char ) ( address );
}

unsigned short Address::GetPort()
{
	return port;
}

template<typedef<T> bool Address::operator==( const T other )
{
	return this->address == other.address && this->port == other.port;
}

template<typedef<T> bool Address::operator!=( const T other )
{
	return ! ( *this == other );
}

sockaddr_in Address::to_sai()
{
	sockaddr_in address;
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = htonl( this->address );
	address.sin_port = htons( (unsigned short) port );
	return address;
}
