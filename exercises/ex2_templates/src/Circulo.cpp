#include "../include/ex2/Circulo.hpp"
#include <iostream>
#include <cmath>

Circulo::Circulo() : centro(0, 0), 
                     radio(1) {}
                     
Circulo::Circulo(const Punto& _centro, double _radio) : centro(_centro), 
                                                        radio(_radio) {}

Circulo::Circulo(double _x, double _y, double _radio) : centro(_x, _y), 
                                                        radio(_radio) {}

Punto Circulo::getCentro() const { return centro; }
double Circulo::getRadio() const { return radio; }

void Circulo::setCentro(const Punto& _centro) { centro = _centro; }
void Circulo::setCentro(double _x, double _y) { centro.setPosicion(_x, _y); }
void Circulo::setRadio(double _radio) { radio = _radio; }