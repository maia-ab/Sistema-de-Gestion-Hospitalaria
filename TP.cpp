//  TP Sistema de Gestión Hospitalaria

#include <iostream>
#include <string>
#include <vector>
using namespace std;


//  CLASE TURNO

class Turno {
public:
    int turnoID;
    int pacienteID;
    int medicoID;
    string fechaTurno; // formato tal cual el pdf o sea año, mes, dia. todo junto
    string especialidad;
    int duracionMin;

    Turno(int turnoID, int pacienteID, int medicoID, string fechaTurno, string especialidad, int duracionMin) {
        this->turnoID = turnoID;
        this->pacienteID = pacienteID;
        this->medicoID = medicoID;
        this->fechaTurno = fechaTurno;
        this->especialidad = especialidad;
        this->duracionMin = duracionMin;
    }

    void obtenerInfoTurno() {
        cout << "TurnoID: " << turnoID << endl;
        cout << "PacienteID: " << pacienteID << endl;
        cout << "MedicoID: " << medicoID << endl;
        cout << "Fecha: " << fechaTurno << endl;
        cout << "Especialidad: " << especialidad << endl;
        cout << "Duracion: " << duracionMin << " minutos." << endl;
    }
};

//  CLASE PACIENTE

class Paciente {
public:
    int pacienteID;
    int dni;
    string fechaIngreso; // idem fecha turno
    string diagnostico;
    int prioridad;
    float peso;
    string codigoHospital;
    vector<Turno> turnos;

    Paciente(int pacienteID, int dni, string fechaIngreso, string diagnostico, int prioridad, float peso, string codigoHospital) {
        this->pacienteID = pacienteID;
        this->dni = dni;
        this->fechaIngreso = fechaIngreso;
        this->diagnostico = diagnostico;
        this->prioridad = prioridad;
        this->peso = peso;
        this->codigoHospital = codigoHospital;
    }

    void agregarTurno(Turno turno) {
        turnos.push_back(turno);
    }

    void obtenerTurnos() {
        if (turnos.size() == 0) {
            cout << "El paciente " << pacienteID << " no tiene turnos." << endl;
            return;
        }
        cout << "Turnos del paciente " << pacienteID << ":" << endl;
        for (int i = 0; i < turnos.size(); i++) {
            turnos[i].obtenerInfoTurno();
        }
    }

    void obtenerInfoPaciente() {
        cout << "PacienteID: " << pacienteID << endl;
        cout << "DNI: " << dni << endl;
        cout << "Fecha que ingresó: " << fechaIngreso << endl;
        cout << "Diagnostico: " << diagnostico << endl;
        cout << "Prioridad: " << prioridad << endl;
        cout << "Peso: " << peso << endl;
        cout << "Hospital: " << codigoHospital << endl;
        cout << "Turnos: " << turnos.size() << endl;
    }
};

//  CLASE MEDICO

class Medico {
public:
    int medicoID;
    string nombre;
    string especialidad;
    vector<Turno> turnos;

    Medico(int medicoID, string nombre, string especialidad) {
        this->medicoID = medicoID;
        this->nombre = nombre;
        this->especialidad = especialidad;
    }

    void agregarTurno(Turno turno) {
        turnos.push_back(turno);
    }

    void obtenerInfoMedico() {
        cout << "Medico ID: " << medicoID << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Especialidad: " << especialidad << endl;
        cout << "Turnos: " << turnos.size() << endl;
    }

    void obtenerListaTurno() {
        cout << "Turnos del médico " << nombre << ":" << endl;
        for (int i = 0; i < turnos.size(); i++) {
            turnos[i].obtenerInfoTurno();
            cout << "---" << endl;
        }
    }
};

//  CLASE HOSPITAL

class Hospital {
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

    Hospital(string codigo, string nombre, string ciudad, int capacidadCamas, vector<string> especialidades, int personalMedico, double presupuestoAnual) {
        this->codigo = codigo;
        this->nombre = nombre;
        this->ciudad = ciudad;
        this->capacidadCamas = capacidadCamas;
        this->especialidades = especialidades;
        this->personalMedico = personalMedico;
        this->presupuestoAnual = presupuestoAnual;
    }

    void agregarPaciente(Paciente paciente) {
        pacientes.push_back(paciente);
    }

    void agregarTurno(Turno turno) {
        turnos.push_back(turno);
    }

    void eliminarPaciente(int pacienteID) {
        for (int i = 0; i < (int)pacientes.size(); i++) {
            if (pacientes[i].pacienteID == pacienteID) {
                for (int j = i; j < (int)pacientes.size() - 1; j++) {
                    pacientes[j] = pacientes[j + 1];
                }
                pacientes.pop_back();
                cout << "Borraste el paciente" << pacienteID << " del hospital " << codigo << "." << endl;
                return;
            }
        }
        cout << "Paciente " << pacienteID << " no encontrado." << endl;
    }

    int obtenerDisponibilidad() {
        return capacidadCamas - (int)pacientes.size();
    }

    bool tieneEspecialidad(string especialidad) {
        for (int i = 0; i < (int)especialidades.size(); i++) {
            if (especialidades[i] == especialidad) return true;
        }
        return false;
    }

    void obtenerInfoHospital() {
        cout << "Hospital: " << codigo << endl;
        cout << "Nombre:" << nombre << endl;
        cout << "Ciudad:" << ciudad << endl;
        cout << "Capacidad camas: " << capacidadCamas << endl;
        cout << "Personal medico: " << personalMedico << endl;
        cout << "Presupuesto anual: " << presupuestoAnual << endl;
        cout << "Camas libres: " << obtenerDisponibilidad() << endl;
        cout << "Especialidades: ";
        for (int i = 0; i < (int)especialidades.size(); i++) {
            cout << especialidades[i] << endl;
        }
        cout << "Pacientes actuales: " << pacientes.size() << endl;
        cout << "Turnos registrados: " << turnos.size() << endl;
    }
};

//  CLASE DERIVACION

class Derivacion {
public:
    string codigoOrigen;
    string codigoDestino;
    int tiempoMinutos;

    Derivacion(string codigoOrigen, string codigoDestino, int tiempoMinutos) {
        this->codigoOrigen = codigoOrigen;
        this->codigoDestino = codigoDestino;
        this->tiempoMinutos = tiempoMinutos;
    }

    void obtenerInfoDerivacion() {
        cout << "Derivacion" << endl;
        cout << "Origen: " << codigoOrigen << endl;
        cout << "Destino: " << codigoDestino << endl;
        cout << "Tiempo: " << tiempoMinutos << " min" << endl;
    }
};