#include "Archivos.h"

Archivos::Archivos() {

}

string Archivos::Leer(string ruta) {
	ifstream archivo;
	string contenido;
	archivo.open(ruta, ios::in); // se abre el archivo en modo lectura
	if (archivo.fail())
	{
		return "NULL";
	}
	else {
		while (!archivo.eof()) // mientras no sea el final
		{
			getline(archivo, contenido);
			//cout << contenido << endl;
		}
		archivo.close();
		return contenido;
	}
}