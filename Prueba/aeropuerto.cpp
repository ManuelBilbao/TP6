#include "aeropuerto.h"

Aeropuerto::Aeropuerto(){

	this->nombre_aeropuerto_destino = '\0';
	this->nombre_aeropuerto_partida = '\0';
	this->ciudad_destino = '\0';
	this->ciudad_partida = '\0';
	this->pais_destino = '\0';
	this->pais_partida = '\0';
	this->costo_vuelo = 0;

}

void Aeropuerto::asignar_nombre_aeropuerto(string nombre_aeropuerto_partida, string nombre_aeropuerto_destino) {

	this->nombre_aeropuerto_partida = nombre_aeropuerto_partida;
	this->nombre_aeropuerto_destino = nombre_aeropuerto_destino;

}

void Aeropuerto::asignar_nombre_ciudad(string ciudad_partida, string ciudad_destino) {

	this->ciudad_partida = ciudad_partida;
	this->ciudad_destino = ciudad_destino;

}

void Aeropuerto::asignar_pais(string pais_partida, string pais_destino) {

	this->pais_partida = pais_partida;
	this->pais_destino = pais_destino;

}

void Aeropuerto::asignar_costo(int costo_vuelo) {

	this->costo_vuelo = costo_vuelo;

}


string Aeropuerto::obtener_nombre_aeropuerto_partida() {

	return this->nombre_aeropuerto_partida;

}

string Aeropuerto::obtener_nombre_aeropuerto_destino() {

	return this->nombre_aeropuerto_destino;

}

string Aeropuerto::obtener_nombre_ciudad_partida() {

	return this->ciudad_partida;

}

string Aeropuerto::obtener_nombre_ciudad_destino() {

	return this->ciudad_destino;

}

string Aeropuerto::obtener_pais_partida() {

	return this->pais_partida;

}

int Aeropuerto::obtener_costo() {

	return this->costo_vuelo;

}
