#include "../include/ex2/Punto.hpp"
#include <iostream>
#include <cmath>

Punto::Punto() : x(0), 
                 y(0) {}

Punto::Punto(double _x, double _y) : x(_x), 
                                     y(_y) {}

double Punto::getX() const { return x; }
double Punto::getY() const { return y; }

void Punto::setX(double _x) { x = _x; }
void Punto::setY(double _y) { y = _y; }

void Punto::setPosicion(double _x, double _y) { x = _x; y = _y; }

