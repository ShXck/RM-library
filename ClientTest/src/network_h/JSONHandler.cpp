#include "JSONHandler.h"

JSON_Handler::JSON_Handler() {
}

std::string JSON_Handler::build_new( const char* key, void* value, std::size_t size ) {

	rapidjson::Document _doc;
	_doc.SetObject();
	rapidjson::Document::AllocatorType& _alloc = _doc.GetAllocator();

	std::string *casted_value = static_cast<std::string*>( value );

	{
		rapidjson::Value str_key;
		str_key.SetString( key, _alloc );
		_doc.AddMember( "key", str_key, _alloc );
	}

	{
		rapidjson::Value value_str;
		value_str.SetString( casted_value->c_str(), _alloc );
		_doc.AddMember( "value", value_str, _alloc );
	}

	_doc.AddMember( "size", size, _alloc );
	_doc.AddMember( "instruction", "create", _alloc );

	rapidjson::StringBuffer str_buffer;
	rapidjson::Writer<rapidjson::StringBuffer> _writer( str_buffer );
	_doc.Accept( _writer );

	return str_buffer.GetString();
}

std::string JSON_Handler::build_deleted( const char* key ) {

	rapidjson::Document _doc;
	_doc.SetObject();
	rapidjson::Document::AllocatorType& _alloc = _doc.GetAllocator();

	{
		rapidjson::Value str_key;
		str_key.SetString( key, _alloc );
		_doc.AddMember( "key", str_key, _alloc );
	}

	_doc.AddMember( "instruction", "delete", _alloc );

	rapidjson::StringBuffer str_buffer;
	rapidjson::Writer<rapidjson::StringBuffer> _writer( str_buffer );
	_doc.Accept( _writer );

	return str_buffer.GetString();
}

std::string JSON_Handler::build_get( const char* key ) {

	rapidjson::Document _doc;
	_doc.SetObject();
	rapidjson::Document::AllocatorType& _alloc = _doc.GetAllocator();

	{
		rapidjson::Value str_key;
		str_key.SetString( key, _alloc );
		_doc.AddMember( "key", str_key, _alloc );
	}

	_doc.AddMember( "instruction", "get", _alloc );

	rapidjson::StringBuffer str_buffer;
	rapidjson::Writer<rapidjson::StringBuffer> _writer( str_buffer );
	_doc.Accept( _writer );

	return str_buffer.GetString();
}

rapidjson::Value& JSON_Handler::get_value( const char* json, const char* json_key ) {

	rapidjson::Document _doc;
	_doc.Parse( json );

	rapidjson::Document::AllocatorType& _alloc = _doc.GetAllocator();

	rapidjson::Value str_key;
	str_key.SetString( json_key, _alloc );

	rapidjson::Value& _val = _doc[ str_key ];

	return _val;

}

JSON_Handler::~JSON_Handler() {
	// TODO Auto-generated destructor stub
}

