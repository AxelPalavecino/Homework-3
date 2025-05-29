#pragma once 
#include <iostream>

/**
 * @brief Clase que representa un punto en el plano cartesiano 2D
 * 
 * Proporciona funcionalidad básica para manejar coordenadas (x, y)
 * con métodos para obtener y modificar la posición del punto.
 */
class Punto {
private: 
    double x;  ///< Coordenada x del punto
    double y;  ///< Coordenada y del punto
public: 
    /**
     * @brief Constructor por defecto que inicializa el punto en el origen (0, 0)
     */
    Punto();
    
    /**
     * @brief Constructor que inicializa el punto con coordenadas específicas
     * @param _x Coordenada x del punto
     * @param _y Coordenada y del punto
     */
    Punto(double _x, double _y);
    
    /**
     * @brief Destructor por defecto
     */
    ~Punto() = default;

    /**
     * @brief Obtiene la coordenada x del punto
     * @return Valor de la coordenada x
     */
    double getX() const;
    
    /**
     * @brief Obtiene la coordenada y del punto
     * @return Valor de la coordenada y
     */
    double getY() const;

    /**
     * @brief Establece la coordenada x del punto
     * @param _x Nuevo valor para la coordenada x
     */
    void setX(double _x);
    
    /**
     * @brief Establece la coordenada y del punto
     * @param _y Nuevo valor para la coordenada y
     */
    void setY(double _y);
    
    /**
     * @brief Establece ambas coordenadas del punto simultáneamente
     * @param _x Nuevo valor para la coordenada x
     * @param _y Nuevo valor para la coordenada y
     */
    void setPosicion(double _x, double _y);
};