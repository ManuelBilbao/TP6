#ifndef AEROPUERTO_H
#define AEROPUERTO_H

#include <iostream>
#include <string>

using namespace std;

class Aeropuerto {
	private:
		string codigo_IATA;
		string nombre_aeropuerto;
		string ciudad;
		string pais;

	public:
		//pre: -
		//pos: Crea un aeropuerto con todos los valores inicializados en 0 y los string con el valor '\0'
		Aeropuerto();

		Aeropuerto(string codigo_IATA, string nombre_aeropuerto, string ciudad, string pais);

		void asignar_codigo_IATA(string codigo_IATA);

		//pre: Recibe un string con el nombre del aeropuerto
		//pos: Le asigna el nombre al aeropuerto
		void asignar_nombre_aeropuerto(string nombre_aeropuerto);

		//pre: Recibe un string con el nombre de la ciudad
		//pos: Le asigna el nombre de la ciudad al aeropuerto
		void asignar_ciudad(string ciudad);

		//pre:	Recibe un string con el nombre del pais
		//pos:	Le asigna el pais al aeropuerto
		void asignar_pais(string pais);

		string obtener_codigo_IATA();

		//pre: -
		//pos: obtiene el nombre del aeropuerto del aeropuerto
		string obtener_nombre_aeropuerto();

		//pre: -
		//pos: obtiene el nombre de la ciudad del aeropuerto
		string obtener_ciudad();

		//pre: -
		//pos: obtiene el nombre del pais del aeropuerto
		string obtener_pais();

};

#endif
