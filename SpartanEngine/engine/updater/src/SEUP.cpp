#include "SEUP.h"

SEUPGame::SEUPGame(std::string game_name, unsigned short update_port)
{
	this->game_name = game_name;
	this->update_socket = new SENSocket(update_port);
}

SEUPGame::~SEUPGame()
{
	delete update_socket;
}

bool SEUPGame::CheckForUpdate()
{
	SENAddress update_address;
	int size = 1;
	update_socket.Recieve( update_address, recieved_data, size );
	delete update_address;
	int number_data = seuConvertToInt(recieved_data);
	if(recieved_data == 't' || recieved_data == 'T' || recieved_data == '1' || recieved_data == 'y' || recieved_data == 'Y' || number_data > 0)
		return this->Update();
	return false;
}

bool SEUPGame::Update()
{
	SENAddress update_address;
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

bool SEUP::OnFailedUpdate()
{
	return false;
}

//SEUPEngine
SEUPEngine::SEUPEngine()
{
	this->engine_name = "Spartan Engine";
	this->update_socket = new SENSocket(4000);
}

SEUPEngine::~SEUPEngine()
{
	delete update_socket;
}

bool SEUPEngine::CheckForUpdate()
{
	SENAddress update_address;
	int size = 1;
	update_socket.Recieve( update_address, recieved_data, size );
	delete update_address;
	int number_data = seuConvertToInt(recieved_data);
	if(recieved_data == 't' || recieved_data == 'T' || recieved_data == '1' || recieved_data == 'y' || recieved_data == 'Y' || number_data > 0)
		return this->Update();
	return false;
}

bool SEUPEngine::Update()
{
	SENAddress update_address;
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
