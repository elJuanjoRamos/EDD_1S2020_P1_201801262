#include "PilaRevertido.h"
#include <iostream>
#include "Cambio.h"
using namespace std;


PilaRevertido::PilaRevertido()
{
    //ctor
}

PilaRevertido::~PilaRevertido()
{
    //dtor
}


/*                        Apilar elemento
------------------------------------------------------------------------*/
/*void PilaRevertido::push(Cambio* p, Cambio* n)
{
    Cambio* aux = n;  // apuntamos al nuevo nodo creado
    aux->sig = p;
    p = aux;
}*/

void PilaRevertido::push(Cambio* p)
{
    Cambio* n;
    n = p;
    n->sig = ptrPila;
    ptrPila = n;
}

bool PilaRevertido::pilaVacia()
{
    return ptrPila == NULL;
}

/*                Desapilar elemento(devuelve elemento)
------------------------------------------------------------------------*/

Cambio* PilaRevertido::pop()
{
    if (pilaVacia())
        throw "Pila vacía, no se puede extraer.";
    Cambio* aux = ptrPila;
    ptrPila = ptrPila->sig;
    return aux;
}

/*                     Muestra elementos de la pila
------------------------------------------------------------------------*/
void PilaRevertido::mostrar_pila()
{
    if (pilaVacia()) {
        std::cout << "Pila vacía, no se puede extraer.";
    }
    else {
        Cambio* aux;
        aux = ptrPila;     // apunta al inicio de la lista

        while (aux != NULL)
        {
            cout << "\t" << aux->palabra << endl;
            aux = aux->sig;
        }
    }
}

/*                Eliminar todos los elementos de la pila
------------------------------------------------------------------------*/
void PilaRevertido::destruir_pila()
{
    Cambio* aux;

    while (ptrPila != NULL)
    {
        aux = ptrPila;
        ptrPila = aux->sig;
        delete(aux);
    }
}


