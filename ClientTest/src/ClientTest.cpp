#include <iostream>
#include <string>
#include "lib_ops/RMlib.h"
#include "data_structs/LinkedList.h"

void process( int command , rm::RM_lib& rm_lib ) {

	switch( command ) {
	case 1: {
		rm_lib.rm_init( 1,1,1,1 );
		break;
	}
	case 2: {
		std::string _name;
		std::string _value;
		std::cout << "Enter the name: " << std::endl;
		std::getline( std::cin, _name );
		std::cout << "Enter the value: " << std::endl;
		std::getline( std::cin, _value );

		rm_lib.rm_new( _name.c_str() , &_value , sizeof( _value ) );
		break;
	}
	case 3: {
		std::string _key;
		std::cout << "Enter the key: " << std::endl;
		std::getline( std::cin, _key );
		rm_lib.rm_get( _key.c_str() );
		break;
	}
	case 4: {
		std::string _key;
		std::cout << "Enter the key: " << std::endl;
		std::getline( std::cin, _key );
		rm_lib.rm_delete( _key.c_str() );
		break;
	}
	case 5:
		std::cout << "Type the keys to be retrieved! Type . to exit!" << std::endl;
		std::string _text;
		Linked_List <std::string> _keys;
		while( true ) {
			std::cout << "KEY:" << std::endl;
			std::getline( std::cin, _text );
			if( _text == "." ) break;
			_keys.add( _text );
		}
		rm_lib.rm_get_set( _keys );
		break;
	}
}

int main() {

	rm::RM_lib _lib;
	std::string _option;

	while ( true ) {
		std::cout << "WHat would you like to do?" << "\n\t 1. Connect." << "\n\t 2. Create value."
					<< "\n\t 3. Get value."  << "\n\t 4. Delete value. " << "\n\t 5. Get set of values" << std::endl;

		std::getline( std::cin, _option );

		process( std::stoi( _option ), _lib );

	}

	return 0;
}
