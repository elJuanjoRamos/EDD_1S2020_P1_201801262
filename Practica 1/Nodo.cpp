#include "Nodo.h"
#include <windows.h>
#include <stdio.h>
Nodo::Nodo()
{
}

Nodo::~Nodo()
{
}

Nodo::Nodo(char l, int x1, int y1) {
    letra = l;
    x = x1;
    y = y1;
    sig = ant = NULL;
}
