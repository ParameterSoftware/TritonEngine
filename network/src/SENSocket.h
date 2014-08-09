#include "SEN.h"

#ifndef __SENSOCKET__
#define __SENSOCKET__

class SENAddress
{
public:
	SENAddress();
	SENAddress( unsigned char a, unsigned char b, unsigned char c, unsigned char d, unsigned short port );
	SENAddress( unsigned int address, unsigned short port );
	unsigned int GetAddress() const;
	unsigned char GetA() const;
	unsigned char GetB() const;
	unsigned char GetC() const;
	unsigned char GetD() const;
	unsigned short GetPort() const;
	bool operator == ( const SENAddress & other ) const;
	bool operator != ( const SENAddress & other ) const;
	sockaddr_in to_sai();
private:
	unsigned int address;
	unsigned short port;
};

class SENSocket
{
public:
	SENSocket(unsigned short port=0, bool blocking_mode=false);
	~SENSocket();
	bool Open( unsigned short port, bool bm=false);
	void Close();
	bool IsOpen() const;
	bool Send( const SENAddress & destination, const void * data, int size );
	int Receive( SENAddress & sender, void * data, int size );
private:
	int socket;
};

#endif /* define(__SENSOCKET__) */
