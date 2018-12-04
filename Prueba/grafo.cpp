#include "grafo.h"
#include <iostream>

using namespace std;

void generar_random(list<Nodo> vecinos[]) {
	vecinos[0].push_back(Nodo(4, 4));
	vecinos[2].push_back(Nodo(5, 9));
	vecinos[2].push_back(Nodo(1, 5));
	vecinos[4].push_back(Nodo(6, 3));
	vecinos[4].push_back(Nodo(7, 1));
	vecinos[5].push_back(Nodo(1, 2));
	vecinos[5].push_back(Nodo(3, 7));
	vecinos[5].push_back(Nodo(6, 8));
	vecinos[5].push_back(Nodo(7, 4));
	vecinos[6].push_back(Nodo(2, 5));
	vecinos[6].push_back(Nodo(4, 3));
	vecinos[7].push_back(Nodo(5, 9));
	vecinos[7].push_back(Nodo(6, 8));
}

Grafo::Grafo() {
	this->cantidad = VERTICES;
	generar_random(this->vecinos);
}

int Grafo::obtener_cantidad() {
	return this->cantidad;
}

list<Nodo> Grafo::obtener_vecinos(int i) {
	return this->vecinos[i];
}

void Grafo::mostrar() {
	for (int i = 0; i < VERTICES; i++) {
		for (std::list<Nodo>::iterator j = this->vecinos[i].begin(); j != this->vecinos[i].end(); j++) {
			cout << "El nodo " << i << " apunta a " << (*j).first << " con peso " << (*j).second << endl;
		}
	}
}