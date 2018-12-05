#ifndef VERTICE_H
#define VERTICE_H

#include <string>
#include "aeropuerto.h"

using namespace std;

class Vertice {
	private:
		string iata;
		Aeropuerto* datos_aeropuerto;

	public:
		Vertice();
		Vertice(string iata, Aeropuerto* aeropuerto);
		string obtener_iata();
		Aeropuerto* obtener_aeropuerto();
		void asignar_iata(string iata);
		void asignar_aeropuerto(Aeropuerto* aeropuerto);
};

#endif