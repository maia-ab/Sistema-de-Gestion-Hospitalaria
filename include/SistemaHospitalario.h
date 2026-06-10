#ifndef SISTEMAHOSPITALARIO_H
#define SISTEMAHOSPITALARIO_H

#include <string>
#include <vector>
#include "Hospital.h"

using namespace std;

class SistemaHospitalario
{
private:
    vector<vector<Hospital>> tablaHash;
    struct Conexion
    {
        int hospitalDestino;
        int tiempo;
    };
    vector<vector<Conexion>> grafoHospitales;

public:
    void infoDeHospital(int hospitalID);
    void agregarHospital(Hospital hospital);
    void eliminarHospital(int hospitalID);
    Hospital *buscarHospital(int hospitalID);
    void listarHospitales();
    int funcionHash(int hospitalID);
};

#endif