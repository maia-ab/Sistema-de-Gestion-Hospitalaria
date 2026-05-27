#include "../include/Paciente.h"
#include <iostream>

using namespace std;

Paciente::Paciente(int pacienteID, int dni, string fechaIngreso, string diagnostico, int prioridad, float peso, string codigoHospital)
{
    this->pacienteID = pacienteID;
    this->dni = dni;
    this->fechaIngreso = fechaIngreso;
    this->diagnostico = diagnostico;
    this->prioridad = prioridad;
    this->peso = peso;
    this->codigoHospital = codigoHospital;
}

void Paciente::agregarTurno(Turno turno)
{
    turnos.push_back(turno);
}

void Paciente::obtenerTurnos()
{
    if (turnos.size() == 0)
    {
        cout << "El paciente " << pacienteID << " no tiene turnos." << endl;
        return;
    }
    cout << "Turnos del paciente " << pacienteID << ":" << endl;
    for (int i = 0; i < turnos.size(); i++)
    {
        turnos[i].obtenerInfoTurno();
    }
}

void Paciente::obtenerInfoPaciente()
{
    cout << "PacienteID: " << pacienteID << endl;
    cout << "DNI: " << dni << endl;
    cout << "Fecha que ingresó: " << fechaIngreso << endl;
    cout << "Diagnostico: " << diagnostico << endl;
    cout << "Prioridad: " << prioridad << endl;
    cout << "Peso: " << peso << endl;
    cout << "Hospital: " << codigoHospital << endl;
    cout << "Turnos: " << turnos.size() << endl;
}
