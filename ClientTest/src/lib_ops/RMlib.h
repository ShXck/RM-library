#ifndef LIB_OPS_RMLIB_H_
#define LIB_OPS_RMLIB_H_

#define PORT_M 8000
#define PORT_HA 7500

#include <cstddef>
#include <string>
#include <iostream>
#include "rmRefh.h"
#include "../network_h/NetworkHandler.h"
#include "../network_h/JSONHandler.h"
#include "../data_structs/LinkedList.h"
#include "../util.hpp"

namespace rm {


class RM_lib {
public:
	RM_lib();
	/**
	 * Inicial la conexión con el servidor principal.
	 * @param ip_m la ip principal.
	 * @param port_m el puerto principal.
	 * @param ip_HA la ip pasiva.
	 * @param port_HA el puerto pasivo.
	 */
	void rm_init( int ip_m, int port_m, int ip_HA, int port_HA );
	/**
	 * Envía una petición al servidor para guardar un nuevo elemento.
	 * @param key la id del elemento.
	 * @param value el valor del elemento.
	 * @param size el tamaño del elemento.
	 */
	void rm_new( const char* key, void* value, std::size_t size );
	/**
	 * Envía una petición para obtener el valor de un elemento guardado,
	 * @param key la id del elemento.
	 * @return una estructura con la información requerida.
	 */
	void rm_new( const char* key, std::string value, std::size_t size );
	/**
	 * Envía una petición para obtener el valor de un elemento guardado,
	 * @param key la id del elemento.
	 * @return una estructura con la información requerida.
	 */
	rmRef_h* rm_get( const char* key );
	/**
	 * Envía una petición para obtener un conjunto de valores.
	 * @param keys el conjunto de id de los elementos.
	 * @return una estructura con la información.
	 */
	rmRef_h* rm_get_set( Linked_List< std::string > keys );
	/**
	 * Envía una petición para eliminar una elemento.
	 * @param key la llave por eliminar.
	 */
	void rm_delete( const char* key );
	/**
	 * Envía una petición para reemplazar el valor de un elemento.
	 * @param key la id del elemento.
	 * @param new_value la información nueva del elemento.
	 */
	void rm_replace( const char* key, void* new_value );
	/**
	 * Elimina todos los recursos asociados a un cliente.
	 */
	void rm_disconnect();
	virtual ~RM_lib();
private:
	Network_Handler _handler;
	char* client_id;
};

} /* namespace rm */

#endif /* LIB_OPS_RMLIB_H_ */
