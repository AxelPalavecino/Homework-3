#include "../include/ex1/Posicion.hpp"
#include <iostream>

Posicion::Posicion(float lat, float lon, float alt, float t) : MedicionBase(t), 
                                                               latitud(lat), 
                                                               longitud(lon), 
                                                               altitud(alt) {}

Posicion::Posicion(const Posicion &other) : MedicionBase(*other.tiempoMedicion), 
                                            latitud(other.latitud), 
                                            longitud(other.longitud), 
                                            altitud(other.altitud) {}

void Posicion::serializar(std::ofstream &out) const {
    MedicionBase::serializar(out);

    out.write(reinterpret_cast<const char*>(&latitud), sizeof(float));
    if (!out.good()) throw std::runtime_error("Error al escribir latitud\n");

    out.write(reinterpret_cast<const char*>(&longitud), sizeof(float));
    if (!out.good()) throw std::runtime_error("Error al escribir longitud\n");

    out.write(reinterpret_cast<const char*>(&altitud), sizeof(float));
    if (!out.good()) throw std::runtime_error("Error al escribir altitud\n");
}

void Posicion::deserializar(std::ifstream &in) {
    MedicionBase::deserializar(in);

    in.read(reinterpret_cast<char*>(&latitud), sizeof(float));
    if (!in.good()) throw std::runtime_error("Error al leer latitud");

    in.read(reinterpret_cast<char*>(&longitud), sizeof(float));
    if (!in.good()) throw std::runtime_error("Error al leer longitud");
    
    in.read(reinterpret_cast<char*>(&altitud), sizeof(float));
    if (!in.good()) throw std::runtime_error("Error al leer altitud");
    
}

void Posicion::imprimir() const {
    std::cout << "Tiempo de medición: " << *tiempoMedicion << " segundos " << std::endl;   
    std::cout << "Latitud: " << latitud << "°" << std::endl;
    std::cout << "Longitud: " << longitud << "°" << std::endl;
    std::cout << "Altitud: " << altitud << " metros" << std::endl;
}