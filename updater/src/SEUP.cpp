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

bool SEUPGame::Update()
{
	int size = 10;
	int recieved_bytes = update_socket.Recieve( update_address, recieved_data, size );
	recieved_data = seuConvertToInt(recieved_data);
	size = recieved_data;
	last_packet_size = size;
	recieved_bytes = update_socket.Recieve( update_address, recieved_data, size );
	return recieved_bytes > 0;
}
