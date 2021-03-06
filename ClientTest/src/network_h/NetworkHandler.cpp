#include "NetworkHandler.h"

Network_Handler::Network_Handler() { }

void Network_Handler::connect_to_main() {
	_socket.disconnect();
	sf::IpAddress _address = sf::IpAddress::getLocalAddress();
	_socket.setBlocking( false );
	_socket.connect( _address, PORT_M );
}

void Network_Handler::connect_to_ha() {
	std::cout << "CONNECTED TO HA" << std::endl;
	_socket.disconnect();
	sf::IpAddress _address = sf::IpAddress::getLocalAddress();
	_socket.setBlocking( false );
	_socket.connect( _address, PORT_HA );
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

rm::rmRef_h* Network_Handler::get_resource() {
	return ref_container.ref();
}

void Network_Handler::send( std::string message ) {
	sf::Packet _packet;
	_packet << _encrypter.apply(message);
	_socket.send( _packet );
}

void Network_Handler::check_server_status() {
	std::string check_msg = JSON_Handler::build_check_msg();
	send( check_msg );
	wait_for_check_response();
}

void Network_Handler::wait_for_check_response() {

	sf::Packet _packet;
	std::string _message;

	std::time_t _start, _end;
	double _elapsed;

	time( &_start );

	while( _elapsed < 2 ) {
		time( &_end );
		_elapsed = difftime( _end, _start );
		if ( _socket.receive( _packet ) == sf::Socket::Done ) {
			if( _packet >> _message ) {
				_reader.read( _message, ref_container );
				break;
			}
		}
	}

	if( _elapsed >= 2 ) {
		connect_to_ha();
	}
}


Network_Handler::~Network_Handler() { }

