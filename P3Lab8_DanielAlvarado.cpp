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
#include "Alfil.h"
#include "Caballo.h"
#include "Pieza.h"
#include "Reina.h"
#include "Rey.h"
#include "Torre.h"
#include "Peon.h"


using namespace std;

//prototipos
int encontrarIndice(string);
int menu();
vector<Partida*> leerPartidas();
void jugarPartida();
string** proveerMatriz();
void liberarMatriz(string**&);

/*
 * 
 */
int main(int argc, char** argv) {

    vector<Partida*> partidasGuardadas;

    partidasGuardadas = leerPartidas();

    int opcion = 0;

    while (opcion != 3) {

        switch ((opcion = menu())) {

            case 1:
            {
                cout << "Jugar Partida" << endl << endl;


                break;

            }
            case 2:
            {
                cout << "Recrear Partida" << endl << endl;

                break;

            }
            case 3:
            {
                cout << "Ha salido del programa...." << endl;
                break;
            }
        }
    }


    return 0;
}

void jugarPartida(){
    
    Partida* game;
    
    string nombrePartida = "";
    string pieza = "";
    
    cout << "Ingrese el nombre de la Partida: ";
    cin >> nombrePartida;
    cout << endl;
    
    cout << "Ingrese la pieza a usar: ";
    cin >> pieza;
    cout << endl;
    
    game = new Partida(nombrePartida, pieza);
    
    
    bool flag = true;
    
    Pieza* reyBlanco = new Rey();
    Pieza* reyNegro = new Rey();
    
    
    Pieza* blanco;
    Pieza* negro;
    
    int indice = encontrarIndice(pieza);
    
    switch(indice){
        
        case 1:{
            blanco = new Reina();
            negro = new Reina();
            break;
        
        }case 2:{
            blanco = new Alfil();
            negro = new Alfil();
            break;
        
        }case 3:{
            blanco = new Torre();
            negro = new Torre();
            break;
        
        }case 4:{
            blanco = new Caballo();
            negro = new Caballo();
            break;
        
        }case 5:{
            blanco = new Peon();
            negro = new Peon();
        }
    }
    
    
    while(flag){
        
    }//while
    
    
}//fin



//menu que valida opciones ingresadas del usuario
int menu() {

    int opcion = 0;

    do {

        cout << "------MENU------" << endl
                << "1. Jugar Partida" << endl
                << "2. Recrear Partida" << endl
                << "Ingrese su eleccion: ";

        cin >> opcion;
        cout << endl;

    } while (opcion > 3 || opcion < 1);

    return opcion;
}


//lee del archivo la bitacora y las llena en el vector

vector<Partida*> leerPartidas() {

    vector<Partida*> lectorPartidas;
    vector<string> movimientos;

    ifstream lectura;
    lectura.open("bitacoraPartidas.txt");


    if (lectura.is_open()) {

        string buffer = "";
        string nombrePieza = "";
        string jugadas = "";

        while (getline(lectura, buffer)) {

            getline(lectura, nombrePieza);

            Partida* game = new Partida(buffer, nombrePieza);

            getline(lectura, jugadas);

            string play = "";
            for (int i = 0; i < jugadas.size(); i++) {
                char a = jugadas[i];

                if (a == ';') {

                    movimientos.push_back(play);
                } else {
                    play += a;
                }
            }

            game->setJugadas(movimientos);

            lectorPartidas.push_back(game);

            getline(lectura, buffer);

            buffer.clear();

        }
    }
    return lectorPartidas;
}

//provee un arreglo bidimensional de piezas
string** proveerMatriz() {

    string** tablero = NULL;

    tablero = new string* [8];

    for (int i = 0; i < 8; i++) {
        tablero[i] = new string[8];
    }

    return tablero;
}

int encontrarIndice(string pieza){
    
    if(pieza == "Reina"){
        return 1;
    }else if(pieza == "Alfil"){
        return 2;
    }else if(pieza == "Torre"){
        return 3;
    }else if(pieza == "Caballo"){
        return 4;
    }else if(pieza == "Peon"){
        return 5;
    }else{
        return 0;
    }
}