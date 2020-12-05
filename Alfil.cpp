/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alfil.cpp
 * Author: dalva
 * 
 * Created on December 4, 2020, 2:43 PM
 */

#include "Alfil.h"

Alfil::Alfil() {
}

Alfil::Alfil(char pieza) : Pieza(pieza){
    
}

Alfil::Alfil(const Alfil& orig) {
}

Alfil::~Alfil() {
}

bool Alfil::validarMovimiento(string movimiento){
    
    string pPosition = "";
    string fPosition = "";

    int indice = movimiento.find(',');

    pPosition = movimiento.substr(0, indice);
    fPosition = movimiento.substr(indice);

    char oColumna = pPosition[1];
    char dColumna = fPosition[1];

    int oFila = pPosition[2];
    int dFila = fPosition[2];
    
    if(oColumna > 104 || oColumna < 97 || dColumna > 104 || dColumna < 97
            || oFila > 8 || oFila < 1 || dFila > 8 || dFila < 1){
        return false;
    }else{
        
        if(oFila != dFila || oColumna != dColumna){
            return true;
        }else{
            return false;
        }
    }
}