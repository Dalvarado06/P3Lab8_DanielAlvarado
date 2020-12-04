/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Rey.cpp
 * Author: dalva
 * 
 * Created on December 4, 2020, 1:51 PM
 */

#include "Rey.h"

Rey::Rey() {
}

Rey::Rey(const Rey& orig) {
}

Rey::~Rey() {
}

bool Rey::validarMovimiento(string movimiento) {

    string pPosition = "";
    string fPosition = "";

    int indice = movimiento.find(',');

    pPosition = movimiento.substr(0, indice);
    fPosition = movimiento.substr(indice);

    char oColumna = pPosition[1];
    char dColumna = fPosition[1];

    int suma = 0;

    int char1 = oColumna;
    int char2 = dColumna;

    suma = char1 - char2;

    if (suma > 1 || suma < -1) {
        return false;
    } else {

        int oFila = pPosition[2];
        int dFila = fPosition[2];

        int sumFila = 0;
                
        sumFila = oFila - dFila;

        if (sumFila > 1 || sumFila < -1) {
            return false;
        } else {
            return true;
        }

    }
}

