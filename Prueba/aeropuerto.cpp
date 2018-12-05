#include "aeropuerto.h"

Aeropuerto::Aeropuerto() {
	this->codigo_IATA = "";
	this->nombre_aeropuerto = "";
	this->ciudad = "";
	this->pais = "";
}

Aeropuerto::Aeropuerto(string codigo_IATA, string nombre_aeropuerto, string ciudad, string pais) {
	this->codigo_IATA = codigo_IATA;
	this->nombre_aeropuerto = nombre_aeropuerto;
	this->ciudad = ciudad;
	this->pais = pais;
}

void Aeropuerto::asignar_codigo_IATA(string codigo_IATA) {
	this->codigo_IATA = codigo_IATA;
}

void Aeropuerto::asignar_nombre_aeropuerto(string nombre_aeropuerto) {
	this->nombre_aeropuerto = nombre_aeropuerto;
}

void Aeropuerto::asignar_ciudad(string ciudad) {
	this->ciudad = ciudad;
}

void Aeropuerto::asignar_pais(string pais) {
	this->pais = pais;
}

string Aeropuerto::obtener_codigo_IATA() {
	return this->codigo_IATA;
}

string Aeropuerto::obtener_nombre_aeropuerto() {
	return this->nombre_aeropuerto;
}

string Aeropuerto::obtener_ciudad() {
	return this->ciudad;
}

string Aeropuerto::obtener_pais() {
	return this->pais;
}
