#pragma once
#include <iostream>
#include <fstream>

/**
 * @brief Interfaz abstracta para serialización de mediciones
 * 
 * Define los métodos que deben implementar todas las clases
 * que manejen datos serializables de mediciones de vuelo.
 */
class IMediciones {
    public: 
        /**
         * @brief Destructor virtual por defecto
         */
        virtual ~IMediciones() = default; 
        
        /**
         * @brief Serializa datos a un archivo binario
         * @param out Stream de salida donde escribir los datos
         */
        virtual void serializar(std::ofstream &out) const = 0;
        
        /**
         * @brief Deserializa datos desde un archivo binario
         * @param in Stream de entrada desde donde leer los datos
         */
        virtual void deserializar(std::ifstream &in) = 0;
};