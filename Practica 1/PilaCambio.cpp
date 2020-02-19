#include "PilaCambio.h"
#include <iostream>
#include <fstream>
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
/*void PilaCambio::push(Cambio* p, Cambio* n)
{
    Cambio* aux = n;  // apuntamos al nuevo nodo creado
    aux->sig = p;
    p = aux;
}*/

void PilaCambio::push(Cambio* p)
{
    Cambio* n;
    n = p;
    n->sig = ptrPila;
    ptrPila = n;
}

bool PilaCambio::pilaVacia()
{
    return ptrPila == NULL;
}

/*                Desapilar elemento(devuelve elemento)
------------------------------------------------------------------------*/

Cambio* PilaCambio::pop()
{
    if (pilaVacia())
        throw "Pila vacía, no se puede extraer.";
    Cambio *aux = ptrPila;
    ptrPila = ptrPila->sig;
    return aux;
}

/*                     Muestra elementos de la pila
------------------------------------------------------------------------*/
void PilaCambio::mostrar_pila()
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
void PilaCambio::destruir_pila()
{
    Cambio* aux;

    while (ptrPila != NULL)
    {
        aux = ptrPila;
        ptrPila = aux->sig;
        delete(aux);
    }
}

void PilaCambio::GenerarGrafica(string nombre) {
	string archivoCabeza = "digraph G {"
		"node[shape = box];\n";

	string nodos;
	string juntarNodos;
	string masNodos;

	ofstream ofs(nombre + ".dot", ofstream::out);

	Cambio* aux;
	aux = ptrPila;     // apunta al inicio de la lista
	int contador = 0;
	string texto = "";


	if (!pilaVacia()) {
		while (aux != NULL)
		{
			cout << "\t" << aux->palabra << endl;
			nodos = nodos + "Nodo" + to_string(contador) + " [label =  " + '"' + "Palabra Buscada:  " + aux->buscar + " \n" +
				"Reemplazada por: " + aux->reemplazar + "\n"
				"Estado:  No revertido\n"
				"Palabra: " + aux->palabra + "\n"
				"Posicion: " + to_string(aux->x) + "-" + to_string(aux->y) + "\n"
				+ '"' + "]";
			aux = aux->sig;

			masNodos = masNodos + "Nodo" + to_string(contador) + ";";
			contador++;
		}

		for (size_t i = 0; i < contador - 1; i++)
		{
			juntarNodos = juntarNodos + "Nodo" + to_string(i) + "->Nodo" + to_string(i + 1);

		}

		//std::cout << texto;
		texto = archivoCabeza + nodos + juntarNodos + "{rank=same; " + masNodos + "}}";
		//std::cout << texto;
		ofs << texto;

		ofs.close();
		system("dot -Tjpg -o PilaCambio.png PilaCambio.dot");
		system("PilaCambio.png");

	}
	else {
		cout << "Pila vacia";
	}



}