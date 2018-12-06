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
		//pre: -
		//pos: Inicializa la cantidad de vertices en 0
		Grafo();

		//pre: -
		//pos: Devuelve la cantidad de vertices
		int obtener_cantidad();

		//pre: Recibe un entero indice que representa a un aeropuerto
		//pos: Devuelve una lista con los viajes al aeropuerto
		list<Viaje> obtener_viajes(int indice);

		//pre: Recibe un entero indice que representa a un aeropuerto
		//pos: Devuelve una variable de tipo aeropuerto con los datos
		Aeropuerto* obtener_aeropuerto(int indice);

		//pre: Resive un string con el codigo IATA
		//pos: Devuelve el indice del aeropuerto
		int obtener_indice(string iata);

		//pre: Resive le indice del aeropuerto de partida, el indice del aeropuerto destino y el peso del viaje
		//pos: Agrega el viaje a la lista de viajes del aeropuerto
		void agregar_viaje(int origen, int destino, int peso);

		//pre: Resive un aeropuerto
		//pos: Agrega el aeropuerto al grafo
		int agregar_aeropuerto(Aeropuerto* aeropuerto);

		//pre: -
		//pos: Lista todos los viajes de cada aeropuerto en el grafo
		void mostrar();

		//pre: -
		//pos: Lista todos los aeropuertos presentes en el grafo
		void mostrar_aeropuertos();

		//pre: -
		//pos: Libera la memori dinamica utilizada
		~Grafo();
};

#endif
