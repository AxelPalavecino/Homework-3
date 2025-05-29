#pragma once 
#include "Punto.hpp"

/**
 * @brief Clase que representa una elipse en el plano cartesiano 2D
 * 
 * Define una elipse mediante su centro, semieje mayor y semieje menor.
 * Proporciona métodos para manipular estas propiedades geométricas.
 */
class Elipse {
private: 
    Punto centro;           ///< Centro de la elipse representado como un punto
    double semieje_mayor;   ///< Longitud del semieje mayor de la elipse
    double semieje_menor;   ///< Longitud del semieje menor de la elipse
public: 
    /**
     * @brief Constructor por defecto que crea una elipse centrada en (0,0) con semieje mayor 2 y menor 1
     */
    Elipse();
    
    /**
     * @brief Constructor que inicializa la elipse con coordenadas del centro y semiejes
     * @param _x Coordenada x del centro
     * @param _y Coordenada y del centro
     * @param _semieje_mayor Longitud del semieje mayor
     * @param _semieje_menor Longitud del semieje menor
     */
    Elipse(double _x, double _y, double _semieje_mayor, double _semieje_menor);
    
    /**
     * @brief Constructor que inicializa la elipse con un punto centro y semiejes
     * @param _centro Punto que representa el centro de la elipse
     * @param _semieje_mayor Longitud del semieje mayor (por defecto 2)
     * @param _semieje_menor Longitud del semieje menor (por defecto 1)
     */
    Elipse(const Punto& _centro, double _semieje_mayor = 2, double _semieje_menor = 1);
    
    /**
     * @brief Destructor por defecto
     */
    ~Elipse() = default;

    /**
     * @brief Obtiene el centro de la elipse
     * @return Punto que representa el centro de la elipse
     */
    Punto getCentro() const;
    
    /**
     * @brief Obtiene la longitud del semieje mayor
     * @return Valor del semieje mayor
     */
    double getSemiejeMayor() const;
    
    /**
     * @brief Obtiene la longitud del semieje menor
     * @return Valor del semieje menor
     */
    double getSemiejeMenor() const;

    /**
     * @brief Establece el centro de la elipse usando un punto
     * @param _centro Nuevo punto centro de la elipse
     */
    void setCentro(const Punto& _centro);
    
    /**
     * @brief Establece el centro de la elipse usando coordenadas
     * @param _x Nueva coordenada x del centro
     * @param _y Nueva coordenada y del centro
     */
    void setCentro(double _x, double _y);
    
    /**
     * @brief Establece la longitud del semieje mayor
     * @param _semieje_mayor Nuevo valor del semieje mayor
     */
    void setSemiejeMayor(double _semieje_mayor);
    
    /**
     * @brief Establece la longitud del semieje menor
     * @param _semieje_menor Nuevo valor del semieje menor
     */
    void setSemiejeMenor(double _semieje_menor);
};