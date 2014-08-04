#include "SEUException.h"
#include "SENSocket.h"

Socket::Socket()
{
	int handle = socket( AF_INET, SOCK_DGRAM, IPPROTO_UDP );

	if ( handle <= 0 )
	{
		throw SEUException( "Socket Creation Failed\n" );
		return false;
	}
}
