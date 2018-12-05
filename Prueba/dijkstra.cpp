#include "dijkstra.h"

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

int costo_menor(int costo[], bool visitado[], int cantidad) {
	int costo_menor = INF;
	int indice_menor = -1;
	for (int i = 0; i < cantidad; i++) {
		if ((!visitado[i]) && (costo[i] < costo_menor)) {
			indice_menor = i;
			costo_menor = costo[i];
		}
	}

	return indice_menor;
}

bool faltan_visitar(bool visitado[], int cantidad) {
	int i = 0;
	while (i < cantidad && !visitado[i])
		i++;

	return (i != cantidad);
}

void actualizar_vecinos(Grafo &grafo, int index, int costo[], bool visitado[], int previo[]) {
	list<Viaje> vecinos = grafo.obtener_viajes(index);
	for (list<Viaje>::iterator it = vecinos.begin(); it != vecinos.end(); it++) {
		if (!visitado[it->first]) {
			if (costo[index] + it->second < costo[it->first]) {
				costo[it->first] = costo[index] + it->second;
				previo[it->first] = index;
			}
		}
	}
}

void mostrar_pasos(Grafo &grafo, int costo[], int previo[], int cantidad, int destino) {
	int i = previo[destino];
	if (i == -1) {
		cout << grafo.obtener_aeropuerto(destino)->obtener_codigo_IATA() << " $" << costo[destino] << endl;
		return;
	}

	cout << "Partida  Llegada  Precio" << endl;
	cout << "  " << grafo.obtener_aeropuerto(i)->obtener_codigo_IATA() << "      " << grafo.obtener_aeropuerto(destino)->obtener_codigo_IATA() << "    " << " $" << costo[destino] - costo[i] << endl;
	while (previo[i] != -1) {
		cout << "  " << grafo.obtener_aeropuerto(previo[i])->obtener_codigo_IATA() << "      " << grafo.obtener_aeropuerto(i)->obtener_codigo_IATA() << "    " << " $" << costo[i] - costo[previo[i]] << endl;
		i = previo[i];
	}
}

int buscar_menor_camino(Grafo &grafo, int inicio, int destino) {
	int cantidad = grafo.obtener_cantidad();

	int costo[cantidad]; // Costo que requiere llegar a cada vertice
	bool visitado[cantidad]; // Si ya me "pare" sobre este vertice
	int previo[cantidad]; // Por que vertice hay que pasar antes

	inicializar(costo, INF, cantidad);
	inicializar(visitado, false, cantidad);
	inicializar(previo, -1, cantidad);
	costo[inicio] = 0;

	bool sigue = true;
	int vertice_actual = inicio;
	while (sigue) {
		visitado[vertice_actual] = true;
		actualizar_vecinos(grafo, vertice_actual, costo, visitado, previo);
		vertice_actual = costo_menor(costo, visitado, cantidad);
		// Si ya se visitaron todos o si el vertice que se busca ya esta visitado
		sigue = (faltan_visitar(visitado, cantidad)) && (vertice_actual != -1) && (!visitado[destino]);
	}

	if (costo[destino] == INF) {
		return -1;
	}

	mostrar_pasos(grafo, costo, previo, cantidad, destino);
	return costo[destino];
}
