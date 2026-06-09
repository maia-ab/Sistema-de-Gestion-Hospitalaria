#include "../include/Diagnostico.h"
#include <iostream>

using namespace std;

Diagnostico::Diagnostico(int diagnosticoID,
                           std::string nombre,
                           std::string descripcion)
{
    this->diagnosticoID = diagnosticoID;
    this->nombre = nombre;
    this->descripcion = descripcion;
}
