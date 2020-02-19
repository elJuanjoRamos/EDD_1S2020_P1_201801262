
#include "iostream"
#include <windows.h>
#include <stdio.h>
#include <string>
#include <vector>
#include "Nodo.h"
#include "Cambio.h"

using namespace std;

class ListaDobleLetras
{
public:
    Nodo* primero, * ultimo = NULL;
    Cambio* cambio = NULL;
    int contador = 0;
    bool ex = false;
    ListaDobleLetras();
    void Insertar(char l, int x, int y);
    void Insertar(char l);
    void InsertarReemplazo(char l, int x, int y);
    bool NodoInterno(int x, int y);
    void Mostrar();
    void Reordenar();
    void InsertarInicio(char entrada);
    void InsertarUltimo(char entrada);
    void LimpiarLista();
    void Eliminar(/*Nodo* n*/ int x, int y);
    void Reemplazar(string letras, string reemplazo);
    void Buscar(string linea);
    void EliminarPrimero();
    void EliminarFinal();
    bool Existe();
    void LimpiarEx();
    string trim(string& str);
    int getContador();
    Cambio* getCambio();
    void GuardarArchivo(string texto);
	void GenerarGrafica(string nombre);
    void limpiarCambio();
    void limpiarContador();
    virtual ~ListaDobleLetras();
};