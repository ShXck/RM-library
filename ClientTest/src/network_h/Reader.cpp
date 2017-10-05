#include "Reader.h"

Reader::Reader() { }

void Reader::read( std::string message, Temp_Ref_Container& container ) {

	std::string data = _encrypter.apply( message );

	std::cout << data << std::endl;

	int _instr = JSON_Handler::get_value( data.c_str(), "instruction" ).GetInt();

	if( _instr == 2 || _instr == 4 ) {
		container.set_ref( process_data( data.c_str(), _instr ) );
	}
}

rm::rmRef_h* Reader::process_data( const char* data, int instr ) {

	if( instr == 2 ){
		const char* data_key = JSON_Handler::get_value( data, "key" ).GetString();
		std::size_t data_size = JSON_Handler::get_value( data, "size" ).GetInt();
		std::string data_value = JSON_Handler::get_value( data, "value" ).GetString();
		rm::rmRef_h* new_ref = new rm::rmRef_h( strdup( data_value.c_str() ), data_size, data_key );
		return new_ref;
	} else {
		std::string data_value = JSON_Handler::get_value( data, "value_set" ).GetString();
		rm::rmRef_h* new_ref = new rm::rmRef_h( strdup( data_value.c_str() ), 0, "NO_KEY" );
		return new_ref;
	}

}


Reader::~Reader() {}

