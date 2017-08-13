#include "rmRefh.h"

namespace rm {

rmRef_h::rmRef_h( void* value, std::size_t size, const char* key ) : _value( value ), _size( size ), _key( key )  { }

bool rmRef_h::operator !=( const rmRef_h& ref ) {
	if ( _key != ref._key ) {
		return true;
	}
	return false;
}

bool rmRef_h::operator ==( const rmRef_h& ref ) {
	if ( _key == ref._key ) {
		return true;
	}
	return false;
}

std::ostream& operator << ( std::ostream& strm, const rmRef_h& ref ) {
	strm << ref._key;
	return strm;
}

rmRef_h::~rmRef_h() {
	// TODO Auto-generated destructor stub
}

} /* namespace rm */
