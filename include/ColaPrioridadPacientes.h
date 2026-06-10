#ifndef COLA_PRIORIDAD_PACIENTES_H
#define COLA_PRIORIDAD_PACIENTES_H

#include <vector>
#include "Paciente.h"
using namespace std;

class ColaPrioridadPacientes
{
private:
    vector<Paciente> heap;

    int obtenerPadre(int indice) const;
    int obtenerIzquierdo(int indice) const;
    int obtenerDerecho(int indice) const;

    bool tieneUnaMayorPrioridad(const Paciente& paciente1, const Paciente& paciente2) const;

    // Funciones para mantener la propiedad del heap
    void bubbleDarUp(int indice);   // Sube elemento hacia la raíz
    void bubbleDown(int indice);    // Baja elemento hacia las hojas

public:
    ColaPrioridadPacientes();

    void insertar(const Paciente& paciente);
    Paciente extraerMasUrgente();
    bool estaVacia() const;
    int obtenerTamano() const;

    void mostrarListaEspera() const;
};

#endif
