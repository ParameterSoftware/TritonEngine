#ifndef __SEUP__
#define __SEUP__

#include "SENConnection.h"

class SEUPGame
{
public:
	SEUPGame(std::string game_name, unsigned short update_port);
	~SEUPGame();
	bool CheckForUpdate();
	bool Update();
	virtual bool OnFailedUpdate();
private:
	std::string game_name;
	SENSocket update_socket;
	void* recieved_data;
	int last_packet_size;
};

class SEUPEngine
{
public:
	SEUPEngine();
	~SEUPEngine();
	bool Update();
	bool OnFailedUpdate();
	void SetGameUpdater(SEUPGame updater);
private:
	std::string engine_name = "Spartan Engine";
	SEUPGame game_updater;
	SENSocket update_address;
};

#endif /* define(__SEUP__) */
