#include "Updater.h"
#include "../../utilities/src/Utilities.h"

GameUpdater::GameUpdater(std::string game_name, unsigned short update_port)
{
	this->game_name = game_name;
	this->update_socket = new Socket(update_port);
}

GameUpdater::~GameUpdater()
{
	delete update_socket;
}

bool GameUpdater::CheckForUpdate()
{
	Address update_address;
	int size = 1;
	update_socket.Recieve( update_address, recieved_data, size );
	delete update_address;
	int number_data = seuConvertToInt(recieved_data);
	if(recieved_data == 't' || recieved_data == 'T' || recieved_data == '1' || recieved_data == 'y' || recieved_data == 'Y' || number_data > 0)
		return this->Update();
	return false;
}

bool GameUpdater::Update()
{
	Address update_address;
	int size = 10;
	int recieved_bytes = update_socket.Recieve( update_address, recieved_data, size );
	size = (int)recieved_data;
	last_packet_size = size;
	recieved_bytes = update_socket.Recieve( update_address, recieved_data, size );
	if(!(recieved_bytes > 0))
	{
		bool next_action = this->OnFailedUpdate();
		return false;
	}
	return true;
}

bool GameUpdater::OnFailedUpdate()
{
	return false;
}

EngineUpdater::EngineUpdater()
{
	this->engine_name = "Spartan Engine";
	this->update_socket = new Socket(4000);
}

EngineUpdater::~EngineUpdater()
{
	delete update_socket;
}

bool EngineUpdater::CheckForUpdate()
{
	Address update_address;
	int size = 1;
	update_socket.Recieve( update_address, recieved_data, size );
	delete update_address;
	int number_data = seuConvertToInt(recieved_data);
	if(recieved_data == 't' || recieved_data == 'T' || recieved_data == '1' || recieved_data == 'y' || recieved_data == 'Y' || number_data > 0)
		return this->Update();
	return false;
}

bool EngineUpdater::Update()
{
	Address update_address;
	int size = 10;
	int recieved_bytes = update_socket.Recieve( update_address, recieved_data, size );
	recieved_data = seuConvertToInt(recieved_data);
	size = recieved_data;
	last_packet_size = size;
	recieved_bytes = update_socket.Recieve( update_address, recieved_data, size );
	if(!(recieved_bytes > 0))
	{
		bool next_action = this->OnFailedUpdate();
		return false;
	}
	return true;
}
