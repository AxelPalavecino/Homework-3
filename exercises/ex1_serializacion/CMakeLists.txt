cmake_minimum_required(VERSION 3.10)
project(ex1_serializacion)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

# Aplicación principal (ejemplo básico)
add_executable(ex1_serializacion 
    main.cpp
    src/MedicionBase.cpp
    src/Posicion.cpp
    src/Presicion.cpp
    src/SaveFlightData.cpp
)

# Tests (ejecutable separado)
add_subdirectory(tests)