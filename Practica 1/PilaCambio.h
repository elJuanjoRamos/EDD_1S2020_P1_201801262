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
    void push(Cambio* p);
    bool pilaVacia();
    Cambio* pop();
    void mostrar_pila();
    void destruir_pila();
	void GenerarGrafica(string nombre);
    virtual ~PilaCambio();
};
