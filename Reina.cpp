/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Reina.cpp
 * Author: dalva
 * 
 * Created on December 4, 2020, 2:23 PM
 */

#include "Reina.h"

Reina::Reina() {
}

Reina::Reina(char pieza) : Pieza(pieza){
    
}

Reina::Reina(const Reina& orig) {
}

Reina::~Reina() {
}

bool Reina::validarMovimiento(string movimiento) {

    string pPosition = "";
    string fPosition = "";

    int indice = movimiento.find(',');

    pPosition = movimiento.substr(0, indice);
    fPosition = movimiento.substr(indice);

    char oColumna = pPosition[1];
    char dColumna = fPosition[1];
    
    if(oColumna > 104 || oColumna < 97 || dColumna > 104 || dColumna < 97){
        return false;
    }else{
        
        int oFila = pPosition[2];
        int dFila = fPosition[2];
        
        if(dFila > 8 || oFila == dFila){
            return false;
        }else{
            return true;
        }
    }
}

