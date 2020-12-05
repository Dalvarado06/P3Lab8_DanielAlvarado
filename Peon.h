/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Peon.h
 * Author: dalva
 *
 * Created on December 4, 2020, 1:26 PM
 */

#ifndef PEON_H
#define PEON_H

#include "Pieza.h"

class Peon : public Pieza{
public:
    
    Peon();
    
    Peon(char);
    
    Peon(const Peon& orig);
    
    virtual ~Peon();
    
    virtual bool validarMovimiento(string);
private:

};

#endif /* PEON_H */

