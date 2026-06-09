#ifndef DIAGNOSTICO_H
#define DIAGNOSTICO_H

#include <string>
using namespace std;

class Diagnostico
{
public:
    int diagnosticoID;
    string nombre;
    string descripcion;

    Diagnostico(int diagnosticoID,
                 string nombre,
                 string descripcion);

   
};

#endif