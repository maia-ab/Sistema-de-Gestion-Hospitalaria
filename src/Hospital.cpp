#include "../include/Hospital.h"
#include <iostream>

using namespace std;

Hospital::Hospital(string codigo,
                   string nombre, string ciudad,
                   int capacidadCamas,
                   int camasOcupadas,
                   vector<string> especialidades,
                   vector<Turno> turnos,
                   int cantidadDeMedicos,
                   vector<Medico> personalMedico,
                   double presupuestoAnual)
{
    this->codigo = codigo;
    this->nombre = nombre;
    this->ciudad = ciudad;
    this->capacidadCamas = capacidadCamas;
    this->camasOcupadas = camasOcupadas;
    this->especialidades = especialidades;
    this->turnos = turnos;
    this->personalMedico = personalMedico;
    this->cantidadDeMedicos = cantidadDeMedicos;
    this->presupuestoAnual = presupuestoAnual;
}

void Hospital::agregarPaciente(Paciente paciente)
{
    if (paciente.ocupaCama)
    {
        camasOcupadas++;
    }
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

bool Hospital::estaSobrecargado(string fechaDesde,
                                string fechaHasta,
                                int maxIngresos)
{
    return (camasOcupadas > capacidadCamas * 0.9) || pacientesIngresadosDesde_Hasta_(fechaDesde, fechaHasta) > maxIngresos;
};

int Hospital::pacientesIngresadosDesde_Hasta_(string fechaDesde, string fechaHasta)
{
    int totalIngresados = 0;

    for (const Paciente &paciente : pacientes)
    {
        if (paciente.getFechaIngreso() >= fechaDesde && paciente.getFechaIngreso() <= fechaHasta)
        {
            totalIngresados++;
        }
    }
}
void Hospital::turnosDePaciente(int pacienteDNI)
{
    for (Paciente &paciente : pacientes)
    {
        if (paciente.getDNI() == pacienteDNI)
        {
            return paciente.obtenerInfoTurnos();
        }
    }
}

void Hospital::turnosDeMedico(int medicoID)
{
    for (Medico &medico : personalMedico)
    {
        if (medico.getID() == medicoID)
        {
            return medico.obtenerInfoTurnos();
        }
    }
}

void Hospital::obtenerInfoHospital()
{
    cout << "Hospital: " << codigo << endl;
    cout << "Nombre:" << nombre << endl;
    cout << "Ciudad:" << ciudad << endl;
    cout << "Capacidad camas: " << capacidadCamas << endl;
    cout << "Cantidad de medicos: " << cantidadDeMedicos << endl;
    cout << "Presupuesto anual: " << presupuestoAnual << endl;
    cout << "Camas libres: " << obtenerDisponibilidad() << endl;
    cout << "Personal Medico: ";
    for (int i = 0; i < (int)personalMedico.size(); i++)
    {
        cout << personalMedico[i].nombre << endl;
    }
    cout << "Especialidades: ";
    for (int i = 0; i < (int)especialidades.size(); i++)
    {
        cout << especialidades[i] << endl;
    }
    cout << "Pacientes actuales: " << pacientes.size() << endl;
    cout << "Turnos registrados: " << turnos.size() << endl;
}
