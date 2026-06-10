#include "../include/ColaPrioridadPacientes.h"
#include <iostream>
#include <algorithm>

using namespace std;

ColaPrioridadPacientes::ColaPrioridadPacientes()
{
}

int ColaPrioridadPacientes::obtenerPadre(int indice) const
{
    return (indice - 1) / 2;
}

int ColaPrioridadPacientes::obtenerIzquierdo(int indice) const
{
    return 2 * indice + 1;
}

int ColaPrioridadPacientes::obtenerDerecho(int indice) const
{
    return 2 * indice + 2;
}

bool ColaPrioridadPacientes::tieneUnaMayorPrioridad(const Paciente& paciente1, const Paciente& paciente2) const
{
    if (paciente1.prioridad != paciente2.prioridad)
    {
        return paciente1.prioridad < paciente2.prioridad;
    }
    return paciente1.fechaIngreso < paciente2.fechaIngreso;
}

void ColaPrioridadPacientes::insertar(const Paciente& paciente)
{
    heap.push_back(paciente);
    bubbleDarUp(heap.size() - 1);
}

void ColaPrioridadPacientes::bubbleDarUp(int indice)
{
    while (indice > 0)
    {
        int indicePadre = obtenerPadre(indice);

        if (tieneUnaMayorPrioridad(heap[indice], heap[indicePadre]))
        {
            swap(heap[indice], heap[indicePadre]);
            indice = indicePadre;
        }
        else
        {
            break;
        }
    }
}

Paciente ColaPrioridadPacientes::extraerMasUrgente()
{
    if (estaVacia())
    {
        throw runtime_error("Error: La cola de prioridad está vacía");
    }

    Paciente masUrgente = heap[0];

    heap[0] = heap.back();
    heap.pop_back();

    if (!estaVacia())
    {
        bubbleDown(0);
    }

    return masUrgente;
}

void ColaPrioridadPacientes::bubbleDown(int indice)
{
    int tamanio = heap.size();

    while (true)
    {
        int indiceIzquierdo = obtenerIzquierdo(indice);
        int indiceDerecho = obtenerDerecho(indice);
        int indiceMasPequeno = indice;

        if (indiceIzquierdo < tamanio &&
            tieneUnaMayorPrioridad(heap[indiceIzquierdo], heap[indiceMasPequeno]))
        {
            indiceMasPequeno = indiceIzquierdo;
        }

        if (indiceDerecho < tamanio &&
            tieneUnaMayorPrioridad(heap[indiceDerecho], heap[indiceMasPequeno]))
        {
            indiceMasPequeno = indiceDerecho;
        }

        if (indiceMasPequeno != indice)
        {
            swap(heap[indice], heap[indiceMasPequeno]);
            indice = indiceMasPequeno;
        }
        else
        {
            break;
        }
    }
}

bool ColaPrioridadPacientes::estaVacia() const
{
    return heap.empty();
}

int ColaPrioridadPacientes::obtenerTamano() const
{
    return heap.size();
}

void ColaPrioridadPacientes::mostrarListaEspera() const
{
    if (estaVacia())
    {
        cout << "La cola de espera esta vacia" << endl;
        return;
    }

    cout << endl;
    cout << "Pacientes" << endl;

    for (int i = 0; i < heap.size(); i++)
    {
        cout << "Paciente " << i + 1 << ":" << endl;
        cout << "ID: " << heap[i].pacienteID << endl;
        cout << "DNI: " << heap[i].dni << endl;
        cout << "Prioridad: " << heap[i].prioridad << endl;
        cout << "Fecha de ingreso: " << heap[i].fechaIngreso << endl;
        cout << endl;
    }
}
