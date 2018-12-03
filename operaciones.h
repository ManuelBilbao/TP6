#ifndef OPERACIONES_H
#define OPERACIONES_H

//#include "Grafo.h"
#include "aeropuerto.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;


//Pre: necesita un arbol binario previamente cargado
//Pos: devuelve los datos del aeropuerto pedido
void consultar_viaje(/*Grafo* grafo*/);

//Pre: necesita un arbol binario previamente cargado
//Pos: lista todos los aeropuertos en orden alfabetico
void listar_convinaciones(/*Grafo* grafo*/);

//Pre: necesita un arbol binario creado y un archivo aeropuertos.txt previamente cargado y bien formado
//Pos: devuelve el arbol completamente cargado con los datos de un archivo
void cargar_grafo(/*Grafo* grafo*/);

//Pre: necesita un string que tenga una linea del archivo aeropuertos.txt
//Pos: devuelve el dato le
void pasar_datos(string linea_leida/*Grafo* grafo*/);

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
