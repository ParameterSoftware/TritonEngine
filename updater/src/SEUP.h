#ifndef __SEUP__
#define __SEUP__

#include "SENConnection.h"

class SEUPGame
{
public:
	SEUPGame(std::string game_name, SENAddress update_address);
	~SEUPGame();
	bool Update();
	virtual bool OnFailedUpdate();
private:
	std::string game_name;
	SENSocket update_socket;
	SENAddress update_address;
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
