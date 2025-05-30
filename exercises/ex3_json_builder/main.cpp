#include "include/ex3/ProcesadorDeDatos.hpp"
#include "include/ex3/ConstructorDeJSON.hpp"
#include <iostream>

int main() {
    // ===================================
    //          EJEMPLO ENUNCIADO 
    // ==================================
    
    // Crear procesadores para cada tipo de dato
    ProcesadorDeDatos<double> procesadorDoubles;
    ProcesadorDeDatos<std::string> procesadorStrings;
    ProcesadorDeDatos<std::vector<int>> procesadorVectores;
    
    // Agregar datos de diferentes tipos
    procesadorDoubles.agregarDato(1.3);
    procesadorDoubles.agregarDato(2.1);
    procesadorDoubles.agregarDato(3.2);
    
    procesadorStrings.agregarDato(std::string("Hola, Mundo"));
    
    procesadorVectores.agregarDato(std::vector<int>{1, 2});
    procesadorVectores.agregarDato(std::vector<int>{3, 2});
    
    // Crear instancia del constructor JSON
    ConstructorDeJSON builder;
    
    // Procesar y agregar cada sección al JSON con validación
    try {
        builder.agregarSeccion("vec_doubles", procesadorDoubles);
        builder.agregarSeccion("palabras", procesadorStrings);
        builder.agregarSeccion("listas", procesadorVectores);
        
        // La siguiente línea generaría error por tipo incorrecto:
        // builder.agregarSeccion("vec_doubles", procesadorStrings);
        
        // Esta línea generaría error por etiqueta no válida:
        // builder.agregarSeccion("otra_etiqueta", procesadorDoubles);
        
        builder.PrintearJSON();
        
        // Guarda del archivo JSON
        builder.guardarEnArchivo("output.json");
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}