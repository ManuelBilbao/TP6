#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "grafo.h"
#include <iostream>

const int INF = 1<<30;

using namespace std;

int buscar_menor_camino(Grafo grafo, int inicio, int destino);

#endif