#include "NodoCircular.h"

NodoCircular::NodoCircular(int i, string n, string r) {
	index = i;
	nombre = n;
	ruta = r;
	enlace = this;
}