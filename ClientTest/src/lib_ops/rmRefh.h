#ifndef LIB_OPS_RMREFH_H_
#define LIB_OPS_RMREFH_H_
#include <cstddef>
#include <string>
#include <iostream>

namespace rm {

class rmRef_h {
public:
	char* _value;
	std::size_t _size;
	const char* _key;
public:
	rmRef_h( char* value, std::size_t size, const char* key );
	bool operator != ( const rmRef_h& ref );
	bool operator == ( const rmRef_h& ref );
	friend std::ostream& operator << ( std::ostream& strm, const rmRef_h& ref );
	virtual ~rmRef_h();
};

} /* namespace rm */

#endif /* LIB_OPS_RMREFH_H_ */
