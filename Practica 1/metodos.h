#include <windows.h>
#include <stdio.h>
#include "string"
#include "string.h"
using namespace std;
class metodos
{
public:
    metodos();
    void menu();
    void ImprimirXY(int x, int y);
    void Imprimir(const char* txt);
    void Imprimir(int x, int y, const char* txt, int color);
    void Cls();
    int wherex();
    int wherey();
    void gotoxy(int x, int y);
    void SetColorTexto(int color);
    void ImprimirXY(int x, int y, int color);
    bool EsUnNumero(string cadena);
    virtual ~metodos();

protected:

private:
};
