#ifndef NETWORK_H_JSONHANDLER_H_
#define NETWORK_H_JSONHANDLER_H_

#define NEW 1
#define GET 2
#define DELETE 3
#define VAL_SET 4
#define REPLACE 5
#define DISCONNECT 6

#include <cstddef>
#include <string>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>
#include "../data_structs/LinkedList.h"


class JSON_Handler {
	typedef rapidjson::Document::AllocatorType& Alloc;
	typedef rapidjson::Writer< rapidjson::StringBuffer > Writer;
public:
	JSON_Handler();
	/**
	 * Construye un JSON con la información del nuevo elemento.
	 * @param key la llave del elemento.
	 * @param value el valor del elemento.
	 * @param id la id del usuario.
	 * @param size el tamaño del valor.
	 * @return un JSON con la información.
	 */
	static std::string build_new( const char* key, void* value, char* id, std::size_t size );
	/**
	 * Construye un JSON con la información del elemento deseado.
	 * @param key la llave del elemento.
	 * @return un json con la información.
	 */
	static std::string build_new( const char* key, std::string value, char* id, std::size_t size );
	/**
	 * Construye un JSON con la información del elemento deseado.
	 * @param key la llave del elemento.
	 * @return un json con la información.
	 */
	static std::string build_get( const char* key );
	/**
	 * Construye un JSON con la llave del elemento a eliminar.
	 * @param key la llave del elemento.
	 * @return un json con la llave del elemento.
	 */
	static std::string build_deleted( const char* key );
	/**
	 * Construye un JSON con un conjunto de llaves por obtener.
	 * @param list la lista de llaves.
	 * @return un json con el conjunto de llaves.
	 */
	static std::string build_set( Linked_List < std::string > list );
	/**
	 * Construye un JSON con el nuevo valor del elemento.
	 * @param key la llave del elemento.
	 * @param new_val el nuevo valor.
	 * @return un json con la nueva información del elemento.
	 */
	static std::string build_replace( const char* key, void* new_val );
	/**
	 * Construye un JSON con la clave del cliente.
	 * @param key la llave del cliente.
	 * @return un json con la llave del cliente.
	 */
	static std::string build_dc_msg( char* key );
	/**
	 * Construye un JSON con un mensaje de verificación.
	 * @return un json con el mensaje.
	 */
	static std::string build_check_msg();
	/**
	 * OBtiene un valor del json dado.
	 * @param json el mensaje json.
	 * @param json_key la clave especifica del valor dentro del json.
	 * @return el valor pedido.
	 */
	static rapidjson::Value& get_value ( const char* json, const char* json_key );
	virtual ~JSON_Handler();
};

#endif /* NETWORK_H_JSONHANDLER_H_ */
