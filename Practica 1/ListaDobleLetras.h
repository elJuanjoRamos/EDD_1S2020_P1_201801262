
#include "iostream"
#include <windows.h>
#include <stdio.h>
#include <string>
#include <vector>
#include "Nodo.h"

using namespace std;

class ListaDobleLetras
{
public:
    Nodo* primero, * ultimo = NULL;
    int contador = 0;
    ListaDobleLetras();
    void Insertar(char l, int x, int y);
    void InsertarFinal(char l, int x, int y);
    void InsertarReemplazo(char l, int x, int y);
    bool NodoInterno(int x, int y);
    void Mostrar();
    void Reordenar();
    void LimpiarLista();
    void Eliminar(/*Nodo* n*/ int x, int y);
    void Reemplazar(string letras, string reemplazo);
    bool Buscar(string linea);
    string trim(string& str);
    int getContador();
    virtual ~ListaDobleLetras();
};