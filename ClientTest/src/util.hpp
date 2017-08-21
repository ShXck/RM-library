#ifndef UTIL_HPP_
#define UTIL_HPP_
#include <cstddef>
#include <string>
#include <random>

namespace util {

	bool is_int( const std::string& a );
	bool is_float( const std::string& a );
	std::size_t check_size( const std::string& a );
	std::string create_random_key( std::string::size_type length );

}



#endif /* UTIL_HPP_ */
