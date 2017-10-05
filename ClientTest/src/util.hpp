#ifndef UTIL_HPP_
#define UTIL_HPP_
#include <cstddef>
#include <string>
#include <random>

namespace util {

	/**
	 * Verifica si un string es entero.
	 * @param a el string
	 * @return si es entero o no.
	 */
	bool is_int( const std::string& a );
	/**
	 * Verifica si un string es decimal.
	 * @param a el string
	 * @return si es decimal o no.
	 */
	bool is_float( const std::string& a );
	/**
	 * @param a el string.
	 * @return el tamaño real del valor.
	 */
	std::size_t check_size( const std::string& a );
	/**
	 * Crea un string aleatorio.
	 * @param length el largo deseado.
	 * @return el string construido.
	 */
	std::string create_random_key( std::string::size_type length );

}



#endif /* UTIL_HPP_ */
