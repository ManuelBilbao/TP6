#include "vertice.h"
#include <string>

using namespace std;

Vertice::Vertice(string iata, Aeropuerto* aeropuerto) {
	this->iata = iata;
	this->datos_aeropuerto = aeropuerto;
}

string obtener_iata() {
	return this->iata;
}

Aeropuerto* obtener_aeropuerto() {
	return this->datos_aeropuerto;
}

void asignar_iata(string iata) {
	this->iata = iata;
}

void asignar_aeropuerto(Aeropuerto* aeropuerto) {
	this->datos_aeropuerto = aeropuerto;
}