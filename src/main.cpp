#include <iostream>
#include "../include/Hospital.h"
#include "../include/Paciente.h"
#include "../include/Medico.h"

using namespace std;

int main()
{
    Hospital hospital("123", "Hospital Posadas", "Moron", 200, {"Neurologia", "Cardiologia"}, 50, 50000000);

    hospital.obtenerInfoHospital();

    return 0;
}