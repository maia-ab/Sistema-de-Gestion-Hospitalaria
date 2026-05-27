#include "../include/Turno.h"
#include <iostream>

using namespace std;

Turno::Turno(int turnoID,
             int pacienteID,
             int medicoID,
             std::string fechaTurno,
             std::string especialidad,
             int duracionMin)
{
    this->turnoID = turnoID;
    this->pacienteID = pacienteID;
    this->medicoID = medicoID;
    this->fechaTurno = fechaTurno;
    this->especialidad = especialidad;
    this->duracionMin = duracionMin;
}

void Turno::obtenerInfoTurno()
{
    cout << "TurnoID: " << turnoID << endl;
    cout << "PacienteID: " << pacienteID << endl;
    cout << "MedicoID: " << medicoID << endl;
    cout << "Fecha: " << fechaTurno << endl;
    cout << "Especialidad: " << especialidad << endl;
    cout << "Duracion: " << duracionMin << " minutos." << endl;
}