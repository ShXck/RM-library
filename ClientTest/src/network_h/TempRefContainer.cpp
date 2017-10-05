#include "TempRefContainer.h"

Temp_Ref_Container::Temp_Ref_Container() : tmp_ref( nullptr ) { }

void Temp_Ref_Container::set_ref( rm::rmRef_h* ref ) {
	tmp_ref = ref;
}

bool Temp_Ref_Container::is_null() {
	return tmp_ref == nullptr;
}

rm::rmRef_h* Temp_Ref_Container::ref() {
	return tmp_ref;
}

Temp_Ref_Container::~Temp_Ref_Container() {
	delete tmp_ref;
}
