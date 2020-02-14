#include "iostream"
#include "string"
#include "conio.h" 
#include "stdio.h"
#include "string.h"
#include "metodos.h"
#include "Nodo.h"
#include "ListaDobleLetras.h"
#include "PilaCambio.h"
#include <vector>

using namespace std;

//VARIABLES GLOBALES
string opc = "";


metodos m;
ListaDobleLetras lista;
PilaCambio pilaCambio;


void CrearArchivo();

int main()
{
	
	bool Salir = false;
	do {
		if (opc == "")
		{
			m.Cls();
			//aqui iba el menu
			m.menu();
			do
			{
				opc = "";
				cout <<"\n" <<"\t\t\t"<<"    Por favor, ingrese el valor: ";
				cin >> opc;

			} while (m.EsUnNumero(opc) != true);
		}
		

		int opcion = atoi(opc.c_str());
		opc = "";


		if (opcion == 1)
		{
			m.Cls();
			CrearArchivo();
		}
		else if (opcion == 2) {
			m.Cls();
			lista.Mostrar();
		}
		else if (opcion == 3) {
			//Cls();
			//Eliminar();
		}
		else if (opcion == 4) {
			cout<<("\nGracias por su Tiempo....","Hasta la Vista...."); 
			Salir = true;
		}
		else {
			opc = "";
		}

	} while (Salir == false);
	return 0;
}




void Limpiar() {
	m.Cls(); 
	puts("Editor Simple v1");
	puts("Comience a capturar los datos");
	puts("Presione 'ESC' para terminar");
	puts("------------------------------------");

	lista.Mostrar();
}

void CrearArchivo() {
	//Limpia la lista para poner nuevos caracteres
	lista.LimpiarLista();
	lista.Insertar('.', 0, 4);
	Limpiar();

	//variable para leer datos
	char strLinea[100];
	string texto = "";
	char key_press;
	int ascii_value;
	int espacio = 4;
	int contadorCaracter = 0;



	do {
		key_press = _getch();
		ascii_value = key_press;

		//cout << "el ascii"<< ascii_value << "el key"<< key_press;
		
		if (ascii_value == -32) {
		}
		else if (ascii_value == 75 && key_press == 'K')
		{
			m.gotoxy(m.wherex()-1, m.wherey());
		}
		else if (ascii_value == 72 && key_press == 'H') {

			m.gotoxy(m.wherex(), m.wherey()-1);
		}
		else if (ascii_value == 80 && key_press == 'P') {

			m.gotoxy(m.wherex(), m.wherey() + 1);
		}
		else if (ascii_value == 77 && key_press == 'M') {

			m.gotoxy(m.wherex()+1, m.wherey());
		}

		else if (ascii_value == 8) { //presiono backspace o flecha izquierda
			//contadorCaracter++;
			int x= m.wherex() - 1;
			int y = m.wherey(); 
			lista.Eliminar(x, y);
			m.gotoxy(x,y);//mueve el cursor una posicion atras
			Limpiar();
		}
		else if (ascii_value == 27) //presiono ESC sale del bucle
		{
			break;
		}
		else if (ascii_value == 13) //presiono enter
		{
			int x = m.wherex();
			int y = m.wherey();
			//cout << " en X" << x << "Y" << y;
			//lista.Insertar(' ', x, y);
			lista.Insertar('\n', x, y);
			Limpiar();
			espacio++;
		}
		else if (key_press == 23) { //Presiono Control W
			int x = m.wherex();
			int y = m.wherey();
			lista.Insertar('\n', x, y);
			cout << "\nIngrese el texto a buscar: ";
			string buscar = "";
			cin >> buscar;
			if (lista.Buscar(buscar)) {
				Limpiar();
				cout << "\n------------------------------\n";
				cout << lista.getContador() << " Palabra(s) afectada(s)\n";
				cout << "\n------------------------------\n";
				system("pause");
				Limpiar();
			}
			else {
				cout << "No se ha detectado coincidencia";
			}
		}
		else if(key_press == 19){ //PRESIONO CONTROL S
			
			string buscar = "";
			cout << "\n------------------------------\n";
			cout << "\n| Infrese el nombre del archivo:";
			cin >> buscar;
			cout << "\n------------------------------\n";

			if (buscar != "") {
				lista.GuardarArchivo(buscar);
				cout << "\n Archivo Guardado correctamente \n";
				system("pause");
			}
			else {
				cout << "\n Debe introducir un nombre valido";
				system("pause");
			}
			Limpiar();

		}
		else {
			int x = m.wherex();
			int y = m.wherey();
			lista.Insertar(key_press, x, y);
			Limpiar();
		}
		key_press = ' ';

	} while (-1);
}






/*void Insertar(char dato, int as, int x, int y) {
	if (as != -32)
	{
		lista.Insertar(dato, x, y);
	}
}
void Insertar(char dato, int x, int y) {
	Nodo* nuevo;
	nuevo = new Nodo(dato);
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
}*/

/*void Mostrar() {
	Nodo* actual = new Nodo();
	actual = primero;
	if (primero != NULL)
	{
		
		while (actual != NULL)
		{
			cout << actual->letra;
			actual = actual->sig;
		}
	}
	else {
		cout << "vacia";
	}
	//system("pause");
}
*/
/*void Eliminar(int xa, int ya) {
	Nodo* actual = new Nodo();
	actual = primero;
	Nodo* anterior = new Nodo();
	anterior = NULL;
	bool encontrado = false;
	if (primero != NULL) {

		while (actual != NULL && encontrado != true) {

			if (actual->x == xa && actual->y == ya) {

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
}
*/





/*void Reemplazar(string letras, string reemplazo) {

	Nodo* aux = primero;
	Nodo* rex; 

	Nodo* n = new Nodo();
	n->ant = n->sig = NULL;

	for (size_t i = 0; i < reemplazo.size(); i++)
	{

	}

	for (size_t i = 0; i < letras.size(); i++)
	{
		while (aux != NULL)
		{
			if (aux->letra == letras[i])
			{
				rex = aux->sig;
				Nodo* temp = new Nodo(reemplazo[i], aux->x, aux->y);
				
				
				aux->ant->sig = temp;
				temp->ant = aux->ant;
				aux->ant = NULL;


				aux->sig->ant = temp;
				temp->sig = aux->sig;
				aux->sig = NULL;

				aux = rex;
				
				break;
			}
			else
			{
				aux = aux->sig;
			}
		}
	}
	if (reemplazo.size() > letras.size()) {

	}

}
*/


/*
Nodo* primeroReemplazo = NULL;
Nodo* ultimoReemplazo = NULL;

void InsertarReemplazo(char dato) {

	Nodo* nuevo;
	nuevo = new Nodo(dato);
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
}*/




void Reemplazar(string letras, string reemplazo) {
	/*primeroReemplazo = NULL;
	ultimoReemplazo = NULL;
	Nodo* aux = primero;
	Nodo* rex;


	for (size_t i = 0; i < reemplazo.size(); i++) {
		InsertarReemplazo(reemplazo[i]);
	}
	*/



	for (size_t i = 0; i < letras.size(); i++)
	{
		//while (aux != NULL)
	//	{
		//	if (aux->letra == letras[i])
			//{
				/*rex = aux->sig;
				if (i == 0) {
					aux->ant->sig = primeroReemplazo;
					primeroReemplazo->ant = aux->ant;
				}
				else if (i + 1 == letras.size()) {
					aux->sig->ant = ultimoReemplazo;
					ultimoReemplazo->sig = aux->sig;
				}
				*/
				/*Nodo* temp = new Nodo(reemplazo[i]);
				aux->ant->sig = temp;
				temp->ant = aux->ant;
				aux->ant = NULL;

				aux->sig->ant = temp;
				temp->sig = aux->sig;
				aux->sig = NULL;

				aux = rex;*/

			//	break;
			//}
			//else
			//{
			//	aux = aux->sig;
			//}

		//}
	}
}

bool Buscar(string linea) {

	/*vector<string> coincidencias;
	
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
	*/
	return false;
	
}