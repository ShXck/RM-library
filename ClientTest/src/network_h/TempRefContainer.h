#ifndef NETWORK_H_TEMPREFCONTAINER_H_
#define NETWORK_H_TEMPREFCONTAINER_H_
#include "../lib_ops/rmRefh.h"


class Temp_Ref_Container {
public:
	Temp_Ref_Container();
	/**
	 * Verifica si el contenedor tiene algo.
	 * @return si tiene algo o no.
	 */
	bool is_null();
	/**
	 *
	 * Asigna el valor de la referencia.
	 * @param ref la referencia nueva.
	 */
	void set_ref( rm::rmRef_h* ref );
	/**
	 * @return la estructura con la información.
	 */
	rm::rmRef_h* ref();
	virtual ~Temp_Ref_Container();
private:
	rm::rmRef_h* tmp_ref;
};

#endif /* NETWORK_H_TEMPREFCONTAINER_H_ */
