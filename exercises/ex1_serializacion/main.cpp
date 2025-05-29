#include <iostream>
#include <fstream>
#include "include/ex1/SaveFlightData.hpp"

int main() {
    std::cout << "=== EJEMPLO CONSIGNA ===" << std::endl;
    
    Posicion posicion(-34.6f, -58.4f, 950.0f, 5.3f);
    Presion presion(101.3f, 5.8f, 6.1f);
    SaveFlightData datos(posicion, presion);
    
    std::cout << "\nDatos originales:" << std::endl;
    datos.imprimir();
    
    std::ofstream archivo("vuelo.bin", std::ios::binary);
    datos.serializar(archivo);
    archivo.close();
    std::cout << "\nDatos serializados en vuelo.bin" << std::endl;
    
    Posicion posNueva(0, 0, 0, 0);
    Presion presNueva(0, 0, 0);
    SaveFlightData datosNuevos(posNueva, presNueva);
    
    std::ifstream archivoLectura("vuelo.bin", std::ios::binary);
    datosNuevos.deserializar(archivoLectura);
    archivoLectura.close();
    
    std::cout << "\nDatos recuperados:" << std::endl;
    datosNuevos.imprimir();
    
    return 0;
}
