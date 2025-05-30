#include "../include/ex3/ConstructorDeJSON.hpp"
#include <iostream>
#include <fstream>

void ConstructorDeJSON::PrintearJSON() const {
    std::cout << "{\n"; 
    auto iterador = partesJSON.begin(); 
    while (iterador != partesJSON.end()) {
        std::cout << " \"" << iterador->first << " \" : " << iterador->second;
        ++iterador; 
        if (iterador != partesJSON.end()) {
            std::cout << ",";
        } 
        std::cout << "\n";
    }
    std::cout << "}\n";
}

void ConstructorDeJSON::guardarEnArchivo(const std::string& nombreArchivo) const {
    std::ofstream file(nombreArchivo);
    if (!file.is_open()) {
        std::cerr << "Error: No se pudo crear el archivo " << nombreArchivo << std::endl;
        return;
    }

    file << "{\n";
    auto iterador = partesJSON.begin();
    while (iterador != partesJSON.end()) {
            file << "  \"" << iterador->first << "\" : " << iterador->second;
            ++iterador;
            if (iterador != partesJSON.end()) {
                file << ",";
            }
            file << "\n";
    }
    file << "}\n";
    file.close();
}