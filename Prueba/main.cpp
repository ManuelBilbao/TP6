#include "grafo.h"
#include "dijkstra.h"
#include <iostream>

using namespace std;

int main() {
	Grafo grafo = Grafo();
	int inicio;
	int destino;
	
	cout << "Inicio: ";
	cin >> inicio;
	cout << "Destino: ";
	cin >> destino;

	int costo = buscar_menor_camino(grafo, inicio, destino);
	
	if (costo == -1)
		cout << endl << "El destino es inaccesible" << endl;
	else
		cout << endl << "Costo a destino: " << costo << endl;

	return 0;
}