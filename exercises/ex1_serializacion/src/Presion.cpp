#include "../include/ex1/Presion.hpp"
#include <iostream>

Presion::Presion(float p, float q, float t) : MedicionBase(t) , 
                                              presionEstatica(p) , 
                                              presionDinamica(q) {}

Presion::Presion(const Presion& other) : MedicionBase(*other.tiempoMedicion) ,
                                         presionEstatica(other.presionEstatica) , 
                                         presionDinamica(other.presionDinamica) {}

void Presion::serializar(std::ofstream &out) const {
    MedicionBase::serializar(out);

    out.write(reinterpret_cast<const char*>(&presionEstatica), sizeof(float));
    if (!out.good()) throw std::runtime_error("Error al escribir presión estática");
    
    out.write(reinterpret_cast<const char*>(&presionDinamica), sizeof(float));
    if (!out.good()) throw std::runtime_error("Error al escribir presión dinámica");
}

void Presion::deserializar(std::ifstream &in) {
    MedicionBase::deserializar(in);

    in.read(reinterpret_cast<char*>(&presionEstatica), sizeof(float));
    if (!in.good()) throw std::runtime_error("Error al leer presión estática");
    
    in.read(reinterpret_cast<char*>(&presionDinamica), sizeof(float));
    if (!in.good()) throw std::runtime_error("Error al leer presión dinámica");
}

void Presion::imprimir() const {
    std::cout << "Tiempo de medición: " << *tiempoMedicion << " segundos " << std::endl; 
    std::cout << "Presión estática: " << presionEstatica << " hPa" << std::endl;
    std::cout << "Presión dinámica: " << presionDinamica << " hPa" << std::endl;
}