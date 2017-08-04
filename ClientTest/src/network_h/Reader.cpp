/*
 * Reader.cpp
 *
 *  Created on: Jul 31, 2017
 *      Author: marcelo
 */

#include "Reader.h"

Reader::Reader() {
	// TODO Auto-generated constructor stub

}

void Reader::read( std::string message ) {

	rm::rmRef_h new_ref = process_data( message.c_str() );

}

rm::rmRef_h Reader::process_data( const char* data ) {

	const char* data_key = JSON_Handler::get_value( data, "key" ).GetString();
	std::size_t data_size = JSON_Handler::get_value( data, "size" ).GetInt();
	std::string data_value = JSON_Handler::get_value( data, "value" ).GetString();

	void* value_ptr = &data_value;

	rm::rmRef_h new_ref( data_key , value_ptr, data_size );
	return new_ref;
}

Reader::~Reader() {
	// TODO Auto-generated destructor stub
}

