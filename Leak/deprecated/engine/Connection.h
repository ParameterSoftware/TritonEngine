#include "Socket.h"

#ifndef __SENCONNECTION__
#define __SENCONNECTION__

namespace sen
{
	class Connection
	{
	public:
		friend class Address;
		enum Mode
		{
			None,
			Client,
			Server
		};
	
		Connection( unsigned int protocolId, float timeout, int port = NULL );
		virtual ~Connection();
		bool Start( int port );
		void Stop();
		bool IsRunning();
		void Listen();
		void Connect( const Address & address );
		bool IsConnecting();
		bool ConnectFailed();
		bool IsConnected();
		bool IsListening();
		Mode GetMode();
		virtual void Update( float deltaTime );
		virtual bool SendPacket( const unsigned char data[], int size, Address laddress = Address(NULL, NULL));
		virtual int ReceivePacket( unsigned char data[], int size );
		int GetHeaderSize();
		template<typedef<T> bool operator!=(T object);
		template<typedef<T> bool operator==(T object);
	
	protected:
		virtual void OnStart();
		virtual void OnStop();
		virtual void OnConnect();
		virtual void OnDisconnect();

	private:
		void ClearData();
	
		enum State
		{
			Disconnected,
			Listening,
			Connecting,
			ConnectFail,
			Connected
		};
	
		unsigned int protocolId;
		float timeout;
	
		bool running;
		Mode mode;
		State state;
		Socket socket;
		float timeoutAccumulator;
		Address address;

	};
}

#endif /* define(__SENCONNECTION__) */
