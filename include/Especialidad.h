#ifndef ESPECIALIDAD_H
#define ESPECIALIDAD_H

#include <string>
using namespace std;

class Especialidad
{
public:
    int especialidadID;
    string nombre;
    string descripcion;

    Especialidad(int especialidadID,
                 string nombre,
                 string descripcion);
};

#endif