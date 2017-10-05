#ifndef NETWORK_H_READER_H_
#define NETWORK_H_READER_H_
#include <SFML/Network.hpp>
#include <string>
#include <iostream>
#include "JSONHandler.h"
#include <exception>
#include "Encrypter.h"
#include "../lib_ops/rmRefh.h"
#include "TempRefContainer.h"

class Reader {
public:
	Reader();
	/**
	 * Lee los mensajes provenientes del servidor.
	 * @param message el mensaje entrante.
	 * @param container el contenedor temporal para guardar la respuesta.
	 */
	void read( std::string message, Temp_Ref_Container& container );
	/**
	 * Procesa la información de la respuesta del servidor.
	 * @param data la infromación.
	 * @param instr la instrucción por realizar.
	 * @return una estructura con la información.
	 */
	rm::rmRef_h* process_data( const char* data, int instr );
	virtual ~Reader();
private:
	Encrypter _encrypter;
};

#endif /* NETWORK_H_READER_H_ */
