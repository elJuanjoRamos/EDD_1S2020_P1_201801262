#pragma once
#include <windows.h>
#include <stdio.h>
#include <conio.h>


class Nodo
{
public:
    Nodo();
    Nodo(char l, int x1, int y1);
    int x;
    int y;
    char letra;
    Nodo* sig;
    Nodo* ant;
    virtual ~Nodo();
};





