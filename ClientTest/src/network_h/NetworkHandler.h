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
#include "TempRefContainer.h"
#include "Encrypter.h"

class Network_Handler {
public:
	Network_Handler();
	void make_connection();
	void wait_for_response();
	void send( std::string message );
	void check_server_status();  // checks the status of main server.
	rm::rmRef_h* get_resource();
	virtual ~Network_Handler();
private:
	sf::TcpSocket _socket;
	Reader _reader;
	Temp_Ref_Container ref_container;
	Encrypter _encrypter;
};

#endif /* NETWORK_H_NETWORKHANDLER_H_ */
