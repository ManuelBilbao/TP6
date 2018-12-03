//#include "grafo.h"
#include "operaciones.h"


const int MINIMO_NUMERO_MENU = 1;
const int MAXIMO_NUMERO_MENU = 5;


//Pre: -
//Pos: Maneja el flujo de programa
int main() {
	//Grafo grafo;
	bool sigue_programa = true;
	cargar_grafo(/*&grafo*/);
	system("clear");
	while(sigue_programa){

		mostrar_menu();
		int opcion_pedida = pedir_opcion();

		switch (opcion_pedida) {
			case 1:
				consultar_viaje();
				break;
			case 2:
				listar_convinaciones();
				break;
			default:
				sigue_programa = false;

		}
	}

	return EXIT_SUCCESS;
}
