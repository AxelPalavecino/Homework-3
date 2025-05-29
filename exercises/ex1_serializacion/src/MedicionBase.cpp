#include "../include/ex1/MedicionBase.hpp"

MedicionBase::MedicionBase(float t) : tiempoMedicion(std::make_unique<float>(t)) {}

MedicionBase::MedicionBase(const MedicionBase& other) : tiempoMedicion(std::make_unique<float>(*other.tiempoMedicion)) {}

float MedicionBase::getTiempo() const {
    return *tiempoMedicion;
}

void MedicionBase::serializar(std::ofstream &out) const {
    if (!out) throw std::runtime_error("Error al abrir archivo para serializar MedicionBase\n");
    
    out.write(reinterpret_cast<const char*>(&(*tiempoMedicion)), sizeof(float));
    if (!out.good()) throw std::runtime_error("Error al escribir tiempo de medicion en MedicionBase\n");
}

void MedicionBase::deserializar(std::ifstream& in) {
    if (!in) throw std::runtime_error("Error al abrir archivo para deserializar en MedicionBase\n");

    if (!tiempoMedicion) {
        tiempoMedicion = std::make_unique<float>();
    }

    in.read(reinterpret_cast<char*>(tiempoMedicion.get()), sizeof(float));
    if (!in.good()) throw std::runtime_error("Error al leer tiempo de medicion\n");
}

