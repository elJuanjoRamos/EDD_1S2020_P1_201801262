#include "PilaCambio.h"
#include <iostream>
#include "Cambio.h"
using namespace std;


PilaCambio::PilaCambio()
{
    //ctor
}

PilaCambio::~PilaCambio()
{
    //dtor
}






/*                        Apilar elemento
------------------------------------------------------------------------*/
void PilaCambio::push(Cambio* p, Cambio* n)
{
    Cambio* aux = n;  // apuntamos al nuevo nodo creado
    aux->sig = p;
    p = aux;
}

/*                Desapilar elemento(devuelve elemento)
------------------------------------------------------------------------*/
Cambio* PilaCambio::pop(Cambio* p)
{
    Cambio* num;
    Cambio* aux;

    aux = p;
    num = aux;   // asignamos el primer vamor de la pila

    p = aux->sig;
    delete(aux);

    return num;
}

/*                     Muestra elementos de la pila
------------------------------------------------------------------------*/
void PilaCambio::mostrar_pila(Cambio* p)
{
    Cambio* aux;
    aux = p;     // apunta al inicio de la lista

    while (aux != NULL)
    {
        cout << "\t" << aux->palabra<< endl;
        aux = aux->sig;
    }
}

/*                Eliminar todos los elementos de la pila
------------------------------------------------------------------------*/
void PilaCambio::destruir_pila(Cambio* p)
{
    Cambio* aux;

    while (p != NULL)
    {
        aux = p;
        p = aux->sig;
        delete(aux);
    }
}


