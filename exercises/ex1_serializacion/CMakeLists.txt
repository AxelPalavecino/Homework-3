cmake_minimum_required(VERSION 3.10)
project(ex1_serializacion)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

# Aplicación principal (ejemplo básico)
add_executable(ex1_serializacion 
    main.cpp
    src/MedicionBase.cpp
    src/Posicion.cpp
    src/Presion.cpp
    src/SaveFlightData.cpp
)