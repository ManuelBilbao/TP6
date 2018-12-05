#include "operaciones.h"
#include "dijkstra.h"

using namespace std;
const char FIN_LINEA = '\0';
const char FIN_PALABRA = ' ';

string pedir_palabra(string campo);
string pedir_codigo(string mensaje);
double pedir_numero(string campo);

void consultar_viaje(Grafo &grafo) {

	system("clear");

	string codigo = pedir_codigo(" del aeropuerto de partida");
	int indice = grafo.obtener_indice(codigo);

	if (indice == -1) {

		cout << "No se encontro el aeropuerto" << endl;
		return;

	}

	string codigo_destino = pedir_codigo(" del aeropuerto de llegada");
	int indice_destino = grafo.obtener_indice(codigo_destino);

	if (indice_destino == -1) {

		cout << "No se encontro el aeropuerto" << endl;
		return;

	}

	cout << "Listando escalas del vuelo de menor costo: " << endl;

	int costo = buscar_menor_camino(grafo, indice, indice_destino);

	if (costo != -1) {
		cout << "El costo final de este vuelo es: $" << costo << endl;
	} else {
		cout << "No existe un viaje posible" << endl;
	}

}

void listar_combinaciones(Grafo &grafo) {

	system("clear");

	cout << "Listado de vuelos:" << endl;
	grafo.mostrar();

}

string pedir_palabra(string campo) {

	string palabra;
	cout << campo << ": ";

	cin.clear(); // Borro el buffer
	getline(cin, palabra);

	return (string)palabra;

}

double pedir_numero(string campo) {

	double numero;
	cout << campo << ": ";
	cin >> numero;

	if (!cin.good()) { // Comprobar que sea un numero

		cin.clear();
		cin.ignore();
		cout << "Por favor ingrese un numero" << endl;
		return pedir_numero(campo);

	}

	return numero;
}

string pedir_codigo(string mensaje) {

	string codigo;
	cout << "Codigo IATA" << mensaje << ": ";
	cin >> codigo;

	if (codigo.length() != 3) {

		cout << "El codigo debe tener 3 cifras" << endl;
		return pedir_codigo(mensaje);

	}

	return codigo;


}

string obtener_palabra(string linea_leida, int &posicion_inicio, char final_lectura) {
	int  contador = 0;
	char dato_leido[50];

	while(linea_leida[posicion_inicio] != final_lectura) {

		dato_leido[contador] = linea_leida[posicion_inicio];
		contador++;
		posicion_inicio++;

	}

	dato_leido[contador]= '\0';
	posicion_inicio++;
	return (string)dato_leido;

}

int obtener_dato(string linea_leida, int &posicion_inicio, char final_lectura) {

	int contador = 0;
	string dato_leido;
	double medida_leida;

	while(linea_leida[posicion_inicio] != final_lectura){

		dato_leido[contador] = linea_leida[posicion_inicio];
		contador++;
		posicion_inicio++;

	}

	posicion_inicio++;
	medida_leida = atoi(dato_leido.c_str());
	return medida_leida;

}

void pasar_datos(Grafo &grafo, string linea_leida) {

	int posicion_inicio = 0;
	Aeropuerto* datos_aeropuerto_partida = new Aeropuerto();
	Aeropuerto* datos_aeropuerto_destino = new Aeropuerto();


	string codigo_IATA_partida = obtener_palabra(linea_leida, posicion_inicio, FIN_PALABRA);
	string nombre_aeropuerto_partida = obtener_palabra(linea_leida, posicion_inicio, FIN_PALABRA);
	string ciudad_partida = obtener_palabra(linea_leida, posicion_inicio, FIN_PALABRA);
	string pais_partida = obtener_palabra(linea_leida, posicion_inicio, FIN_PALABRA);
	string codigo_IATA_destino = obtener_palabra(linea_leida, posicion_inicio, FIN_PALABRA);
	string nombre_aeropuerto_destino = obtener_palabra(linea_leida, posicion_inicio, FIN_PALABRA);
	string ciudad_destino = obtener_palabra(linea_leida, posicion_inicio, FIN_PALABRA);
	string pais_destino = obtener_palabra(linea_leida, posicion_inicio, FIN_PALABRA);
	int costo_vuelo = (int)obtener_dato(linea_leida, posicion_inicio, FIN_LINEA);

	datos_aeropuerto_partida->asignar_codigo_IATA(codigo_IATA_partida);
	datos_aeropuerto_partida->asignar_nombre_aeropuerto(nombre_aeropuerto_partida);
	datos_aeropuerto_partida->asignar_ciudad(ciudad_partida);
	datos_aeropuerto_partida->asignar_pais(pais_partida);

	datos_aeropuerto_destino->asignar_codigo_IATA(codigo_IATA_destino);
	datos_aeropuerto_destino->asignar_nombre_aeropuerto(nombre_aeropuerto_destino);
	datos_aeropuerto_destino->asignar_ciudad(ciudad_destino);
	datos_aeropuerto_destino->asignar_pais(pais_destino);

	int indice_partida = grafo.obtener_indice(codigo_IATA_partida);
	if (indice_partida == -1) // Si no existe el aeropuerto
		indice_partida = grafo.agregar_aeropuerto(datos_aeropuerto_partida);

	int indice_destino = grafo.obtener_indice(codigo_IATA_destino);
	if (indice_destino == -1) // Si no existe el aeropuerto
		indice_destino = grafo.agregar_aeropuerto(datos_aeropuerto_destino);

  grafo.agregar_viaje(indice_partida, indice_destino, costo_vuelo);

}


void cargar_grafo(Grafo &grafo) {

	ifstream archivo;
	string linea_leida;
	archivo.open("aeropuertos.txt");

	getline(archivo, linea_leida);

	while(!(archivo.eof())) {

		pasar_datos(grafo, linea_leida);
		getline(archivo, linea_leida);


	}

	archivo.close();

}

void mostrar_menu() {

	cout << endl << endl << "           Menu de viajes 🛫       "<< endl << endl;
	cout << "  ①  Consultar viajes con codigos IATA" << endl;
	cout << "  ②  Listar vuelos" << endl;
	cout << "  ③  Listar aeropuertos" << endl;
	cout << "  ④  Salir" << endl;

}

int pedir_opcion() {

	int opcion_pedida;
	cout << " Opcion: ";
	cin >> opcion_pedida;

	if (!cin.good()) { // Comprobar que sea un numero

		cin.clear();
		cin.ignore();
		cout << " Por favor ingrese un numero" << endl;
		return pedir_opcion();

	}

	if (opcion_pedida < MINIMO_NUMERO_MENU || opcion_pedida > MAXIMO_NUMERO_MENU) {

		cout << " Por favor ingrese un numero entre " << MINIMO_NUMERO_MENU << " y " << MAXIMO_NUMERO_MENU << endl;
		return pedir_opcion();

	}

	return opcion_pedida;

}
