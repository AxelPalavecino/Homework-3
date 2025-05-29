#pragma once
#include "Punto.hpp"

/**
 * @brief Clase que representa un rectángulo en el plano cartesiano 2D
 * 
 * Define un rectángulo mediante su vértice inferior izquierdo, ancho y largo.
 * Los lados del rectángulo son paralelos a los ejes coordenados.
 */
class Rectangulo {
private: 
    Punto vertice_inferior_izquierdo;  ///< Vértice inferior izquierdo del rectángulo
    double ancho;                      ///< Ancho del rectángulo (dimensión horizontal)
    double largo;                      ///< Largo del rectángulo (dimensión vertical)
public:
    /**
     * @brief Constructor por defecto que crea un rectángulo con vértice en (0,0) y dimensiones 1x1
     */
    Rectangulo();
    
    /**
     * @brief Constructor que inicializa el rectángulo con coordenadas del vértice y dimensiones
     * @param _x Coordenada x del vértice inferior izquierdo
     * @param _y Coordenada y del vértice inferior izquierdo
     * @param _ancho Ancho del rectángulo
     * @param _largo Largo del rectángulo
     */
    Rectangulo(double _x, double _y, double _ancho, double _largo);
    
    /**
     * @brief Constructor que inicializa el rectángulo con un punto vértice y dimensiones
     * @param _vertice_inferior_izquierdo Punto del vértice inferior izquierdo
     * @param _ancho Ancho del rectángulo (por defecto 1)
     * @param _largo Largo del rectángulo (por defecto 1)
     */
    Rectangulo(const Punto& _vertice_inferior_izquierdo, double _ancho = 1, double _largo = 1);
    
    /**
     * @brief Destructor por defecto
     */
    ~Rectangulo() = default;

    /**
     * @brief Obtiene el vértice inferior izquierdo del rectángulo
     * @return Punto que representa el vértice inferior izquierdo
     */
    Punto getVerticeInferiorIzquierdo() const;
    
    /**
     * @brief Obtiene el ancho del rectángulo
     * @return Valor del ancho
     */
    double getAncho() const;
    
    /**
     * @brief Obtiene el largo del rectángulo
     * @return Valor del largo
     */
    double getLargo() const;

    /**
     * @brief Establece el vértice inferior izquierdo usando un punto
     * @param _vertice Nuevo punto del vértice inferior izquierdo
     */
    void setVerticeInferiorIzquierdo(const Punto& _vertice);
    
    /**
     * @brief Establece el vértice inferior izquierdo usando coordenadas
     * @param _x Nueva coordenada x del vértice
     * @param _y Nueva coordenada y del vértice
     */
    void setVerticeInferiorIzquierdo(double _x, double _y);
    
    /**
     * @brief Establece el ancho del rectángulo
     * @param _ancho Nuevo valor del ancho
     */
    void setAncho(double _ancho);
    
    /**
     * @brief Establece el largo del rectángulo
     * @param _largo Nuevo valor del largo
     */
    void setLargo(double _largo);
};
