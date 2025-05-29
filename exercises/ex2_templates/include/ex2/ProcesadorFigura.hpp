#pragma once

#include "Punto.hpp"
#include "Circulo.hpp"
#include "Elipse.hpp"
#include "Rectangulo.hpp"
#include <cmath>

/**
 * @brief Clase template para procesar figuras geométricas
 * 
 * Utiliza especialización de plantillas para calcular el área de diferentes
 * tipos de figuras geométricas. La implementación genérica retorna 0.
 * 
 * @tparam T Tipo de figura geométrica a procesar
 */
template<typename T>
class ProcesadorFigura {
public:
    /**
     * @brief Calcula el área de una figura genérica
     * @param figura Referencia constante a la figura
     * @return Área de la figura (0.0 por defecto para tipos no especializados)
     */
    static double calcularArea(const T& figura) {
        return 0.0;
    }
};

/**
 * @brief Especialización de plantilla para calcular el área de un Punto
 * 
 * Un punto geométrico no tiene área, por lo que siempre retorna 0.
 */
template<>
class ProcesadorFigura<Punto> {
public:
    /**
     * @brief Calcula el área de un punto
     * @param punto Referencia constante al punto
     * @return Área del punto (siempre 0.0)
     */
    static double calcularArea([[maybe_unused]] const Punto& punto) {
        return 0.0;
    }
};

/**
 * @brief Especialización de plantilla para calcular el área de un Círculo
 * 
 * Calcula el área usando la fórmula: π * r²
 */
template<>
class ProcesadorFigura<Circulo> {
public:
    /**
     * @brief Calcula el área de un círculo
     * @param circulo Referencia constante al círculo
     * @return Área del círculo (π * radio²)
     */
    static double calcularArea(const Circulo& circulo) {
        return M_PI * circulo.getRadio() * circulo.getRadio();
    }
};

/**
 * @brief Especialización de plantilla para calcular el área de una Elipse
 * 
 * Calcula el área usando la fórmula: π * a * b
 * donde a es el semieje mayor y b el semieje menor
 */
template<>
class ProcesadorFigura<Elipse> {
public:
    /**
     * @brief Calcula el área de una elipse
     * @param elipse Referencia constante a la elipse
     * @return Área de la elipse (π * semieje_mayor * semieje_menor)
     */
    static double calcularArea(const Elipse& elipse) {
        return M_PI * elipse.getSemiejeMayor() * elipse.getSemiejeMenor();
    }
};

/**
 * @brief Especialización de plantilla para calcular el área de un Rectángulo
 * 
 * Calcula el área usando la fórmula: ancho * largo
 */
template<>
class ProcesadorFigura<Rectangulo> {
public:
    /**
     * @brief Calcula el área de un rectángulo
     * @param rectangulo Referencia constante al rectángulo
     * @return Área del rectángulo (ancho * largo)
     */
    static double calcularArea(const Rectangulo& rectangulo) {
        return rectangulo.getAncho() * rectangulo.getLargo();
    }
};