#include <iostream>
#include "../include/Paciente.h"
#include "../include/ColaPrioridadPacientes.h"

using namespace std;

int main()
{
    ColaPrioridadPacientes colaEspera;

    Paciente p1(1001, 12345678, "20250310", "Fractura", 3, 72.5, "HGA");
    Paciente p2(1002, 23456789, "20250308", "Infarto", 1, 80.0, "HGA");

    colaEspera.insertar(p1);
    colaEspera.insertar(p2);

    colaEspera.mostrarListaEspera();

    cout << endl;
    cout << "Atendiendo pacientes" << endl;
    while (!colaEspera.estaVacia())
    {
        Paciente atendido = colaEspera.extraerMasUrgente();
        cout << "Paciente " << atendido.pacienteID << endl;
        cout << "DNI: " << atendido.dni << endl;
        cout << "Prioridad: " << atendido.prioridad << endl;
        cout << endl;
    }

    cout << "Cola vacia. Fin del programa." << endl;

    return 0;
}