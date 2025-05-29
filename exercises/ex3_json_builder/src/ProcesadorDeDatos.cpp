#include "../include/ex3/ProcesadorDeDatos.hpp"
#include <string>
#include <sstream>
#include <iomanip>


std::string ProcesadorDeDatos::formatoDoubles() const {
    std::string result = "[";
    for (size_t i = 0; i < doubles.size(); ++i) {
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(1) << doubles[i];
        result += oss.str();
        if (i < doubles.size() - 1) result += ", ";
    }
    result += "]";
    return result;
}

std::string ProcesadorDeDatos::formatoStrings() const {
    std::string result = "[";
    for (size_t i = 0; i < cadenas.size(); ++i) {
        result += "\"" + cadenas[i] + "\"";
        if (i < cadenas.size() - 1) result += ", ";
    }
    result += "]";
    return result;
}

std::string ProcesadorDeDatos::formatoMatrizInts() const {
    std::string result = "[\n";
    for (size_t i = 0; i < matrizEnteros.size(); ++i) {
        result += "           [";
        for (size_t j = 0; j < matrizEnteros[i].size(); ++j) {
            result += std::to_string(matrizEnteros[i][j]);
            if (j < matrizEnteros[i].size() - 1) result += ", ";
        }
        result += "]";
        if (i < matrizEnteros.size() - 1) result += ",";
        result += "\n";
    }
    result += "           ]";
    return result;
}