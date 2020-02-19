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
			cout << "\t\t\t\t" << p->index << "." << p->nombre << "\t" << p->ruta << "\n";
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

void ListaCircular::GenerarGrafica(string nombre) {
	string archivoCabeza = "digraph G {"
		"node[shape = box];\n";

	string nodos;
	string juntarNodos;
	string masNodos;

	ofstream ofs(nombre + ".dot", ofstream::out);

	NodoCircular* aux;
	aux = primero;     // apunta al inicio de la lista
	int contador = 0;
	string texto = "";


	if (ultimo != NULL)
	{
		aux = ultimo->enlace;
		do {
			//string ruta = aux->ruta.replace('\\', '\\\\');

			nodos = nodos + "Nodo" + to_string(aux->index) + "[label = " + '"' +"Nombre: " + aux->nombre + " " +
				"\nRuta: \n\t-" + aux->ruta + '"' + "]\n";
			masNodos = masNodos + "Nodo" + to_string(aux->index) + ";";
			aux = aux->enlace;
			contador++;
		} while (aux != primero);
	}
	else {
		cout << "\n\t La lista esta vacia";
	}
	for (size_t i = 1; i < contador; i++)
	{
		juntarNodos = juntarNodos + "Nodo" + to_string(i) + "->Nodo" + to_string(i + 1) +"\n";
	}
	juntarNodos = juntarNodos + "Nodo" + to_string(contador) + "->Nodo1";


	texto = archivoCabeza + nodos + juntarNodos + "{rank=same; " + masNodos + "}}";
	ofs << texto;
	ofs.close();
	system("dot -Tjpg -o ListaCircular.png Circular.dot");
	system("ListaCircular.png");

}