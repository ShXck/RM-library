#include "util.hpp"

namespace util {

	bool is_int( const std::string& a ) {
		if( a.empty() || ( ( !std::isdigit( a[0] ) ) && ( a[0] != '-' ) && ( a[0] != '+' ) ) ) return false;

		char* _p;
		std::strtol( a.c_str(), &_p, 10 );

		return (*_p == 0);
	}

	bool is_float( const std::string& a ) {
		char* end_ptr = 0;
		std::strtod( a.c_str(), &end_ptr );

		if( *end_ptr != '\0' || end_ptr == a.c_str() ) return false;

		return true;
	}

	std::size_t check_size( const std::string& a ) {
		if( is_int( a ) ) {
			return sizeof( int );
		} else if( is_float( a) ) {
			return sizeof( float );
		} else {
			return sizeof( char *);
		}
	}

	std::string create_random_key( std::string::size_type length ) {
	    static auto& _chrs = "0123456789"
	            "abcdefghijklmnopqrstuvwxyz"
	            "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	    thread_local static std::mt19937 rg{ std::random_device{ }( ) };
	    thread_local static std::uniform_int_distribution<std::string::size_type> pick( 0, sizeof( _chrs ) - 2 );

	    std::string _result;

	    _result.reserve( length ) ;

	    while( length-- )
	        _result += _chrs[ pick( rg ) ];

	    return _result;
	}
}

