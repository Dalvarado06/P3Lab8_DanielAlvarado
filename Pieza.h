/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pieza.h
 * Author: dalva
 *
 * Created on December 4, 2020, 1:17 PM
 */

#ifndef PIEZA_H
#define PIEZA_H

#include <string>
using std::string;

class Pieza {
public:
    //Original
    Pieza();
    //sobrecargado
    Pieza(string);
    //Copia
    Pieza(const Pieza& orig);
    //Destructor
    virtual ~Pieza();
    
    //metodo polimorfico de validar movimiento
    virtual bool validarMoviemiento(string);
    
   
private:
    string pieza;
};

#endif /* PIEZA_H */

