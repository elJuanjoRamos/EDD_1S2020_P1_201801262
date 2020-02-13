#include "ListaDobleLetras.h"


ListaDobleLetras::ListaDobleLetras()
{
	//ctor
}

ListaDobleLetras::~ListaDobleLetras()
{
	//dtor
}





void ListaDobleLetras::Insertar(char dato, int x1, int y1) {
	Nodo* nuevo;

	nuevo = new Nodo(dato, x1, y1);
	if (primero == NULL) {
		primero = nuevo;
		primero->sig = NULL;
		primero->ant = NULL;
		ultimo = primero;
	}
	else {

		if (NodoInterno(x1, y1)) {
			Nodo* temp = new Nodo();
			temp = primero;
			while (temp != NULL) {
				if (temp->x == x1 && temp->y == y1) {
					temp->ant->sig = nuevo;
					nuevo->ant = temp->ant;
					temp->ant = nuevo;
					nuevo->sig = temp;
					break;
				}
				temp = temp->sig;
			}
		}
		else {
			ultimo->sig = nuevo;
			nuevo->sig = NULL;
			nuevo->ant = ultimo;
			ultimo = nuevo;
		}
		Reordenar();
	}
}

void ListaDobleLetras::InsertarFinal(char dato, int x1, int y1) {
	Nodo* nuevo =  new Nodo(dato, x1, y1);
	
	ultimo->sig = nuevo;
	nuevo->sig = NULL;
	nuevo->ant = ultimo;
	ultimo = nuevo;
	Reordenar();
	
}


bool ListaDobleLetras::NodoInterno(int x1, int y1) {

	Nodo* temp = new Nodo();
	int contador = 0;
	temp = primero;
	while (temp != NULL) {
		if (temp->x == x1 && temp->y == y1) {
			contador++;
			break;
		}
		temp = temp->sig;
	}
	if (contador != 0)
	{
		return true;
	}
	return false;
}

Nodo* primeroReemplazo = NULL;
Nodo* ultimoReemplazo = NULL;

void ListaDobleLetras::InsertarReemplazo(char dato, int x, int y) {

	Nodo* nuevo;
	nuevo = new Nodo(dato, x, y);
	if (primeroReemplazo == NULL) {
		primeroReemplazo = nuevo;
		primeroReemplazo->sig = NULL;
		primeroReemplazo->ant = NULL;
		ultimoReemplazo = primeroReemplazo;
	}
	else {
		ultimoReemplazo->sig = nuevo;
		nuevo->sig = NULL;
		nuevo->ant = ultimoReemplazo;
		ultimoReemplazo = nuevo;
	}
}



void ListaDobleLetras::Mostrar() {
	Nodo* actual = new Nodo();
	actual = primero;
	if (primero != NULL)
	{
		while (actual != NULL)
		{
			if (actual->letra == ' ') {
				cout << " ";
			} else if(actual->letra == '\n')
			{
				cout << "\n.";
			}
			else {
				cout << actual->letra;
			}//cout << actual->letra;
			actual = actual->sig;
		}
	}
	else {
		cout << "vacia";
	}
	//system("pause");
}

void ListaDobleLetras::Eliminar(int pox, int poy) {
	Nodo* actual = new Nodo();
	actual = primero;
	Nodo* anterior = new Nodo();
	anterior = NULL;
	bool encontrado = false;
	if (primero != NULL) {

		while (actual != NULL && encontrado != true) {

			if (actual->x == pox && actual->y == poy) {

				if (actual == primero) {
					primero = primero->sig;
					primero->ant = NULL;
				}
				else if (actual == ultimo) {
					anterior->sig = NULL;
					ultimo = anterior;
				}
				else {
					anterior->sig = actual->sig;
					actual->sig->ant = anterior;
				}
				encontrado = true;
			}
			anterior = actual;
			actual = actual->sig;
		}

	}
	else {
		cout << "\n La listas se encuentra Vacia\n\n";
	}
	Reordenar();
}

/*REORDENA LAS POSICIONES XY DE LOS CARACTERES AL INSERTAR UN NUEVO ELEMENTO EN MEDIO O REEMPLAZAR*/
void ListaDobleLetras::Reordenar() {
	int x = 0;
	int y = 4;
	Nodo* actual = new Nodo();
	actual = primero;
	bool encontrado = false;
	int nodoBuscado = 0;
	if (primero != NULL) {

		while (actual != NULL) {

			if (actual->letra == '\n') {
				y++;
				x = 0;
			}
			actual->x = x;
			actual->y = y;
			x++;
			actual = actual->sig;
		}
	}
	else {
		cout << "\n La listas se encuentra Vacia\n\n";
	}

}


bool ListaDobleLetras::Buscar(string linea) {
	vector<string> coincidencias;

	string str = linea;
	string str1 = ";";
	int cantidad = 0;

	size_t found = str.find(str1); //Hace split al texto de busqueda
	if (found != string::npos) {

		coincidencias.push_back(linea.substr(0, found)); //palabra a bucar

		coincidencias.push_back(linea.substr(found + 1, linea.size())); // palabra a reemplazar

		Nodo* aux = primero;
		for (size_t i = 0; i < coincidencias[0].size(); i++)
		{
			while (aux != NULL)
			{
				if (aux->letra == coincidencias[0][i])
				{
					cantidad++;
					aux = aux->sig;
					break;
				}
				else
				{
					aux = aux->sig;
				}
			}
		}
		if (cantidad == coincidencias[0].size())
		{
			Reemplazar(trim(coincidencias[0]), trim(coincidencias[1]));
			contador++;
			Buscar(trim(linea));
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}


}

inline string ListaDobleLetras::trim(string& str)
{
	str.erase(0, str.find_first_not_of(' '));       //prefixing spaces
	str.erase(str.find_last_not_of(' ') + 1);         //surfixing spaces
	return str;
}



void ListaDobleLetras::Reemplazar(string letras, string reemplazo) {
	Nodo* aux = primero;
	Nodo* rex;


	for (size_t i = 0; i < reemplazo.size(); i++) {
		InsertarReemplazo(reemplazo[i], 0, 0);
	}

	for (size_t i = 0; i < letras.size(); i++)
	{
		while (aux != NULL)
		{
			if (aux->letra == letras[i])
			{
				rex = aux->sig;
				if (i == 0) {
					aux->ant->sig = primeroReemplazo;
					primeroReemplazo->ant = aux->ant;
				}
				else if (i + 1 == letras.size()) {
					aux->sig->ant = ultimoReemplazo;
					ultimoReemplazo->sig = aux->sig;
				}
				break;
			}
			else
			{
				aux = aux->sig;
			}

		}
	}
	primeroReemplazo = NULL;
	ultimoReemplazo = NULL;
	Reordenar();
}

int ListaDobleLetras::getContador() {
	return contador;
}
void ListaDobleLetras::LimpiarLista() {
	primeroReemplazo = NULL;
	primero = NULL;
}