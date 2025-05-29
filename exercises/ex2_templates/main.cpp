#include <iostream>
#include <iomanip>
#include "include/ex2/Punto.hpp"
#include "include/ex2/Circulo.hpp"
#include "include/ex2/Elipse.hpp"
#include "include/ex2/Rectangulo.hpp"
#include "include/ex2/ProcesadorFigura.hpp"

int main() {
    std::cout << "=== Demostración de Figuras Geométricas ===" << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    
    // === PUNTO ===
    std::cout << "\n--- PUNTO ---" << std::endl;
    Punto punto1;
    Punto punto2(3.5, 2.8);
    
    std::cout << "Punto1: (" << punto1.getX() << ", " << punto1.getY() << ")" << std::endl;
    std::cout << "Punto2: (" << punto2.getX() << ", " << punto2.getY() << ")" << std::endl;
    
    punto1.setPosicion(1.0, 1.0);
    std::cout << "Punto1 después de modificar: (" << punto1.getX() << ", " << punto1.getY() << ")" << std::endl;
    std::cout << "Área del punto: " << ProcesadorFigura<Punto>::calcularArea(punto1) << std::endl;
    
    // === CÍRCULO ===
    std::cout << "\n--- CÍRCULO ---" << std::endl;
    Circulo circulo1;
    Circulo circulo2(punto2, 5.0);
    Circulo circulo3(2.0, 3.0, 4.0);
    
    std::cout << "Círculo1 - Centro: (" << circulo1.getCentro().getX() << ", " 
              << circulo1.getCentro().getY() << "), Radio: " << circulo1.getRadio() << std::endl;
    std::cout << "Círculo2 - Centro: (" << circulo2.getCentro().getX() << ", " 
              << circulo2.getCentro().getY() << "), Radio: " << circulo2.getRadio() << std::endl;
    std::cout << "Círculo3 - Centro: (" << circulo3.getCentro().getX() << ", " 
              << circulo3.getCentro().getY() << "), Radio: " << circulo3.getRadio() << std::endl;
    
    std::cout << "Área del círculo1: " << ProcesadorFigura<Circulo>::calcularArea(circulo1) << std::endl;
    std::cout << "Área del círculo2: " << ProcesadorFigura<Circulo>::calcularArea(circulo2) << std::endl;
    std::cout << "Área del círculo3: " << ProcesadorFigura<Circulo>::calcularArea(circulo3) << std::endl;
    
    // === ELIPSE ===
    std::cout << "\n--- ELIPSE ---" << std::endl;
    Elipse elipse1;
    Elipse elipse2(punto1, 6.0, 3.0);
    Elipse elipse3(0.0, 0.0, 8.0, 4.0);
    
    std::cout << "Elipse1 - Centro: (" << elipse1.getCentro().getX() << ", " 
              << elipse1.getCentro().getY() << "), Semieje mayor: " << elipse1.getSemiejeMayor() 
              << ", Semieje menor: " << elipse1.getSemiejeMenor() << std::endl;
    std::cout << "Elipse2 - Centro: (" << elipse2.getCentro().getX() << ", " 
              << elipse2.getCentro().getY() << "), Semieje mayor: " << elipse2.getSemiejeMayor() 
              << ", Semieje menor: " << elipse2.getSemiejeMenor() << std::endl;
    
    std::cout << "Área de la elipse1: " << ProcesadorFigura<Elipse>::calcularArea(elipse1) << std::endl;
    std::cout << "Área de la elipse2: " << ProcesadorFigura<Elipse>::calcularArea(elipse2) << std::endl;
    std::cout << "Área de la elipse3: " << ProcesadorFigura<Elipse>::calcularArea(elipse3) << std::endl;
    
    // === RECTÁNGULO ===
    std::cout << "\n--- RECTÁNGULO ---" << std::endl;
    Rectangulo rect1;
    Rectangulo rect2(punto1, 5.0, 3.0);
    Rectangulo rect3(1.0, 2.0, 6.0, 4.0);
    
    std::cout << "Rectángulo1 - Vértice inferior izquierdo: (" 
              << rect1.getVerticeInferiorIzquierdo().getX() << ", " 
              << rect1.getVerticeInferiorIzquierdo().getY() << "), Ancho: " 
              << rect1.getAncho() << ", Largo: " << rect1.getLargo() << std::endl;
    std::cout << "Rectángulo2 - Vértice inferior izquierdo: (" 
              << rect2.getVerticeInferiorIzquierdo().getX() << ", " 
              << rect2.getVerticeInferiorIzquierdo().getY() << "), Ancho: " 
              << rect2.getAncho() << ", Largo: " << rect2.getLargo() << std::endl;
    
    std::cout << "Área del rectángulo1: " << ProcesadorFigura<Rectangulo>::calcularArea(rect1) << std::endl;
    std::cout << "Área del rectángulo2: " << ProcesadorFigura<Rectangulo>::calcularArea(rect2) << std::endl;
    std::cout << "Área del rectángulo3: " << ProcesadorFigura<Rectangulo>::calcularArea(rect3) << std::endl;
    
    // === MODIFICACIONES ===
    std::cout << "\n--- MODIFICANDO FIGURAS ---" << std::endl;
    circulo1.setRadio(3.0);
    circulo1.setCentro(5.0, 5.0);
    std::cout << "Círculo1 modificado - Nueva área: " << ProcesadorFigura<Circulo>::calcularArea(circulo1) << std::endl;
    
    rect1.setAncho(10.0);
    rect1.setLargo(8.0);
    std::cout << "Rectángulo1 modificado - Nueva área: " << ProcesadorFigura<Rectangulo>::calcularArea(rect1) << std::endl;
    
    return 0;
}
