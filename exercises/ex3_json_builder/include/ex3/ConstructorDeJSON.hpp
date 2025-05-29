#pragma once

#include <iostream>
#include <vector>

class ConstructorDeJSON {
private: 
    std::vector<std::pair<std::string, std::string>> partesJSON;  

public:
    void agregarSeccion(const std::string &etiqueta, const std::string& contenido);
    void PrintearJSON() const;
    void guardarEnArchivo(const std::string& nombreArchivo = "output.json") const;
};