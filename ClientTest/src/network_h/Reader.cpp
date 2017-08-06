#include "Reader.h"

Reader::Reader() { }

void Reader::read( std::string message, Temp_Ref_Container& container ) {

	std::cout << "Message: " << message << std::endl;

	std::string __data__ = _encrypter.apply( message );

	const char* data = _encrypter.apply( message ).c_str();

	std::cout << "DATA: "<< __data__ << std::endl;

	int _instr = JSON_Handler::get_value( data, "instruction" ).GetInt();

	try {
		check_for_exception( JSON_Handler::get_value( data, "error" ).GetBool(), JSON_Handler::get_value( data, "msg" ).GetString() );
	} catch (Data_Excp& e ) {
		e.what();
	}
	if( _instr == 2 ) {
		rm::rmRef_h new_ref = process_data( _encrypter.apply( message ).c_str() );
		container.set_ref( &new_ref );
	}
}

rm::rmRef_h Reader::process_data( const char* data ) {

	const char* data_key = JSON_Handler::get_value( data, "key" ).GetString();
	std::size_t data_size = JSON_Handler::get_value( data, "size" ).GetInt();
	std::string data_value = JSON_Handler::get_value( data, "value" ).GetString();

	void* value_ptr = &data_value;

	rm::rmRef_h new_ref( data_key , value_ptr, data_size );
	return new_ref;
}

void Reader::check_for_exception( bool error, std::string msg  ) {
	if ( error ) {
		throw Data_Excp( msg.c_str() );
	}
}

Reader::~Reader() {
	// TODO Auto-generated destructor stub
}

