#include "ListaDobleLetras.h"
#include <fstream>

ListaDobleLetras::ListaDobleLetras()
{
	//ctor
}

ListaDobleLetras::~ListaDobleLetras()
{
	//dtor
}




/* METODO INSERTAR DE LA LISTA DOBLE CON UNA MODIFICACION PARA INSERTAR EN MEDIO DE OTROS NODOS*/
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

/*****************************************************/
/* METODO QUE INSERTA ELEMENTOS UNICAMENTE AL FINAL, ESTE METODO SE UTLIZA CUANDO SE HACE CARGA DE ARCHIVOS */
void ListaDobleLetras::Insertar(char dato) {
	Nodo* nuevo;

	nuevo = new Nodo(dato, 0, 0);
	if (primero == NULL) {
		primero = nuevo;
		primero->sig = NULL;
		primero->ant = NULL;
		ultimo = primero;
	}
	else {
		ultimo->sig = nuevo;
		nuevo->sig = NULL;
		nuevo->ant = ultimo;
		ultimo = nuevo;
		
	}
	Reordenar();
}

/*******************************************************/

/* METODO QUE VERIFICA SI EXISTE UN NODO EN LA POSICION XY EN LA QUE SE ESTA INTENTANDO INSERTAR*/
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
/*****************************************************/



/* CREA UNA MINI LISTA QUE CONTIENE LOS NODOS DE LA PALABRA A REEMPLAZAR*/
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
/**************************************************************************/


void ListaDobleLetras::Mostrar() {
	Nodo* actual = new Nodo();
	actual = primero;
	if (primero != NULL)
	{
		while (actual != NULL)
		{
			if (actual->letra == ' ') {
				//cout << " " << " (" << actual->x << "," << actual->y << ") ";
				cout << " ";
			} else if(actual->letra == '\n')
			{
				cout << "\n.";
			}
			else {
				//cout << actual->letra << " (" << actual->x << "," << actual->y << ") ";
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
	if (actual != NULL) {

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

void ListaDobleLetras::InsertarInicio(char entrada)
{
	Nodo* aux = new Nodo(entrada, 0, 0);
	if (primero != NULL)
	{
		primero = aux;
		ultimo = aux;
	}
	else {
		aux->sig = primero;
		primero->ant = aux;
		primero = aux;
	}
}

void ListaDobleLetras::InsertarUltimo(char entrada) {
	Nodo* nuevo = new Nodo(entrada, 0, 0);
	if (primero == NULL) {
		primero = nuevo;
		primero = ultimo;
	}
	else {
		ultimo->sig = nuevo;
		nuevo->ant = ultimo;
		ultimo = nuevo;
	}
	
}

bool ListaDobleLetras::Existe() {
	return ex;
}
void ListaDobleLetras::LimpiarEx() {
	ex = false;
}


void ListaDobleLetras::Buscar(string linea) {
	//INSERTAR AL INICIO
	//InsertarInicio(' ');
	//INSERTAR AL FINAL
	
	vector<string> coincidencias;

	string str = linea;
	string str1 = ";";
	int cantidad = 0;

	size_t found = str.find(str1); //Hace split al texto de busqueda
	
	if (found != string::npos) {

		coincidencias.push_back(linea.substr(0, found) + " "); //palabra a bucar

		coincidencias.push_back(linea.substr(found + 1, linea.size()) + " "); // palabra a reemplazar

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
			ex = true;
			//EliminarPrimero();
			//EliminarFinal();
			Buscar(trim(linea));
			
		}
		else {
			//EliminarPrimero();
			//EliminarFinal();
		}
	}
}

void ListaDobleLetras::EliminarPrimero() {
	if (primero != NULL) {
		if (primero == ultimo) {
			primero = NULL;
			ultimo = NULL;
		}
		else {
			primero = primero->sig;
			primero->ant = NULL;
		}

	}
}


void ListaDobleLetras::EliminarFinal()
{
	if (primero == NULL) {
		std::cout << "La lista esta vacía.";
	}
	else if (primero == ultimo) {
		ultimo = NULL;
		primero = NULL;
	}
	else {
		ultimo = ultimo->ant;
		ultimo->sig = NULL;
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
	Nodo* auxprimero;
	Nodo* auxultimo;
	Nodo* nuevo;
	string concatenar;
	
		do
		{
			if (aux->letra == letras[0] && (aux->ant == NULL || aux->ant->letra == ' ' || aux->ant->letra == '.' || aux->ant->letra == ',' || aux->ant->letra == '\n'))
			{
				while (aux->letra != ' ')
				{
					concatenar += aux->letra;
					if (aux->sig == NULL || aux->sig->letra == ' ')
					{
						break;
					}
					aux = aux->sig;
				}

				if (letras == concatenar)
				{
					auxultimo = aux;
					while (aux->letra != letras[0])
					{
						aux = aux->ant;
					}

					auxprimero = aux;
					if (auxprimero != primero)
					{
						auxprimero = aux->ant;
					}

					for (int i = 0; i < reemplazo.size(); i++)
					{
						nuevo = new Nodo(reemplazo[i], 0,0);

						auxprimero->sig= nuevo;
						nuevo->ant = auxprimero;

						if (i == reemplazo.size() - 1)
						{
							if (auxultimo != ultimo)
							{
								nuevo->sig = auxultimo->sig;
								auxultimo->sig->ant = nuevo;
							}
							else
							{
								ultimo = nuevo;
							}
						}

						auxprimero = auxprimero->sig;

						if (auxprimero->ant != NULL && auxprimero->ant == primero && auxprimero->ant->letra == letras[0])
						{
							auxprimero->ant->sig = NULL;
							auxprimero->ant = NULL;
							primero = auxprimero;
						}
					}
					aux = auxprimero;
				}
			}

			aux = aux->sig;
		} while (aux != NULL);
	


	
	/*Nodo* aux = primero;
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
	ultimoReemplazo = NULL;*/
	

	Reordenar();
}

int ListaDobleLetras::getContador() {
	return contador;
}
void ListaDobleLetras::limpiarContador() {
	contador = 0;
}

/* LIMPIA LA LISTA */
void ListaDobleLetras::LimpiarLista() {
	primeroReemplazo = NULL;
	primero = NULL;
}
/**********************/


Cambio* ListaDobleLetras::getCambio() {
	return cambio;
}

void ListaDobleLetras::limpiarCambio() {

}

void ListaDobleLetras::GuardarArchivo(string nombre) {
	Nodo* aux = primero->sig;
	string texto = "";

	if (aux != NULL)
	{
		ofstream fout;
		fout.open(nombre + ".txt");
		while (aux != NULL)
		{
			fout << aux->letra;
			aux = aux->sig;
		}

		fout.close();
	}
}

void ListaDobleLetras::GenerarGrafica(string nombre) {
	string archivoCabeza = "digraph G {"
		"node[shape = box];\n";

	string nodos;
	string juntarNodos;

	ofstream ofs(nombre + ".dot", ofstream::out);

	Nodo* aux = primero->sig;
	string texto = "";
	int contador = 0;

	while (aux != NULL)
	{
		if (aux->letra == ' ') {
			nodos = nodos + "Nodo" + to_string(contador) + " [label = " + '"' + " " + '"' + "];\n";
		}
		else if (aux->letra == '\n')
		{
			nodos = nodos + "Nodo" + to_string(contador) + " [label = " + '"' + " " + '"' + "];\n";
		}
		else {
			nodos = nodos + "Nodo" + to_string(contador) + " [label = " + '"' + aux->letra + '"' + "];\n";
		}
		aux = aux->sig;
		contador++;
	}

	for (size_t i = 0; i < contador-1; i++)
	{
		juntarNodos = juntarNodos + "Nodo" + to_string(i) + "->Nodo" + to_string(i + 1) + ";\nNodo" + to_string(i + 1) + "->Nodo" + to_string(i) + ";\n";
	}

	//std::cout << texto;
	texto = archivoCabeza + nodos + juntarNodos + "}";
	//std::cout << texto;
	ofs << texto;

	ofs.close();
	system("dot -Tjpg -o ListaDobleLetras.png ListaDobleLetras.dot");
	system("ListaDobleLetras.png");
	
}