#include "iostream"
#include <windows.h>
#include <stdio.h>
#include <string>
#include <vector>
#include "Cambio.h"
using namespace std;


class PilaRevertido
{
public:
    PilaRevertido();
    Cambio* ptrPila = NULL;
    void push(Cambio* p);
    bool pilaVacia();
    Cambio* pop();
    void mostrar_pila();
    void destruir_pila();
    virtual ~PilaRevertido();
};
