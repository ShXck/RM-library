#ifndef NETWORK_H_READER_H_
#define NETWORK_H_READER_H_
#include <SFML/Network.hpp>
#include <string>
#include <iostream>
#include "JSONHandler.h"
#include <exception>
#include "Encrypter.h"
#include "../lib_ops/rmRefh.h"

class Reader {
public:
	Reader();
	void read( std::string message );
	rm::rmRef_h process_data( const char* data );
	virtual ~Reader();
private:
	Encrypter _encrypter;
};

#endif /* NETWORK_H_READER_H_ */
