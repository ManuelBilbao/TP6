#ifndef OPERACIONES_H
#define OPERACIONES_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>
#include "grafo.h"
#include "aeropuerto.h"

using namespace std;

const int MINIMO_NUMERO_MENU = 1;
const int MAXIMO_NUMERO_MENU = 4;

//Pre: necesita un Grafo previamente cargado
//Pos: solicita al usuario el codigo del aeropuerto del que parte y el
//aeropuerto al que ariba e imprime por pantalla las conexiones nesesarias para
//obtener el viaje menos costoso, en caso de un error se lo informa al usuario
void consultar_viaje(Grafo &grafo);

//Pre: necesita un Grafo previamente cargado
//Pos: lista todas las combinaciones que hay en el grafo
void listar_combinaciones(Grafo &grafo);

//Pre: nnecesita un Grafo previamente cargado y un archivo vuelos.txt previamente cargado y bien formado
//Pos: devuelve el Grafo completamente cargado con los datos de un archivo
void cargar_grafo(Grafo &grafo);

//Pre: necesita un string que tenga una linea del archivo vuelos.txt
//Pos: devuelve el dato leeido
void pasar_datos(Grafo &grafo, string linea_leida);

//Pre: necesita la posicion de inicio de lectura y el char donde dejar de leer ambos validos
//Pos: devuelve el dato que se encuentra en la posicion del string pedida
int obtener_dato(string linea_leida, int &posicion_inicio, char final_lectura);

//Pre: necesita la posicion de inicio de lectura y el char donde dejar de leer ambos validos
//Pos: devuelve la palabra que se encuentra en la posicion del string pedida
string obtener_palabra(string linea_leida, int &posicion_inicio, char final_lectura);

//Pre: -
//Pos: imprime el menu por pantalla
void mostrar_menu();

//Pre: -
//Pos: pide al usuario la opcion del menu que quiere y la devuelve si es valida
int pedir_opcion();

#endif
