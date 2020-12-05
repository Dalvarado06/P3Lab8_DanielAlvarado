/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Rey.h
 * Author: dalva
 *
 * Created on December 4, 2020, 1:51 PM
 */

#ifndef REY_H
#define REY_H

#include "Pieza.h"

class Rey : public Pieza{
public:
    
    Rey();
    
    Rey(char);
    
    Rey(const Rey& orig);
    
    virtual ~Rey();
    
    virtual bool validarMovimiento(string);
    
private:

};

#endif /* REY_H */

