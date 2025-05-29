#pragma once 
#include "IMediciones.hpp"
#include <memory>

/**
 * @brief Clase base abstracta para todas las mediciones de vuelo
 * 
 * Proporciona funcionalidad común para manejo de tiempo de medición
 * usando smart pointers y define la interfaz para serialización.
 */
class MedicionBase : public IMediciones {
    protected: 
        std::unique_ptr<float> tiempoMedicion;  ///< Tiempo de medición en segundos usando smart pointer
        
    public: 
        /**
         * @brief Constructor que inicializa el tiempo de medición
         * @param t Tiempo de medición en segundos
         */
        MedicionBase(float t);
        
        /**
         * @brief Constructor de copia que duplica el smart pointer
         * @param other Objeto MedicionBase a copiar
         */
        MedicionBase(const MedicionBase& other);

        /**
         * @brief Destructor virtual por defecto
         */
        virtual ~MedicionBase() = default;
    
        /**
         * @brief Obtiene el tiempo de medición
         * @return Tiempo en segundos
         */
        float getTiempo() const; 
        
        /**
         * @brief Método virtual puro para mostrar datos por consola
         */
        virtual void imprimir() const = 0;

        /**
         * @brief Serializa el tiempo de medición a archivo binario
         * @param out Stream de salida donde escribir el tiempo
         */
        void serializar(std::ofstream &out) const override;
        
        /**
         * @brief Deserializa el tiempo de medición desde archivo binario
         * @param in Stream de entrada desde donde leer el tiempo
         */
        void deserializar(std::ifstream &in) override;
};