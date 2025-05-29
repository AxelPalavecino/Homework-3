#pragma once

#include <iostream>
#include <vector>
#include <string>

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

public:
    /**
     * @brief Agrega una nueva sección al JSON en construcción
     * 
     * Valida que tanto la etiqueta como el contenido no estén vacíos
     * antes de agregar la sección al contenedor interno.
     * 
     * @param etiqueta Nombre/clave de la sección JSON
     * @param contenido Datos formateados para esta sección
     */
    void agregarSeccion(const std::string &etiqueta, const std::string& contenido);
    
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