#include "rmRefh.h"

namespace rm {

rmRef_h::rmRef_h( const char* key, void* value, std::size_t size ) : _key( key ), _value( value ), _size( size ) {
}

bool rmRef_h::operator == ( const rmRef_h& rm_h ) {
	if ( _key == rm_h.key() ) {
		return true;
	}
	return false;
}

bool rmRef_h::operator !=( const rmRef_h& rm_h ) {
	if ( _key != rm_h.key() ) {
		return true;
	}
	return false;
}

std::size_t rmRef_h::size() {
	return _size;
}

const char* rmRef_h::key() const {
	return _key;
}

void* rmRef_h::value() {
	return _value;
}

rmRef_h::~rmRef_h() {
	// TODO Auto-generated destructor stub
}

} /* namespace rm */
