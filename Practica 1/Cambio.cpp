#include "Cambio.h"

Cambio::Cambio()
{
}

Cambio::~Cambio()
{
}

Cambio::Cambio(string b, string r, bool e, string p, int x1, int y1) {
    palabra = p;
    buscar = b;
    reemplazar = r;
    estado = e;
    x = x1;
    y = y1;
    sig =  NULL;
}
