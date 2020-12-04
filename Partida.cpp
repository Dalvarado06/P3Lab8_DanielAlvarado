/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Partida.cpp
 * Author: dalva
 * 
 * Created on December 4, 2020, 2:58 PM
 */

#include "Partida.h"
#include <fstream>

using std::ofstream;

Partida::Partida() {
}

Partida::Partida(string nombreJuego, string pieza){
    nombrePartida = nombreJuego;
    this->pieza = pieza;
}

Partida::Partida(const Partida& orig) {
}

Partida::~Partida() {
}

void Partida::setJugadas(vector<string> jugadasLeidas){
    
    jugadas.clear();
    
    int size = jugadasLeidas.size();
    
    for(int i = 0; i < size; i++){
        
        string jugada = jugadasLeidas[i];
        
        jugadas.push_back(jugada);
    }
}

void Partida::guardarPartida(){
    
    ofstream outPut;
    
   outPut.open("bitacoraPartidas", ofstream::out | ofstream::app);
    
    outPut << nombrePartida << endl;
    outPut << pieza << endl;
    
    int size = jugadas.size();
    
    for(int i = 0; i < size; i++){
        
        outPut << jugadas[i] << ";";
    }
    
    outPut << endl;
    
    outPut << "--------------------------------";
    outPut << endl;
    
}
