#ifndef TURNO_H
#define TURNO_H

#include <string>
using namespace std;

class Turno
{
public:
    int turnoID;
    int pacienteID;
    int medicoID;
    string fechaTurno; // formato tal cual el pdf o sea año, mes, dia. todo junto
    string especialidad;
    int duracionMin;

    Turno(int turnoID,
          int pacienteID,
          int medicoID,
          string fechaTurno,
          string especialidad,
          int duracionMin);

    void obtenerInfoTurno();
};

#endif