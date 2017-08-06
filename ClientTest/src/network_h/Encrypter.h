#ifndef NETWORK_H_ENCRYPTER_H_
#define NETWORK_H_ENCRYPTER_H_
#include <string>
#include <iostream>

class Encrypter {
public:
	Encrypter();
	std::string apply( std::string data );
	virtual ~Encrypter();
};

#endif /* NETWORK_H_ENCRYPTER_H_ */
