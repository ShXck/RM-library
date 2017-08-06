#ifndef NETWORK_H_READER_H_
#define NETWORK_H_READER_H_
#include <SFML/Network.hpp>
#include <string>
#include <iostream>
#include "../lib_ops/rmRefh.h"
#include "JSONHandler.h"
#include "TempRefContainer.h"
#include <exception>
#include "Encrypter.h"

struct Data_Excp : public std::exception {
	const char* _message;
	Data_Excp( const char* message ) : _message( message ) {}
	const char* what() const throw () {
		return _message;
	}
};

class Reader {
public:
	Reader();
	void read( std::string message, Temp_Ref_Container& container );
	rm::rmRef_h process_data( const char* data );
	void check_for_exception( bool error, std::string msg );
	virtual ~Reader();
private:
	Encrypter _encrypter;
};

#endif /* NETWORK_H_READER_H_ */
