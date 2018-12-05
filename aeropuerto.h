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

		//pre: Resive cuatro strings con el nombre, pais, ciudad y codigo_IATA del aeropuerto
		//pos: Crea el aeropuerto y le asigna los parametros ingresados
		Aeropuerto(string codigo_IATA, string nombre_aeropuerto, string ciudad, string pais);

		//pre: Recibe un string con el codigo IATA del aeropuerto
		//pos: Le asigna su codigo al aeropuerto
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

		//pre: -
		//pos: Devuelve un string con el codigo_IATA del aeropuerto
		string obtener_codigo_IATA();

		//pre: -
		//pos: Obtiene el nombre del aeropuerto del aeropuerto
		string obtener_nombre_aeropuerto();

		//pre: -
		//pos: Obtiene el nombre de la ciudad del aeropuerto
		string obtener_ciudad();

		//pre: -
		//pos: Obtiene el nombre del pais del aeropuerto
		string obtener_pais();

};

#endif
