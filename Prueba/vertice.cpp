#include "vertice.h"
#include <string>

using namespace std;

Vertice::Vertice() {
	this->iata = "";
	this->datos_aeropuerto = 0;
}

Vertice::Vertice(string iata, Aeropuerto* aeropuerto) {
	this->iata = iata;
	this->datos_aeropuerto = aeropuerto;
}

string Vertice::obtener_iata() {
	return this->iata;
}

Aeropuerto* Vertice::obtener_aeropuerto() {
	return this->datos_aeropuerto;
}

void Vertice::asignar_iata(string iata) {
	this->iata = iata;
}

void Vertice::asignar_aeropuerto(Aeropuerto* aeropuerto) {
	this->datos_aeropuerto = aeropuerto;
}