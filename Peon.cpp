/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Peon.cpp
 * Author: dalva
 * 
 * Created on December 4, 2020, 1:26 PM
 */

#include "Peon.h"

Peon::Peon() {
}

Peon::Peon(char pieza) : Pieza(pieza){
    
}

Peon::Peon(const Peon& orig) {
}

Peon::~Peon() {
}

bool Peon::validarMovimiento(string movimiento){\
    
    string pPosition = "";
    string fPosition = "";
    
    int indice = movimiento.find(',');
    
    pPosition = movimiento.substr(0,indice);
    fPosition = movimiento.substr(indice);
    
    char oColumna = pPosition[1];
    char dColumna = fPosition[1];
    
    if((int) oColumna > 104 || (int)dColumna > 104 || oColumna != dColumna){
        return false;
    }else{
        
        int oFila = pPosition[2];
        int dFila = fPosition[2];
        
        int result = 0;
        
        if(oFila > dFila){
            result = oFila - dFila;
        }else{
            result = dFila - oFila;
        }
        
        if(result > 2 && dFila == oFila){
            return false;
        }else{
            return true;
        }
        
    }
    
}
