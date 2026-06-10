#include "../include/Hospital.h"
#include <iostream>

using namespace std;

Hospital::Hospital(string codigo,
                   string nombre, string ciudad,
                   int capacidadCamas,
                   vector<string> especialidades,
                   vector<Turno> turnos,
                   int personalMedico,
                   double presupuestoAnual)
{
    this->codigo = codigo;
    this->nombre = nombre;
    this->ciudad = ciudad;
    this->capacidadCamas = capacidadCamas;
    this->especialidades = especialidades;
    this->turnos = turnos;
    this->personalMedico = personalMedico;
    this->presupuestoAnual = presupuestoAnual;
}

void Hospital::agregarPaciente(Paciente paciente)
{
    pacientes.push_back(paciente);
}

void Hospital::agregarTurno(Turno turno)
{
    turnos.push_back(turno);
}

void Hospital::eliminarPaciente(int pacienteID)
{
    for (int i = 0; i < (int)pacientes.size(); i++)
    {
        if (pacientes[i].pacienteID == pacienteID)
        {
            for (int j = i; j < (int)pacientes.size() - 1; j++)
            {
                pacientes[j] = pacientes[j + 1];
            }
            pacientes.pop_back();
            cout << "Borraste el paciente" << pacienteID << " del hospital " << codigo << "." << endl;
            return;
        }
    }
    cout << "Paciente " << pacienteID << " no encontrado." << endl;
}

int Hospital::obtenerDisponibilidad()
{
    return capacidadCamas - (int)pacientes.size();
}

bool Hospital::tieneEspecialidad(string especialidad)
{
    for (int i = 0; i < (int)especialidades.size(); i++)
    {
        if (especialidades[i] == especialidad)
            return true;
    }
    return false;
}

int Hospital::pacientesAtendidosDesde_Hasta_(string fechaDesde, string fechaHasta)
{
    int totalAtendidos = 0;

    for (const Turno &turno : turnos)
    {
        if (turno.getFecha() >= fechaDesde && turno.getFecha() <= fechaHasta)
        {
            totalAtendidos++;
        }
    }
}

bool Hospital::estaSobrecargado(){

};

void Hospital::obtenerInfoHospital()
{
    cout << "Hospital: " << codigo << endl;
    cout << "Nombre:" << nombre << endl;
    cout << "Ciudad:" << ciudad << endl;
    cout << "Capacidad camas: " << capacidadCamas << endl;
    cout << "Personal medico: " << personalMedico << endl;
    cout << "Presupuesto anual: " << presupuestoAnual << endl;
    cout << "Camas libres: " << obtenerDisponibilidad() << endl;
    cout << "Especialidades: ";
    for (int i = 0; i < (int)especialidades.size(); i++)
    {
        cout << especialidades[i] << endl;
    }
    cout << "Pacientes actuales: " << pacientes.size() << endl;
    cout << "Turnos registrados: " << turnos.size() << endl;
}
