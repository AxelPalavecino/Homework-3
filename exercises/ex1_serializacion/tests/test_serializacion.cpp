#include <iostream>
#include <fstream>
#include "../include/ex1/SaveFlightData.hpp"

class ProbadorTests {
private:
    int testsTotal = 0;
    int testsPasados = 0;
    
    void limpiarArchivo(const std::string& nombreArchivo) {
        std::remove(nombreArchivo.c_str());
    }

public:
    void ejecutarTest(const std::string& nombreTest, bool condicion) {
        testsTotal++;
        if (condicion) {
            testsPasados++;
            std::cout << "[EXITOSO] " << nombreTest << std::endl;
        } else {
            std::cout << "[FALLIDO] " << nombreTest << std::endl;
        }
    }
    
    void mostrarResumen() {
        std::cout << "\n=== RESUMEN DE TESTS ===" << std::endl;
        std::cout << "Exitosos: " << testsPasados << "/" << testsTotal << std::endl;
        std::cout << "Porcentaje: " << (testsPasados * 100 / testsTotal) << "%" << std::endl;
    }
    
    // Test 1: Serialización básica
    void testSerializacionBasica() {
        std::cout << "\n--- Test 1: Serialización Básica ---" << std::endl;
        
        Posicion posicionOriginal(-34.6f, -58.4f, 950.0f, 5.3f);
        Presion presionOriginal(101.3f, 5.8f, 6.1f);
        SaveFlightData datosVueloOriginal(posicionOriginal, presionOriginal);
        
        // Serializar
        std::ofstream archivoSalida("test_basico.bin", std::ios::binary);
        datosVueloOriginal.serializar(archivoSalida);
        archivoSalida.close();
        
        // Deserializar
        Posicion posicionRecuperada(0.0f, 0.0f, 0.0f, 0.0f);
        Presion presionRecuperada(0.0f, 0.0f, 0.0f);
        SaveFlightData datosVueloRecuperado(posicionRecuperada, presionRecuperada);
        
        std::ifstream archivoEntrada("test_basico.bin", std::ios::binary);
        datosVueloRecuperado.deserializar(archivoEntrada);
        archivoEntrada.close();
        
        // Verificar datos
        ejecutarTest("Latitud correcta", datosVueloOriginal.posicion.latitud == datosVueloRecuperado.posicion.latitud);
        ejecutarTest("Longitud correcta", datosVueloOriginal.posicion.longitud == datosVueloRecuperado.posicion.longitud);
        ejecutarTest("Altitud correcta", datosVueloOriginal.posicion.altitud == datosVueloRecuperado.posicion.altitud);
        ejecutarTest("Tiempo posición correcto", datosVueloOriginal.posicion.getTiempo() == datosVueloRecuperado.posicion.getTiempo());
        
        ejecutarTest("Presión estática correcta", datosVueloOriginal.presion.presionEstatica == datosVueloRecuperado.presion.presionEstatica);
        ejecutarTest("Presión dinámica correcta", datosVueloOriginal.presion.presionDinamica == datosVueloRecuperado.presion.presionDinamica);
        ejecutarTest("Tiempo presión correcto", datosVueloOriginal.presion.getTiempo() == datosVueloRecuperado.presion.getTiempo());
        
        limpiarArchivo("test_basico.bin");
    }
    
    // Test 2: Valores extremos
    void testValoresExtremos() {
        std::cout << "\n--- Test 2: Valores Extremos ---" << std::endl;
        
        Posicion posicionExtrema(0.0f, -180.0f, -500.0f, 0.0f);
        Presion presionExtrema(0.0f, 1013.25f, 99999.9f);
        SaveFlightData datosExtremos(posicionExtrema, presionExtrema);
        
        std::ofstream archivoSalida("test_extremos.bin", std::ios::binary);
        datosExtremos.serializar(archivoSalida);
        archivoSalida.close();
        
        Posicion posicionRecuperada(1.0f, 1.0f, 1.0f, 1.0f);
        Presion presionRecuperada(1.0f, 1.0f, 1.0f);
        SaveFlightData datosRecuperados(posicionRecuperada, presionRecuperada);
        
        std::ifstream archivoEntrada("test_extremos.bin", std::ios::binary);
        datosRecuperados.deserializar(archivoEntrada);
        archivoEntrada.close();
        
        ejecutarTest("Latitud cero", datosExtremos.posicion.latitud == datosRecuperados.posicion.latitud);
        ejecutarTest("Longitud negativa", datosExtremos.posicion.longitud == datosRecuperados.posicion.longitud);
        ejecutarTest("Altitud negativa", datosExtremos.posicion.altitud == datosRecuperados.posicion.altitud);
        ejecutarTest("Presión grande", datosExtremos.presion.presionDinamica == datosRecuperados.presion.presionDinamica);
        
        limpiarArchivo("test_extremos.bin");
    }
    
    // Test 3: Constructor de copia
    void testConstructorCopia() {
        std::cout << "\n--- Test 3: Constructor de Copia ---" << std::endl;
        
        Posicion posicionOriginal(12.34f, 56.78f, 2000.0f, 15.5f);
        Posicion posicionCopia(posicionOriginal);
        
        Presion presionOriginal(1020.5f, 85.3f, 20.2f);
        Presion presionCopia(presionOriginal);
        
        ejecutarTest("Copia latitud", posicionOriginal.latitud == posicionCopia.latitud);
        ejecutarTest("Copia longitud", posicionOriginal.longitud == posicionCopia.longitud);
        ejecutarTest("Copia altitud", posicionOriginal.altitud == posicionCopia.altitud);
        ejecutarTest("Copia tiempo posición", posicionOriginal.getTiempo() == posicionCopia.getTiempo());
        
        ejecutarTest("Copia presión estática", presionOriginal.presionEstatica == presionCopia.presionEstatica);
        ejecutarTest("Copia presión dinámica", presionOriginal.presionDinamica == presionCopia.presionDinamica);
        ejecutarTest("Copia tiempo presión", presionOriginal.getTiempo() == presionCopia.getTiempo());
    }
    
    // Test 4: Manejo de errores
    void testManejoErrores() {
        std::cout << "\n--- Test 4: Manejo de Errores ---" << std::endl;
        
        bool excepcionCapturada = false;
        
        // Probar lectura de archivo inexistente
        try {
            Posicion pos(0.0f, 0.0f, 0.0f, 0.0f);
            Presion pres(0.0f, 0.0f, 0.0f);
            SaveFlightData datos(pos, pres);
            
            std::ifstream archivoEntrada("archivo_inexistente.bin", std::ios::binary);
            datos.deserializar(archivoEntrada);
        } catch (const std::runtime_error& e) {
            excepcionCapturada = true;
        }
        
        ejecutarTest("Manejo archivo inexistente", excepcionCapturada);
    }
};

int main() {
    std::cout << "=== SUITE DE TESTS PARA SERIALIZACIÓN DE DATOS DE VUELO ===" << std::endl;
    
    ProbadorTests probador;
    
    try {
        probador.testSerializacionBasica();
        probador.testValoresExtremos();
        probador.testConstructorCopia();
        probador.testManejoErrores();
        
        probador.mostrarResumen();
        
    } catch (const std::exception& e) {
        std::cerr << "Excepción inesperada en suite de tests: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
