#include "../include/ex2/Elipse.hpp"
#include <iostream>
#include <cmath>

Elipse::Elipse() : centro(0, 0), 
                   semieje_mayor(2), 
                   semieje_menor(1) {}
Elipse::Elipse(double _x, double _y, double _semieje_mayor, double _semieje_menor) : centro(_x, _y), 
                                                                                     semieje_mayor(_semieje_mayor), 
                                                                                     semieje_menor(_semieje_menor) {}

Elipse::Elipse(const Punto& _centro, double _semieje_mayor, double _semieje_menor) : centro(_centro), 
                                                                                     semieje_mayor(_semieje_mayor), 
                                                                                     semieje_menor(_semieje_menor) {}

Punto Elipse::getCentro() const { return centro; }
double Elipse::getSemiejeMayor() const { return semieje_mayor; }
double Elipse::getSemiejeMenor() const { return semieje_menor; }

void Elipse::setCentro(const Punto& _centro) { centro = _centro; }
void Elipse::setCentro(double _x, double _y) { centro.setPosicion(_x, _y); }
void Elipse::setSemiejeMayor(double _semieje_mayor) { semieje_mayor = _semieje_mayor; }
void Elipse::setSemiejeMenor(double _semieje_menor) { semieje_menor = _semieje_menor; }