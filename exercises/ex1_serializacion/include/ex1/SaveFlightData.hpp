#pragma once
#include "Presion.hpp"
#include "Posicion.hpp"

/**
 * @brief Clase que agrupa datos de posición y presión de vuelo para serialización
 * 
 * Esta clase combina mediciones de posición y presión atmosférica,
 * permitiendo guardar y recuperar toda la información de vuelo de forma conjunta.
 */
class SaveFlightData {
    public: 
        Posicion posicion;  ///< Datos de posición del vuelo (latitud, longitud, altitud)
        Presion presion;    ///< Datos de presión atmosférica del vuelo

        /**
         * @brief Constructor que inicializa con datos de posición y presión
         * @param p Objeto Posicion con coordenadas y tiempo de medición
         * @param q Objeto Presion con datos atmosféricos y tiempo de medición
         */
        SaveFlightData(const Posicion &p, const Presion &q);

        /**
         * @brief Serializa todos los datos de vuelo a un archivo binario
         * @param out Stream de salida donde escribir los datos serializados
         */
        void serializar(std::ofstream &out) const;
        
        /**
         * @brief Deserializa datos de vuelo desde un archivo binario
         * @param in Stream de entrada desde donde leer los datos
         */
        void deserializar(std::ifstream &in);
        
        /**
         * @brief Muestra por consola todos los datos de vuelo
         */
        void imprimir() const; 
};