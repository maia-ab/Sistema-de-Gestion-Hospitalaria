cmake_minimum_required(VERSION 3.10)

project(SistemaHospitalario)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(SistemaHospitalario
    src/Turno.cpp
    src/Paciente.cpp
    src/Medico.cpp
    src/Hospital.cpp
    src/Especialidad.cpp
    src/Diagnostico.cpp
    src/SistemaHospitalario.cpp
    src/ColaPrioridadPacientes.cpp
    src/main.cpp
)