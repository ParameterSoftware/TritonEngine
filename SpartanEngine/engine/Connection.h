#include "Socket.h"

#ifndef __SENCONNECTION__
#define __SENCONNECTION__

class Connection
{
public:
	enum Mode
	{
		None,
		Client,
		Server
	};
	
	Connection( unsigned int protocolId, float timeout );
	virtual ~Connection();
	bool Start( int port );
	void Stop();
	bool IsRunning() const;
	void Listen();
	void Connect( const Address & address );
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

#endif /* define(__SENCONNECTION__) */
