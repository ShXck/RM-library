#include "Reader.h"

Reader::Reader() { }

void Reader::read( std::string message ) {

	std::string data = _encrypter.apply( message );

	std::cout << data << std::endl;

	int _instr = JSON_Handler::get_value( data.c_str(), "instruction" ).GetInt();

	if( _instr == 2 ) {
		rm::rmRef_h new_ref = process_data( data.c_str() );
	}
}

rm::rmRef_h Reader::process_data( const char* data ) {

	const char* data_key = JSON_Handler::get_value( data, "key" ).GetString();
	std::size_t data_size = JSON_Handler::get_value( data, "size" ).GetInt();
	std::string data_value = JSON_Handler::get_value( data, "value" ).GetString();

	void* value_ptr = &data_value;

	rm::rmRef_h new_ref( value_ptr, data_size, data_key );
	return new_ref;
}


Reader::~Reader() {
	// TODO Auto-generated destructor stub
}

