#include "SENSocket.h"

#ifndef __SENCONNECTION__
#define __SENCONNECTION__

class SENConnection
{
public:
	enum SENMode
	{
		None,
		Client,
		Server
	};
	
	SENConnection( unsigned int protocolId, float timeout );
	virtual ~SENConnection();
	bool Start( int port );
	void Stop();
	bool IsRunning() const;
	void Listen();
	void Connect( const SENAddress & address );
	bool IsConnecting() const;
	bool ConnectFailed() const;
	bool IsConnected() const;
	bool IsListening() const;
	Mode GetMode() const;
	virtual void Update( float deltaTime );
	virtual bool SendPacket( const unsigned char data[], int size );
	virtual int ReceivePacket( unsigned char data[], int size );
	int GetHeaderSize() const;
	
protected:
	virtual void OnStart();
	virtual void OnStop();
	virtual void OnConnect();
	virtual void OnDisconnect();

private:
	void ClearData();
	
	enum SENState
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
	SENMode mode;
	SENState state;
	SENSocket socket;
	float timeoutAccumulator;
	SENAddress address;

};

#endif /* define(__SENCONNECTION__) */
