#include "iostream"
#include "string"
#include "conio.h" 
#include "stdio.h"
#include "string.h"
#include "metodos.h"
#include "Nodo.h"
#include "Archivos.h"
#include "ListaDobleLetras.h"
#include "ListaCircular.h"
#include "PilaCambio.h"
#include <vector>
#include "PilaRevertido.h"

using namespace std;

//VARIABLES GLOBALES
string opc = "";


metodos m;
ListaDobleLetras lista;
PilaCambio pilaCambio;
PilaRevertido pilaRevertido;
Archivos arch;
ListaCircular listacircular;
void CrearArchivo();
void AbrirArchivo(string ruta);
void ArchivosRecientes();
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
			//Limpia la lista para poner nuevos caracteres
			lista.LimpiarLista();
			lista.Insertar('.', 0, 4);
			m.Cls();
			CrearArchivo();
		}
		else if (opcion == 2) {
			//Limpia la lista para poner nuevos caracteres
			lista.LimpiarLista();
			lista.Insertar('.', 0, 4);
			m.Cls();
			puts("Carga de Archivos Simple v1");
			puts("Ingrese la ruta del archivo, segido del nombre con su extension");
			puts("------------------------------------");
			string ruta;
			cout << ">>";
			cin >> ruta;
			AbrirArchivo(ruta);
		}
		else if (opcion == 3) {
			m.Cls();
			ArchivosRecientes();
		}
		else if (opcion == 4) {
			//m.Cls();
			//pilaCambio.mostrar_pila();
			cout<<("\nGracias","Nos vemos"); 
			Salir = true;
		}
		else {
			opc = "";
		}

	} while (Salir == false);
	return 0;
}

void Reportes() {
	int opcion = 0;
	system("cls");
	cout << "\n\t\t\t\t------------------------------\n";
	cout << "\n\t\t\t\t|           Reportes:         |";
	cout << "\n\t\t\t\t------------------------------\n";
	cout << "\n\t\t\t\t| 1. Lista Doble              |";
	cout << "\n\t\t\t\t| 2. Pila Cambio              |";
	cout << "\n\t\t\t\t| 3. Pila Revertido           |";
	cout << "\n\t\t\t\t| 4. Salir                    |\n";

	while (opcion != 4) {
		cout << "\t\t\t\t Ingrese la opcion: ";
		cin >> opcion;
		switch (opcion)
		{
		case 1:
			lista.GenerarGrafica("ListaDobleLetras");
			break;
		case 2:
			pilaCambio.GenerarGrafica("PilaCambio");
			break;
		case 3:
			pilaRevertido.GenerarGrafica("PilaRevertido");
			break;
		default:
			break;
		}
	}
}


void Limpiar() {
	m.Cls(); 
	puts("Editor Simple v1");
	puts("Comience a capturar los datos");
	puts("Presione 'CTRL X' para terminar, CTRL W: Buscar y reemplazar, CTRL C: Reportes, CTRL S: guardar");
	puts("---------------------------------------------------------------------------------------------");

	lista.Mostrar();
}

void CrearArchivo() {

	Limpiar();

	//variable para leer datos
	char strLinea[100];
	string texto = "";
	char key_press;
	int ascii_value;
	int espacio = 4;
	int contadorCaracter = 0;
	bool var = false;


	do {
		key_press = _getch();
		ascii_value = key_press;

		
		if (ascii_value == -32) {
			var = true;
		}
		else if (ascii_value == 75 && var)
		{
			m.gotoxy(m.wherex()-1, m.wherey());
			var = false;
		}
		else if (ascii_value == 72 && var) {

			m.gotoxy(m.wherex(), m.wherey()-1);
			var = false;
		}
		else if (ascii_value == 80 && var) {

			m.gotoxy(m.wherex(), m.wherey() + 1);
			var = false;
		}
		else if (ascii_value == 77 && var) {
			m.gotoxy(m.wherex()+1, m.wherey());
			var = false;
		}

		else if (ascii_value == 8) { //presiono backspace o flecha izquierda
			//contadorCaracter++;
			int x= m.wherex() - 1;
			int y = m.wherey(); 
			lista.Eliminar(x, y);
			m.gotoxy(x,y);//mueve el cursor una posicion atras
			Limpiar();
		}
		else if (ascii_value == 24) //presiono CTRL X sale del bucle
		{
			break;
		}
		else if (ascii_value == 13) //presiono enter
		{
			lista.InsertarUltimo(' ');
			int x = m.wherex();
			int y = m.wherey();
			//cout << " en X" << x << "Y" << y;
			//lista.Insertar(' ', x, y);
			lista.Insertar('\n', x, y);
			//lista.Insertar('', x, y);
			Limpiar();
			espacio++;
		}
		else if (key_press == 23) { //Presiono Control W
			
			
			lista.limpiarContador();
			cout << "\nIngrese el texto a buscar: ";
			string buscar = "";
			cin >> buscar;
			size_t found = buscar.find(";");
			vector<string> palabra;
			palabra.push_back(buscar.substr(0, found)); //palabra a bucar

			palabra.push_back(buscar.substr(found + 1, buscar.size())); // palabra a reemplazar
			lista.LimpiarEx();
			lista.Buscar(buscar);
			if (lista.Existe()) {
				Limpiar();
				cout << "\n------------------------------\n";
				cout << lista.getContador() << " Palabra(s) afectada(s)\n";
				cout << "\n------------------------------\n";
				system("pause");
				Limpiar();
				//GUARDAR PILA
				pilaCambio.push(new Cambio(palabra[0], palabra[1], false, "", 0, 0));
				
				
				pilaCambio.mostrar_pila();

				//pilaCambio.GenerarGrafica("PilaCambio");
			}
			else {
				cout << "No se ha detectado coincidencia";
			}
		}
		else if (key_press == 25) { //Presiono CONTROL Y REHACER
			if (!pilaRevertido.pilaVacia()) {
				Cambio* c = pilaRevertido.pop();
				c->estado = true;
				pilaCambio.push(c);
				string buscar = c->buscar + ";" + c->reemplazar;
				lista.Buscar(buscar);
				if (lista.Existe()) {
					Limpiar();
				}
			}
		}
		else if (key_press == 26) { //Presiono CONTROL Z DESHACER
			if (!pilaCambio.pilaVacia()) {
				lista.InsertarUltimo(' ');

				Cambio* c = pilaCambio.pop();
				c->estado = true;
				pilaRevertido.push(c);
				string buscar = c->reemplazar + ";" + c->buscar;
				lista.Buscar(buscar);
				if (lista.Existe()) {
					Limpiar();
				}
				lista.EliminarFinal();
			}
		}
		else if (key_press == 3) { //Presiono CONTROL C 
			Reportes();
		}
		else if(key_press == 19){ //PRESIONO CONTROL S
			


			string buscar = "";
			cout << "\n------------------------------\n";
			cout << "\n| Ingrese el nombre del archivo:";
			cin >> buscar;
			cout << "\n------------------------------\n";

			if (buscar != "") {
				lista.GuardarArchivo(lista.trim(buscar));
				puts("\t\t\t\t\n Archivo Guardado correctamente \n");
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
			//pilaCambio.push(new Cambio("", "", false, ""+key_press, x, y));
			Limpiar();
		}
		key_press = ' ';

	} while (-1);
}



void AbrirArchivo(string ruta) {
	
	string cont = arch.Leer(ruta);
	
	
	if (cont != "NULL")
	{
		for (size_t i = 0; i < cont.size(); i++)
		{
			lista.Insertar(cont[i]);
		}
		puts(" ");
		puts("\t\t\t\t---------------------------------------");
		puts("\t\t\t\t     Archivo encontrado con exito");
		puts("\t\t\t\t---------------------------------------");
		
		puts("\t\t\t\t>> Los datos seran mostrados en el editor");

		////// GUARDA EL NOMBRE DE ARCHIVO Y RUTA DENTRO DE LA LISTA DOBLE
		string nombre = "";
		for (size_t i = ruta.size() - 1; i > 0; i--)
		{
			if (ruta[i] == '\\')
			{
				nombre = ruta.substr(i + 1, ruta.size());
				break;
			}
		}
		listacircular.insertar(nombre, ruta);
		/////////////////////////////////////////

		system("pause");
		CrearArchivo();

	}
	else {
		puts(" ");
		puts("\t\t\t\t------------------------------------");
		puts("\t\t\t\t       Archivo No encontrado");
		puts("\t\t\t\t------------------------------------");
		system("pause");
	}

	

}


void ArchivosRecientes() {
	lista.LimpiarLista();
	puts("Selector Simple v1");
	puts("Datos de archivos vistos anteriormente");
	puts("Presione 'CTRL X' para terminar, X(Mayus) para generar reporte");
	puts("-------------------------------------------------------------");
	char key_press;
	int ascii_value;


	if (!listacircular.esVacia())
	{
		puts("\t\t\t\t------------------------------------------------------");
		puts("\t\t\t\t       Lista de Archivos abiertos recientemente       ");
		puts("\t\t\t\t------------------------------------------------------");

		listacircular.recorrer();
		puts(" ");
		

		string opc = "";
		puts(" ");
		puts(" ");
		
		
		if (opc == "")
		{
			do
			{
				opc = "";
				cout << "\n" << "\t\t\t\t" << "    Por favor, ingrese el valor: ";
				cin >> opc;
				if (opc == "X") {
					opc = "100";
					break;
				}
			} while (m.EsUnNumero(opc) != true);
		}

		int opcion = atoi(opc.c_str());
		string rutaArchivo = listacircular.buscarArchivo(opcion);
		if (rutaArchivo != "NULL")
		{
			AbrirArchivo(rutaArchivo);
			CrearArchivo();
		}
		else if(opc == "100"){
			listacircular.GenerarGrafica("Circular");
			puts("\t\t\t------------------------------------------");
			puts("\t\t\t       Grafica generada con exito!!       ");
			puts("\t\t\t------------------------------------------");
			system("pause");
		}
		else {
			puts("\t\t\t------------------------------------");
			puts("\t\t\t        ARCHIVO NO ENCONTRADO       ");
			puts("\t\t\t------------------------------------");
			system("pause");
		}
		opc = "";

	



	}
	else {
		puts("No hay registros de archivos");
		system("pause");
	}


}

