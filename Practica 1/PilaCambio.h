#include "iostream"
#include <windows.h>
#include <stdio.h>
#include <string>
#include <vector>
#include "Cambio.h"
using namespace std;


class PilaCambio
{
public:
    PilaCambio();
    Cambio* ptrPila = NULL;
    void push(Cambio* p, Cambio* n);
    Cambio* pop(Cambio* p);
    void mostrar_pila(Cambio* p);
    void destruir_pila(Cambio* p);
    virtual ~PilaCambio();
};
