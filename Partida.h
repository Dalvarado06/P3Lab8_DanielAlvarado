/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Partida.h
 * Author: dalva
 *
 * Created on December 4, 2020, 2:58 PM
 */

#ifndef PARTIDA_H
#define PARTIDA_H

#include <string>
#include <iostream>
#include <vector>
#include "Pieza.h"

using std::cout;
using std::string;
using std::cin;
using std::endl;
using std::vector;

class Partida {
public:
    
    Partida();
    
    //constructor sobre cargado
    Partida(string, string);
    
    Partida(const Partida& orig);
    
    virtual ~Partida();\

    void guardarPartida();
    
    void setJugadas(vector<string>);
    
private:
    string nombrePartida;
    vector<string> jugadas;
    string pieza;
    
};

#endif /* PARTIDA_H */

