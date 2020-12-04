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

using namespace std;

//prototipos
int menu();

/*
 * 
 */
int main(int argc, char** argv) {

    vector<Partida*> partidasGuardadas;
    
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