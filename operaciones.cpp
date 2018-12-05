#include "operaciones.h"


using namespace std;
const int MINIMO_NUMERO_MENU = 1;
const int MAXIMO_NUMERO_MENU = 5;

string pedir_palabra(string campo);
string pedir_codigo();
double pedir_numero(string campo);

void consultar_viaje(/*Grafo* grafo*/) {
	cout << "hola";
	/*
	system("clear");

	string codigo = pedir_codigo();
	Node* buscado = arbol->search(codigo);

	if (!buscado) {

		cout << "No se encontro el aeropuerto" << endl;
		return;

	}

	cout << "Nombre: " << buscado->datos_aeropuerto->obtener_nombre_aeropuerto() << endl;
	cout << "Ciudad: " << buscado->datos_aeropuerto->obtener_nombre_ciudad() << endl;
	cout << "Pais: " << buscado->datos_aeropuerto->obtener_pais() << endl;
	cout << "Superficie: " << buscado->datos_aeropuerto->obtener_superficie() << endl;
	cout << "Terminales: " << buscado->datos_aeropuerto->obtener_cantidad_terminales() << endl;
	cout << "Destinos nacionales: " << buscado->datos_aeropuerto->obtener_destinos_nacionales() << endl;
	cout << "Destinos internacionales: " << buscado->datos_aeropuerto->obtener_destinos_internacionales() << endl;
   */
}

void listar_convinaciones(/*Grafo* grafo*/) {

	system("clear");

	cout << "Listado de aeropuertos:" << endl;
	//arbol->print();

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

string pedir_codigo() {

	string codigo;
	cout << "Codigo IATA: ";
	cin.ignore();
	getline(cin, codigo);

	if (codigo.length() != 3) {

		cout << "El codigo debe tener 3 cifras" << endl;
		return pedir_codigo();

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


	string codigo_IATA_partida = obtener_palabra(linea_leida, posicion_inicio, ' ');
	string nombre_aeropuerto_partida = obtener_palabra(linea_leida, posicion_inicio, ' ');
	string ciudad_partida = obtener_palabra(linea_leida, posicion_inicio, ' ');
	string pais_partida = obtener_palabra(linea_leida, posicion_inicio, ' ');
	string codigo_IATA_destino = obtener_palabra(linea_leida, posicion_inicio, ' ');
	string nombre_aeropuerto_destino = obtener_palabra(linea_leida, posicion_inicio, ' ');
	string ciudad_destino = obtener_palabra(linea_leida, posicion_inicio, ' ');
	string pais_destino = obtener_palabra(linea_leida, posicion_inicio, ' ');
	int costo_vuelo = (int)obtener_dato(linea_leida, posicion_inicio, '\0');

	datos_aeropuerto->asignar_nombre_aeropuerto(nombre_aeropuerto_partida);
	datos_aeropuerto->asignar_nombre_ciudad(ciudad_partida);
	datos_aeropuerto->asignar_pais(pais_partida);
	datos_aeropuerto->asignar_costo(costo_vuelo);

	//arbol->add(codigo, datos_aeropuerto);

}


void cargar_grafo(/*BST* arbol*/) {

	ifstream archivo;
	string linea_leida;
	archivo.open("aeropuertos.txt");

	getline(archivo, linea_leida);

	while(!(archivo.eof())) {

		pasar_datos(linea_leida/*, grafo*/);
		getline(archivo, linea_leida);


	}

	archivo.close();

}

void mostrar_menu() {

	cout << endl << endl << "           Menu de viajes 🛫       "<< endl << endl;
	cout << "  ①  Consultar viajes con codigos IATA" << endl;
	cout << "  ②  Listar convinaciones" << endl;
	cout << "  ③  Salir" << endl;

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

		cout << " Por favor ingrese un numero entre 1 y 5" << endl;
		return pedir_opcion();

	}

	return opcion_pedida;

}
