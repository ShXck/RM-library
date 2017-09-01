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
	static std::string build_new( const char* key, void* value, char* id, std::size_t size );
	static std::string build_get( const char* key );
	static std::string build_deleted( const char* key );
	static std::string build_set( Linked_List < std::string > list );
	static std::string build_replace( const char* key, void* new_val );
	static std::string build_dc_msg( char* key );
	static std::string build_check_msg();
	static rapidjson::Value& get_value ( const char* json, const char* json_key );
	virtual ~JSON_Handler();
};

#endif /* NETWORK_H_JSONHANDLER_H_ */
