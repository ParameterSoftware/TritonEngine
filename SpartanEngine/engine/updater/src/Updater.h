#ifndef __SEUP__
#define __SEUP__

#include <string>
#include <iostream>

#include "../../network/src/Connection.h"

class GameUpdater
{
public:
	GameUpdater(std::string game_name, unsigned short update_port);
	~GameUpdater();
	bool CheckForUpdate();
	bool Update();
	virtual bool OnFailedUpdate();
private:
	std::string game_name;
	Socket update_socket;
	void* recieved_data;
	int last_packet_size;
};

class EngineUpdater
{
public:
	EngineUpdater();
	~EngineUpdater();
	bool CheckForUpdate();
	bool Update();
	bool OnFailedUpdate();
	void SetGameUpdater(GameUpdater updater);
private:
	std::string engine_name;
	GameUpdater game_updater;
	Socket update_socket;
	void* recieved_data;
	int last_packet_size;
};

#endif /* define(__SEUP__) */
