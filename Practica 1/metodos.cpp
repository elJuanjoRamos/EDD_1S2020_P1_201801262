#include "metodos.h"

metodos::metodos()
{
	//ctor
}

metodos::~metodos()
{
	//dtor
}

void metodos::menu() {

	//SetColorB(2,19);
	//Rectangle(20,8,40,12,"#");
	//SetColorA(2,22);
	metodos::Imprimir(20, 2, "UNIVERSIDAD DE SAN CARLOS DE GUATEMALA", 10);
	metodos::Imprimir(20, 3, "FACULTAD DE INGENIERIA", 10);
	metodos::Imprimir(20, 4, "ESTRUCTURA DE DATOS", 10);
	metodos::Imprimir(20, 5, "PRACTICA 1", 10);
	metodos::Imprimir(20, 6, "JUAN JOSE RAMOS CAMPOS", 10);
	metodos::Imprimir(20, 7, "201801262", 10);
	metodos::Imprimir(28, 10, "*** MENU PRINCIPAL ***", 15);
	metodos::Imprimir(28, 11, " ", 15);
	metodos::Imprimir(28, 12, " ", 15);
	metodos::Imprimir(28, 13, "1. Crear Archivo", 15);
	metodos::Imprimir(28, 14, "2. Abrir Archivo", 15);
	metodos::Imprimir(28, 15, "3. Archivos Recientes", 15);
	metodos::Imprimir(28, 16, "4. Salir", 15);
	metodos::Imprimir(28, 17, " ", 15);
}


//SETEAR COLOR AL TEXTO
void metodos::SetColorTexto(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void metodos::ImprimirXY(int x, int y, int color) {
	HANDLE var;
	var = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(var, coord);
	metodos::SetColorTexto(color);
}

void metodos::Imprimir(const char* txt)
{
	printf("%s", txt);
}

void metodos::Imprimir(int x, int y, const char* txt, int color)
{
	metodos::ImprimirXY(x, y, color);
	printf("%s", txt);
}


void metodos::Cls() {
	system("cls");
}


int metodos::wherex()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	return csbi.dwCursorPosition.X;
}
int metodos::wherey()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	return csbi.dwCursorPosition.Y;
}

void metodos::gotoxy(int x, int y) {
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { x,y };
	SetConsoleCursorPosition(hStdout, pos);
}

bool metodos::EsUnNumero(string cadena)
{
	for (size_t i = 0; i < cadena.size(); i++)
	{
		// En cuanto un caracter no sea numérico
		if (!isdigit(cadena[i]))
			return false;
	}

	return true;
}

