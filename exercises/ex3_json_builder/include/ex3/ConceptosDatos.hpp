#pragma once

#include <type_traits>
#include <vector>
#include <string>

/**
 * @brief Concept que define los tipos de datos aceptables para el procesador
 * 
 * Restringe los tipos que pueden ser utilizados en ProcesadorDeDatos a
 * solamente double, string o vector<int>.
 */
template<typename T>
concept es_Dato_Aceptable = std::is_same_v<double, T> || 
                            std::is_same_v<std::string, T> || 
                            std::is_same_v<std::vector<int>, T>;
