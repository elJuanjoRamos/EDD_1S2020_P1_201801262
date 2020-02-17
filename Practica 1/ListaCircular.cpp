#include "ListaCircular.h"
ListaCircular::ListaCircular() {
	primero = NULL;
	ultimo = NULL;
}

int index = 1;

void ListaCircular::insertar(string n, string r) {
	NodoCircular* nuevo = new NodoCircular(index, n, r);
	if (primero == NULL) {
		primero = nuevo;
		primero->enlace = primero;
		ultimo = primero;
	}
	else {
		ultimo->enlace = nuevo;
		nuevo->enlace = primero;
		ultimo = nuevo;
	}
	index++;
}

void ListaCircular::recorrer() {
	NodoCircular* p;
	if (ultimo != NULL)
	{
		p = ultimo->enlace;
		do {
			cout << "\t" << p->index << "." << p->nombre << "\t" << p->ruta;
			p = p->enlace;
		} while (p != primero);
	}
	else {
		cout << "\n\t La lista esta vacia";
	}
}

void ListaCircular::limpiar() {
	primero = NULL;
	ultimo = NULL;
}

bool ListaCircular::esVacia() {
	if (primero == NULL)
	{
		return true;
	}
	else {
		return false;
	}
}

string ListaCircular::buscarArchivo(int d) {
	NodoCircular* p;
	if (ultimo != NULL)
	{
		p = ultimo->enlace;
		do {
			if (p->index == d)
			{
				return p->ruta;
			}
			else {
				p = p->enlace;
			}
		} while (p != primero);
	}
	else {
		return "NULL";
	}
	return "NULL";
}