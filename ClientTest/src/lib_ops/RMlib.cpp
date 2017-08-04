#include "RMlib.h"

namespace rm {

RM_lib::RM_lib() {
	// TODO Auto-generated constructor stub

}

void RM_lib::rm_init( int ip, int port, int ipHA, int portHA ) {
	_handler.make_connection();
}

void RM_lib::rm_new( const char* key, void* value, std::size_t size ) {
	std::string new_resource = JSON_Handler::build_new( key, value, size );
	_handler.send( new_resource );
}


rmRef_h RM_lib::rm_get( const char* key ) {
	std::string get_resource = JSON_Handler::build_get( key );
	_handler.send( get_resource );

}

void RM_lib::rm_delete( rmRef_h* handler ) {
	std::string deleted_resource = JSON_Handler::build_deleted( handler->key() );
	_handler.send( deleted_resource );
}

RM_lib::~RM_lib() {

}

} /* namespace rm */