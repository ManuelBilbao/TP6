#ifndef AEROPUERTO_H
#define AEROPUERTO_H

#include <iostream>
#include <string>

using namespace std;

class Aeropuerto {
	private:
		string codigo_IATA_partida;
		string nombre_aeropuerto_partida;
		string ciudad_partida;
		string pais_partida;
		string codigo_IATA_destino;
		string nombre_aeropuerto_destino;
		string ciudad_destino;
		string pais_destino;
		int costo_vuelo;

	public:
		//pre: -
		//pos: Crea un aeropuerto con todos los valores inicializados en 0 y los string con el valor '\0'
		Aeropuerto();

		//pre: Recibe un string con el nombre del aeropuerto
		//pos: Le asigna el nombre al aeropuerto
		void asignar_nombre_aeropuerto(string nombre_aeropuerto_partida, string nombre_aeropuerto_destino);

		//pre: Recibe un string con el nombre de la ciudad
		//pos: Le asigna el nombre de la ciudad al aeropuerto
		void asignar_nombre_ciudad(string ciudad_partida, string ciudad_destino);

		//pre:	Recibe un string con el nombre del pais
		//pos:	Le asigna el pais al aeropuerto
		void asignar_pais(string pais_partida, string pais_destino);

		//pre: Recibe un double con el valor de la superficie
		//pos: Le asigna el valor al aeropuerto
		void asignar_costo(int costo_vuelo);

		//pre: -
		//pos: obtiene el nombre del aeropuerto del aeropuerto
		string obtener_nombre_aeropuerto_partida();

		string obtener_nombre_aeropuerto_destino();

		//pre: -
		//pos: obtiene el nombre de la ciudad del aeropuerto
		string obtener_nombre_ciudad_partida();

		string obtener_nombre_ciudad_destino();

		//pre: -
		//pos: obtiene el nombre del pais del aeropuerto
		string obtener_pais_partida();

		string obtener_pais_destino();

		//pre: -
		//pos: obtiene la superficie del aeropuerto
		int obtener_costo();


		// ~Aeropuerto();

};

#endif
