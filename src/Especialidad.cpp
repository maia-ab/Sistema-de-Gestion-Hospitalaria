#include "../include/Especialidad.h"
#include <iostream>

using namespace std;

Especialidad::Especialidad(int especialidadID,
                           std::string nombre,
                           std::string descripcion)
{
    this->especialidadID = especialidadID;
    this->nombre = nombre;
    this->descripcion = descripcion;
}
