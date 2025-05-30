#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <type_traits>
#include <sstream>
#include <iomanip>
#include <stdexcept> 
#include "ConceptosDatos.hpp"  // Incluir el concept desde archivo común

/**
 * @brief Clase template que procesa datos de un tipo específico para generar JSON
 * 
 * Utiliza un único vector de datos de tipo T para almacenar y procesar información
 * que luego será formateada como JSON según el tipo específico.
 * 
 * @tparam T Tipo de datos a procesar (restringido a double, string, o vector<int>)
 */
template<es_Dato_Aceptable T>
class ProcesadorDeDatos {
private: 
    std::vector<T> datos;  ///< Vector de datos del tipo T

public:
    /**
     * @brief Agrega un dato al vector
     * @param dato Valor a agregar
     */
    void agregarDato(const T& dato) {
        datos.push_back(dato);
    }

    /**
     * @brief Procesa los datos y los convierte a formato JSON
     * @return String con el formato JSON apropiado para el tipo T
     */
    std::string procesarDatos() const {
        if constexpr (std::is_same_v<T, double>) {
            return formatoDoubles();
        }
        else if constexpr (std::is_same_v<T, std::string>) {
            return formatoStrings();
        }
        else if constexpr (std::is_same_v<T, std::vector<int>>) {
            return formatoMatrizInts();
        }
        return "";
    }

private:
    /**
     * @brief Formatea los valores double como array JSON
     * @return String con formato JSON para los doubles almacenados
     */
    std::string formatoDoubles() const {
        std::string result = "[";
        for (size_t i = 0; i < datos.size(); ++i) {
            std::ostringstream oss;
            oss << std::fixed << std::setprecision(1) << datos[i];
            result += oss.str();
            if (i < datos.size() - 1) result += ", ";
        }
        result += "]";
        return result;
    }
    
    /**
     * @brief Formatea las cadenas como array JSON con escapado apropiado
     * @return String con formato JSON para las cadenas almacenadas
     */
    std::string formatoStrings() const {
        std::string result = "[";
        for (size_t i = 0; i < datos.size(); ++i) {
            result += "\"" + datos[i] + "\"";
            if (i < datos.size() - 1) result += ", ";
        }
        result += "]";
        return result;
    }
    
    /**
     * @brief Formatea los vectores de enteros como array bidimensional JSON
     * @return String con formato JSON para los vectores de enteros almacenados
     */
    std::string formatoMatrizInts() const {
        std::string result = "[\n";
        for (size_t i = 0; i < datos.size(); ++i) {
            result += "           [";
            for (size_t j = 0; j < datos[i].size(); ++j) {
                result += std::to_string(datos[i][j]);
                if (j < datos[i].size() - 1) result += ", ";
            }
            result += "]";
            if (i < datos.size() - 1) result += ",";
            result += "\n";
        }
        result += "           ]";
        return result;
    }
};