#ifndef GRAFO_H
#define GRAFO_H

#include <list>
#include <string>
#include "aeropuerto.h"
#include "vertice.h"

const int MAX = 200;
const int VERTICES = 8;

using namespace std;

#define Arista pair<int, int>

class Grafo {
	private:
		int cantidad;
		list<Arista> vecino[MAX];
		Vertice vertice[MAX];

	public:
		Grafo();
		int obtener_cantidad();
		list<Arista> obtener_vecino(int i);
		Vertice obtener_vertice(int i);
		void mostrar();
};

#endif