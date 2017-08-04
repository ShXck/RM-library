#include "NetworkHandler.h"

Network_Handler::Network_Handler() {
}

void Network_Handler::make_connection() {
	sf::IpAddress _address = sf::IpAddress::getLocalAddress();
	_socket.setBlocking( false );
	_socket.connect( _address, PORT );
	init_thread();
}

void Network_Handler::init_thread() {
	std::thread t( &Network_Handler::run, this );
	t.detach();
}

void Network_Handler::run() {

	std::cout << "running..." << std::endl;

	sf::Packet _packet;
	std::string _message;

	while ( true ) {
		if ( _socket.receive( _packet ) == sf::Socket::Done ) {
			if( _packet >> _message ) {
				_reader.read( _message );
			}
		}
	}

}

void Network_Handler::send( std::string message ) {
	sf::Packet _packet;
	_packet << message;
	_socket.send( _packet );
}

void Network_Handler::check_server_status() {

}

Network_Handler::~Network_Handler() {
	// TODO Auto-generated destructor stub
}

