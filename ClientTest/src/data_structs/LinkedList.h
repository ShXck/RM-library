#ifndef DATA_STRUCTS_LINKEDLIST_H_
#define DATA_STRUCTS_LINKEDLIST_H_
#include <iostream>
#include <cstdio>
#include <cstdlib>

template <class T>
struct Node {
	T _data;
	Node <T> *_next;
	Node ( T data ):_data( data ) {
		_next = nullptr;
	}
};

template<class T>
class Linked_List {
private:
	Node<T> *_head;
	int _size;
private:
	void remove_head() {
		Node<T> *_temp = _head;
		_head = _head->_next;
		delete _temp;
	}
public:
	Linked_List() {
		_head = nullptr;
		_size = 0;
	}

	void add( T data ) {
		Node<T>* _new = new Node<T>( data );
		if( is_empty() ) {
			_head = _new;
		} else {
			Node<T> *_current = _head;
			while( _current->_next != nullptr ) {
				_current = _current->_next;
			}
			_current->_next = _new;
		}
		_size++;
	}

	void add_first( T data ) {
		Node<T>* _new = new Node<T>( data );
		if( is_empty() ) {
			_head = _new;
		} else {
			_new->_next = _head;
			_head = _new;
		}
		_size++;
	}

	void add_at( int pos, T data ) {
		Node<T>* _new = new Node<T>( data );

		if( pos > _size || pos < 0 || (is_empty() && pos != 0) ){
			throw std::invalid_argument( "Impossible action. Invalid position value" );
		} else {
			Node<T> *_current = _head;
			int i = 0;
			while ( i < (pos - 1) ) {
				_current = _current->_next;
				i++;
			}
			_new->_next = _current->_next;
			_current->_next = _new;
		}
		_size++;
	}

	void remove( T data ) {

		std::runtime_error not_found( "Element not found" );

		if( is_empty() ) {
			throw not_found;
		} else if( _head->_data == data ) {
			remove_head();
		} else {
			Node<T> *_current = _head;
			while( _current->_next != nullptr ) {
				if( _current->_next->_data == data ){
					Node<T> *_temp = _current->_next;
					_current->_next = _current->_next->_next;
					delete _temp;
					_size--;
					return;
				} else {
					_current = _current->_next;
				}
			}
			throw not_found;
		}
	}

	void remove_at( int pos ) {
		if( pos > _size || pos < 0 || (is_empty() && pos != 0) ){
			throw std::invalid_argument( "Impossible action. Invalid position value" );
		} else if( pos == 0 ) {
			remove_head();
		} else {
			Node<T> *_current = _head;
			int i = 0;
			while( i < (pos - 1) ) {
				_current = _current->_next;
				i++;
			}
			Node<T> *_temp = _current->_next;
			_current->_next = _current->_next->_next;
			delete _temp;
		}
		_size--;
	}

	bool contains( T data ) {
		if( is_empty() ) {
			return false;
		} else {
			Node<T> *_current = _head;
			while( _current != nullptr ) {
				if( _current->_data == data ) {
					return true;
				} else {
					_current = _current->_next;
				}
			}
		}
		return false;
	}

	T& get( T data ) {

		std::runtime_error not_found( "Element not found" );

		if( is_empty() ) {
			throw not_found;
		} else {
			Node<T> *_current = _head;
			while( _current != nullptr ) {
				if( _current->_data == data ) {
					return _current->_data;
				}
				_current = _current->_next;
			}
		}
		throw not_found;
	}

	T* last() {
		if( is_empty() ) {
			return nullptr;
		} else {
			Node<T>* _current = _head;
			while( _current->_next != nullptr ) {
				_current = _current->_next;
			}
			return &_current->_data;
		}
	}

	T* peek() {
		if( is_empty() ) {
			return nullptr;
		} else {
			return *_head->_data;
		}
	}

	Node<T>* head() {
		if( is_empty() ) {
			return nullptr;
		} else {
			return _head;
		}
	}

	void display() {
		if( is_empty() ) {
			std::cout << "The list is empty" << std::endl;
		} else  {
			Node<T> *_current = _head;
			while( _current != nullptr ) {
				std::cout << _current->_data << " ";
				_current = _current->_next;
			}
			std::cout << "" << std::endl;
		}
	}

	bool is_empty() const {
		return _size == 0;
	}

	const int& size() const {
		return _size;
	}


};







#endif /* DATA_STRUCTS_LINKEDLIST_H_ */
