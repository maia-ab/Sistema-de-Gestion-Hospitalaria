#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <string>
#include <vector>
#include "Turno.h"
#include "Paciente.h"
#include "Medico.h"
using namespace std;

class Hospital
{
public:
    string codigo;
    string nombre;
    string ciudad;
    int capacidadCamas;
    vector<string> especialidades;
    int personalMedico;
    double presupuestoAnual;
    vector<Paciente> pacientes;
    vector<Turno> turnos;

    Hospital(string codigo,
             string nombre,
             string ciudad,
             int capacidadCamas,
             vector<string> especialidades,
             vector<Turno> turnos,
             int personalMedico,
             double presupuestoAnual);

    void agregarPaciente(Paciente paciente);
    void agregarTurno(Turno turno);
    void eliminarPaciente(int pacienteID);
    int obtenerDisponibilidad();
    bool tieneEspecialidad(string especialidad);
    void obtenerInfoHospital();
    int pacientesAtendidosDesde_Hasta_(string fechaDesde,string fechaHasta);
    bool estaSobrecargado();

};

#endif