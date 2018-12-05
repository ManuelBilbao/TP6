#include <iostream>
#include <cstdlib>
#include "grafo.h"

using namespace std;

Grafo::Grafo() {
	this->cantidad = 0;
}

int Grafo::obtener_cantidad() {
	return this->cantidad;
}

list<Viaje> Grafo::obtener_viajes(int indice) {
	return this->viajes[indice];
}

Aeropuerto* Grafo::obtener_aeropuerto(int indice) {
	return this->aeropuerto[indice];
}

int Grafo::obtener_indice(string iata) {
	int i = 0;
	while (i < cantidad && aeropuerto[i]->obtener_codigo_IATA() != iata)
		i++;

	if (i == cantidad)
		return -1;

	return i;
}

void Grafo::agregar_viaje(int origen, int destino, int peso) {
	this->viajes[origen].push_back(Viaje(destino, peso));
}

int Grafo::agregar_aeropuerto(Aeropuerto* aeropuerto) {
	this->aeropuerto[this->cantidad] = aeropuerto;
	return this->cantidad++;
}

void Grafo::mostrar() {
	for (int i = 0; i < this->cantidad; i++) {
		for (std::list<Viaje>::iterator j = this->viajes[i].begin(); j != this->viajes[i].end(); j++) {
			cout << "Salida: " << aeropuerto[i]->obtener_ciudad() << " (" << aeropuerto[i]->obtener_codigo_IATA() << ") - Destino: " << aeropuerto[j->first]->obtener_ciudad() << " (" << aeropuerto[j->first]->obtener_codigo_IATA() << ") - Precio: $" << j->second << endl;
			// cout << "El nodo " << i << " apunta a " << (*j).first << " con peso " << (*j).second << endl;
		}
	}
}

void Grafo::mostrar_aeropuertos() {
	system("clear");
	for (int i = 0; i < cantidad; i++) {
		Aeropuerto* aeropuerto = this->aeropuerto[i];
		cout << aeropuerto->obtener_codigo_IATA() << ": ";
		cout << aeropuerto->obtener_nombre_aeropuerto() << ", ";
		cout << aeropuerto->obtener_ciudad() << ", ";
		cout << aeropuerto->obtener_pais() << endl;
	}
}

Grafo::~Grafo() {
	for (int i = 0; i < this->cantidad; i++) {
		delete this->aeropuerto[i];
	}
}
