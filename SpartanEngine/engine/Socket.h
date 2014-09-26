#include "Networking.h"

#ifndef __SENSOCKET__
#define __SENSOCKET__
namespace sen
{
	class Address
	{
	public:
		friend class Connection;
		Address();
		Address( unsigned char a, unsigned char b, unsigned char c, unsigned char d, unsigned short port );
		Address( unsigned int address, unsigned short port );
		unsigned int GetAddress();
		unsigned char GetA();
		unsigned char GetB();
		unsigned char GetC();
		unsigned char GetD();
		unsigned short GetPort();
		sockaddr_in to_sai();
	protected:
		unsigned int address;
		unsigned short port;
	};

	class Socket
	{
	public:
		Socket(unsigned short port=0, bool blocking_mode=false);
		~Socket();
		bool Open( unsigned short port, bool bm=false);
		void Close();
		bool IsOpen();
		bool Send( const Address & destination, const void * data, int size );
		int Receive( Address & sender, void * data, int size );
	private:
		int socket;
	};
}

#endif /* define(__SENSOCKET__) */
