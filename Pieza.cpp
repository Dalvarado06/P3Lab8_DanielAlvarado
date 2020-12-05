/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pieza.cpp
 * Author: dalva
 * 
 * Created on December 4, 2020, 1:17 PM
 */

#include "Pieza.h"

Pieza::Pieza() {
}

Pieza::Pieza(char pieza){
    this->pieza = pieza;
}

Pieza::Pieza(const Pieza& orig) {
}

Pieza::~Pieza() {
}

bool Pieza::validarMoviemiento(string movimiento){
    return false;
}

char Pieza::getPieza(){
    return pieza;
}