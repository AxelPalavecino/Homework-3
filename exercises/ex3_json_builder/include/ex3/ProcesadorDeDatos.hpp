#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <type_traits>

/**
 * @brief Clase template que procesa datos de diferentes tipos para generar JSON
 * 
 * Utiliza templates con `constexpr if` para manejar múltiples tipos de datos
 * (double, string, vector<int>) y formatearlos apropiadamente para salida JSON.
 * La clase demuestra programación genérica moderna con características de C++17.
 */
class ProcesadorDeDatos {
private: 
    std::vector<double> doubles;                ///< Contenedor para valores de tipo double
    std::vector<std::string> cadenas;           ///< Contenedor para strings
    std::vector<std::vector<int>> matrizEnteros; ///< Contenedor para vectores de enteros

    /**
     * @brief Formatea los valores double como array JSON
     * @return String con formato JSON para los doubles almacenados
     */
    std::string formatoDoubles() const;
    
    /**
     * @brief Formatea las cadenas como array JSON con escapado apropiado
     * @return String con formato JSON para las cadenas almacenadas
     */
    std::string formatoStrings() const;
    
    /**
     * @brief Formatea los vectores de enteros como array bidimensional JSON
     * @return String con formato JSON para los vectores de enteros almacenados
     */
    std::string formatoMatrizInts() const; 

public:
    /**
     * @brief Template que agrega datos de cualquier tipo soportado
     * 
     * Utiliza `constexpr if` para determinar en tiempo de compilación
     * qué contenedor usar basado en el tipo T del parámetro.
     * 
     * @tparam T Tipo del dato a agregar (double, string, o vector<int>)
     * @param dato Referencia constante al dato que se va a almacenar
     */
    template <typename T>
    void agregarDato(const T& dato) {
        if constexpr (std::is_same_v<T, double>) {
            doubles.push_back(dato);
        }
        else if constexpr (std::is_same_v<T, std::string>) {
            cadenas.push_back(dato);
        }
        else if constexpr (std::is_same_v<T, std::vector<int>>) {
            matrizEnteros.push_back(dato);
        }
    }

    /**
     * @brief Template que procesa y formatea datos de un tipo específico
     * 
     * Utiliza `constexpr if` para seleccionar el formateador apropiado
     * basado en el tipo T especificado en la llamada.
     * 
     * @tparam T Tipo de datos a procesar (double, string, o vector<int>)
     * @return String con los datos formateados como JSON, o string vacío si el tipo no es soportado
     */
    template <typename T>
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
};