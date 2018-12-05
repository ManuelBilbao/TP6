#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "grafo.h"
#include <iostream>

const int INF = 1<<30;

using namespace std;

//pre: Recibe un grafo con los vuelos, un numero que reprecenta el aeropuerto de
//inicio y otro que representa el destino (segun donde se encuentran en el grafo)
//pos: Calcula la ruta de menor coste e imprime por pantalla los vuelos que se deben tomar
int buscar_menor_camino(Grafo &grafo, int inicio, int destino);

#endif
