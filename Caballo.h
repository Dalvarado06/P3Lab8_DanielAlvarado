/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Caballo.h
 * Author: dalva
 *
 * Created on December 4, 2020, 2:08 PM
 */

#ifndef CABALLO_H
#define CABALLO_H

#include "Pieza.h"

class Caballo : public Pieza{
public:
    
    Caballo();
    
    Caballo(string);
    
    Caballo(const Caballo& orig);
    
    virtual ~Caballo();
    
    virtual bool validarMovimiento(string);
    
private:

};

#endif /* CABALLO_H */

