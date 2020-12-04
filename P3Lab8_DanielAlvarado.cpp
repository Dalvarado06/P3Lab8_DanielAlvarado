/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   P3Lab8_DanielAlvarado.cpp
 * Author: dalva
 *
 * Created on December 4, 2020, 1:09 PM
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include "Partida.h"
#include <vector>
#include <fstream>

using namespace std;

//prototipos
int menu();
vector<Partida*> leerPartidas();

/*
 * 
 */
int main(int argc, char** argv) {

    vector<Partida*> partidasGuardadas;
    
    partidasGuardadas = leerPartidas();
    
    int opcion = 0;
    
    while(opcion != 3){
        
        switch((opcion = menu())){
            
            case 1:{
                cout << "Jugar Partida" << endl << endl;
                
                
                break;
            
            }case 2:{
                cout << "Recrear Partida" << endl << endl;
                
                break;
            
            }case 3:{
                cout << "Ha salido del programa...." << endl;
                break;
            }
        }
    }
    
    
    return 0;
}

int menu(){
    
    int opcion = 0;
    
    do{
        
        cout << "------MENU------" << endl
             << "1. Jugar Partida" << endl
             << "2. Recrear Partida" <<endl
             << "Ingrese su eleccion: ";
        
        cin >> opcion;
        cout << endl;
        
    }while(opcion > 3 || opcion < 1);
    
    return opcion;
}

vector<Partida*> leerPartidas(){
    
    vector<Partida*> lectorPartidas;
    vector<string> movimientos;
    
    ifstream lectura;
    lectura.open("bitacoraPartidas.txt");
    
    string buffer = "";
    string nombrePieza = "";
    string jugadas = "";
    
    while(getline(lectura, buffer)){
        
        getline(lectura, nombrePieza);
        
        Partida* game = new Partida(buffer, nombrePieza);
        
        getline(lectura, jugadas);
        
        string play = "";
        for(int i = 0; i < jugadas.size(); i++){
            char a = jugadas[i];
            
            if(a == ';'){
                
                movimientos.push_back(play);
            }else{
                play += a;
            }
        }
        
        game->setJugadas(movimientos);
        
        lectorPartidas.push_back(game);
        
        getline(lectura, buffer);
        
        buffer.clear();
        
    }
    
    return lectorPartidas;
}
