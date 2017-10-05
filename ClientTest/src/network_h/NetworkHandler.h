#ifndef NETWORK_H_NETWORKHANDLER_H_
#define NETWORK_H_NETWORKHANDLER_H_
#define PORT_M 8000
#define PORT_HA 7500
#include <SFML/Network.hpp>
#include <string>
#include <iostream>
#include "../lib_ops/rmRefh.h"
#include "Reader.h"
#include "JSONHandler.h"
#include <thread>
#include <future>
#include "TempRefContainer.h"
#include "Encrypter.h"

class Network_Handler {
public:
	Network_Handler();
	/**
	 * Se conecta al servidor principal.
	 */
	void connect_to_main();
	/**
	 * Se conecta al servidor secundario.
	 */
	void connect_to_ha();
	/**
	 * Espera la respuesta del servidor.
	 */
	void wait_for_response();
	/**
	 * Espera por la respuestas al mensaje de verificación.
	 */
	void wait_for_check_response();
	/**
	 * Envía el mensaje al servidor.
	 * @param message el mensaje a enviar.
	 */
	void send( std::string message );
	/**
	 * Envía un mensaje para verificar si el servidor está funcionando.
	 */
	void check_server_status();
	/**
	 * Obtiene una estructura con la información de la última petición.
	 * @return
	 */
	rm::rmRef_h* get_resource();
	virtual ~Network_Handler();
private:
	sf::TcpSocket _socket;
	Reader _reader;
	Temp_Ref_Container ref_container;
	Encrypter _encrypter;
};

#endif /* NETWORK_H_NETWORKHANDLER_H_ */
