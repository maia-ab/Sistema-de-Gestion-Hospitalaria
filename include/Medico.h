#ifndef MEDICO_H
#define MEDICO_H

#include <string>
#include <vector>
#include "Turno.h"
using namespace std;

class Medico
{
public:
    int medicoID;
    string nombre;
    string especialidad;
    vector<Turno> turnos;

    Medico(int medicoID,
           string nombre,
           string especialidad);

    void agregarTurno(Turno turno);
    void obtenerTurnos();
    void obtenerInfoMedico();
};

#endif