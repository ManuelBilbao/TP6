#include "grafo.h"
#include <iostream>

using namespace std;

void generar_random(list<Arista> vecino[]) {
	vecino[0].push_back(Arista(1, 8));
	vecino[0].push_back(Arista(4, 6));
	vecino[1].push_back(Arista(3, 8));
	vecino[1].push_back(Arista(5, 2));
	vecino[1].push_back(Arista(6, 9));
	vecino[2].push_back(Arista(0, 2));
	vecino[2].push_back(Arista(5, 8));
	vecino[4].push_back(Arista(2, 5));
	vecino[4].push_back(Arista(6, 5));
	vecino[5].push_back(Arista(3, 1));
	vecino[6].push_back(Arista(2, 5));
	vecino[7].push_back(Arista(6, 9));
}

Grafo::Grafo() {
	this->cantidad = VERTICES;
	generar_random(this->vecino);
}

int Grafo::obtener_cantidad() {
	return this->cantidad;
}

list<Arista> Grafo::obtener_vecino(int i) {
	return this->vecino[i];
}

Vertice Grafo::obtener_vertice(int i) {
	return this->vertice[i];
}

void Grafo::mostrar() {
	for (int i = 0; i < this->cantidad; i++) {
		for (std::list<Arista>::iterator j = this->vecino[i].begin(); j != this->vecino[i].end(); j++) {
			cout << "El nodo " << i << " apunta a " << (*j).first << " con peso " << (*j).second << endl;
		}
	}
}