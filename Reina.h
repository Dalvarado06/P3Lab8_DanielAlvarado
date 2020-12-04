/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Reina.h
 * Author: dalva
 *
 * Created on December 4, 2020, 2:23 PM
 */

#ifndef REINA_H
#define REINA_H

#include "Pieza.h"

class Reina : public Pieza{
public:
    
    Reina();
    
    Reina(const Reina& orig);
    
    virtual ~Reina();
    
    virtual bool validarMovimiento(string);
    
private:

};

#endif /* REINA_H */

