#pragma once
#include "MedicionBase.hpp"

/**
 * @brief Clase que representa la posición geográfica de una aeronave
 * 
 * Hereda de MedicionBase para incluir tiempo de medición y agrega
 * coordenadas geográficas y altitud.
 */
class Posicion : public MedicionBase {
    public: 
        float latitud;   ///< Latitud en grados decimales (-90 a +90)
        float longitud;  ///< Longitud en grados decimales (-180 a +180)
        float altitud;   ///< Altitud sobre el nivel del mar en metros

        /**
         * @brief Constructor con coordenadas y tiempo de medición
         * @param lat Latitud en grados decimales
         * @param lon Longitud en grados decimales
         * @param alt Altitud en metros sobre nivel del mar
         * @param t Tiempo de medición en segundos
         */
        Posicion(float lat, float lon, float alt, float t); 
        
        /**
         * @brief Constructor de copia
         * @param other Objeto Posicion a copiar
         */
        Posicion(const Posicion &other);

        /**
         * @brief Serializa datos de posición a archivo binario
         * @param out Stream de salida para escribir datos
         */
        void serializar(std::ofstream &out) const override;
        
        /**
         * @brief Deserializa datos de posición desde archivo binario
         * @param in Stream de entrada para leer datos
         */
        void deserializar(std::ifstream &in) override; 
        
        /**
         * @brief Muestra por consola los datos de posición
         */
        void imprimir() const override;
};
