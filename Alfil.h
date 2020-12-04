/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alfil.h
 * Author: dalva
 *
 * Created on December 4, 2020, 2:43 PM
 */

#ifndef ALFIL_H
#define ALFIL_H

#include "Pieza.h"

class Alfil : public Pieza {
public:
    
    Alfil();
    
    Alfil(const Alfil& orig);
    
    virtual ~Alfil();
    
    virtual bool validarMovimiento(string);
private:

};

#endif /* ALFIL_H */

