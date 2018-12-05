#ifndef GRAFO_H
#define GRAFO_H

#include <list>
#include <string>
#include "aeropuerto.h"

const int MAX = 200;

using namespace std;

#define Viaje pair<int, int>

class Grafo {
	private:
		int cantidad;
		list<Viaje> viajes[MAX];
		Aeropuerto* aeropuerto[MAX];

	public:
		Grafo();
		int obtener_cantidad();
		list<Viaje> obtener_viajes(int indice);
		Aeropuerto* obtener_aeropuerto(int indice);
		int obtener_indice(string iata);
		void agregar_viaje(int origen, int destino, int peso);
		int agregar_aeropuerto(Aeropuerto* aeropuerto);
		void mostrar();
		void mostrar_aeropuertos();
		~Grafo();
};

#endif
