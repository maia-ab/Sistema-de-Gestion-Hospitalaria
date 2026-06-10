#include "../include/Medico.h"
#include <iostream>

using namespace std;

Medico::Medico(int medicoID, string nombre, string especialidad)
{
    this->medicoID = medicoID;
    this->nombre = nombre;
    this->especialidad = especialidad;
}

void Medico::agregarTurno(Turno turno)
{
    turnos.push_back(turno);
}

void Medico::obtenerInfoTurnos()
{
    if (turnos.size() == 0)
    {
        cout << "El medico " << medicoID << " no tiene turnos." << endl;
        return;
    }
    cout << "Turnos del medico " << medicoID << ":" << endl;
    for (int i = 0; i < turnos.size(); i++)
    {
        turnos[i].obtenerInfoTurno();
    }
}

int Medico::getID() const
{
    return medicoID;
}

vector<Turno> Medico::getTurnos() const
{
    return turnos;
}

void Medico::obtenerInfoMedico()
{
    cout << "Medico ID: " << medicoID << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Especialidad: " << especialidad << endl;
    cout << "Turnos: " << turnos.size() << endl;
}
