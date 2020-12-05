/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Caballo.cpp
 * Author: dalva
 * 
 * Created on December 4, 2020, 2:08 PM
 */

#include "Caballo.h"

Caballo::Caballo() {
}

Caballo::Caballo(char pieza) : Pieza(pieza){
    
}

Caballo::Caballo(const Caballo& orig) {
}

Caballo::~Caballo() {
}

bool Caballo::validarMovimiento(string movimiento) {

    string pPosition = "";
    string fPosition = "";

    int indice = movimiento.find(',');

    pPosition = movimiento.substr(0, indice);
    fPosition = movimiento.substr(indice);

    char oColumna = pPosition[1];
    char dColumna = fPosition[1];

    int suma = 0;

    suma = oColumna + dColumna;

    if (oColumna == dColumna || suma > 1 || suma < -1) {
        return false;
    } else {

        int oFila = pPosition[2];
        int dFila = fPosition[2];

        int result = 0;

        if (oFila > dFila) {
            result = oFila - dFila;
        } else {
            result = dFila - oFila;
        }
        
        if(result == 2){
            return true;
        }else{
            return false;
        }
    }
}
