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
char** proveerMatriz();
void liberarMatriz(char**&);
void imprimirTablero(char**);
void realizarMovimiento(char**);
void freeVector(vector<Partida*>&);

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

                jugarPartida();

                break;

            }
            case 2:
            {
                cout << "Recrear Partida" << endl << endl;

                if (partidasGuardadas.empty()) {
                    cout << "No existen partidas guardadas..." << endl << endl;

                } else {

                    for (int i = 0; i < partidasGuardadas.size(); i++) {
                        Partida* p = partidasGuardadas[i];

                        cout << i << ". " << p->getNombre() << endl;
                    }

                    int index = -1;

                    cout << "Ingrese la partida a recrear: ";
                    cin >> index;
                    cout << endl;

                    while (index < 0) {
                        cout << "Ingrese la partida a recrear: ";
                        cin >> index;
                        cout << endl;
                    }


                }

                break;

            }
            case 3:
            {
                freeVector(partidasGuardadas);
                cout << "Ha salido del programa...." << endl;
                break;
            }
        }
    }


    return 0;
}

void jugarPartida() {

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

    switch (indice) {

        case 1:
        {
            blanco = new Reina('Q');
            negro = new Reina('q');
            break;

        }
        case 2:
        {
            blanco = new Alfil('A');
            negro = new Alfil('a');
            break;

        }
        case 3:
        {
            blanco = new Torre('T');
            negro = new Torre('t');
            break;

        }
        case 4:
        {
            blanco = new Caballo('C');
            negro = new Caballo('c');
            break;

        }
        case 5:
        {
            blanco = new Peon('P');
            negro = new Peon('p');
        }
    }


    if (indice != 0) {

        char** tablero = NULL;
        tablero = proveerMatriz();

        switch (indice) {
            case 1:
            {
                //ubicar pieza
                tablero[0][3] = negro->getPieza();
                tablero[7][3] = blanco->getPieza();
                //ubicar reyes
                tablero[0][4] = reyNegro->getPieza();
                tablero[7][4] = reyBlanco->getPieza();
                break;

            }
            case 2:
            {
                tablero[0][2] = negro->getPieza();
                tablero[7][5] = blanco->getPieza();

                tablero[0][4] = reyNegro->getPieza();
                tablero[7][4] = reyBlanco->getPieza();

                break;

            }
            case 3:
            {

                tablero[0][7] = negro->getPieza();
                tablero[7][0] = blanco->getPieza();

                tablero[0][4] = reyNegro->getPieza();
                tablero[7][4] = reyBlanco->getPieza();
                break;

            }
            case 4:
            {
                tablero[0][6] = negro->getPieza();
                tablero[7][1] = blanco->getPieza();

                tablero[0][4] = reyNegro->getPieza();
                tablero[7][4] = reyBlanco->getPieza();
                break;

            }
            case 5:
            {
                tablero[1][4] = negro->getPieza();
                tablero[6][4] = blanco->getPieza();

                tablero[0][4] = reyNegro->getPieza();
                tablero[7][4] = reyBlanco->getPieza();
                break;
            }
        }

        int numJugadas = 0;
        int stillPlaying = 0;
        while (flag) {

            cout << "Este es el tablero: " << endl;
            imprimirTablero(tablero);

            string movimiento = "";
            if (numJugadas == 0 || numJugadas % 2 == 0) {

                imprimirTablero(tablero);

                cout << "Ingrese su movimiento: " << endl;
                cin >> movimiento;
                cout << endl;

                bool canDue = blanco->validarMoviemiento(movimiento);

                while (!canDue) {
                    cout << "Corrija su movimiento: ";
                    cin >> movimiento;
                    cout << endl;

                    canDue = blanco->validarMoviemiento(movimiento);
                }

                //realizar el movimiento


            } else {

                imprimirTablero(tablero);

                cout << "Ingrese su movimiento: " << endl;
                cin >> movimiento;
                cout << endl;

                bool canDue = negro->validarMoviemiento(movimiento);

                while (!canDue) {
                    cout << "Corrija su movimiento: ";
                    cin >> movimiento;
                    cout << endl;

                    canDue = negro->validarMoviemiento(movimiento);
                }

                //realizar el movimiento



                //preguntar si siguen jugando
                cout << "Desea seguir jugando (1 = si): ";
                cin >> stillPlaying;
                cout << endl;

                if (stillPlaying == 1) {
                    flag = false;
                }
            }

        }//while

        liberarMatriz(tablero);

    }//if

    game->guardarPartida();

    delete reyBlanco;
    delete reyNegro;
    delete blanco;
    delete negro;

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

char** proveerMatriz() {

    char** tablero = NULL;

    tablero = new char* [8];

    for (int i = 0; i < 8; i++) {
        tablero[i] = new char[8];
    }

    return tablero;
}

int encontrarIndice(string pieza) {

    if (pieza == "Reina") {
        return 1;
    } else if (pieza == "Alfil") {
        return 2;
    } else if (pieza == "Torre") {
        return 3;
    } else if (pieza == "Caballo") {
        return 4;
    } else if (pieza == "Peon") {
        return 5;
    } else {
        return 0;
    }
}

void liberarMatriz(char** &matriz) {

    if (matriz != NULL) {

        for (int i = 0; i < 8; i++) {
            if (matriz[i] != NULL) {
                delete[] matriz[i];
            }
        }

        delete[] matriz;

        matriz = 0;

    }
}

void imprimirTablero(char** matriz) {

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; i++) {

            if (j == 0) {
                cout << "[ " << i + 1 << " ]" << " [ " << matriz[i][j] << " ] ";
            } else {
                cout << " [ " << matriz[i][j] << " ] ";
            }
        }
        cout << endl;
    }

    for (int i = 0; i < 8; i++) {
        cout << "[ " << i + 1 << " ]";
    }

    cout << endl << endl;
}

void freeVector(vector<Partida*> &lista) {

    int size = lista.size();

    for (int i = 0; i < size; i++) {
        delete lista[i];
        lista[i] = 0;
    }

    lista.clear();
}