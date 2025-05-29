#include "include/ex3/ProcesadorDeDatos.hpp"
#include "include/ex3/ConstructorDeJSON.hpp"

int main() {
    // ===================================
    //          EJEMPLO ENUNCIADO 
    // ==================================
    ProcesadorDeDatos processor;
    
    // Agregar datos de diferentes tipos
    processor.agregarDato(1.3);
    processor.agregarDato(2.1);
    processor.agregarDato(3.2);
    
    processor.agregarDato(std::string("Hola, Mundo"));
    
    processor.agregarDato(std::vector<int>{1, 2});
    processor.agregarDato(std::vector<int>{3, 2});
    
    // Crear instancia del constructor JSON
    ConstructorDeJSON builder;
    
    // Procesar y agregar cada sección al JSON
    builder.agregarSeccion("vec_doubles", processor.procesarDatos<double>());
    builder.agregarSeccion("palabras", processor.procesarDatos<std::string>());
    builder.agregarSeccion("listas", processor.procesarDatos<std::vector<int>>());
    
    builder.PrintearJSON();
    
    // Guarda del archivo JSON por si quiero verificar su contenido
    builder.guardarEnArchivo("output.json");
    
    return 0;
}