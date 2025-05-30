#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <type_traits>
#include "ConceptosDatos.hpp"  // Incluir el concept desde archivo común

// Forward declaration para usar ProcesadorDeDatos
template<es_Dato_Aceptable T>
class ProcesadorDeDatos;

/**
 * @brief Clase que construye y maneja archivos JSON estructurados
 * 
 * Permite agregar secciones de datos formateados y generar un archivo JSON
 * válido con estructura adecuada. Proporciona funcionalidades para mostrar
 * el JSON por consola y guardarlo en archivo.
 */
class ConstructorDeJSON {
private: 
    /**
     * @brief Contenedor de pares etiqueta-contenido para las secciones JSON
     * 
     * Cada par representa una sección del JSON final donde:
     * - first: etiqueta/clave de la sección
     * - second: contenido formateado de la sección
     */
    std::vector<std::pair<std::string, std::string>> partesJSON;  

    /**
     * @brief Verifica si una etiqueta es válida
     * 
     * Solo permite las etiquetas predefinidas: "vec_doubles", "palabras", "listas"
     * 
     * @param etiqueta Etiqueta a verificar
     * @return true si la etiqueta es válida, false en caso contrario
     */
    bool esEtiquetaValida(const std::string& etiqueta) const {
        return etiqueta == "vec_doubles" || 
               etiqueta == "palabras" || 
               etiqueta == "listas";
    }

public:
    /**
     * @brief Agrega una nueva sección al JSON con validación de etiqueta y tipo
     * 
     * Verifica que la etiqueta sea una de las permitidas y que el tipo
     * de datos coincida con lo esperado para esa etiqueta.
     * 
     * @tparam T Tipo de datos en el procesador (restringido por es_Dato_Aceptable)
     * @param etiqueta Nombre/clave de la sección JSON (debe ser una etiqueta válida)
     * @param procesador Procesador de datos con el contenido a formatear
     * @throws std::invalid_argument Si la etiqueta es inválida o el tipo no coincide
     */
    template<es_Dato_Aceptable T>
    void agregarSeccion(const std::string& etiqueta, const ProcesadorDeDatos<T>& procesador) {
        // Verificar si la etiqueta es válida
        if (!esEtiquetaValida(etiqueta)) {
            throw std::invalid_argument("Etiqueta no válida. Use 'vec_doubles', 'palabras' o 'listas'");
        }

        // Verificar que el tipo coincida con la etiqueta
        if (etiqueta == "vec_doubles" && !std::is_same_v<T, double>) {
            throw std::invalid_argument("La etiqueta 'vec_doubles' requiere un ProcesadorDeDatos<double>");
        }
        else if (etiqueta == "palabras" && !std::is_same_v<T, std::string>) {
            throw std::invalid_argument("La etiqueta 'palabras' requiere un ProcesadorDeDatos<std::string>");
        }
        else if (etiqueta == "listas" && !std::is_same_v<T, std::vector<int>>) {
            throw std::invalid_argument("La etiqueta 'listas' requiere un ProcesadorDeDatos<std::vector<int>>");
        }

        // Si todo está bien, agregar la sección
        std::string contenido = procesador.procesarDatos();
        partesJSON.emplace_back(etiqueta, contenido);
    }
    
    /**
     * @brief Muestra el JSON completo por consola con formato legible
     * 
     * Itera a través de todas las secciones agregadas y las muestra
     * con la estructura JSON apropiada, incluyendo llaves, comas y saltos de línea.
     */
    void PrintearJSON() const;
    
    /**
     * @brief Guarda el JSON en un archivo con el nombre especificado
     * 
     * Crea un archivo con el JSON formateado correctamente. Si no se puede
     * crear el archivo, muestra un mensaje de error por stderr.
     * 
     * @param nombreArchivo Nombre del archivo donde guardar el JSON (por defecto "output.json")
     */
    void guardarEnArchivo(const std::string& nombreArchivo = "output.json") const;
};