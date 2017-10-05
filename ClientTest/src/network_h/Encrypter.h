#ifndef NETWORK_H_ENCRYPTER_H_
#define NETWORK_H_ENCRYPTER_H_
#include <string>
#include <iostream>

class Encrypter {
public:
	Encrypter();
	/**
	 * Encripta y desencripta los mensajes entrantes y salientes.
	 * @param data el mensaje por aplicar la acción.
	 * @return el mensaje desencriptado/encriptado.
	 */
	std::string apply( std::string data );
	virtual ~Encrypter();
};

#endif /* NETWORK_H_ENCRYPTER_H_ */
