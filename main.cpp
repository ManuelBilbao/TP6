#include <iostream>
#include <string>
#include "grafo.h"
#include "dijkstra.h"
#include "operaciones.h"

using namespace std;

// pre: -
// post: maneja el flujo del programa
int main() {
	Grafo grafo = Grafo();

	cargar_grafo(grafo);
	system("clear");

	bool sigue_programa = true;
	while (sigue_programa) {
		mostrar_menu();
		int opcion_pedida = pedir_opcion();

		switch (opcion_pedida) {
			case 1:
				consultar_viaje(grafo);
				break;
			case 2:
				listar_combinaciones(grafo);
				break;
			case 3:
				grafo.mostrar_aeropuertos();
				break;
			default:
				sigue_programa = false;
		}
	}

	return 0;
}
