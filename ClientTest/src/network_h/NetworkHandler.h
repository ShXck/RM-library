#ifndef NETWORK_H_NETWORKHANDLER_H_
#define NETWORK_H_NETWORKHANDLER_H_
#define PORT 8000
#include <SFML/Network.hpp>
#include <string>
#include <iostream>
#include "../lib_ops/rmRefh.h"
#include "Reader.h"
#include "JSONHandler.h"
#include <thread>

class Network_Handler {
public:
	Network_Handler();
	void make_connection();
	void run();
	void send( std::string message );
	void check_server_status();  // checks the status of main server.
	virtual ~Network_Handler();
private:
	void init_thread();
private:
	sf::TcpSocket _socket;
	Reader _reader;
};

#endif /* NETWORK_H_NETWORKHANDLER_H_ */
