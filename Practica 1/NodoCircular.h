#pragma once
#include <iostream>
#include <string>
using namespace std;
class NodoCircular
{
public:
	int index;
	string nombre;
	string ruta;
	NodoCircular* enlace;
	NodoCircular(int i, string n, string r);
};

