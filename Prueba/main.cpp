#include "grafo.h"
#include <iostream>

const int INF = 1<<30;

using namespace std;

int costo_menor(int costo[], bool visitado[], int cantidad) {
	int costo_menor = INF;
	int indice_menor = -1;
	for (int i = 0; i < cantidad; i++) {
		cout << "Visitado: " << visitado[i] << ", " << costo[i] << " < " << costo_menor << "?" << endl;
		if (!visitado[i] && costo[i] < costo_menor) {
			indice_menor = i;
			costo_menor = costo[i];
		}
	}

	return indice_menor;
}

void inicializar(int vector[], int valor, int cantidad) {
	for (int i = 0; i < cantidad; i++) {
		vector[i] = valor;
	}
}

void inicializar(bool vector[], bool valor, int cantidad) {
	for (int i = 0; i < cantidad; i++) {
		vector[i] = valor;
	}
}

void actualizar_vecinos(Grafo grafo, int index, int costo[], bool visitado[], int previo[]) {
	list<Nodo> vecinos = grafo.obtener_vecinos(index);
	for (list<Nodo>::iterator it = vecinos.begin(); it != vecinos.end(); it++) {
		cout << "El vertice " << index << " apunta a " << it->first << " con peso " << it->second << endl;
		if (visitado[it->first]) continue;

		if (costo[index] + it->second < costo[it->first]) {
			cout << "Modificando costo " << it->first << " a " << costo[index] + it->second << endl;
			costo[it->first] = costo[index] + it->second;
			previo[it->first] = index;
		}
	}
}

bool faltan_visitar(bool visitado[], int cantidad) {
	bool faltan_visitar = false;
	for (int i = 0; i < cantidad; i++) {
		if (!visitado[i]) {
			faltan_visitar = true;
			return faltan_visitar;
		}
	}

	return faltan_visitar;
}

void mostrar_pasos(int previo[], int cantidad, int destino) {
	cout << endl << "Pasos: " << destino << ", ";
	int i = previo[destino];
	while (previo[i] != -1) {
		cout << i << ", ";
		i = previo[i];
	}
	cout << i;
	cout << endl;
}

int dijkstra(Grafo grafo, int cantidad, int inicio, int destino) {
	int costo[cantidad];
	bool visitado[cantidad];
	int previo[cantidad];
	inicializar(costo, INF, cantidad);
	inicializar(visitado, false, cantidad);
	inicializar(previo, -1, cantidad);
	costo[inicio] = 0;

	bool sigue = true;
	int actual = costo_menor(costo, visitado, cantidad);
	while (sigue) {
		cout << "Vertice actual: " << actual << endl;
		visitado[actual] = true;
		actualizar_vecinos(grafo, actual, costo, visitado, previo);
		for (int i = 0; i < cantidad; i++)
		{
			cout << i << ": " << costo[i] << " - " << previo[i] << endl;
		}
		actual = costo_menor(costo, visitado, cantidad);
		cout << "Costo menor: " << actual << endl;
		sigue = faltan_visitar(visitado, cantidad) && actual != -1;
		cout << "Sigue: " << sigue << endl;
	}

	mostrar_pasos(previo, cantidad, destino);
	return costo[destino];
}

int main() {
	Grafo grafo = Grafo();
	grafo.mostrar();
	int cantidad = VERTICES;
	int inicio = 0;
	int destino = 5;
	int costo = dijkstra(grafo, cantidad, inicio, destino);
	cout << endl << "Costo a destino: " << costo << endl;

	return 0;
}