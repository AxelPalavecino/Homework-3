#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <type_traits>


class ProcesadorDeDatos {
private: 
    std::vector<double> doubles; 
    std::vector<std::string> cadenas; 
    std::vector<std::vector<int>> matrizEnteros; 

    std::string formatoDoubles() const;
    std::string formatoStrings() const;
    std::string formatoMatrizInts() const; 

public:
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