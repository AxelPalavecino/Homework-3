#include "../include/ex2/Rectangulo.hpp"
#include "../include/ex2/Punto.hpp"
#include <iostream>

Rectangulo::Rectangulo() : vertice_inferior_izquierdo(0, 0), 
                           ancho(1), 
                           largo(1) {}

Rectangulo::Rectangulo(double _x, double _y, double _ancho, double _largo) : vertice_inferior_izquierdo(_x, _y), 
                                                                             ancho(_ancho), 
                                                                             largo(_largo) {}

Rectangulo::Rectangulo(const Punto& _vertice_inferior_izquierdo, double _ancho, double _largo) : vertice_inferior_izquierdo(_vertice_inferior_izquierdo), 
                                                                                          ancho(_ancho),
                                                                                          largo(_largo) {}

Punto Rectangulo::getVerticeInferiorIzquierdo() const { return vertice_inferior_izquierdo; }
double Rectangulo::getAncho() const { return ancho; }
double Rectangulo::getLargo() const { return largo; }

void Rectangulo::setVerticeInferiorIzquierdo(const Punto& _vertice) { vertice_inferior_izquierdo = _vertice; }
void Rectangulo::setVerticeInferiorIzquierdo(double _x, double _y) { vertice_inferior_izquierdo.setPosicion(_x, _y); }
void Rectangulo::setAncho(double _ancho) { ancho = _ancho; }
void Rectangulo::setLargo(double _largo) { largo = _largo; }