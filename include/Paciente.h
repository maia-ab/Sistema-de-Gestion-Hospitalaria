#ifndef PACIENTE_H
#define PACIENTE_H

#include <string>
#include <vector>
#include "Turno.h"
using namespace std;

class Paciente
{
public:
    int pacienteID;
    int dni;
    string fechaIngreso; // idem fecha turno
    string diagnostico;
    int prioridad;
    float peso;
    bool ocupaCama;
    string codigoHospital;
    vector<Turno> turnos;

    Paciente(int pacienteID,
             int dni, string fechaIngreso,
             string diagnostico,
             int prioridad,
             float peso,
             string codigoHospital);

    void agregarTurno(Turno turno);
    void obtenerInfoTurnos();
    vector<Turno> getTurnos() const;
    void obtenerInfoPaciente();
    string getFechaIngreso() const;
    int getID() const;
    int getDNI() const;
};

#endif