#pragma once
#include <windows.h>
#include "string"
using namespace std;

class Cambio
{
public:
    Cambio();
    Cambio(string b, string r, bool e, string p, int x1, int y1);
    int x;
    int y;
    string buscar;
    string reemplazar;
    bool estado;
    string palabra;
    Cambio* sig;
    virtual ~Cambio();
};


