#pragma once
#include "MedicionBase.hpp"
#include <stdexcept>

/**
 * @brief Clase que representa mediciones de presión atmosférica
 * 
 * Hereda de MedicionBase para incluir tiempo de medición y agrega
 * datos específicos de presión estática y dinámica.
 */
class Presion : public MedicionBase {
    public: 
        float presionEstatica;  ///< Presión atmosférica estática en hPa
        float presionDinamica;  ///< Presión dinámica del aire en hPa

        /**
         * @brief Constructor con valores de presión y tiempo
         * @param p Presión estática en hectopascales
         * @param q Presión dinámica en hectopascales  
         * @param t Tiempo de medición en segundos
         */
        Presion(float p, float q, float t);
        
        /**
         * @brief Constructor de copia
         * @param other Objeto Presion a copiar
         */
        Presion(const Presion& other);

        /**
         * @brief Serializa datos de presión a archivo binario
         * @param out Stream de salida para escribir datos
         */
        void serializar(std::ofstream &out) const override;
        
        /**
         * @brief Deserializa datos de presión desde archivo binario
         * @param in Stream de entrada para leer datos
         */
        void deserializar(std::ifstream &in) override; 
        
        /**
         * @brief Muestra por consola los datos de presión
         */
        void imprimir() const override;
};