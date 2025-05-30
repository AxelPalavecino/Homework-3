cmake_minimum_required(VERSION 3.10)
project(ex2_templates)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

# Aplicación principal (ejemplo básico)
add_executable(ex2_templates 
    main.cpp
    src/Punto.cpp
    src/Circulo.cpp
    src/Elipse.cpp
    src/Rectangulo.cpp
)

