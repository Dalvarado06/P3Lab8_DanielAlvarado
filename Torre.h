/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Torre.h
 * Author: dalva
 *
 * Created on December 4, 2020, 2:31 PM
 */

#ifndef TORRE_H
#define TORRE_H

#include "Pieza.h"

class Torre : public Pieza {
public:
    
    Torre();
    
    Torre(const Torre& orig);
    
    virtual ~Torre();
    
    virtual bool validarMovimiento(string);
    
private:

};

#endif /* TORRE_H */

