#include <iostream>
#include <cmath>
#include <cassert>
#include "../include/ex2/Punto.hpp"
#include "../include/ex2/Circulo.hpp"
#include "../include/ex2/Elipse.hpp"
#include "../include/ex2/Rectangulo.hpp"
#include "../include/ex2/ProcesadorFigura.hpp"

// Función auxiliar para comparar doubles con tolerancia
bool sonIguales(double a, double b, double tolerancia = 1e-6) {
    return std::abs(a - b) < tolerancia;
}

void testPunto() {
    std::cout << "Ejecutando tests de Punto..." << std::endl;
    
    // Test constructor por defecto
    Punto p1;
    assert(sonIguales(p1.getX(), 0.0));
    assert(sonIguales(p1.getY(), 0.0));
    
    // Test constructor con parámetros
    Punto p2(3.5, 2.8);
    assert(sonIguales(p2.getX(), 3.5));
    assert(sonIguales(p2.getY(), 2.8));
    
    // Test setters
    p1.setX(1.5);
    p1.setY(2.5);
    assert(sonIguales(p1.getX(), 1.5));
    assert(sonIguales(p1.getY(), 2.5));
    
    // Test setPosicion
    p1.setPosicion(10.0, 20.0);
    assert(sonIguales(p1.getX(), 10.0));
    assert(sonIguales(p1.getY(), 20.0));
    
    // Test área (debe ser 0)
    assert(sonIguales(ProcesadorFigura<Punto>::calcularArea(p1), 0.0));
    
    std::cout << "✓ Todos los tests de Punto pasaron" << std::endl;
}

void testCirculo() {
    std::cout << "Ejecutando tests de Círculo..." << std::endl;
    
    // Test constructor por defecto
    Circulo c1;
    assert(sonIguales(c1.getCentro().getX(), 0.0));
    assert(sonIguales(c1.getCentro().getY(), 0.0));
    assert(sonIguales(c1.getRadio(), 1.0));
    
    // Test constructor con punto y radio
    Punto centro(2.0, 3.0);
    Circulo c2(centro, 5.0);
    assert(sonIguales(c2.getCentro().getX(), 2.0));
    assert(sonIguales(c2.getCentro().getY(), 3.0));
    assert(sonIguales(c2.getRadio(), 5.0));
    
    // Test constructor con coordenadas y radio
    Circulo c3(1.0, 1.0, 3.0);
    assert(sonIguales(c3.getCentro().getX(), 1.0));
    assert(sonIguales(c3.getCentro().getY(), 1.0));
    assert(sonIguales(c3.getRadio(), 3.0));
    
    // Test setters
    c1.setRadio(4.0);
    assert(sonIguales(c1.getRadio(), 4.0));
    
    c1.setCentro(5.0, 6.0);
    assert(sonIguales(c1.getCentro().getX(), 5.0));
    assert(sonIguales(c1.getCentro().getY(), 6.0));
    
    Punto nuevoCentro(8.0, 9.0);
    c1.setCentro(nuevoCentro);
    assert(sonIguales(c1.getCentro().getX(), 8.0));
    assert(sonIguales(c1.getCentro().getY(), 9.0));
    
    // Test cálculo de área
    Circulo c4(0.0, 0.0, 2.0);
    double areaEsperada = M_PI * 4.0; // π * r²
    assert(sonIguales(ProcesadorFigura<Circulo>::calcularArea(c4), areaEsperada));
    
    std::cout << "✓ Todos los tests de Círculo pasaron" << std::endl;
}

void testElipse() {
    std::cout << "Ejecutando tests de Elipse..." << std::endl;
    
    // Test constructor por defecto
    Elipse e1;
    assert(sonIguales(e1.getCentro().getX(), 0.0));
    assert(sonIguales(e1.getCentro().getY(), 0.0));
    assert(sonIguales(e1.getSemiejeMayor(), 2.0));
    assert(sonIguales(e1.getSemiejeMenor(), 1.0));
    
    // Test constructor con coordenadas
    Elipse e2(1.0, 2.0, 4.0, 3.0);
    assert(sonIguales(e2.getCentro().getX(), 1.0));
    assert(sonIguales(e2.getCentro().getY(), 2.0));
    assert(sonIguales(e2.getSemiejeMayor(), 4.0));
    assert(sonIguales(e2.getSemiejeMenor(), 3.0));
    
    // Test constructor con punto
    Punto centro(5.0, 6.0);
    Elipse e3(centro, 8.0, 4.0);
    assert(sonIguales(e3.getCentro().getX(), 5.0));
    assert(sonIguales(e3.getCentro().getY(), 6.0));
    assert(sonIguales(e3.getSemiejeMayor(), 8.0));
    assert(sonIguales(e3.getSemiejeMenor(), 4.0));
    
    // Test setters
    e1.setSemiejeMayor(6.0);
    e1.setSemiejeMenor(3.0);
    assert(sonIguales(e1.getSemiejeMayor(), 6.0));
    assert(sonIguales(e1.getSemiejeMenor(), 3.0));
    
    // Test cálculo de área
    Elipse e4(0.0, 0.0, 3.0, 2.0);
    double areaEsperada = M_PI * 3.0 * 2.0; // π * a * b
    assert(sonIguales(ProcesadorFigura<Elipse>::calcularArea(e4), areaEsperada));
    
    std::cout << "✓ Todos los tests de Elipse pasaron" << std::endl;
}

void testRectangulo() {
    std::cout << "Ejecutando tests de Rectángulo..." << std::endl;
    
    // Test constructor por defecto
    Rectangulo r1;
    assert(sonIguales(r1.getVerticeInferiorIzquierdo().getX(), 0.0));
    assert(sonIguales(r1.getVerticeInferiorIzquierdo().getY(), 0.0));
    assert(sonIguales(r1.getAncho(), 1.0));
    assert(sonIguales(r1.getLargo(), 1.0));
    
    // Test constructor con coordenadas
    Rectangulo r2(2.0, 3.0, 4.0, 5.0);
    assert(sonIguales(r2.getVerticeInferiorIzquierdo().getX(), 2.0));
    assert(sonIguales(r2.getVerticeInferiorIzquierdo().getY(), 3.0));
    assert(sonIguales(r2.getAncho(), 4.0));
    assert(sonIguales(r2.getLargo(), 5.0));
    
    // Test constructor con punto
    Punto vertice(1.0, 1.0);
    Rectangulo r3(vertice, 6.0, 8.0);
    assert(sonIguales(r3.getVerticeInferiorIzquierdo().getX(), 1.0));
    assert(sonIguales(r3.getVerticeInferiorIzquierdo().getY(), 1.0));
    assert(sonIguales(r3.getAncho(), 6.0));
    assert(sonIguales(r3.getLargo(), 8.0));
    
    // Test setters
    r1.setAncho(10.0);
    r1.setLargo(12.0);
    assert(sonIguales(r1.getAncho(), 10.0));
    assert(sonIguales(r1.getLargo(), 12.0));
    
    r1.setVerticeInferiorIzquierdo(3.0, 4.0);
    assert(sonIguales(r1.getVerticeInferiorIzquierdo().getX(), 3.0));
    assert(sonIguales(r1.getVerticeInferiorIzquierdo().getY(), 4.0));
    
    // Test cálculo de área
    Rectangulo r4(0.0, 0.0, 5.0, 3.0);
    double areaEsperada = 15.0; // ancho * largo
    assert(sonIguales(ProcesadorFigura<Rectangulo>::calcularArea(r4), areaEsperada));
    
    std::cout << "✓ Todos los tests de Rectángulo pasaron" << std::endl;
}

void testProcesadorFigura() {
    std::cout << "Ejecutando tests de ProcesadorFigura..." << std::endl;
    
    // Test de todas las especializaciones
    Punto punto(0.0, 0.0);
    Circulo circulo(0.0, 0.0, 3.0);
    Elipse elipse(0.0, 0.0, 4.0, 2.0);
    Rectangulo rectangulo(0.0, 0.0, 5.0, 6.0);
    
    // Verificar que las áreas se calculan correctamente
    assert(sonIguales(ProcesadorFigura<Punto>::calcularArea(punto), 0.0));
    assert(sonIguales(ProcesadorFigura<Circulo>::calcularArea(circulo), M_PI * 9.0));
    assert(sonIguales(ProcesadorFigura<Elipse>::calcularArea(elipse), M_PI * 8.0));
    assert(sonIguales(ProcesadorFigura<Rectangulo>::calcularArea(rectangulo), 30.0));
    
    std::cout << "✓ Todos los tests de ProcesadorFigura pasaron" << std::endl;
}

int main() {
    std::cout << "=== Ejecutando Tests de Figuras Geométricas ===" << std::endl;
    
    try {
        testPunto();
        testCirculo();
        testElipse();
        testRectangulo();
        testProcesadorFigura();
        
        std::cout << "\n🎉 ¡Todos los tests pasaron exitosamente!" << std::endl;
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "❌ Error en los tests: " << e.what() << std::endl;
        return 1;
    }
}
