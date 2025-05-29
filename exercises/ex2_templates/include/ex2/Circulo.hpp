#pragma once
#include "Punto.hpp"

/**
 * @brief Clase que representa un círculo en el plano cartesiano 2D
 * 
 * Define un círculo mediante su centro (un punto) y su radio.
 * Proporciona métodos para manipular estas propiedades geométricas.
 */
class Circulo {
private: 
    Punto centro;   ///< Centro del círculo representado como un punto
    double radio;   ///< Radio del círculo
public:
    /**
     * @brief Constructor por defecto que crea un círculo centrado en (0,0) con radio 1
     */
    Circulo();
    
    /**
     * @brief Constructor que inicializa el círculo con un punto centro y radio específicos
     * @param _centro Punto que representa el centro del círculo
     * @param _radio Radio del círculo (por defecto 1)
     */
    Circulo(const Punto& _centro, double _radio = 1);
    
    /**
     * @brief Constructor que inicializa el círculo con coordenadas del centro y radio
     * @param _x Coordenada x del centro
     * @param _y Coordenada y del centro
     * @param _radio Radio del círculo
     */
    Circulo(double _x, double _y, double _radio);
    
    /**
     * @brief Destructor por defecto
     */
    ~Circulo() = default;

    /**
     * @brief Obtiene el centro del círculo
     * @return Punto que representa el centro del círculo
     */
    Punto getCentro() const;
    
    /**
     * @brief Obtiene el radio del círculo
     * @return Valor del radio
     */
    double getRadio() const;

    /**
     * @brief Establece el centro del círculo usando un punto
     * @param _centro Nuevo punto centro del círculo
     */
    void setCentro(const Punto& _centro);
    
    /**
     * @brief Establece el centro del círculo usando coordenadas
     * @param _x Nueva coordenada x del centro
     * @param _y Nueva coordenada y del centro
     */
    void setCentro(double _x, double _y);
    
    /**
     * @brief Establece el radio del círculo
     * @param _radio Nuevo valor del radio
     */
    void setRadio(double _radio);
};