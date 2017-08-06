#include "NetworkHandler.h"

Network_Handler::Network_Handler() {
}

void Network_Handler::make_connection() {
	sf::IpAddress _address = sf::IpAddress::getLocalAddress();
	_socket.setBlocking( false );
	_socket.connect( _address, PORT );
}


void Network_Handler::wait_for_response() {

	sf::Packet _packet;
	std::string _message;
	bool received = false;

	while ( !received ) {
		if ( _socket.receive( _packet ) == sf::Socket::Done ) {
			if( _packet >> _message ) {
				_reader.read( _message, ref_container );
				received = true;
			}
		}
	}
}

void Network_Handler::send( std::string message ) {
	sf::Packet _packet;
	_packet << _encrypter.apply(message);
	_socket.send( _packet );
}

void Network_Handler::check_server_status() {

}

rm::rmRef_h* Network_Handler::get_resource() {
	return ref_container.ref();
}

Network_Handler::~Network_Handler() {
	// TODO Auto-generated destructor stub
}

